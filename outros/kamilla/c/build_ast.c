#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include "build_ast.h"

struct _ast *newAST(char *_nodeType, char *_value, struct ast *_leftTree, struct ast *_rightTree){

	struct _ast *newAST = malloc(sizeof(struct _ast));
	
	if(!newAST) {
    	yyerror("Out of space to create the new AST");
    	exit(0);
  	}

	newAST->nodeType = _nodeType;
	newAST->leftTree = _leftTree;
	newAST->rightTree = _rightTree;
	
	return newAST;
}
