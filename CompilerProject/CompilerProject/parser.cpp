/* A Bison parser, made by GNU Bison 2.7.  */

/* Bison implementation for Yacc-like parsers in C
   
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

/* C LALR(1) parser skeleton written by Richard Stallman, by
   simplifying the original so-called "semantic" parser.  */

/* All symbols defined below should begin with yy or YY, to avoid
   infringing on user name space.  This should be done even for local
   variables, as they might otherwise be expanded by user macros.
   There are some unavoidable exceptions within include files to
   define necessary library symbols; they are noted "INFRINGES ON
   USER NAME SPACE" below.  */

/* Identify Bison output.  */
#define YYBISON 1

/* Bison version.  */
#define YYBISON_VERSION "2.7"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* Copy the first part of user declarations.  */
/* Line 371 of yacc.c  */
#line 1 "parser.y"


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
	

	



/* Line 371 of yacc.c  */
#line 97 "parser.cpp"

# ifndef YY_NULL
#  if defined __cplusplus && 201103L <= __cplusplus
#   define YY_NULL nullptr
#  else
#   define YY_NULL 0
#  endif
# endif

/* Enabling verbose error messages.  */
#ifdef YYERROR_VERBOSE
# undef YYERROR_VERBOSE
# define YYERROR_VERBOSE 1
#else
# define YYERROR_VERBOSE 0
#endif

/* In a future release of Bison, this section will be replaced
   by #include "parser.h".  */
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
/* Line 387 of yacc.c  */
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



/* Line 387 of yacc.c  */
#line 202 "parser.cpp"
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

/* Copy the second part of user declarations.  */

/* Line 390 of yacc.c  */
#line 230 "parser.cpp"

#ifdef short
# undef short
#endif

#ifdef YYTYPE_UINT8
typedef YYTYPE_UINT8 yytype_uint8;
#else
typedef unsigned char yytype_uint8;
#endif

#ifdef YYTYPE_INT8
typedef YYTYPE_INT8 yytype_int8;
#elif (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
typedef signed char yytype_int8;
#else
typedef short int yytype_int8;
#endif

#ifdef YYTYPE_UINT16
typedef YYTYPE_UINT16 yytype_uint16;
#else
typedef unsigned short int yytype_uint16;
#endif

#ifdef YYTYPE_INT16
typedef YYTYPE_INT16 yytype_int16;
#else
typedef short int yytype_int16;
#endif

#ifndef YYSIZE_T
# ifdef __SIZE_TYPE__
#  define YYSIZE_T __SIZE_TYPE__
# elif defined size_t
#  define YYSIZE_T size_t
# elif ! defined YYSIZE_T && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# else
#  define YYSIZE_T unsigned int
# endif
#endif

#define YYSIZE_MAXIMUM ((YYSIZE_T) -1)

#ifndef YY_
# if defined YYENABLE_NLS && YYENABLE_NLS
#  if ENABLE_NLS
#   include <libintl.h> /* INFRINGES ON USER NAME SPACE */
#   define YY_(Msgid) dgettext ("bison-runtime", Msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(Msgid) Msgid
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YYUSE(E) ((void) (E))
#else
# define YYUSE(E) /* empty */
#endif

/* Identity function, used to suppress warnings about constant conditions.  */
#ifndef lint
# define YYID(N) (N)
#else
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static int
YYID (int yyi)
#else
static int
YYID (yyi)
    int yyi;
#endif
{
  return yyi;
}
#endif

#if ! defined yyoverflow || YYERROR_VERBOSE

/* The parser invokes alloca or malloc; define the necessary symbols.  */

# ifdef YYSTACK_USE_ALLOCA
#  if YYSTACK_USE_ALLOCA
#   ifdef __GNUC__
#    define YYSTACK_ALLOC __builtin_alloca
#   elif defined __BUILTIN_VA_ARG_INCR
#    include <alloca.h> /* INFRINGES ON USER NAME SPACE */
#   elif defined _AIX
#    define YYSTACK_ALLOC __alloca
#   elif defined _MSC_VER
#    include <malloc.h> /* INFRINGES ON USER NAME SPACE */
#    define alloca _alloca
#   else
#    define YYSTACK_ALLOC alloca
#    if ! defined _ALLOCA_H && ! defined EXIT_SUCCESS && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
#     include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
      /* Use EXIT_SUCCESS as a witness for stdlib.h.  */
#     ifndef EXIT_SUCCESS
#      define EXIT_SUCCESS 0
#     endif
#    endif
#   endif
#  endif
# endif

# ifdef YYSTACK_ALLOC
   /* Pacify GCC's `empty if-body' warning.  */
#  define YYSTACK_FREE(Ptr) do { /* empty */; } while (YYID (0))
#  ifndef YYSTACK_ALLOC_MAXIMUM
    /* The OS might guarantee only one guard page at the bottom of the stack,
       and a page size can be as small as 4096 bytes.  So we cannot safely
       invoke alloca (N) if N exceeds 4096.  Use a slightly smaller number
       to allow for a few compiler-allocated temporary stack slots.  */
#   define YYSTACK_ALLOC_MAXIMUM 4032 /* reasonable circa 2006 */
#  endif
# else
#  define YYSTACK_ALLOC YYMALLOC
#  define YYSTACK_FREE YYFREE
#  ifndef YYSTACK_ALLOC_MAXIMUM
#   define YYSTACK_ALLOC_MAXIMUM YYSIZE_MAXIMUM
#  endif
#  if (defined __cplusplus && ! defined EXIT_SUCCESS \
       && ! ((defined YYMALLOC || defined malloc) \
	     && (defined YYFREE || defined free)))
#   include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#   ifndef EXIT_SUCCESS
#    define EXIT_SUCCESS 0
#   endif
#  endif
#  ifndef YYMALLOC
#   define YYMALLOC malloc
#   if ! defined malloc && ! defined EXIT_SUCCESS && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
void *malloc (YYSIZE_T); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
#  ifndef YYFREE
#   define YYFREE free
#   if ! defined free && ! defined EXIT_SUCCESS && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
void free (void *); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
# endif
#endif /* ! defined yyoverflow || YYERROR_VERBOSE */


