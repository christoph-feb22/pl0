#ifndef AST_STATEMENT_NODE_H
#define AST_STATEMENT_NODE_H

#include "ast_node.h"

class ASTStatementNode : public ASTNode {
public:
  ASTStatementNode();
  ASTStatementNode(MemoryManagement * m);
  virtual void execute() = 0;
};

#endif
