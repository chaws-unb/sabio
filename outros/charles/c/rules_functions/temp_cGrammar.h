
/*
*	Some abreviations
*	OPP = OPEN PARENTHESIS '('
*	CLP = CLOSE PARENTHESIS ')'
*	OPC = OPEN COLCHES '['
*	CLC = CLOSE COLCHES ']'
*	OPB = OPEN BRACKETS '{'
*	CLB = CLOSE BRACKETS '}'
*	NAR = The narrow sign '->'
*	PLUS = '+'
*	MINUS = '-'
*	COMMA = COMMA ','
*	COLON = ':'
*	SEMICOLON = ';'
*	IMARK = '!'
*	QMARK = '?'
*	STAR = '*'
*	TILDE = '~'
*	HAT = '^'
*	AMPER = '&'
*	PERC = '%
*	SLASH = '/'
*	EQ = '='
*	
*	and so on...
*/

___// Primary_expression
void primary_expression__IDENTIFIER();
void primary_expression__CONSTANT();
void primary_expression__STRING_LITERAL();
void primary_expression__OPP__expression__CLP();

___// Postfix_expression
void postfix_expression__primary_expression();
void postfix_expression__OPC__expression__CLC();
void postfix_expression__OPP__CLP();
void postfix_expression__OPP__argument_expression_list__CLP();
void postfix_expression__IDENTIFIER();
void postfix_expression__NAR__IDENTIFIER();
void postfix_expression__PP();
void postfix_expression__MM();

___// argument_expression_list
void argument_expression_list__assignment_expression();
void argument_expression_list__argument_expression_list__COMMA__assignment_expression();

___// unary_expression
void unary_expression__postfix_expression();
void unary_expression__INC_OP__unary_expression();
void unary_expression__DEC_OP__unary_expression();
void unary_expression__unary_operator__cast_expression();
void unary_expression__sizeof__unary_operator();
void unary_expression__sizeof__OPP__type_name__CLP();

___// unary_operator
void unary_operator__AMPER();
void unary_operator__STAR();
void unary_operator__PLUS();
void unary_operator__MINUS();
void unary_operator__TILDE();
void unary_operator__IMARK();

___// cast_expression
void cast_expression__unary_expression();
void cast_expression__OPP__type_name__CLP();

___// multiplicative_expression
void multiplicative_expression__cast_expression();
void multiplicative_expression__multiplicative_expression__STAR__cast_expression();
void multiplicative_expression__multiplicative_expression__SLASH__cast_expression();
void multiplicative_expression__multiplicative_expression__PERC__cast_expression();

___// additive_expression
void additive_expression__multiplicative_expression();
void additive_expression__additive_expression__PLUS__multiplicative_expression();
void additive_expression__additive_expression__MINUS__multiplicative_expression();

___// shift_expression
void shift_expression__additive_expression();
void shift_expression__shift_expression__LEFT_OP__additive_expression();
void shift_expression__shift_expression__RIGHT_OP__additive_expression();

___// relational_expression
void relational_expression__shift_expression();
void relational_expression__relational_expression__LT__shift_expression();
void relational_expression__relational_expression__GT__shift_expression();
void relational_expression__relational_expression__LE_OP__shift_expression();
void relational_expression__relational_expression__GE_OP__shift_expression();

___// equality_expression
void equality_expression__relational_expression();
void equality_expression__equality_expression__EQ_OP__relational_expression();
void equality_expression__equality_expression__NE_OP__relational_expression();

___// and_expression
void and_expression__equality_expression();
void and_expression__and_expression__AMPER__equality_expression();

___// exclusive_or_expression
void exclusive_or_expression__and_expression();
void exclusive_or_expression__exclusive_or_expression__XOR__and_expression();

___// inclusive_or_expression
void inclusive_or_expression__exclusive_or_expression();
void inclusive_or_expression__inclusive_or_expression__OR__exclusive_or_expression();

___// logical_and_expression
void logical_and_expression__inclusive_or_expression();
void logical_and_expression__logical_and_expression__AND_OP__inclusive_or_expression();

___// logical_or_expression
void logical_or_expression__logical_and_expression();
void logical_or_expression__logical_or_expression__OR_OP__logical_and_expression();

___// conditional_expression
void conditional_expression__logical_or_expression();
void conditional_expression__logical_or_expression__QMARK__expression__COLON__conditional_expression();

___// assignment_expression
void assignment_expression__conditional_expression();
void assignment_expression__unary_expression__assignment_operator__assignment_expression();

