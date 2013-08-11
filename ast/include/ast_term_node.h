#ifndef AST_TERM_NODE_H
#define AST_TERM_NODE_H

#include "ast_expression_node.h"

class ASTTermNode : public ASTExpressionNode {
public:
  ASTTermNode(ASTFactorNode * factor) {
    factors = new FactorList;
    factors->push_back(factor);
  }
  void insert(ASTFactorNode * factor) {
    factors->push_back(factor);
  }

private:
  FactorList * factors;
};

typedef std::vector<ASTTermNode *> TermList;

#endif