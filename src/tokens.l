%{
	#include "Simple.tab.h" /*the tokes*/
%}
DIGIT [0-9]
ID    [a-z][a-z0-9]*

%%

":="		{return(ASSGNOP);	}
{DIGIT}+	{return(NUMBER);	}
do		{return(DO);		}
else		{return(ELSE);		}
if		{return(IF);		}
integer		{return(INTEGER)	}
read		{return(READ);		}
while		{return(WHILE);		}
write		{return(WRITE);		}
{ID}		{return(IDENTIFIER);	}
[\t\n]+		/*blank, tab, new line*/

%%

