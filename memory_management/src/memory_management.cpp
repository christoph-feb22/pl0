#include "../include/memory_management.h"

MemoryManagement::MemoryManagement() {
  // Setting activation record size
  activation_record_size = 2;
  // Setting Top of Stack
  stack.push_back(-1);
}

void MemoryManagement::newMemorySegment(int delta, int n) {
  // allocate memory for new segment
  for(int i = 0; i < getSegmentSize(n); i++) {
    stack.push_back(0);
  }

  // insert values for activation record
  stack[stack[0] + getSegmentSize(0) - 1] = stack[0]; // dynamic link
  int adr = stack[0];
  for(int i = 0; i < delta; i++) {
    adr = stack[adr];
  }
  stack[stack[0] + getSegmentSize(n)] = adr; // static link

  // update top of stack
  stack[0] = stack[0] + getSegmentSize(n);
}

void MemoryManagement::deleteMemorySegment(int n) {
  // update top of stack
  stack[0] = stack[stack[0] - 1];

  // free memory of deleted segment
  for(int i = 0; i < getSegmentSize(n); i++) {
    stack.pop_back();
  }
}

void MemoryManagement::insertValue(int delta, int number, int value) {
  int adr = getAddress(delta, number);
  stack[adr] = value;
}

int MemoryManagement::getValue(int delta, int number) {
  int adr = getAddress(delta, number);
  return stack[adr];
}

int MemoryManagement::getSegmentSize(int n) {
  return n + activation_record_size;
}

int MemoryManagement::getAddress(int delta, int number) {
  int adr = stack[0];

  for(int i = 0; i < delta; i++) {
    adr = stack[adr];
  }
  adr -= activation_record_size;
  adr -= number;

  return adr;
}