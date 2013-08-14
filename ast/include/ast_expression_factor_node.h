#ifndef AST_EXPRESSION_FACTOR_NODE_H
#define AST_EXPRESSION_FACTOR_NODE_H

#include "ast_factor_node.h"
#include "ast_numeric_expression_node.h"

class ASTExpressionFactorNode : public ASTFactorNode {
public:
  ASTExpressionFactorNode(ASTNumericExpressionNode * exp);
  int eval();

private:
  ASTNumericExpressionNode * expression;
};

#endif
