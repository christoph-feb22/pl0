#include "symbol_table.h"

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
	symbol_table.push_back(map<string, SymbolTableEntry>().insert(make_pair(key, SymbolTableEntry(type))));
}

void SymbolTable::lookup()
{
}
