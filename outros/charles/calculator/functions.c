/* Companion source code for "flex & bison", published by O'Reilly
 * Media, ISBN 978-0-596-15597-1
 * Copyright (c) 2009, Taughannock Networks. All rights reserved.
 * See the README file for license conditions and contact info.
 * $Header: /home/johnl/flnb/code/RCS/fb3-1funcs.c,v 2.1 2009/11/08 02:53:18 johnl Exp $
 */
/*
 * helper functions for fb3-1
 */
#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include <string.h>
#include "functions.h"
#include "../xml/simpleXML.h"

struct ast *
newast(int nodetype, struct ast *l, struct ast *r)
{
  struct ast *a = malloc(sizeof(struct ast));
  
  if(!a) {
    yyerror("out of space");
    exit(0);
  }
  a->nodetype = nodetype;
  a->l = l;
  a->r = r;
  return a;
}

struct ast *
newnum(double d)
{
  struct numval *a = malloc(sizeof(struct numval));
  
  if(!a) {
    yyerror("out of space");
    exit(0);
  }
  a->nodetype = 'K';
  a->number = d;
  return (struct ast *)a;
}

double
eval(struct ast *a, xmlNode * xml)
{
  double v;

  // Cria o no dessa arvore
  xmlNode * leftNode = NULL, * rightNode = NULL;

  switch(a->nodetype) {
  case 'K': 
    v = ((struct numval *)a)->number; 
    break;

  case '+': 
    leftNode = createNode(xml, "left"); 
    rightNode = createNode(xml, "right"); 
    v = eval(a->l, leftNode) + eval(a->r, rightNode); 
    break;

  case '-': 
    leftNode = createNode(xml, "left"); 
    rightNode = createNode(xml, "right"); 
    v = eval(a->l, leftNode) - eval(a->r, rightNode); 
    break;

  case '*': 
    leftNode = createNode(xml, "left"); 
    rightNode = createNode(xml, "right"); 
    v = eval(a->l, leftNode) * eval(a->r, rightNode); 
    break;

  case '/': 
    leftNode = createNode(xml, "left"); 
    rightNode = createNode(xml, "right"); 
    v = eval(a->l, leftNode) / eval(a->r, rightNode); 
    break;

  case '|': 
    leftNode = createNode(xml, "left"); 
    rightNode = createNode(xml, "right"); 
    v = eval(a->l, leftNode); 
    if(v < 0) 
      v = -v; 
    break;

  case 'M': 
    leftNode = createNode(xml, "left"); 
    v = -eval(a->l, leftNode); 
    break;

  default: printf("internal error: bad node %c\n", a->nodetype);
  }

  // Adiciona o resultado
  char result[10] = {0};
  char type[10] = {0};

  sprintf(result, "%.2f", v);
  sprintf(type, "%c", a->nodetype);

  addAttribute(xml, "type", type); 
  addAttribute(xml, "result", result);
    
  return v;
}

void
treefree(struct ast *a)
{
  switch(a->nodetype) {

    /* two subtrees */
  case '+':
  case '-':
  case '*':
  case '/':
    treefree(a->r);

    /* one subtree */
  case '|':
  case 'M':
    treefree(a->l);

    /* no subtree */
  case 'K':
    free(a);
    break;

  default: printf("internal error: free bad node %c\n", a->nodetype);
  }
}

void
yyerror(char *s, ...)
{
  va_list ap;
  va_start(ap, s);

  fprintf(stderr, "%d: error: ", yylineno);
  vfprintf(stderr, s, ap);
  fprintf(stderr, "\n");
}

int
main()
{
  printf("> "); 

  FILE * input = fopen("input.in", "r");
  if(!input){
    printf("Ops, no file!\n");
    return -1;  
  }

  yyin = input;

  // Faz todo parsing
  printf("\n*** INICIO ***\n");
  do
  {
    yyparse();
  }while(!feof(yyin));
  printf("\n*** FIM ***\n");

  //return yyparse();
  return 0;
}
