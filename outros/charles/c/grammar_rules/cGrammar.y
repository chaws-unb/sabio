%{
#include <stdio.h>
#include "../ast/ast.h"
#include "../rules_functions/cGrammar.h"
%}

/* Declare data types to be used */
%union {
	double number;
	char * string;
	struct _ast * tree;
}

/* My declarations */
%token <string> IDENTIFIER STRING_LITERAL
%token <number> CONSTANT

%type <tree> direct_declarator declarator init_declarator_list init_declarator iteration_statement
%type <tree> additive_expression multiplicative_expression cast_expression expression statement
%type <tree> equality_expression relational_expression primary_expression declaration declaration_specifiers
%type <tree> type_specifier compound_statement expression_statement selection_statement
%type <tree> postfix_expression unary_expression shift_expression initializer initializer_list
%type <tree> and_expression exclusive_or_expression inclusive_or_expression logical_and_expression
%type <tree> logical_or_expression conditional_expression assignment_expression statement_list argument_expression_list
%type <tree> jump_statement labeled_statement declaration_list

%token SIZEOF
%token PTR_OP INC_OP DEC_OP LEFT_OP RIGHT_OP LE_OP GE_OP EQ_OP NE_OP
%token AND_OP OR_OP MUL_ASSIGN DIV_ASSIGN MOD_ASSIGN ADD_ASSIGN
%token SUB_ASSIGN LEFT_ASSIGN RIGHT_ASSIGN AND_ASSIGN
%token XOR_ASSIGN OR_ASSIGN TYPE_NAME

%token TYPEDEF EXTERN STATIC AUTO REGISTER
%token CHAR SHORT INT LONG SIGNED UNSIGNED FLOAT DOUBLE CONST VOLATILE VOID
%token STRUCT UNION ENUM ELLIPSIS

%token CASE DEFAULT IF ELSE SWITCH WHILE DO FOR GOTO CONTINUE BREAK RETURN

%start translation_unit
%%

primary_expression
	: IDENTIFIER 		 {$$ = primary_expression__IDENTIFIER($1);}
	| CONSTANT   		 {$$ = primary_expression__CONSTANT($1);}
	| STRING_LITERAL 	 {$$ = primary_expression__STRING_LITERAL($1);}
	| '(' expression ')' {$$ = primary_expression__OPP__expression__CLP($2);}
	;

postfix_expression
	: primary_expression 								  {$$ = postfix_expression__primary_expression($1);}
	| postfix_expression '[' expression ']' 			  {printf(": postfix_expression->[expression]\n");}
	| postfix_expression '(' ')' 	 					  {printf(": postfix_expression->()\n");}
	| postfix_expression '(' argument_expression_list ')' {printf(": postfix_expression->(argument_expression_list)\n");}
	| postfix_expression '.' IDENTIFIER 				  {printf(": postfix_expression->IDENTIFIER\n");}
	| postfix_expression PTR_OP IDENTIFIER 				  {printf(": postfix_expression->'->'IDENTIFIER\n");}
	| postfix_expression INC_OP 						  {printf(": postfix_expression->++\n");}
	| postfix_expression DEC_OP 						  {printf(": postfix_expression->--\n");}
	;

argument_expression_list
	: assignment_expression 							 {$$ = argument_expression_list__assignment_expression($1);}
	| argument_expression_list ',' assignment_expression {$$ = argument_expression_list__argument_expression_list__COMMA__assignment_expression($1, $3);}
	;

unary_expression
	: postfix_expression 			 {$$ = unary_expression__postfix_expression($1);}
	| INC_OP unary_expression 		 {printf(": unary_expression->++ unary_expression \n");}
	| DEC_OP unary_expression 		 {printf(": unary_expression->-- unary_expression \n");}
	| unary_operator cast_expression {printf(": unary_expression->unary_operator cast_expression \n");}
	| SIZEOF unary_expression 		 {printf(": unary_expression->sizeof unary_operator\n");}
	| SIZEOF '(' type_name ')' 		 {printf(": unary_expression->sizeof (type_name)\n");}
	;

