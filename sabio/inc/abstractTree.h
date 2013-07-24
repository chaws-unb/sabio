/**
 * @file abstractTree.h
 * @brief Functions to handle Abstract Tree
**/
#ifndef _ABSTRACT_TREE_H_
#define _ABSTRACT_TREE_H_

#include <dataType.h>

typedef struct 
{
	genericType type;
	symbol * sym;
} identifier;

/**
 * @param _nodeType Node type of new node.
 * @param _left Reference to left side of tree.
 * @param _right Reference to right side of tree.
 * @return Reference to new node.
 * @brief Creates one new node in abstract tree and return the reference.
 * @see dataType.h
 **/
extern abstractTree * newAbstractTree(int _nodeType, abstractTree * _left, abstractTree * _right);
/**
 * @param _cmpType Type of new node.
 * @param _left Reference to left side in abstract tree.
 * @param _right Reference to right side in abstract tree.
 * @return Returns the reference to new node.
 * @brief Create a node for comparation.
 **/
extern abstractTree * newCmp(int _cmpType, abstractTree * _left, abstractTree * _right);
/**
 * @param _funcType Funtion type.
 * @param _left Reference to left side in abstract tree.
 * @return Reference to new node.
 * @brief Create a new node for function.
 **/
extern abstractTree * newFunc(int _funcType, abstractTree * _left);
/**
 * @param _sym Symbol reference.
 * @param _left Reference to left side in abtract tree.
 * @return Reference to new node 
 * @brief Create a new node for user call.
 **/
extern abstractTree * newUserCall(symbol * _sym, abstractTree * _left);
/**
 * @param _sym Reference to symbol
 * @return Reference to new node.
 * @brief Create a new node for reference.
 **/
extern abstractTree * newRef(symbol * _sym);
/**
 * @param _sym Reference to symbol.
 * @param _value Value that will be assign to symbol.
 * @return Reference to new node.
 * @brief Doing the assignment.
 **/
extern abstractTree * newAsgn(symbol * _sym, abstractTree * _value);
/**
 * @param _value
 * @return Reference to new node.
 * @brief Create new node and returns the reference.
 **/
extern abstractTree * newNum(double _value);
/**
 * @param _nodeType Type of flow control.
 * @param _cond Expression of condition.
 * @param _tl 'Then' in if condition.
 * @parma _tr 'else' in if condition.
 * @return Referece to new node.
 * @brief Create new node for handle conditional flow. 
 **/
extern abstractTree * newFlow(int _nodeType, abstractTree * _cond, abstractTree * _thenList, abstractTree * _elseList);
/**
 * @param _name Name of function
 * @param _syms List of reference (parameters).
 * @param _stmts 
 * @brief Define a function.
 **/
extern void dodef(symbol * _name, symlist * _syms, abstractTree * _stmts);
/**
 * @param _stmt Evaluation the command.
 * @return Result of expression.
 * @brief Evaluate an abstractTree.
 **/
extern double eval(abstractTree * _stmt);
extern abstractTree * newNum(double _value);
/* delete and free an abstractTree */
extern void treefree(abstractTree * );

extern void * eval_identifier(identifier * id);

extern abstractTree * newIdentifier(symbol * sym);

/* interface to the lexer */
extern int yylineno; /* from lexer */
extern void yyerror(char *s, ...);

extern int debug;
extern void dumpabstractTree(abstractTree * _absTree, int _level);

#endif
