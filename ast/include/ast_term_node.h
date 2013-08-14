#ifndef AST_TERM_NODE_H
#define AST_TERM_NODE_H

#include "ast_expression_node.h"
#include "ast_factor_node.h"

class ASTTermNode : public ASTExpressionNode {
public:
  ASTTermNode(ASTFactorNode * factor);
  void insert(ASTFactorNode * factor);
  int eval();

private:
  FactorList * factors;
};

#endif