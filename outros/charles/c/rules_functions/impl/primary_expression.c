#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../cGrammar.h"


void * primary_expression__IDENTIFIER(char * identifier)
{
	if(debugMode) printf(": primary_expression->IDENTIFIER\n");
}


void * primary_expression__CONSTANT(double cons)
{
	if(debugMode) printf(": primary_expression->CONSTANT\n");

	// Crate the current value
	currentValue = newConstant(cons);
}


void * primary_expression__STRING_LITERAL()
{
	
}


void * primary_expression__OPP__expression__CLP()
{
	
}



