#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../ast.h"


void * eval_constant(constant * cons)
{
	return &cons->value;
}
