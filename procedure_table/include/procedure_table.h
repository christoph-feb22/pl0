#ifndef PROCEDURE_TABLE_H
#define PROCEDURE_TABLE_H

#include "../../ast/include/ast_procedure_node.h"
#include "../../ast/include/ast_procedure_call_node.h"
#include "procedure_call_list_element.h"
#include <map>
  using std::map;
#include <forward_list>
  using std::forward_list;

class ProcedureTable {
public:
  void insertProcedure(int level, int number, ASTProcedureNode * proc);
  void insertProcedureCall(int level, int number, ASTProcedureCallNode * proc_call);

  void setProcedureCalls();

  void print();

private:
  map< int, map<int, ASTProcedureNode *> > procedure_table;
  forward_list<ProcedureCallListElement *> procedure_calls_list;
};

#endif