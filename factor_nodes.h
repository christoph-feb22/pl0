#ifndef FACTOR_NODES_H
#define FACTOR_NODES_H

#include "nodes.h"

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

#endif
