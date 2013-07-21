#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../cGrammar.h"


void direct_declarator__IDENTIFIER(char * identifier)
{
	if(debugMode) printf(": direct_declarator->IDENTIFIER\n");

	if(!identifier)
	{
		printf("NULL identifier\n");
		return;
	}

	if(debugMode) printf("identifier = %s", identifier);

	// Build a new symbol
	currentSymbol = lookup(identifier);
	currentSymbol->type = currentSymbolType;
	currentSymbol->value = currentValue;
}


void direct_declarator__OPP__declarator__CLP()
{
	
}


void direct_declarator__direct_declarator__OPC__constant_expression__CLC()
{
	
}


void direct_declarator__direct_declarator__OPC__CLC()
{
	
}


void direct_declarator__direct_declarator__OPP__parameter_type_list__CLP()
{
	
}


void direct_declarator__direct_declarator__OPP__identifier_list__CLP()
{
	
}


void direct_declarator__direct_declarator__OPP__CLP()
{
	if(debugMode) printf(": direct_declarator->direct_declarator ( )\n");
}