unary_operator
	: '&' {printf(": unary_operator->&\n");}
	| '*' {printf(": unary_operator->*\n");}
	| '+' {printf(": unary_operator->+\n");}
	| '-' {printf(": unary_operator->-\n");}
	| '~' {printf(": unary_operator->~\n");}
	| '!' {printf(": unary_operator->!\n");}
	;

cast_expression
	: unary_expression 					{$$ = cast_expression__unary_expression($1);}
	| '(' type_name ')' cast_expression {printf(": cast_expression->(type_name)\n");}
	;

multiplicative_expression
	: cast_expression 								{$$ = multiplicative_expression__cast_expression($1);}
	| multiplicative_expression '*' cast_expression {$$ = multiplicative_expression__multiplicative_expression__STAR__cast_expression($1, $3);}
	| multiplicative_expression '/' cast_expression {$$ = multiplicative_expression__multiplicative_expression__SLASH__cast_expression($1, $3);}
	| multiplicative_expression '%' cast_expression {$$ = multiplicative_expression__multiplicative_expression__PERC__cast_expression($1, $3);}
	;

additive_expression
	: multiplicative_expression 						{$$ = additive_expression__multiplicative_expression($1);}
	| additive_expression '+' multiplicative_expression {$$ = additive_expression__additive_expression__PLUS__multiplicative_expression($1, $3);}
	| additive_expression '-' multiplicative_expression {$$ = additive_expression__additive_expression__MINUS__multiplicative_expression($1, $3);}
	;

shift_expression
	: additive_expression 							{$$ = shift_expression__additive_expression($1);}
	| shift_expression LEFT_OP additive_expression  {printf(": shift_expression->shift_expression << additive_expression\n");}
	| shift_expression RIGHT_OP additive_expression {printf(": shift_expression->shift_expression >> additive_expression\n");}
	;

relational_expression
	: shift_expression 							   {$$ = relational_expression__shift_expression($1);}
	| relational_expression '<' shift_expression   {$$ = relational_expression__relational_expression__LT__shift_expression($1, $3);}
	| relational_expression '>' shift_expression   {$$ = relational_expression__relational_expression__GT__shift_expression($1, $3);}
	| relational_expression LE_OP shift_expression {$$ = relational_expression__relational_expression__LE_OP__shift_expression($1, $3);}
	| relational_expression GE_OP shift_expression {$$ = relational_expression__relational_expression__GE_OP__shift_expression($1, $3);}
	;

equality_expression
	: relational_expression 						  {$$ = equality_expression__relational_expression($1);}
	| equality_expression EQ_OP relational_expression {$$ = equality_expression__equality_expression__EQ_OP__relational_expression($1, $3);}
	| equality_expression NE_OP relational_expression {$$ = equality_expression__equality_expression__NE_OP__relational_expression($1, $3);}
	;

and_expression
	: equality_expression 					 {$$ = and_expression__equality_expression($1);}
	| and_expression '&' equality_expression {printf(": and_expression->and_expression '&' equality_expression\n");}
	;

exclusive_or_expression
	: and_expression 							 {$$ = exclusive_or_expression__and_expression($1);}
	| exclusive_or_expression '^' and_expression {printf(": exclusive_or_expression->exclusive_or_expression ^ and_expression\n");}
	;

inclusive_or_expression
	: exclusive_or_expression 							  {$$ = inclusive_or_expression__exclusive_or_expression($1);}
	| inclusive_or_expression '|' exclusive_or_expression {printf(": inclusive_or_expression->inclusive_or_expression | exclusive_or_expression\n");}
	;

logical_and_expression
	: inclusive_or_expression 								{$$ = logical_and_expression__inclusive_or_expression($1);}
	| logical_and_expression AND_OP inclusive_or_expression {$$ = logical_and_expression__logical_and_expression__AND_OP__inclusive_or_expression($1, $3);}
	;

logical_or_expression
	: logical_and_expression 							 {$$ = logical_or_expression__logical_and_expression($1);}
	| logical_or_expression OR_OP logical_and_expression {$$ = logical_or_expression__logical_or_expression__OR_OP__logical_and_expression($1, $3);}
	;

