#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../ast.h"

void * eval_whileStatement(whileStatement * _whileStmt)
{
	int expressionResult = (int)(*(double *)eval(_whileStmt->expr));

	if(expressionResult)
	{
		while(eval(_whileStmt->expr) != 0)
		{
			expressionResult = eval(_whileStmt->statm);
		}
	}

	return 0;
}
