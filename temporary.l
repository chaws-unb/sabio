%option noyywrap nodefault yylineno
%option header-file="clexer.h"

%x COMMENT
%x IFILE

D	[0-9]
L	[a-zA-Z_]
H	[a-fA-F0-9]
E	[Ee][+-]?{D}+
FS	(f|F|l|L)
IS	(u|U|l|L)*
UCN	(\\u[0-9a-fA-F]{4}|\\U[0-9a-fA-F]{8})
EXP	([Ee][-+]?[0-9]+)
ILEN	([Uu](L|l|LL|ll)?|(L|l|LL|ll)[Uu]?)

%{
	#include "handleFile.h"
	#include "symbolTable.h"
	#include "dataType.h"
%}

%%
"/*"
	{
		BEGIN(COMMENT);
	}
<COMMENT>"*/"
	{
		BEGIN(INITIAL);
	}
<COMMENT>([^*]|\en)+|.
	/* Comments in C++*/
"//".*\n

<COMMENT><<EOF>> {
		printf("%s:%d: Unterminated comment\n", currentFileName, yylineno);
		return 0;
	}

 /*Basic Pre-processor*/
"#"" "*if.*\n 
"#"" "*else.*\n
"#"" "*endif.*\n
"#"" "*define.*\n
"#"" "*line.*\n

 /*Recognize include*/
^"#"[ \t]*include[ \t]*[\"<] {
		BEGIN IFILE;
	}
<IFILE>[^>\"]+ {
		{
			int c;
			while((c = input()) && c != '\n');
		}
		newFile(strdup(yytext));
		BEGIN INITIAL;
		}

<IFILE>.|\n {
		fprintf(stderr, "%s:%d bad include line\n", currentFileName, yylineno);
		BEGIN INITIAL;
	}

<<EOF>> {
		if(!popFile()) yyterminate();
	}

"auto"			{ addSymbolRef(yylineno, currentFileName, yytext, defining); return(AUTO); }
"break"			{ addSymbolRef(yylineno, currentFileName, yytext, defining); return(BREAK); }
"case"			{ addSymbolRef(yylineno, currentFileName, yytext, defining); return(CASE); }
"char"			{ addSymbolRef(yylineno, currentFileName, yytext, defining); return(CHAR); }
"const"			{ addSymbolRef(yylineno, currentFileName, yytext, defining); return(CONST); }
"continue"		{ addSymbolRef(yylineno, currentFileName, yytext, defining); return(CONTINUE); }
"default"		{ addSymbolRef(yylineno, currentFileName, yytext, defining); return(DEFAULT); }
"do"			{ addSymbolRef(yylineno, currentFileName, yytext, defining); return(DO); }
"double"		{ addSymbolRef(yylineno, currentFileName, yytext, defining); return(DOUBLE); }
"else"			{ addSymbolRef(yylineno, currentFileName, yytext, defining); return(ELSE); }
"enum"			{ addSymbolRef(yylineno, currentFileName, yytext, defining); return(ENUM); }
"extern"		{ addSymbolRef(yylineno, currentFileName, yytext, defining); return(EXTERN); }
"float"			{ addSymbolRef(yylineno, currentFileName, yytext, defining); return(FLOAT); }
"for"			{ addSymbolRef(yylineno, currentFileName, yytext, defining); return(FOR); }
"goto"			{ addSymbolRef(yylineno, currentFileName, yytext, defining); return(GOTO); }
"if"			{ addSymbolRef(yylineno, currentFileName, yytext, defining); return(IF); }
"int"			{ addSymbolRef(yylineno, currentFileName, yytext, defining); return(INT); }
"long"			{ addSymbolRef(yylineno, currentFileName, yytext, defining); return(LONG); }
"register"		{ addSymbolRef(yylineno, currentFileName, yytext, defining); return(REGISTER); }
"return"		{ addSymbolRef(yylineno, currentFileName, yytext, defining); return(RETURN); }
"short"			{ addSymbolRef(yylineno, currentFileName, yytext, defining); return(SHORT); }
"signed"		{ addSymbolRef(yylineno, currentFileName, yytext, defining); return(SIGNED); }
"sizeof"		{ addSymbolRef(yylineno, currentFileName, yytext, defining); return(SIZEOF); }
"static"		{ addSymbolRef(yylineno, currentFileName, yytext, defining); return(STATIC); }
"struct"		{ addSymbolRef(yylineno, currentFileName, yytext, defining); return(STRUCT); }
"switch"		{ addSymbolRef(yylineno, currentFileName, yytext, defining); return(SWITCH); }
"typedef"		{ addSymbolRef(yylineno, currentFileName, yytext, defining); return(TYPEDEF); }
"union"			{ addSymbolRef(yylineno, currentFileName, yytext, defining); return(UNION); }
"unsigned"		{ addSymbolRef(yylineno, currentFileName, yytext, defining); return(UNSIGNED); }
"void"			{ addSymbolRef(yylineno, currentFileName, yytext, defining); return(VOID); }
"volatile"		{ defining = 1; addSymbolRef(yylineno, currentFileName, yytext, defining); return(VOLATILE); }
"while"			{ addSymbolRef(yylineno, currentFileName, yytext, defining); return(WHILE); }

{L}({L}|{D})*		{ addSymbolRef(yylineno, currentFileName, yytext, defining); return(check_type()); }

0[xX]{H}+{IS}?		{ addSymbolRef(yylineno, currentFileName, yytext, defining); return(CONSTANT); }
0{D}+{IS}?		{ addSymbolRef(yylineno, currentFileName, yytext, defining); return(CONSTANT); }
{D}+{IS}?		{ addSymbolRef(yylineno, currentFileName, yytext, defining); return(CONSTANT); }
L?'(\\.|[^\\'])+'	{ addSymbolRef(yylineno, currentFileName, yytext, defining); return(CONSTANT); }

