#include "../include/ast_expression_factor_node.h"

ASTExpressionFactorNode::ASTExpressionFactorNode(ASTNumericExpressionNode * exp) : expression(exp) {}

int ASTExpressionFactorNode::eval() {
  return expression->eval();
}