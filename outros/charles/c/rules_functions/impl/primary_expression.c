#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../cGrammar.h"

void * primary_expression__IDENTIFIER(char * name)
{
	if(debugMode) printf(": primary_expression->IDENTIFIER\n");

	symbol * sym = lookup(name);
	identifier * id = newIdentifier(sym);
	return id;
}

void * primary_expression__CONSTANT(double cons)
{
	if(debugMode) printf(": primary_expression->CONSTANT\n");

	// Crate the current value
	return newConstant(cons);

	// mainProgram->next = newProgramNode();
	// mainProgram = mainProgram->next;
}


void * primary_expression__STRING_LITERAL(char * string)
{
	if(debugMode) printf(": primary_expression->STRING_LITERAL\n");

	printf("Not implemented yet\n");
	return NULL;
}


void * primary_expression__OPP__expression__CLP(ast * expr)
{
	if(debugMode) printf(": primary_expression->(expression)\n");

	return expr;
}



