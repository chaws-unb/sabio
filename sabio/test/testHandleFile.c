#include "CUnit/Basic.h"

int initSuiteHandleFile(void)
{

}

int cleanSuiteHandleFile(void)
{
}

void testHandleFile(void)
{
	CU_ASSERT(1 == newFile("/bin/simple2.c"));
	CU_ASSERT(-1 == newFile("/bin/blah.c"));
	CU_ASSERT(1 == popFile());
}
