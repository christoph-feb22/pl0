#ifndef AST_PROCEDURE_CALL_NODE_H
#define AST_PROCEDURE_CALL_NODE_H

#include "ast_pl0_statement_node.h"
#include "ast_procedure_node.h"

class ASTProcedureCallNode : public ASTPL0StatementNode {
public:
  ASTProcedureCallNode(ASTProcedureNode *);
  void execute();

private:
  ASTProcedureNode * procedure;
};

#endif