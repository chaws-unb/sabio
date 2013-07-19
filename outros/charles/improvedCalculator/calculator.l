%option noyywrap nodefault yylineno
%{
#include "calculator.h"
#include "calculator.tab.h"
%}

 /* Regex for exponential numbers */
EXP (Ee[+-]?[0-9]+)

%%

 /* One-character tokens */
"+" | "-" | "*" | "/" | "=" | "|" | "," | ";" | "(" | ")" {ECHO; return yytext[0];}

 /* Comparison tokens */
">"  {ECHO; yylval.fn = 1; return CMP;}
"<"  {ECHO; yylval.fn = 2; return CMP;}
"<>" {ECHO; yylval.fn = 3; return CMP;}
"==" {ECHO; yylval.fn = 4; return CMP;}
">=" {ECHO; yylval.fn = 5; return CMP;}
"<=" {ECHO; yylval.fn = 6; return CMP;} 

 /* Reserved/Key words */
"if" 	{ECHO; return IF;}
"then" 	{ECHO; return THEN;}
"else" 	{ECHO; return ELSE;}
"while" {ECHO; return WHILE;}
"do" 	{ECHO; return DO;}
"let" 	{ECHO; return LET;}

 /* Built-in functions */
"sqrt" 	{ECHO; yylval.fn = B_sqrt; return FUNC;}
"exp" 	{ECHO; yylval.fn = B_exp; return FUNC;}
"log" 	{ECHO; yylval.fn = B_log; return FUNC;}
"print" {ECHO; yylval.fn = B_print; return FUNC;}

 /* Names */
[a-zA-Z][a-zA-Z0-9]* {ECHO; yylval.sym = lookup(yytext); return NAME;}

 /* Numbers */
[0-9]+"."?[0-9]*{EXP}? | "."[0-9]+{EXP}? {ECHO; yylval.d = atof(yytext); return NUMBER;}

 /* Do nothing about comments */
"//".*

 /* Ignore whitespace */
[ \t] {ECHO; }

 /* Continue next line */
\\\n {ECHO; printf("c> ");}

\n {ECHO; return EOL;}

. {ECHO; yyerror("Mystery character %c\n", *yytext);}
%%