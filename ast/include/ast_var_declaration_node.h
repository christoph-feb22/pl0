#ifndef AST_VAR_DECLARATION_NODE_H
#define AST_VAR_DECLARATION_NODE_H

#include "ast_declaration_node.h"

class ASTVarDeclarationNode : public ASTDeclarationNode {
public:
  ASTVarDeclarationNode(String ident) : ASTDeclarationNode(ident) {};
};

#endif