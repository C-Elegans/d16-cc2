%{
#include <stdio.h>
#define YYDEBUG 1
extern int yylex();
extern int yyparse();
extern FILE* yyin;
extern int yyline;
void yyerror(const char* s);
%}
%union{
	char* sval;
	int ival;

}
%token<sval> ID
%token<ival> NUM
%token ELSE IF INT RETURN VOID WHILE
%start program
%%
program:
		declaration_list
;
declaration_list:
		declaration_list declaration
	|	declaration
;
declaration:
	var_declaration | fun_declaration
;
var_declaration:
		type_specifier ID ';'
	|   type_specifier ID '[' NUM ']' ';'
;
type_specifier:
	INT | VOID
;
fun_declaration:
	type_specifier ID '(' params ')' compound_stmt
;
params:
	param_list | VOID
;
param_list:
		param_list ',' param
	|   param
;
param:
		type_specifier ID
	|	type_specifier ID '[' ']'
;
compound_stmt:
	'{' local_declarations statement_list '}'
;
local_declarations:
	local_declarations var_declaration
	| /* empty */
;
statement_list:
	statement_list statement
	| /* empty */
;

statement:
		expression_stmt
	|	compound_stmt
	|	selection_stmt
	|	iteration_stmt
	|	return_stmt
;
expression_stmt:
	expression ';' | ';'
;
selection_stmt:
		IF '(' expression ')'
	|	IF '(' expression ')' statement ELSE statement
;
iteration_stmt:
	WHILE '(' expression ')' statement
;
return_stmt:
		RETURN ';'
	|	RETURN expression ';'
;
expression:
	var '=' expression | simple_expression
;
var:
		ID
	|	ID '[' expression ']'
;
//these should probably become just operators with precedence sometime
//however, for now I am sticking with the C_ standard
simple_expression:
		additive_expression relop additive_expression
	|	additive_expression
;
relop:
		"<="
	|	"<"
	|	">"
	|	">="
	|	"=="
	|	"!="
;
additive_expression:
	additive_expression addop term | term
;
addop:
	'+' | '-'
;
term:
		term mulop factor
	|	factor
;
mulop:
	'*'|'/'
;
factor:
		'(' expression ')'
	|	var
	|	call
	|	NUM
;
call:
	ID '(' args ')'
;
args:
		args_list
	|	/* empty */
;
args_list:
		args_list ',' expression
	|	expression
;

%%
void yyerror(const char* s){
	fprintf(stderr, "Parse error on line %d: %s\n",yyline,s);
	exit(1);
}
