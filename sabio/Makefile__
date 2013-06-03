INCPACK = inc/
SRCPACK = src/
OBJPACK = obj/
BINPACK = bin/
OTHERSPACK = others/

flags#flags
GCC = gcc
CFLAG = -c 
FLEXFLAG = -lfl
BISONFLAG = --verbose --debug -d 

all : project 

project : lexer parser lex.yy.o 
  $(GCC) lex.yy.o parser.c -o $(BINPACK)sabio

#flex bindconfig2.l
lexer : lexer.l 
  flex $^

#bison --verbose --debug -d filename.y -o  filename.cc
parser.c : parser.y
  bison $(BISONFLAG) $^ -o $@ 

#cc -c lex.yy.c -o lex.yy.o

lex.yy.o : lex.yy.c 
  $(GCC) $(CFLAG) $^ -o $@
 






