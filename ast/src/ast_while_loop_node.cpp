#include "../include/ast_while_loop_node.h"

ASTWhileLoopNode::ASTWhileLoopNode(ASTConditionNode * cond, ASTStatementNode * stat) : ASTConditionalStatementNode(cond, stat) {};

void ASTWhileLoopNode::execute() {
  while(condition->eval()) {
    statement->execute();
  }
}