#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../cGrammar.h"


void * expression__assignment_expression(ast * tree)
{
	if(debugMode) printf(": expression->assignment_expression\n");
	return tree;
}


void * expression__expression__COMMA__assignment_expression()
{
	
}



