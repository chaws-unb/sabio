#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../cGrammar.h"


void * statement__labeled_statement()
{
	
}


void * statement__compound_statement()
{
	
}


void * statement__expression_statement(ast * expr)
{
	if(debugMode) printf(" : statement->expression_statement\n");
	return expr;
}


void * statement__selection_statement()
{
	
}


void * statement__iteration_statement()
{
	
}


void * statement__jump_statement()
{
	
}



