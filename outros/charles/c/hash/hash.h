#ifndef HASH
#define HASH 

#include "../ast/ast.h"

/**
 *	Simple Symbol Hash table
 */
#define MAX_HASH 9997
symbol symbolTable[MAX_HASH];

/**
 *	Lookup function for HASH table
 */
symbol * lookup(char * name);

#endif