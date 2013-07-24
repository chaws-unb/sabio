#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../ast.h"

void * eval_whileStatement(whileStatement * _whileStmt, xmlNode * out)
{
	int expressionResult = (int)(*(double *)eval(_whileStmt->expr, out));

	if(expressionResult)
	{
		while(eval(_whileStmt->expr, out) != 0)
		{
			eval(_whileStmt->statm, out);
		}
	}

	return 0;
}
