#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../cGrammar.h"


void selection_statement__IF__OPP__expression__CLP__statement()
{
	if(debugMode)
		printf(": selection_statement->IF ( expression ) statement\n");

	currentSymbolType = _IF_EXP_STMT;
	
}


void selection_statement__IF__OPP__expression__CLP__statement__ELSE__statement()
{
	if(debugMode)
		printf(": selection_statement->IF ( expression ) statement ELSE statement\n");

	currentSymbolType = _IF_EXP_STMT_ELSE;
}


void selection_statement__SWITCH__OPP__expression__CLP__statement()
{
	if(debugMode)
		printf(": selection_statement->SWITCH ( expression ) statement\n");

	currentSymbolType = _SWITCH;
}



