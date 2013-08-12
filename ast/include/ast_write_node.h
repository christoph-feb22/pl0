#ifndef AST_WRITE_NODE_H
#define AST_WRITE_NODE_H

#include "ast_pl0_statement_node.h"
#include "ast_numeric_expression_node.h"

class ASTWriteNode : public ASTPL0StatementNode {
public:
  ASTWriteNode(ASTNumericExpressionNode * exp) : expression(exp) {};
private:
  ASTNumericExpressionNode * expression;
};

#endif