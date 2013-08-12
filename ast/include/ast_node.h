#ifndef NODES_H
#define NODES_H

#include <string>
typedef std::string String;

#include "types.h"
#include "../../memory_management/include/memory_management.h"

class ASTNode {
public:
  ASTNode();
  ASTNode(MemoryManagement * m);

protected:
  MemoryManagement * memory;
};

#endif
