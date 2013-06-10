
%option noyywrap nodefault yylineno
%x IFILE

%{
#  include "../inc/sabio.h"
#  include "../inc/bufStack.h"
#  include "../inc/parser.tab.h"
%}

/* float exponent */
EXP	([Ee][-+]?[0-9]+)

%%

^"#"[ \t]*include[ \t]*\[\"<] { BEGIN IFILE; }	

 /*handle filename up to the closing quote, >, o EOF*/
<IFILE>[^ \t\n\">]+	      {			 
				int c;
				while((c = input()) && c!= '\n')
				{
				  yylineno++;
				}
/*the filename is passed to newfile to stack the current input file and set up the next level of input*/
				if(!newfile(yytext))
				  yyterminate();  /*no such file*/
				BEGIN INITIAL;
			      }

<IFILE>.|\n		      {fprintf(stderr, "%4d bad include line\n", yylineno);
				yyterminate();
			      }

<<EOF>>			      {if(!popfile()) yyterminate();}

^.			      {fprintf(yyout, "%4d %s", yylineno, yytext);}
^\n			      {fprintf(yyout, "%4d %s", yylineno++, yytext);}
\n			      {ECHO; yylineno++;}
.			      {ECHO;}


"+" |
"-" |
"*" |
"/" |
"|" |
"(" |
")"     { return yytext[0]; }
[0-9]+"."[0-9]*{EXP}? |
"."?[0-9]+{EXP}? { yylval.d = atof(yytext); return NUMBER; }

\n      { return EOL; }
"//".*  
[ \t]   { /* ignore white space */ }
.	{ yyerror("Mystery character %c\n", *yytext); }
%%
