#include "expression_nodes.h"

int ASTNumericExpressionNode::eval() {
	int val = 0;

	for(TermList::iterator it = terms->begin(); it != terms->end(); ++it) {
		val += (*it)->eval();
	}

	return val;
}