___// assignment_operator
void assignment_operator__EQ();
void assignment_operator__MUL_ASSIGN();
void assignment_operator__DIV_ASSIGN();
void assignment_operator__MOD_ASSIGN();
void assignment_operator__ADD_ASSIGN();
void assignment_operator__SUB_ASSIGN();
void assignment_operator__LEFT_ASSIGN();
void assignment_operator__RIGHT_ASSIGN();
void assignment_operator__AND_ASSIGN();
void assignment_operator__XOR_ASSIGN();
void assignment_operator__OR_ASSIGN();

___// expression
void expression__assignment_expression();
void expression__expression__COMMA__assignment_expression();

___// constant_expression
void constant_expression__conditional_expression();

___// declaration
void declaration__declaration_specifiers__SEMICOLON();
void declaration__declaration_specifiers__init_declarator_list__SEMICOLON();

___// declaration_specifiers
void declaration_specifiers__storage_class_specifier();
void declaration_specifiers__storage_class_specifier__declaration_specifiers();
void declaration_specifiers__type_specifier();
void declaration_specifiers__type_specifier__declaration_specifiers();
void declaration_specifiers__type_qualifier();
void declaration_specifiers__type_qualifier__declaration_specifiers();

___// init_declarator_list
void init_declarator_list__init_declarator();
void init_declarator_list__init_declarator_list__COMMA__init_declarator();

___// init_declarator
void init_declarator__declarator();
void init_declarator__declarator__EQ__initializer();

___// storage_class_specifier
void storage_class_specifier__TYPEDEF();
void storage_class_specifier__EXTERN();
void storage_class_specifier__STATIC();
void storage_class_specifier__AUTO();
void storage_class_specifier__REGISTER();

___// type_specifier
void type_specifier__VOID();
void type_specifier__CHAR();
void type_specifier__SHORT();
void type_specifier__INT();
void type_specifier__LONG();
void type_specifier__FLOAT();
void type_specifier__DOUBLE();
void type_specifier__SIGNED();
void type_specifier__UNSIGNED();
void type_specifier__struct_or_union_specifier();
void type_specifier__enum_specifier();
void type_specifier__TYPE_NAME();

___// struct_or_union_specifier
void struct_or_union_specifier__struct_or_union__IDENTIFIER__OPB__struct_declaration_list__CLB();
void struct_or_union_specifier__struct_or_union__OPB__struct_declaration_list__CLB();
void struct_or_union_specifier__struct_or_union__IDENTIFIER();

___// struct_or_union
void struct_or_union__STRUCT();
void struct_or_union__UNION();

___// struct_declaration_list
void struct_declaration_list__struct_declaration();
void struct_declaration_list__struct_declaration_list__struct_declaration();

___// struct_declaration
void struct_declaration__specifier_qualifier_list__struct_declarator_list__SEMICOLON();

___// specifier_qualifier_list
void specifier_qualifier_list__type_specifier__specifier_qualifier_list();
void specifier_qualifier_list__type_specifier();
void specifier_qualifier_list__type_qualifier__specifier_qualifier_list();
void specifier_qualifier_list__type_qualifier();

___// struct_declarator_list
void struct_declarator_list__struct_declarator();
void struct_declarator_list__struct_declarator_list__COMMA__struct_declarator();

___// struct_declarator
void struct_declarator__declarator();
void struct_declarator__COLON__constant_expression();
void struct_declarator__declarator__COLON__constant_expression();

___// enum_specifier
void enum_specifier__ENUM__OPB__enumerator_list__CLB();
void enum_specifier__ENUM__IDENTIFIER__OPB__enumerator_list__CLB();
void enum_specifier__ENUM__IDENTIFIER();

___// enumerator_list
void enumerator_list__enumerator();
void enumerator_list__enumerator_list__COMMA__enumerator();

___// enumerator
void enumerator__IDENTIFIER();
void enumerator__IDENTIFIER__EQ__constant_expression();

___// type_qualifier
void type_qualifier__CONST();
void type_qualifier__VOLATILE();

___// declarator
void declarator__pointer__direct_declarator();
void declarator__direct_declarator();

___// direct_declarator
void direct_declarator__IDENTIFIER();
void direct_declarator__OPP__declarator__CLP();
void direct_declarator__direct_declarator__OPC__constant_expression__CLC();
void direct_declarator__direct_declarator__OPC__CLC();
void direct_declarator__direct_declarator__OPP__parameter_type_list__CLP();
void direct_declarator__direct_declarator__OPP__identifier_list__CLP();
void direct_declarator__direct_declarator__OPP__CLP();

