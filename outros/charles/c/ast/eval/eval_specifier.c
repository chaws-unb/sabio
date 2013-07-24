#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "../ast.h"

void * eval_specifier(specifier * spec, xmlNode * out)
{
	return &spec->dataType;
}
