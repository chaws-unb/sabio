#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../ast.h"

void * eval_identifier(identifier * id)
{
	if(debugMode) printf("Identifier '%s' \n", id->sym->name);
	return id->sym;
}
