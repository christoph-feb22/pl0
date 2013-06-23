#include <map>
#include <string>
	using namespace std;

class SymbolTable
{
	public:
		void level_up();
		void level_down();
		void insert(string key);
		void lookup();

	private:
		int level;
		map<string, int> symbol_table[];
}
