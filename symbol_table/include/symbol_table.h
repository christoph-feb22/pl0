#ifndef SYMBOL_TABLE_H
#define SYMBOL_TABLE_H

#define _VAR 1
#define _CONST 2
#define _PROC 3

#define IDENTIFIER_NOT_FOUND 1
#define IDENTIFIER_WRONG_TYPE 2
#define IDENTIFIER_FOUND 3

#include "symbol_table_entry.h"
#include <vector>
#include <map>
#include <string>
	using namespace std;
#include "../../ast/include/ast_procedure_node.h"

class SymbolTable {
public:
	SymbolTable();
	void level_up();
	void level_down();
	void insert(string, int);
	//void insert(string, int, ASTProcedureNode *);
	SymbolTableEntry * getSymbolTableEntry(string, int);
	ASTProcedureNode * getProcedureNode(string, int);
	ASTProcedureNode * getProcedureNode(int level, string key);
	int lookup(string, int, int&, int&);

	int getCurrentLevel();

	void print();

private:
	int level;
	vector< map<string, SymbolTableEntry> > symbol_table;
	typedef map<string, SymbolTableEntry>::reverse_iterator map_iter;
	int max_number;
};

#endif
