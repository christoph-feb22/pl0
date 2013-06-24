#ifndef ABSTRACT_SYNTAX_TREE_H
#define ABSTRACT_SYNTAX_TREE_H

#include "abstract_syntax_tree_node.h"

class AbstractSyntaxTree
{
	public:
		AbstractSyntaxTree();
		AbstractSyntaxTreeNode getRoot();
		int insertNode(AbstractSyntaxTreeNode* parent, AbstractSyntaxTreeNode* current);
		
	private:
		AbstractSyntaxTreeNode root;
};

#endif
