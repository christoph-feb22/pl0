#ifndef MEMORY_MANAGEMENT_H
#define MEMORY_MANAGEMENT_H

#include <vector>

class MemoryManagement {
public:
  MemoryManagement();
  int setValue(int delta, int number);
  int getValue(int address);

private:
  std::vector<int> * memory;
};

#endif