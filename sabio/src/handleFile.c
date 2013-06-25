/**
 * @file handleFile.c
 **/
#include "clexer.h"
#include "handleFile.h"

/* nested input files */
int newFile(char * _fileName)
{
	FILE * file = fopen(_fileName, "r");
	bufferStack * buffStack = 0;

	if(!file)
	{
		perror(_fileName);
		return -1;
	}

	buffStack = malloc(sizeof(bufferStack));
	if(!buffStack)
	{
		perror("malloc");
		exit(1);
	}

	// remember state
	if(curbs)
	{
		curbs->lineno = yylineno;
	}

	buffStack->previous = curbs;
	buffStack->currentFile = file;
	buffStack->fileName = _fileName;

	// set up current entry
	buffStack->bufferState = yy_create_buffer(file, YY_BUF_SIZE);
	yy_switch_to_buffer(buffStack->bufferState);
	curbs = buffStack;
	yylineno = 1;
	currentFileName = _fileName;

	return 1;
}

int popFile(void)
{
		bufferStack * buffStack = curbs;
	bufferStack * previousBuffStack = 0;

	if(!buffStack)
	{
		return -1;
	}

	//Switch back to previous
	previousBuffStack = buffStack->previous;
	free(buffStack);

	if(!previousBuffStack)
	{
		return 0;
	}

	yy_switch_to_buffer(previousBuffStack->bufferState);
	curbs = previousBuffStack;
	yylineno = curbs->lineno;
	currentFileName = curbs->fileName;
	
	return 1;
}
