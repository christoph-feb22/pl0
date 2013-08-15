#include "../include/ast_term_node.h"

ASTTermNode::ASTTermNode(ASTFactorNode * factor) {
  factors = new FactorList;
  factors->push_back(factor);
}

void ASTTermNode::insert(ASTFactorNode * factor) {
  factors->push_back(factor);
}

int ASTTermNode::eval() {
  int val = 1;
  for(int i = 0; i < factors->size(); i++) {
    ASTFactorNode * factor = factors->at(i);
    if(factor->getOperator() == MULTIPLICATION) {
      val *= factor->eval();
    }
    else if(factor->getOperator() == DIVISION) {
      val /= factor->eval();
    }
  }

  return val;
}