%{
  #include <stdio.h>
%}

%%
[a-zA-z][a-zA-Z0-9]* printf("%s ", yytext); return WORD;
[0-9]+		     printf("%s ", yytext); return NUMBER;
[a-zA-Z0-9\/.-]+     printf("%s ", yytext); return FILENAME;
\"		     printf("%s ", yytext); return QUOTE;
\{		     printf("%s ", yytext); return OBRACE;
\}		     printf("%s ", yytext); return EBRACE;
;		     printf("%s ", yytext); return SEMICOLON;
+		     printf("%s ", yytext); return PLUS;
-		     printf("%s ", yytext); return MINUS;
*		     printf("%s ", yytext); return MULT;
/		     printf("%s ", yytext); return DIV;
\n		     printf("%s ", yytext); 
[ \t]+		     /* ignore whitespace */;
%%

