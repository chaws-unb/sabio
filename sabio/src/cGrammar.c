#include <stdio.h>
#include <cGrammar.h>
#include <dataType.h>
#include <symbolTable.h>
#include <abstractTree.h>

void * postfixExpression_IDENTIFIER(char * _absTree)
{
	puts(": direct_declarator->IDENTIFIER");

	// Build a new symbol
	currentSymbol = NULL; // only frees after eval
	currentSymbol = lookUp(_absTree);
	currentSymbol->dataType = currentSymbolDataType;
	return newIdentifier(currentSymbol);
}

