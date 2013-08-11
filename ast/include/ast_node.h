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

typedef std::vector<ASTProcedureNode *> ProcedureDeclarationList;
typedef std::vector<ASTStatementNode *> StatementList;
typedef std::vector<ASTConstDeclarationNode *> ConstDeclarationList;
typedef std::vector<ASTVarDeclarationNode *> VarDeclarationList;
typedef std::vector<ASTTermNode *> TermList;
typedef std::vector<ASTFactorNode *> FactorList;


class ASTNode {
public:
	void execute();
};

#endif
