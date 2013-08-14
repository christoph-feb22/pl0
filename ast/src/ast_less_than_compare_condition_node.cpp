#include "../include/ast_less_than_compare_condition_node.h"

ASTLessThanCompareConditionNode::ASTLessThanCompareConditionNode(ASTNumericExpressionNode * exp1, ASTNumericExpressionNode * exp2) : ASTCompareConditionNode(exp1, exp2) {}

int ASTLessThanCompareConditionNode::eval() {
  return (expression_l->eval() < expression_r->eval());
}