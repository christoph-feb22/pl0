#include "../include/procedure_table.h"
#include <iostream>

void ProcedureTable::insertProcedure(int level, int number, ASTProcedureNode * proc) {
  map< int, map<int, ASTProcedureNode *> >::iterator proc_table_it;
  proc_table_it = procedure_table.find(level);

  if(proc_table_it == procedure_table.end()) {
    // insert the level and the procedure (nothing found)
    map<int, ASTProcedureNode *> level_table;// = new map<int, ASTProcedureNode *>();
    level_table[number] = proc;
    procedure_table[level] = level_table;
    //procedure_table.insert( std::pair<int, map<int, ProcedureNode *> *>(level, new std::pair<int, ProcedureNode*>(number, proc)) );
  }
  else {
    map<int, ASTProcedureNode *>::iterator level_table_it = procedure_table[level].find(number);
    if(level_table_it == procedure_table[level].end()) {
      // insert only the procedure (level already inserted)
      procedure_table[level][number] = proc;
      //level_table.insert( std::pair<int, ProcedureNode *>(number, proc) );
    }
    // otherwise already inserted, do nothing
  }
}

void ProcedureTable::insertProcedureCall(int level, int number, ASTProcedureCallNode * proc_call) {
  procedure_calls_list.push_front(new ProcedureCallListElement(level, number, proc_call));
}

void ProcedureTable::setProcedureCalls() {
  // while(!procedure_calls_list.empty()) {
  //   ProcedureCallListElement * element = procedure_calls_list.front();

  //   ASTProcedureNode * procedure = procedure_table[element->getLevel()][element->getNumber()];
  //   element->setProcedure(procedure);

  //   procedure_calls_list.pop_front();
  // }
  for ( ProcedureCallListElement * elem : procedure_calls_list ) {
    ASTProcedureNode * procedure = procedure_table[elem->getLevel()][elem->getNumber()];
    elem->setProcedure(procedure);
  }
}

void ProcedureTable::print() {
  for ( ProcedureCallListElement * elem : procedure_calls_list ) {
    std::cout << "L:" << elem->getLevel() << " N: " << elem->getNumber() << "\n";
    std::cout << procedure_table[elem->getLevel()][elem->getNumber()] << "\n";
  }
}