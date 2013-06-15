/**
 * @file dataType.h
 * @brief Keeps general definitions and functions.
 **/
#ifndef _DATA_TYPE_H_
#define _DATA_TYPE_H_

/**
* @def SIZE_SYMBOL_TABLE
* @brief Initial size for symbol table
*/
#define SIZE_SYMBOL_TABLE 9997

/**
 * @def HASH_CALC
 * @brief Value for calculus of hash.
 **/
#define HASH_CALC 9

/**
 * @struct _refList
 * @brief Linked list that keeps the details about one specific symbol.
 **/
typedef struct _refList
{
	struct _refList * next;
	char * fileName;
	int flags;	/**< Flags with some extra information about symbol.*/
	int lineno;	/**< Line that the symbols was found.*/
}refList;

/**
* @struct _symbol 
* @brief Keeps the name and informations about symbol.
*/
typedef struct _symbol
{
	refList * refInfoList;	/**< Linked list with informations about symbol.*/
	char * symbolName;			/**< Name of symbol.*/
}symbol;

#endif
