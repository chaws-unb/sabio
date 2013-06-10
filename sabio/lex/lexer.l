%option noyywrap nodefault yylineno
%option header-file="lexer.h"

%x COMMENT
%x IFILE

UCN (\\u[0-9a-fA-F]{4}|\\U[0-9a-fA-F]{8})
EXP ([Ee][-+]?[0-9]+)
ILEN ([Uu](L|l|LL|ll)?|(L|l|LL|ll)[Uu]?)

%{
	#include "lexer.h"
	#include "dataType.h"
	#include "symbolTable.h"
	#include "handleFile.h"

	int defining = 0;
%}

%%
"/*"
	{
		BEGIN(COMMENT);
	}
<COMMENT>"*/"
	{
		BEGIN(INITIAL);
	}
<COMMENT>([^*]|\en)+|.
	/* Comentário C++, uma extesão comum */
"//".*\n

<COMMENT><<EOF>> {
		printf("%s:%d: Unterminated comment\n", currentFileName, yylineno);
		return 0;
	}

 /*Declaração de palavras chaves. Repare que foi feita uma divisão entre
  * palavras chaves que introduzem uma definição das demais */
_Bool 		|
_Complex 	|
_Imaginary 	|
auto 		|
char 		|
const 		|
double 		|
enum 		|
extern 		|
float 		|
inline 		|
int 		|
long 		|
register 	|
restrict 	|
short 		|
signed 		|
static 		|
struct 		|
typedef 	|
union 		|
unsigned 	|
void 		|
volatile { defining = 1;}

 /*Keywords*/
break
case
continue
default
do
else
for
goto
if
return
sizeof
switch
while

 /*Constantes. Note o uso dos subpadrões aqui*/
 /*Inteiros*/
0[0-7]*{ILEN}?
[1-9][0-9]*{ILEN}?
0[Xx][0-9a-fA-F]+{ILEN}?

 /*Decimal float*/
([0-9]*\.[0-9]+|[0-9]+\.){EXP}?[flFL]?
[0-9]+{EXP}[flFL]?

 /*Hex float*/
0[Xx]([0-9a-fA-F]*\.[0-9a-fA-F]+\.?)[Pp][-+]?[0-9]+[flFL]?

 /* char const */
\'([^'\\]|\\['"?\\abfnrtv]|\\[0-7]{1,3}|\\[Xx][0-9a-fA-F]+|{UCN})+\'

 /* string literal */
L?\"([^\"\\]|\\['"?\\abfnrtv]|\\[0-7]{1,3}|\\[Xx][0-9a-fA-F]+|{UCN})+\"

 /*Pontuadores*/
"{"|"<%"|";"	{defining = 0;}

"["|"]"|"("|")"|"{"|"}"|"."|"->"
"++"|"--"|"&"|"*"|"+"|"-"|"~"|"!"
"/"|"%"|"<<"|">>"|"<"|">"|"<="|">="|"=="|"!="|"^"|"|"|"&&"|"||"
"?"|":"|";"|"..."
"="|"*="|"/="|"%="|"+="|"-="|"<<="|">>="|"&="|"^=""|="
","|"#"|"##"
"<:"|":>"|"%>"|"%:"|"%:%:"

 /*Identificador. Neste ponto é realizado o reconhecimento de variáveis,
  * palavra-chave, dentre outros.*/
([_a-zA-Z]|{UCN})([_a-zA-Z0-9]|{UCN})* {
		addSymbolRef(yylineno, currentFileName, yytext, defining);
	}
 /*Espaço em branco*/
[ \t\n]+
 /* Linha de continuação*/
\\$

 /*Alguns tratamento para pré-processador*/
"#"" "*if.*\n
"#"" "*else.*\n
"#"" "*endif.*\n
"#"" "*define.*\n
"#"" "*line.*\n

 /*Reconhece include*/
^"#"[ \t]*include[ \t]*[\"<] {
		BEGIN IFILE;
	}
<IFILE>[^>\"]+ {
		{
			int c;
			while((c = input()) && c != '\n');
		}
		newFile(strdup(yytext));
		BEGIN INITIAL;
		}

<IFILE>.|\n {
		fprintf(stderr, "%s:%d bad include line\n", currentFileName, yylineno);
		BEGIN INITIAL;
	}

<<EOF>> {
		if(!popFile()) yyterminate();
	}

	/*Caracter invalido*/
. {
	printf("%s, %d: Mystery character '%s'\n", currentFileName, yylineno, yytext);
  }
%%

int main(int argc, char ** argv)
{
	int i = 0;

	if(argc < 2)
	{
		fprintf(stderr, "need filename\n");
		return 1;
	}

	for(i = 1; i < argc; i++)
	{
		if(newFile(argv[i]))
		{
			yylex();
		}
	}

	printrefs();
	return 0;
}
