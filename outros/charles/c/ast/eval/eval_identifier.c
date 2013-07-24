#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../ast.h"

void * eval_identifier(identifier * id, xmlNode * out)
{
	if(debugMode) printf("Identifier '%s' \n", id->sym->name);
	xmlNode * child = createNode(xml, "identifier");
	addAttribute(child, "name", id->sym->name);
	return id->sym;
}
