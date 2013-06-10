INCPACK = inc/
PARSERPACK = par/
LEXERPACK = lex/
SRCPACK = src/
OBJPACK = obj/
BINPACK = bin/
OTHERSPACK = others/

compile: 
	bison -d $(PARSERPACK)parser.y 
	mv parser.tab.c src/
	mv parser.tab.h inc/  
	flex -o $(SRCPACK)lexer.lex.c  $(LEXERPACK)lexer.l
	gcc -o $(BINPACK)sabio $(SRCPACK)parser.tab.c $(SRCPACK)lexer.lex.c $(SRCPACK)sabio_funcs.c

clean:
	rm $(SRCPACK)lexer.lex.c $(SRCPACK)parser.tab.c $(INCPACK)parser.tab.h $(BINPACK)sabio

