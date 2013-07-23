#		Makefile - Compile a set of code in C
#
#This Makefile compiles C codes based on file organization described below:
#	- inc: Folder with all headers.
#	- src: Folder with implementations of headers.
#	- bin: The binary file will be put on this folder.
#	- obj: Objects file of project. 
#Basically this Makefile first generate all the object files and next generate
#the binary file. This Makefile has a target for compile unitary tests.

# Initialize the variables used

#Folders
PACKBIN		= bin
PACKINC		= inc
PACKSRC		= src
PACKBUILD	= build
OTHERSPACK	= others
PACKLEX		= lex
PACKPAR		= par
PACKOBJ		= obj
PACKTESTS	= test
#Flags
CC		= gcc
BISON		= bison
LEXER		= flex
LEXFLAGS	= -lfl
CFLAGS		= -Wall -I./$(PACKINC)
CUNIT		= -lcunit
#Create one list with all sources
LEXSOURCES	= $(wildcard lex/*l)
BISONSOURCES	= $(wildcard par/*y)
CSOURCES	= $(wildcard src/*c)

# TARGETS
all: sabio

# Main target, whose the goal is generate binary files. 
# Dependencies are inserted by: $(CSOURCES:src/%.c=obj/%.o)
#	*Basically capture all the elements of list and change the pieces
#	 with "src/%.c" by "obj/%.o".
obj/%.o: src/%.c
	$(CC) -c $< -o $@ $(CFLAGS) -I./build -lm

sabio: lexerCode bisonCode $(CSOURCES:src/%.c=obj/%.o) confBuild
	@echo "________________________________________________"
	@echo "### Build binary ###"

	$(CC) $(PACKBUILD)/lexer.lex.c build/cparser.tab.c $(PACKBUILD)/*.o -o bin/$@ $(LEXFLAGS) $(CFLAGS) -I./$(PACKBUILD) -I./build -lm
	@echo "________________________________________________"

# Generate lexer Code
lexerCode: $(LEXSOURCES)
	@echo "_______________________________________________"
	@echo "### Generate C code with flex ###"

	$(LEXER) --outfile=$(PACKBUILD)/lexer.lex.c $^
	@echo "_______________________________________________"

# Generate bison Code
bisonCode: $(BISONSOURCES)
	@echo "_______________________________________________"
	@echo "### Generate C code with bison ###"

	$(BISON) -d $^
	mv cparser.tab.c build/cparser.tab.c
	mv cparser.tab.h build/cparser.tab.h
	@echo "_______________________________________________"

confBuild:
	@echo "________________________________________________"
	@echo "### Prepare folder \"build\" for compilation ###"

	cp $(PACKLEX)/* $(PACKBUILD)
	cp $(PACKOBJ)/* $(PACKBUILD)

build/%.o: src/%.c
	$(CC) -c $< -o $@ $(CFLAGS) $(LEXFLAGS)

# 
# Unitary test
#
runTest: runTestsSuites
	@echo "_______________________________________________"
	@echo "### Running Unit Tests ###"
	$(PACKBIN)/runTestsSuites
	@echo "_______________________________________________"

# Compile tests
runTestsSuites: test/runTestsSuites.c
	@echo "_______________________________________________"
	@echo "### Generate object file ###"
	$(CC) -c $< -o obj/runTestsSuites.o -I./$(PACKINC) $(CUNIT)
	@echo "### Compiling Unit Tests ###"
	$(CC) $(PACKBUILD)/handleFile.o $(PACKBUILD)/symbolTable.o $(PACKBUILD)/lexer.lex.c $^ -o bin/$@ -I./$(PACKBUILD) $(CUNIT) -I./$(PACKINC)


# Clean all
clean:
	@echo "________________________________________________"
	rm -f build/*
	rm -f bin/*
	rm -f obj/*
	touch build/tmp.txt
	cp others/simple2.c bin/
	@echo "________________________________________________"

