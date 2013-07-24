#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../ast.h"

void * eval_relationalExpression(relationalExpression * rel, xmlNode * out)
{
	double * result = (double *)malloc(sizeof(double));
	*result = 0.0;

	// Cria o no dessa arvore
  	xmlNode * leftNode = NULL, * rightNode = NULL, * center = NULL;
	center = createNode(out, "relationalExpression"); 
	leftNode = createNode(center, "left"); 
    rightNode = createNode(center, "right"); 

	switch(rel->relationType)
	{
		case LT:
			addAttribute(center, "type", "<"); 	
			*result = ((*(double *)eval(rel->left, leftNode)) <  (*(double *)eval(rel->right, rightNode)));
			break;

		case GT: 	
			addAttribute(center, "type", ">");
			*result = ((*(double *)eval(rel->left, leftNode)) >  (*(double *)eval(rel->right, rightNode)));
			break;

		case LTE:
			addAttribute(center, "type", "<=");	
			*result = ((*(double *)eval(rel->left, leftNode)) <= (*(double *)eval(rel->right, rightNode)));
			break;

		case GTE:	
			addAttribute(center, "type", ">=");	
			*result = ((*(double *)eval(rel->left, leftNode)) >= (*(double *)eval(rel->right, rightNode)));
			break;

		case EQ: 
			addAttribute(center, "type", "==");	
			*result = ((*(double *)eval(rel->left, leftNode)) == (*(double *)eval(rel->right, rightNode)));
			break;

		case NEQ:	
			addAttribute(center, "type", "!=");
			*result = ((*(double *)eval(rel->left, leftNode)) != (*(double *)eval(rel->right, rightNode)));
			break;

		case OR: 	
			addAttribute(center, "type", "||");
			*result = ((*(double *)eval(rel->left, leftNode)) || (*(double *)eval(rel->right, rightNode)));
			break;

		case AND:	
			addAttribute(center, "type", "&&");
			*result = ((*(double *)eval(rel->left, leftNode)) && (*(double *)eval(rel->right, rightNode)));
			break;

		default:
			addAttribute(center, "type", "Unkown logical expression!");
			printf("Error: Unkown logical expression!\n");
	}
	return result;
}
