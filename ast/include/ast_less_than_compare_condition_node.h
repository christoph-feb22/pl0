#include "ast_compare_condition_node.h"

class ASTLessThanCompareConditionNode : public ASTCompareConditionNode {
public:
  ASTLessThanCompareConditionNode(ASTNumericExpressionNode * exp1, ASTNumericExpressionNode * exp2);
  int eval();

};