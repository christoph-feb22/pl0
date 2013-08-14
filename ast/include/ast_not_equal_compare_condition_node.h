#include "ast_compare_condition_node.h"

class ASTNotEqualCompareConditionNode : public ASTCompareConditionNode {
public:
  ASTNotEqualCompareConditionNode(ASTNumericExpressionNode * exp1, ASTNumericExpressionNode * exp2);
  int eval();

};