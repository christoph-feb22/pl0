#include "../include/memory_management.h"
#include <iostream>

MemoryManagement::MemoryManagement() {
  stack = vector<int> (1);
  // Setting activation record size
  activation_record_size = 2;
  // Setting Top of Stack
  stack.at(0) = 0;
}

void MemoryManagement::newMemorySegment(int delta, int n) {
  //print();
  //std::cout << "Level: " << delta << " n: " << n << "\n";
  //std::cout << "Segmentgroeße: " << getSegmentSize(n) << "\n";
  // allocate memory for new segment
  for(int i = 0; i < getSegmentSize(n); i++) {
    stack.push_back(0);
  }

  // insert values for activation record
  stack[stack[0] + getSegmentSize(n) - 1] = stack[0]; // tos to dynamic link
  int adr = stack[0];
  for(int i = 0; i < delta; i++) {
    adr = stack[adr];
  }
  stack[stack[0] + getSegmentSize(n)] = adr; // static link
  // update top of stack
  stack[0] = stack[0] + getSegmentSize(n);
  //std::cout << delta << "\n";
  //print();
}

void MemoryManagement::deleteMemorySegment(int n) {
  //std::cout << "Segment loeschen \n";
  //print();
  // update top of stack
  stack[0] = stack[stack[0] - 1];

  // free memory of deleted segment
  for(int i = 0; i < getSegmentSize(n); i++) {
    stack.pop_back();
  }
}

void MemoryManagement::insertValue(int delta, int number, int value) {
  //std::cout << "MemoryWrite -- Level: " << delta << " Nummer: " << number << "Wert: " << value << "\n";
  int adr = getAddress(delta, number);
  stack[adr] = value;
}

int MemoryManagement::getValue(int delta, int number) {
  int adr = getAddress(delta, number);
  //std::cout << "MemoryRead -- Level: " << delta << " Nummer: " << number << " Wert: " << stack[adr] << "\n";
  //print();
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

void MemoryManagement::print() {
  std::cout << "---- Start MemoryPrint ----" << "\n";
  for(int i = stack.size() - 1; i >= 0; i--) {
    std::cout << stack[i] << "\n";
  }
  std::cout << "---- Ende MemoryPrint ----" << "\n";
}