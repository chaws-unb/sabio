#ifndef _C_GRAMMAR_H_
#define _C_GRAMMAR_H_

#include <dataType.h>

/**
 *	Store current symbol data type read by the parser y
 */
symbolDataType currentSymbolDataType;

/**
 * @brief Store current symbol
 */
symbol * currentSymbol;

/**
 * @brief List of all ast of this source
 */
extern programNode * mainProgram;

void * postfixExpression_IDENTIFIER(char * _absTree);

#endif
