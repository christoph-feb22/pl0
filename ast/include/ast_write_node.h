#ifndef AST_WRITE_NODE_H
#define AST_WRITE_NODE_H

#include "ast_statement_node.h"

class ASTWriteNode : public ASTStatementNode {
public:
  ASTWriteNode(ASTNumericExpressionNode * exp) : expression(exp) {};
private:
  ASTNumericExpressionNode * expression;
};

#endif