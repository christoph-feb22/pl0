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


/********** Set of nodes **********/
class ASTNode {
public:
	void execute();
};

#include "expression_nodes.h"
#include "statement_nodes.h"
#include "block_nodes.h"
#include "declaration_nodes.h"
#include "factor_nodes.h"
//#include "term_nodes.h"
#endif
