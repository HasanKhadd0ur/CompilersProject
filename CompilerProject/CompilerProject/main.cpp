#include <iostream>
#include "ast.h"
#include "printVisitor.h"
using std::cout;
using std::endl;

extern int yylex();
extern int yyparse();
extern smallc * rootProgram;


void main()
{

	yyparse();
	Visitor * printVisitor = new PrintVisitor;
	rootProgram->accept(printVisitor);
	cout << "parsing succesfuly \n";

}