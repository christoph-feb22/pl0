#ifndef AST_DECLARATION_NODE_H
#define AST_DECLARATION_NODE_H

#include "ast_node.h"

/********** Subset of declaration nodes ***********/
class ASTDeclarationNode : public ASTNode {
public:
	ASTDeclarationNode(String ident) : identifier(ident) {};
private:
	String identifier;
};

#endif
