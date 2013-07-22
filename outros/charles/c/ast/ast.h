#ifndef AST
#define AST 
#include <stdlib.h>

#ifndef new
	#define new(type) ((type *)malloc(sizeof(type)))
#endif

/**
 *	External references used in this implementation
 */
extern int yylineno; 				// Current line number
extern void yyerror(char * s, ...); // Error handling
extern int yylex(); 				// Lexer
extern int debugMode;

/**
 *	Node types for all kinds of tree
 *	Actually ALL SYMBOLS MUST BE HERE, in order to have a generic tree evaluation
 *	it's messy, but we don't have much time to think
 */
typedef enum
{
	ROOT = 1,			 // First ast ever
	ASSIGNMENT,		 	 // a = b; a = func(); etc
	DECLARATION, 		 // int a; 
	FUNCTION_DEFINITION, // int func(int a) {return 0;}
	IF_FLOW, 			 // if(1);
	IF_ELSE_FLOW, 		 // if(1);else;
	_SWITCH,
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

	/**
	 *	Symbol's type: global function, local function, global var, etc
 	 *	Let's do only bascis one for less complexity
 	 */
	VARIABLE,
	USER_FUNCTION,
	BUILT_FUNCTION
} genericType;

/**
 *	Nodes in the abstract syntax tree all have commom initial node type
 */
typedef struct _ast
{
	genericType type;
	struct _ast * left;
	struct _ast * right;
} ast;

/**
 *	THIS IS THE MAIN PROGRAM structure
 *	it stores all ast's of a source
 */
typedef struct _programNode
{
	ast * node;
	struct _programNode * next;
} programNode;

/**
 *	Symbol's data type: int, char, short, double, void etc
 */
typedef enum
{
	_VOID = 1,
	_CHAR,
	_SHORT,
	_INT,
	_FLOAT,
	_DOUBLE
} symbolDataType;

/**
 *	Pre-definition of symbol and symbolList, once both need each other
 */
typedef struct _symbol symbol;
typedef struct _symbolList symbolList;

/**
 *	Symbol table
 */
struct _symbol 
{
	symbolDataType dataType; // Symbol's datatype
	char * name; 			 // Symbol's name
	void * value; 			 // Point to this symbol's value
	ast * function; 		 // In case this symbol is Function body (list of statements)
	symbolList * symbols; 	 // Arguments
};

/**
 *	List of symbols for an argument List
 */
struct _symbolList
{
	symbol * sym; 			   // Current symbol
	struct _symbolList * next; // Next one
};

/**
 *	Declaration
 */
typedef struct 
{
	genericType type;
	symbol * sym;
	ast * expression; // everything after '=' sign
} declaration;

/**
 *	Constant value, it's always a number
 */
typedef struct 
{
	genericType type;
	double value;
} constant;

/**
 *	A mathematical operation with the format: ast OP ast
 */
typedef ast mathOperation;

/**
 *	A AST version of a symbol
 */
typedef struct 
{
	genericType type;
	symbol * sym;
} identifier;

/**
 *	Create a program node
 */
programNode * newProgramNode(ast * tree);

/**
 *	Create an abstract AST
 */
ast * newAst(genericType type, ast * left, ast * right);

/**
 *	Free an AST
 */
void freeAst(ast * tree);

/**
 *	Create a Declaration
 */
ast * newDeclaration(symbol * sym);

/**
 *	Create a Constant
 */
ast * newConstant(double consValue);

/**
 *	Create a Math operation
 */
ast * newMathOperation(genericType type, ast * left, ast * right);

/**
 *	A new identifier
 */
ast * newIdentifier(symbol * sym);

/**
 *	Eval can result in anything
 */
void * eval(ast * tree);

/**
 *	This evals each ast node type. This is better for shared code editing
 *	So more people can edit the project at the same time
 *	without intereferring in others commit/updates
 */
void * eval_root(ast * tree);
void * eval_declaration(declaration * decl);
void * eval_constant(constant * cons);
void * eval_mathOperation(mathOperation * op);

/**
 *	Create types
 */
void defineFunction();

/**
 *	Auxiliars
 */
char * dataType2String(symbolDataType type);
char * genericType2String(genericType type);
void printSymbol(symbol * sym);

#endif