___// pointer
void pointer__STAR();
void pointer__STAR__type_qualifier_list();
void pointer__STAR__pointer();
void pointer__STAR__type_qualifier_list__pointer();

___// type_qualifier_list
void type_qualifier_list__type_qualifier();
void type_qualifier_list__type_qualifier_list__type_qualifier();


___// parameter_type_list
void parameter_type_list__parameter_list();
void parameter_type_list__parameter_list__COMMA__ELLIPSIS();

___// parameter_list
void parameter_list__parameter_declaration();
void parameter_list__parameter_list__COMMA__parameter_declaration();

___// parameter_declaration
void parameter_declaration__declaration_specifiers__declarator();
void parameter_declaration__declaration_specifiers__abstract_declarator();
void parameter_declaration__declaration_specifiers();

___// identifier_list
void identifier_list__IDENTIFIER();
void identifier_list__identifier_list__COMMA__IDENTIFIER();

___// type_name
void type_name__specifier_qualifier_list();
void type_name__specifier_qualifier_list__abstract_declarator();

___// abstract_declarator
void abstract_declarator__pointer();
void abstract_declarator__direct_abstract_declarator();
void abstract_declarator__pointer__direct_abstract_declarator();

___// direct_abstract_declarator
void direct_abstract_declarator__OPP__abstract_declarator__CLP();
void direct_abstract_declarator__OPC__CLC();
void direct_abstract_declarator__OPC__constant_expression__CLC();
void direct_abstract_declarator__direct_abstract_declarator__OPC__CLC();
void direct_abstract_declarator__direct_abstract_declarator__OPC__constant_expression__CLC();
void direct_abstract_declarator__OPP__CLP();
void direct_abstract_declarator__OPP__parameter_type_list__CLP();
void direct_abstract_declarator__direct_abstract_declarator__OPP__CLP();
void direct_abstract_declarator__direct_abstract_declarator__OPP__parameter_type_list__CLP();

___// initializer
void initializer__assignment_expression();
void initializer__OPB__initializer_list__CLB();
void initializer__OPB__initializer_list__COMMA__CLB();

___// initializer_list
void initializer_list__initializer();
void initializer_list__initializer_list__COMMA__initializer();

___// statement
void statement__labeled_statement();
void statement__compound_statement();
void statement__expression_statement();
void statement__selection_statement();
void statement__iteration_statement();
void statement__jump_statement();

___// labeled_statement
void labeled_statement__IDENTIFIER__COLON__statement();
void labeled_statement__CASE__constant_expression__COLON__statement();
void labeled_statement__DEFAULT__COLON__statement();

___// compound_statement
void compound_statement__OPB__CLB();
void compound_statement__OPB__statement_list__CLB();
void compound_statement__OPB__declaration_list__CLB();
void compound_statement__OPB__declaration_list__statement_list__CLB();

___// declaration_list
void declaration_list__declaration();
void declaration_list__declaration_list__declaration();

___// statement_list
void statement_list__statement();
void statement_list__statement_list__statement();

___// expression_statement
void expression_statement__SEMICOLON();
void expression_statement__expression__SEMICOLON();

___// selection_statement
void selection_statement__IF__OPP__expression__CLP__statement();
void selection_statement__IF__OPP__expression__CLP__statement__ELSE__statement();
void selection_statement__SWITCH__OPP__expression__CLP__statement();

___// iteration_statement
void iteration_statement__WHILE__OPP__expression__CLP__statement();
void iteration_statement__DO__statement__WHILE__OPP__expression__CLP__SEMICOLON();
void iteration_statement__FOR__OPP__expression_statement__expression_statement__CLP__statement();
void iteration_statement__FOR__OPP__expression_statement__expression_statement__expression__CLP__statement();

___// jump_statement
void jump_statement__GOTO__IDENTIFIER__SEMICOLON();
void jump_statement__CONTINUE__SEMICOLON();
void jump_statement__BREAK__SEMICOLON();
void jump_statement__RETURN__SEMICOLON();
void jump_statement__RETURN__expression__SEMICOLON();

___// translation_unit
void translation_unit__external_declaration();
void translation_unit__translation_unit__external_declaration();

___// External_declaration
void external_declaration__function_definition();
void external_declaration__declaration();

___// Function_definition
void function_definition__declaration_specifiers__declarator__declaration_list__compound_statement();
void function_definition__declaration_specifiers__declarator__compound_statement();
void function_definition__declarator__declaration_list__compound_statement();
void function_definition__declarator__compound_statement();

___//