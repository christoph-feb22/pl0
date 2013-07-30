#ifndef EXPRESSION_NODES_H
#define EXPRESSION_NODES_H

#include "nodes.h"

/********** Subset of expression nodes **********/
class ASTExpressionNode : public ASTNode {
public:
	int eval();
};

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
	int eval();
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


/********** Subset of term nodes **********/
class ASTTermNode : public ASTExpressionNode {
public:
	ASTTermNode(ASTFactorNode * factor) {
		factors = new FactorList;
		factors->push_back(factor);
	}
	void insert(ASTFactorNode * factor) {
		factors->push_back(factor);
	}
	int eval() {return 1};
private:
	FactorList * factors;
};

class ASTAdditionNode : public ASTTermNode {};

class ASTSubtractionNode : public ASTTermNode {};



#endif
