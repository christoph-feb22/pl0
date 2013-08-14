#include "ast_compare_condition_node.h"

class ASTEqualCompareConditionNode : public ASTCompareConditionNode {
public:
  ASTEqualCompareConditionNode(ASTNumericExpressionNode * exp1, ASTNumericExpressionNode * exp2);
  int eval();

};