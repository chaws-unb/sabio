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

ast * newDeclaration(ast * sym, ast * expr)
{
	declaration * decl = new(declaration);
	decl->type = DECLARATION;
	decl->sym = ((identifier *)sym)->sym;
	decl->expr = expr;
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

ast * newSpecifier(symbolDataType dataType)
{
	specifier * spec = new(specifier);
	spec->type = _SPECIFIER;
	spec->dataType = dataType;
	return (ast *)spec;
}

ast * newIfStatement(ast * expr, ast * ifTrue, ast * ifFalse)
{
	ifStatement * ifStmt = new(ifStatement);
	ifStmt->type = IF_FLOW;
	ifStmt->expr = expr;
	ifStmt->ifTrue = ifTrue;

	if(ifFalse)
		ifStmt->ifFalse = ifFalse;

	return (ast *)ifStmt;
}

ast * newRelationalExpression(logicRelationType type, ast * left, ast * right)
{
	relationalExpression * rel = new(relationalExpression);
	rel->type = RELATIONAL_EXPRESSION;
	rel->relationType = type;
	rel->left = left;
	rel->right = right;
	return (ast *)rel;
}

ast * newWhileStatement(ast * _expression, ast * _statment)
{
	whileStatement * whileStmt = new(whileStatement);
	whileStmt->type = WHILE_FLOW;
	whileStmt->expr = _expression;
	whileStmt->statm = _statment;
	return (ast *)whileStmt;
}

ast * newAstList(astList * list, ast * newNode)
{
	astList * newList;
	astList * otherList;
	if(!newNode)
	{
		printf("Error! New node to an ast tree MUST be non-NULL");
		return NULL;
	}

	// Check if it's an append of two lists
	if(newNode->type == AST_LIST)
		newList = (astList *)newNode;
	else
	{
		newList = new(astList);
		newList->type = AST_LIST;
		newList->node = newNode;
	}

	// Creates a list with two nodes, it's probably the first time call
	if(list)
	{
		if(list->type == AST_LIST)
		{
			list->next = newList;
			return (ast *)list;
		}
		else
		{
			otherList = (astList *)newAstList(NULL, (ast *)list);
			otherList->next = newList;
			return (ast *)otherList;
		}

	}

	return (ast *)newList;
}

// This is the generic eval, I think it's better this way so everyone can
// edit at the same time
void * eval(ast * tree, xmlNode * out)
{
	if(!tree)
	{
		if(debugMode) printf("Error: empty tree!\n");
		return NULL;
	}
	if(debugMode) printf("Evaluating %s...\n", genericType2String(tree->type));
	switch(tree->type)
	{
		case ROOT: 			
		case EMPTY: 			
			break;
		case DECLARATION:	return eval_declaration((declaration *)tree, out);
		case _CONSTANT: 	return eval_constant((constant *)tree, out);

		case SUM:
		case SUB:
		case DIV:
		case MUL:
		case MOD:
			return eval_mathOperation((mathOperation *)tree, out);

		case _IDENTIFIER:
			return eval_identifier((identifier *)tree, out);

		case _SPECIFIER:
			return eval_specifier((specifier *)tree, out);

		case RELATIONAL_EXPRESSION:
			return eval_relationalExpression((relationalExpression *)tree, out);

		case FUNCTION_DEFINITION:
			return eval_functionDefinition((declaration *)tree, out);

		case IF_FLOW:
			return eval_ifStatement((ifStatement*)tree, out);

		case WHILE_FLOW:
			return eval_whileStatement((whileStatement *)tree, out);

		case AST_LIST:
			return eval_astList((astList *)tree, out);

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
		case EMPTY:					return "empty";
		case ASSIGNMENT:			return "assignemnt";
		case DECLARATION: 			return "declaration";
		case FUNCTION_DEFINITION:	return "function definition";
		case IF_FLOW:				return "if[else]";
		case WHILE_FLOW:			return "while";
		case _CONSTANT:				return "constant";
		case SUM:					return "sum";
		case SUB:					return "sub";
		case DIV:					return "div";
		case MUL:					return "mul";
		case MOD:					return "mod";
		case _IDENTIFIER:			return "identifier";
		case _SPECIFIER:			return "specifier";
		case RELATIONAL_EXPRESSION:	return "relational expression";
		case AST_LIST:				return "ast list";
		case VARIABLE:				return "var";
		case USER_FUNCTION:			return "user function";
		case BUILT_FUNCTION:		return "built-in function";
	}
	return "Unknown generic type";
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
