#ifndef BLOCK_NODES_H
#define BLOCK_NODES_H

#include "nodes.h"

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


class ASTProcedureNode : public ASTNode {
public:
	ASTProcedureNode(String ident, ASTBlockNode * block) : identifier(ident), block(block) {};
private:
	String identifier;
	ASTBlockNode * block;
};

#endif
