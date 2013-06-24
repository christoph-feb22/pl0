#ifndef SYMBOL_TABLE_ENTRY_H
#define SYMBOL_TABLE_ENTRY_H
class SymbolTableEntry
{
	public:
		SymbolTableEntry(int type, int number);
		int getType();
		int getNumber();

	private:
		int type;
		int number;
};

#endif
