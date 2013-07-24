#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../ast.h"

void * eval_functionDefinition(declaration * func, xmlNode * out)
{
	if(debugMode) printf("Begin of '%s' defintion...", func->sym->name);

	xmlNode * center = createNode(out, "functionDefinition");
	addAttribute(center, "name", func->sym->name);

	xmlNode * body = createNode(center, "body");

	// Only evaluate its body
	return eval(func->sym->function, body);
}
