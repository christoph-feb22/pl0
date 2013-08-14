#include "../include/ast_less_than_or_equal_compare_condition_node.h"

ASTLessThanOrEqualCompareConditionNode::ASTLessThanOrEqualCompareConditionNode(ASTNumericExpressionNode * exp1, ASTNumericExpressionNode * exp2) : ASTCompareConditionNode(exp1, exp2) {}

int ASTLessThanOrEqualCompareConditionNode::eval() {
  return (expression_l->eval() <= expression_r->eval());
}