compile:	cGrammar.l cGrammar.y
	bison -d cGrammar.y
	flex cGrammar.l
	cc -o out cGrammar.tab.c lex.yy.c 

clean:	
	rm cGrammar.tab.c cGrammar.tab.h out lex.yy.c