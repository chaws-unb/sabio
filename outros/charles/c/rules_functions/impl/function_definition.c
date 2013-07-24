#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../cGrammar.h"


void * function_definition__declaration_specifiers__declarator__declaration_list__compound_statement()
{
	
}

// When it get here, it needs to set the function and symbollist of the identifier symbol
// Also change the type to FUNCTION_DEFINITION
void * function_definition__declaration_specifiers__declarator__compound_statement(ast * spec, ast * decl, ast * stmts)
{
	if(debugMode) printf(": function_definition->declaration_specifiers declarator compound_statement\n");

	declaration * func = (declaration *) decl;
	func->type = FUNCTION_DEFINITION;
	func->sym->function = stmts;


	// Make this node as the next step of previous AST
	mainProgram->next = newProgramNode((ast *)func);

	// Now, the current tree is this node
	// Remember the first tree is stored in main.c for later evaluation hehe
	mainProgram = mainProgram->next;
}


void * function_definition__declarator__declaration_list__compound_statement()
{
	
}


void * function_definition__declarator__compound_statement()
{
	
}



