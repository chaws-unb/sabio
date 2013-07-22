#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../ast.h"

void * eval_identifier(identifier * id)
{
	return id->sym;
}
