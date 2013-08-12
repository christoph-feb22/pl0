#include "../include/ast_write_node.h"
#include <iostream>
  using std::cout;

ASTWriteNode::ASTWriteNode(ASTNumericExpressionNode * exp) : expression(exp) {}

void ASTWriteNode::execute() {
  cout << expression->eval();
}