#if (! defined yyoverflow \
     && (! defined __cplusplus \
	 || (defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  yytype_int16 yyss_alloc;
  YYSTYPE yyvs_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (sizeof (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (sizeof (yytype_int16) + sizeof (YYSTYPE)) \
      + YYSTACK_GAP_MAXIMUM)

# define YYCOPY_NEEDED 1

/* Relocate STACK from its old location to the new one.  The
   local variables YYSIZE and YYSTACKSIZE give the old and new number of
   elements in the stack, and YYPTR gives the new location of the
   stack.  Advance YYPTR to a properly aligned location for the next
   stack.  */
# define YYSTACK_RELOCATE(Stack_alloc, Stack)				\
    do									\
      {									\
	YYSIZE_T yynewbytes;						\
	YYCOPY (&yyptr->Stack_alloc, Stack, yysize);			\
	Stack = &yyptr->Stack_alloc;					\
	yynewbytes = yystacksize * sizeof (*Stack) + YYSTACK_GAP_MAXIMUM; \
	yyptr += yynewbytes / sizeof (*yyptr);				\
      }									\
    while (YYID (0))

#endif

#if defined YYCOPY_NEEDED && YYCOPY_NEEDED
/* Copy COUNT objects from SRC to DST.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(Dst, Src, Count) \
      __builtin_memcpy (Dst, Src, (Count) * sizeof (*(Src)))
#  else
#   define YYCOPY(Dst, Src, Count)              \
      do                                        \
        {                                       \
          YYSIZE_T yyi;                         \
          for (yyi = 0; yyi < (Count); yyi++)   \
            (Dst)[yyi] = (Src)[yyi];            \
        }                                       \
      while (YYID (0))
#  endif
# endif
#endif /* !YYCOPY_NEEDED */

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  2
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   269

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  49
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  26
/* YYNRULES -- Number of rules.  */
#define YYNRULES  80
/* YYNRULES -- Number of states.  */
#define YYNSTATES  134

/* YYTRANSLATE(YYLEX) -- Bison symbol number corresponding to YYLEX.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   287

#define YYTRANSLATE(YYX)						\
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[YYLEX] -- Bison symbol number corresponding to YYLEX.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    31,     2,     2,     2,     2,     2,     2,
      43,    44,     2,    36,    46,    35,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,    39,    45,
      33,    32,    34,    37,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,    47,     2,    48,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    41,     2,    42,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     1,     2,     3,     4,
       5,     6,     7,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    38,    40
};

#if YYDEBUG
/* YYPRHS[YYN] -- Index of the first RHS symbol of rule number YYN in
   YYRHS.  */
static const yytype_uint8 yyprhs[] =
{
       0,     0,     3,     6,     9,    12,    13,    19,    22,    25,
      28,    29,    35,    37,    39,    41,    43,    45,    47,    49,
      51,    53,    55,    57,    59,    63,    70,    74,    76,    80,
      82,    86,    90,    98,   102,   104,   106,   108,   110,   112,
     114,   116,   118,   120,   124,   127,   132,   134,   135,   136,
     139,   142,   144,   148,   149,   151,   156,   158,   160,   162,
     164,   166,   171,   177,   185,   191,   193,   195,   197,   200,
     203,   207,   209,   215,   217,   219,   224,   228,   232,   235,
     238
};

/* YYRHS -- A `-1'-separated list of the rules' RHS.  */
static const yytype_int8 yyrhs[] =
{
      50,     0,    -1,    50,    56,    -1,    50,    57,    -1,    50,
      51,    -1,    -1,    23,     3,    41,    52,    42,    -1,    52,
      56,    -1,    52,    57,    -1,    52,    53,    -1,    -1,     3,
      43,    64,    44,    55,    -1,    36,    -1,    35,    -1,    15,
      -1,    13,    -1,    34,    -1,    33,    -1,    24,    -1,    25,
      -1,    26,    -1,    27,    -1,    12,    -1,    14,    -1,    41,
      65,    42,    -1,    68,     3,    43,    64,    44,    55,    -1,
      68,    58,    45,    -1,    59,    -1,    58,    46,    59,    -1,
       3,    -1,     3,    32,    74,    -1,     3,    47,    48,    -1,
       3,    47,    48,    32,    41,    60,    42,    -1,    60,    46,
      61,    -1,    61,    -1,     4,    -1,     5,    -1,     6,    -1,
       9,    -1,     8,    -1,    10,    -1,     7,    -1,    63,    -1,
      62,    46,    63,    -1,    68,     3,    -1,    68,     3,    47,
      48,    -1,    62,    -1,    -1,    -1,    65,    72,    -1,    65,
      57,    -1,    74,    -1,    66,    46,    74,    -1,    -1,     3,
      -1,     3,    47,    74,    48,    -1,    18,    -1,    22,    -1,
      21,    -1,    20,    -1,    19,    -1,    67,    32,    74,    45,
      -1,    11,    43,    74,    44,    72,    -1,    11,    43,    74,
      44,    72,    16,    72,    -1,    17,    43,    74,    44,    72,
      -1,    69,    -1,    70,    -1,    71,    -1,    28,    45,    -1,
      29,    45,    -1,    30,    74,    45,    -1,    55,    -1,    74,
      37,    74,    39,    74,    -1,    67,    -1,    61,    -1,     3,
      43,    66,    44,    -1,    43,    74,    44,    -1,    74,    54,
      74,    -1,    31,    74,    -1,    35,    74,    -1,    73,    -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,   132,   132,   139,   148,   157,   176,   190,   194,   197,
     201,   209,   218,   221,   224,   227,   230,   233,   236,   239,
     242,   246,   250,   253,   262,   271,   285,   297,   302,   312,
     317,   323,   328,   339,   343,   352,   358,   364,   371,   377,
     384,   390,   404,   407,   416,   421,   432,   437,   446,   449,
     453,   463,   467,   470,   482,   485,   493,   498,   502,   506,
     511,   520,   527,   533,   543,   554,   560,   565,   571,   578,
     584,   590,   597,   605,   611,   618,   625,   631,   635,   638,
     644
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 0
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "IDENT", "INTNUM", "STRINGCONST",
  "CHARCONST", "NULLL", "FALSE", "TRUE", "REALNUM", "IF", "OR", "DIV",
  "AND", "MUL", "ELSE", "WHILE", "INT", "FLOAT", "BOOL", "CHAR", "STRING",
  "CLASS", "GREATER", "SMALLER", "ISEQUAL", "NOTEQUAL", "BREAK",
  "CONTINUE", "RETURN", "'!'", "'='", "'<'", "'>'", "'-'", "'+'", "'?'",
  "IF_PREC", "':'", "CONFLICTSOLUTION", "'{'", "'}'", "'('", "')'", "';'",
  "','", "'['", "']'", "$accept", "smalc_program", "class_dec", "members",
  "constructor", "unary_operator", "compound_statement", "func",
  "var_decl", "var_decl_list", "variable_id", "valueList", "value", "args",
  "arg", "arg_e", "stmts", "expression_list", "variable", "standard_type",
  "assignStatement", "cond_stmt", "while_stmt", "statement",
  "tripleCondition", "expression", YY_NULL
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[YYLEX-NUM] -- Internal token number corresponding to
   token YYLEX-NUM.  */
static const yytype_uint16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
     285,    33,    61,    60,    62,    45,    43,    63,   286,    58,
     287,   123,   125,    40,    41,    59,    44,    91,    93
};
# endif

/* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    49,    50,    50,    50,    50,    51,    52,    52,    52,
      52,    53,    54,    54,    54,    54,    54,    54,    54,    54,
      54,    54,    54,    54,    55,    56,    57,    58,    58,    59,
      59,    59,    59,    60,    60,    61,    61,    61,    61,    61,
      61,    61,    62,    62,    63,    63,    64,    64,    65,    65,
      65,    66,    66,    66,    67,    67,    68,    68,    68,    68,
      68,    69,    70,    70,    71,    72,    72,    72,    72,    72,
      72,    72,    73,    74,    74,    74,    74,    74,    74,    74,
      74
};

/* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     2,     2,     2,     0,     5,     2,     2,     2,
       0,     5,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     3,     6,     3,     1,     3,     1,
       3,     3,     7,     3,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     3,     2,     4,     1,     0,     0,     2,
       2,     1,     3,     0,     1,     4,     1,     1,     1,     1,
       1,     4,     5,     7,     5,     1,     1,     1,     2,     2,
       3,     1,     5,     1,     1,     4,     3,     3,     2,     2,
       1
};

/* YYDEFACT[STATE-NAME] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE doesn't specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       5,     0,     1,    56,    60,    59,    58,    57,     0,     4,
       2,     3,     0,     0,    29,     0,    27,    10,     0,    47,
       0,    26,     0,     0,    54,    35,    36,    37,    41,    39,
      38,    40,     0,     0,     0,    74,    73,    80,    30,    46,
      42,     0,     0,    31,    29,    28,     0,     6,     9,     7,
       8,    53,     0,    78,    79,     0,    22,    15,    23,    14,
      18,    19,    20,    21,    17,    16,    13,    12,     0,     0,
       0,     0,    44,     0,    47,     0,    51,     0,    76,     0,
      77,    43,    48,    25,     0,     0,     0,    75,     0,    55,
       0,     0,    45,     0,    34,     0,    52,    72,    54,     0,
       0,     0,     0,     0,    24,    71,    50,     0,     0,    65,
      66,    67,    49,    32,     0,    11,     0,     0,    68,    69,
       0,     0,    33,     0,     0,    70,     0,     0,     0,    61,
      62,    64,     0,    63
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int8 yydefgoto[] =
{
      -1,     1,     9,    23,    48,    69,   105,    10,    11,    15,
      16,    93,    35,    39,    40,    41,    91,    75,    36,    42,
     109,   110,   111,   112,    37,    38
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -120
static const yytype_int16 yypact[] =
{
    -120,    45,  -120,  -120,  -120,  -120,  -120,  -120,    30,  -120,
    -120,  -120,    41,     9,    39,   -34,  -120,  -120,    11,    59,
       5,  -120,    54,     7,   -13,  -120,  -120,  -120,  -120,  -120,
    -120,  -120,    11,    11,    11,  -120,  -120,  -120,   217,    12,
    -120,    26,    81,    63,     4,  -120,    53,  -120,  -120,  -120,
    -120,    11,    11,   232,    22,   151,  -120,  -120,  -120,  -120,
    -120,  -120,  -120,  -120,  -120,  -120,  -120,  -120,    11,    11,
      59,    66,    64,    71,    59,    48,   217,    91,  -120,   200,
    -120,  -120,  -120,  -120,    65,   197,    70,  -120,    11,  -120,
      11,    80,  -120,    10,  -120,    66,   217,    50,    72,    77,
      90,    78,    93,    11,  -120,  -120,  -120,   108,    54,  -120,
    -120,  -120,  -120,  -120,   197,  -120,    11,    11,  -120,  -120,
     117,    11,  -120,   156,   184,  -120,   122,    44,    44,  -120,
     129,  -120,    44,  -120
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -120,  -120,  -120,  -120,  -120,  -120,   -64,   137,   -22,  -120,
     139,  -120,   -82,  -120,   102,    99,  -120,  -120,   -89,    -1,
    -120,  -120,  -120,  -119,  -120,   -28
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -1
static const yytype_int16 yytable[] =
{
      12,    50,   107,    94,    53,    54,    55,    83,   130,   131,
      46,    21,    22,   133,    24,    25,    26,    27,    28,    29,
      30,    31,    12,    76,    77,     3,     4,     5,     6,     7,
      51,   115,   122,    13,    52,    57,    18,    59,   107,   107,
      79,    80,    32,   107,    14,     2,    33,    98,    62,    47,
      17,    20,   113,    43,    34,    99,   114,    44,    70,    68,
      96,   100,    97,     3,     4,     5,     6,     7,     8,   106,
      71,    18,   101,   102,   103,   120,    62,     3,     4,     5,
       6,     7,    19,    98,    72,    82,    20,    -1,   123,   124,
     108,    99,    87,   126,    88,    73,    74,   100,     3,     4,
       5,     6,     7,    56,    57,    58,    59,    82,   101,   102,
     103,    84,    85,    92,    95,    60,    61,    62,    63,    52,
     116,    82,   104,   118,    64,    65,    66,    67,    68,    56,
      57,    58,    59,   117,    56,    57,    58,    59,   119,    89,
     121,    60,    61,    62,    63,   132,    60,    61,    62,    63,
      64,    65,    66,    67,    68,    64,    65,    66,    67,    68,
      49,    45,   125,    56,    57,    58,    59,   129,    56,    57,
      58,    59,    81,    86,     0,    60,    61,    62,    63,     0,
      60,    61,    62,    63,    64,    65,    66,    67,    68,    64,
      65,    66,    67,    68,     0,    78,    56,    57,    58,    59,
     127,    25,    26,    27,    28,    29,    30,    31,    60,    61,
      62,    63,    56,    57,    58,    59,     0,    64,    65,    66,
      67,    68,     0,     0,    60,    61,    62,    63,   128,    56,
      57,    58,    59,    64,    65,    66,    67,    68,     0,    90,
       0,    60,    61,    62,    63,    57,     0,    59,     0,     0,
      64,    65,    66,    67,    68,     0,    60,    61,    62,    63,
       0,     0,     0,     0,     0,    64,    65,    66,    67,    68
};

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-120)))

#define yytable_value_is_error(Yytable_value) \
  (!!((Yytable_value) == (-1)))

static const yytype_int16 yycheck[] =
{
       1,    23,    91,    85,    32,    33,    34,    71,   127,   128,
       3,    45,    46,   132,     3,     4,     5,     6,     7,     8,
       9,    10,    23,    51,    52,    18,    19,    20,    21,    22,
      43,    95,   114,     3,    47,    13,    32,    15,   127,   128,
      68,    69,    31,   132,     3,     0,    35,     3,    26,    42,
      41,    47,    42,    48,    43,    11,    46,     3,    46,    37,
      88,    17,    90,    18,    19,    20,    21,    22,    23,    91,
      44,    32,    28,    29,    30,   103,    26,    18,    19,    20,
      21,    22,    43,     3,     3,    41,    47,    37,   116,   117,
      91,    11,    44,   121,    46,    32,    43,    17,    18,    19,
      20,    21,    22,    12,    13,    14,    15,    41,    28,    29,
      30,    47,    41,    48,    44,    24,    25,    26,    27,    47,
      43,    41,    42,    45,    33,    34,    35,    36,    37,    12,
      13,    14,    15,    43,    12,    13,    14,    15,    45,    48,
      32,    24,    25,    26,    27,    16,    24,    25,    26,    27,
      33,    34,    35,    36,    37,    33,    34,    35,    36,    37,
      23,    22,    45,    12,    13,    14,    15,    45,    12,    13,
      14,    15,    70,    74,    -1,    24,    25,    26,    27,    -1,
      24,    25,    26,    27,    33,    34,    35,    36,    37,    33,
      34,    35,    36,    37,    -1,    44,    12,    13,    14,    15,
      44,     4,     5,     6,     7,     8,     9,    10,    24,    25,
      26,    27,    12,    13,    14,    15,    -1,    33,    34,    35,
      36,    37,    -1,    -1,    24,    25,    26,    27,    44,    12,
      13,    14,    15,    33,    34,    35,    36,    37,    -1,    39,
      -1,    24,    25,    26,    27,    13,    -1,    15,    -1,    -1,
      33,    34,    35,    36,    37,    -1,    24,    25,    26,    27,
      -1,    -1,    -1,    -1,    -1,    33,    34,    35,    36,    37
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,    50,     0,    18,    19,    20,    21,    22,    23,    51,
      56,    57,    68,     3,     3,    58,    59,    41,    32,    43,
      47,    45,    46,    52,     3,     4,     5,     6,     7,     8,
       9,    10,    31,    35,    43,    61,    67,    73,    74,    62,
      63,    64,    68,    48,     3,    59,     3,    42,    53,    56,
      57,    43,    47,    74,    74,    74,    12,    13,    14,    15,
      24,    25,    26,    27,    33,    34,    35,    36,    37,    54,
      46,    44,     3,    32,    43,    66,    74,    74,    44,    74,
      74,    63,    41,    55,    47,    41,    64,    44,    46,    48,
      39,    65,    48,    60,    61,    44,    74,    74,     3,    11,
      17,    28,    29,    30,    42,    55,    57,    67,    68,    69,
      70,    71,    72,    42,    46,    55,    43,    43,    45,    45,
      74,    32,    61,    74,    74,    45,    74,    44,    44,    45,
      72,    72,    16,    72
};

#define yyerrok		(yyerrstatus = 0)
#define yyclearin	(yychar = YYEMPTY)
#define YYEMPTY		(-2)
#define YYEOF		0

#define YYACCEPT	goto yyacceptlab
#define YYABORT		goto yyabortlab
#define YYERROR		goto yyerrorlab


/* Like YYERROR except do call yyerror.  This remains here temporarily
   to ease the transition to the new meaning of YYERROR, for GCC.
   Once GCC version 2 has supplanted version 1, this can go.  However,
   YYFAIL appears to be in use.  Nevertheless, it is formally deprecated
   in Bison 2.4.2's NEWS entry, where a plan to phase it out is
   discussed.  */

#define YYFAIL		goto yyerrlab
#if defined YYFAIL
  /* This is here to suppress warnings from the GCC cpp's
     -Wunused-macros.  Normally we don't worry about that warning, but
     some users do, and we want to make it easy for users to remove
     YYFAIL uses, which will produce warnings from Bison 2.5.  */
#endif

#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)                                  \
do                                                              \
  if (yychar == YYEMPTY)                                        \
    {                                                           \
      yychar = (Token);                                         \
      yylval = (Value);                                         \
      YYPOPSTACK (yylen);                                       \
      yystate = *yyssp;                                         \
      goto yybackup;                                            \
    }                                                           \
  else                                                          \
    {                                                           \
      yyerror (YY_("syntax error: cannot back up")); \
      YYERROR;							\
    }								\
while (YYID (0))

/* Error token number */
#define YYTERROR	1
#define YYERRCODE	256


/* This macro is provided for backward compatibility. */
#ifndef YY_LOCATION_PRINT
# define YY_LOCATION_PRINT(File, Loc) ((void) 0)
#endif


/* YYLEX -- calling `yylex' with the right arguments.  */
#ifdef YYLEX_PARAM
# define YYLEX yylex (YYLEX_PARAM)
#else
# define YYLEX yylex ()
#endif

/* Enable debugging if requested.  */
#if YYDEBUG

# ifndef YYFPRINTF
#  include <stdio.h> /* INFRINGES ON USER NAME SPACE */
#  define YYFPRINTF fprintf
# endif

# define YYDPRINTF(Args)			\
do {						\
  if (yydebug)					\
    YYFPRINTF Args;				\
} while (YYID (0))

# define YY_SYMBOL_PRINT(Title, Type, Value, Location)			  \
do {									  \
  if (yydebug)								  \
    {									  \
      YYFPRINTF (stderr, "%s ", Title);					  \
      yy_symbol_print (stderr,						  \
		  Type, Value); \
      YYFPRINTF (stderr, "\n");						  \
    }									  \
} while (YYID (0))


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

/*ARGSUSED*/
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_symbol_value_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
#else
static void
yy_symbol_value_print (yyoutput, yytype, yyvaluep)
    FILE *yyoutput;
    int yytype;
    YYSTYPE const * const yyvaluep;
#endif
{
  FILE *yyo = yyoutput;
  YYUSE (yyo);
  if (!yyvaluep)
    return;
# ifdef YYPRINT
  if (yytype < YYNTOKENS)
    YYPRINT (yyoutput, yytoknum[yytype], *yyvaluep);
# else
  YYUSE (yyoutput);
# endif
  switch (yytype)
    {
      default:
        break;
    }
}


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_symbol_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
#else
static void
yy_symbol_print (yyoutput, yytype, yyvaluep)
    FILE *yyoutput;
    int yytype;
    YYSTYPE const * const yyvaluep;
#endif
{
  if (yytype < YYNTOKENS)
    YYFPRINTF (yyoutput, "token %s (", yytname[yytype]);
  else
    YYFPRINTF (yyoutput, "nterm %s (", yytname[yytype]);

  yy_symbol_value_print (yyoutput, yytype, yyvaluep);
  YYFPRINTF (yyoutput, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_stack_print (yytype_int16 *yybottom, yytype_int16 *yytop)
#else
static void
yy_stack_print (yybottom, yytop)
    yytype_int16 *yybottom;
    yytype_int16 *yytop;
#endif
{
  YYFPRINTF (stderr, "Stack now");
  for (; yybottom <= yytop; yybottom++)
    {
      int yybot = *yybottom;
      YYFPRINTF (stderr, " %d", yybot);
    }
  YYFPRINTF (stderr, "\n");
}

# define YY_STACK_PRINT(Bottom, Top)				\
do {								\
  if (yydebug)							\
    yy_stack_print ((Bottom), (Top));				\
} while (YYID (0))


/*------------------------------------------------.
| Report that the YYRULE is going to be reduced.  |
`------------------------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_reduce_print (YYSTYPE *yyvsp, int yyrule)
#else
static void
yy_reduce_print (yyvsp, yyrule)
    YYSTYPE *yyvsp;
    int yyrule;
#endif
{
  int yynrhs = yyr2[yyrule];
  int yyi;
  unsigned long int yylno = yyrline[yyrule];
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %lu):\n",
	     yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr, yyrhs[yyprhs[yyrule] + yyi],
		       &(yyvsp[(yyi + 1) - (yynrhs)])
		       		       );
      YYFPRINTF (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)		\
do {					\
  if (yydebug)				\
    yy_reduce_print (yyvsp, Rule); \
} while (YYID (0))

/* Nonzero means print parse trace.  It is left uninitialized so that
   multiple parsers can coexist.  */
int yydebug;
#else /* !YYDEBUG */
# define YYDPRINTF(Args)
# define YY_SYMBOL_PRINT(Title, Type, Value, Location)
# define YY_STACK_PRINT(Bottom, Top)
# define YY_REDUCE_PRINT(Rule)
#endif /* !YYDEBUG */


/* YYINITDEPTH -- initial size of the parser's stacks.  */
#ifndef	YYINITDEPTH
# define YYINITDEPTH 200
#endif

/* YYMAXDEPTH -- maximum size the stacks can grow to (effective only
   if the built-in stack extension method is used).

   Do not make this value too large; the results are undefined if
   YYSTACK_ALLOC_MAXIMUM < YYSTACK_BYTES (YYMAXDEPTH)
   evaluated with infinite-precision integer arithmetic.  */

#ifndef YYMAXDEPTH
# define YYMAXDEPTH 10000
#endif


#if YYERROR_VERBOSE

# ifndef yystrlen
#  if defined __GLIBC__ && defined _STRING_H
#   define yystrlen strlen
#  else
/* Return the length of YYSTR.  */
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static YYSIZE_T
yystrlen (const char *yystr)
#else
static YYSIZE_T
yystrlen (yystr)
    const char *yystr;
#endif
{
  YYSIZE_T yylen;
  for (yylen = 0; yystr[yylen]; yylen++)
    continue;
  return yylen;
}
#  endif
# endif

# ifndef yystpcpy
#  if defined __GLIBC__ && defined _STRING_H && defined _GNU_SOURCE
#   define yystpcpy stpcpy
#  else
/* Copy YYSRC to YYDEST, returning the address of the terminating '\0' in
   YYDEST.  */
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static char *
yystpcpy (char *yydest, const char *yysrc)
#else
static char *
yystpcpy (yydest, yysrc)
    char *yydest;
    const char *yysrc;
#endif
{
  char *yyd = yydest;
  const char *yys = yysrc;

  while ((*yyd++ = *yys++) != '\0')
    continue;

  return yyd - 1;
}
#  endif
# endif

# ifndef yytnamerr
/* Copy to YYRES the contents of YYSTR after stripping away unnecessary
   quotes and backslashes, so that it's suitable for yyerror.  The
   heuristic is that double-quoting is unnecessary unless the string
   contains an apostrophe, a comma, or backslash (other than
   backslash-backslash).  YYSTR is taken from yytname.  If YYRES is
   null, do not copy; instead, return the length of what the result
   would have been.  */
static YYSIZE_T
yytnamerr (char *yyres, const char *yystr)
{
  if (*yystr == '"')
    {
      YYSIZE_T yyn = 0;
      char const *yyp = yystr;

      for (;;)
	switch (*++yyp)
	  {
	  case '\'':
	  case ',':
	    goto do_not_strip_quotes;

	  case '\\':
	    if (*++yyp != '\\')
	      goto do_not_strip_quotes;
	    /* Fall through.  */
	  default:
	    if (yyres)
	      yyres[yyn] = *yyp;
	    yyn++;
	    break;

	  case '"':
	    if (yyres)
	      yyres[yyn] = '\0';
	    return yyn;
	  }
    do_not_strip_quotes: ;
    }

  if (! yyres)
    return yystrlen (yystr);

  return yystpcpy (yyres, yystr) - yyres;
}
# endif

/* Copy into *YYMSG, which is of size *YYMSG_ALLOC, an error message
   about the unexpected token YYTOKEN for the state stack whose top is
   YYSSP.

   Return 0 if *YYMSG was successfully written.  Return 1 if *YYMSG is
   not large enough to hold the message.  In that case, also set
   *YYMSG_ALLOC to the required number of bytes.  Return 2 if the
   required number of bytes is too large to store.  */
static int
yysyntax_error (YYSIZE_T *yymsg_alloc, char **yymsg,
                yytype_int16 *yyssp, int yytoken)
{
  YYSIZE_T yysize0 = yytnamerr (YY_NULL, yytname[yytoken]);
  YYSIZE_T yysize = yysize0;
  enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
  /* Internationalized format string. */
  const char *yyformat = YY_NULL;
  /* Arguments of yyformat. */
  char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];
  /* Number of reported tokens (one for the "unexpected", one per
     "expected"). */
  int yycount = 0;

  /* There are many possibilities here to consider:
     - Assume YYFAIL is not used.  It's too flawed to consider.  See
       <http://lists.gnu.org/archive/html/bison-patches/2009-12/msg00024.html>
       for details.  YYERROR is fine as it does not invoke this
       function.
     - If this state is a consistent state with a default action, then
       the only way this function was invoked is if the default action
       is an error action.  In that case, don't check for expected
       tokens because there are none.
     - The only way there can be no lookahead present (in yychar) is if
       this state is a consistent state with a default action.  Thus,
       detecting the absence of a lookahead is sufficient to determine
       that there is no unexpected or expected token to report.  In that
       case, just report a simple "syntax error".
     - Don't assume there isn't a lookahead just because this state is a
       consistent state with a default action.  There might have been a
       previous inconsistent state, consistent state with a non-default
       action, or user semantic action that manipulated yychar.
     - Of course, the expected token list depends on states to have
       correct lookahead information, and it depends on the parser not
       to perform extra reductions after fetching a lookahead from the
       scanner and before detecting a syntax error.  Thus, state merging
       (from LALR or IELR) and default reductions corrupt the expected
       token list.  However, the list is correct for canonical LR with
       one exception: it will still contain any token that will not be
       accepted due to an error action in a later state.
  */
  if (yytoken != YYEMPTY)
    {
      int yyn = yypact[*yyssp];
      yyarg[yycount++] = yytname[yytoken];
      if (!yypact_value_is_default (yyn))
        {
          /* Start YYX at -YYN if negative to avoid negative indexes in
             YYCHECK.  In other words, skip the first -YYN actions for
             this state because they are default actions.  */
          int yyxbegin = yyn < 0 ? -yyn : 0;
          /* Stay within bounds of both yycheck and yytname.  */
          int yychecklim = YYLAST - yyn + 1;
          int yyxend = yychecklim < YYNTOKENS ? yychecklim : YYNTOKENS;
          int yyx;

          for (yyx = yyxbegin; yyx < yyxend; ++yyx)
            if (yycheck[yyx + yyn] == yyx && yyx != YYTERROR
                && !yytable_value_is_error (yytable[yyx + yyn]))
              {
                if (yycount == YYERROR_VERBOSE_ARGS_MAXIMUM)
                  {
                    yycount = 1;
                    yysize = yysize0;
                    break;
                  }
                yyarg[yycount++] = yytname[yyx];
                {
                  YYSIZE_T yysize1 = yysize + yytnamerr (YY_NULL, yytname[yyx]);
                  if (! (yysize <= yysize1
                         && yysize1 <= YYSTACK_ALLOC_MAXIMUM))
                    return 2;
                  yysize = yysize1;
                }
              }
        }
    }

  switch (yycount)
    {
# define YYCASE_(N, S)                      \
      case N:                               \
        yyformat = S;                       \
      break
      YYCASE_(0, YY_("syntax error"));
      YYCASE_(1, YY_("syntax error, unexpected %s"));
      YYCASE_(2, YY_("syntax error, unexpected %s, expecting %s"));
      YYCASE_(3, YY_("syntax error, unexpected %s, expecting %s or %s"));
      YYCASE_(4, YY_("syntax error, unexpected %s, expecting %s or %s or %s"));
      YYCASE_(5, YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s"));
# undef YYCASE_
    }

  {
    YYSIZE_T yysize1 = yysize + yystrlen (yyformat);
    if (! (yysize <= yysize1 && yysize1 <= YYSTACK_ALLOC_MAXIMUM))
      return 2;
    yysize = yysize1;
  }

  if (*yymsg_alloc < yysize)
    {
      *yymsg_alloc = 2 * yysize;
      if (! (yysize <= *yymsg_alloc
             && *yymsg_alloc <= YYSTACK_ALLOC_MAXIMUM))
        *yymsg_alloc = YYSTACK_ALLOC_MAXIMUM;
      return 1;
    }

  /* Avoid sprintf, as that infringes on the user's name space.
     Don't have undefined behavior even if the translation
     produced a string with the wrong number of "%s"s.  */
  {
    char *yyp = *yymsg;
    int yyi = 0;
    while ((*yyp = *yyformat) != '\0')
      if (*yyp == '%' && yyformat[1] == 's' && yyi < yycount)
        {
          yyp += yytnamerr (yyp, yyarg[yyi++]);
          yyformat += 2;
        }
      else
        {
          yyp++;
          yyformat++;
        }
  }
  return 0;
}
#endif /* YYERROR_VERBOSE */

/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

/*ARGSUSED*/
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yydestruct (const char *yymsg, int yytype, YYSTYPE *yyvaluep)
#else
static void
yydestruct (yymsg, yytype, yyvaluep)
    const char *yymsg;
    int yytype;
    YYSTYPE *yyvaluep;
#endif
{
  YYUSE (yyvaluep);

  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yytype, yyvaluep, yylocationp);

  switch (yytype)
    {

      default:
        break;
    }
}




/* The lookahead symbol.  */
int yychar;


#ifndef YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_END
#endif
#ifndef YY_INITIAL_VALUE
# define YY_INITIAL_VALUE(Value) /* Nothing. */
#endif

/* The semantic value of the lookahead symbol.  */
YYSTYPE yylval YY_INITIAL_VALUE(yyval_default);

/* Number of syntax errors so far.  */
int yynerrs;


/*----------.
| yyparse.  |
`----------*/

#ifdef YYPARSE_PARAM
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
int
yyparse (void *YYPARSE_PARAM)
#else
int
yyparse (YYPARSE_PARAM)
    void *YYPARSE_PARAM;
#endif
#else /* ! YYPARSE_PARAM */
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
int
yyparse (void)
#else
int
yyparse ()

#endif
#endif
{
    int yystate;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus;

    /* The stacks and their tools:
       `yyss': related to states.
       `yyvs': related to semantic values.

       Refer to the stacks through separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* The state stack.  */
    yytype_int16 yyssa[YYINITDEPTH];
    yytype_int16 *yyss;
    yytype_int16 *yyssp;

    /* The semantic value stack.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs;
    YYSTYPE *yyvsp;

    YYSIZE_T yystacksize;

  int yyn;
  int yyresult;
  /* Lookahead token as an internal (translated) token number.  */
  int yytoken = 0;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;

#if YYERROR_VERBOSE
  /* Buffer for error messages, and its allocated size.  */
  char yymsgbuf[128];
  char *yymsg = yymsgbuf;
  YYSIZE_T yymsg_alloc = sizeof yymsgbuf;
#endif

#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  yyssp = yyss = yyssa;
  yyvsp = yyvs = yyvsa;
  yystacksize = YYINITDEPTH;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yystate = 0;
  yyerrstatus = 0;
  yynerrs = 0;
  yychar = YYEMPTY; /* Cause a token to be read.  */
  goto yysetstate;

/*------------------------------------------------------------.
| yynewstate -- Push a new state, which is found in yystate.  |
`------------------------------------------------------------*/
 yynewstate:
  /* In all cases, when you get here, the value and location stacks
     have just been pushed.  So pushing a state here evens the stacks.  */
  yyssp++;

 yysetstate:
  *yyssp = yystate;

  if (yyss + yystacksize - 1 <= yyssp)
    {
      /* Get the current used size of the three stacks, in elements.  */
      YYSIZE_T yysize = yyssp - yyss + 1;

#ifdef yyoverflow
      {
	/* Give user a chance to reallocate the stack.  Use copies of
	   these so that the &'s don't force the real ones into
	   memory.  */
	YYSTYPE *yyvs1 = yyvs;
	yytype_int16 *yyss1 = yyss;

	/* Each stack pointer address is followed by the size of the
	   data in use in that stack, in bytes.  This used to be a
	   conditional around just the two extra args, but that might
	   be undefined if yyoverflow is a macro.  */
	yyoverflow (YY_("memory exhausted"),
		    &yyss1, yysize * sizeof (*yyssp),
		    &yyvs1, yysize * sizeof (*yyvsp),
		    &yystacksize);

	yyss = yyss1;
	yyvs = yyvs1;
      }
#else /* no yyoverflow */
# ifndef YYSTACK_RELOCATE
      goto yyexhaustedlab;
# else
      /* Extend the stack our own way.  */
      if (YYMAXDEPTH <= yystacksize)
	goto yyexhaustedlab;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
	yystacksize = YYMAXDEPTH;

      {
	yytype_int16 *yyss1 = yyss;
	union yyalloc *yyptr =
	  (union yyalloc *) YYSTACK_ALLOC (YYSTACK_BYTES (yystacksize));
	if (! yyptr)
	  goto yyexhaustedlab;
	YYSTACK_RELOCATE (yyss_alloc, yyss);
	YYSTACK_RELOCATE (yyvs_alloc, yyvs);
#  undef YYSTACK_RELOCATE
	if (yyss1 != yyssa)
	  YYSTACK_FREE (yyss1);
      }
# endif
#endif /* no yyoverflow */

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;

      YYDPRINTF ((stderr, "Stack size increased to %lu\n",
		  (unsigned long int) yystacksize));

      if (yyss + yystacksize - 1 <= yyssp)
	YYABORT;
    }

  YYDPRINTF ((stderr, "Entering state %d\n", yystate));

  if (yystate == YYFINAL)
    YYACCEPT;

  goto yybackup;

/*-----------.
| yybackup.  |
`-----------*/
yybackup:

  /* Do appropriate processing given the current state.  Read a
     lookahead token if we need one and don't already have one.  */

  /* First try to decide what to do without reference to lookahead token.  */
  yyn = yypact[yystate];
  if (yypact_value_is_default (yyn))
    goto yydefault;

  /* Not known => get a lookahead token if don't already have one.  */

  /* YYCHAR is either YYEMPTY or YYEOF or a valid lookahead symbol.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token: "));
      yychar = YYLEX;
    }

  if (yychar <= YYEOF)
    {
      yychar = yytoken = YYEOF;
      YYDPRINTF ((stderr, "Now at end of input.\n"));
    }
  else
    {
      yytoken = YYTRANSLATE (yychar);
      YY_SYMBOL_PRINT ("Next token is", yytoken, &yylval, &yylloc);
    }

  /* If the proper action on seeing token YYTOKEN is to reduce or to
     detect an error, take that action.  */
  yyn += yytoken;
  if (yyn < 0 || YYLAST < yyn || yycheck[yyn] != yytoken)
    goto yydefault;
  yyn = yytable[yyn];
  if (yyn <= 0)
    {
      if (yytable_value_is_error (yyn))
        goto yyerrlab;
      yyn = -yyn;
      goto yyreduce;
    }

  /* Count tokens shifted since error; after three, turn off error
     status.  */
  if (yyerrstatus)
    yyerrstatus--;

  /* Shift the lookahead token.  */
  YY_SYMBOL_PRINT ("Shifting", yytoken, &yylval, &yylloc);

  /* Discard the shifted token.  */
  yychar = YYEMPTY;

  yystate = yyn;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END

  goto yynewstate;


/*-----------------------------------------------------------.
| yydefault -- do the default action for the current state.  |
`-----------------------------------------------------------*/
yydefault:
  yyn = yydefact[yystate];
  if (yyn == 0)
    goto yyerrlab;
  goto yyreduce;


/*-----------------------------.
| yyreduce -- Do a reduction.  |
`-----------------------------*/
yyreduce:
  /* yyn is the number of a rule to reduce with.  */
  yylen = yyr2[yyn];

  /* If YYLEN is nonzero, implement the default value of the action:
     `$$ = $1'.

     Otherwise, the following line sets YYVAL to garbage.
     This behavior is undocumented and Bison
     users should not rely upon it.  Assigning to YYVAL
     unconditionally makes the parser a bit smaller, and it avoids a
     GCC warning that YYVAL may be used uninitialized.  */
  yyval = yyvsp[1-yylen];


  YY_REDUCE_PRINT (yyn);
  switch (yyn)
    {
        case 2:
/* Line 1792 of yacc.c  */
#line 132 "parser.y"
    {
												(yyval.tsmallc)->addprogramFunc((yyvsp[(2) - (2)].tFunc));
												rootProgram=(yyval.tsmallc);
											}
    break;

  case 3:
/* Line 1792 of yacc.c  */
#line 139 "parser.y"
    {
											    
												
												(yyval.tsmallc)->addGlobalVar((yyvsp[(2) - (2)].tvDecl));
												rootProgram=(yyval.tsmallc);
											}
    break;

  case 4:
/* Line 1792 of yacc.c  */
#line 148 "parser.y"
    {
			
											
												(yyval.tsmallc)->addprogramClasses((yyvsp[(2) - (2)].tClassDecl));	
												rootProgram=(yyval.tsmallc);
											}
    break;

  case 5:
/* Line 1792 of yacc.c  */
#line 157 "parser.y"
    {

					                           (yyval.tsmallc)= new smallc (Row ,col);
											   rootProgram =(yyval.tsmallc);
											  }
    break;

  case 6:
/* Line 1792 of yacc.c  */
#line 176 "parser.y"
    {
                                           (yyval.tClassDecl)= new ClassDecl((yyvsp[(2) - (5)].tIdent),Row,col);
										

										   (yyval.tClassDecl)->addMethods((yyvsp[(4) - (5)].tmembers)->method);
										   (yyval.tClassDecl)->addConstructors((yyvsp[(4) - (5)].tmembers)->constructor);
										   (yyval.tClassDecl)->addProps((yyvsp[(4) - (5)].tmembers)->props);


										  }
    break;

  case 7:
/* Line 1792 of yacc.c  */
#line 190 "parser.y"
    {
									(yyval.tmembers)->method.push_back((yyvsp[(2) - (2)].tFunc));
                                }
    break;

  case 8:
/* Line 1792 of yacc.c  */
#line 194 "parser.y"
    {
									(yyval.tmembers)->props.push_back((yyvsp[(2) - (2)].tvDecl));
								}
    break;

  case 9:
/* Line 1792 of yacc.c  */
#line 197 "parser.y"
    {
										(yyval.tmembers)->constructor.push_back((yyvsp[(2) - (2)].tFunc));
									}
    break;

  case 10:
/* Line 1792 of yacc.c  */
#line 201 "parser.y"
    {
									
									(yyval.tmembers)=new members();
		                   }
    break;

  case 11:
/* Line 1792 of yacc.c  */
#line 209 "parser.y"
    {
														(yyval.tFunc)= new Func(6,(yyvsp[(1) - (5)].tIdent) , (yyvsp[(3) - (5)].tArgs) , (yyvsp[(5) - (5)].tcStmt)->compStmt ,Row ,col );
													  }
    break;

  case 12:
/* Line 1792 of yacc.c  */
#line 218 "parser.y"
    {
                           (yyval.tInt)=0;
						   }
    break;

  case 13:
/* Line 1792 of yacc.c  */
#line 221 "parser.y"
    {
                           (yyval.tInt)=1;
						   }
    break;

  case 14:
/* Line 1792 of yacc.c  */
#line 224 "parser.y"
    {
                           (yyval.tInt)=2;
						   }
    break;

  case 15:
/* Line 1792 of yacc.c  */
#line 227 "parser.y"
    {
                           (yyval.tInt)=3;
						   }
    break;

  case 16:
/* Line 1792 of yacc.c  */
#line 230 "parser.y"
    {
                           (yyval.tInt)=4;
						   }
    break;

  case 17:
/* Line 1792 of yacc.c  */
#line 233 "parser.y"
    {
                           (yyval.tInt)=5;
						   }
    break;

  case 18:
/* Line 1792 of yacc.c  */
#line 236 "parser.y"
    {
                           (yyval.tInt)=6;
						   }
    break;

  case 19:
/* Line 1792 of yacc.c  */
#line 239 "parser.y"
    {
                           (yyval.tInt)=7;
						   }
    break;

  case 20:
/* Line 1792 of yacc.c  */
#line 242 "parser.y"
    {
                           (yyval.tInt)=8;
						   }
    break;

  case 21:
/* Line 1792 of yacc.c  */
#line 246 "parser.y"
    {
                           (yyval.tInt)=9;
						   }
    break;

  case 22:
/* Line 1792 of yacc.c  */
#line 250 "parser.y"
    {
                           (yyval.tInt)=10;
						   }
    break;

  case 23:
/* Line 1792 of yacc.c  */
#line 253 "parser.y"
    {
                           (yyval.tInt)=11;
						   }
    break;

  case 24:
/* Line 1792 of yacc.c  */
#line 262 "parser.y"
    {
									 (yyval.tcStmt)=new compoundStmt ((yyvsp[(2) - (3)].tStmts) ,Row ,col );
								 }
    break;

  case 25:
/* Line 1792 of yacc.c  */
#line 272 "parser.y"
    {
			(yyval.tFunc) = new Func((yyvsp[(1) - (6)].tInt), (yyvsp[(2) - (6)].tIdent), (yyvsp[(4) - (6)].tArgs), (yyvsp[(6) - (6)].tcStmt)->compStmt, Row, col);
		

		}
    break;

  case 26:
/* Line 1792 of yacc.c  */
#line 285 "parser.y"
    {  
									
                                              (yyvsp[(2) - (3)].tvDecl)->type=(yyvsp[(1) - (3)].tInt);
											  (yyval.tvDecl)=(yyvsp[(2) - (3)].tvDecl);

											  

									 }
    break;

  case 27:
/* Line 1792 of yacc.c  */
#line 297 "parser.y"
    {   
                                                (yyval.tvDecl)=new variableDecl(1 ,Row,col);
												(yyval.tvDecl)->names.push_back( (yyvsp[(1) - (1)].tp));

                                        }
    break;

  case 28:
/* Line 1792 of yacc.c  */
#line 302 "parser.y"
    {
                                                   (yyvsp[(1) - (3)].tvDecl)->names.push_back( (yyvsp[(3) - (3)].tp));
												   (yyval.tvDecl)=(yyvsp[(1) - (3)].tvDecl);
                                                   }
    break;

  case 29:
/* Line 1792 of yacc.c  */
#line 312 "parser.y"
    {
                                 (yyval.tp)= new simpleVar (NULL,(yyvsp[(1) - (1)].tIdent) ,Row ,col ) ;
								 }
    break;

  case 30:
/* Line 1792 of yacc.c  */
#line 318 "parser.y"
    {
									
									(yyval.tp)= new simpleVar ((yyvsp[(3) - (3)].tExpr),(yyvsp[(1) - (3)].tIdent) ,Row ,col ) ;
								 }
    break;

  case 31:
/* Line 1792 of yacc.c  */
#line 323 "parser.y"
    {
									
                                 (yyval.tp)=new arrayVar (NULL ,(yyvsp[(1) - (3)].tIdent) ,Row ,col );

								}
    break;

  case 32:
/* Line 1792 of yacc.c  */
#line 328 "parser.y"
    {
                                 
                                 (yyval.tp)=new arrayVar ((yyvsp[(6) - (7)].tExprs) ,(yyvsp[(1) - (7)].tIdent) ,Row ,col );
								 }
    break;

  case 33:
/* Line 1792 of yacc.c  */
#line 339 "parser.y"
    {
							(yyval.tExprs)->AddExpr((yyvsp[(3) - (3)].tExpr));
						}
    break;

  case 34:
/* Line 1792 of yacc.c  */
#line 343 "parser.y"
    {
		
		               (yyval.tExprs)=new Exprs((yyvsp[(1) - (1)].tExpr), Row ,col);
					   }
    break;

  case 35:
/* Line 1792 of yacc.c  */
#line 352 "parser.y"
    {
			        		(yyval.tExpr) = (yyvsp[(1) - (1)].tVal);
							(yyval.tExpr)->t= 0 ;
					    }
    break;

  case 36:
/* Line 1792 of yacc.c  */
#line 358 "parser.y"
    {
							(yyval.tExpr) = (yyvsp[(1) - (1)].tVal);
							
							(yyval.tExpr)->t=1;
						 }
    break;

  case 37:
/* Line 1792 of yacc.c  */
#line 364 "parser.y"
    {
							(yyval.tExpr) = (yyvsp[(1) - (1)].tVal);
							
							(yyval.tExpr)->t=2;
				       	 }
    break;

  case 38:
/* Line 1792 of yacc.c  */
#line 371 "parser.y"
    {
							(yyval.tExpr) = new Val(true  ,Row,col);
							
							(yyval.tExpr)->t=3;
						 }
    break;

  case 39:
/* Line 1792 of yacc.c  */
#line 377 "parser.y"
    {
							(yyval.tExpr) = new Val(false ,Row,col);
							
							(yyval.tExpr)->t=3;
						 }
    break;

  case 40:
/* Line 1792 of yacc.c  */
#line 384 "parser.y"
    {
							(yyval.tExpr) = (yyvsp[(1) - (1)].tVal);
							
							(yyval.tExpr)->t=0;
					     }
    break;

  case 41:
/* Line 1792 of yacc.c  */
#line 390 "parser.y"
    {
						(yyval.tExpr) = NULL ;
						
						(yyval.tExpr)->t=5;
					}
    break;

  case 42:
/* Line 1792 of yacc.c  */
#line 404 "parser.y"
    {
						(yyval.tArgs) = new Args((yyvsp[(1) - (1)].tArg), Row, col);
					}
    break;

  case 43:
/* Line 1792 of yacc.c  */
#line 407 "parser.y"
    {
						(yyvsp[(1) - (3)].tArgs)->AddArg((yyvsp[(3) - (3)].tArg));
						(yyval.tArgs) = (yyvsp[(1) - (3)].tArgs);
					}
    break;

  case 44:
/* Line 1792 of yacc.c  */
#line 416 "parser.y"
    {
								(yyval.tArg) = new Arg((yyvsp[(1) - (2)].tInt), (yyvsp[(2) - (2)].tIdent), Row, col);
						}
    break;

  case 45:
/* Line 1792 of yacc.c  */
#line 422 "parser.y"
    {
					(yyval.tArg) = new Arg((yyvsp[(1) - (4)].tInt), (yyvsp[(2) - (4)].tIdent), Row, col);
				}
    break;

  case 46:
/* Line 1792 of yacc.c  */
#line 432 "parser.y"
    {
						(yyval.tArgs) = (yyvsp[(1) - (1)].tArgs);
				  }
    break;

  case 47:
/* Line 1792 of yacc.c  */
#line 437 "parser.y"
    {
						(yyval.tArgs) = new Args(Row, col);
				
				}
    break;

  case 48:
/* Line 1792 of yacc.c  */
#line 446 "parser.y"
    {
							(yyval.tStmts) = new Stmts(Row, col);
						}
    break;

  case 49:
/* Line 1792 of yacc.c  */
#line 449 "parser.y"
    {
							(yyvsp[(1) - (2)].tStmts)->AddStmt((yyvsp[(2) - (2)].tStmt));
							(yyval.tStmts) = (yyvsp[(1) - (2)].tStmts);
						}
    break;

  case 50:
/* Line 1792 of yacc.c  */
#line 453 "parser.y"
    {
						
							(yyvsp[(1) - (2)].tStmts)->AddStmt((yyvsp[(2) - (2)].tvDecl));
							(yyval.tStmts) = (yyvsp[(1) - (2)].tStmts);
						}
    break;

  case 51:
/* Line 1792 of yacc.c  */
#line 463 "parser.y"
    {
										(yyval.tExprs)= new Exprs(Row ,col);
										(yyval.tExprs)->AddExpr((yyvsp[(1) - (1)].tExpr));
								}
    break;

  case 52:
/* Line 1792 of yacc.c  */
#line 467 "parser.y"
    {
										(yyvsp[(1) - (3)].tExprs)->AddExpr((yyvsp[(3) - (3)].tExpr));	
								}
    break;

  case 53:
/* Line 1792 of yacc.c  */
#line 470 "parser.y"
    {
										(yyval.tExprs)=new Exprs (Row ,col );
								}
    break;

  case 54:
/* Line 1792 of yacc.c  */
#line 482 "parser.y"
    {
                     (yyval.tIdExpr)=new IdExpr( (yyvsp[(1) - (1)].tIdent) ,Row ,col);
					 }
    break;

  case 55:
/* Line 1792 of yacc.c  */
#line 485 "parser.y"
    {
                     (yyval.tIdExpr)=new arrayExpr((yyvsp[(3) - (4)].tExpr), (yyvsp[(1) - (4)].tIdent)  ,Row ,col);
					 }
    break;

  case 56:
/* Line 1792 of yacc.c  */
#line 494 "parser.y"
    {
							(yyval.tInt) = 0;
						}
    break;

  case 57:
/* Line 1792 of yacc.c  */
#line 498 "parser.y"
    {
							(yyval.tInt) = 1;
						}
    break;

  case 58:
/* Line 1792 of yacc.c  */
#line 502 "parser.y"
    {
							(yyval.tInt) = 2;
						}
    break;

  case 59:
/* Line 1792 of yacc.c  */
#line 506 "parser.y"
    {
							(yyval.tInt) = 3;
						}
    break;

  case 60:
/* Line 1792 of yacc.c  */
#line 511 "parser.y"
    {
							(yyval.tInt) = 4 ;
						}
    break;

  case 61:
/* Line 1792 of yacc.c  */
#line 521 "parser.y"
    {
			(yyval.tasStmt) = new assignStatement((yyvsp[(3) - (4)].tExpr),(yyvsp[(1) - (4)].tIdExpr), Row, col);
		}
    break;

  case 62:
/* Line 1792 of yacc.c  */
#line 527 "parser.y"
    {

														(yyval.tcon)= new condStatement(NULL ,(yyvsp[(5) - (5)].tStmt) ,(yyvsp[(3) - (5)].tExpr), Row ,col);

									}
    break;

  case 63:
/* Line 1792 of yacc.c  */
#line 533 "parser.y"
    {

										
														(yyval.tcon)= new condStatement((yyvsp[(7) - (7)].tStmt)  ,(yyvsp[(5) - (7)].tStmt) ,(yyvsp[(3) - (7)].tExpr), Row ,col);

								}
    break;

  case 64:
/* Line 1792 of yacc.c  */
#line 543 "parser.y"
    {
									(yyval.twhile)=new whileStatement((yyvsp[(5) - (5)].tStmt),(yyvsp[(3) - (5)].tExpr),Row,col);
						}
    break;

  case 65:
/* Line 1792 of yacc.c  */
#line 554 "parser.y"
    {
							(yyval.tStmt)=(yyvsp[(1) - (1)].tasStmt);
						}
    break;

  case 66:
/* Line 1792 of yacc.c  */
#line 560 "parser.y"
    {
							(yyval.tStmt)=(yyvsp[(1) - (1)].tcon);
						}
    break;

  case 67:
/* Line 1792 of yacc.c  */
#line 565 "parser.y"
    {
							(yyval.tStmt)=(yyvsp[(1) - (1)].twhile);
						}
    break;

  case 68:
/* Line 1792 of yacc.c  */
#line 571 "parser.y"
    {  
		 
									(yyval.tStmt)=new flowControlStatement(2,Row,col);

						}
    break;

  case 69:
/* Line 1792 of yacc.c  */
#line 578 "parser.y"
    {

									(yyval.tStmt)=new flowControlStatement(1,Row,col);
						}
    break;

  case 70:
/* Line 1792 of yacc.c  */
#line 584 "parser.y"
    {


									(yyval.tStmt)=new returnStatement((yyvsp[(2) - (3)].tExpr), (yyvsp[(2) - (3)].tExpr)->t,Row,col);
						}
    break;

  case 71:
/* Line 1792 of yacc.c  */
#line 590 "parser.y"
    {  
                       (yyval.tStmt)=(yyvsp[(1) - (1)].tcStmt) ;
					}
    break;

  case 72:
/* Line 1792 of yacc.c  */
#line 597 "parser.y"
    {

															(yyval.triple)=new tripleExpr((yyvsp[(1) - (5)].tExpr) ,(yyvsp[(3) - (5)].tExpr), (yyvsp[(5) - (5)].tExpr) ,Row ,col) ;
                                         }
    break;

  case 73:
/* Line 1792 of yacc.c  */
#line 605 "parser.y"
    {
							(yyval.tExpr) =(yyvsp[(1) - (1)].tIdExpr) ;

							}
    break;

  case 74:
/* Line 1792 of yacc.c  */
#line 611 "parser.y"
    {
							(yyval.tExpr)=(yyvsp[(1) - (1)].tExpr) ;	
						   }
    break;

  case 75:
/* Line 1792 of yacc.c  */
#line 618 "parser.y"
    {
							
							(yyval.tExpr)=new funcCallExpr((yyvsp[(1) - (4)].tIdent) , (yyvsp[(3) - (4)].tExprs) , Row ,col ) ;

						  }
    break;

  case 76:
/* Line 1792 of yacc.c  */
#line 625 "parser.y"
    {
							(yyval.tExpr)=(yyvsp[(2) - (3)].tExpr) ;
						}
    break;

  case 77:
/* Line 1792 of yacc.c  */
#line 631 "parser.y"
    {
							(yyval.tExpr)= new unOperatExp((yyvsp[(1) - (3)].tExpr) ,(yyvsp[(3) - (3)].tExpr) ,(yyvsp[(2) - (3)].tInt) ,Row ,col);
						}
    break;

  case 78:
/* Line 1792 of yacc.c  */
#line 635 "parser.y"
    {(yyval.tExpr)=(yyvsp[(2) - (2)].tExpr) ;}
    break;

  case 79:
/* Line 1792 of yacc.c  */
#line 638 "parser.y"
    { 
		                            Val* a =new Val(0 ,Row ,col);
									 (yyval.tExpr)= new unOperatExp(a ,(yyvsp[(2) - (2)].tExpr),2 ,Row ,col);
		                           }
    break;

  case 80:
/* Line 1792 of yacc.c  */
#line 644 "parser.y"
    {
							(yyval.tExpr)=(yyvsp[(1) - (1)].triple) ;
						 }
    break;


/* Line 1792 of yacc.c  */
#line 2268 "parser.cpp"
      default: break;
    }
  /* User semantic actions sometimes alter yychar, and that requires
     that yytoken be updated with the new translation.  We take the
     approach of translating immediately before every use of yytoken.
     One alternative is translating here after every semantic action,
     but that translation would be missed if the semantic action invokes
     YYABORT, YYACCEPT, or YYERROR immediately after altering yychar or
     if it invokes YYBACKUP.  In the case of YYABORT or YYACCEPT, an
     incorrect destructor might then be invoked immediately.  In the
     case of YYERROR or YYBACKUP, subsequent parser actions might lead
     to an incorrect destructor call or verbose syntax error message
     before the lookahead is translated.  */
  YY_SYMBOL_PRINT ("-> $$ =", yyr1[yyn], &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);

  *++yyvsp = yyval;

  /* Now `shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */

  yyn = yyr1[yyn];

  yystate = yypgoto[yyn - YYNTOKENS] + *yyssp;
  if (0 <= yystate && yystate <= YYLAST && yycheck[yystate] == *yyssp)
    yystate = yytable[yystate];
  else
    yystate = yydefgoto[yyn - YYNTOKENS];

  goto yynewstate;


/*------------------------------------.
| yyerrlab -- here on detecting error |
`------------------------------------*/
yyerrlab:
  /* Make sure we have latest lookahead translation.  See comments at
     user semantic actions for why this is necessary.  */
  yytoken = yychar == YYEMPTY ? YYEMPTY : YYTRANSLATE (yychar);

  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
#if ! YYERROR_VERBOSE
      yyerror (YY_("syntax error"));
#else
# define YYSYNTAX_ERROR yysyntax_error (&yymsg_alloc, &yymsg, \
                                        yyssp, yytoken)
      {
        char const *yymsgp = YY_("syntax error");
        int yysyntax_error_status;
        yysyntax_error_status = YYSYNTAX_ERROR;
        if (yysyntax_error_status == 0)
          yymsgp = yymsg;
        else if (yysyntax_error_status == 1)
          {
            if (yymsg != yymsgbuf)
              YYSTACK_FREE (yymsg);
            yymsg = (char *) YYSTACK_ALLOC (yymsg_alloc);
            if (!yymsg)
              {
                yymsg = yymsgbuf;
                yymsg_alloc = sizeof yymsgbuf;
                yysyntax_error_status = 2;
              }
            else
              {
                yysyntax_error_status = YYSYNTAX_ERROR;
                yymsgp = yymsg;
              }
          }
        yyerror (yymsgp);
        if (yysyntax_error_status == 2)
          goto yyexhaustedlab;
      }
# undef YYSYNTAX_ERROR
#endif
    }



  if (yyerrstatus == 3)
    {
      /* If just tried and failed to reuse lookahead token after an
	 error, discard it.  */

      if (yychar <= YYEOF)
	{
	  /* Return failure if at end of input.  */
	  if (yychar == YYEOF)
	    YYABORT;
	}
      else
	{
	  yydestruct ("Error: discarding",
		      yytoken, &yylval);
	  yychar = YYEMPTY;
	}
    }

  /* Else will try to reuse lookahead token after shifting the error
     token.  */
  goto yyerrlab1;


/*---------------------------------------------------.
| yyerrorlab -- error raised explicitly by YYERROR.  |
`---------------------------------------------------*/
yyerrorlab:

  /* Pacify compilers like GCC when the user code never invokes
     YYERROR and the label yyerrorlab therefore never appears in user
     code.  */
  if (/*CONSTCOND*/ 0)
     goto yyerrorlab;

  /* Do not reclaim the symbols of the rule which action triggered
     this YYERROR.  */
  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);
  yystate = *yyssp;
  goto yyerrlab1;


/*-------------------------------------------------------------.
| yyerrlab1 -- common code for both syntax error and YYERROR.  |
`-------------------------------------------------------------*/
yyerrlab1:
  yyerrstatus = 3;	/* Each real token shifted decrements this.  */

  for (;;)
    {
      yyn = yypact[yystate];
      if (!yypact_value_is_default (yyn))
	{
	  yyn += YYTERROR;
	  if (0 <= yyn && yyn <= YYLAST && yycheck[yyn] == YYTERROR)
	    {
	      yyn = yytable[yyn];
	      if (0 < yyn)
		break;
	    }
	}

      /* Pop the current state because it cannot handle the error token.  */
      if (yyssp == yyss)
	YYABORT;


      yydestruct ("Error: popping",
		  yystos[yystate], yyvsp);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END


  /* Shift the error token.  */
  YY_SYMBOL_PRINT ("Shifting", yystos[yyn], yyvsp, yylsp);

  yystate = yyn;
  goto yynewstate;


/*-------------------------------------.
| yyacceptlab -- YYACCEPT comes here.  |
`-------------------------------------*/
yyacceptlab:
  yyresult = 0;
  goto yyreturn;

/*-----------------------------------.
| yyabortlab -- YYABORT comes here.  |
`-----------------------------------*/
yyabortlab:
  yyresult = 1;
  goto yyreturn;

#if !defined yyoverflow || YYERROR_VERBOSE
/*-------------------------------------------------.
| yyexhaustedlab -- memory exhaustion comes here.  |
`-------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  /* Fall through.  */
#endif

yyreturn:
  if (yychar != YYEMPTY)
    {
      /* Make sure we have latest lookahead translation.  See comments at
         user semantic actions for why this is necessary.  */
      yytoken = YYTRANSLATE (yychar);
      yydestruct ("Cleanup: discarding lookahead",
                  yytoken, &yylval);
    }
  /* Do not reclaim the symbols of the rule which action triggered
     this YYABORT or YYACCEPT.  */
  YYPOPSTACK (yylen);
  YY_STACK_PRINT (yyss, yyssp);
  while (yyssp != yyss)
    {
      yydestruct ("Cleanup: popping",
		  yystos[*yyssp], yyvsp);
      YYPOPSTACK (1);
    }
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif
#if YYERROR_VERBOSE
  if (yymsg != yymsgbuf)
    YYSTACK_FREE (yymsg);
#endif
  /* Make sure YYID is used.  */
  return YYID (yyresult);
}


/* Line 2055 of yacc.c  */
#line 650 "parser.y"


int yyerror(const char*)
{
	cout << "error in   line " << Row << " , col "<<col <<" , characters " << LeftCursor << '-' << RightCursor << endl;
	cout << "Syntax Error" << endl;
	return 1;
}
