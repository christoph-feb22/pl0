#include "../include/ast_not_equal_compare_condition_node.h"

ASTNotEqualCompareConditionNode::ASTNotEqualCompareConditionNode(ASTNumericExpressionNode * exp1, ASTNumericExpressionNode * exp2) : ASTCompareConditionNode(exp1, exp2) {}

int ASTNotEqualCompareConditionNode::eval() {
  return (expression_l->eval() != expression_r->eval());
}