/**
 * @file main.c
 **/
#include <stdio.h>
#include "clexer.h"
#include "dataType.h"
#include "handleFile.h"
#include "printDebug.h"

int main(int argc, char **argv)
{
	int i = 0;

	if(argc < 2)
	{
		fprintf(stderr, "need filename\n");
		return 1;
	}
	for(i = 1; i < argc; i++)
	{
		if(newFile(argv[i])) yylex();
	}

	printReferences();
	return 0;
}
