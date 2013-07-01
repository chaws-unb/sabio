/* Companion source code for "flex & bison", published by O'Reilly
 * Media, ISBN 978-0-596-15597-1
 * Copyright (c) 2009, Taughannock Networks. All rights reserved.
 * See the README file for license conditions and contact info.
 * $Header: /home/johnl/flnb/code/RCS/fb3-1.h,v 2.1 2009/11/08 02:53:18 johnl Exp $
 */
/*
 * Declarations for a calculator fb3-1
 */

/* Para escrever num XML !!! MULK DOIDO!!! */
#include "../xml/simpleXML.h"

/* interface to the lexer */
extern int yylineno; /* from lexer */
extern FILE * yyin;
void yyerror(char *s, ...);

/* nodes in the Abstract Syntax Tree */
struct ast {
  int nodetype;
  struct ast *l;
  struct ast *r;
};

struct numval {
  int nodetype;			/* type K */
  double number;
};

/* build an AST */
struct ast *newast(int nodetype, struct ast *l, struct ast *r);
struct ast *newnum(double d);

/* evaluate an AST and writes it into a xml file =D */
double eval(struct ast *, xmlNode * xml);

/* delete and free an AST */
void treefree(struct ast *);
