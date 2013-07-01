compile:	lexer.l parser.y
	bison -d parser.y
	flex lexer.l
	gcc lex.yy.c parser.tab.c functions.c ../xml/simpleXML.c -o calc -I../xml

clean:	
	rm calc lex.yy.c parser.tab.h parser.tab.c treeOfLine_1.xml treeOfLine_2.xml treeOfLine_3.xml