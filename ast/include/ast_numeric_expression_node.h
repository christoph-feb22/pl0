#ifndef AST_NUMERIC_EXPRESSION_NODE
#define AST_NUMERIC_EXPRESSION_NODE

#include "ast_pl0_expression_node.h"
#include "ast_term_node.h"

class ASTNumericExpressionNode : public ASTPL0ExpressionNode {
public:
  ASTNumericExpressionNode(ASTTermNode * term);

  void insert(ASTTermNode * term);
  int eval();

private:
  TermList * terms;
};

#endif