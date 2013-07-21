#include "../ast/ast.h"

// YEAH, I KNOW, GLOBAL VARS SUCK, BUT HAVE A BETTER IDEA IN THIS SHORT AVAILABLE TIME ?
// Store current symbol type read by the parser y
symbolType currentSymbolType;

// Store current symbol
symbol * currentSymbol;

// Store current value: CAN BE ANYTHING, SINCE AN ACTUAL VALUE TO A WHOLE AST
void * currentValue;

// Store current AST
ast * currentAst;