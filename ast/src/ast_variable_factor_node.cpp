#include "../include/ast_variable_factor_node.h"

ASTVariableFactorNode::ASTVariableFactorNode(int delta, int number) : delta(delta), number(number) {}

int ASTVariableFactorNode::eval() {
  return memory->getValue(delta, number);
}