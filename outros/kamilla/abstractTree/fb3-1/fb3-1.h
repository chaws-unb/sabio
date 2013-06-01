extern int yylineno;
void yyerror(char *s);

struct ast {
  int nodetype;
  struct ast *l;
  struct ast *r;
}

struct numval {
  int nodetype;
  double number;
}

/*build an AST*/
struct ast *newast(int nodetype, struct ast *l, struct ast *r);
struct ast *newnum(double d);

/*evaluate an AST*/
double eval(struct ast *);

/*detele and free and AST*/
void treefree(struct ast *);
