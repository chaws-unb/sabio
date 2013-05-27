%{
#include <iostream>
#include "snazzle.tab.h"
#define YY_DECL extern "C" int yylex()
using namespace std;
%}
%%
[ \t\n];
sNaZZle 	  {return SNAZZLE;}
type 		  {return TYPE;}
end			  {return END;}
[0-9]+\.[0-9] {yylval.fval = atof(yytext); return FLOAT;}
[0-9]+		  {yylval.ival = atoi(yytext); return INT;}
[0-9a-zA-Z]+  {yylval.sval = strdup(yytext); return STRING;}
. ;
%%
