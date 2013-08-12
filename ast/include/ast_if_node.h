#ifndef AST_IF_NODE_H
#define AST_IF_NODE_H

#include "ast_conditional_statement_node.h"

class ASTIfNode : public ASTConditionalStatementNode {
public:
  ASTIfNode(ASTConditionNode * cond, ASTStatementNode * stat);
  void execute();
};

#endif