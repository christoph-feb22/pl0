#ifndef AST_WHILE_LOOP_NODE_H
#define AST_WHILE_LOOP_NODE_H

#include "ast_conditional_statement_node.h"

class ASTWhileLoopNode : public ASTConditionalStatementNode {
public:
  ASTWhileLoopNode(ASTConditionNode * cond, ASTStatementNode * stat) : ASTConditionalStatementNode(cond, stat) {};
};

#endif