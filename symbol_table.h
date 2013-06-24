#ifndef SYMBOL_TABLE_H
#define SYMBOL_TABLE_H

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
		void insert(string key, int type);
		void lookup();
		void print();

	private:
		int level;
		vector< map<string, SymbolTableEntry> > symbol_table;
		typedef map<string, SymbolTableEntry>::iterator map_iter;
};

#endif
