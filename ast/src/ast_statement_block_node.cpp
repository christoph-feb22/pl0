#include "../include/ast_statement_block_node.h"

ASTStatementBlockNode::ASTStatementBlockNode(StatementList * statements) : statements(statements) {}

void ASTStatementBlockNode::execute() {
  for(StatementList::iterator it = statements->begin(); it != statements->end(); ++it) {
    (*it)->execute();
  }
}


