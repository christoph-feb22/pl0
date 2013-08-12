#include "../include/ast_if_node.h"

ASTIfNode::ASTIfNode(ASTConditionNode * cond, ASTStatementNode * stat) : ASTConditionalStatementNode(cond, stat) {}

void ASTIfNode::execute() {
  if(condition->eval()) {
    statement->execute();
  }
}