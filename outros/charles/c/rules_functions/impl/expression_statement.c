#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../cGrammar.h"

// THIS, MY FRIEND, IS AN EMPTY STATEMENT!
void * expression_statement__SEMICOLON()
{
	if(debugMode) printf(" : expression_statement->;\n");
	return newAst(EMPTY, NULL, NULL);
}

void * expression_statement__expression__SEMICOLON(ast * expr)
{
	if(debugMode) printf(" : expression_statement->expression ;\n");
	return expr;
}



