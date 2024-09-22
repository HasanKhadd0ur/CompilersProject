#ifndef VISITOR_H 
#define VISITOR_H
#include "ast.h"
#include "statement.h"
class Visitor
{
public:
	virtual void Visit(Node *) = 0;
	virtual void Visit(Func *) = 0;
	virtual void Visit(smallc  *) = 0;
	virtual void Visit(Ident  *) = 0;
	virtual void Visit(variableDecl *) = 0;
	virtual void Visit(ClassDecl *) = 0;

	virtual void Visit(Args * n) =0;

	virtual void Visit(Arg *) = 0;
	virtual void Visit(Stmt *) = 0;
	virtual void Visit(Stmts *) = 0;

	virtual void Visit(arrayVar  * n) = 0;
	virtual void Visit(simpleVar  * n) = 0;


	virtual void Visit(whileStatement  * n) = 0;
	virtual void Visit(Exprs * n  )=0 ;
	virtual void Visit(condStatement   * n) = 0;
	virtual void Visit(returnStatement  * n) =0 ;
	virtual void Visit(compoundStmt  * n) = 0;
	virtual void Visit(assignStatement  * n) = 0;

	virtual void Visit(IdExpr  *)=0;

	virtual void Visit(arrayExpr  *) = 0;
	virtual void Visit(Val  *) = 0;
	virtual void Visit(unOperatExp  *) = 0;
	virtual void Visit(funcCallExpr  *) = 0;
	virtual void Visit(tripleExpr  *) = 0;
};


#endif;