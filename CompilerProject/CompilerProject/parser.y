%{

	#include<iostream>
	#include "ast.h"
	#include "statement.h"
	#include "Expr.h"
	using std::cout;
	using std::endl;
	extern int yyerror(const char*);
	extern int yylex();
	extern int yydebug;
	extern int Row;
	extern type a ;
	// Before Reading Token
	extern int LeftCursor;

	// After Reading Token
	extern int RightCursor;
	// the col tracer 
	extern int col ;
    Func * func;
	smallc  * rootProgram; 
	

	


%}

%union{
	Func *tFunc;
	Args *tArgs;
	Arg *tArg;
	
	Expr *tExpr;
	
	Exprs *tExprs;
	tripleExpr *  triple ;
	funcCallExpr * tcFunc ;
	int  tInt;
	Stmts *tStmts;
	Stmt *tStmt;
	assignStatement * tasStmt;
	condStatement *tcon ;
	whileStatement *twhile ;
	compoundStmt  * tcStmt ;
	Val *tVal;
	smallc * tsmallc ;
	variable *   tp ;
	IdExpr *tIdExpr;
	Ident *tIdent;
	variableDecl *tvDecl;
	unOperatExp * tOP ;
	ClassDecl * tClassDecl;
	members * tmembers;

}

%type <tsmallc> smalc_program 
%type <tasStmt> assignStatement
%type <tcon>   cond_stmt
%type <twhile> while_stmt
%type <tcStmt>  compound_statement

%type <tp> variable_id
%type <tClassDecl> class_dec
%type <tmembers>  members 
%type <tvDecl> var_decl var_decl_list
%type <tFunc> func constructor
%type <tArgs> args arg_e
%type <tArg> arg
%type <tInt> standard_type

%type <tExpr> value expression   
%type <tExprs> valueList 

%type <tExprs>   expression_list
%type <triple>  tripleCondition
%type <tInt> unary_operator

%type <tStmts> stmts 
%type <tStmt> statement
%type <tIdExpr> variable 
%token <tIdent> IDENT 

%token <tVal> INTNUM  STRINGCONST   CHARCONST  NULLL FALSE TRUE REALNUM



%token IF
%token    OR
%token DIV  AND  MUL 
%token   ELSE  
%token    WHILE

%token INT FLOAT  BOOL CHAR STRING  CLASS

%token GREATER SMALLER 

%token  ISEQUAL NOTEQUAL 

%token BREAK CONTINUE RETURN



%left OR
%left AND
%left '!'
%left '=' NOTEQUAL
%left '<' GREATER '>' SMALLER



%left  '-' '+'
%left MUL DIV

%nonassoc IF_PREC '?'
%nonassoc ELSE ':' ISEQUAL


%nonassoc CONFLICTSOLUTION 





%%

// Start State
// the c program should start with declaring a function  or a variable or define a class 

smalc_program:		smalc_program	 func    {
												$$->addprogramFunc($2);
												rootProgram=$$;
											}
					
									

			|	    smalc_program  var_decl  {
											    
												
												$$->addGlobalVar($2);
												rootProgram=$$;
											}



			|		smalc_program class_dec  {
			
											
												$$->addprogramClasses($2);	
												rootProgram=$$;
											}
												


			|	    /*empty */				 {

					                           $$= new smallc (Row ,col);
											   rootProgram =$$;
											  }



;


// class declaration 
// like class myClass {/*some statments or functions  or constructor  */}
// the member are ethier a :
//                        1- a function (method)
//						  2- a constructor 
//					      3- a variables  


class_dec: CLASS IDENT '{' members   '}'  {
                                           $$= new ClassDecl($2,Row,col);
										

										   $$->addMethods($4->method);
										   $$->addConstructors($4->constructor);
										   $$->addProps($4->props);


										  }


// define a rule for the member of the class 

members:		 members func   {
									$$->method.push_back($2);
                                }

		|		 members var_decl {
									$$->props.push_back($2);
								}
		|		members constructor {
										$$->constructor.push_back($2);
									}

		|		 /*empty */ {
									
									$$=new members();
		                   }
