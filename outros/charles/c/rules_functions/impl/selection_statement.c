#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../cGrammar.h"


void * selection_statement__IF__OPP__expression__CLP__statement(ast * expr, ast * state)
{
	if(debugMode)
		printf(": selection_statement->IF ( expression ) statement\n");
	printf("Expression = %i\n", (int)((constant *)expr)->value);
	mainProgram->next = newProgramNode(newIfStatement(expr, state, NULL));
	mainProgram = mainProgram->next;
}


void * selection_statement__IF__OPP__expression__CLP__statement__ELSE__statement(ast * expression, ast * statement, ast * _else)
{
	if(debugMode)
		printf(": selection_statement->IF ( expression ) statement ELSE statement\n");

	mainProgram->next = newProgramNode(newIfStatement(expression, statement, _else));
	mainProgram = mainProgram->next;
}


void * selection_statement__SWITCH__OPP__expression__CLP__statement()
{
	if(debugMode)
		printf(": selection_statement->SWITCH ( expression ) statement\n");

	//genericType = SWITCH;
}



