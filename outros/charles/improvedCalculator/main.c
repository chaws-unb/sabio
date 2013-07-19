#include "calculator.h"
#include <stdio.h>

extern char yytext[];
extern int column;
extern int yylex();
extern int yyparse();
extern FILE * yyin;

int main()
{
	FILE * input = fopen("input.in", "r");
	if(!input){
		printf("Ops, no file!\n");
		return -1;  
	}

	yyin = input;

	// Faz todo parsing
	printf("\n*** INICIO ***\n");
	//return 0;
	do
	{
		printf("parsando");
		yyparse();
	}while(!feof(yyin));

	printf("\n*** FIM ***\n"); 
	fclose(input);

	return 0;
}