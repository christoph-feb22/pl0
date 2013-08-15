#include "../include/ast_assignment_node.h"

ASTAssignmentNode::ASTAssignmentNode(int delta, int number, ASTNumericExpressionNode * exp, MemoryManagement * m) : delta(delta), number(number), expression(exp), ASTPL0StatementNode(m) {}

void ASTAssignmentNode::execute() {
  memory->insertValue(delta, number, expression->eval());
}