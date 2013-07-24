#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../cGrammar.h"


void * argument_expression_list__assignment_expression(ast * tree)
{
	if(debugMode) printf(": argument_expression_list->assignment_expression \n");
	return tree;
}


void * argument_expression_list__argument_expression_list__COMMA__assignment_expression(ast * list, ast * newNode)
{
	if(debugMode) printf(": argument_expression_list->argument_expression_list,assignment_expression \n");
	return newAstList(list, newNode);
}



