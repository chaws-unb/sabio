#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../cGrammar.h"

void * additive_expression__multiplicative_expression(ast * expr)
{
	if(debugMode) printf(": additive_expression->multiplicative_expression\n");
	return expr;
}

void * additive_expression__additive_expression__PLUS__multiplicative_expression(ast * right, ast * left)
{
	if(debugMode) printf(": additive_expression->additive_expression + multiplicative_expression\n");
	return newMathOperation(SUM, right, left);
}

void * additive_expression__additive_expression__MINUS__multiplicative_expression(ast * right, ast * left)
{
	if(debugMode) printf(": additive_expression->additive_expression - multiplicative_expression\n");
	return newMathOperation(SUB, right, left);
}
