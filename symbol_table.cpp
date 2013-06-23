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

void SymbolTable::insert(string key)
{
	symbol_table[level] = map<string, int>().insert();
}

void SymbolTable::lookup()
{
}
