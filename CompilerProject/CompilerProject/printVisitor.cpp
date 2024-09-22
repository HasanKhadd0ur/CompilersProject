#include "printVisitor.h"
#include "statement.h"
 string  typesName[] = { "int", "String ", "char", "bool", "float", "Null", "cnstr" };
 string operation[] = {"plus" ,"minus","Mul","div","greater", "smaler","greater or equal ","smaler or equal ", "is equal " , "not equal" , "or" , "and"};




///////////////////////// Print Visitor ////////


void PrintVisitor::Visit(smallc * n)
{

	cout << "smallc \n";
	cout << "----global variable ( " << n->globalVar.size() << " )\n";
	for (int i = 0; i < n->globalVar.size(); i++){
		cout << "----";
		(n->globalVar[i])->accept(this);
		cout << "\n";
	}
	cout << "----functions ( " << n->programFunc.size() << " )\n";
	for (int i = 0; i < n->programFunc.size(); i++){
		cout << "----";
		(n->programFunc[i])->accept(this);
		cout << "\n";
	}
	cout << "----classes ( " << n->programClasses.size() << " )\n";

	for (int i = 0; i < n->programClasses.size(); i++){
		cout << "----";
		(n->programClasses[i])->accept(this);
		cout << "\n";
	}
}
void  PrintVisitor::Visit(Func * n){

	cout << "func name " << n->name->value << "\n";
	cout << "----@returned type " << typesName[n->type] << "\n";
	cout << "----@arugument :  ";
	if (n->args->args.size() == 0){
		cout << "empty ";
	}
	for (int i = 0; i < n->args->args.size(); i++){
		
		(n->args->args[i])->accept(this);
		if(i +1 <n->args->args.size())cout << ", ";

	}
	cout << "\n";
	(n->stmts)->accept(this);


}
void PrintVisitor::Visit(variableDecl * n){
	if (n->names.size() == 1){
		cout << " ( ";
		n->names[0]->accept(this);
	}
	else {
		cout << "---- variables  decl  (  ";
		for (int i = 0; i < n->names.size(); i++){
			n->names[i]->accept(this);
			if (i + 1 < n->names.size())cout << " ,  ";

		}
	}
	cout << " ) of type " << typesName[n->type];
}
void PrintVisitor::Visit(ClassDecl * n){
	{

		cout << "----class  " << n->className->value << "\n";
		cout << "--------functions ( "<<n->methods.size() <<" )\n";
		for (int i = 0; i < n->methods.size(); i++){
			cout << "--------";
			n->methods[i]->accept(this);
			cout << "";
		}
		cout << "--------Constructors  ( " << n->constructors.size() << " )\n";
		for (int i = 0; i < n->constructors.size(); i++){
			cout << "--------";
			n->constructors[i]->accept(this);
			cout << "\n";
		}

	}
}
void PrintVisitor::Visit(Stmt *n) {


}
void PrintVisitor::Visit(Stmts *n) {


	for (int i = 0; i < n->stmts.size(); i++){
		cout << "---- stmt " << i << " ";
		n->stmts[i]->accept(this);
		cout << "\n";
	}
}

void PrintVisitor::Visit(Ident *n) {

	cout << "Ident ( " << n->value <<" ) ";
}

void PrintVisitor::Visit(IdExpr *n) {

	cout << "Ident ( " << n->id->value << " ) ";
}

void PrintVisitor::Visit(arrayExpr *n) {


	cout << "array call  ( " << n->id->value << " ) ";
}
void  PrintVisitor::Visit(whileStatement  * n){
	cout << "---- while statement ";
	n->whileBody->accept(this);
	cout << "\n";



}
void PrintVisitor::Visit(condStatement   * n) {
	cout << "---- if statement  @condtion (  ";
	n->condition->accept(this);
	cout << " )\n@statement intrue case  \n ";
	
	n->ifBody->accept(this);

	


}



void PrintVisitor::Visit(returnStatement * n){

	cout << "---- return statement   of ( ";

	n->returnedExpr->accept(this);
	cout << " ) ";



}
void PrintVisitor::Visit(Val  * n){

	cout << " value   ";
	
	if (n->vtype == 1){
		cout <<" ( "<< n->vInt<<" ) ";

	}
	if (n->vtype == 2){
		cout << " ( " << n->vString<<" ) ";

	}
	if (n->vtype == 3){
		cout << " ( " << n->vChar << " ) ";

	}
	if (n->vtype == 4){
		cout << " ( " << n->vDouble << " ) ";

	}
	if (n->vtype == 5){
		cout << " ( " << n->vBool << " ) ";

	}

	/*
	for (int i = 0; i < 5; i++){

		if (i == n->t){
		//	cout << "of type " << a[i];
			break;
		}
	}

	*/


}


 void PrintVisitor::Visit(unOperatExp  *n ) {
	 cout << " operation  "<<operation[n->opc]<<"( left ";
	 n->left->accept(this)  ;
	 cout << " , right  "; 
	 n->right->accept(this);
	 cout << " ) ";


}
void PrintVisitor::Visit(assignStatement  * n) {
	cout << "---- assigne statement  (  left side ";
	n->id->accept(this);
	

	cout << "  ,  right side ";
	n->exp->accept(this);
	cout << " ) ";
}
void PrintVisitor::Visit(compoundStmt  * n) {

	cout << "---- compound Statement   started compound statement at line " << n->line<<"\n";
	n->compStmt->accept(this);
	cout << "---- ended compound statement  \n";




}


void PrintVisitor::Visit(funcCallExpr  *n) {
	cout << "calling function " << n->fname->value;
	if (n->paramList->exprs.size() != 0)
	{
		cout << "  @expresssion list   (  ";

		n->paramList->accept(this);
		cout << " ) ";
	}
else
cout << "   ";

}
void PrintVisitor::Visit(tripleExpr  * n) {
	cout << "triple expresion ";
	cout << " @condtion  ( ";
	n->cond->accept(this);
	cout << " ) ";

	cout << "@if expr is ture ( ";
	n->ifExpr->accept(this);
	cout << " ) ";


	cout << "@if expr is false (  ";
	n->elseExpr->accept(this);
	cout << " ) ";
}

void PrintVisitor::Visit(Arg * n ){
	cout << "arg  name   " << n->name->value << " of type " << typesName[n->type] ;

}
void PrintVisitor::Visit(Args * n){
	
	cout << " @params (  ";
	for (int i = 0; i < n->args.size(); i++){
		n->args[i]->accept(this);
		cout << " ,  ";
	}
	cout << " ) ";

}

void PrintVisitor::Visit(arrayVar  * n) {
	cout << "array " << " (  " << n->varName->value << " )";
	if (n->initValue != NULL){
		cout << "  <== initial values [ ";
		for (int i = 0; i < n->initValue->exprs.size(); i++){
			n->initValue->exprs[i]->accept(this);
			if (i < n->initValue->exprs.size() - 1)cout << ", ";
		}
		cout << " ] ";
	}
}
void PrintVisitor::Visit(simpleVar  * n) {
	cout << "var  " << " (  " << n->varName->value << " )  <== initial values " ;
	if (n->initValue!= NULL )
	n->initValue->accept(this );
	

}

void PrintVisitor::Visit(Exprs   * n) {

	for (int i = 0; i < (n->exprs.size()) ; i++){
		n->exprs[i]->accept(this);
		if (i <( n->exprs.size() - 1) )cout << ", ";

	}

}

