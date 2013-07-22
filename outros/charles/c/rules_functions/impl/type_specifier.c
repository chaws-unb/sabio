#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../cGrammar.h"

void * type_specifier__VOID()
{
	if(debugMode)
		printf(": type_specifier->VOID\n");

	currentSymbolDataType = _VOID;
}

void * type_specifier__CHAR()
{
	if(debugMode)
		printf(": type_specifier->CHAR\n");

	currentSymbolDataType = _CHAR;
}

void * type_specifier__SHORT()
{
	if(debugMode)
		printf(": type_specifier->SHORT\n");

	currentSymbolDataType = _SHORT;
}

void * type_specifier__INT()
{
	if(debugMode)
		printf(": type_specifier->INT\n");

	currentSymbolDataType = _INT;
}

void * type_specifier__LONG()
{
	//if(debugMode)
		printf(": type_specifier->LONG *** Not working yet...\n");
}

void * type_specifier__FLOAT()
{
	if(debugMode)
		printf(": type_specifier->FLOAT\n");

	currentSymbolDataType = _FLOAT;
}

void * type_specifier__DOUBLE()
{
	if(debugMode)
		printf(": type_specifier->DOUBLE\n");

	currentSymbolDataType = _DOUBLE;
}

void * type_specifier__SIGNED()
{
	//if(debugMode)
		printf(": type_specifier->SIGNED *** Not working yet...\n");
}

void * type_specifier__UNSIGNED()
{
	//if(debugMode)
		printf(": type_specifier->UNSIGNED *** Not working yet...\n");
}

void * type_specifier__struct_or_union_specifier()
{
	//if(debugMode)
		printf(": type_specifier->struct_or_union_specifier *** Not working yet...\n");
}

void * type_specifier__enum_specifier()
{
	//if(debugMode)
		printf(": type_specifier->enum_specifier *** Not working yet...\n");
}

void * type_specifier__TYPE_NAME()
{
	//if(debugMode)
		printf(": type_specifier->TYPE_NAME *** Not working yet...\n");
}
