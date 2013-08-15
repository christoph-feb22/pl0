#ifndef AST_VARIABLE_FACTOR_NODE_H
#define AST_VARIABLE_FACTOR_NODE_H

#include "ast_factor_node.h"

class ASTVariableFactorNode : public ASTFactorNode {
public:
  ASTVariableFactorNode(int delta, int number, MemoryManagement * m);
  int eval();

private:
  int delta, number;
};

#endif