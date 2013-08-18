#include "../include/ast_read_node.h"
#include <string>
  using std::string;
#include <iostream>
  using std::cin;

ASTReadNode::ASTReadNode(int delta, int number, MemoryManagement * m) : delta(delta), number(number), ASTPL0StatementNode(m) {}

void ASTReadNode::execute() {
  std::cout << "Eingabe: ";
  int x;
  cin >> x;

  memory->insertValue(delta, number, x);
}