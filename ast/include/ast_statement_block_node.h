#ifndef AST_STATEMENT_BLOCK_NODE_H
#define AST_STATEMENT_BLOCK_NODE_H

#include "ast_statement_node.h"

class ASTStatementBlockNode : public ASTStatementNode {
public:
  ASTStatementBlockNode(StatementList * statements) : statements(statements) {};
private:
  StatementList * statements;
};

#endif