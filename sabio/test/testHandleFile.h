#ifndef _TEST_HANDLE_FILE_H
#define _TEST_HANDLE_FILE_H

static FILE * temp_file = NULL;

int initSuiteHandleFile(void);
int cleanSuiteHandleFile(void);
void testHandleFile(void);

#endif
