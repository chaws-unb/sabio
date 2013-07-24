#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../cGrammar.h"


void * declaration__declaration_specifiers__SEMICOLON(ast * decl)
{
	if(debugMode) printf(": declaration->declaration_specifiers ;\n");
	return decl;
}

// THIS FUNCTION MUST DO SOMETHING ELSE, EVAL??, SINCE IT FOUND A SEMICOLON
/**
 *	This is the kind: int a;
 *	So we probably have current symbol set
 */
void * declaration__declaration_specifiers__init_declarator_list__SEMICOLON(/*ast * spec,*/ ast * init)
{
	if(debugMode) printf(": declaration->declaration_specifiers init_declarator_list ;\n");
	return init;
}
