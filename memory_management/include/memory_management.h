#ifndef MEMORY_MANAGEMENT_H
#define MEMORY_MANAGEMENT_H

#include <vector>
  using std::vector;

class MemoryManagement {
public:
  MemoryManagement();
  int insertValue(int delta, int number, int value = 0);
  int getValue(int address);

private:
  vector<int> * memory;
};

#endif