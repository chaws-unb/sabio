#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../ast.h"


void * eval_constant(constant * cons)
{
	if(debugMode)
		printf("Evaluating constant. Value = %.2f", *(&cons->value));
	
	return &cons->value;
}
