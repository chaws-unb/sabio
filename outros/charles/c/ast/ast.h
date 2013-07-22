#ifndef AST
#define AST 
#include <stdlib.h>

// Current line number
extern int yylineno;

// Error handling
extern void yyerror(char * s, ...);

// Lexer
extern int yylex();

// Node types for all kinds of tree
typedef enum
{
	ASSIGNMENT = 1,
	DECLARATION,
	FLOW
} astType;

// Nodes in the abstract syntax tree all have commom initial node type
typedef struct _ast
{
	astType type;
	struct _ast * left;
	struct _ast * right;
} ast;

// The variable type: int, char, short, double, void
// JUST THE BASICS, WE NEED TO DO OTHER THINGS FIRST haha
typedef enum
{
	_VOID = 1,
	_CHAR,
	_SHORT,
	_INT,
	_FLOAT,
	_DOUBLE,
	_IF_EXP_STMT,
	_IF_EXP_STMT_ELSE,
	_SWITCH
} symbolType;

typedef struct _symbol symbol;
typedef struct _symbolList symbolList;

// Symbol table
struct _symbol 
{
	// Symbol's type
	symbolType type;

	// Symbol's name
	char * name;

	// Point to this symbol's value
	void * value;

	// In case this symbol is Function body
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

// AST Functions
ast * newAst(astType type, ast * left, ast * right);
ast * newDeclaration(astType type, symbol * sym);

// Simple HASH table
// Simple symbol table 
#define MAX_HASH 9997
symbol symbolTable[MAX_HASH];

// Lookup function for HASH table
symbol * lookup(char * name);

#endif