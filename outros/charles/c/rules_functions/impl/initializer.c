#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../cGrammar.h"

void * initializer__assignment_expression(ast * tree)
{
	if(debugMode) printf(": initializer->assignment_expression\n");
	return tree;
}


void * initializer__OPB__initializer_list__CLB(ast * tree)
{
	if(debugMode) printf(": initializer->{ initializer_list }\n");
	return tree;
}


void * initializer__OPB__initializer_list__COMMA__CLB(ast * tree)
{
	if(debugMode) printf(": initializer->{ initializer_list , }\n");
	return tree;
}



