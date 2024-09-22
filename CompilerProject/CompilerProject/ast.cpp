#include "ast.h"
#include "statement.h"
#include "Expr.h"
#include "visitor.h"
// string typesName[] = { "int", "String ", "char", "bool" ,"float","Null","cnstr"};

int typeOf[] = { 0, 1, 2, 3, 4, 5, 6, 7 };

Node::Node(int line, int column)
{
	this->line = line;
	this->column = column;
	this->father = NULL;
}

Func::Func(int t, Ident* n, Args* as, Stmts * ss, int l, int c) : Node(l, c)
{
	this->type = t;
	this->name = n;
	this->args = as;
	this->stmts = ss;
	
	this->name->father = this;
	this->args->father = this;
	this->stmts->father = this;
    

	

}

variableDecl::variableDecl(int t, int r, int c) :Stmt(r, c){

	type = t;
}

Arg::Arg(int t, Ident* n, int l, int c): Node(l, c)
{
	this->type = t;
	this->name = n;
	this->name->father = this;
}

Args::Args(int l, int c) : Node(l, c)
{

}
Args::Args(Arg* a, int l, int c) : Node(l, c)
{

	a->father = this;
	this->AddArg(a);
	
}
void  Args::AddArg(Arg* a)
{
	this->args.push_back(a);
	a->father = this;
}


ClassDecl::ClassDecl(Ident * name,int r, int c) :Node(r, c){

	this->className = name;
	this->className->father = this; 
}


Ident::Ident(char * v, int l, int c) : Node(l, c)
{
	this->value = v;

}






void ClassDecl::addMethods(vector <Func * > f ){

	for (int i = 0; i < f.size(); i++){

		this->methods.push_back(f[i]);
		f[i]->father = this;
	}
}
void ClassDecl::addConstructors(vector <Func * > f){

	for (int i = 0; i < f.size(); i++){

		this->constructors.push_back(f[i]);
		f[i]->father = this;
	}
}
void ClassDecl::addProps(vector <variableDecl * > f ){

	for (int i = 0; i < f.size(); i++){

		this->props.push_back(f[i]);
		f[i]->father = this;
	}
}
smallc::smallc(int r, int c) :Node(r, c){

}
smallc:: smallc(Func * f, int r, int c) :Node(r, c){

	programFunc.push_back(f);
	f->father = this;
}

void smallc::addGlobalVar(variableDecl * v ){
	this->globalVar.push_back(v);
	v->father = this;

}
void smallc::addprogramClasses(ClassDecl *v){
	this->programClasses.push_back(v);
	v->father = this;

}
void smallc::addprogramFunc(Func * v){
	this->programFunc.push_back(v);
	v->father = this;

}

void
Node::accept(Visitor *v)
{
	v->Visit(this);
}

void
Func::accept(Visitor *v)
{
	v->Visit(this);
}
void
Arg::accept(Visitor *v)
{
	v->Visit(this);
}
void Args::accept(Visitor *v)
{
	v->Visit(this);
}
void
Ident::accept(Visitor *v)
{
	v->Visit(this);
}




void
ClassDecl::accept(Visitor *v)
{
	v->Visit(this);
}

void
variableDecl::accept(Visitor *v)
{
	v->Visit(this);
}void smallc::accept(Visitor * v){

	v->Visit(this);
}