;


// a rule for the constructor 
constructor: IDENT '(' arg_e ')'  compound_statement  {
														$$= new Func(6,$1 , $3 , $5->compStmt ,Row ,col );
													  }
;


//1

// Defining different unary  operaters
unary_operator:		'+'  {
                           $$=0;
						   }
			 |		 '-'  {
                           $$=1;
						   }
			 |		 MUL {
                           $$=2;
						   }
			 |		 DIV  {
                           $$=3;
						   }
			 |		 '>'  {
                           $$=4;
						   }
			 |		 '<' {
                           $$=5;
						   }
			 |		 GREATER {
                           $$=6;
						   } 
			 |		 SMALLER {
                           $$=7;
						   } 
			 |		 ISEQUAL {
                           $$=8;
						   }

			 |		 NOTEQUAL {
                           $$=9;
						   } 

			 |		 OR  {
                           $$=10;
						   }
			 |		 AND {
                           $$=11;
						   }
;



// Defining  a block level statement   { statements }

compound_statement:	'{' stmts '}'  {
									 $$=new compoundStmt ($2 ,Row ,col );
								 }
				   
;


// a rule for deining the  fuction  

func: standard_type  IDENT '(' arg_e ')'  compound_statement 
		{
			$$ = new Func($1, $2, $4, $6->compStmt, Row, col);
		

		}
										


;


//declaring a variables 

var_decl: standard_type var_decl_list ';'  {  
									
                                              $2->type=$1;
											  $$=$2;

											  

									 }

;


var_decl_list:       variable_id    {   
                                                $$=new variableDecl(1 ,Row,col);
												$$->names.push_back( $1);

                                        }
 |					  var_decl_list   ','	variable_id    {
                                                   $1->names.push_back( $3);
												   $$=$1;
                                                   }
 ;	


//rule for defining the variables name and assig a initial value 
// and assign the init values of the array like  a [] ={1,2,3 }.. 

variable_id:		 IDENT     {
                                 $$= new simpleVar (NULL,$1 ,Row ,col ) ;
								 } 


		  |			IDENT  '=' expression     
									{
									
									$$= new simpleVar ($3,$1 ,Row ,col ) ;
								 } 
		
		  |			IDENT '['  ']' {
									
                                 $$=new arrayVar (NULL ,$1 ,Row ,col );

								} 
		 |			IDENT '['  ']' '=' '{' valueList '}'    {
                                 
                                 $$=new arrayVar ($6 ,$1 ,Row ,col );
								 } 

;


//3
// this list of values  like 1,2,3,4 // this is for the array asssignment int a[]= {1,3,4}

valueList:		valueList ',' value   {
							$$->AddExpr($3);
						}

		|		value  {
		
		               $$=new Exprs($1, Row ,col);
					   }
	
;


//rule for the value of a datatype 
value :      INTNUM		{
			        		$$ = $1;
							$$->t= 0 ;
					    }
	    
		
		|    STRINGCONST {
							$$ = $1;
							
							$$->t=1;
						 }
	    
		|	CHARCONST    {
							$$ = $1;
							
							$$->t=2;
				       	 }
		
		
		|	TRUE		 {
							$$ = new Val(true  ,Row,col);
							
							$$->t=3;
						 }
	    
		|	FALSE		 {
							$$ = new Val(false ,Row,col);
							
							$$->t=3;
						 }
		
		
		|	REALNUM      {
							$$ = $1;
							
							$$->t=0;
					     }
						  
		|	NULLL {
						$$ = NULL ;
						
						$$->t=5;
					}

;



// Defining Rule to allow defining multiple parameters to the functions 
// Example int flag1, int flag2 ,bool a 


args:	 		arg {
						$$ = new Args($1, Row, col);
					}
     |		    args ',' arg  {
						$1->AddArg($3);
						$$ = $1;
					}


;


arg :       standard_type IDENT  		{
								$$ = new Arg($1, $2, Row, col);
						}

 
    |		standard_type IDENT '[' ']'
					{
					$$ = new Arg($1, $2, Row, col);
				}



