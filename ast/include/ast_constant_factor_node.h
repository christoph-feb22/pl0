#ifndef AST_CONSTANT_FACTOR_NODE_H
#define AST_CONSTANT_FACTOR_NODE_H

#include "ast_factor_node.h"

class ASTConstantFactorNode : public ASTFactorNode {
public:
  ASTConstantFactorNode(int val);
  int eval();

private:
  int value;
};

#endif