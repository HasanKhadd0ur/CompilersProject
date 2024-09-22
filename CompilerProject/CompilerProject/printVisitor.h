#ifndef PRINTVISITOR_H
#define PRINTVISITOR_H
#include "visitor.h" 
class PrintVisitor : public Visitor
{
public:
	virtual void Visit(Node *n){}


	virtual void Visit(smallc * n);


	virtual void Visit(Func * n);
	virtual void Visit(Args * n);

	virtual void Visit(Exprs * n) ;
	virtual void Visit(Arg * n);
	virtual void Visit(arrayVar  * n) ;
	virtual void Visit(simpleVar  * n) ;


	virtual void Visit(variableDecl * n);

	virtual void Visit(ClassDecl * n);

	virtual void Visit(Stmt * n);
	virtual void Visit(Stmts * n);

	virtual void Visit(whileStatement  * n);

	virtual void Visit(unOperatExp  *) ;

	virtual void Visit(funcCallExpr  *) ;
	virtual void Visit(tripleExpr  *) ;

	virtual void Visit(condStatement   * n);

	virtual void Visit(returnStatement  * n) ;

	virtual void Visit(compoundStmt  * n);
	virtual void Visit(assignStatement  * n) ;

	virtual void Visit(Ident  *);
	virtual void Visit(IdExpr  *);

	virtual void Visit(arrayExpr  *) ;
	virtual void Visit(Val *) ;
};

#endif;