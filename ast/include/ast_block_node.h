#ifndef AST_BLOCK_NODE_H
#define AST_BLOCK_NODE_H

#include "ast_statement_node.h"
#include "ast_const_declaration_node.h"
#include "ast_var_declaration_node.h"
#include "ast_procedure_node.h"
#include "ast_pl0_statement_node.h"
#include "../../memory_management/include/memory_management.h"

class ASTBlockNode : public ASTStatementNode {
public:
	ASTBlockNode(ConstDeclarationList * consts, VarDeclarationList * vars, ProcedureDeclarationList * procs, ASTPL0StatementNode * statement, MemoryManagement * memory, int level = 0);
  void setLevel(int l);
  void execute();

private:
	ConstDeclarationList * constants;
	VarDeclarationList * variables;

	ProcedureDeclarationList * procedures;

	ASTPL0StatementNode * statement;

  int level;
};

#endif
