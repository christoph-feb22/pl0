#include "ast_compare_condition_node.h"

class ASTGreaterThanCompareConditionNode : public ASTCompareConditionNode {
public:
  ASTGreaterThanCompareConditionNode(ASTNumericExpressionNode * exp1, ASTNumericExpressionNode * exp2);
  int eval();

};