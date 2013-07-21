#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>

// Input
extern FILE * yyin;
extern int yylineno;

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
		if(strcmp("-debug", argv[i]) == 0)
			debugMode = 1;

	FILE * input = fopen(argv[1], "r");
	if(!input){
		printf("Ops, no file!\n");
		return -1;  
	}

	yyin = input;

	// Faz todo parsing
	printf("\n*** INICIO ***\n");
	do
	{
		yyparse();
	}while(!feof(yyin));

	printf("\n*** FIM ***\n"); 
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
