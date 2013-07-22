%{
#include <stdio.h>
#include <stdlib.h>
#include <dataType.h>
#include <abstractTree.h>
%}

%union {
  abstractTree * a;
  double d;
}

/* declare tokens */
%token <d> NUMBER
%token EOL

%type <a> exp factor term

%%

calclist: /* nothing */
| calclist exp EOL {
     printf("= %4.4g\n", eval($2));
     treefree($2);
     printf("> ");
 }

 | calclist EOL { printf("> "); } /* blank line or a comment */
 ;

exp: factor
 | exp '+' factor { $$ = newAbstractTree('+', $1,$3); }
 | exp '-' factor { $$ = newAbstractTree('-', $1,$3);}
 ;

factor: term
 | factor '*' term { $$ = newAbstractTree('*', $1,$3); }
 | factor '/' term { $$ = newAbstractTree('/', $1,$3); }
 ;

term: NUMBER   { $$ = newNum($1); }
 | '|' term    { $$ = newAbstractTree('|', $2, NULL); }
 | '(' exp ')' { $$ = $2; }
 | '-' term    { $$ = newAbstractTree('M', $2, NULL); }
 ;
%%
