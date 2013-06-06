/**
 * @file symbolTable.h
 * @brief This file keeps some definitions and declaration for works
 * 	with symbol table.
 **/
#ifndef _SYMBOL_TABLE_H_
#define _SYMBOL_TABLE_H_

#define SIZE_HASH 9997

/**
 * @struct _referenceSymbol
 * @brief Keeps some informations about reference, mainly the number of
 *	line and the name file.
 **/
typedef struct _infoRefSymbol
{
	struct _infoRefSymbol * next;
	char * fileName;
	int flags;	/**< Gives some additional information.*/
	int lineno;	/**< Line that the reference was found.*/
}infoRefSymbol;

/**
 * @struct _symbol
 * @brief Keeps the name of symbol and information about them in a list.
 */
typedef struct _symbol
{
	infoRefSymbol * reflist;
	char * name;
}symbol;

/**
 * @param _symbolName Name of symbol for inspection in symbol table.
 * @return If the symbol exist this function return the reference of
 * 	them. Otherwise the function will enter with the new name.
 * @brief Look inside of symbol table and try to find the symbol.
 **/
extern symbol * lookup(char * _symbolName);

/**
 * @param _lineRef Number of line in file that the symbol was found.
 * @param _fileName Name of file that was analysed.
 * @param _word Name of word found. 
 * @param _flag Extra information about the word.
 * @brief Adds the informations about the word in found in symbol table.
 **/
extern void addRef(int _lineRef, char * _fileName, char * _word, int _flag);

#endif
