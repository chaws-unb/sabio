#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../ast.h"

void * eval_whileStatement(whileStatement * whileStmt, xmlNode * out)
{
	xmlNode * center = createNode(out, "while");
	xmlNode * expr = createNode(center, "expression");
	xmlNode * stmt = createNode(center, "statement");
	
	eval(whileStmt->expr, expr);
	eval(whileStmt->statm, stmt);

	// It's not needed to execute =)
	//int expressionResult = (int)(*(double *)eval(_whileStmt->expr, out));

	/*if(expressionResult)
	{
		while(eval(_whileStmt->expr, out) != 0)
		{
			eval(_whileStmt->statm, out);
		}
	}*/

	return 0;
}
