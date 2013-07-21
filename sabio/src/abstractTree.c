/**
 * @file abstractTree.c
 **/
#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include <string.h>
#include <math.h>

#include <dataType.h>
#include <abstractTree.h>

static double callBuiltIn(builtInFuncCall *);
static double callUser(userFuncCall *);

abstractTree * newAbstractTree(int _nodeType, abstractTree * _left, abstractTree * _right)
{
	abstractTree * absTree = 0;

	absTree = malloc(sizeof(abstractTree));

	if(!absTree)
	{
		yyerror("out of space");
		exit(0);
	}
	absTree->nodeType = _nodeType;
	absTree->left = _left;
	absTree->right = _right;

	return absTree;
}

abstractTree * newCmp(int _cmpType, abstractTree * _left, abstractTree * _right)
{
	abstractTree * abstractNode = 0;

	abstractNode = malloc(sizeof(abstractTree));

	if(!abstractNode)
	{
		yyerror("out of space");
		exit(0);
	}

	abstractNode->nodeType = '0' + _cmpType;
	abstractNode->left = _left;
	abstractNode->right = _right;

	return abstractNode;
}

abstractTree * newFunc(int _funcType, abstractTree * _left)
{
	builtInFuncCall * absFuncNode = 0;

	absFuncNode = malloc(sizeof(builtInFuncCall));

	if(!absFuncNode)
	{
		yyerror("out of space");
		exit(0);
	}
	absFuncNode->nodeType = 'F';
	absFuncNode->left = _left;
	absFuncNode->functionType = _funcType;
	return (abstractTree *)absFuncNode;
}

abstractTree * newUserCall(symbol * _sym, abstractTree * _left)
{
	userFuncCall * absUserFunc = 0;

	absUserFunc = malloc(sizeof(userFuncCall));

	if(!absUserFunc)
	{
		yyerror("out of space");
		exit(0);
	}
	absUserFunc->nodeType = 'C';
	absUserFunc->left = _left;
	absUserFunc->userSymbolRef = _sym;

	return (abstractTree *)absUserFunc;
}

abstractTree * newRef(symbol * _sym)
{
	symbolRef * absSymbolRef = 0;
	absSymbolRef = malloc(sizeof(symbolRef));

	if(!absSymbolRef)
	{
		yyerror("out of space");
		exit(0);
	}

	absSymbolRef->nodeType = 'N';
	absSymbolRef->symb = _sym;

	return (abstractTree *)absSymbolRef;
}

abstractTree * newAsgn(symbol * _sym, abstractTree * _value)
{
	symasgn * absAsg = 0 ;

	absAsg = malloc(sizeof(symasgn));

	if(!absAsg)
	{
		yyerror("out of space");
		exit(0);
	}

	absAsg->nodeType = '=';
	absAsg->sym = _sym;
	absAsg->value = _value;

	return (abstractTree *)absAsg;
}

abstractTree * newNum(double _value)
{
	numValue * absValue = 0;

	absValue = malloc(sizeof(numValue));

	if(!absValue)
	{
		yyerror("out of space");
		exit(0);
	}

	absValue->nodeType = 'K';
	absValue->number = _value;

	return (abstractTree *)absValue;
}

abstractTree * newFlow(int _nodeType, abstractTree * _cond, abstractTree * _thenList, abstractTree * _elseList)
{
	flow * absFlow = 0;

	absFlow = malloc(sizeof(flow));

	if(!absFlow)
	{
		yyerror("out of space");
		exit(0);
	}

	absFlow->nodeType = _nodeType;
	absFlow->condition = _cond;
	absFlow->thenList = _thenList;
	absFlow->elseList = _elseList;

	return (abstractTree *)absFlow;
}

static void refListfree(symlist * _sl)
{
	symlist * nsl;

	while(_sl)
	{
		nsl = _sl->next;
		free(_sl);
		_sl = nsl;
	}
}

/* define a function */
void dodef(symbol * _name, symlist * _syms, abstractTree * _stmts)
{
	if(_name->symbolName)
	{
		refListfree(_name->syms);
	}
	if(_name->function)
	{
		treefree(_name->function);
	}
	_name->syms = _syms;
	_name->function = _stmts;
}

