%{
#include <stdio.h>
#include <cstdlib>
#include "symbol_table.h"
#include "global.h"

#include "ast/include/types.h"

//#include "ast/include/ast_node.h"
#include "ast/include/ast_block_node.h"
#include "ast/include/ast_pl0_statement_node.h"
#include "ast/include/ast_condition_node.h"
#include "ast/include/ast_numeric_expression_node.h"
#include "ast/include/ast_term_node.h"
#include "ast/include/ast_factor_node.h"
#include "ast/include/ast_const_declaration_node.h"
#include "ast/include/ast_var_declaration_node.h"
#include "ast/include/ast_procedure_node.h"
#include "ast/include/ast_assignment_node.h"
#include "ast/include/ast_procedure_call_node.h"
#include "ast/include/ast_write_node.h"
#include "ast/include/ast_read_node.h"
#include "ast/include/ast_statement_block_node.h"
#include "ast/include/ast_if_node.h"
#include "ast/include/ast_while_loop_node.h"
#include "ast/include/ast_odd_condition_node.h"
#include "ast/include/ast_compare_condition_node.h"

void error(int);
SymbolTable symtab;
ASTBlockNode * root;

extern int yylex();
int yyerror(char * s) { printf(" %s\n", s); exit(1); }
%}

%union {
	char string[255];
	int number;
	ASTBlockNode * block;
	ASTPL0StatementNode * statement;
	ASTConditionNode * condition;
	ASTNumericExpressionNode * expression;
	ASTTermNode * term;
	ASTFactorNode * factor;

	ConstDeclarationList * constassignmentlist;
	VarDeclarationList * identlist;
	ProcedureDeclarationList * proclist;
	StatementList * statementlist;
}

%token K_CONST K_VAR K_PROCEDURE K_CALL K_BEGIN K_END K_IF K_THEN K_WHILE K_DO K_ODD COMMA SEMICOLON EX_MARK QUE_MARK BEQ SEQ ASSIGN EQ PLUS MINUS MUL DIV LT GT HASH DOT L_BRACE R_BRACE CONST ERROR
%token<string> IDENTIFIER
%token<number> NUMBER

%type<block> block
%type<constassignmentlist> constassignmentlist constdecl
%type<identlist> identlist vardecl
%type<proclist> procdecl
%type<statement> statement
%type<statementlist> statementlist
%type<condition> condition
%type<expression> expression
%type<term> term
%type<factor> factor

%%
program:				block DOT { root = $1; }
						;
block:					{ symtab.level_up(); }
						constdecl vardecl procdecl statement
						{ $$ = new ASTBlockNode($2, $3, $4, $5); symtab.level_down(); }
						;
constdecl:				K_CONST constassignmentlist SEMICOLON
						{ $$ = $2; }
						|
						{ $$ = NULL; }
						;
constassignmentlist:	constassignmentlist COMMA IDENTIFIER { symtab.insert($3, _CONST); } EQ NUMBER
						{ $$ = $1; $$->push_back(new ASTConstDeclarationNode($3, $6)); }
						| IDENTIFIER { symtab.insert($1, _CONST); } EQ NUMBER
						{ $$ = new ConstDeclarationList(); $$->push_back(new ASTConstDeclarationNode($1, $4)); }
						;
vardecl:				K_VAR identlist SEMICOLON
						{ $$ = $2; }
						|
						{ $$ = NULL; }
						;
identlist:				identlist COMMA IDENTIFIER
						{ symtab.insert($3, _VAR); $$ = $1; $$->push_back(new ASTVarDeclarationNode($3)); }
						| IDENTIFIER
						{ symtab.insert($1, _VAR); $$ = new VarDeclarationList(); $$->push_back(new ASTVarDeclarationNode($1)); }
						;
procdecl:				procdecl K_PROCEDURE IDENTIFIER { symtab.insert($3, _PROC); } SEMICOLON block SEMICOLON
						{ $$ = $1; $$->push_back(new ASTProcedureNode($3, $6)); }
						|
						{ $$ = new ProcedureDeclarationList(); }
						;
statement:				IDENTIFIER ASSIGN expression
						{ int level, number, result ; result = symtab.lookup($1, _VAR, level, number); if(result != IDENTIFIER_FOUND) error(result);
						$$ = new ASTAssignmentNode($1, $3); }
						| K_CALL IDENTIFIER
						{ int level, number, result ; result = symtab.lookup($2, _PROC, level, number); if(result != IDENTIFIER_FOUND) error(result);
						$$ = new ASTProcedureCallNode($2); }
						| EX_MARK expression
						{ $$ = new ASTWriteNode($2); }
						| QUE_MARK IDENTIFIER
						{ int level, number, result ; result = symtab.lookup($2, _VAR, level, number); if(result != IDENTIFIER_FOUND) error(result);
						$$ = new ASTReadNode($2); }
						| K_BEGIN statementlist K_END
						{ $$ = new ASTStatementBlockNode($2); }
						| K_IF condition K_THEN statement
						{ $$ = new ASTIfNode($2, $4); }
						| K_WHILE condition K_DO statement
						{ $$ = new ASTWhileLoopNode($2, $4); }
						|
						{ $$ = NULL; }
						;
statementlist:			statementlist SEMICOLON statement
						{ $$ = $1; $$->push_back($3); }
						| statement
						{ $$ = new StatementList(); $$->push_back($1); }
						;
condition:				K_ODD expression
						{ $$ = new ASTOddConditionNode($2); }
						| expression relation expression
						{ $$ = new ASTCompareConditionNode($1, $3); }
						;
relation:				EQ
						| HASH
						| LT
						| GT
						| BEQ
						| SEQ
						;
expression:				expression addingoperator term
						{ $$ = $1; $$->insert($3); }
						| addingoperator term
						{ $$ = new ASTNumericExpressionNode($2); }
						| term
						{ $$ = new ASTNumericExpressionNode($1); }
						;
addingoperator:			PLUS
						| MINUS
						;
term:					term multipliyingoperator factor
						{ $$ = $1; $$->insert($3); }
						| factor
						{ $$ = new ASTTermNode($1); }
						;
multipliyingoperator:	MUL
						| DIV
						;
factor:					IDENTIFIER
						{ int level, number, result ; result = symtab.lookup($1, _VAR, level, number); if(result != IDENTIFIER_FOUND) error(result);
						$$ = new ASTFactorNode($1); }
						| NUMBER
						{ $$ = new ASTFactorNode($1); }
						| L_BRACE expression R_BRACE
						{ $$ = new ASTFactorNode($2); }
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
	root->execute();
}

