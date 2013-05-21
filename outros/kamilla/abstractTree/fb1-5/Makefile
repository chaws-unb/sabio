compile:
	bison -d fb1-5.y
	flex fb1-5.l
	gcc -o fb1 fb1-5.tab.c lex.yy.c -lfl
	@echo "Make complete."

clean:
	rm -f fb1-5.tab.c fb1-5.tab.h lex.yy.c fb1
	@echo "$(obj) files are removed."
