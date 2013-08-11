#ifndef AST_ODD_CONDITION_NODE_H
#define AST_ODD_CONDITION_NODE_H

#include "ast_condition_node.h"

class ASTOddConditionNode : public ASTConditionNode {
public:
  ASTOddConditionNode(ASTNumericExpressionNode * exp) : expression(exp) {};
private:
  ASTNumericExpressionNode * expression;
};

#endif