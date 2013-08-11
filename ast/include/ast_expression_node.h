#ifndef AST_EXPRESSION_NODE_H
#define AST_EXPRESSION_NODE_H

#include "ast_node.h"

class ASTExpressionNode : public ASTNode {
public:
	int eval();
};

#endif
