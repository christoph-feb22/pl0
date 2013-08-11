#ifndef AST_ASSIGNMENT_NODE_H
#define AST_ASSIGNMENT_NODE_H

#include "ast_statement_node.h"
#include "ast_numeric_expression_node.h"

class ASTAssignmentNode : public ASTStatementNode {
public:
  ASTAssignmentNode(String ident, ASTNumericExpressionNode * exp) : identifier(ident), expression(exp) {};
private:
  String identifier;
  ASTNumericExpressionNode * expression;
};

#endif