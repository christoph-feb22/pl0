#include "../include/ast_block_node.h"

ASTBlockNode::ASTBlockNode(ConstDeclarationList * consts, VarDeclarationList * vars, ProcedureDeclarationList * procs, ASTPL0StatementNode * statement) : constants(consts), variables(vars), procedures(procs), statement(statement) {}

void ASTBlockNode::execute() {
  if(constants) {
    for(int i = 0; i < constants->size(); i++) {
      constants->at(i)->execute();
    }
  }

  if(variables) {
    for(int i = 0; i < variables->size(); i++) {
      variables->at(i)->execute();
    }
  }

  if(procedures) {
    for(int i = 0; i < procedures->size(); i++) {
      procedures->at(i)->execute();
    }
  }

  statement->execute();
}
