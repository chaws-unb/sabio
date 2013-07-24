#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../ast.h"

void * eval_astList(astList * list, xmlNode * out)
{
	astList * temp = list;
	while(temp)
	{
		eval(temp->node, out);
		temp = temp->next;
	}
	
	return NULL;
}
