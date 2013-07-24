#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../cGrammar.h"


void * iteration_statement__WHILE__OPP__expression__CLP__statement(ast * _expression, ast * _statement)
{
	if(debugMode)
	{
		printf(": iteration_statement->WHILE ( expression ) statement\n");
	}
	//Here we have a new node in the trunk. Therefore we create and returns.
	return newWhileStatement(_expression, _statement);
}


void * iteration_statement__DO__statement__WHILE__OPP__expression__CLP__SEMICOLON()
{
	
}


void * iteration_statement__FOR__OPP__expression_statement__expression_statement__CLP__statement()
{
	
}


void * iteration_statement__FOR__OPP__expression_statement__expression_statement__expression__CLP__statement()
{
	
}



