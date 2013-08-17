#ifndef SYMBOL_TABLE_ENTRY_H
#define SYMBOL_TABLE_ENTRY_H

#include "../../ast/include/ast_procedure_node.h"

class SymbolTableEntry {
	public:
    SymbolTableEntry(int type, int number);
    SymbolTableEntry(int type, int number, ASTProcedureNode * proc);
		int getType();
		int getNumber();
    ASTProcedureNode * getProcedureNode();
    void setProcedureNode(ASTProcedureNode *);

	private:
		int type;
		int number;
    ASTProcedureNode * procedure;
};

#endif
