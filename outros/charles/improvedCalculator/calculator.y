%{
#include <stdio.h>
#include <stdlib.h>	
#include "calculator.h"
%}

 // Declare data types to be used
%union{
	int fn;	
	double d;
	struct _ast * tree;
	struct _symbol * sym;
	struct _symbolList * list;
}

 // Declare associative tokens with data types
%token <d> NUMBER
%token <sym> NAME
%token <fn> FUNC
%token EOL
%token IF THEN ELSE WHILE DO LET

%nonassoc <fn> CMP
%right '='
%left '+' '-'
%left '*' '/'
%nonassoc '|' UMINUS

 // I think here it defines just like token ones, but with the whole rule
%type <tree> expression statement list expression_list
%type <list> symlist

%start calclist

%%

statement
	: IF expression THEN list 			 {fprintf(stderr, " statement: IF expression THEN list\n"); $$ = newFlow('I', $2, $4, NULL);}
	| IF expression THEN list ELSE list  {fprintf(stderr, " statement: IF expression THEN list ELSE list\n"); $$ = newFlow('I', $2, $4, $6);}
	| WHILE expression DO list 		 	 {fprintf(stderr, " statement: WHILE expression DO list\n"); $$ = newFlow('W', $2, $4, NULL);}
	| expression 						 {fprintf(stderr, " statement: expression\n"); }
	;

list
	: 					 {fprintf(stderr, " list: <<empty>>\n"); $$ = NULL;}
	| statement ';' list {fprintf(stderr, " list: statement ; list\n"); $$ = ($3 ? newAst('L', $1, $3) : $1);}
	;

expression
	: expression CMP expression    {fprintf(stderr, " expression: expression CMP expression\n"); $$ = newComparison($2, $1, $3);}
	| expression '+' expression    {fprintf(stderr, " expression: expression + expression\n"); $$ = newAst('+', $1, $3);}
	| expression '-' expression    {fprintf(stderr, " expression: expression - expression\n"); $$ = newAst('-', $1, $3);}
	| expression '*' expression    {fprintf(stderr, " expression: expression * expression\n"); $$ = newAst('*', $1, $3);}
	| expression '/' expression    {fprintf(stderr, " expression: expression / expression\n"); $$ = newAst('/', $1, $3);}
	| '|' expression 			   {fprintf(stderr, " expression: '|' expression\n"); $$ = newAst('|', $2, NULL);}
	| '(' expression ')' 		   {fprintf(stderr, " expression: '(' expression ')'\n"); $$ = $2;}
	| '-' expression %prec UMINUS  {fprintf(stderr, " expression: '-' expression UMINUS\n"); $$ = newAst('M', $2, NULL);}
	| NUMBER 					   {fprintf(stderr, " expression: NUMBER\n"); $$ = newNumber($1);}
	| NAME 						   {fprintf(stderr, " expression: NAME\n"); $$ = newReference($1);}
	| NAME '=' expression 		   {fprintf(stderr, " expression: NAME = expression\n"); $$ = newAssignment($1, $3);}
	| FUNC '(' expression_list ')' {fprintf(stderr, " expression: FUNC ( expression_list )\n"); $$ = newFunction($1, $3);}
	| NAME '(' expression_list ')' {fprintf(stderr, " expression: NAME ( expression_list )\n"); $$ = newCall($1, $3);}
	;

expression_list
	: expression 	{fprintf(stderr, " expression_list: expression\n");}
	| expression ',' expression_list {
			fprintf(stderr, " expression_list: expression, expression_list\n");
			$$ = newAst('L', $1, $3);
		}
	;

symlist
	: NAME {
			fprintf(stderr, " symlist: NAME\n");
			$$ = newSymbolList($1, NULL);
		}
	| NAME ',' symlist {
			fprintf(stderr, " NAME , symlist\n");
			$$ = newSymbolList($1, $3);
		}
	;

calclist
	:	{fprintf(stderr, " calclist: <<empty>>\n");}
	| calclist statement EOL {
			fprintf(stderr, " calclist: calclist statement EOL\n");
			printf("= %4.4g\n> ", eval($2)); treeFree($2);
		}
	| calclist LET NAME '(' symlist ')' '=' list EOL {
			fprintf(stderr, " calclist: calclist LET NAME ( symlist ) = list EOL\n");
			doDefine($3, $5, $8); 
			printf("Defined %s\n> ", $3->name);
		}
	| calclist error EOL {
			fprintf(stderr, " calclist: calclist error EOL\n");
			yyerrok; 
			printf("> ");
		}
	;
%%
