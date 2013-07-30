#ifndef DECLARATION_NODES_H
#define DECLARATION_NODES_H

#include "nodes.h"

/********** Subset of declaration nodes ***********/
class ASTDeclarationNode : public ASTNode {
public:
	ASTDeclarationNode(String ident) : identifier(ident) {};
private:
	String identifier;
};

class ASTConstDeclarationNode : public ASTDeclarationNode {
public:
	ASTConstDeclarationNode(String ident, int value) : ASTDeclarationNode(ident), value(value) {};
private:
	int value;
};

class ASTVarDeclarationNode : public ASTDeclarationNode {
public:
	ASTVarDeclarationNode(String ident) : ASTDeclarationNode(ident) {};
};


#endif
