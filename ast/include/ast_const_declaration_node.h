#ifndef AST_CONST_DECLARATION_NODE_H
#define AST_CONST_DECLARATION_NODE_H

#include "ast_declaration_node.h"

class ASTConstDeclarationNode : public ASTDeclarationNode {
public:
  ASTConstDeclarationNode(String ident, int value) : ASTDeclarationNode(ident), value(value) {};
private:
  int value;
};

typedef std::vector<ASTConstDeclarationNode *> ConstDeclarationList;

#endif