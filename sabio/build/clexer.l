%option noyywrap nodefault yylineno
%option header-file="clexer.h"

%x COMMENT
%x IFILE

UCN (\\u[0-9a-fA-F]{4}|\\U[0-9a-fA-F]{8})
EXP ([Ee][-+]?[0-9]+)
ILEN ([Uu](L|l|LL|ll)?|(L|l|LL|ll)[Uu]?)

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

 /*Set Keywords. Note that we divide keywords that introduce definition
  * from the others. */
_Bool 		|
_Complex 	|
_Imaginary 	|
auto 		|
char 		|
const 		|
double 		|
enum 		|
extern 		|
float 		|
inline 		|
int 		|
long 		|
register 	|
restrict 	|
short 		|
signed 		|
static 		|
struct 		|
typedef 	|
union 		|
unsigned 	|
void 		|
volatile { defining = 1;}

 /*Keywords*/
break
case
continue
default
do
else
for
goto
if
return
sizeof
switch
while

 /*Constantes, note the use of subpatterns.*/
0[0-7]*{ILEN}?
[1-9][0-9]*{ILEN}?
0[Xx][0-9a-fA-F]+{ILEN}?

 /*Decimal float*/
([0-9]*\.[0-9]+|[0-9]+\.){EXP}?[flFL]?
[0-9]+{EXP}[flFL]?

 /*Hex float*/
0[Xx]([0-9a-fA-F]*\.[0-9a-fA-F]+\.?)[Pp][-+]?[0-9]+[flFL]?

 /* char const */
\'([^'\\]|\\['"?\\abfnrtv]|\\[0-7]{1,3}|\\[Xx][0-9a-fA-F]+|{UCN})+\'

 /* literal string */
L?\"([^\"\\]|\\['"?\\abfnrtv]|\\[0-7]{1,3}|\\[Xx][0-9a-fA-F]+|{UCN})+\"

 /*Pontuadores*/
"{"|"<%"|";"	{defining = 0;}

"["|"]"|"("|")"|"{"|"}"|"."|"->"
"++"|"--"|"&"|"*"|"+"|"-"|"~"|"!"
"/"|"%"|"<<"|">>"|"<"|">"|"<="|">="|"=="|"!="|"^"|"|"|"&&"|"||"
"?"|":"|";"|"..."
"="|"*="|"/="|"%="|"+="|"-="|"<<="|">>="|"&="|"^=""|="
","|"#"|"##"
"<:"|":>"|"%>"|"%:"|"%:%:"

 /*Identification. In this point are recognize variables.*/
([_a-zA-Z]|{UCN})([_a-zA-Z0-9]|{UCN})* {
		addSymbolRef(yylineno, currentFileName, yytext, defining);
	}
 /*White space*/
[ \t\n]+
 /*Line of continuation*/
\\$

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

	/*Invalid character*/
. {
	printf("%s, %d: Mystery character '%s'\n", currentFileName, yylineno, yytext);
  }
%%
