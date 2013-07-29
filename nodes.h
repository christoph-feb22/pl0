#ifndef NODES_H
#define NODES_H
#include <string>
typedef std::string String;
#include <vector>

class ASTNumericExpressionNode;
class ASTProcedureNode;

typedef std::vector<ASTProcedureNode *> ProcedureDeclarationList;

/********** Set of nodes **********/
class ASTNode {};

class ASTStatementNode : public ASTNode {};
typedef std::vector<ASTStatementNode *> StatementList;

class ASTExpressionNode : public ASTNode {};


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

typedef std::vector<ASTConstDeclarationNode *> ConstDeclarationList;
typedef std::vector<ASTVarDeclarationNode *> VarDeclarationList;


/********** Subset of block nodes **********/
class ASTBlockNode : public ASTNode {
public:
	ASTBlockNode() {};
	ASTBlockNode(ConstDeclarationList * consts, VarDeclarationList * vars, ProcedureDeclarationList * procs, ASTStatementNode * statement)
		: constants(consts), variables(vars), procedures(procs), statement(statement) {};
	void run();
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


/********** Subset of factor nodes **********/
class ASTFactorNode : public ASTNode {
public:
	ASTFactorNode(String ident) : identifier(ident) {};
	ASTFactorNode(int val) : value(val) {};
	ASTFactorNode(ASTNumericExpressionNode * exp) : expression(exp) {};
private:
	String identifier;
	int value;
	ASTNumericExpressionNode * expression;
};
typedef std::vector<ASTFactorNode *> FactorList;

class ASTMultiplicationFactorNode : public ASTFactorNode {};

class ASTDivisionFactorNode : public ASTFactorNode {};

/********** Subset of term nodes **********/
class ASTTermNode : public ASTNode {
public:
	ASTTermNode(ASTFactorNode * factor) {
		factors = new FactorList;
		factors->push_back(factor);
	}
	void insert(ASTFactorNode * factor) {
		factors->push_back(factor);
	}
private:
	FactorList * factors;
};
typedef std::vector<ASTTermNode *> TermList;

class ASTAdditionNode : public ASTTermNode {};

class ASTSubtractionNode : public ASTTermNode {};


/********** Subset of expression nodes **********/
/********** Subset of numeric expression nodes **********/
class ASTNumericExpressionNode : public ASTExpressionNode {
public:
	ASTNumericExpressionNode(ASTTermNode * term) {
		terms = new TermList;
		terms->push_back(term);
	}
	void insert(ASTTermNode * term) {
		terms->push_back(term);
	}
private:
	TermList * terms;
};

/********** Subset of boolean expression nodes (conditions) **********/
class ASTBooleanExpressionNode : public ASTExpressionNode {};

class ASTConditionNode : public ASTBooleanExpressionNode {};

class ASTOddConditionNode : public ASTConditionNode {
public:
	ASTOddConditionNode(ASTNumericExpressionNode * exp) : expression(exp) {};
private:
	ASTNumericExpressionNode * expression;
};

class ASTCompareConditionNode : public ASTConditionNode {
public:
	ASTCompareConditionNode(ASTNumericExpressionNode * exp1, ASTNumericExpressionNode * exp2) : expression_l(exp1), expression_r(exp2) {};
private:
	ASTNumericExpressionNode * expression_l, * expression_r;
};


/********** Subset of statement nodes **********/
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
