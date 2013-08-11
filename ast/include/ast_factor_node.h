#ifndef FACTOR_NODES_H
#define FACTOR_NODES_H

#include "ast_expression_node.h"
#include "ast_numeric_expression_node.h"

class ASTFactorNode : public ASTExpressionNode {
public:
	ASTFactorNode(String ident) : identifier(ident) {};
	ASTFactorNode(int val) : value(val) {};
	ASTFactorNode(ASTNumericExpressionNode * exp) : expression(exp) {};

private:
	String identifier;
	int value;
	ASTNumericExpressionNode * expression;
};

#endif
