#ifndef AST_DECLARATION_NODE_H
#define AST_DECLARATION_NODE_H

#include "ast_statement_node.h"

class ASTDeclarationNode : public ASTStatementNode {
public:
	ASTDeclarationNode(String ident);
  ASTDeclarationNode(MemoryManagement * m);

private:
	String identifier;
};

#endif
