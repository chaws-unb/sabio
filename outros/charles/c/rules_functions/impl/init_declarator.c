#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../cGrammar.h"


void * init_declarator__declarator(ast * tree)
{
	if(debugMode) printf(": init_declarator->declarator\n");
	return tree;
}


void * init_declarator__declarator__EQ__initializer(ast * decl, ast * init)
{
	if(debugMode) printf(": init_declarator->declarator = initializer\n");

	declaration * tree = newDeclaration(decl, init);
	return (ast *)tree;
}



