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

typedef enum
{
	ROOT = 1,			 // First ast ever
	EMPTY,			 	 // Empty statement
	ASSIGNMENT,		 	 // a = b; a = func(); etc
	DECLARATION, 		 // int a; 
	FUNCTION_DEFINITION, // int func(int a) {return 0;}
	IF_FLOW, 			 // if(1);[else;]
	_SWITCH,			 // switch(1){case 1: stmt}
	_CONSTANT,			 // 0,1,2,3...9

	/**
	 *	Math operations
	 */
	SUM,
	SUB,
	DIV,
	MUL,
	MOD,

	/**
	 *	A Symbol/Reference
	 */
	_IDENTIFIER,

	_SPECIFIER, // Data type specifier

	/**
	 *	Symbol's type: global function, local function, global var, etc
 	 *	Let's do only bascis one for less complexity
 	 */
	VARIABLE,
	USER_FUNCTION,
	BUILT_FUNCTION
}genericType;

/**
 * @enum _builtInfFunction
 * @brief Keeps some codes for internal function.
 **/
typedef enum _builtInfFunction
{
	B_sqrt = 1,
	B_exp,
	B_log,
	B_print
}builtInFunction;

typedef enum
{
	_VOID = 1,
	_CHAR,
	_SHORT,
	_INT,
	_FLOAT,
	_DOUBLE
}symbolDataType;

/**
 * @struct _abstractTree
 * @brief Nodes of abstract tree.
 **/
typedef struct _abstractTree
{
	genericType nodeType;
	struct _abstractTree * left;
	struct _abstractTree * right;
}abstractTree;

typedef struct _programNode
{
	abstractTree * node;
	struct _programNode * next;
} programNode;

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
	symbolDataType dataType;
	char * symbolName;		/**< Name of symbol.*/
	double value;
	abstractTree * function;	/**< stmt for the function.*/
	struct _symlist * syms; 	/**< List of dummy args.*/
	refList * refInfoList;
}symbol;

/**
 * @struct _symlist
 * @brief 
 **/
typedef struct _symlist
{
	symbol * sym;
	struct _symlist * next;
}symlist;

/**
 * @struct _builtInFuncCall
 * @brief Internal functions use this struct for represent them. Node
 * type for this struct normally is 'F'
 **/
typedef struct _builtInFuncCall
{
	int nodeType;
	abstractTree * left;
	builtInFunction functionType;
}builtInFuncCall;

/**
 * @struct _userFuncCall
 * @brief User function. Type 'C'
 **/
typedef struct _userFuncCall
{
	int nodeType;
	abstractTree * left;
	symbol * userSymbolRef;
}userFuncCall;

/**
 * @struct _flow
 * @brief Handles the flow control. If type is 'I' refers to "if" or if
 * type is 'W' refers to "while" loop.
 **/
typedef struct _flow
{
	int nodeType; 						/**< Type I or W.*/
	abstractTree * condition;	/**< Condition.*/
	abstractTree * thenList;		/**< Then or do list.*/
	abstractTree * elseList;		/**< Optional else list.*/
}flow;

/**
 * @struct _numValue
 * @brief Handle number values. 
 **/
typedef struct _numValue
{
	int nodeType;	/**< Type K.*/
	double number;
}numValue;

/**
 * @struct _symbolRef
 * @brief Reference to symbol
 **/
typedef struct _symbolRef
{
	int nodeType;		/**< Type N.*/
	symbol * symb;
}symbolRef;

/**
 * @struct _symAssignment
 * @brief 
 **/
typedef struct _symAssignment
{
	int nodeType;			/**< type = .*/
	symbol * sym;
	abstractTree * value;	/**< Value.*/
}symasgn;

#endif
