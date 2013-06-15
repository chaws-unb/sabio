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
#Flags
CC			= gcc
BISON		= bison
LEXER		= flex
LEXFLAGS	= -lfl
CFLAGS		= -Wall -I./$(PACKINC)
#Create one list with all sources
LEXSOURCES	= $(wildcard lex/*l)
CSOURCES	= $(wildcard src/*c)

# TRAGETS
all: sabio

# Main target, whose the objective is generate binary files. 
# Dependencies are inserted by: $(CSOURCES:src/%.c=obj/%.o)
#	*Basically capture all the elements of list and change the pieces
#	 with "src/%.c" by "obj/%.o".
obj/%.o: src/%.c
	$(CC) -c $< -o $@ $(CFLAGS) -I./build

sabio: lexerCode $(CSOURCES:src/%.c=obj/%.o) confBuild
	@echo "________________________________________________"
	@echo "### Build binary ###"

	$(CC) $(PACKBUILD)/lexer.lex.c $(PACKBUILD)/*.o -o bin/$@ -I./$(PACKBUILD) $(LEXFLAGS) $(CFLAGS)
	@echo "________________________________________________"

# Generate lexer Code
lexerCode: $(LEXSOURCES)
	@echo "_______________________________________________"
	@echo "### Generate C code with flex ###"

	$(LEXER) -o $(PACKBUILD)/lexer.lex.c $^
	mv clexer.h build/clexer.h
	@echo "_______________________________________________"

confBuild:
	@echo "________________________________________________"
	@echo "### Prepare folder \"build\" for compilation ###"

	cp $(PACKLEX)/* $(PACKBUILD)
	cp $(PACKOBJ)/* $(PACKBUILD)

build/%.o: src/%.c
	$(CC) -c $< -o $@ $(CFLAGS) $(LEXFLAGS)

# Clean all
clean:
	@echo "________________________________________________"
	rm -f build/*
	rm -f bin/*
	rm -f obj/*
	touch build/tmp.txt
	cp others/simple2.c bin/
	@echo "________________________________________________"

