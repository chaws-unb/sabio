#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include "build_ast.h"

struct ast *newAST(enum nodeType _nodeType, char *_value, struct ast *_leftTree, struct ast *_rightTree){

	struct ast *newAST = malloc(sizeof(struct ast*));
	
	if(!newAST) {
    	yyerror("Out of space to create the new AST");
    	exit(0);
  	}

	*newAST->nodeType = _nodeType;
	*newAST->leftTree = _leftTree;
	*newAST->rightTree = _rightTree;
	
	return newAST;
}
