#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include "ast/ast.h"

#ifndef new
	#define new(type) ((type *)malloc(sizeof(type)))
#endif

// Input
extern FILE * yyin;
extern int yylineno;

extern programNode * mainProgram;

int debugMode = 0;

int main(int argc, char ** argv)
{
	if(argc < 2)
	{
		printf("sabioCC: no input files\n");
		return;
	}

	int i = 1;
	for(; i < argc; i++)
		if(strcmp("--debug", argv[i]) == 0)
		{
			debugMode = 1;
		}
		//else
		//{
		//	printf("Ops, unknown argument!\n");
		//	return -1; 
		//}


	FILE * input = fopen(argv[1], "r");
	if(!input){
		printf("Ops, no file!\n");
		return -1;  
	}

	if(debugMode) printf("\n*** START-DEBUGMODE ***\n");

	yyin = input;

	// Some initial work to grammar init correctly
	initGrammar();

	// Before building things, get a reference of the first AST, this is the root of it
	programNode * root = mainProgram;

	do
	{
		yyparse();
	}while(!feof(yyin));

	// Now, it's time to evaluate!!!
	programNode * temp = root;
	while(temp)
	{
		eval(temp->node);
		temp = temp->next;
	}

	if(debugMode) printf("\n*** END-DEBUGMODE ***\n"); 
	fclose(input);

	return 0;
}

void yyerror(char *s, ...)
{
	va_list ap;
	va_start(ap, s);
	fprintf(stderr, "%d: error: ", yylineno);
	vfprintf(stderr, s, ap);
	fprintf(stderr, "\n");
}
