#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../cGrammar.h"


void * external_declaration__function_definition()
{
	
}


void * external_declaration__declaration(ast * tree)
{
	if(debugMode) printf(": external_declaration->declaration\n");
	mainProgram->next = newProgramNode(tree);
	mainProgram = mainProgram->next;
}


/*
	//mainProgram->next = 
	//mainProgram = mainProgram->next;
	// Create a new AST as a declaration node
	//ast * newNode = newDeclaration(currentSymbol);

	// Set the currentValue, which is another AST of a constant, expression, etc
	//newNode->right = (ast *)currentValue; // yeah, we cast void * * to ast *

	// Make this node as the next step of previous AST
	//mainProgram->next = newProgramNode(newNode);

	// Now, the current tree is this node
	// Remember the first tree is stored in main.c for later evaluation hehe
	//mainProgram = mainProgram->next;

	// Clean all other things
	*/
