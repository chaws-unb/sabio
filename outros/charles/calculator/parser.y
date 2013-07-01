/* Companion source code for "flex & bison", published by O'Reilly
 * Media, ISBN 978-0-596-15597-1
 * Copyright (c) 2009, Taughannock Networks. All rights reserved.
 * See the README file for license conditions and contact info.
 * $Header: /home/johnl/flnb/code/RCS/fb3-1.y,v 2.1 2009/11/08 02:53:18 johnl Exp $
 */

/* calculator with AST */

%{
#  include <stdio.h>
#  include <stdlib.h>
#  include "functions.h"
%}

%union {
  struct ast *a;
  double d;
}

/* declare tokens */
%token <d> NUMBER
%token EOL

%type <a> exp factor term

%%

calclist: /* nothing */
| calclist exp EOL {
	 printf(": calclist->calclist exp EOL\n");
     printf("= %4.4g\n", eval($2));
     treefree($2);
     printf("> ");
 }

 | calclist EOL { printf(": calclist->calclist EOL\n"); printf("> "); } /* blank line or a comment */
 ;

exp: factor 	  { printf(": exp->factor\n");}
 | exp '+' factor { printf(": exp->exp + factor\n"); $$ = newast('+', $1,$3); }
 | exp '-' factor { printf(": exp->exp - factor\n"); $$ = newast('-', $1,$3);}
 ;

factor: term       {printf(": factor->term\n");}
 | factor '*' term {printf(": factor->factor * term\n"); $$ = newast('*', $1,$3); }
 | factor '/' term {printf(": factor->factor / term\n"); $$ = newast('/', $1,$3); }
 ;

term: NUMBER   {printf(": term->NUMBER \n"); $$ = newnum($1); }
 | '|' term    {printf(": term->| term\n"); $$ = newast('|', $2, NULL); }
 | '(' exp ')' {printf(": term->( exp )\n"); $$ = $2; }
 | '-' term    {printf(": term->- term\n"); $$ = newast('M', $2, NULL); }
 ;
%%
