#include "../include/ast_procedure_node.h"

ASTProcedureNode::ASTProcedureNode(ASTBlockNode * block) : block(block) {}

void ASTProcedureNode::execute() {
  block->execute();
}
