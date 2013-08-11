#ifndef AST_NUMERIC_EXPRESSION_NODE
#define AST_NUMERIC_EXPRESSION_NODE

#include "ast_expression_node.h"
#include "ast_term_node.h"

class ASTNumericExpressionNode : public ASTExpressionNode {
public:
  ASTNumericExpressionNode(ASTTermNode * term) {
    terms = new TermList;
    terms->push_back(term);
  }
  void insert(ASTTermNode * term) {
    terms->push_back(term);
  }
  int eval();
private:
  TermList * terms;
};

#endif