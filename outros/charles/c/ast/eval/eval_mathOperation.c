#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../ast.h"

void * eval_mathOperation(mathOperation * op, xmlNode * out)
{
	xmlNode * center = createNode(out, "mathOperation");
	xmlNode * left = createNode(center, "left");
	xmlNode * right = createNode(center, "right");

	double * returned = new(double);
	double tempAvoidZero = 0.0;
	int tempAvoidZeroInt = 0;
	switch(op->type)
	{
		case SUM: 
			addAttribute(center, "type", "+");
			*returned = (*(double *)eval(op->left, left) + *(double *)eval(op->right, right));
			break;
		case SUB: 
			addAttribute(center, "type", "-");
			*returned = (*(double *)eval(op->left, left) - *(double *)eval(op->right, right));
			break;
		case DIV: 
			addAttribute(center, "type", "/");
			tempAvoidZero = *(double *)eval(op->right, right);
			if(tempAvoidZero == 0.0)
			{
				printf("Ops! Never divide by zero!\n Program will exit now!\n");
				exit(-1);
			}
			*returned = (*(double *)eval(op->left, left) / tempAvoidZero);
			break;
		case MUL: 
			addAttribute(center, "type", "*");
			*returned = (*(double *)eval(op->left, left) * *(double *)eval(op->right, right));
			break;
		case MOD: 
			addAttribute(center, "type", "%%");
			tempAvoidZeroInt = (int)(*(double *)eval(op->right, right));
			if(tempAvoidZeroInt == 0)
			{
				printf("Ops! Never mod by zero!\n Program will exit now!\n");
				exit(-1);
			}
			*returned = ((int)(*(double *)eval(op->left, left)) % tempAvoidZeroInt);
			break;
		default:
			printf("Ops! Math operator not found!\n");
	}
	return returned;
}