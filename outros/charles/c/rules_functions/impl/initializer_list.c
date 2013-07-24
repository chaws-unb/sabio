#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../cGrammar.h"


void * initializer_list__initializer(ast * tree)
{
	if(debugMode) printf(": initializer_list->initializer\n");
	return tree;
}


void * initializer_list__initializer_list__COMMA__initializer(ast * list, ast * newNode)
{
	if(debugMode) printf(": initializer_list->initializer_list , initializer\n");

	// CREATE AN AST LIST HERE
	return newAst(EMPTY, NULL, NULL);
}



