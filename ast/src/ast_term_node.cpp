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
  for(FactorList::iterator it = factors->begin(); it != factors->end(); ++it) {
    if((*it)->getOperator() == MULTIPLICATION) {
      val *= (*it)->eval();
    }
    else if((*it)->getOperator() == DIVISION) {
      val /= (*it)->eval();
    }
  }
}