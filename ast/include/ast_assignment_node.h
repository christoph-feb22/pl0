#ifndef AST_ASSIGNMENT_NODE_H
#define AST_ASSIGNMENT_NODE_H

#include "ast_pl0_statement_node.h"
#include "ast_numeric_expression_node.h"

class ASTAssignmentNode : public ASTPL0StatementNode {
public:
  ASTAssignmentNode(int delta, int number, ASTNumericExpressionNode * exp);
  void execute();

private:
  int delta, number;
  ASTNumericExpressionNode * expression;
};

#endif