#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ast.h"

#ifndef new
	#define new(type) ((type *)malloc(sizeof(type)))
#endif

programNode * newProgramNode(ast * tree)
{
	programNode * returned = new(programNode);
	returned->node = tree;
	returned->next = NULL;
	return returned;
}

ast * newAst(genericType type, ast * left, ast * right)
{
	ast * returned = new(ast);
	returned->type = type;
	returned->left = left;
	returned->right = right;
	return returned;
}

ast * newDeclaration(symbol * sym)
{
	declaration * decl = new(declaration);
	decl->type = DECLARATION;
	decl->sym = sym;
	decl->expression = NULL;
	return (ast *)decl;
}

ast * newConstant(double consValue)
{
	constant * cons = new(constant);
	cons->type = _CONSTANT;
	cons->value = consValue;
	return (ast *)cons;
}

ast * newMathOperation(genericType type, ast * left, ast * right)
{
	mathOperation * op = new(mathOperation);
	op->type = type;
	op->left = left;
	op->right = right;
	return (ast *)op;
}

ast * newIdentifier(symbol * sym)
{
	identifier * id = new(identifier);
	id->type = _IDENTIFIER;
	id->sym = sym;
	return (ast *)id;
}

ast * newIfStatement(ast * expr, ast * ifTrue, ast * ifFalse)
{
	if(debugMode) printf("Creating new IF_FLOW\n");
	ifStatement * ifStmt = new(ifStatement);
	ifStmt->type = IF_FLOW;
	ifStmt->expr = expr;
	ifStmt->ifTrue = ifTrue;

	if(ifFalse)
		ifStmt->ifFalse = ifFalse;

	return (ast *)ifStmt;
}

// This is the generic eval, I think it's better this way so everyone can
// edit at the same time
void * eval(ast * tree)
{
	if(!tree)
	{
		if(debugMode) printf("Error: empty tree!\n");
		return NULL;
	}

	switch(tree->type)
	{
		case ROOT: 			
		case EMPTY: 			
			break;
		case DECLARATION:	return eval_declaration((declaration *)tree);
		case _CONSTANT: 	return eval_constant((constant *)tree);

		case SUM:
		case SUB:
		case DIV:
		case MUL:
		case MOD:
			return eval_mathOperation((mathOperation *)tree);

		case _IDENTIFIER:
			return eval_identifier((identifier *)tree);

		case IF_FLOW:
			return eval_ifStatement((ifStatement*)tree);

		default:
			printf("Unknown node!\n");
	}
	return NULL;
}

void freeAst(ast * tree)
{
	// IF WE HAVE TIME WRITE THIS FUNCTION
	// OTHERWISE, LET'S JUST RESTART OUR MACHINE IN CASE OF MEMORY ERROR 
	// LOL
}

char * dataType2String(symbolDataType type)
{
	switch(type)
	{
		case _VOID:
			return "void";
			break;

		case _CHAR:
			return "char";
			break;

		case _SHORT:
			return "short";
			break;

		case _INT:
			return "int";
			break;

		case _FLOAT:
			return "float";
			break;

		case _DOUBLE:
			return "double";
			break;
	}
	return "Unknown data type";
}

char * genericType2String(genericType type)
{
	switch(type)
	{
		case ROOT:					return "root";
		case EMPTY:					return "empy";
		case ASSIGNMENT:			return "assignemnt";
		case DECLARATION: 			return "declaration";
		case FUNCTION_DEFINITION:	return "function definition";
		case IF_FLOW:				return "if[else]";
		case _CONSTANT:				return "constant";
		case SUM:					return "sum";
		case SUB:					return "sub";
		case DIV:					return "div";
		case MUL:					return "mul";
		case MOD:					return "mod";
		case _IDENTIFIER:			return "identifier";
		case VARIABLE:				return "var";
		case USER_FUNCTION:			return "user function";
		case BUILT_FUNCTION:		return "built-in function";
	}
	return "Unknown data type";
}

void printSymbol(symbol * sym)
{
	printf("Data type = %s, ", dataType2String(sym->dataType));
	printf("Name = %s, ", sym->name);

	if(sym->value)
	{
		switch(sym->dataType)
		{
			case _VOID:
				printf("Value = %p, ", sym->value);
				break;

			case _CHAR:
				printf("Value = %c[%i], ", *(char *)sym->value, *(char *)sym->value);
				break;

			case _SHORT:
				printf("Value = %i, ", *(short *)sym->value);
				break;

			case _INT:
				printf("Value = %i, ", *(int *)sym->value);
				break;

			case _FLOAT:
			case _DOUBLE:
				printf("Value = %4.4g, ", *(double *)sym->value);
				break;
		}
	}
	printf("\n");
}
