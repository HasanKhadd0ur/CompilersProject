#include "Expr.h"
#include "visitor.h"


//

Expr::Expr(int l, int c) : Node(l, c)
{
	this->t = -1;
}

Expr::Expr(int t, int l, int c) : Node(l, c)
{
	this->t = t;
}

Val::Val(char s, int r, int c) :Expr(r, c)
{
	type a;
	a = Char;
	this->vtype = 3;
	this->vChar = s;


}

Val::Val(char * s, int r, int c) :Expr(r, c)
{
	type a;
	a = String;
	this->vtype = 2;
	this->vString = s;


}
Val::Val(int s, int r, int c) :Expr(r, c)
{
	type a;
	a = Int;
	this->vtype = 1;
	this->vInt = s;


}
Val::Val(double  s, int r, int c) :Expr(r, c)
{
	type a;
	a = Float;
	this->vtype = 4;
	this->vDouble = s;


}
Val::Val(bool  s, int r, int c) :Expr(r, c)
{
	type a;
	a = Bool;
	this->vtype = 5;
	this->vBool = s;


}
IdExpr::IdExpr(int r, int c) :Expr(r, c){

}

IdExpr::IdExpr(Ident * id, int r, int c) : Expr(r, c){
	this->id = id;
	id->father = this;
}

tripleExpr::tripleExpr(Expr * cond, Expr * ifExp, Expr * elseExp, int r, int  c) : Expr(r, c){
	this->elseExpr = elseExp;
	this->cond = cond;
	this->ifExpr = ifExp;
	ifExp->father = this;
	elseExp->father = this;
	cond->father = this;


}
funcCallExpr::funcCallExpr(Ident * f, Exprs * arg, int r, int c) :Expr(r, c){
	this->fname = f;
	this->paramList = arg;
	f->father = this;
	arg->father = this;

}

void Exprs::AddExpr(Expr *e){

	this->exprs.push_back(e);
	e->father = this;
}
Exprs::Exprs(Expr * e, int r, int c) :Node(r, c){
	this->exprs.push_back(e);
	e->father = this;
}
Exprs::Exprs(int r, int c) : Node(r, c){

}
unOperatExp::unOperatExp(Expr * l, Expr* ri, int op, int r, int c) : Expr(r, c){
	this->left = l;
	this->right = ri;
	this->opc = op;
	l->father = this;
	ri->father = this;

}

arrayExpr::arrayExpr(Expr * i ,Ident * n , int r ,int c ):IdExpr(n,r,c){
	inde = i;
	if (i != NULL) {
		i->father = this;
	}

}

void IdExpr::accept(Visitor * v ) {
	v->Visit(this);
}



void unOperatExp::accept(Visitor * v) {
	v->Visit(this);
}

void tripleExpr::accept(Visitor * v) {
	v->Visit(this);
}

void funcCallExpr::accept(Visitor * v) {
	v->Visit(this);
}


void Val::accept(Visitor * v) {
	v->Visit(this);
}


void arrayExpr::accept(Visitor * v) {
	v->Visit(this);
}


void Exprs::accept(Visitor *v  ){
	v->Visit(this);

}