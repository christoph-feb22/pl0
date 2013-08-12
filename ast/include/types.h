#include <vector>

class ASTConstDeclarationNode;
class ASTFactorNode;
class ASTPL0StatementNode;
class ASTProcedureNode;
class ASTTermNode;
class ASTVarDeclarationNode;
class ASTBlockNode;
class ASTConditionNode;
class ASTNumericExpressionNode;


typedef std::vector<ASTConstDeclarationNode *> ConstDeclarationList;
typedef std::vector<ASTFactorNode *> FactorList;
typedef std::vector<ASTPL0StatementNode *> StatementList;
typedef std::vector<ASTProcedureNode *> ProcedureDeclarationList;
typedef std::vector<ASTTermNode *> TermList;
typedef std::vector<ASTVarDeclarationNode *> VarDeclarationList;
