/**
 * @file symbolTable.h
 * @brief 
 **/
#ifndef _SYMBOL_H_
#define _SYMBOL_H_

#include "dataType.h"

symbol symbolTableHash[SIZE_SYMBOL_TABLE];

/**
 * @param _symbolName The name of symbol that would like to check in symbol table
 * @return Upon succesfull completition, lookUp shall return a reference to the
 * symbol. Otherwise, the function shall return NULL.
 * @brief Check the symbol table, if the element exist the function just return
 * the reference to them. If doesn't exists it's the lookUp() will insert the
 * new element and them return the reference. In case of error return NULL.
 **/
extern symbol * lookUp(char * _symbolName);

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

#endif
