#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../cGrammar.h"


void * init_declarator_list__init_declarator(ast * tree)
{
	if(debugMode) printf(": init_declarator_list->init_declarator\n");
	return tree;
}


void * init_declarator_list__init_declarator_list__COMMA__init_declarator()
{
	if(debugMode) printf(": init_declarator_list->init_declarator_list , init_declarator\n");
	
}



