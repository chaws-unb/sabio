#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include <string.h>
#include <math.h>
#include "calculator.h"
#define new(type) ((type *)malloc(sizeof(type)))

// Hash function
static unsigned int symbolHash(char * symbolName)
{
    unsigned int hash = 0;
	unsigned char c;

	while(c = *symbolName)
		hash = (hash * 9) ^ c;

	return hash;
}

// Look up for a symbol name, otherwise insert it
symbol * lookup(char * symbolName)
{
	// % here means AVOID BUFFER OVERFLOW!!!
	symbol * sym = &(symbolTable[symbolHash(symbolName) % MAX_HASH]);

	// Counter to track how many looked symbols
	int scount = MAX_HASH;

	while(--scount >= 0)
	{
		// Check if already exists
		if(sym->name && !strcmp(sym->name, (char *)sym))
			return sym;

		// Ops, no name means empty set
		if(!sym->name)
		{
			sym->name = strdup((char *)sym);
			sym->value = 0;
			sym->function = NULL;
			sym->symbols = NULL;
			return sym;
		}

		// Let's try next hash table entry
		if(++sym >= (symbolTable + MAX_HASH))
			sym = symbolTable; // OK, this line is useless!!!
	}

	yyerror("Symbol Table overflow! Watch out! \n");
	abort();
}

symbolList * newSymbolList(symbol * sym, symbolList * next)
{
	symbolList * returned = new(symbolList);
	if(!returned)
	{
		yyerror("Out of space!");
		exit(0);
	}

	returned->sym  = sym;
	returned->next = next;
	return returned;
}

void symbolListFree(symbolList * sl)
{
	symbolList * temp;
	while(sl)
	{
		temp = sl->next;
		free(sl);
		sl = temp;
	}
}

ast * newAst(int nodeType, ast * left, ast * right)
{
	ast * returned = new(ast);
	if(!returned)
	{
		yyerror("Out of space!");
		exit(0);
	}

	returned->nodeType = nodeType;
	returned->right    = right;
	returned->left     = left;
	return returned;
}

ast * newComparison(int comparisonType, ast * left, ast * right)
{
	ast * returned = new(ast);
	if(!returned)
	{
		yyerror("Out of space!");
		exit(0);
	}

	returned->nodeType = '0' + comparisonType;
	returned->right    = right;
	returned->left     = left;
	return returned;
}

ast * newFunction(int functionType, ast * left)
{
	fnCall * returned = new(fnCall);
	if(!returned)
	{
		yyerror("Out of space!");
		exit(0);
	}

	returned->nodeType 	   = 'F';
	returned->left     	   = left;
	returned->functionType = functionType;
	return (ast *)returned;
}

ast * newCall(symbol * sym, ast * left)
{
	uFnCall * returned = new(uFnCall);
	if(!returned)
	{
		yyerror("Out of space!");
		exit(0);
	}

	returned->nodeType = 'C';
	returned->left     = left;
	returned->sym 	   = sym;
	return (ast *)returned;
}

ast * newReference(symbol * sym)
{
	symbolReference * returned = new(symbolReference);
	if(!returned)
	{
		yyerror("Out of space!");
		exit(0);
	}

	returned->nodeType = 'N';
	returned->sym 	   = sym;
	return (ast *)returned;
}

ast * newAssignment(symbol * sym, ast * value)
{
	symbolAssignment * returned = new(symbolAssignment);
	if(!returned)
	{
		yyerror("Out of space!");
		exit(0);
	}

	returned->nodeType = '=';
	returned->sym 	   = sym;
	returned->value	   = value;
	return (ast *)returned;
}

ast * newNumber(double number)
{
	numberValue * returned = new(numberValue);
	if(!returned)
	{
		yyerror("Out of space!");
		exit(0);
	}

	returned->nodeType = 'K';
	returned->number    = number;
	return (ast *)returned;
}

ast * newFlow(int nodeType, ast * condition, ast * left, ast * right)
{
	flow * returned = new(flow);
	if(!returned)
	{
		yyerror("Out of space!");
		exit(0);
	}

	returned->nodeType   = nodeType;
	returned->condition  = condition;
	returned->thanOrList = left;
	returned->_else	     = right;
	return (ast *)returned;
}

void doDefine(symbol * name, symbolList * symbols, ast * statements)
{
	// It overwrites the old declaration of this function...cooooooooooool!
	if(name->symbols)
		symbolListFree(name->symbols);

	if(name->function)
		treeFree(name->function);

	// Now build it
	name->symbols = symbols;
	name->function = statements;
}

static double callBuiltInFunction(fnCall * function);
static double callUserFunction(uFnCall * function);

