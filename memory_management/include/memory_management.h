#ifndef MEMORY_MANAGEMENT_H
#define MEMORY_MANAGEMENT_H

#include <vector>
  using std::vector;

class MemoryManagement {
public:
  MemoryManagement();
  void newMemorySegment(int delta, int n);
  void deleteMemorySegment(int);
  void insertValue(int delta, int number, int value = 0);
  int getValue(int delta, int number);

  void print();

private:
  int getSegmentSize(int);
  int getAddress(int delta, int number);
  int activation_record_size;
  vector<int> stack;
};

#endif