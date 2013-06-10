/**
 * @file symbolTable.c
 **/
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#include "symbolTable.h"
#include "dataType.h"

static symbol symbolTableHash[SIZE_SYMBOL_TABLE];

static unsigned calcHash(char * _nameForHash)
{
	unsigned int hashTmp = 0;
	unsigned character = 0;

	while(character = *_nameForHash++)
	{
		hashTmp = hashTmp * HASH_CALC ^ character;
	}

	return hashTmp;
}

symbol * lookUp(char * _symbolName)
{
	symbol * sp = 0;
	int howManyLooked = SIZE_SYMBOL_TABLE;

	sp = &symbolTableHash[calcHash(_symbolName) % SIZE_SYMBOL_TABLE];

	while(--howManyLooked >= 0)
	{
		if(sp->symbolName && !strcmp(sp->symbolName, _symbolName))
		{
			return sp;
		}
		
		/* new entry */
		if(!sp->symbolName)
		{
			sp->symbolName = strdup(_symbolName);
			sp->refInfoList = 0;
			return sp;
		}

		if(++sp >= symbolTableHash + SIZE_SYMBOL_TABLE)
		{
			sp = symbolTableHash; //try the next entry
		}
	}
	fputs("symbol table overflow\n", stderr);
	abort(); /* tried them all, table is full */

	return 0;
}

int addSymbolRef(int _lineno, char * _fileName, char * _word, int _flag)
{
	refList * newReference = 0;	//Fill the informations about reference.
	symbol * sp = 0;

	sp = lookUp(_word);

	//Don't do dups
	if(sp->refInfoList &&
		sp->refInfoList->lineno == _lineno &&
		sp->refInfoList->fileName == _fileName)
	{
		return -1;
	}

	newReference = malloc(sizeof(refList));
	if(!newReference)
	{
		fputs("out of space\n", stderr); abort();
		return -1;
	}

	newReference->next = sp->refInfoList;
	newReference->fileName = _fileName;
	newReference->lineno = _lineno;
	newReference->flags = _flag;
	sp->refInfoList = newReference;

	return 1;
}


//============== REMOVE THIS FUNCTION FOR ANOTHER FILE
static int symcompare(const void * xa, const void * xb)
{
	const symbol *a = xa;
	const symbol *b = xb;

	if(!a->symbolName)
	{
		if(!b->symbolName) return 0;	/* both empty */
		return 1;	/* put empties at the end */
	}
	if(!b->symbolName)
	{
		return -1;
	}
	return strcmp(a->symbolName, b->symbolName);
}

void printrefs()
{
	symbol * sp = 0;

	qsort(symbolTableHash, SIZE_SYMBOL_TABLE, sizeof(symbol), symcompare); /* sort the symbol table */

	for(sp = symbolTableHash; sp->symbolName && sp < symbolTableHash + SIZE_SYMBOL_TABLE; sp++)
	{
		char * prevfn = 0;	/* last printed filename, to skip dups */

		/* reverse the list of references */
		refList * rp = sp->refInfoList;
		refList * rpp = 0;	/* previous ref */
		refList * rpn;	/* next ref */

		do
		{
			rpn = rp->next;
			rp->next = rpp;
			rpp = rp;
			rp = rpn;
		} while(rp);

		/* now print the word and its references */
		printf("%10s", sp->symbolName);
		for(rp = rpp; rp; rp = rp->next)
		{
			if(rp->fileName == prevfn)
			{
				printf(" %d", rp->lineno);
			}
			else
			{
				printf(" %s:%d", rp->fileName, rp->lineno);
				prevfn = rp->fileName;
			}
			if(rp->flags & 01)
			{
				printf("*");
			}
		}
		printf("\n");
	}
}
