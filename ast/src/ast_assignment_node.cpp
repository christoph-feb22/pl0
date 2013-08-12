#include "../include/ast_assignment_node.h"

ASTAssignmentNode(int delta, int number, ASTNumericExpressionNode * exp) : delta(delta), number(number), expression(exp) {}

void ASTAssignmentNode::execute() {
  memory->insertValue(delta, number, expression->eval());
}