#include "../include/ast_statement_block_node.h"

ASTStatementBlockNode::ASTStatementBlockNode(StatementList * statements) : statements(statements) {}

void ASTStatementBlockNode::execute() {
  if(statements) {
    for(int i = 0; i < statements->size(); i++) {
      if(statements->at(i))
      statements->at(i)->execute();
    }
  }
}


