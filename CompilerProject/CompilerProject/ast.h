#ifndef AST_H
#define AST_H

#include <iostream>
using std::cout;

#include <vector>

using std::vector;
using std::pair;
#include <string>
using std::string;

class Node;
class Func;
class Ident;
class Args;
class Stmts;
class Stmt;
class Arg;
class Visitor;

class variableDecl;

enum type  { Int = 0, String = 1, Char = 2, Bool = 3, Float = 4, NLLL = 5, constructor  =6};



// class node 
class Node
{
public:
	int line;
	int column;
	Node* father;
	Node(int, int);

	virtual void accept(Visitor *v);
};



// class identifier 
class Ident : public Node
{
public:
	string   value;
	Ident(char *, int, int);
	virtual void accept(Visitor *v);



};

// class Function  contain   (returned  type , function name , parameter  list, statements )      
class Func : public Node
{
public:
	int type;
	Ident* name;
	Args* args;
	Stmts *  stmts;

	virtual void accept(Visitor *v);


	Func(int, Ident*, Args*, Stmts *, int,
		int);
};

//class argument (standard_type  Ident    )
class Arg : public Node

{
public:
	int type;
	Ident* name;
	Arg(int, Ident*, int, int);
	virtual void accept(Visitor *v);



};


class Args : public Node
{
public:
	vector<Arg* > args;
	Args(int, int);
	Args(Arg*, int, int);
	void AddArg(Arg*);
	virtual void accept(Visitor *v);



};


class members {

public : 
	vector<variableDecl * >props;
	vector<Func * >method; 
	vector <Func * >constructor;
	/*
	members(vector<variableDecl * >, vector<Func * >, vector<Func * >);
	
	*/
};


//class for defineing a like java class    
// contain :
//        (1) vector of   variable declartion  refers to (class attributes )
//        (2) vector of functions to refers to  (the class method)
//        (3) vedctor of contrucors  
class ClassDecl :public Node  {

		public :
			vector<variableDecl * >props;
			vector<Func * >methods;
			vector <Func * >constructors;

			Ident * className ;

			ClassDecl(Ident * , int, int);

			void addMethods( vector <Func * > );
			void addConstructors(vector <Func * >);
			void addProps(vector <variableDecl * >);

			virtual void accept(Visitor *v);
};





class smallc :Node {

public:
	vector <Func *>  programFunc;

	vector <variableDecl *  >globalVar;
	vector <ClassDecl * > programClasses;
	virtual void accept(Visitor * v);

	void addGlobalVar(variableDecl *);
	void addprogramClasses(ClassDecl * );
	void addprogramFunc(Func * );
	smallc(int , int );

	smallc(Func * , int , int );


};

#endif 