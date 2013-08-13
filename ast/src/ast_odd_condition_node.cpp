#include "../include/ast_odd_condition_node.h"

ASTOddConditionNode::ASTOddConditionNode(ASTNumericExpressionNode * exp) : expression(exp) {}

int ASTOddConditionNode::eval() {
  return expression->eval() & 1
}