{D}+{E}{FS}?		{ addSymbolRef(yylineno, currentFileName, yytext, defining); return(CONSTANT); }
{D}*"."{D}+({E})?{FS}?	{ addSymbolRef(yylineno, currentFileName, yytext, defining); return(CONSTANT); }
{D}+"."{D}*({E})?{FS}?	{ addSymbolRef(yylineno, currentFileName, yytext, defining); return(CONSTANT); }

L?\"(\\.|[^\\"])*\"	{ addSymbolRef(yylineno, currentFileName, yytext, defining); return(STRING_LITERAL); }

"..."			{ addSymbolRef(yylineno, currentFileName, yytext, defining); return(ELLIPSIS); }
">>="			{ addSymbolRef(yylineno, currentFileName, yytext, defining); return(RIGHT_ASSIGN); }
"<<="			{ addSymbolRef(yylineno, currentFileName, yytext, defining); return(LEFT_ASSIGN); }
"+="			{ addSymbolRef(yylineno, currentFileName, yytext, defining); return(ADD_ASSIGN); }
"-="			{ addSymbolRef(yylineno, currentFileName, yytext, defining); return(SUB_ASSIGN); }
"*="			{ addSymbolRef(yylineno, currentFileName, yytext, defining); return(MUL_ASSIGN); }
"/="			{ addSymbolRef(yylineno, currentFileName, yytext, defining); return(DIV_ASSIGN); }
"%="			{ addSymbolRef(yylineno, currentFileName, yytext, defining); return(MOD_ASSIGN); }
"&="			{ addSymbolRef(yylineno, currentFileName, yytext, defining); return(AND_ASSIGN); }
"^="			{ addSymbolRef(yylineno, currentFileName, yytext, defining); return(XOR_ASSIGN); }
"|="			{ addSymbolRef(yylineno, currentFileName, yytext, defining); return(OR_ASSIGN); }
">>"			{ addSymbolRef(yylineno, currentFileName, yytext, defining); return(RIGHT_OP); }
"<<"			{ addSymbolRef(yylineno, currentFileName, yytext, defining); return(LEFT_OP); }
"++"			{ addSymbolRef(yylineno, currentFileName, yytext, defining); return(INC_OP); }
"--"			{ addSymbolRef(yylineno, currentFileName, yytext, defining); return(DEC_OP); }
"->"			{ addSymbolRef(yylineno, currentFileName, yytext, defining); return(PTR_OP); }
"&&"			{ addSymbolRef(yylineno, currentFileName, yytext, defining); return(AND_OP); }
"||"			{ addSymbolRef(yylineno, currentFileName, yytext, defining); return(OR_OP); }
"<="			{ addSymbolRef(yylineno, currentFileName, yytext, defining); return(LE_OP); }
">="			{ addSymbolRef(yylineno, currentFileName, yytext, defining); return(GE_OP); }
"=="			{ addSymbolRef(yylineno, currentFileName, yytext, defining); return(EQ_OP); }
"!="			{ addSymbolRef(yylineno, currentFileName, yytext, defining); return(NE_OP); }
";"			{ addSymbolRef(yylineno, currentFileName, yytext, defining); return(';'); }
("{"|"<%")		{ addSymbolRef(yylineno, currentFileName, yytext, defining); return('{'); }
("}"|"%>")		{ addSymbolRef(yylineno, currentFileName, yytext, defining); return('}'); }
","			{ addSymbolRef(yylineno, currentFileName, yytext, defining); return(','); }
":"			{ addSymbolRef(yylineno, currentFileName, yytext, defining); return(':'); }
"="			{ addSymbolRef(yylineno, currentFileName, yytext, defining); return('='); }
"("			{ addSymbolRef(yylineno, currentFileName, yytext, defining); return('('); }
")"			{ addSymbolRef(yylineno, currentFileName, yytext, defining); return(')'); }
("["|"<:")		{ addSymbolRef(yylineno, currentFileName, yytext, defining); return('['); }
("]"|":>")		{ addSymbolRef(yylineno, currentFileName, yytext, defining); return(']'); }
"."			{ addSymbolRef(yylineno, currentFileName, yytext, defining); return('.'); }
"&"			{ addSymbolRef(yylineno, currentFileName, yytext, defining); return('&'); }
"!"			{ addSymbolRef(yylineno, currentFileName, yytext, defining); return('!'); }
"~"			{ addSymbolRef(yylineno, currentFileName, yytext, defining); return('~'); }
"-"			{ addSymbolRef(yylineno, currentFileName, yytext, defining); return('-'); }
"+"			{ addSymbolRef(yylineno, currentFileName, yytext, defining); return('+'); }
"*"			{ addSymbolRef(yylineno, currentFileName, yytext, defining); return('*'); }
"/"			{ addSymbolRef(yylineno, currentFileName, yytext, defining); return('/'); }
"%"			{ addSymbolRef(yylineno, currentFileName, yytext, defining); return('%'); }
"<"			{ addSymbolRef(yylineno, currentFileName, yytext, defining); return('<'); }
">"			{ addSymbolRef(yylineno, currentFileName, yytext, defining); return('>'); }
"^"			{ addSymbolRef(yylineno, currentFileName, yytext, defining); return('^'); }
"|"			{ addSymbolRef(yylineno, currentFileName, yytext, defining); return('|'); }
"?"			{ addSymbolRef(yylineno, currentFileName, yytext, defining); return('?'); }

[ \t\v\n\f]		{  }
.			{ /* ignore bad characters */ }

%%