conditional_expression
	: logical_or_expression 										  {$$ = conditional_expression__logical_or_expression($1);}
	| logical_or_expression '?' expression ':' conditional_expression {printf(": conditional_expression->logical_or_expression ? expression : conditional_expression\n");}
	;

assignment_expression
	: conditional_expression 									 {$$ = assignment_expression__conditional_expression($1);}
	| unary_expression assignment_operator assignment_expression {printf(": assignment_expression->unary_expression assignment_operator assignment_expression\n");}
	;

assignment_operator
	: '=' 	       {printf(": assignment_operator->=\n");}
	| MUL_ASSIGN   {printf(": assignment_operator->*=\n");}
	| DIV_ASSIGN   {printf(": assignment_operator->/=\n");}
	| MOD_ASSIGN   {printf(": assignment_operator->%%=\n");}
	| ADD_ASSIGN   {printf(": assignment_operator->+=\n");}
	| SUB_ASSIGN   {printf(": assignment_operator->-=\n");}
	| LEFT_ASSIGN  {printf(": assignment_operator-><<=\n");}
	| RIGHT_ASSIGN {printf(": assignment_operator->>>=\n");}
	| AND_ASSIGN   {printf(": assignment_operator->&=\n");}
	| XOR_ASSIGN   {printf(": assignment_operator->^=\n");}
	| OR_ASSIGN    {printf(": assignment_operator->|=\n");}
	;

expression
	: assignment_expression 			   {$$ = expression__assignment_expression($1);}
	| expression ',' assignment_expression {printf(": expression->expression , assignment_expression\n");}
	;

constant_expression
	: conditional_expression {printf(": constant_expression->conditional_expression\n");}
	;

declaration
	: declaration_specifiers ';' 					  {$$ = declaration__declaration_specifiers__SEMICOLON($1);}
	| declaration_specifiers init_declarator_list ';' {$$ = declaration__declaration_specifiers__init_declarator_list__SEMICOLON($2);}
	;

declaration_specifiers
	: storage_class_specifier 						 {printf(": declaration_specifiers->storage_class_specifier\n");}
	| storage_class_specifier declaration_specifiers {printf(": declaration_specifiers->storage_class_specifier declaration_specifiers\n");}
	| type_specifier								 {$$ = declaration_specifiers__type_specifier();}
	| type_specifier declaration_specifiers	 		 {$$ = declaration_specifiers__type_specifier__declaration_specifiers();}
	| type_qualifier 								 {printf(": declaration_specifiers->type_qualifier\n");}
	| type_qualifier declaration_specifiers 		 {printf(": declaration_specifiers->type_qualifier declaration_specifiers\n");}
	;

init_declarator_list
	: init_declarator 						   {$$ = init_declarator_list__init_declarator($1);}
	| init_declarator_list ',' init_declarator {$$ = init_declarator_list__init_declarator_list__COMMA__init_declarator($1, $3);}
	;

init_declarator
	: declarator 				 {$$ = init_declarator__declarator($1);}
	| declarator '=' initializer {$$ = init_declarator__declarator__EQ__initializer($1, $3);}
	;

storage_class_specifier
	: TYPEDEF  {printf(": storage_class_specifier->TYPEDEF\n");}
	| EXTERN   {printf(": storage_class_specifier->EXTERN\n");}
	| STATIC   {printf(": storage_class_specifier->STATIC\n");}
	| AUTO 	   {printf(": storage_class_specifier->AUTO\n");}
	| REGISTER {printf(": storage_class_specifier->REGISTER\n");}
	;

type_specifier
	: VOID 						{$$ = type_specifier__VOID();}
	| CHAR 						{$$ = type_specifier__CHAR();}
	| SHORT 					{$$ = type_specifier__SHORT();}
	| INT 						{$$ = type_specifier__INT();}
	| LONG 						{$$ = type_specifier__LONG();}
	| FLOAT 					{$$ = type_specifier__FLOAT();}
	| DOUBLE 					{$$ = type_specifier__DOUBLE();}
	| SIGNED 					{$$ = type_specifier__SIGNED();}
	| UNSIGNED 					{$$ = type_specifier__UNSIGNED();}
	| struct_or_union_specifier {$$ = type_specifier__struct_or_union_specifier();}
	| enum_specifier 			{$$ = type_specifier__enum_specifier();}
	| TYPE_NAME 				{$$ = type_specifier__TYPE_NAME();}
	;

