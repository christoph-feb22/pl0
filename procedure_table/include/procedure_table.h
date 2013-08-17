#ifndef PROCEDURE_TABLE_H
#define PROCEDURE_TABLE_H

#include "../../ast/include/ast_procedure_node.h"
#include <vector>
  using std::vector;

class ProcedureTable {
public:
  void insertProcedure(int level, int number, ASTProcedureNode * proc);
  void insertProcedureCall(int level, int number);

  void setProcedureCalls();

private:
  vector< vector<ASTProcedureNode *>> procedure_table;
};

#endif