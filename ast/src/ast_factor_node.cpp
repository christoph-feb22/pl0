#include "../include/ast_factor_node.h"

ASTFactorNode::ASTFactorNode() {}

ASTFactorNode::ASTFactorNode(MemoryManagement * m) : ASTExpressionNode(m) {}

void ASTFactorNode::setMultiplicationOperator() {
  factor_operator = MULTIPLICATION;
}

void ASTFactorNode::setDivisionOperator() {
  factor_operator = DIVISION;
}

int ASTFactorNode::getOperator() {
  return factor_operator;
}