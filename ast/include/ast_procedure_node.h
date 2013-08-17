#ifndef AST_PROCEDURE_NODE_H
#define AST_PROCEDURE_NODE_H

#include "ast_statement_node.h"
#include "ast_block_node.h"

class ASTProcedureNode : public ASTStatementNode {
public:
  ASTProcedureNode(ASTBlockNode * block);
  void execute();

private:
  ASTBlockNode * block;
};

#endif