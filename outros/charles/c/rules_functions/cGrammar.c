#include "../ast/ast.h"
#ifndef new
	#define new(type) ((type *)malloc(sizeof(type)))
#endif

// YEAH, I KNOW, GLOBAL VARS SUCK, BUT HAVE A BETTER IDEA IN THIS SHORT AVAILABLE TIME ?
symbolDataType  currentSymbolDataType;
symbol * 		currentSymbol;
void * 			currentValue;
ast * 			currentAst;
programNode * 	mainProgram;

void initGrammar()
{
	// Do some initial work
	currentAst  	  = new(ast);
	currentAst->type  = ROOT;
	currentAst->left  = NULL;
	currentAst->right = NULL;

	// Set a default data type
	currentSymbolDataType = _VOID;

	// Create initial node and set next = NULL
	mainProgram = newProgramNode(currentAst);
}