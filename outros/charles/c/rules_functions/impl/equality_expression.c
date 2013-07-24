#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../cGrammar.h"


void * equality_expression__relational_expression(ast * expr)
{
	if(debugMode) printf(": equality_expression->relational_expression\n");
	return expr;
}


void * equality_expression__equality_expression__EQ_OP__relational_expression(ast * left, ast * right)
{
	if(debugMode) printf(": equality_expression->equality_expression == relational_expression\n");
	return newRelationalExpression(EQ, left, right);
}


void * equality_expression__equality_expression__NE_OP__relational_expression(ast * left, ast * right)
{
	if(debugMode) printf(": equality_expression->equality_expression != relational_expression\n");
	return newRelationalExpression(NEQ, left, right);
}



