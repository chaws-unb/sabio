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

	RELATIONAL_EXPRESSION, // logical expressions

	/**
	 *	Symbol's type: global function, local function, global var, etc
 	 *	Let's do only bascis one for less complexity
 	 */
	VARIABLE,
	USER_FUNCTION,
	BUILT_FUNCTION
} genericType;

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

typedef enum
{
	LT = 1, // '<' 
	GT, 	// '>' 
	LTE,	// <=
	GTE,	// >=
	EQ, 	// ==
	NEQ,	// !=
	OR, 	// ||
	AND 	// &&
} logicRelationType;

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
	ast * expr; // everything after '=' sign
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

typedef struct 
{
	genericType type;
	symbolDataType dataType;
} specifier;

/**
* An AST to if(1){stmt} and if(1){stmt}else{stmt} statements
*
*/
typedef struct
{
	genericType type;
	ast * expr;
	ast * ifTrue;
	ast * ifFalse;
}ifStatement;

/**
 *	Relational expression
 */
typedef struct ast
{
	genericType type;
	logicRelationType relationType;
	ast * left;
	ast * right;
} relationalExpression;

/**
* An AST to switch(1){case 1: stmt} statement
*
*/
typedef struct
{
	genericType type;
	symbol * sym;
}switchStatement;

/**
 *	Create each of AST subtypes
 */
ast * newAst(genericType type, ast * left, ast * right); // Most generic one
ast * newDeclaration(ast * sym, ast * expr);
ast * newConstant(double consValue);
ast * newMathOperation(genericType type, ast * left, ast * right);
ast * newIdentifier(symbol * sym);
ast * newSpecifier(symbolDataType dataType);
ast * newIfStatement(ast * expression, ast * ifTrue, ast * ifFalse);
ast * newRelationalExpression(logicRelationType type, ast * left, ast * right);

/**
 *	Free an AST
 */
void freeAst(ast * tree);

/**
 *	This evals each ast node type. This is better for shared code editing
 *	So more people can edit the project at the same time
 *	without intereferring in others commit/updates
 */
void * eval(ast * tree); // Most generic one
void * eval_root(ast * tree);
void * eval_declaration(declaration * decl);
void * eval_identifier(identifier * id);
void * eval_specifier(specifier * spec);
void * eval_constant(constant * cons);
void * eval_mathOperation(mathOperation * op);
void * eval_ifStatement(ifStatement * ifStmt);
void * eval_relationalExpression(relationalExpression * rel);
void * eval_functionDefinition(declaration * func); // OBS: there's no typedef for functionDefinition since it's the same as declaration!!!


/**
 *	Create a program node
 */
programNode * newProgramNode(ast * tree);

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