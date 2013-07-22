#include "hash.h"
#include "../ast/ast.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#ifndef new
	#define new(type) ((type *)malloc(sizeof(type)))
#endif

/**
 * Hash function
 */
static unsigned int symbolHash(char * symbolName)
{
    unsigned int hash = 0;
	unsigned char c;

	if(strlen(symbolName) > 5)
	{
		printf("Symbol name %s is too long for this program!\n", symbolName);
		exit(0);
	}

	while(c = *symbolName++)
		hash = hash * 9 ^ c;

	return hash;
}

/**
 *	Look up for a symbol name, otherwise insert it
 */
symbol * lookup(char * symbolName)
{
	//printf("SymbolName before: %s\n", symbolName);
	// % here means AVOID BUFFER OVERFLOW!!!
	symbol * sym = &(symbolTable[symbolHash(symbolName) % MAX_HASH]);
	//printf("SymbolName after: %s\n", sym->name);

	// Counter to track how many looked symbols
	//int scount = MAX_HASH;

	//while(--scount >= 0)
	//{
		// Check if already exists
		if(sym->name && !strcmp(sym->name, symbolName))
			return sym;

		// Ops, no name means empty set
		//if(!sym->name)
		//{
			sym->name = strdup(symbolName);
			sym->value = 0;
			sym->function = NULL;
			sym->symbols = NULL;
			return sym;
		//}

		// Let's try next hash table entry
		//if(++sym >= (symbolTable + MAX_HASH))
		//	sym = symbolTable; // OK, this line is useless!!!
	//}

	//yyerror("Symbol Table overflow! Watch out! \n");
	//abort();
}