struct_or_union_specifier
	: struct_or_union IDENTIFIER '{' struct_declaration_list '}' {printf(": struct_or_union_specifier->struct_or_union IDENTIFIER { struct_declaration_list }\n");}
	| struct_or_union '{' struct_declaration_list '}' 			 {printf(": struct_or_union_specifier->struct_or_union { struct_declaration_list }\n");}
	| struct_or_union IDENTIFIER 								 {printf(": struct_or_union_specifier->struct_or_union IDENTIFIER\n");}
	;

struct_or_union
	: STRUCT {printf(": struct_or_union->STRUCT\n");}
	| UNION  {printf(": struct_or_union->UNION\n");}
	;

struct_declaration_list
	: struct_declaration 						 {printf(": struct_declaration_list->struct_declaration\n");}
	| struct_declaration_list struct_declaration {printf(": struct_declaration_list->struct_declaration_list struct_declaration\n");}
	;

struct_declaration
	: specifier_qualifier_list struct_declarator_list ';' {printf(": struct_declaration->specifier_qualifier_list struct_declarator_list ;\n");}
	;

specifier_qualifier_list
	: type_specifier specifier_qualifier_list {printf(": specifier_qualifier_list->type_specifier specifier_qualifier_list\n");}
	| type_specifier 						  {printf(": specifier_qualifier_list->type_specifier\n");}
	| type_qualifier specifier_qualifier_list {printf(": specifier_qualifier_list->type_qualifier specifier_qualifier_list\n");}
	| type_qualifier 						  {printf(": specifier_qualifier_list->type_qualifier\n");}
	;

struct_declarator_list
	: struct_declarator 						   {printf(": struct_declarator_list->struct_declarator\n");}
	| struct_declarator_list ',' struct_declarator {printf(": struct_declarator_list->struct_declarator_list , struct_declarator\n");}
	;

struct_declarator
	: declarator 						 {printf(": struct_declarator->declarator\n");}
	| ':' constant_expression 			 {printf(": struct_declarator->: constant_expression\n");}
	| declarator ':' constant_expression {printf(": struct_declarator->declarator : constant_expression\n");}
	;

enum_specifier
	: ENUM '{' enumerator_list '}' 			  {printf(": enum_specifier->ENUM { enumerator_list }\n");}
	| ENUM IDENTIFIER '{' enumerator_list '}' {printf(": enum_specifier->ENUM IDENTIFIER { enumerator_list }\n");}
	| ENUM IDENTIFIER 						  {printf(": enum_specifier->ENUM IDENTIFIER\n");}
	;

enumerator_list
	: enumerator 					 {printf(": enumerator_list->enumerator\n");}
	| enumerator_list ',' enumerator {printf(": enumerator_list->enumerator_list , enumerator\n");}
	;

enumerator
	: IDENTIFIER 						 {printf(": enumerator->IDENTIFIER\n");}
	| IDENTIFIER '=' constant_expression {printf(": enumerator->IDENTIFIER = constant_expression\n");}
	;

type_qualifier
	: CONST    {printf(": type_qualifier->CONST\n");}
	| VOLATILE {printf(": type_qualifier->VOLATILE\n");}
	;

declarator
	: pointer direct_declarator {printf(": declarator->pointer direct_declarator\n");}
	| direct_declarator 		{$$ = declarator__direct_declarator($1);}
	;

direct_declarator
	: IDENTIFIER 									{$$ = direct_declarator__IDENTIFIER($1);}
	| '(' declarator ')' 							{$$ = direct_declarator__OPP__declarator__CLP($2);}
	| direct_declarator '[' constant_expression ']' {printf(": direct_declarator->direct_declarator [ constant_expression ]\n");}
	| direct_declarator '[' ']' 					{printf(": direct_declarator->direct_declarator [ ]\n");}
	| direct_declarator '(' parameter_type_list ')' {printf(": direct_declarator->direct_declarator ( parameter_type_list )\n");}
	| direct_declarator '(' identifier_list ')' 	{printf(": direct_declarator->direct_declarator ( identifier_list )\n");}
	| direct_declarator '(' ')' 					{$$ = direct_declarator__direct_declarator__OPP__CLP($1);}
	;

