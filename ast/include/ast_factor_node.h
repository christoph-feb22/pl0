#ifndef AST_FACTOR_NODE_H
#define AST_FACTOR_NODE_H

#define MULTIPLICATION 1
#define DIVISION 2

#include "ast_expression_node.h"

class ASTFactorNode : public ASTExpressionNode {
public:
  ASTFactorNode();
  ASTFactorNode(MemoryManagement * m);
  void setMultiplicationOperator();
  void setDivisionOperator();
  int getOperator();

private:
  int factor_operator;
};

#endif
