#ifndef AST_CONDITIONAL_STATEMENT_NODE_H
#define AST_CONDITIONAL_STATEMENT_NODE_H

#include "ast_statement_node.h"
#include "ast_condition_node.h"

class ASTConditionalStatementNode : public ASTStatementNode {
public:
  ASTConditionalStatementNode(ASTConditionNode * cond, ASTStatementNode * stat) : condition(cond), statement(stat) {};
private:
  ASTConditionNode * condition;
  ASTStatementNode * statement;
};

#endif