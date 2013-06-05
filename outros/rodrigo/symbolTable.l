/*A tabela de símbolo é simplesmente um array de structs symbols, onde
 * cada uma contém um ponteiro para o nome e uma lista de referências.
 * A referência são uma lista encadeada de numero de linhas e ponteiros
 * para o nome do arquivo.*/
/**
 * Configura algumas opções:
 * 1 - noyywrap:
 * 2 - nodefault:
 * 3 - yylineno: Diz ao flex para manter uma variável inteira com o valor
 * 		atual da linha.
 * 4 - case-insensitive: Faz com que o flex não seja case-sensitive
 **/
%option noyywrap nodefault yylineno case-insensitive

/*Tabela de símbolo de palavra normais*/
%{
	//Pilha
	struct symbol
	{
		struct ref * reflist;
		char * name;
	};
	//Nó
	struct ref
	{
		struct ref * next;
		char * filename;
		int flags;
		int lineno;
	};

	/*Tabela de símbolo simples de tamanho fixo.*/
	#define NHASH 9997
	struct symbol symtab[NHASH];	//TAbela

	struct symbol * lookup(char *);
	void addref(int, char *, char *, int);

	char * curfilename;	//Nome da atual entrada.
%}

/* Lembrando:
  1 - yytext: Em qualquer ação do flex, a variável yytext é setada como
  		um ponto de entrada para a entrada do padrão do texto encontrado
  2 - (): Agrupa uma série de expressões regulares juntas dentro de uma
  		nova expressão regular. 
  3 - \: Usado para sair de metacaracteres como os utilizados em C.
  4 - ?: Marca zero ou uma ocorrencia de uma expressão regular.
  5 - +: Marca uma ou mais ocorrencias de uma expressão regular. 
 */
/*Regras para concordancia gerada*/
/*Pula palavras comuns*/
%%
a |
an |
and |
are |
as |
at |
be |
but |
for |
in |
is |
it |
of |
on |
or |
that |
the |
this |
to /*Só adicionará na tabela se símbolos se uma palavra sob as condições abaixo for encontrada.*/

[a-z]+(\'(s|t))? {addref(yylineno, curfilename, yytext, 0);}
.|\n	//Ignora todo o resto
%%

/*Hash de símbolo*/
static unsigned symhash(char * sym)
{
	unsigned int hash = 0;
	unsigned c;
	//Repare que se a palavra for repetida, o valor será o mesmo para ela
	while((c = *sym++))
	{
		hash = hash * 9 ^ c;
	}

	return hash;
}

struct symbol * lookup(char * sym)
{
	struct symbol * sp = &symtab[symhash(sym) % NHASH];
	int scount = NHASH;	//Quantas vezes é preciso olhar

	while(--scount >= 0)
	{
		//Verifica se já existe um nome inserido na tabela
		if(sp->name && !strcmp(sp->name, sym))
		{
			return sp;
		}
		//Copia o nome para a hash
		if(!sp->name)
		{
			sp->name = strdup(sym);
			sp->reflist = 0;//Será o novo nó, ou seja, o último.
			return sp;
		}
		//Caso em que uma nova entrada é encontrada
		if(++sp >= symtab + NHASH)
		{
			sp = symtab;	//Tenta a próxima entrada
		}
	}
	fputs("Symbol table overflow \n", stderr);
	abort(); //Tentou tudo, tabela de símbolo cheia
}

void addref(int lineno, char * filename, char * word, int flags)
{
	struct ref * r;
	struct symbol * sp = lookup(word);

	//Não realizar a duplicação da mesma linha e arquivo
	if(sp->reflist && sp->reflist->lineno == lineno &&
		sp->reflist->filename == filename)
	{
			return;
	}

	r = malloc(sizeof(struct ref));
	if(!r)
	{
		fputs("out of space \n", stderr);
		abort();
	}
	r->next = sp->reflist;
	r->filename = filename;
	r->lineno = lineno;
	r->flags = flags;
	sp->reflist = r;
}

/*Imprime a referência organizada em ordem alfabetica.*/
static int symcompare(const void * xa, const void * xb)
{
	const struct symbol * a = xa;
	const struct symbol * b = xb;

	if(!a->name)
	{
		if(!b->name)
		{
			return 0;	//Ambos vázios
		}
		return 1;
	}

	if(!b->name)
	{
		return -1;
	}

	return strcmp(a->name, b->name);
}

void printrefs()
{
	struct symbol * sp;

	qsort(symtab, NHASH, sizeof(struct symbol), symcompare); //Ordena a tabela de símbolos

	for(sp = symtab; sp->name && sp < symtab + NHASH; sp++)
	{
		char * prevfn = NULL;	//Ultima impressão do nome do arquivo
		//Lista de referência reversa
		struct ref * rp = sp->reflist;
		struct ref * rpp = 0;	//rep anterior
		struct ref * rpn;	//Próxima referência

		do
		{
			rpn = rp->next;
			rp->next = rpp;
			rpp = rp;
			rp = rpn;
		}while(rp);

		//Agora imprime a palavra e a referência
		printf("%10s", sp->name);
		for(rp = rpp; rp; rp = rp->next)
		{
			if(rp->filename == prevfn)
			{
				printf(" %d", rp->lineno);
			}
			else
			{
				printf(" %s:%d", rp->filename, rp->lineno);
				prevfn = rp->filename;
			}
		}
		printf("\n");
	}
}

int main(int argc, char ** argv)
{
	int i = 0;
	//Se nenhuma entrada especifica for informada lê do terminal
	if(argc < 2)
	{
		curfilename = "(stdin)";
		yylineno = 1;
		yylex(); //Como o flex chama a rotina de scanner e imprime os resultados
	}
	else
	{
		//Varre a leitura por todos os arquivos
		for(i = 1; i < argc; i++)
		{
			FILE * f = fopen(argv[i], "r");
			if(!f)
			{
				perror(argv[1]);
				return 1;
			}
			curfilename = argv[i];	//Para addref
			/*Para programas com I/O simples que precisam ler cada arquivo de entrada
			 * do início para o fim, o flex fornece a rotina yyrestart, que diz ao
			 * scanner para ler do stdio indicado.*/
			yyrestart(f);
			yylineno = 1;
			yylex();
			fclose(f);
		}
	}
	printrefs();

	return 0;
}
