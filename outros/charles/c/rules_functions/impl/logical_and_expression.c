#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../cGrammar.h"


void * logical_and_expression__inclusive_or_expression(ast * expr)
{
	if(debugMode) printf(": logical_and_expression->inclusive_or_expression\n");
	return expr;
}


void * logical_and_expression__logical_and_expression__AND_OP__inclusive_or_expression(ast * left, ast * right)
{
	if(debugMode) printf(": logical_and_expression->logical_and_expression && inclusive_or_expression\n");
	return newRelationalExpression(AND, left, right);
}



