%{
#include <stdio.h>
%}
%token K_CONST K_VAR K_PROCEDURE K_CALL K_BEGIN K_END K_IF K_THEN K_WHILE K_DO K_ODD COMMA SEMICOLON EX_MARK QUE_MARK BEQ SEQ ASSIGN EQ PLUS MINUS MUL DIV LT GT HASH DOT L_BRACE R_BRACE CONST WHT ERROR;
%union { 
int _double;
char t[100];
}
%token<t> IDENTIFIER;
%token<_double> NUMBER;
%%
program:				block DOT
						;
block:					constdecl vardecl procdecl statement
						;
constdecl:				K_CONST constassignmentlist SEMICOLON
						|
						;
constassignmentlist:	IDENTIFIER EQ NUMBER
						| constassignmentlist COMMA IDENTIFIER EQ NUMBER
						;
vardecl:				K_VAR identlist SEMICOLON
						|
						;
identlist:				IDENTIFIER
						| identlist COMMA IDENTIFIER
						;
procdecl:				procdecl K_PROCEDURE IDENTIFIER SEMICOLON block SEMICOLON
						|
						;
statement:				IDENTIFIER ASSIGN expression
						| K_CALL IDENTIFIER
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
int yyerror(char * s) {
	printf("%s\n", s);
	return 0;
}

int main() {
	int input;


	if(yyparse() == 0) {
		printf("Syntax OK!\n");
		return 0;
	}
	else {
		printf("Syntax schlecht!\n");
		return 1;
	}
}
