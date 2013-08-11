#ifndef AST_PROCEDURE_NODE_H
#define AST_PROCEDURE_NODE_H

#include "ast_node.h"
#include "ast_block_node.h"

class ASTProcedureNode : public ASTNode {
public:
  ASTProcedureNode(String ident, ASTBlockNode * block) : identifier(ident), block(block) {};
private:
  String identifier;
  ASTBlockNode * block;
};

#endif