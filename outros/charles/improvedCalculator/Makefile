compile: calculator.l calculator.y calculator.h calculatorImpl.c main.c
	bison -d calculator.y
	flex -ocalculator.lex.c calculator.l
	gcc -o calculator calculatorImpl.c calculator.lex.c calculator.tab.c main.c -lm

clean:	
	rm calculator.tab.c calculator.tab.h calculator.lex.c calculator