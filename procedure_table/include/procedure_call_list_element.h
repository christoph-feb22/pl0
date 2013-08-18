#ifndef PROCEDURE_CALL_LIST_ELEMENT_H
#define PROCEDURE_CALL_LIST_ELEMENT_H

#include "../../ast/include/ast_procedure_node.h"
#include "../../ast/include/ast_procedure_call_node.h"

class ProcedureCallListElement {
public:
  ProcedureCallListElement(int level, int number, ASTProcedureCallNode * node);
  void setProcedure(ASTProcedureNode *);
  int getLevel();
  int getNumber();

private:
  ASTProcedureCallNode * procedure_call_node;
  int level, number;
};

#endif