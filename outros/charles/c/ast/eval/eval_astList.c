#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../ast.h"

void * eval_astList(astList * list)
{
	astList * temp = list;
	while(temp)
	{
		eval(temp->node);
		temp = temp->next;
	}
	
	return NULL;
}
