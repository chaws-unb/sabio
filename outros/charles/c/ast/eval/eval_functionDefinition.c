#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../ast.h"

void * eval_functionDefinition(declaration * func)
{
	if(debugMode) printf("Begin of '%s' defintion...", func->sym->name);

	// Only evaluate its body
	return eval(func->sym->function);
}
