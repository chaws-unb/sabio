#include <symbolTable.h>
#include <dataType.h>

static struct symbol symbolTableHash[NHASH];

static unsigned calcHash(char * _nameForHash)
{
	unsigned int hashTmp = 0;
	unsigned character = 0;

	while(character = *_nameForHash++)
	{
		hashTmp = hashTmp * HASH_CALC ^ character;
	}

	return hash;
}

int addSymbolRef(int _lineno, char * _fileName, char * _word, int _flag)
{
	struct ref *r;
	struct symbol *sp = lookup(word);

	/* don't do dups */
	if(sp->reflist && sp->reflist->lineno == lineno &&
		sp->reflist->filename == filename)
	{
		return -1;
	}

	r = malloc(sizeof(struct ref));
	if(!r)
	{
		fputs("out of space\n", stderr); abort();
		return -1;
	}
	r->next = sp->reflist;
	r->filename = filename;
	r->lineno = lineno;
	r->flags = flags;
	sp->reflist = r;
	return 1;
}

symbol * lookUp(char * _symbolName)
{
	symbol * sp = 0;
	int howManyLooked = NHASH;

	sp = &symbolTableHash[calcHash(_symbolName) % SIZE_SYMBOL_TABLE]

	while(--howManyLooked >= 0)
	{
		if(sp->name && !strcmp(sp->name, sym))
		{
			return sp;
		}
		/* new entry */
		if(!sp->name)
		{
			sp->name = strdup(sym);
			sp->reflist = 0;
			return sp;
		}

		if(++sp >= symtab+NHASH)
		{
			sp = symtab; /* try the next entry */
		}
	}
	fputs("symbol table overflow\n", stderr);
	abort(); /* tried them all, table is full */

	return NULL;
}
