#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../ast.h"


void * eval_constant(constant * cons)
{
	if(debugMode)
		printf("Constant value = %.2f\n", *(&cons->value));
	
	return &cons->value;
}
