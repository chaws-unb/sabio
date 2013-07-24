/**
 * @file symbolTable.c
 **/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "symbolTable.h"
#include "clexer.h"

static unsigned calcHash(char * _nameForHash)
{
	unsigned int hashTmp = 0;
	unsigned character = 0;

	if(strlen(_nameForHash) > 5)
	{
		printf("Symbol name %s is too long for this program!\n", _nameForHash);
		exit(0);
	}

	while((character = *_nameForHash++))
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
