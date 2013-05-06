%start program
%token LET INTEGER IN
%token SKIP IF THEN ELSE END WHILE DO READ WRITE
%token NUMBER
%token IDENTIFIER
%left '-' '+'
%right '^'

%%

program : LET declarations IN commands END;
declarations: /*empty*/
  | INTEGER id_seq IDENTIFIER '.';
id_seq : /*empty*/
  | id_seq IDENTIFIER ',';
commands : /*empty*/
  | commands command ';';
command : READ IDENTIFIER
  | WRITE exp
  | IDENTIFIER ASSGNOP exp
  | IF exp commands ELSE
  | WHILE exp DO commands END;
exp: NUMBER
  | IDENTIFIER
  | exp '<' exp
  | exp '=' exp
  | exp '>' exp
  | exp '+' exp
  | exp '-' exp
  | exp '*' exp
  | exp '/' exp
  | exp '^' exp
  | exp '(' exp ')';

%%

main(int argc, char *argv[])
{
  extern FILE *yyin;
  ++argv; --argc;
  yyin = fopen(argv[0], "r");
  yydebug = 1;
  erros = 0;
  yyparse();
}
yyerror(char *s)
{
  printf("%s\n", s);
}

