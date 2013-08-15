%{
#include <stdio.h>
#include <cstdlib>
#include "symbol_table/include/symbol_table.h"
#include "global.h"
#include "memory_management/include/memory_management.h"

#include "ast/include/types.h"

#include "ast/include/ast_block_node.h"
#include "ast/include/ast_pl0_statement_node.h"
#include "ast/include/ast_condition_node.h"
#include "ast/include/ast_numeric_expression_node.h"
#include "ast/include/ast_term_node.h"
#include "ast/include/ast_factor_node.h"
#include "ast/include/ast_constant_factor_node.h"
#include "ast/include/ast_variable_factor_node.h"
#include "ast/include/ast_expression_factor_node.h"
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
#include "ast/include/ast_equal_compare_condition_node.h"
#include "ast/include/ast_not_equal_compare_condition_node.h"
#include "ast/include/ast_less_than_compare_condition_node.h"
#include "ast/include/ast_greater_than_compare_condition_node.h"
#include "ast/include/ast_greater_than_or_equal_compare_condition_node.h"
#include "ast/include/ast_less_than_or_equal_compare_condition_node.h"

#define EQUAL 1
#define NOT_EQUAL 2
#define LESS_THAN 3
#define GREATER_THAN 4
#define LESS_THAN_OR_EQUAL 5
#define GREATER_THAN_OR_EQUAL 6
#define MULTIPLICATION_OPERATOR 7
#define DIVISION_OPERATOR 8

void error(int);
SymbolTable symtab;
MemoryManagement * memory = new MemoryManagement();
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
%type<number> relation multipliyingoperator

%%
program:				block DOT { root = $1; }
						;
block:					{ symtab.level_up(); }
						constdecl vardecl procdecl statement
						{ $$ = new ASTBlockNode($2, $3, $4, $5, memory, symtab.getCurrentLevel()); symtab.level_down(); }
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
						{ $$ = NULL ; }
						;
identlist:				identlist COMMA IDENTIFIER
						{ symtab.insert($3, _VAR);
							int level, number; symtab.lookup($3, _VAR, level, number);
							$$ = $1; $$->push_back(new ASTVarDeclarationNode(memory, level, number)); }
						| IDENTIFIER
						{ symtab.insert($1, _VAR);
							int level, number; symtab.lookup($1, _VAR, level, number);
							$$ = new VarDeclarationList(); $$->push_back(new ASTVarDeclarationNode(memory, level, number)); }
						;
procdecl:				procdecl K_PROCEDURE IDENTIFIER { symtab.insert($3, _PROC); } SEMICOLON block SEMICOLON
						{ $$ = $1; $$->push_back(new ASTProcedureNode($3, $6)); }
						|
						{ $$ = new ProcedureDeclarationList(); }
						;
statement:				IDENTIFIER ASSIGN expression
						{ int level, number, result ; result = symtab.lookup($1, _VAR, level, number); if(result != IDENTIFIER_FOUND) error(result);
						$$ = new ASTAssignmentNode(level, number, $3); }
						| K_CALL IDENTIFIER
						{ int level, number, result ; result = symtab.lookup($2, _PROC, level, number); if(result != IDENTIFIER_FOUND) error(result);
						$$ = new ASTProcedureCallNode($2); }
						| EX_MARK expression
						{ $$ = new ASTWriteNode($2); }
						| QUE_MARK IDENTIFIER
						{ int level, number, result ; result = symtab.lookup($2, _VAR, level, number); if(result != IDENTIFIER_FOUND) error(result);
						$$ = new ASTReadNode(level, number); }
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
						{ if($2 == EQ) $$ = new ASTEqualCompareConditionNode($1, $3);
							else if($2 == HASH) $$ = new ASTNotEqualCompareConditionNode($1, $3);
							else if($2 == LT)  $$ = new ASTLessThanCompareConditionNode($1, $3);
							else if($2 == GT) $$ = new ASTGreaterThanCompareConditionNode($1, $3);
							else if($2 == BEQ) $$ = new ASTLessThanOrEqualCompareConditionNode($1, $3);
							else if($2 == SEQ) $$ = new ASTGreaterThanOrEqualCompareConditionNode($1, $3); }
						;
relation:				EQ { $$ = EQUAL; }
						| HASH { $$ = NOT_EQUAL; }
						| LT { $$ = LESS_THAN; }
						| GT { $$ = GREATER_THAN; }
						| BEQ { $$ = GREATER_THAN_OR_EQUAL; }
						| SEQ { $$ = LESS_THAN_OR_EQUAL; }
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
						{ $$ = $1;
						if($2 == MULTIPLICATION) $3->setMultiplicationOperator();
						else if($2 == DIVISION) $3->setDivisionOperator();
						$$->insert($3); }
						| factor
						{ $1->setMultiplicationOperator();
							$$ = new ASTTermNode($1); }
						;
multipliyingoperator:	MUL { return MULTIPLICATION_OPERATOR; }
						| DIV { return DIVISION_OPERATOR; }
						;
factor:					IDENTIFIER
						{ int level, number, result ; result = symtab.lookup($1, _VAR, level, number); if(result != IDENTIFIER_FOUND) error(result);
						$$ = new ASTVariableFactorNode(level, number); }
						| NUMBER
						{ $$ = new ASTConstantFactorNode($1); }
						| L_BRACE expression R_BRACE
						{ $$ = new ASTExpressionFactorNode($2); }
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

