#ifndef AST_PROCEDURE_CALL_NODE_H
#define AST_PROCEDURE_CALL_NODE_H

#include "ast_pl0_statement_node.h"

class ASTProcedureCallNode : public ASTPL0StatementNode {
public:
  ASTProcedureCallNode(String ident) : identifier(ident) {};
private:
  String identifier;
};

#endif