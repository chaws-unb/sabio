%{
#include <cstdio>
#include <iostream>
using namespace std;

// Avoid g++ symbols name
extern "C" int yylex();
extern "C" int yyparse();
extern "C" FILE * yyin;

void yyerror(const char *);
%}

%union {
	int ival;
	float fval;
	char *sval;
}

%token <ival> INT 
%token <fval> FLOAT
%token <sval> STRING
%token SNAZZLE TYPE
%token END

%%
snazzle:
	header template body_section footer {cout << "Compiled!" << endl;};
header:
	SNAZZLE FLOAT {cout << "reading a snazzle file version: " << $2 << endl;};
template:
	typelines;
typelines:
	typelines typeline | typeline;
typeline:
	TYPE STRING {cout << "new defined snazzle type " << $2 << endl;};
body_section:
	body_lines;
body_lines:
	body_lines body_line | body_line;
body_line:
	INT INT INT INT STRING {cout << "new snazzle: " << $1 << $2 << $3 << $4 << $5 << endl;};
footer:
	END;
%%

main() 
{

	FILE * input = fopen("input.snazzle", "r");
	if(!input){
		cout << "Ops, no file!" << endl;
		return -1;	
	}

	yyin = input;

	// Faz todo parsing
	do
	{
		yyparse();
	}while(!feof(yyin));
}

void yyerror(const char * s)
{
	cout << "EEK, parse error! Message: " << s << endl;
	exit(-1);
}
/* ANTIGO
snazzle INT 	 {cout << "bison found an int: " 	<< $2 << endl;}
	| snazzle FLOAT  {cout << "bison found a float: " 	<< $2 << endl;}
	| snazzle STRING {cout << "bison found a string: "  << $2 << endl;}
	| INT 			 {cout << "bison found an int: " 	<< $1 << endl;}
	| FLOAT 		 {cout << "bison found a float: " 	<< $1 << endl;}
	| STRING 		 {cout << "bison found a string: " 	<< $1 << endl;}
	;
*/