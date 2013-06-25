/**
 * @file handleFile.h
 * @brief This file keeps some functions for handle files.
 **/
#ifndef _HANDLE_FILE_H_
#define _HANDLE_FILE_H_

#include <stdio.h>
#include "lexer.h"

/**
 * @struct _bufferStack
 * @brief Keeps some informations about file.
 **/
typedef struct _bufferStack
{
	struct _bufferStack * previous;	/**< Previous node.*/
	YY_BUFFER_STATE bufferState;	/**< */
	int lineno;				/**< Line.*/
	char * fileName;		/**< Name of file.*/
	FILE * currentFile;		/**< current file.*/
}bufferStack;

/**
 * @var curbs
 * @brief Current Buffer Stack.
 **/
bufferStack  * curbs = 0;

/**
 * @var currentFileName
 * @brief Name of current input file.
 **/
char * currentFileName = 0;

/**
 * @param _fileName Current name of the file.
 * @return Upon succesfull completition, shall return a non-negative integer.
 * Otherwise, the function shall return one negative number that correspond
 * an internal code error.
 * @brief Add a new file in the queue.
 **/
extern int newFile(char * _fileName);

/**
 * @return 
 * @brief 
 **/
extern int popFile();

#endif
