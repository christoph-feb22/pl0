#include "ast_compare_condition_node.h"

class ASTGreaterThanOrEqualCompareConditionNode : public ASTCompareConditionNode {
public:
  ASTGreaterThanOrEqualCompareConditionNode(ASTNumericExpressionNode * exp1, ASTNumericExpressionNode * exp2);
  int eval();

};