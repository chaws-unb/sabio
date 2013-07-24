#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../cGrammar.h"


void * logical_or_expression__logical_and_expression(ast * expr)
{
	if(debugMode) printf(": logical_or_expression->logical_and_expression\n");
	return expr;
}


void * logical_or_expression__logical_or_expression__OR_OP__logical_and_expression(ast * left, ast * right)
{
	if(debugMode) printf(": logical_or_expression->logical_or_expression || logical_and_expression\n");
	return newRelationalExpression(OR, left, right);
}

