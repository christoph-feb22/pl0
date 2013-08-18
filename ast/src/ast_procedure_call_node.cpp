#include "../include/ast_procedure_call_node.h"

ASTProcedureCallNode::ASTProcedureCallNode() {}

ASTProcedureCallNode::ASTProcedureCallNode(int level) : level(level) {}

ASTProcedureCallNode::ASTProcedureCallNode(ASTProcedureNode * proc) : procedure(proc) {}

void ASTProcedureCallNode::setProcedure(ASTProcedureNode * proc) {
  procedure = proc;
}

void ASTProcedureCallNode::execute() {
  procedure->execute(level);
}