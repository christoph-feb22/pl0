#include "../include/ast_procedure_node.h"

ASTProcedureNode::ASTProcedureNode(String ident, ASTBlockNode * block) : identifier(ident), block(block) {};

void ASTProcedureNode::execute() {
  block->execute();
}