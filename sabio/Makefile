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
sabio: confBuild lexer
	@echo "________________________________________________"
	@echo "Generate object file."
	$(CC) -c $(PACKBUILD)/symbolTable.c -o $(PACKBUILD)/symbolTable.o $(LEXFLAGS)
	$(CC) -c $(PACKBUILD)/handleFile.c -o $(PACKBUILD)/handleFile.o $(LEXFLAGS)
	$(CC) -c $(PACKBUILD)/lexer.lex.c -o $(PACKBUILD)/lexer.lex.o $(LEXFLAGS)
	$(CC) -Wall $(PACKBUILD)/handleFile.o $(PACKBUILD)/symbolTable.o $(PACKBUILD)/lexer.lex.o -o bin/$@ -I./$(PACKBUILD) $(LEXFLAGS)
	@echo "________________________________________________"

confBuild:
	@echo "Prepare folder \"build\" for compilation."
	@echo "________________________________________________"
	cp $(PACKINC)/* $(PACKBUILD)
	cp $(PACKLEX)/* $(PACKBUILD)
	cp $(PACKSRC)/* $(PACKBUILD)

lexer: $(LEXSOURCES)
	@echo "________________________________________________"
	@echo "Generate C code with flex"
	$(LEXER) -o $(PACKBUILD)/lexer.lex.c $^
	mv lexer.h build/lexer.h

build/%.o: src/%.c
	$(CC) -c $< -o $@ $(CFLAGS) $(LEXFLAGS)

# Clean all
clean:
	@echo "________________________________________________"
	rm -f build/*
	rm -f bin/*
	touch build/tmp.txt
	@echo "________________________________________________"

