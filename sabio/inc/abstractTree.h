/**
*	@file abstractTree.h
*	@brief Functions to handle Abstract Tree
**/
#ifndef _ABSTRACT_TREE_H_
#define _ABSTRACT_TREE_H_

/* node types
 *  + - * / |
 *  0-7 comparison ops, bit coded 04 equal, 02 less, 01 greater
 *  M unary minus
 *  L statement list
 *  I IF statement
 *  W WHILE statement
 *  N symbol ref
 *  = assignment
 *  S list of symbols
 *  F built in function call
 *  C user function call
 */ 
enum builtInfFunctions {			/* built-in functions */
  B_sqrt = 1,
  B_exp,
  B_log,
  B_print
};


/* nodes in the Abstract Syntax Tree */
/* all have common initial nodetype */

typedef struct _abstractTree {
  int nodetype;
  struct abstractTree *l;
  struct abstractTree *r;
}abstractTree;

typedef struct _builtInFuncCall {			/* built-in function */
  int nodetype;			/* type F */
  struct abstractTree *l;
  enum builtInfFunctions functype;
}builtInFuncCall;

typedef struct _userFuncCall {		/* user function */
  int nodetype;			/* type C */
  struct abstractTree *l;		/* list of arguments */
  struct symbol *s;
}userFuncCall;

typedef struct _flow {
  int nodetype;			/* type I or W */
  struct abstractTree *condition;		/* condition */
  struct abstractTree *thenList;		/* then or do list */
  struct abstractTree *elseList;		/* optional else list */
};

typedef struct _numValue {
  int nodetype;			/* type K */
  double number;
}numValue;

typedef struct _symbomRef {
  int nodetype;			/* type N */
  struct symbol *s;
} symbomRef;

typedef struct _symAsgn {
  int nodetype;			/* type = */
  struct symbol *s;
  struct abstractTree *v;		/* value */
} symasgn;

/* build an abstractTree */
struct abstractTree *newabstractTree(int nodetype, struct abstractTree *l, struct abstractTree *r);
struct abstractTree *newcmp(int cmptype, struct abstractTree *l, struct abstractTree *r);
struct abstractTree *newfunc(int functype, struct abstractTree *l);
struct abstractTree *newcall(struct symbol *s, struct abstractTree *l);
struct abstractTree *newref(struct symbol *s);
struct abstractTree *newasgn(struct symbol *s, struct abstractTree *v);
struct abstractTree *newnum(double d);
struct abstractTree *newflow(int nodetype, struct abstractTree *cond, struct abstractTree *tl, struct abstractTree *tr);

/* define a function */
void dodef(struct symbol *name, struct refList *syms, struct abstractTree *stmts);

/* evaluate an abstractTree */
double eval(struct abstractTree *);

/* delete and free an abstractTree */
void treefree(struct abstractTree *);

/* interface to the lexer */
extern int yylineno; /* from lexer */
void yyerror(char *s, ...);

extern int debug;
void dumpabstractTree(struct abstractTree *a, int level);

#endif