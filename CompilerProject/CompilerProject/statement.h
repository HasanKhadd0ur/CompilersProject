#ifndef STATEMENT_H
#define STATEMENT_H
#include "ast.h"
class Expr;
#include "Expr.h"

class Stmt : public Node
{
public:

	Stmt(int, int);

	virtual void accept(Visitor *v);

};

class Stmts : public Node
{
public:
	vector <Stmt* > stmts;
	Stmts(int, int);
	Stmts(Stmt*, int, int);
	void AddStmt(Stmt*);

	virtual void accept(Visitor *v);


};


class compoundStmt : public Stmt
{
public:
	Stmts *   compStmt;
	compoundStmt(Stmts *, int, int);


	virtual void accept(Visitor *v);
};

class variable : public Stmt {
	public :
	Ident * varName;
	variable(Ident * ,int ,int );

	virtual void accept(Visitor *v);
};

class simpleVar : public variable {
public :
	Expr  * initValue;
	simpleVar(Expr *, Ident *, int, int);

	virtual void accept(Visitor *v);
};


class arrayVar : public variable {
public :
	Exprs    * initValue;
	arrayVar(Exprs *, Ident *, int, int);

	virtual void accept(Visitor *v);
};
class variableDecl :public Stmt{
public:
	int type;
	vector < variable *  >  names;
	variableDecl(int, int, int);

	virtual void accept(Visitor *v);
};



class assignStatement : public Stmt
{
public:
	IdExpr * id;
	Expr * exp;
	assignStatement(Expr*, IdExpr  *, int, int);

	virtual void accept(Visitor *v);
};


class condStatement :public Stmt {
public:
	Expr * condition;
	Stmt * ifBody;
	Stmt * elseBody;

	virtual void accept(Visitor *);

	condStatement(Stmt *, Stmt *, Expr *, int, int);
};

class whileStatement :public Stmt {
public:
	Expr * condition;
	Stmt * whileBody;


	virtual void accept(Visitor *);
	whileStatement(Stmt*, Expr *, int, int);
};


class returnStatement :public Stmt {
public:
	int type;
	Expr * returnedExpr;
	returnStatement(int, int);
	returnStatement(Expr *, int, int, int);

	virtual void accept(Visitor *v);

};

//class refers to breack and continue statments  
//      (1) int typeOFControl (1  => mean continue , 2 => mean break )
class flowControlStatement :public Stmt {
public :
	int typeOfControl;
	flowControlStatement(int,  int , int );
	virtual void accept(Visitor *v);

};

#endif;
