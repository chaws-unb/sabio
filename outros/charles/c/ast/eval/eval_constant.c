#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../ast.h"


void * eval_constant(constant * cons, xmlNode * out)
{
	if(debugMode)
		printf("Constant value = %.2f\n", *(&cons->value));

	//printf("que caralho eh esse????? %p\n", xml);
	xmlNode * center = createNode(out, "constant");
	char * valueTxt = (char *)malloc(5*sizeof(char));
	// Salva num arquivo
    sprintf(valueTxt, "%.2g", cons->value);
    addAttribute(center, "value", valueTxt);
	
	return &cons->value;
}
