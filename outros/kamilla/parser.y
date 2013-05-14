%{
#include <stdio.h>
#include <string.h>

void yyerror(const char *str)
{
  fprintf(stderr,"error: %s\n",str);
}

int yywrap()
{
  return 1;
}

main()
{
  yyparse();
}

%}

%token WORD NUMBER FILENAME QUOTE OBRACE EBRACE SEMICOLON PLUS MINUS MULT DIV;

%%

commands:
  | commands command
  ;

command: /* empty */
    | 

exp:
    NUMBER
    | 
    exp '+' exp
    |
    exp '-' exp
    |
    exp '*' exp
    ;
  





