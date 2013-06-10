#ifndef _DATA_TYPE_H_
#define _DATA_TYPE_H_

/**
* @def SIZE_SYMBOL_TABLE
* @brief Initial size for symbol table
*/
#define SIZE_SYMBOL_TABLE 9997
/**
* @brief Keeps the values of symbol table
*/
typedef struct _symbol
{
  
}symbol;

typedef struct _refList
{

}refList;

/**
* @param _list 
* @param _symNode
* @return 
* @brief 
*/
extern int pushRef(refList * _list, symbol * _symNode);

#endif
