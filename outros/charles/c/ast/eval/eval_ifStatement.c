#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../ast.h"

void * eval_ifStatement(ifStatement * ifStmt, xmlNode * out)
{
	xmlNode * center = createNode(out, "if");
	xmlNode * expr = createNode(center, "expression");
	xmlNode * stmtTrue = createNode(center, "true");

	int expressionResult = (int)(*(double *)eval(ifStmt->expr, expr));

	if(expressionResult)
		eval(ifStmt->ifTrue, stmtTrue);
	// Not execute else 
	if(ifStmt->ifFalse)
	{
		xmlNode * stmtFalse = createNode(center, "false");
		eval(ifStmt->ifFalse, stmtFalse);
	}
}
