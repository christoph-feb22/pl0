#ifndef NODES_H
#define NODES_H
#include <vector>
#typedef std::vector<ASTStatement> Statementlist;
#typedef std::vector<ASTDeclarationNode> Declarationlist;
#typedef std::vector<ASTProcedureBlockNode> ProcedureBlockList;
#typedef std::vector<ASTFactorNode> Factorlist;


/********** Set of nodes **********/
class ASTNode {};
class ASTStatementNode : public ASTNode {};
class ASTExpressionNode : public ASTNode {};

/********** Subset of declaration nodes ***********/
class ASTDeclarationNode : public ASTNode {
private:
	Declarationlist declarations;
};

class ASTConstDeclarationNode : public ASTDeclarationNode {};

class ASTVarDeclarationNode : public ASTDeclarationNode {};


/********** Subset of block nodes **********/
class ASTBlockNode : public ASTNode {
private:
	ASTConstDeclarationNode * constants;
	ASTVarDeclarationNode * variables;
	
	ProcedureBlockList procedures;

	ASTStatementNode * statement;
};

class ASTProcedureBlockNode : public ASTBlockNode {
private:
	ASTBlockNode * block;
};


/********** Subset of factor nodes **********/
class ASTFactorNode : public ASTNode {};

class ASTMultiplicationFactorNode : public ASTFactorNode {};

class ASTDivisionFactorNode : public ASTFactorNode {};


/********** Subset of term nodes **********/
class ASTTermNode : public ASTNode {};

class ASTAdditionNode : public ASTTermNode {};

class ASTSubtractionNode : public ASTTermNode {};


/********** Subset of expression nodes **********/
/********** Subset of numeric expression nodes **********/
class ASTNumericExpressionNode : public ASTExpressionNode {};

/********** Subset of boolean expression nodes (conditions) **********/
class ASTBooleanExpressionNode : public ASTExpressionNode {};

class ASTConditionNode : public ASTBooleanExpressionNode {};

class ASTOddConditionNode : public ASTConditionNode {
private:
	ASTNumericExpressionNode * exp;
};

class ASTCompareConditionNode : public ASTConditionNode {
private:
	ASTNumericExpressionNode * exp1, exp2;
};






/********** Subset of statement nodes **********/
class ASTStatementBlockNode : public ASTStatementNode {
private:
	Statementlist statements;
};

class ASTWhileLoopNode : public ASTStatementNode {
private:
	ASTConditionNode * condition;
	ASTStatementNode * statement;
};

class ASTIfNode : public ASTStatementNode {
private:
	ASTConditionNode * condition;
	ASTStatementNode * statement;
};

class ASTWriteNode : public ASTStatementNode {};

class ASTReadNode : public ASTStatementNode {};

class ASTAssignmentNode : public ASTStatementNode {
private:
	ASTNumericExpressionNode * exp;
};

class ASTFunctionCallNode : public ASTStatementNode {};




#endif