;



arg_e:		args  {
						$$ = $1;
				  }
		

	|   	/*Empty */	{
						$$ = new Args(Row, col);
				
				}
		
;


stmts:		 /* Empty */
						{
							$$ = new Stmts(Row, col);
						}
	|		stmts statement {
							$1->AddStmt($2);
							$$ = $1;
						}
	|		 stmts var_decl {
						
							$1->AddStmt($2);
							$$ = $1;
						}
		 
;


// Defining Rule for Parsing the regular expression {expression {, expression}*};
expression_list:			expression {
										$$= new Exprs(Row ,col);
										$$->AddExpr($1);
								}
				|			expression_list ',' expression {
										$1->AddExpr($3);	
								}
				|			   /* empty*/  {
										$$=new Exprs (Row ,col );
								}
;





// Defining Rule for variables as either an alias (int x;) x is an alias
// Or Arrays by the form MY_ARRAY [{expression ]

variable:	IDENT  {
                     $$=new IdExpr( $1 ,Row ,col);
					 }
|			IDENT '[' expression ']'  {
                     $$=new arrayExpr($3, $1  ,Row ,col);
					 }
;



// Primitive data types
standard_type:		INT 
						{
							$$ = 0;
						}
		
			|		STRING {
							$$ = 1;
						}
			
			|		CHAR {
							$$ = 2;
						}

			|		BOOL {
							$$ = 3;
						}


			|		FLOAT {
							$$ = 4 ;
						}
;





assignStatement :	variable  '=' expression ';' 	
		{
			$$ = new assignStatement($3,$1, Row, col);
		}		

;

cond_stmt : 			IF '(' expression ')'  statement  %prec IF_PREC {

														$$= new condStatement(NULL ,$5 ,$3, Row ,col);

									}
		 |      
						IF '(' expression ')'  statement ELSE statement {

										
														$$= new condStatement($7  ,$5 ,$3, Row ,col);

								}


;

while_stmt :       		WHILE '(' expression ')'  statement {
									$$=new whileStatement($5,$3,Row,col);
						}
	


;


// statement definition
// Additional Rule (defining Case Statement)
statement:		assignStatement {
							$$=$1;
						}


   
		 |		cond_stmt {
							$$=$1;
						} 

		
		 |		while_stmt {
							$$=$1;
						}
		 
		

		 |	    BREAK  ';'     {  
		 
									$$=new flowControlStatement(2,Row,col);

						}      

		
		 |		CONTINUE ';'{

									$$=new flowControlStatement(1,Row,col);
						}

		
		 |		RETURN  expression ';' {


									$$=new returnStatement($2, $2->t,Row,col);
						}

		|	  compound_statement {  
                       $$=$1 ;
					}
			   
;


tripleCondition:    expression '?' expression ':' expression %prec IF_PREC  {

															$$=new tripleExpr($1 ,$3, $5 ,Row ,col) ;
                                         }
;



expression:			variable  {
							$$ =$1 ;

							}
	

		|			value {
							$$=$1 ;	
						   }
	



        |			IDENT '(' expression_list ')' {
							
							$$=new funcCallExpr($1 , $3 , Row ,col ) ;

						  }

	
		|			'(' expression ')' {
							$$=$2 ;
						}

	
	
		|			expression unary_operator expression %prec CONFLICTSOLUTION {
							$$= new unOperatExp($1 ,$3 ,$2 ,Row ,col);
						}
	
		|			'!' expression  {$$=$2 ;}
	
	
		|			'-' expression { 
		                            Val* a =new Val(0 ,Row ,col);
									 $$= new unOperatExp(a ,$2,2 ,Row ,col);
		                           }


		|			tripleCondition {
							$$=$1 ;
						 }
;


%%

int yyerror(const char*)
{
	cout << "error in   line " << Row << " , col "<<col <<" , characters " << LeftCursor << '-' << RightCursor << endl;
	cout << "Syntax Error" << endl;
	return 1;
}
