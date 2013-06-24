#include "symbol_table.h"
#include <iostream>
	using namespace std;

SymbolTable::SymbolTable()
{
	level = 0;
}

void SymbolTable::level_up()
{
	level++;
}

void SymbolTable::level_down()
{
	level--;
}

void SymbolTable::insert(string key, int type)
{
	symbol_table.push_back(map<string, SymbolTableEntry>());
	symbol_table[level].insert(pair<string, SymbolTableEntry>(key, SymbolTableEntry(type)));
}

void SymbolTable::lookup()
{
}

void SymbolTable::print()
{
	for(int i = 0; i < symbol_table.size(); i++) {
		for(map_iter iter = symbol_table[i].begin(); iter != symbol_table[i].end(); iter++) {
			//cout << iterator->
		}
	}
}