pointer
	: '*' 							  {printf(": pointer->*\n");}
	| '*' type_qualifier_list 		  {printf(": pointer->* type_qualifier_list\n");}
	| '*' pointer 					  {printf(": pointer->* pointer\n");}
	| '*' type_qualifier_list pointer {printf(": pointer->* type_qualifier_list pointer\n");}
	;

type_qualifier_list
	: type_qualifier 					 {printf(": type_qualifier_list->type_qualifier\n");}
	| type_qualifier_list type_qualifier {printf(": type_qualifier_list->type_qualifier_list type_qualifier\n");}
	;


parameter_type_list
	: parameter_list 			  {printf(": parameter_type_list->parameter_list\n");}
	| parameter_list ',' ELLIPSIS {printf(": parameter_type_list->parameter_list , ...\n");}
	;

parameter_list
	: parameter_declaration 				   {printf(": parameter_list->parameter_declaration\n");}
	| parameter_list ',' parameter_declaration {printf(": parameter_list->parameter_list , parameter_declaration\n");}
	;

parameter_declaration
	: declaration_specifiers declarator 		 {printf(": parameter_declaration->declaration_specifiers declarator\n");}
	| declaration_specifiers abstract_declarator {printf(": parameter_declaration->declaration_specifiers abstract_declarator\n");}
	| declaration_specifiers 					 {printf(": parameter_declaration->declaration_specifiers\n");}
	;

identifier_list
	: IDENTIFIER  					 {printf(": identifier_list->IDENTIFIER\n");}
	| identifier_list ',' IDENTIFIER {printf(": identifier_list->identifier_list , IDENTIFIER\n");}
	;

type_name
	: specifier_qualifier_list 					   {printf(": type_name->specifier_qualifier_list\n");}
	| specifier_qualifier_list abstract_declarator {printf(": type_name->specifier_qualifier_list abstract_declarator\n");}
	;

abstract_declarator
	: pointer 							 {printf(": abstract_declarator->pointer\n");}
	| direct_abstract_declarator 		 {printf(": abstract_declarator->direct_abstract_declarator\n");}
	| pointer direct_abstract_declarator {printf(": abstract_declarator->pointer direct_abstract_declarator\n");}
	;

direct_abstract_declarator
	: '(' abstract_declarator ')' 							 {printf(": direct_abstract_declarator->( abstract_declarator )\n");}
	| '[' ']' 												 {printf(": direct_abstract_declarator->[ ]\n");}
	| '[' constant_expression ']' 							 {printf(": direct_abstract_declarator->[ constant_expression ]\n");}
	| direct_abstract_declarator '[' ']' 					 {printf(": direct_abstract_declarator->direct_abstract_declarator [ ]\n");}
	| direct_abstract_declarator '[' constant_expression ']' {printf(": direct_abstract_declarator->direct_abstract_declarator [ constant_expression ]\n");}
	| '(' ')' 												 {printf(": direct_abstract_declarator->( )\n");}
	| '(' parameter_type_list ')' 							 {printf(": direct_abstract_declarator->( parameter_type_list )\n");}
	| direct_abstract_declarator '(' ')' 					 {printf(": direct_abstract_declarator->direct_abstract_declarator ( )\n");}
	| direct_abstract_declarator '(' parameter_type_list ')' {printf(": direct_abstract_declarator->direct_abstract_declarator ( parameter_type_list )\n");}
	;

initializer
	: assignment_expression 	   {$$ = initializer__assignment_expression($1);}
	| '{' initializer_list '}'	   {$$ = initializer__OPB__initializer_list__CLB($2);}
	| '{' initializer_list ',' '}' {$$ = initializer__OPB__initializer_list__COMMA__CLB($2);}
	;

initializer_list
	: initializer 					   {$$ = initializer_list__initializer($1);}
	| initializer_list ',' initializer {$$ = initializer_list__initializer_list__COMMA__initializer($1, $3);}
	;

