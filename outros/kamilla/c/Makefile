compile:	cGrammar.l cGrammar.y build_ast.h build_ast.h
	bison -d cGrammar.y
	flex -ocGrammar.lex.c cGrammar.l
	cc -o out cGrammar.tab.c cGrammar.lex.c build_ast.c -lm

clean:	
	rm cGrammar.tab.c cGrammar.tab.h out lex.yy.c
