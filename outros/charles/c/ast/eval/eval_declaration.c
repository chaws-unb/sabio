#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../ast.h"

void * eval_declaration(declaration * decl)
{
	if(debugMode) printf("Begin of '%s' declaration...", decl->sym->name);

	// Aux vars
	char *  charVal;
	short * shortVal;
	int *   intVal;

	// The value is going to be an eval of the right node of this tree
	if(decl->expression)
	{
		if(debugMode) printf("Eval its expression...");

		decl->sym->value = eval(decl->expression);
		// Try to convert to correct type
		switch(decl->sym->dataType)
		{

			case _CHAR:
				charVal = new(char);
				*charVal = (char)(*(double *)decl->sym->value);
				decl->sym->value = charVal;
				break;
				break;

			case _SHORT:
				shortVal = new(short);
				*shortVal = (short)(*(double *)decl->sym->value);
				decl->sym->value = shortVal;
				break;

			case _INT:
				// Acessa o valor em double antes de converter pra inteiro
				// assim evita os big/little endian da vida
				intVal = new(int);
				*intVal = (int)(*(double *)decl->sym->value);
				decl->sym->value = intVal;
				break;

			// Nothing to do
			case _VOID:
			case _FLOAT:
			case _DOUBLE:
				break;
		}

	}

	// The symbol
	if(debugMode) 
	{
		printf("End of '%s' declaration\n", decl->sym->name);
		printSymbol(decl->sym);
	}
}