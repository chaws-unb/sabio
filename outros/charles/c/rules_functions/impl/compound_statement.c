#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../cGrammar.h"


void * compound_statement__OPB__CLB()
{
	if(debugMode) printf(": compound_statement->{ }\n");

	ast * tree = newAst(EMPTY, NULL, NULL);

	return tree;
}


void * compound_statement__OPB__statement_list__CLB(ast * list)
{
	if(debugMode) printf(": compound_statement->{ statement_list }\n");
	return list;
}


void * compound_statement__OPB__declaration_list__CLB(ast * list)
{
	if(debugMode) printf(": compound_statement->{ declaration_list }\n");
	return list;
}


void * compound_statement__OPB__declaration_list__statement_list__CLB(ast * leftList, ast * rightList)
{
	if(debugMode) printf(": compound_statement->{ declaration_list statement_list }\n");
	return newAstList(leftList, rightList);
}

