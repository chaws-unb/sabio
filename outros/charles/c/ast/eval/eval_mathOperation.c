#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../ast.h"

void * eval_mathOperation(mathOperation * op, xmlNode * out)
{
	double * returned = new(double);
	double tempAvoidZero = 0.0;
	int tempAvoidZeroInt = 0;
	switch(op->type)
	{
		case SUM: 
			*returned = (*(double *)eval(op->left, out) + *(double *)eval(op->right, out));
			break;
		case SUB: 
			*returned = (*(double *)eval(op->left, out) - *(double *)eval(op->right, out));
			break;
		case DIV: 
			tempAvoidZero = *(double *)eval(op->right, out);
			if(tempAvoidZero == 0.0)
			{
				printf("Ops! Never divide by zero!\n Program will exit now!\n");
				exit(-1);
			}
			*returned = (*(double *)eval(op->left, out) / tempAvoidZero);
			break;
		case MUL: 
			*returned = (*(double *)eval(op->left, out) * *(double *)eval(op->right, out));
			break;
		case MOD: 
			tempAvoidZeroInt = (int)(*(double *)eval(op->right, out));
			if(tempAvoidZeroInt == 0)
			{
				printf("Ops! Never mod by zero!\n Program will exit now!\n");
				exit(-1);
			}
			*returned = ((int)(*(double *)eval(op->left, out)) % tempAvoidZeroInt);
			break;
		default:
			printf("Ops! Math operator not found!\n");
	}
	return returned;
}