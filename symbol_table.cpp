#include "symbol_table.h"
#include <iostream>
	using namespace std;

SymbolTable::SymbolTable()
{
	level = -1;
	max_number = 0;
}

void SymbolTable::level_up()
{
	level++;
	//print();
}

void SymbolTable::level_down()
{
	print();
	level--;
}

void SymbolTable::insert(string key, int type)
{
	// Vector vergrößern, falls zu klein
	if(symbol_table.size() <= level) {
		symbol_table.push_back(map<string, SymbolTableEntry>());
	}

	// only insert if key not inserted yet in this level
	if(symbol_table[level].find(key) == symbol_table[level].end()) {
		// calculate running number
		int number = symbol_table[level].size();
		// update max_number for print
		if(number > max_number) max_number = number;
		// Insert Element
		symbol_table[level].insert(pair<string, SymbolTableEntry>(key, SymbolTableEntry(type, number)));
	}
}

int SymbolTable::lookup(string key, int type, int& level, int& number)
{
	if(symbol_table[level].find(key) != symbol_table[level].end()) {
		return 0;
	}
}

void SymbolTable::print()
{
	cout << "Start - Print\n";
	for(int i = 0; i < symbol_table.size(); i++) {
		for(map_iter iter = symbol_table[i].rbegin(); iter != symbol_table[i].rend(); iter++) {
			cout << "Ebene: " << i << "\t";
			cout << "Nummer: " << iter->second.getNumber() << "\t";
			cout << "Bez.: " << iter->first << "\t";
			cout << "Typ: " << iter->second.getType() << "\n";
		}
	}
	
/*
	for(int i = 0; i < symbol_table.size(); i++) {
		cout << max_number - i << "\t";
		if(symbol_table[i].size() >= max_number - i)	{
			for(map_iter iter = symbol_table[i].rbegin(); iter != symbol_table[i].rend(); iter++) {
				//cout << "Ebene: " << i << "\t";
				//cout << "Nummer: " << iter->second.getNumber() << "\t";
				cout << "Bez.: " << iter->first << " - ";
				cout << "Typ: " << iter->second.getType() << "\n";
			}
		}
	}
	cout << "Level\t";
	cout << "\n";
*/
	cout << "End - Print\n";
}
