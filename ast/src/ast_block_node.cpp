#include "../include/ast_block_node.h"

ASTBlockNode::ASTBlockNode(ConstDeclarationList * consts, VarDeclarationList * vars, ProcedureDeclarationList * procs, ASTPL0StatementNode * statement) : constants(consts), variables(vars), procedures(procs), statement(statement) {}

void ASTBlockNode::execute() {
	for(ConstDeclarationList::iterator it = constants->begin(); it != constants->end(); ++it) {
    (*it)->execute();
  }

  for(VarDeclarationList::iterator it = variables->begin(); it != variables->end(); ++it) {
    (*it)->execute();
  }

  for(ProcedureDeclarationList::iterator it = procedures->begin(); it != procedures->end(); ++it) {
    (*it)->execute();
  }

  statement->execute();
}
