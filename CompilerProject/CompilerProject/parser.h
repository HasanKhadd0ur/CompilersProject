/* A Bison parser, made by GNU Bison 2.7.  */

/* Bison interface for Yacc-like parsers in C
   
      Copyright (C) 1984, 1989-1990, 2000-2012 Free Software Foundation, Inc.
   
   This program is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.
   
   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.
   
   You should have received a copy of the GNU General Public License
   along with this program.  If not, see <http://www.gnu.org/licenses/>.  */

/* As a special exception, you may create a larger work that contains
   part or all of the Bison parser skeleton and distribute that work
   under terms of your choice, so long as that work isn't itself a
   parser generator using the skeleton or a modified version thereof
   as a parser skeleton.  Alternatively, if you modify or redistribute
   the parser skeleton itself, you may (at your option) remove this
   special exception, which will cause the skeleton and the resulting
   Bison output files to be licensed under the GNU General Public
   License without this special exception.
   
   This special exception was added by the Free Software Foundation in
   version 2.2 of Bison.  */

#ifndef YY_YY_PARSER_H_INCLUDED
# define YY_YY_PARSER_H_INCLUDED
/* Enabling traces.  */
#ifndef YYDEBUG
# define YYDEBUG 1
#endif
#if YYDEBUG
extern int yydebug;
#endif

/* Tokens.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
   /* Put the tokens into the symbol table, so that GDB and other debuggers
      know about them.  */
   enum yytokentype {
     IDENT = 258,
     INTNUM = 259,
     STRINGCONST = 260,
     CHARCONST = 261,
     NULLL = 262,
     FALSE = 263,
     TRUE = 264,
     REALNUM = 265,
     IF = 266,
     OR = 267,
     DIV = 268,
     AND = 269,
     MUL = 270,
     ELSE = 271,
     WHILE = 272,
     INT = 273,
     FLOAT = 274,
     BOOL = 275,
     CHAR = 276,
     STRING = 277,
     CLASS = 278,
     GREATER = 279,
     SMALLER = 280,
     ISEQUAL = 281,
     NOTEQUAL = 282,
     BREAK = 283,
     CONTINUE = 284,
     RETURN = 285,
     IF_PREC = 286,
     CONFLICTSOLUTION = 287
   };
#endif


#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE
{
/* Line 2058 of yacc.c  */
#line 30 "parser.y"

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



/* Line 2058 of yacc.c  */
#line 119 "parser.h"
} YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
#endif

extern YYSTYPE yylval;

#ifdef YYPARSE_PARAM
#if defined __STDC__ || defined __cplusplus
int yyparse (void *YYPARSE_PARAM);
#else
int yyparse ();
#endif
#else /* ! YYPARSE_PARAM */
#if defined __STDC__ || defined __cplusplus
int yyparse (void);
#else
int yyparse ();
#endif
#endif /* ! YYPARSE_PARAM */

#endif /* !YY_YY_PARSER_H_INCLUDED  */
