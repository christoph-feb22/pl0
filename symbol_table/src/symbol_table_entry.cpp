#include "../include/symbol_table_entry.h"

SymbolTableEntry::SymbolTableEntry(int t, int n)
{
	type = t;
	number = n;
}

int SymbolTableEntry::getType()
{
	return this->type;
}

int SymbolTableEntry::getNumber()
{
	return number;
}