double eval(abstractTree * _stmt)
{
	double v = 0;

	if(!_stmt)
	{
		yyerror("internal error, null eval");
		return 0.0;
	}

	switch(_stmt->nodeType)
	{
		/* constant */
		case 'K':
			v = ((numValue *)_stmt)->number;
			break;
		/* name reference */
		case 'N':
			v = ((symbolRef *)_stmt)->symb->value;
			break;
		/* assignment */
		case '=':
			v = ((symasgn *)_stmt)->sym->value = eval(((symasgn *)_stmt)->value);
			break;
		/* expressions */
		case '+':
			v = eval(_stmt->left) + eval(_stmt->right);
			break;
		case '-':
			v = eval(_stmt->left) - eval(_stmt->right);
			break;
		case '*':
			v = eval(_stmt->left) * eval(_stmt->right);
			break;
		case '/':
			v = eval(_stmt->left) / eval(_stmt->right);
			break;
		case '|':
			v = fabs(eval(_stmt->left));
			break;
		case 'M':
			v = -eval(_stmt->left);
			break;
		/* comparisons */
		case '1':
			v = (eval(_stmt->left) > eval(_stmt->right)) ? 1 : 0;
			break;
		case '2':
			v = (eval(_stmt->left) < eval(_stmt->right)) ? 1 : 0;
			break;
		case '3':
			v = (eval(_stmt->left) != eval(_stmt->right)) ? 1 : 0;
			break;
		case '4':
			v = (eval(_stmt->left) == eval(_stmt->right)) ? 1 : 0;
			break;
		case '5':
			v = (eval(_stmt->left) >= eval(_stmt->right)) ? 1 : 0;
			break;
		case '6':
			v = (eval(_stmt->left) <= eval(_stmt->right)) ? 1 : 0;
			break;
		/* control flow */
		/* null if/else/do expressions allowed in the grammar, so check for them */
		case 'I': 
			if(eval(((flow *)_stmt)->condition) != 0)
			{
				if(((flow *)_stmt)->thenList)
				{
					v = eval(((flow *)_stmt)->thenList);
				}
				else
				{
					v = 0.0; /* a default value */
				}
			}
			else
			{
				if( ((flow *)_stmt)->elseList)
				{
					v = eval(((flow *)_stmt)->elseList);
				}
				else
				{
					v = 0.0;		/* a default value */
				}
			}
			break;
		case 'W':
			v = 0.0;		/* a default value */
			if( ((flow *)_stmt)->thenList)
			{
				while( eval(((flow *)_stmt)->condition) != 0)
				v = eval(((flow *)_stmt)->thenList);
			}
			break;			/* labstractTree value is value */
		case 'L':
			eval(_stmt->left);
			v = eval(_stmt->right);
			break;
		case 'F':
			v = callBuiltIn((builtInFuncCall *)_stmt);
			break;
		case 'C':
			v = callUser((userFuncCall *)_stmt);
			break;
		default:
			printf("internal error: bad node %c\n", _stmt->nodeType);
	}
	return v;
}

static double callBuiltIn(builtInFuncCall * _func)
{
	builtInFunction functype = _func->functionType;
	double v = eval(_func->left);

	switch(functype)
	{
		case B_sqrt:
			return sqrt(v);
		case B_exp:
			return exp(v);
		case B_log:
			return log(v);
		case B_print:
			printf("= %4.4g\n", v);
			return v;
		default:
			yyerror("Unknown built-in function %d", functype);
		return 0.0;
	}
}

static double callUser(userFuncCall * _func)
{
	symbol * fn = 0, * tmp = 0;	/* function name */
	symlist * sl;		/* dummy arguments */
	abstractTree * args = 0;	/* actual arguments */
	double * oldval, * newval;	/* saved arg values */
	double v = 0.0;
	int nargs = 0;
	int i = 0;

	fn = _func->userSymbolRef;
	args = _func->left;

	if(!fn->function)
	{
		yyerror("call to undefined function", fn->symbolName);
		return 0;
	}

	/* count the arguments */
	sl = fn->syms;
	for(nargs = 0; sl; sl = sl->next)
	{
		nargs++;
	}

	/* prepare to save them */
	oldval = (double *)malloc(nargs * sizeof(double));
	newval = (double *)malloc(nargs * sizeof(double));
	if(!oldval || !newval)
	{
		yyerror("Out of space in %s", fn->symbolName);
		return 0.0;
	}

	/* evaluate the arguments */
	for(i = 0; i < nargs; i++)
	{
		if(!args)
		{
			yyerror("too few args in call to %s", fn->symbolName);
			free(oldval); free(newval);
			return 0;
		}

		if(args->nodeType == 'L')
		{	/* if this is a list node */
			newval[i] = eval(args->left);
			args = args->right;
		}
		else
		{			/* if it's the end of the list */
			newval[i] = eval(args);
			args = NULL;
		}
	}

	/* save old values of dummies, assign new ones */
	sl = fn->syms;
	for(i = 0; i < nargs; i++)
	{
		tmp = sl->sym;

		oldval[i] = tmp->value;
		tmp->value = newval[i];
		sl = sl->next;
	}

	free(newval);

	/* evaluate the function */
	v = eval(fn->function);

	/* put the dummies back */
	sl = fn->syms;
	for(i = 0, tmp = 0; i < nargs; i++)
	{
		tmp = sl->sym;

		tmp->value = oldval[i];
		sl = sl->next;
	}

	free(oldval);
	return v;
}


