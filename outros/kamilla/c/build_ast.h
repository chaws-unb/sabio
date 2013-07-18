/**
 * @file buildAST.h
 * @brief Keeps general definitions of structures to build the AST.
 **/

#ifndef _BUILD_AST_H_
#define _BUILD_AST_H_


enum nodeType
{
	typeSpecifier,
	unaryOperatorPlus,	
	unaryOperatorMinus,
	unaryOperatorMul,
	unaryOperatorDiv,			
	ifCondition,
	elseCondition
};

/**
 * @struct _ast
 * @brief Nodes to build the AST
 **/
typedef struct _ast {
	enum nodeType nodeType;
	char *value;
	struct ast *leftTree;
	struct ast *rightTree;
}ast;

/**
* @param _nodeType 
* @param _value 
* @param _leftTree 
* @param _rightTree
* @return Upon succesfull completition, addSymbolRef() shall return a
* non-negative integer. Otherwise, the function shall return one negative
* number that correspond an internal code error.
* @brief Every time that one symbol is found, this function is involked
* 	for add them in a list of symbol.
*/
struct ast *newAST(enum nodeType _nodeType, char *_value, struct ast *_leftTree, struct ast *_rightTree);

#endif
