#include "statement.h"
#include "Expr.h"
#include "visitor.h"
Stmt::Stmt(int l, int c) : Node(l, c)
{

}

Stmts::Stmts(int l, int c) : Node(l, c)
{

}
Stmts::Stmts(Stmt* s, int l, int c) :
Node(l, c)
{

	this->AddStmt(s);
}

void
Stmts::AddStmt(Stmt* s)
{
	this->stmts.push_back(s);
}

returnStatement::returnStatement(int r, int c) : Stmt(r, c) {


}

returnStatement::returnStatement(Expr * ex, int type, int r, int  c) : Stmt(r, c){
	this->type = type;
	this->returnedExpr = ex;


}
//

assignStatement::assignStatement(Expr* expp, IdExpr  * iden, int l, int c) : Stmt(l, c)
{
	this->exp = expp;
	this->id = iden;

}

condStatement::condStatement(Stmt *elsStmt, Stmt * ifStmt, Expr *cond, int r, int c) :Stmt(r, c){

	this->elseBody = elsStmt;
	this->condition = cond;
	this->ifBody = ifStmt;

}

whileStatement::whileStatement(Stmt * whileStmt, Expr *cond, int r, int c) :Stmt(r, c){


	this->condition = cond;
	this->whileBody = whileStmt;

}

flowControlStatement::flowControlStatement(int t, int r, int c):Stmt (r,c){
	typeOfControl = t;
}
compoundStmt::compoundStmt(Stmts * cStmt, int r, int c) :Stmt(r, c){
	this->compStmt = cStmt;

}

variable::variable(Ident * n , int r ,int c ):Stmt (r,c){
	varName = n;
	n->father = this;

}
simpleVar::simpleVar(Expr * e , Ident * n, int r, int c ) :variable( n ,r ,c ){
	this->initValue = e;
	this->father = e;
}
arrayVar::arrayVar(Exprs * e, Ident * n, int r, int c) : variable(n, r, c){
	this->initValue = e;
	this->father = e;
}


void
variable ::accept(Visitor *v)
{
	v->Visit(this);
}

void
simpleVar::accept(Visitor *v)
{
	v->Visit(this);
}
void
arrayVar::accept(Visitor *v)
{
	v->Visit(this);
}

void
flowControlStatement::accept(Visitor *v)
{
	v->Visit(this);
}

void
condStatement::accept(Visitor *v)
{
	v->Visit(this);
}




void
Stmt::accept(Visitor *v)
{
	v->Visit(this);
}void Stmts::accept(Visitor * v){

	v->Visit(this);
}

void whileStatement::accept(Visitor * v){

	v->Visit(this);
}



void returnStatement::accept(Visitor * v){

	v->Visit(this);
}

void compoundStmt::accept(Visitor * v){

	v->Visit(this);
}



void assignStatement::accept(Visitor * v){

	v->Visit(this);
}




