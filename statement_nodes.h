#ifndef STATEMENT_NODES_H
#define STATEMENT_NODES_H

#include "nodes.h"

/********** Subset of statement nodes **********/
class ASTStatementNode : public ASTNode {};

class ASTStatementBlockNode : public ASTStatementNode {
public:
	ASTStatementBlockNode(StatementList * statements) : statements(statements) {};
private:
	StatementList * statements;
};

class ASTConditionalStatementNode : public ASTStatementNode {
public:
	ASTConditionalStatementNode(ASTConditionNode * cond, ASTStatementNode * stat) : condition(cond), statement(stat) {};
private:
	ASTConditionNode * condition;
	ASTStatementNode * statement;
};

class ASTWhileLoopNode : public ASTConditionalStatementNode {
public:
	ASTWhileLoopNode(ASTConditionNode * cond, ASTStatementNode * stat) : ASTConditionalStatementNode(cond, stat) {};
};

class ASTIfNode : public ASTConditionalStatementNode {
public:
	ASTIfNode(ASTConditionNode * cond, ASTStatementNode * stat) : ASTConditionalStatementNode(cond, stat) {};
};

class ASTWriteNode : public ASTStatementNode {
public:
	ASTWriteNode(ASTNumericExpressionNode * exp) : expression(exp) {};
private:
	ASTNumericExpressionNode * expression;
};

class ASTReadNode : public ASTStatementNode {
public:
	ASTReadNode(String ident) : identifier(ident) {};
private:
	String identifier;
};

class ASTAssignmentNode : public ASTStatementNode {
public:
	ASTAssignmentNode(String ident, ASTNumericExpressionNode * exp) : identifier(ident), expression(exp) {};
private:
	String identifier;
	ASTNumericExpressionNode * expression;
};

class ASTProcedureCallNode : public ASTStatementNode {
public:
	ASTProcedureCallNode(String ident) : identifier(ident) {};
private:
	String identifier;
};


#endif
