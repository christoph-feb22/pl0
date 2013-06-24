%{
#include <stdio.h>
#include <cstdlib>
#include "symbol_table.h"

extern "C"
{
	int yyparse(void);
	int yylex(void);  
	int yywrap() { return 1; }
	int yyerror(char * s) { printf(" %s\n", s); exit(1); }
}

SymbolTable symtab;
%}

%token K_CONST K_VAR K_PROCEDURE K_CALL K_BEGIN K_END K_IF K_THEN K_WHILE K_DO K_ODD COMMA SEMICOLON EX_MARK QUE_MARK BEQ SEQ ASSIGN EQ PLUS MINUS MUL DIV LT GT HASH DOT L_BRACE R_BRACE CONST ERROR NUMBER;

%union { char string[255]; }
%token<string> IDENTIFIER

%%
program:				block DOT
						;
block:					{ symtab.level_up(); }
						constdecl vardecl procdecl statement
						{ symtab.level_down(); }
						;
constdecl:				K_CONST constassignmentlist SEMICOLON
						|
						;
constassignmentlist:	IDENTIFIER EQ NUMBER { symtab.insert($1, _CONST); }
						| constassignmentlist COMMA IDENTIFIER EQ NUMBER { symtab.insert($3, _CONST); }
						;
vardecl:				K_VAR identlist SEMICOLON
						|
						;
identlist:				IDENTIFIER { symtab.insert($1, _VAR); }
						| identlist COMMA IDENTIFIER { symtab.insert($3, _VAR); }
						;
procdecl:				procdecl K_PROCEDURE IDENTIFIER SEMICOLON block SEMICOLON { symtab.insert($3, _PROC); }
						|
						;
statement:				IDENTIFIER ASSIGN expression
						| K_CALL IDENTIFIER
						| EX_MARK expression
						| QUE_MARK IDENTIFIER
						| K_BEGIN statementlist K_END
						| K_IF condition K_THEN statement
						| K_WHILE condition K_DO statement
						|
						;
statementlist:			statement
						| statementlist SEMICOLON statement
						;
condition:				K_ODD expression
						| expression relation expression
						;
relation:				EQ
						| HASH
						| LT
						| GT
						| BEQ
						| SEQ
						;
expression:				term 
						| addingoperator term
						| expression addingoperator term
						;
addingoperator:			PLUS
						| MINUS
						;
term:					factor
						| term multipliyingoperator factor
						;
multipliyingoperator:	MUL
						| DIV
						;
factor:					IDENTIFIER
						| NUMBER
						| L_BRACE expression R_BRACE
						;
%%
/*
int yyerror(char * s) {
	printf("%s\n", s);
	return 0;
}*/

int main() {
	yyparse();
}
