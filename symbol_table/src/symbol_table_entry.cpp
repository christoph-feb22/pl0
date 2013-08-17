#include "../include/symbol_table_entry.h"

SymbolTableEntry::SymbolTableEntry(int t, int n) : type(t), number(n) {}

SymbolTableEntry::SymbolTableEntry(int type, int number, ASTProcedureNode * proc) : type(type), number(number), procedure(proc) {}

int SymbolTableEntry::getType() {
	return this->type;
}

int SymbolTableEntry::getNumber() {
	return number;
}

ASTProcedureNode * SymbolTableEntry::getProcedureNode() {
  return procedure;
}

void SymbolTableEntry::setProcedureNode(ASTProcedureNode * node) {
  procedure = node;
}