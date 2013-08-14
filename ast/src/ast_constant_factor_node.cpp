#include "../include/ast_constant_factor_node.h"

ASTConstantFactorNode::ASTConstantFactorNode(int val) : value(val) {};

int ASTConstantFactorNode::eval() {
  return value;
}
