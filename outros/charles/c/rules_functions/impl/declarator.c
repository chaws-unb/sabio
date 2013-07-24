#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../cGrammar.h"


void * declarator__pointer__direct_declarator()
{
	
}


void * declarator__direct_declarator(ast * tree)
{
	if(debugMode) printf(": declarator->direct_declarator\n");

	return tree;
}



