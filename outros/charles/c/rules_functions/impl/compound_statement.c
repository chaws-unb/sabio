#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../cGrammar.h"


void * compound_statement__OPB__CLB()
{
	if(debugMode) printf(": compound_statement->{ }\n");

	ast * tree = newAst(EMPTY, NULL, NULL);

	// Make this node as the next step of previous AST
	//mainProgram->next = newProgramNode(tree);

	// Now, the current tree is this node
	// Remember the first tree is stored in main.c for later evaluation hehe
	//mainProgram = mainProgram->next;

	return tree;
}


void * compound_statement__OPB__statement_list__CLB()
{
	
}


void * compound_statement__OPB__declaration_list__CLB()
{
	
}


void * compound_statement__OPB__declaration_list__statement_list__CLB()
{
	
}



