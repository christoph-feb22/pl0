#include "../include/ast_block_node.h"

ASTBlockNode::ASTBlockNode(ConstDeclarationList * consts, VarDeclarationList * vars, ProcedureDeclarationList * procs, ASTPL0StatementNode * statement, MemoryManagement * memory, int level) : ASTStatementNode(memory), constants(consts), variables(vars), procedures(procs), statement(statement), level(level) {}

void ASTBlockNode::setLevel(int l) {
  level = l;
}

void ASTBlockNode::execute() {
  execute(level);
}

void ASTBlockNode::execute(int call_level) {
  int number_of_vars = 0;

  if(constants) {
    for(int i = 0; i < constants->size(); i++) {
      constants->at(i)->execute();
    }
  }

  if(variables) {
    // create new memory segment
    number_of_vars = variables->size();
    memory->newMemorySegment(call_level, number_of_vars);

    for(int i = 0; i < variables->size(); i++) {
      variables->at(i)->execute();
    }
  }
  else {
    memory->newMemorySegment(call_level, number_of_vars);
  }

  // if(procedures) {
  // }

  statement->execute();

  // delete allocated memory
  memory->deleteMemorySegment(number_of_vars);
}
