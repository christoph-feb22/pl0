#ifndef AST_PL0_STATEMENT_NODE_H
#define AST_PL0_STATEMENT_NODE_H

#include "ast_statement_node.h"
#include "../../memory_management/include/memory_management.h"

class ASTPL0StatementNode : public ASTStatementNode {
public:
  ASTPL0StatementNode();
  ASTPL0StatementNode(MemoryManagement * m);
};

#endif