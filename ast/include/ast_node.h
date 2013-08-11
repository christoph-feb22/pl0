#ifndef NODES_H
#define NODES_H

#include <string>
typedef std::string String;
#include <vector>

class ASTNumericExpressionNode;
class ASTProcedureNode;
class ASTStatementNode;
class ASTConstDeclarationNode;
class ASTVarDeclarationNode;
class ASTTermNode;
class ASTConditionNode;
class ASTFactorNode;
class ASTBlockNode;

class ASTNode {
public:
	void execute();
};

#endif
