#include "../include/ast_greater_than_compare_condition_node.h"

ASTGreaterThanCompareConditionNode::ASTGreaterThanCompareConditionNode(ASTNumericExpressionNode * exp1, ASTNumericExpressionNode * exp2) : ASTCompareConditionNode(exp1, exp2) {}

int ASTGreaterThanCompareConditionNode::eval() {
  return (expression_l->eval() > expression_r->eval());
}