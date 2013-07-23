#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../cGrammar.h"


void * expression_statement__SEMICOLON()
{
	
}


void * expression_statement__expression__SEMICOLON(ast * expr)
{
	if(debugMode) printf(" : expression_statement->expression ;\n");
	return expr;
}



