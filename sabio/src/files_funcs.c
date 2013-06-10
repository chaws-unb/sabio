#include "../inc/bufStack.h"

main(int argc, char **argv)
{
  if(argc < 2)
  {
    fprintf(stderr, "need filename\n");
    return 1;
  }
  if(newfile(argv[1]))
    yylex();
}

int newfile(char *fn)
{
  FILE *f = fopen(fn, "r");
  struct bufstack *bs = malloc(sizeof(struct bufstack));

  if(!f){perror(fn); return 0;}
  if(!bs){perror("malloc"); exit(1);}

  /*remember state*/
  if(curbs){curbs->lineno = yylineno;}
  bs->prev = curbs;

  /*set up current entry*/
  bs->bs = yy_create_buffer(f, YY_BUF_SIZE);

  bs->f = f;
  bs->filename = fn;
  yy_switch_to_buffer(bs->bs);
  curbs = bs;
  yylineno = 1;
  curfilename = fn;
  return 1;
}

int popfile(void)
  {
    struct bufstack *bs = curbs;
    struct bufstack *prevbs;
    if(!bs) return 0;

    /*get rid of current entry*/
    fclose(bs->f);
    yy_delete_buffer(bs->bs);

    /*switch back to previous*/
    prevbs = bs->prev;
    free(bs);

    if(!prevbs) return 0;

    yy_switch_to_buffer(prevbs->bs);
    curbs = prevbs;
    yylineno = curbs->lineno;
    curfilename = curbs->filename;
    return 1;  
  }
