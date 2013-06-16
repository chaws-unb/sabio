#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include "printDebug.h"
#include "symbolTable.h"

/* print the references
 * sort the table alphabetically
 * then flip each entry's reflist to get it into forward order
 * and print it out 
 */

/* aux function for sorting */
static int symcompare(const void *xa, const void *xb)
{
  const symbol *a = xa;
  const symbol *b = xb;

  if(!a->symbolName) {
    if(!b->symbolName) return 0;	/* both empty */
    return 1;			/* put empties at the end */
  }
  if(!b->symbolName) return -1;
  return strcmp(a->symbolName, b->symbolName);
}

void printReferences()
{
	symbol *sp;

	qsort(symbolTableHash, SIZE_SYMBOL_TABLE, sizeof(symbol), symcompare); /* Organiza a tabela de simbolo */

	for(sp = symbolTableHash; sp->symbolName && sp < symbolTableHash+SIZE_SYMBOL_TABLE; sp++)
	{
		char *prevfn = NULL; /* Ultimo arquivo*/

		/* reverse the list of references */
		refList *rp = sp->refInfoList;
		refList *rpp = 0;	/* previous ref */
		refList *rpn;	/* next ref */

		do
		{
			rpn = rp->next;
			rp->next = rpp;
			rpp = rp;
			rp = rpn;
		} while(rp);

		/* Imprime as palavras e referências */
		printf(" %10s", sp->symbolName);
		for(rp = rpp; rp; rp = rp->next)
		{
			if(rp->fileName == prevfn)
			{
				printf(" %d", rp->lineno);
			} else
			{
				printf(" %s:%d", rp->fileName, rp->lineno);
				prevfn = rp->fileName;
			}
			if(rp->flags & 01)
			{
				printf("*");
			}
		}
		printf("\n");
	}
}
