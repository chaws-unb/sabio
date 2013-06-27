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

"auto"			{ addSymbolRef(yylineno, currentFileName, yytext, defining);  }
"break"			{ addSymbolRef(yylineno, currentFileName, yytext, defining);  }
"case"			{ addSymbolRef(yylineno, currentFileName, yytext, defining);  }
"char"			{ addSymbolRef(yylineno, currentFileName, yytext, defining); }
"const"			{ addSymbolRef(yylineno, currentFileName, yytext, defining);  }
"continue"		{ addSymbolRef(yylineno, currentFileName, yytext, defining); ; }
"default"		{ addSymbolRef(yylineno, currentFileName, yytext, defining);  }
"do"			{ addSymbolRef(yylineno, currentFileName, yytext, defining); }
"double"		{ addSymbolRef(yylineno, currentFileName, yytext, defining); }
"else"			{ addSymbolRef(yylineno, currentFileName, yytext, defining); }
"enum"			{ addSymbolRef(yylineno, currentFileName, yytext, defining);  }
"extern"		{ addSymbolRef(yylineno, currentFileName, yytext, defining);  }
"float"			{ addSymbolRef(yylineno, currentFileName, yytext, defining);  }
"for"			{ addSymbolRef(yylineno, currentFileName, yytext, defining);  }
"goto"			{ addSymbolRef(yylineno, currentFileName, yytext, defining);  }
"if"			{ addSymbolRef(yylineno, currentFileName, yytext, defining);  }
"int"			{ addSymbolRef(yylineno, currentFileName, yytext, defining);  }
"long"			{ addSymbolRef(yylineno, currentFileName, yytext, defining);  }
"register"		{ addSymbolRef(yylineno, currentFileName, yytext, defining);  }
"return"		{ addSymbolRef(yylineno, currentFileName, yytext, defining);  }
"short"			{ addSymbolRef(yylineno, currentFileName, yytext, defining); }
"signed"		{ addSymbolRef(yylineno, currentFileName, yytext, defining);  }
"sizeof"		{ addSymbolRef(yylineno, currentFileName, yytext, defining);}
"static"		{ addSymbolRef(yylineno, currentFileName, yytext, defining); }
"struct"		{ addSymbolRef(yylineno, currentFileName, yytext, defining);  }
"switch"		{ addSymbolRef(yylineno, currentFileName, yytext, defining);  }
"typedef"		{ addSymbolRef(yylineno, currentFileName, yytext, defining); }
"union"			{ addSymbolRef(yylineno, currentFileName, yytext, defining); }
"unsigned"		{ addSymbolRef(yylineno, currentFileName, yytext, defining); }
"void"			{ addSymbolRef(yylineno, currentFileName, yytext, defining); }
"volatile"		{ defining = 1; addSymbolRef(yylineno, currentFileName, yytext, defining);  }
"while"			{ addSymbolRef(yylineno, currentFileName, yytext, defining); }

{L}({L}|{D})*		{ addSymbolRef(yylineno, currentFileName, yytext, defining);  }

0[xX]{H}+{IS}?		{ addSymbolRef(yylineno, currentFileName, yytext, defining); }
0{D}+{IS}?		{ addSymbolRef(yylineno, currentFileName, yytext, defining);  }
{D}+{IS}?		{ addSymbolRef(yylineno, currentFileName, yytext, defining); }
L?'(\\.|[^\\'])+'	{ addSymbolRef(yylineno, currentFileName, yytext, defining); }

{D}+{E}{FS}?		{ addSymbolRef(yylineno, currentFileName, yytext, defining);}
{D}*"."{D}+({E})?{FS}?	{ addSymbolRef(yylineno, currentFileName, yytext, defining); }
{D}+"."{D}*({E})?{FS}?	{ addSymbolRef(yylineno, currentFileName, yytext, defining);  }

L?\"(\\.|[^\\"])*\"	{ addSymbolRef(yylineno, currentFileName, yytext, defining); }

"..."			{ addSymbolRef(yylineno, currentFileName, yytext, defining); }
">>="			{ addSymbolRef(yylineno, currentFileName, yytext, defining); }
"<<="			{ addSymbolRef(yylineno, currentFileName, yytext, defining); }
"+="			{ addSymbolRef(yylineno, currentFileName, yytext, defining);  }
"-="			{ addSymbolRef(yylineno, currentFileName, yytext, defining);  }
"*="			{ addSymbolRef(yylineno, currentFileName, yytext, defining); }
"/="			{ addSymbolRef(yylineno, currentFileName, yytext, defining);  }
"%="			{ addSymbolRef(yylineno, currentFileName, yytext, defining);  }
"&="			{ addSymbolRef(yylineno, currentFileName, yytext, defining);  }
"^="			{ addSymbolRef(yylineno, currentFileName, yytext, defining);  }
"|="			{ addSymbolRef(yylineno, currentFileName, yytext, defining);  }
">>"			{ addSymbolRef(yylineno, currentFileName, yytext, defining);  }
"<<"			{ addSymbolRef(yylineno, currentFileName, yytext, defining);  }
"++"			{ addSymbolRef(yylineno, currentFileName, yytext, defining);  }
"--"			{ addSymbolRef(yylineno, currentFileName, yytext, defining); }
"->"			{ addSymbolRef(yylineno, currentFileName, yytext, defining); }
"&&"			{ addSymbolRef(yylineno, currentFileName, yytext, defining); }
"||"			{ addSymbolRef(yylineno, currentFileName, yytext, defining); }
"<="			{ addSymbolRef(yylineno, currentFileName, yytext, defining); }
">="			{ addSymbolRef(yylineno, currentFileName, yytext, defining); }
"=="			{ addSymbolRef(yylineno, currentFileName, yytext, defining); }
"!="			{ addSymbolRef(yylineno, currentFileName, yytext, defining);  }
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
