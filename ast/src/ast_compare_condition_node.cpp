#include "../include/ast_compare_condition_node.h"

ASTCompareConditionNode::ASTCompareConditionNode(ASTNumericExpressionNode * exp1, ASTNumericExpressionNode * exp2) : expression_l(exp1), expression_r(exp2) {}