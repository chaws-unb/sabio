/* Companion source code for "flex & bison", published by O'Reilly
 * Media, ISBN 978-0-596-15597-1
 * Copyright (c) 2009, Taughannock Networks. All rights reserved.
 * See the README file for license conditions and contact info.
 * $Header: /home/johnl/flnb/code/RCS/fb3-1.l,v 2.1 2009/11/08 02:53:18 johnl Exp $
 */
/* recognize tokens for the calculator */

%option noyywrap nodefault yylineno
%{
# include "parser.tab.h"
# include "functions.h"
%}

/* float exponent */
EXP	([Ee][-+]?[0-9]+)

%%
"+" |
"-" |
"*" |
"/" |
"|" |
"(" |
")"     { ECHO; return yytext[0]; }
[0-9]+"."[0-9]*{EXP}? |
"."?[0-9]+{EXP}? { ECHO; yylval.d = atof(yytext); return NUMBER; }

\n      {ECHO; return EOL; }
"//".*  
[ \t]   {ECHO; /* ignore white space */ }
.	{ECHO; yyerror("Mystery character %c\n", *yytext); }
%%
