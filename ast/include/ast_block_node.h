#ifndef AST_BLOCK_NODE_H
#define AST_BLOCK_NODE_H

#include "ast_node.h"
#include "ast_statement_node.h"

/********** Subset of block nodes **********/
class ASTBlockNode : public ASTNode {
public:
	ASTBlockNode() {};
	ASTBlockNode(ConstDeclarationList * consts, VarDeclarationList * vars, ProcedureDeclarationList * procs, ASTStatementNode * statement)
		: constants(consts), variables(vars), procedures(procs), statement(statement) {};
	void execute();
private:
	ConstDeclarationList * constants;
	VarDeclarationList * variables;

	ProcedureDeclarationList * procedures;

	ASTStatementNode * statement;
};

#endif