statement
	: labeled_statement    {$$ = statement__labeled_statement($1);}
	| compound_statement   {$$ = statement__compound_statement($1);}
	| expression_statement {$$ = statement__expression_statement($1);}
	| selection_statement  {$$ = statement__selection_statement($1);}
	| iteration_statement  {$$ = statement__iteration_statement($1);}
	| jump_statement       {$$ = statement__jump_statement($1);}
	;

labeled_statement
	: IDENTIFIER ':' statement 				 {printf(": labeled_statement->IDENTIFIER : statement\n");}
	| CASE constant_expression ':' statement {printf(": labeled_statement->CASE constant_expression : statement\n");}
	| DEFAULT ':' statement 				 {printf(": labeled_statement->DEFAULT : statement\n");}
	;

compound_statement
	: '{' '}' 								  {$$ = compound_statement__OPB__CLB();}
	| '{' statement_list '}' 				  {$$ = compound_statement__OPB__statement_list__CLB($2);}
	| '{' declaration_list '}' 				  {$$ = compound_statement__OPB__declaration_list__CLB($2);}
	| '{' declaration_list statement_list '}' {$$ = compound_statement__OPB__declaration_list__statement_list__CLB($2, $3);}
	;

declaration_list
	: declaration 				   {$$ = declaration_list__declaration($1);}
	| declaration_list declaration {$$ = declaration_list__declaration_list__declaration($1, $2);}
	;

statement_list
	: statement 			   {$$ = statement_list__statement($1);}
	| statement_list statement {$$ = statement_list__statement_list__statement($1, $2);}
	;

expression_statement
	: ';' 			 {$$ = expression_statement__SEMICOLON();}
	| expression ';' {$$ = expression_statement__expression__SEMICOLON($1);}
	;

selection_statement
	: IF '(' expression ')' statement {$$ = selection_statement__IF__OPP__expression__CLP__statement($3, $5);}
	| IF '(' expression ')' statement ELSE statement { $$ =  selection_statement__IF__OPP__expression__CLP__statement__ELSE__statement($3, $5, $7);}
	| SWITCH '(' expression ')' statement 			 { $$ =  selection_statement__SWITCH__OPP__expression__CLP__statement();}
	;

iteration_statement
	: WHILE '(' expression ')' statement	{$$ = iteration_statement__WHILE__OPP__expression__CLP__statement($3, $5); }
	| DO statement WHILE '(' expression ')' ';' 	{printf(": iteration_statement->DO statement WHILE ( expression ) ;\n");}
	| FOR '(' expression_statement expression_statement ')' statement 			 {printf(": iteration_statement->FOR ( expression_statement expression_statement ) statement\n");}
	| FOR '(' expression_statement expression_statement expression ')' statement {printf(": iteration_statement->FOR ( expression_statement expression_statement expression ) statement\n");}
	;

jump_statement
	: GOTO IDENTIFIER ';' 	{printf(": jump_statement->GOTO IDENTIFIER ;\n");}
	| CONTINUE ';' 			{printf(": jump_statement->CONTINUE ;\n");}
	| BREAK ';' 			{printf(": jump_statement->BREAK ;\n");}
	| RETURN ';' 			{printf(": jump_statement->RETURN ;\n");}
	| RETURN expression ';' {printf(": jump_statement->RETURN expression ;\n");}
	;

translation_unit
	: external_declaration 					{printf(": translation_unit->external_declaration\n");}
	| translation_unit external_declaration {printf(": translation_unit->translation_unit external_declaration\n");}
	;

external_declaration
	: function_definition {printf(": external_declaration->function_definition\n");}
	| declaration 		  {external_declaration__declaration($1);}
	;

function_definition
	: declaration_specifiers declarator declaration_list compound_statement {printf(": function_definition->declaration_specifiers declarator declaration_list compound_statement\n");}
	| declaration_specifiers declarator compound_statement 					{function_definition__declaration_specifiers__declarator__compound_statement($1, $2, $3);}
	| declarator declaration_list compound_statement 						{printf(": function_definition->declarator declaration_list compound_statement\n");}
	| declarator compound_statement 										{printf(": function_definition->declarator compound_statement\n");}
	;

%%
