#ifndef AST_PROCEDURE_NODE_H
#define AST_PROCEDURE_NODE_H

#include "ast_statement_node.h"
#include "ast_block_node.h"

class ASTProcedureNode : public ASTStatementNode {
public:
  ASTProcedureNode(String ident, ASTBlockNode * block);
  void execute();

private:
  String identifier;
  ASTBlockNode * block;
};

#endif