void treefree(abstractTree * _absTree)
{
	switch(_absTree->nodeType)
	{
		/* two subtrees */
		case '+':
		case '-':
		case '*':
		case '/':
		case '1':  case '2':  case '3':  case '4':  case '5':  case '6':
		case 'L':
		treefree(_absTree->right);

		/* one subtree */
		case '|':
		case 'M': case 'C': case 'F':
			treefree(_absTree->left);

		/* no subtree */
		case 'K': case 'N':
			break;

		case '=':
			free( ((symasgn *)_absTree)->value);
			break;

		case 'I': case 'W':
			free( ((flow *)_absTree)->condition);
			if( ((flow *)_absTree)->thenList)
			{
				free( ((flow *)_absTree)->thenList);
			}
			if( ((flow *)_absTree)->elseList)
			{
				free( ((flow *)_absTree)->elseList);
			}
			break;

		default:
			printf("internal error: free bad node %c\n", _absTree->nodeType);
	}

	free(_absTree); /* always free the node itself */
}

void yyerror(char * s, ...)
{
	va_list ap;
	va_start(ap, s);

	fprintf(stderr, "%d: error: ", yylineno);
	vfprintf(stderr, s, ap);
	fprintf(stderr, "\n");
}

/* debugging: dump out an abstractTree */
int debug = 0;
void dumpabstractTree(abstractTree * _absTree, int _level)
{
	printf("%*s", 2 * _level, "");	/* indent to this level */
	_level++;

	if(!_absTree)
	{
		printf("NULL\n");
		return;
	}

	switch(_absTree->nodeType)
	{
		/* constant */
		case 'K':
			printf("number %4.4g\n", ((numValue *)_absTree)->number);
			break;
		/* name reference */
		case 'N':
			printf("ref %s\n", ((symbolRef *)_absTree)->symb->symbolName);
			break;
		/* assignment */
		case '=':
			printf("= %s\n", ((symbolRef *)_absTree)->symb->symbolName);
			dumpabstractTree( ((symasgn *)_absTree)->value, _level);
			return;

		/* expressions */
		case '+': case '-': case '*': case '/': case 'L':
		case '1': case '2': case '3':
		case '4': case '5': case '6': 
			printf("binop %c\n", _absTree->nodeType);
			dumpabstractTree(_absTree->left, _level);
			dumpabstractTree(_absTree->right, _level);
			return;

		case '|': case 'M': 
			printf("unop %c\n", _absTree->nodeType);
			dumpabstractTree(_absTree->left, _level);
			return;

		case 'I': case 'W':
			printf("flow %c\n", _absTree->nodeType);
			dumpabstractTree( ((flow *)_absTree)->condition, _level);
			if( ((flow *)_absTree)->thenList)
			{
				dumpabstractTree( ((flow *)_absTree)->thenList, _level);
			}
			if( ((flow *)_absTree)->elseList)
			{
				dumpabstractTree( ((flow *)_absTree)->elseList, _level);
			}
			return;

		case 'F':
			printf("builtin %d\n", ((builtInFuncCall *)_absTree)->functionType);
			dumpabstractTree(_absTree->left, _level);
			return;

		case 'C':
			printf("call %s\n", ((userFuncCall *)_absTree)->userSymbolRef->symbolName);
			dumpabstractTree(_absTree->left, _level);
			return;

		default:
			printf("bad %c\n", _absTree->nodeType);
			return;
	}
}
