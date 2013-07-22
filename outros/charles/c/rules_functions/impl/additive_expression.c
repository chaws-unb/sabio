#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../cGrammar.h"

void * additive_expression__multiplicative_expression()
{
	if(debugMode) printf(": additive_expression->multiplicative_expression\n");
}

void * additive_expression__additive_expression__PLUS__multiplicative_expression()
{
	if(debugMode) printf(": additive_expression->additive_expression + multiplicative_expression\n");

}

void * additive_expression__additive_expression__MINUS__multiplicative_expression()
{
	if(debugMode) printf(": additive_expression->additive_expression - multiplicative_expression\n");
}
