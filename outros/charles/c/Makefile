# Flex, Bison stuff
DIR_FLEX_BISON 		= grammar_rules
DIR_RULES_FUNCTIONS = rules_functions
DIR_GENERATED_FILES = generated

# Auxiliary stuff
DIR_AST 			= ast
DIR_HASH 			= hash
DIR_STACK 			= stack
DIR_XML 			= xml

# Build stuff
DIR_INPUT 			= inputs
DIR_BUILD 			= build

# Nifty function hehe, it filters stuff out of our string
FILTER_OUT = $(foreach v,$(2),$(if $(findstring $(1),$(v)),,$(v)))

# Lexer
LEXER 		  = flex
LEXER_FLAGS   = -o $(DIR_GENERATED_FILES)/cGrammar.lex.c
LEXER_FILES   = $(DIR_FLEX_BISON)/cGrammar.l
LEXER_SOURCES = $(wildcard $(DIR_GENERATED_FILES)/*lex.c)

# Bison
BISON 		= bison
BISON_FLAGS = -d
BISON_FILES = $(DIR_FLEX_BISON)/cGrammar.y
BISON_HEADERS = $(wildcard $(DIR_FLEX_BISON)/*h)
BISON_SOURCES = $(wildcard $(DIR_FLEX_BISON)/*c)

# Generated
GENERATED_HEADERS = $(wildcard $(DIR_GENERATED_FILES)/*h)
GENERATED_SOURCES = $(wildcard $(DIR_GENERATED_FILES)/*c)

# AUX = Ast, stack, hash and xml
AUX_HEADERS = $(wildcard $(DIR_AST)/*h) $(wildcard $(DIR_STACK)/*h) $(wildcard $(DIR_HASH)/*h) $(wildcard $(DIR_XML)/*h)
AUX_SOURCES = $(wildcard $(DIR_AST)/*c) $(wildcard $(DIR_STACK)/*c) $(wildcard $(DIR_HASH)/*c) $(wildcard $(DIR_XML)/*c)

# Implementations of Rules functions
RULES_HEADERS = $(wildcard $(DIR_RULES_FUNCTIONS)/cGrammar.h)
RULES_SOURCES = $(wildcard $(DIR_RULES_FUNCTIONS)/impl/*c) $(DIR_RULES_FUNCTIONS)/cGrammar.c

# All headers and Sources
HEADERS = $(AUX_HEADERS) $(GENERATED_HEADERS) $(RULES_HEADERS)
SOURCES = $(AUX_SOURCES) $(GENERATED_SOURCES) $(RULES_SOURCES) main.c

# All files
FILES = $(LEXER_FILES) $(BISON_FILES) $(HEADERS)

# Build file
BUILD = $(DIR_BUILD)/sabioCC

# Targets $(call FILTER_OUT,lex, $(FILES))
compile:	$(FILES) $(SOURCES:%.c=%.o)
	$(BISON) $(BISON_FLAGS) $(BISON_FILES)
	mv cGrammar.tab.h generated/cGrammar.tab.h
	mv cGrammar.tab.c generated/cGrammar.tab.c
	$(LEXER) $(LEXER_FLAGS) $(LEXER_FILES)
	@echo "Compiling objects" 
	@cc $(SOURCES:%.c=%.o) -o $(BUILD)

$(DIR_BUILD)/%.o: $(SOURCES:%.c)
	CC -c $< -o $@

clean:	
	rm $(SOURCES:%.c=%.o)
	rm $(BUILD)
	rm $(GENERATED_HEADERS)
	rm $(GENERATED_SOURCES)