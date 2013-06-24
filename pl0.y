%{
#include <stdio.h>
#include <cstdlib>
#include "symbol_table.h"
#include "global.h"

extern "C"
{
	int yyparse(void);
	int yylex(void);  
	int yywrap() { return 1; }
	int yyerror(char * s) { printf(" %s\n", s); exit(1); }
}

void error(int);
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
constassignmentlist:	IDENTIFIER { symtab.insert($1, _CONST); } EQ NUMBER
						| constassignmentlist COMMA IDENTIFIER { symtab.insert($3, _CONST); } EQ NUMBER
						;
vardecl:				K_VAR identlist SEMICOLON
						|
						;
identlist:				IDENTIFIER { symtab.insert($1, _VAR); }
						| identlist COMMA IDENTIFIER { symtab.insert($3, _VAR); }
						;
procdecl:				procdecl K_PROCEDURE IDENTIFIER { symtab.insert($3, _PROC); } SEMICOLON block SEMICOLON
						|
						;
statement:				IDENTIFIER ASSIGN expression { int level, number, result ; result = symtab.lookup($1, _VAR, level, number); if(result != IDENTIFIER_FOUND) error(result); }
						| K_CALL IDENTIFIER { int level, number, result ; result = symtab.lookup($2, _PROC, level, number); if(result != IDENTIFIER_FOUND) error(result); }
						| EX_MARK expression
						| QUE_MARK IDENTIFIER { int level, number, result ; result = symtab.lookup($2, _VAR, level, number); if(result != IDENTIFIER_FOUND) error(result); }
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
factor:					IDENTIFIER { int level, number, result ; result = symtab.lookup($1, _VAR, level, number); if(result != IDENTIFIER_FOUND) error(result); }
						| NUMBER
						| L_BRACE expression R_BRACE
						;
%%

void error(int error_type) {
	char error_msg[255];
	switch(error_type) {
		case IDENTIFIER_NOT_FOUND:
			sprintf(error_msg, "Line %d: Identifier not found.", line);
			break;
		case IDENTIFIER_WRONG_TYPE:
			sprintf(error_msg, "Line %d: Identifier has wrong type", line);
			break;
		default:
			sprintf(error_msg, "Line %d: Unknown error.", line);
			break;		
	}
	symtab.print();
	yyerror(error_msg);
}

int main() {
	yyparse();
}
