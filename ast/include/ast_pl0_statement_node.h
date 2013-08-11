#ifndef AST_PL0_STATEMENT_NODE_H
#define AST_PL0_STATEMENT_NODE_H

#include "ast_statement_node.h"

class ASTPL0StatementNode : public ASTStatementNode {
};

typedef std::vector<ASTPL0StatementNode *> StatementList;

#endif