#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../cGrammar.h"


void * statement__labeled_statement(ast * stmt)
{
	if(debugMode) printf(": statement->labeled_statement\n");
	return stmt;
}


void * statement__compound_statement(ast * stmt)
{
	if(debugMode) printf(": statement->compound_statement\n");
	return stmt;
}


void * statement__expression_statement(ast * stmt)
{
	if(debugMode) printf(" : statement->expression_statement\n");
	return stmt;
}


void * statement__selection_statement(ast * stmt)
{
	if(debugMode) printf(": statement->selection_statement\n");
	return stmt;
}


void * statement__iteration_statement(ast * stmt)
{
	if(debugMode) printf(": statement->iteration_statement\n");
	return stmt;
}


void * statement__jump_statement(ast * stmt)
{
	if(debugMode) printf(": statement->jump_statement\n");
	return stmt;
}



