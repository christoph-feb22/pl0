#ifndef AST_READ_NODE_H
#define AST_READ_NODE_H

#include "ast_pl0_statement_node.h"

class ASTReadNode : public ASTPL0StatementNode {
public:
  ASTReadNode(int delta, int number);
  void execute();

private:
  int delta, number;
};

#endif