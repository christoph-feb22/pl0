#ifndef AST_COMPARE_CONDITION_NODE_H
#define AST_COMPARE_CONDITION_NODE_H

#include "ast_condition_node.h"
#include "ast_numeric_expression_node.h"

class ASTCompareConditionNode : public ASTConditionNode {
public:
  ASTCompareConditionNode(ASTNumericExpressionNode * exp1, ASTNumericExpressionNode * exp2);

protected:
  ASTNumericExpressionNode * expression_l, * expression_r;
};

#endif