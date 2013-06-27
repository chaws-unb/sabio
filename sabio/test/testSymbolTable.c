#include "CUnit/Basic.h"

int initSuiteSymbolTable(void)
{

}

int cleanSuiteSymbleTable(void)
{
}

void testSymbolTable(void)
{
	CU_ASSERT(1 == calcHash("testHash"));
}
