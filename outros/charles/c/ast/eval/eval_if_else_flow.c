#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../ast.h"

void * eval_if_flow(ifElseStatement * if_else_flow)
{
	
	// The symbol
	if(debugMode) printf("End of if_flow declaration\n");

	if(if_else_flow->_else)
		printf("IF ELSE FLOW");
}