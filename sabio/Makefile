INCPACK = inc/
SRCPACK = src/
OBJPACK = obj/
BINPACK = bin/
OTHERSPACK = others/

compile: 
	bison -d $(SRCPACK)parser.y 
	mv parser.tab.c parser.tab.h src/  
	flex -o $(SRCPACK)lexer.lex.c  $(SRCPACK)lexer.l
	gcc -o sabio $(SRCPACK)parser.tab.c $(SRCPACK)lexer.lex.c $(SRCPACK)sabio_funcs.c

clean:
	rm $(SRCPACK)lexer.lex.c $(SRCPACK)parser.tab.c $(SRCPACK)parser.tab.h sabio

