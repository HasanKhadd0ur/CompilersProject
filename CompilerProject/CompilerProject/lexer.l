
%{
	#include<iostream>
	#include "ast.h"
	
	#include "statement.h"
	#include "parser.h"
	using std::cout;
	using std::endl;
	extern char* yytext;
	extern int Row = 1;

	// Before Reading Token
	extern int LeftCursor = 1;

	// After Reading Token
	extern int RightCursor = 1;
	// the col tracer 
	extern int col =0 ;

	void tracker(int tokenLen  ){
		
		col+=LeftCursor ;
		LeftCursor = RightCursor;
		
		RightCursor += tokenLen;
		
	}
%}

Digit [0-9]
Alpha [a-z]|[A-Z]
int_num 0|[1-9]+{Digit}*

Ident ({Alpha}|_)({Alpha}|{Digit}|_)*

Exponential ([Ee][-+]?{Digit}+)

string_const \"({Alpha}|{Digit}|_|.)*\" 
char_const \'({Alpha}|{Digit})\'

real_num1 ({Digit}+["."]{Digit}+{Exponential}?)
real_num2 (["."]{Digit}+{Exponential}?)
real_num3 {Digit}+{Exponential}
real_num (({real_num1})|({real_num2})|({real_num3}))





greater [>][=]
smaller [<][=]
notequal [<][>]


%option noyywrap

%x BlockComment
%x LineComment

%%



"while" { tracker(yyleng);  return WHILE;}





"&&"	{tracker(yyleng);  return AND;}
"||"	{tracker(yyleng);  return OR;}
"=="	{tracker(yyleng);  return ISEQUAL;}
"/"		{tracker(yyleng);  return DIV;}
"*"		{tracker(yyleng);  return MUL;}

"true"  {tracker(yyleng);  return TRUE;}
"false" {tracker(yyleng);  return FALSE;}



"if"	{tracker(yyleng);  return IF;}

"else"  {tracker(yyleng);  return ELSE;}




"float"	    {tracker(yyleng);  return FLOAT;}
"int"		{tracker(yyleng);  return INT;}
"string"	{tracker(yyleng);  return STRING;}
"char"		{tracker(yyleng);  return CHAR;}
"bool"		{tracker(yyleng);  return BOOL;}



{greater}   {tracker(yyleng);  return GREATER;}
{smaller}   {tracker(yyleng);  return SMALLER;}
{notequal}  {tracker(yyleng);  return NOTEQUAL;}




"class"		{tracker(yyleng);  return CLASS;}
"break"		{tracker(yyleng);  return BREAK;}
"return"	{tracker(yyleng);  return RETURN;}
"continue"  {tracker(yyleng);  return CONTINUE;}
"null"		{tracker(yyleng);  return NULLL;}


{Ident}			 {tracker(yyleng);  yylval.tIdent = new Ident( strdup(yytext), Row, col);
                return IDENT;}

{int_num}		 {tracker(yyleng); yylval.tVal = new  Val(atoi(yytext), Row, col);
                      return INTNUM;}
{real_num}		 {tracker(yyleng);yylval.tVal = new   Val(atof(yytext), Row, col);  return REALNUM;}

{string_const}   {tracker(yyleng);yylval.tVal = new  Val(strdup(yytext), Row, col);  return STRINGCONST;}

{char_const}     {tracker(yyleng); yylval.tVal = new Val(strdup(yytext), Row, col); return CHARCONST;}


':' {tracker(yyleng);   return *yytext;}
'?' { tracker(yyleng);  return *yytext;}

[-+=<>!;,\[\]\.\(\)] { tracker(yyleng); return *yytext;}


\n    {
         Row++;
         RightCursor = 1;
		 col=0;
		 LeftCursor = RightCursor;
      }
[ ]   {
         RightCursor++;
		 LeftCursor = RightCursor;
		  col+=1;
      }
\t    {
         RightCursor += 4;
		 LeftCursor = RightCursor;
		
      }
 [/][/]	{
         RightCursor += 2;
		 LeftCursor = RightCursor;
         BEGIN(LineComment);
		}
"/*" {
      RightCursor++;
	  LeftCursor = RightCursor;
      BEGIN(BlockComment);
   }
.  {tracker(yyleng); 
	  return *yytext;
   }

<BlockComment>"*/" {
                  RightCursor++;
				  LeftCursor = RightCursor;
                  BEGIN(0);
                  }
<BlockComment>.         {RightCursor++; LeftCursor = RightCursor;col+=1;}

<BlockComment>\n	{
						Row++;
						RightCursor = 1;
						LeftCursor = RightCursor;
					}
<LineComment>\n	{
				   Row++;
				   RightCursor = 1;
				   LeftCursor = RightCursor;
				   BEGIN(0);
				}
<LineComment>.	{
					RightCursor++;
					LeftCursor = RightCursor;
				}

%%
