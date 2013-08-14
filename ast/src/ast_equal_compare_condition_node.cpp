#include "../include/ast_equal_compare_condition_node.h"

ASTEqualCompareConditionNode::ASTEqualCompareConditionNode(ASTNumericExpressionNode * exp1, ASTNumericExpressionNode * exp2) : ASTCompareConditionNode(exp1, exp2) {}

int ASTEqualCompareConditionNode::eval() {
  return (expression_l->eval() == expression_r->eval());
}