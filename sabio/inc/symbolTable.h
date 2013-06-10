/**
 * @file symbolTable.h
 * @brief 
 **/
#ifndef _SYMBOL_TABLE_H_
#define _SYMBOL_TABLE_H_

/**
* @struct _symbol 
* @brief Keeps the name and informations about symbol.
*/
typedef struct _symbol
{
	refList * refInfoList;	/**< Linked list with informations about symbol.*/
	char * symbolName;		/**< Name of symbol.*/
}symbol;

/**
 * @struct _refList
 * @brief Linked list that keeps the details about one specific symbol.
 **/
typedef struct _refList
{
	struct _refList * next;
	char * fileName;
	int flags;		/**< Flags with some extra information about symbol.*/
	int lineno;		/**< Line that the symbols was found.*/
}refList;

/**
* @param _lineno The number of line that the symbol was found.
* @param _fileName The name of file where symbol was found.
* @param _word The name of symbol in file.
* @param _flag Extra information
* @return Upon succesfull completition, addSymbolRef() shall return a
* non-negative integer. Otherwise, the function shall return one negative
* number that correspond an internal code error.
* @brief Every time that one symbol is found, this function is involked
* 	for add them in a list of symbol.
*/
extern int addSymbolRef(int _lineno, char * _fileName, char * _word, int _flag);

/**
 * @param _symbolName The name of symbol that would like to check in symbol table
 * @return Upon succesfull completition, lookUp shall return a reference to the
 * symbol. Otherwise, the function shall return NULL.
 * @brief Check the symbol table, if the element exist the function just return
 * the reference to them. If doesn't exists it's the lookUp() will insert the
 * new element and them return the reference. In case of error return NULL.
 **/
extern symbol * lookUp(char * _symbolName);

#endif
