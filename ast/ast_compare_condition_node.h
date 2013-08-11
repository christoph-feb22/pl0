#ifndef AST_COMPARE_CONDITION_NODE_H
#define AST_COMPARE_CONDITION_NODE_H

#include "ast_condition_node.h"

class ASTCompareConditionNode : public ASTConditionNode {
public:
  ASTCompareConditionNode(ASTNumericExpressionNode * exp1, ASTNumericExpressionNode * exp2) : expression_l(exp1), expression_r(exp2) {};
private:
  ASTNumericExpressionNode * expression_l, * expression_r;
};

#endif