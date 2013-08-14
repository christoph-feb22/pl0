#include "ast_compare_condition_node.h"

class ASTLessThanOrEqualCompareConditionNode : public ASTCompareConditionNode {
public:
  ASTLessThanOrEqualCompareConditionNode(ASTNumericExpressionNode * exp1, ASTNumericExpressionNode * exp2);
  int eval();

};