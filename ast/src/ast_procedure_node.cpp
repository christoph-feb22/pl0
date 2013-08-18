#include "../include/ast_procedure_node.h"

ASTProcedureNode::ASTProcedureNode(ASTBlockNode * block) : block(block) {}

void ASTProcedureNode::execute() {}

void ASTProcedureNode::execute(int call_level) {
  block->execute(call_level);
}
