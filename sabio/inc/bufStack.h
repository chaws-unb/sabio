#ifndef _DATA_TYPE_H_
#define _DATA_TYPE_H_

/**
* @brief Keep reference to files
*/
typedef struct _bufstack {
  struct bufstack *prev; /*previous entry*/
  YY_BUFFER_STATE bs;	 /*sabed buffer*/
  int lineno;		 /*saved line number*/
  char *filename;	 /*name of this file*/
  FILE *f;		 /*current file*/
  
} *bufstack=0;

/**
* @param _fn
* @return
* @brief push a new file to list of files
*/
int newfile(char *_fn);

/**
* @return
* @brief pop files from list of files
*/
int popfile(void);

#endif
