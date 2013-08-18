#include "../include/procedure_call_list_element.h"

ProcedureCallListElement::ProcedureCallListElement(int level, int number, ASTProcedureCallNode * node) : level(level), number(number), procedure_call_node(node) {}

void ProcedureCallListElement::setProcedure(ASTProcedureNode * proc) {
  procedure_call_node->setProcedure(proc);
}

int ProcedureCallListElement::getLevel() {
  return level;
}

int ProcedureCallListElement::getNumber() {
  return number;
}