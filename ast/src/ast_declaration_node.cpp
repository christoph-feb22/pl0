#include "../include/ast_declaration_node.h"

ASTDeclarationNode::ASTDeclarationNode(String ident) : identifier(ident) {}

ASTDeclarationNode::ASTDeclarationNode(MemoryManagement * m) : ASTStatementNode(m) {}