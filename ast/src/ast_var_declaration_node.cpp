#include "../include/ast_var_declaration_node.h"

ASTVarDeclarationNode::ASTVarDeclarationNode(String ident) : ASTDeclarationNode(ident) {}

ASTVarDeclarationNode::ASTVarDeclarationNode(MemoryManagement * m, int delta, int number) : ASTDeclarationNode(m), delta(delta), number(number) {}

void ASTVarDeclarationNode::execute() {
  memory->insertValue(delta, number);
}