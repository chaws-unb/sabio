#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../cGrammar.h"


void * init_declarator__declarator()
{
	
}


void * init_declarator__declarator__EQ__initializer(ast * decl, ast * init)
{
	if(debugMode) printf(": init_declarator->declarator = initializer\n");

	declaration * tree = newDeclaration(decl, init);
	return (ast *)tree;
}



