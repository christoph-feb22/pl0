#include "../include/procedure_table.h"

void ProcedureTable::insertProcedure(int level, int number, ASTProcedureNode * proc) {
  vector<ProcedureNode *> procs;

  try {
    procs = procedure_table.at(level);
  }
  catch(exception& e) {
      vector<ProcedureNode *>::iterator it;
    // level does not exist yet

  }

}

void ProcedureTable::insertProcedureCall(int level, int number) {}

void ProcedureTable::setProcedureCalls() {}