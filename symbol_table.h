#ifndef SYMBOL_TABLE_H
#define SYMBOL_TABLE_H

#define _VAR 1
#define _CONST 2
#define _PROC 3

#include "symbol_table_entry.h"
#include <vector>
#include <map>
#include <string>
	using namespace std;

class SymbolTable
{
	public:
		SymbolTable();
		void level_up();
		void level_down();
		void insert(string, int);
		int lookup(string, int, int&, int&);
		void print();

	private:
		int level;
		vector< map<string, SymbolTableEntry> > symbol_table;
		typedef map<string, SymbolTableEntry>::reverse_iterator map_iter;
		int max_number;
};

#endif
