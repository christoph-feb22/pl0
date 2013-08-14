#ifndef AST_VAR_DECLARATION_NODE_H
#define AST_VAR_DECLARATION_NODE_H

#include "ast_declaration_node.h"

class ASTVarDeclarationNode : public ASTDeclarationNode {
public:
  ASTVarDeclarationNode(MemoryManagement *, int delta, int number);
  void execute();

private:
  int delta;
  int number;
};

#endif