double eval(ast * tree)
{
	flow * tempFlow;
	double tempDouble;
	if(!tree)
	{
		yyerror("Internal error, null eval");
		return 0.0;
	}

	switch(tree->nodeType)
	{
		// Constant
		case 'K': return ((numberValue *)tree)->number;

		// Name reference
		case 'N': return ((symbolReference *)tree)->sym->value;

		// Assignment
		case '=': return ((symbolAssignment *)tree)->sym->value = eval(((symbolAssignment *)tree)->value);

		// Expressions
		case '+': return (eval(tree->left) + eval(tree->right));
		case '-': return (eval(tree->left) - eval(tree->right));
		case '*': return (eval(tree->left) * eval(tree->right));
		case '/': return (eval(tree->left) / eval(tree->right));
		case '|': return (fabs(eval(tree->left)));
		case 'M': return (-(eval(tree->left)));

		// Comparisons
		case '1': return (eval(tree->left) > eval(tree->right));
		case '2': return (eval(tree->left) < eval(tree->right));
		case '3': return (eval(tree->left) != eval(tree->right));
		case '4': return (eval(tree->left) == eval(tree->right));
		case '5': return (eval(tree->left) >= eval(tree->right));
		case '6': return (eval(tree->left) <= eval(tree->right));

		// Control flow
		// Null expressions allowed in grammar, so check for them

		// If/Then/Else
		case 'I':
			tempFlow = (flow *)tree;
			if(eval(tempFlow->condition))
				return (tempFlow->thanOrList ? eval(tempFlow->thanOrList) : .0);
			else
				return (tempFlow->_else ? eval(tempFlow->_else) : .0);

		// While/Do
		case 'W':
			tempFlow = (flow *)tree;
			tempDouble = 0.0;
			if(tempFlow->thanOrList)
				while(eval(tempFlow->condition))
					tempDouble = eval(tempFlow->thanOrList);
			return tempDouble;

		// List of statements
		case 'L': eval(tree->left); return eval(tree->right);
		case 'F': return callBuiltInFunction((fnCall *)tree);
		case 'C': return callUserFunction((uFnCall *)tree);

		default: 
			yyerror("Internal error: bad node '%c'\n", tree->nodeType);
	}

	return 0.0;
}

double callBuiltInFunction(fnCall * function)
{
	builtInFunctions type = function->functionType;
	double value = eval(function->left);

	switch(type)
	{
		case B_sqrt: return sqrt(value);
		case B_exp: return exp(value);
		case B_log: return log(value);
		case B_print: printf("= %4.4g\n", value); return value;
		default:
			yyerror("Unknown buit-in function %d", type);
	}
	return 0.0;
}

double callUserFunction(uFnCall * function)
{
	// Function name (and body)
	symbol * name = function->sym;

	// List of arguments
	symbolList * list;

	// Arguents received by this function
	ast * args = function->left;

	// Aux
	double * oldValue, * newValue;
	double value;
	int argc;
	int i;

	if(!name->function)
	{
		yyerror("Call to undefined function '%s'", name->name);
		return 0.0;
	}

	// Check arguments
	list = name->symbols;
	for(argc = 0; list; list = list->next)
		argc++;

	oldValue = (double *)malloc(argc * sizeof(double));
	newValue = (double *)malloc(argc * sizeof(double));
	if(!oldValue || !newValue)
	{
		yyerror("Out of space in '%s'", name->name);
		return .0;
	}

	// Evaluate the arguments
	for(i = 0; i < argc; i++)
	{
		if(!args)
		{
			yyerror("Too few arguments in call to '%s'", name->name);
			free(oldValue);
			free(newValue);
			return .0;
		}

		// Check if it's a list
		if(args->nodeType == 'L')
		{
			newValue[i] = eval(args->left);
			args = args->right;
		}
		// If it's the end of the list
		else 
		{
			newValue[i] = eval(args);
			args = NULL;
		}
	}

	// Save old values of dummies, assign new ones
	list = name->symbols;
	for(i = 0; i < argc; i++)
	{
		symbol * sym = list->sym;

		oldValue[i] = sym->value;
		sym->value = newValue[i];
		list = list->next;
	}

	// Free copies
	free(newValue);

	// Eval the function
	value = eval(name->function);

	// Put the real values of the dummies back
	list = name->symbols;
	for(i = 0; i < argc; i++)
	{
		name = list->sym;
		name->value = oldValue[i];
		list = list->next;
	}

	// Free parameters
	return value;
}

void treeFree(ast * tree)
{
	switch(tree->nodeType)
	{
		// Two subtrees
		case '+':
		case '-':
		case '*':
		case '/':
		case '1': case '2': case '3': case '4': case '5': case '6':
		case 'L':
			treeFree(tree->right);

		// One subtree
		case '|':
		case 'M': case 'C': case 'F':
			treeFree(tree->left);

		// No subtree
		case 'K': case 'N':
			break; 

		case '=':
			free(((symbolAssignment *)tree)->value);
			break;

		// Up to three subtree
		case 'I': case 'W':
			free(((flow *)tree)->condition);
			if(((flow *)tree)->thanOrList)
				treeFree(((flow *)tree)->thanOrList);
			if(((flow *)tree)->_else)
				treeFree(((flow *)tree)->_else);
			break;

		default:
			printf("Internal error: free bad node '%c'\n", tree->nodeType);
	}

	// No releaaaaase-me!
	free(tree);
}

void yyerror(char *s, ...)
{
	va_list ap;
	va_start(ap, s);
	fprintf(stderr, "%d: error: ", yylineno);
	vfprintf(stderr, s, ap);
	fprintf(stderr, "\n");
}