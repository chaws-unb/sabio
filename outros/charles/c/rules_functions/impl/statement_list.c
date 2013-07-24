#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../cGrammar.h"


void * statement_list__statement(ast * stmt)
{
	if(debugMode) printf(": statement_list->statement\n");
	return stmt;
}


void * statement_list__statement_list__statement(ast * list, ast * newNode)
{
	if(debugMode) printf(": statement_list->statement_list statement\n");
	return newAstList(list, newNode);
}



