#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../cGrammar.h"

// THIS MY FRIEND IS AN EMPTY STATEMENT!
void * expression_statement__SEMICOLON()
{
	// Make this node as the next step of previous AST
	mainProgram->next = newProgramNode(NULL);

	// Now, the current tree is this node
	// Remember the first tree is stored in main.c for later evaluation hehe
	mainProgram = mainProgram->next;
}


void * expression_statement__expression__SEMICOLON(ast * expr)
{
	if(debugMode) printf(" : expression_statement->expression ;\n");

	// Make this node as the next step of previous AST
	mainProgram->next = newProgramNode(expr);

	// Now, the current tree is this node
	// Remember the first tree is stored in main.c for later evaluation hehe
	mainProgram = mainProgram->next;

	return expr;
}



