#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../cGrammar.h"


void * multiplicative_expression__cast_expression(ast * expr)
{
	if(debugMode) printf(": multiplicative_expression->cast_expression\n");
	return expr;
}


void * multiplicative_expression__multiplicative_expression__STAR__cast_expression(ast * right, ast * left)
{
	if(debugMode) printf(": multiplicative_expression->cast_expression\n");
	return newMathOperation(MUL, left, right);
}


void * multiplicative_expression__multiplicative_expression__SLASH__cast_expression(ast * right, ast * left)
{
	if(debugMode) printf(": multiplicative_expression->multiplicative_expression / cast_expression\n");
	return newMathOperation(DIV, left, right);
}


void * multiplicative_expression__multiplicative_expression__PERC__cast_expression(ast * right, ast * left)
{
	if(debugMode) printf(": multiplicative_expression->multiplicative_expression %% cast_expression\n");
	return newMathOperation(MOD, left, right);
}



