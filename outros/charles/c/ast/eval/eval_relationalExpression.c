#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../ast.h"

void * eval_relationalExpression(relationalExpression * rel)
{
	double * result = (double *)malloc(sizeof(double));
	*result = 0.0;
	switch(rel->relationType)
	{
		case LT: 	
			*result = ((*(double *)eval(rel->left)) <  (*(double *)eval(rel->right)));
			break;

		case GT: 	
			*result = ((*(double *)eval(rel->left)) >  (*(double *)eval(rel->right)));
			break;

		case LTE:	
			*result = ((*(double *)eval(rel->left)) <= (*(double *)eval(rel->right)));
			break;

		case GTE:	
			*result = ((*(double *)eval(rel->left)) >= (*(double *)eval(rel->right)));
			break;

		case EQ: 	
			*result = ((*(double *)eval(rel->left)) == (*(double *)eval(rel->right)));
			break;

		case NEQ:	
			*result = ((*(double *)eval(rel->left)) != (*(double *)eval(rel->right)));
			break;

		case OR: 	
			*result = ((*(double *)eval(rel->left)) || (*(double *)eval(rel->right)));
			break;

		case AND:	
			*result = ((*(double *)eval(rel->left)) && (*(double *)eval(rel->right)));
			break;

		default:
			printf("Error: Unkown logical expression!\n");
	}
	return result;
}
