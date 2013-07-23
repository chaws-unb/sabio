#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../ast.h"

void * eval_ifStatement(ifStatement * ifStmt)
{
	printf("Chamando a bagaca!!!\n");
	return NULL;
	int expressionResult = (int)(*(double *)eval(ifStmt->expr));

	if(expressionResult)
		eval(ifStmt->ifTrue);
	else if(ifStmt->ifFalse)
		eval(ifStmt->ifFalse);
}
