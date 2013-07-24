#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../cGrammar.h"


void * declaration_list__declaration(ast * node)
{
	if(debugMode) printf(": declaration_list->declaration\n");
	return node;
}


void * declaration_list__declaration_list__declaration(ast * list, ast * node)
{
	if(debugMode) printf(": declaration_list->declaration_list declaration\n");
	return newAstList(list, node);
}
