#ifndef AST_TERM_NODE_H
#define AST_TERM_NODE_H

#include "ast_expression_node.h"
#include "ast_factor_node.h"

#define ADD_OP 1
#define SUB_OP -1

class ASTTermNode : public ASTExpressionNode {
public:
  ASTTermNode(ASTFactorNode * factor);
  void insert(ASTFactorNode * factor);
  int eval();
  void setAdditionOperator();
  void setSubtractionOperator();
  int getOperator();

private:
  FactorList * factors;
  int math_operator;
};

#endif