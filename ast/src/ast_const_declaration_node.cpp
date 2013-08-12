#include "../include/ast_const_declaration_node.h"

ASTConstDeclarationNode::ASTConstDeclarationNode(String ident, int value) : ASTDeclarationNode(ident), value(value) {}

void ASTConstDeclarationNode::execute() {
  return;
}