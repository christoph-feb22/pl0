#ifndef AST_STATEMENT_BLOCK_NODE_H
#define AST_STATEMENT_BLOCK_NODE_H

#include "ast_pl0_statement_node.h"

class ASTStatementBlockNode : public ASTPL0StatementNode {
public:
  ASTStatementBlockNode(StatementList * statements) : statements(statements) {};
private:
  StatementList * statements;
};

#endif