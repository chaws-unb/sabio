#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../cGrammar.h"


void declaration__declaration_specifiers__SEMICOLON()
{
	
}

// THIS FUNCTION MUST DO SOMETHING ELSE, EVAL??, SINCE IT FOUND A SEMICOLON
/**
 *	This is the kind: int a;
 *	So we probably have current symbol set
 */
void declaration__declaration_specifiers__init_declarator_list__SEMICOLON()
{
	if(debugMode) printf(": declaration->declaration_specifiers init_declarator_list ;\n");

	// Take the declaration built until now and creates an AST of it
	//currentSymbol->value = currentValue;

	// Create a new AST as a declaration node
	ast * newNode = newDeclaration(currentSymbol);

	// Set the currentValue, which is another AST of a constant, expression, etc
	newNode->right = (ast *)currentValue; // yeah, we cast void * to ast *

	// Make this node as the next step of previous AST
	mainProgram->next = newProgramNode(newNode);

	// Now, the current tree is this node
	// Remember the first tree is stored in main.c for later evaluation hehe
	mainProgram = mainProgram->next;

	// Clean all other things
	currentSymbol = NULL;
	currentValue  = NULL;
	currentAst    = NULL;
	currentSymbolDataType = _VOID;
}
