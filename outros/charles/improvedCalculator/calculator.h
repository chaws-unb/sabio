#ifndef CALCULATOR
#define CALCULATOR 
#include <stdio.h>

// Current line number
extern int yylineno;

// Error handling
extern void yyerror(char * s, ...);

// Lexer
extern int yylex();

// Input
extern FILE * yyin;

/* node types
* + - * / |
* 0-7 comparison ops, bit coded 04 equal, 02 less, 01 greater
* M unary minus
* L expression or statement list
* I IF statement
* W WHILE statement
* N symbol ref
* = assignment
* S list of symbols
* F built in function call
* C user function call
*/
// Nodes in the abstract syntax tree all have commom initial node type
typedef struct _ast{
	int nodeType;
	struct _ast * left;
	struct _ast * right;
} ast;

typedef struct _symbol symbol;
typedef struct _symbolList symbolList;

// Symbol table
struct _symbol 
{
	// Variable name
	char * name;

	// If it's number, its value
	double value;

	// Function body
	ast * function;

	// Arguments
	symbolList * symbols;
};

// List of symbols for an argument List
struct _symbolList
{
	// Current symbol
	symbol * sym;

	// Next one
	struct _symbolList * next;
};

// Enumeration for built in functions
typedef enum 
{
	B_sqrt = 1,
	B_exp,
	B_log,
	B_print
} builtInFunctions;

// Define a strcture of a buit-in function
typedef struct
{
	int nodeType;
	ast * left;
	builtInFunctions functionType;
}  fnCall;

// Define a strcture of a buit-in function
typedef struct
{
	int nodeType;
	ast * left;
	symbol * sym;
} uFnCall;

typedef struct
{
	int nodeType;
	ast * condition;
	ast * thanOrList;
	ast * _else;
} flow;

typedef struct
{
	int nodeType;
	double number;
} numberValue;

typedef struct
{
	int nodeType;
	symbol * sym;
} symbolReference;

typedef struct
{
	int nodeType;
	symbol * sym;
	ast * value;
} symbolAssignment;

// Simple symbol table 
#define MAX_HASH 9997
symbol symbolTable[MAX_HASH];

// Lookup function for HASH table
symbol * lookup(char * name);

// Create a new list of symbol arguments
symbolList * newSymbolList(symbol * sym, symbolList * next);

// Releeeeeeeeeeeeeeease me!
void symbolListFree(symbolList * sl);

// New AST
ast * newAst(int nodeType, ast * left, ast * right);
ast * newComparison(int comparisonType, ast * left, ast * right);
ast * newFunction(int functionType, ast * left);
ast * newCall(symbol * sym, ast * left);
ast * newReference(symbol * sym);
ast * newAssignment(symbol * sym, ast * value);
ast * newNumber(double number);
ast * newFlow(int nodeType, ast * condition, ast * left, ast * right);

// Define a function
void doDefine(symbol * name, symbolList * symbols, ast * statements);

// Evaluate an AST
double eval(ast * tree);

// Releeeeeeeeeeeeeeease me!!!
void treeFree(ast * tree);

#endif
