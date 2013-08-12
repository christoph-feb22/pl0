#ifndef MEMORY_MANAGEMENT_H
#define MEMORY_MANAGEMENT_H

#include <vector>

class MemoryManagement {
public:
  MemoryManagement();
  int insertValue(int delta, int number, int value = 0);
  int getValue(int address);

private:
  std::vector<int> * memory;
};

#endif