#ifndef EXPR_H 
#define EXPR_H

#include "ast.h"

class Expr : public Node
{
public:
	int t;
	Expr(int, int);
	Expr(int, int, int);

};

// identifier expression 
class IdExpr : public Expr
{
public:
	Ident  * id;
	IdExpr(int, int);
	IdExpr(Ident *, int, int);
	virtual void accept(Visitor * );

};





class Val :public Expr {
public:
	char * vString;
	char vChar;
	int vInt;
	double  vDouble;
	int vtype;

	bool vBool;


	virtual void accept(Visitor * );
	Val(char, int, int);
	Val(char *, int, int);
	Val(int, int, int);
	Val(double, int, int);
	Val(int, int);
	Val(bool, int, int);

};

class Exprs : public Node
{
public:
	vector<Expr* > exprs;
	Exprs(Expr*, int, int);
	void AddExpr(Expr*);
	Exprs(int, int);
	virtual void accept(Visitor *);

};

class unOperatExp :public Expr {
public:
	Expr * left;
	Expr * right;
	int opc;
	unOperatExp(Expr *, Expr*, int, int, int);

	virtual void accept(Visitor *);

};
// value def 
// 
class tripleExpr :public Expr {
public:
	Expr * cond;
	Expr *  ifExpr;
	Expr * elseExpr;
	tripleExpr(Expr *, Expr *, Expr *, int, int);

	virtual void accept(Visitor *);

};

class funcCallExpr :public Expr {
public:
	Ident * fname;
	Exprs * paramList;


	funcCallExpr(Ident *, Exprs *, int, int);

	virtual void accept(Visitor *);
};

class arrayExpr :public IdExpr {
	public :
	Expr * inde;
	arrayExpr(Expr *  ,Ident * ,int , int );
	virtual void accept(Visitor*  );
};
#endif ;