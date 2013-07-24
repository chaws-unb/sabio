#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../cGrammar.h"


void * relational_expression__shift_expression(ast * expr)
{
	if(debugMode) printf(": relational_expression->shift_expression\n");
	return expr;
}


void * relational_expression__relational_expression__LT__shift_expression(ast * left, ast * right)
{
	if(debugMode) printf(": relational_expression->relational_expression < shift_expression\n");
	return newRelationalExpression(LT, left, right);
}


void * relational_expression__relational_expression__GT__shift_expression(ast * left, ast * right)
{
	
	if(debugMode) printf(": relational_expression->relational_expression > shift_expression\n");
	return newRelationalExpression(GT, left, right);
}


void * relational_expression__relational_expression__LE_OP__shift_expression(ast * left, ast * right)
{
	if(debugMode) printf(": relational_expression->relational_expression <= shift_expression\n");
	return newRelationalExpression(LTE, left, right);
}


void * relational_expression__relational_expression__GE_OP__shift_expression(ast * left, ast * right)
{
	if(debugMode) printf(": relational_expression->relational_expression >= shift_expression\n");
	return newRelationalExpression(GTE, left, right);
}
