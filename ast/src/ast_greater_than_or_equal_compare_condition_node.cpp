#include "../include/ast_greater_than_or_equal_compare_condition_node.h"

ASTGreaterThanOrEqualCompareConditionNode::ASTGreaterThanOrEqualCompareConditionNode(ASTNumericExpressionNode * exp1, ASTNumericExpressionNode * exp2) : ASTCompareConditionNode(exp1, exp2) {}

int ASTGreaterThanOrEqualCompareConditionNode::eval() {
  return (expression_l->eval() >= expression_r->eval());
}