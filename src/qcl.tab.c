/* A Bison parser, made by GNU Bison 2.3.  */

/* Skeleton implementation for Bison's Yacc-like parsers in C

   Copyright (C) 1984, 1989, 1990, 2000, 2001, 2002, 2003, 2004, 2005, 2006
   Free Software Foundation, Inc.

   This program is free software; you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation; either version 2, or (at your option)
   any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program; if not, write to the Free Software
   Foundation, Inc., 51 Franklin Street, Fifth Floor,
   Boston, MA 02110-1301, USA.  */

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
#define YYBISON_VERSION "2.3"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Using locations.  */
#define YYLSP_NEEDED 0

/* Substitute the variable and function names.  */
#define yyparse qclparse
#define yylex   qcllex
#define yyerror qclerror
#define yylval  qcllval
#define yychar  qclchar
#define yydebug qcldebug
#define yynerrs qclnerrs


/* Tokens.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
   /* Put the tokens into the symbol table, so that GDB and other debuggers
      know about them.  */
   enum yytokentype {
     tokAND = 258,
     tokBOOLEAN = 259,
     tokBOTHARROW = 260,
     tokCOMPLEX = 261,
     tokCOMPLEX_COORD = 262,
     tokCONST = 263,
     tokCONSTI = 264,
     tokCONSTR = 265,
     tokDUMP = 266,
     tokELSE = 267,
     tokEOF = 268,
     tokEOL = 269,
     tokEQ = 270,
     tokEXIT = 271,
     tokEXTERN = 272,
     tokFALSE = 273,
     tokFOR = 274,
     tokGORE = 275,
     tokID = 276,
     tokIF = 277,
     tokINPUT = 278,
     tokINT = 279,
     tokLEFTARROW = 280,
     tokLETTER = 281,
     tokLIST = 282,
     tokLOAD = 283,
     tokLORE = 284,
     tokMEASURE = 285,
     tokMOD = 286,
     tokMULTDOT = 287,
     tokNEQ = 288,
     tokNOT = 289,
     tokOPERATOR = 290,
     tokOR = 291,
     tokPRINT = 292,
     tokPROCEDURE = 293,
     tokQUCONST = 294,
     tokQUFUNCT = 295,
     tokQUREG = 296,
     tokQUSCRATCH = 297,
     tokQUVOID = 298,
     tokREAL = 299,
     tokRESET = 300,
     tokRETURN = 301,
     tokRIGHTARROW = 302,
     tokSAVE = 303,
     tokSET = 304,
     tokSHELL = 305,
     tokSTEP = 306,
     tokSTRING = 307,
     tokSTRINGCONST = 308,
     tokTO = 309,
     tokTRUE = 310,
     tokUNTIL = 311,
     tokWHILE = 312,
     tokXOR = 313,
     UMINUS = 314
   };
#endif
/* Tokens.  */
#define tokAND 258
#define tokBOOLEAN 259
#define tokBOTHARROW 260
#define tokCOMPLEX 261
#define tokCOMPLEX_COORD 262
#define tokCONST 263
#define tokCONSTI 264
#define tokCONSTR 265
#define tokDUMP 266
#define tokELSE 267
#define tokEOF 268
#define tokEOL 269
#define tokEQ 270
#define tokEXIT 271
#define tokEXTERN 272
#define tokFALSE 273
#define tokFOR 274
#define tokGORE 275
#define tokID 276
#define tokIF 277
#define tokINPUT 278
#define tokINT 279
#define tokLEFTARROW 280
#define tokLETTER 281
#define tokLIST 282
#define tokLOAD 283
#define tokLORE 284
#define tokMEASURE 285
#define tokMOD 286
#define tokMULTDOT 287
#define tokNEQ 288
#define tokNOT 289
#define tokOPERATOR 290
#define tokOR 291
#define tokPRINT 292
#define tokPROCEDURE 293
#define tokQUCONST 294
#define tokQUFUNCT 295
#define tokQUREG 296
#define tokQUSCRATCH 297
#define tokQUVOID 298
#define tokREAL 299
#define tokRESET 300
#define tokRETURN 301
#define tokRIGHTARROW 302
#define tokSAVE 303
#define tokSET 304
#define tokSHELL 305
#define tokSTEP 306
#define tokSTRING 307
#define tokSTRINGCONST 308
#define tokTO 309
#define tokTRUE 310
#define tokUNTIL 311
#define tokWHILE 312
#define tokXOR 313
#define UMINUS 314




/* Copy the first part of user declarations.  */
#line 1 "qcl.y"

#include "qcl.hh"
#include "lex.qcl.c"
#include <string>



using namespace std;

#define YYPARSE_PARAM *mainSymbol /// parameter for yyparse


int yyerror(char * s) { return 0;}



/* Enabling traces.  */
#ifndef YYDEBUG
# define YYDEBUG 1
#endif

/* Enabling verbose error messages.  */
#ifdef YYERROR_VERBOSE
# undef YYERROR_VERBOSE
# define YYERROR_VERBOSE 1
#else
# define YYERROR_VERBOSE 0
#endif

/* Enabling the token table.  */
#ifndef YYTOKEN_TABLE
# define YYTOKEN_TABLE 0
#endif

#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE
#line 22 "qcl.y"
{
	Symbol * symbol;
	Identifier * ident;
	Expression * expression;
    Def * definition;
	Value * value;
	SymbolType stype;
	string * STRING;
	int INT;
 	double REAL; 
}
/* Line 193 of yacc.c.  */
#line 250 "qcl.tab.c"
	YYSTYPE;
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
# define YYSTYPE_IS_TRIVIAL 1
#endif



/* Copy the second part of user declarations.  */


/* Line 216 of yacc.c.  */
#line 263 "qcl.tab.c"

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
# if YYENABLE_NLS
#  if ENABLE_NLS
#   include <libintl.h> /* INFRINGES ON USER NAME SPACE */
#   define YY_(msgid) dgettext ("bison-runtime", msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(msgid) msgid
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YYUSE(e) ((void) (e))
#else
# define YYUSE(e) /* empty */
#endif

/* Identity function, used to suppress warnings about constant conditions.  */
#ifndef lint
# define YYID(n) (n)
#else
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static int
YYID (int i)
#else
static int
YYID (i)
    int i;
#endif
{
  return i;
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
#    if ! defined _ALLOCA_H && ! defined _STDLIB_H && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
#     include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#     ifndef _STDLIB_H
#      define _STDLIB_H 1
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
#  if (defined __cplusplus && ! defined _STDLIB_H \
       && ! ((defined YYMALLOC || defined malloc) \
	     && (defined YYFREE || defined free)))
#   include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#   ifndef _STDLIB_H
#    define _STDLIB_H 1
#   endif
#  endif
#  ifndef YYMALLOC
#   define YYMALLOC malloc
#   if ! defined malloc && ! defined _STDLIB_H && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
void *malloc (YYSIZE_T); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
#  ifndef YYFREE
#   define YYFREE free
#   if ! defined free && ! defined _STDLIB_H && (defined __STDC__ || defined __C99__FUNC__ \
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
  yytype_int16 yyss;
  YYSTYPE yyvs;
  };

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (sizeof (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (sizeof (yytype_int16) + sizeof (YYSTYPE)) \
      + YYSTACK_GAP_MAXIMUM)

/* Copy COUNT objects from FROM to TO.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(To, From, Count) \
      __builtin_memcpy (To, From, (Count) * sizeof (*(From)))
#  else
#   define YYCOPY(To, From, Count)		\
      do					\
	{					\
	  YYSIZE_T yyi;				\
	  for (yyi = 0; yyi < (Count); yyi++)	\
	    (To)[yyi] = (From)[yyi];		\
	}					\
      while (YYID (0))
#  endif
# endif

/* Relocate STACK from its old location to the new one.  The
   local variables YYSIZE and YYSTACKSIZE give the old and new number of
   elements in the stack, and YYPTR gives the new location of the
   stack.  Advance YYPTR to a properly aligned location for the next
   stack.  */
# define YYSTACK_RELOCATE(Stack)					\
    do									\
      {									\
	YYSIZE_T yynewbytes;						\
	YYCOPY (&yyptr->Stack, Stack, yysize);				\
	Stack = &yyptr->Stack;						\
	yynewbytes = yystacksize * sizeof (*Stack) + YYSTACK_GAP_MAXIMUM; \
	yyptr += yynewbytes / sizeof (*yyptr);				\
      }									\
    while (YYID (0))

#endif

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  91
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   1894

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  83
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  18
/* YYNRULES -- Number of rules.  */
#define YYNRULES  109
/* YYNRULES -- Number of states.  */
#define YYNSTATES  243

/* YYTRANSLATE(YYLEX) -- Bison symbol number corresponding to YYLEX.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   315

#define YYTRANSLATE(YYX)						\
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[YYLEX] -- Bison symbol number corresponding to YYLEX.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
      67,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    77,     2,    65,     2,     2,    61,     2,
      68,    70,    63,    76,    69,    71,     2,    62,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,    73,    78,
      59,    79,    60,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,    72,    75,    74,    64,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    81,     2,    82,     2,     2,     2,     2,
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
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
      45,    46,    47,    48,    49,    50,    51,    52,    53,    54,
      55,    56,    57,    58,    66,    80
};

#if YYDEBUG
/* YYPRHS[YYN] -- Index of the first RHS symbol of rule number YYN in
   YYRHS.  */
static const yytype_uint16 yyprhs[] =
{
       0,     0,     3,     6,     8,    10,    13,    16,    19,    22,
      28,    31,    33,    35,    37,    39,    41,    45,    47,    49,
      56,    63,    70,    75,    77,    82,    86,    89,    93,    96,
     100,   104,   108,   112,   116,   120,   124,   128,   132,   136,
     140,   144,   147,   151,   155,   159,   160,   162,   166,   168,
     175,   181,   186,   191,   196,   201,   211,   219,   223,   228,
     234,   238,   242,   246,   252,   256,   260,   263,   267,   273,
     276,   279,   283,   286,   290,   293,   297,   300,   303,   305,
     307,   309,   311,   313,   315,   317,   319,   321,   327,   334,
     340,   344,   347,   351,   353,   354,   358,   362,   366,   369,
     371,   373,   378,   383,   388,   393,   398,   403,   407,   409
};

/* YYRHS -- A `-1'-separated list of the rules' RHS.  */
static const yytype_int8 yyrhs[] =
{
      84,     0,    -1,    85,    13,    -1,    90,    -1,    98,    -1,
      90,    85,    -1,    98,    85,    -1,     1,    67,    -1,     1,
      13,    -1,    68,    86,    69,    86,    70,    -1,    71,    86,
      -1,     7,    -1,     9,    -1,    55,    -1,    18,    -1,    53,
      -1,    68,     1,    70,    -1,     1,    -1,    86,    -1,    89,
      72,    87,    73,    87,    74,    -1,    89,    72,    87,    32,
      87,    74,    -1,    89,    72,    87,    75,    87,    74,    -1,
      89,    72,    87,    74,    -1,    89,    -1,    89,    68,    88,
      70,    -1,    68,    87,    70,    -1,    65,    87,    -1,    87,
      64,    87,    -1,    71,    87,    -1,    87,    63,    87,    -1,
      87,    62,    87,    -1,    87,    31,    87,    -1,    87,    76,
      87,    -1,    87,    71,    87,    -1,    87,    61,    87,    -1,
      87,    15,    87,    -1,    87,    33,    87,    -1,    87,    59,
      87,    -1,    87,    29,    87,    -1,    87,    60,    87,    -1,
      87,    20,    87,    -1,    34,    87,    -1,    87,     3,    87,
      -1,    87,    36,    87,    -1,    87,    58,    87,    -1,    -1,
      87,    -1,    87,    69,    88,    -1,    21,    -1,    77,    89,
      68,    88,    70,    78,    -1,    89,    68,    88,    70,    78,
      -1,    89,    79,    87,    78,    -1,    87,    25,    87,    78,
      -1,    87,    47,    87,    78,    -1,    87,     5,    87,    78,
      -1,    19,    89,    79,    87,    54,    87,    51,    87,    99,
      -1,    19,    89,    79,    87,    54,    87,    99,    -1,    57,
      87,    99,    -1,    99,    56,    87,    78,    -1,    22,    87,
      99,    12,    99,    -1,    22,    87,    99,    -1,    46,    87,
      78,    -1,    23,    89,    78,    -1,    23,    87,    69,    89,
      78,    -1,    37,    88,    78,    -1,    16,    87,    78,    -1,
      16,    78,    -1,    30,    87,    78,    -1,    30,    87,    69,
      89,    78,    -1,    45,    78,    -1,    11,    78,    -1,    11,
      87,    78,    -1,    28,    78,    -1,    28,    87,    78,    -1,
      48,    78,    -1,    48,    87,    78,    -1,    50,    78,    -1,
      90,    80,    -1,     4,    -1,    24,    -1,    44,    -1,     6,
      -1,    52,    -1,    41,    -1,    43,    -1,    39,    -1,    42,
      -1,     8,    89,    79,    87,    78,    -1,    91,    89,    72,
      87,    74,    78,    -1,    91,    89,    79,    87,    78,    -1,
      91,    89,    78,    -1,    91,    89,    -1,    94,    69,    95,
      -1,    94,    -1,    -1,    68,    95,    70,    -1,    68,     1,
      70,    -1,    81,    85,    82,    -1,    81,    82,    -1,    92,
      -1,    93,    -1,    91,    89,    96,    97,    -1,    38,    89,
      96,    97,    -1,    35,    89,    96,    97,    -1,    40,    89,
      96,    97,    -1,    17,    35,    89,    96,    -1,    17,    40,
      89,    96,    -1,    81,   100,    82,    -1,    90,    -1,    90,
     100,    -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,   115,   115,   118,   119,   120,   121,   122,   123,   131,
     132,   133,   134,   135,   136,   137,   138,   139,   144,   145,
     146,   147,   148,   149,   150,   151,   152,   153,   154,   155,
     156,   157,   158,   159,   160,   161,   162,   163,   164,   165,
     166,   167,   168,   169,   170,   173,   174,   175,   179,   189,
     190,   191,   192,   193,   194,   195,   197,   198,   199,   200,
     201,   202,   203,   204,   205,   206,   207,   208,   209,   210,
     211,   212,   213,   214,   215,   216,   217,   220,   229,   230,
     231,   232,   233,   234,   235,   236,   237,   240,   242,   243,
     244,   247,   250,   251,   252,   255,   256,   259,   260,   264,
     265,   266,   267,   268,   269,   270,   271,   274,   277,   278
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || YYTOKEN_TABLE
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "tokAND", "tokBOOLEAN", "tokBOTHARROW",
  "tokCOMPLEX", "tokCOMPLEX_COORD", "tokCONST", "tokCONSTI", "tokCONSTR",
  "tokDUMP", "tokELSE", "tokEOF", "tokEOL", "tokEQ", "tokEXIT",
  "tokEXTERN", "tokFALSE", "tokFOR", "tokGORE", "tokID", "tokIF",
  "tokINPUT", "tokINT", "tokLEFTARROW", "tokLETTER", "tokLIST", "tokLOAD",
  "tokLORE", "tokMEASURE", "tokMOD", "tokMULTDOT", "tokNEQ", "tokNOT",
  "tokOPERATOR", "tokOR", "tokPRINT", "tokPROCEDURE", "tokQUCONST",
  "tokQUFUNCT", "tokQUREG", "tokQUSCRATCH", "tokQUVOID", "tokREAL",
  "tokRESET", "tokRETURN", "tokRIGHTARROW", "tokSAVE", "tokSET",
  "tokSHELL", "tokSTEP", "tokSTRING", "tokSTRINGCONST", "tokTO", "tokTRUE",
  "tokUNTIL", "tokWHILE", "tokXOR", "'<'", "'>'", "'&'", "'/'", "'*'",
  "'^'", "'#'", "UMINUS", "'\\n'", "'('", "','", "')'", "'-'", "'['",
  "':'", "']'", "'\\\\'", "'+'", "'!'", "';'", "'='", "\";\"", "'{'",
  "'}'", "$accept", "qcl_input", "top_symbol", "const", "expr", "expr1",
  "identifier", "stmt", "type", "const_def", "var_def", "arg_def",
  "arg_def1", "arg_list", "body", "def", "block", "block1", 0
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
     285,   286,   287,   288,   289,   290,   291,   292,   293,   294,
     295,   296,   297,   298,   299,   300,   301,   302,   303,   304,
     305,   306,   307,   308,   309,   310,   311,   312,   313,    60,
      62,    38,    47,    42,    94,    35,   314,    10,    40,    44,
      41,    45,    91,    58,    93,    92,    43,    33,    59,    61,
     315,   123,   125
};
# endif

/* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    83,    84,    85,    85,    85,    85,    85,    85,    86,
      86,    86,    86,    86,    86,    86,    86,    86,    87,    87,
      87,    87,    87,    87,    87,    87,    87,    87,    87,    87,
      87,    87,    87,    87,    87,    87,    87,    87,    87,    87,
      87,    87,    87,    87,    87,    88,    88,    88,    89,    90,
      90,    90,    90,    90,    90,    90,    90,    90,    90,    90,
      90,    90,    90,    90,    90,    90,    90,    90,    90,    90,
      90,    90,    90,    90,    90,    90,    90,    90,    91,    91,
      91,    91,    91,    91,    91,    91,    91,    92,    93,    93,
      93,    94,    95,    95,    95,    96,    96,    97,    97,    98,
      98,    98,    98,    98,    98,    98,    98,    99,   100,   100
};

/* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     2,     1,     1,     2,     2,     2,     2,     5,
       2,     1,     1,     1,     1,     1,     3,     1,     1,     6,
       6,     6,     4,     1,     4,     3,     2,     3,     2,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     2,     3,     3,     3,     0,     1,     3,     1,     6,
       5,     4,     4,     4,     4,     9,     7,     3,     4,     5,
       3,     3,     3,     5,     3,     3,     2,     3,     5,     2,
       2,     3,     2,     3,     2,     3,     2,     2,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     5,     6,     5,
       3,     2,     3,     1,     0,     3,     3,     3,     2,     1,
       1,     4,     4,     4,     4,     4,     4,     3,     1,     2
};

/* YYDEFACT[STATE-NAME] -- Default rule to reduce with in state
   STATE-NUM when YYTABLE doesn't specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,    17,    78,    81,    11,     0,    12,     0,     0,     0,
      14,     0,    48,     0,     0,    79,     0,     0,     0,     0,
       0,     0,    85,     0,    83,    86,    84,    80,     0,     0,
       0,     0,    82,    15,    13,     0,     0,     0,     0,     0,
       0,     0,     0,    18,     0,    23,     0,     0,    99,   100,
       0,     0,     8,     7,     0,    17,    70,     0,    23,    66,
       0,     0,     0,     0,     0,     0,    23,    72,     0,     0,
      41,     0,    46,     0,     0,     0,    69,     0,    74,     0,
      76,     0,    26,    17,    18,     0,    10,    28,     0,     0,
       0,     1,     2,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    77,     5,     0,     6,     0,
       0,    71,     0,    65,     0,     0,     0,    60,     0,    62,
      73,     0,    67,     0,     0,     0,    64,     0,     0,    61,
      75,    57,    16,     0,    25,     0,   109,   107,    42,     0,
      35,    40,     0,    38,    31,    36,    43,     0,    44,    37,
      39,    34,    30,    29,    27,    33,    32,     0,     0,     0,
       0,    90,     0,     0,     0,     0,     0,   105,   106,     0,
       0,     0,     0,     0,     0,    93,     0,     0,   103,    47,
     102,   104,     0,     0,     0,     0,    54,    52,    53,    24,
       0,     0,    22,     0,    51,     0,     0,   101,    58,    87,
      24,     0,    59,    63,    68,    96,    91,    94,    95,    98,
       0,     0,    10,     9,     0,    50,     0,     0,     0,     0,
      89,     0,    92,    97,    49,    20,    19,    21,    88,     0,
      56,     0,    55
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,    41,    42,    43,    44,    73,    58,    46,    47,    48,
      49,   185,   186,   134,   188,    50,    51,    90
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -123
static const yytype_int16 yypact[] =
{
     517,    -5,  -123,  -123,  -123,     4,  -123,   708,   712,   -23,
    -123,     4,  -123,  1789,  1789,  -123,   734,  1789,  1789,     4,
     763,     4,  -123,     4,  -123,  -123,  -123,  -123,   -51,  1789,
     799,   -44,  -123,  -123,  -123,  1789,  1789,  1790,  1789,     4,
     586,    36,    25,  -123,  1354,   -27,   205,     4,  -123,  -123,
     287,    -8,  -123,  -123,   -30,  -123,  -123,   870,   -13,  -123,
     906,     4,     4,   -21,   114,  1390,   -22,  -123,   942,   820,
     139,    11,  1440,     6,    11,    11,  -123,   978,  -123,  1014,
    -123,   114,    50,     0,    47,  1459,  -123,    50,    12,   435,
      41,  -123,  -123,  1789,  1789,  1789,  1789,  1789,  1789,  1789,
    1789,  1789,  1789,  1789,  1789,  1789,  1789,  1789,  1789,  1789,
    1789,  1789,  1749,  1789,  1789,  -123,  -123,   -25,  -123,  1789,
    1789,  -123,  1749,  -123,    11,    11,  1789,   112,     4,  -123,
    -123,     4,  -123,  1824,    44,   669,  -123,    44,    44,  -123,
    -123,  -123,  -123,   113,  -123,  1749,  -123,  -123,   139,  1050,
    1668,  1668,  1086,  1668,  1718,  1668,     2,  1122,     2,  1668,
    1668,   203,    80,    80,    50,  1718,  1718,    57,  1302,  1158,
    1789,  -123,  1789,    44,  1194,  1230,    60,  -123,  -123,  1511,
      51,    55,    58,    65,     4,    68,    69,   366,  -123,  -123,
    -123,  -123,   283,   113,    70,    71,  -123,  -123,  -123,    64,
    1789,  1789,  -123,  1789,  -123,  1530,  1266,  -123,  -123,  -123,
    -123,  1789,  -123,  -123,  -123,  -123,  -123,    33,  -123,  -123,
      66,    47,  -123,  -123,    75,  -123,  1580,  1599,  1649,    76,
    -123,   635,  -123,  -123,  -123,  -123,  -123,  -123,  -123,  1789,
    -123,   114,  -123
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -123,  -123,   -32,   -34,    -7,    85,    21,   -20,  -109,  -123,
    -123,  -123,   -71,   274,  -122,  -123,   -62,    72
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If zero, do what YYDEFACT says.
   If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -109
static const yytype_int16 yytable[] =
{
      57,    60,   127,    84,    86,    93,    64,    65,    52,    68,
      69,    70,    61,    72,   116,   190,   191,    62,   118,   141,
      89,    45,    77,    79,   184,    12,    54,    76,    81,    82,
      85,    87,    63,    99,    80,    66,    91,     2,    92,     3,
      71,   112,    74,   133,    75,   113,   122,   170,   119,   120,
     113,   207,   114,   171,   172,   122,   129,    15,   126,   113,
      88,    45,    53,   106,   107,   108,   109,    45,   117,    89,
     142,    45,    22,   110,    24,    25,    26,    27,   111,   133,
     145,    99,   124,   125,   136,    32,   148,   149,   150,   151,
     152,   153,   154,   155,   156,   157,   158,   159,   160,   161,
     162,   163,   164,   165,   166,    72,   168,   169,   184,   194,
      45,    99,   174,   175,    55,    72,   143,    93,   212,   179,
       4,   110,     6,   147,   180,   187,   111,   199,    72,    95,
     210,    10,    40,   213,    96,   215,   214,   217,    72,   218,
     223,   224,   225,    98,   109,    99,   232,   100,   233,   181,
     101,   110,   182,   234,   238,   220,   111,     0,   221,   222,
       0,   146,     0,   205,     0,   206,    33,     0,    34,   240,
      99,     0,   103,   104,   105,   106,   107,   108,   109,   242,
       0,   192,     0,     0,   193,   110,     0,     0,     0,     0,
     111,     0,     0,   226,   227,    40,   228,   167,     0,     0,
     106,   107,   108,   109,   231,   216,     1,   176,    45,     2,
     110,     3,     4,     5,     6,   111,     7,     0,    -3,     0,
     189,     8,     9,    10,    11,     0,    12,    13,    14,    15,
     195,     0,   241,    16,    99,    17,     0,     0,     0,    18,
      19,     0,    20,    21,    22,    23,    24,    25,    26,    27,
      28,    29,     0,    30,     0,    31,     0,    32,    33,     0,
      34,     0,    35,     0,     0,   107,   108,   109,     0,     0,
      36,     0,     0,    37,   110,     0,    38,     0,     0,   111,
       0,     0,    39,     0,    83,   115,    40,    -3,     1,     0,
       4,     2,     6,     3,     4,     5,     6,     0,     7,     0,
      -4,    10,     0,     8,     9,    10,    11,     0,    12,    13,
      14,    15,     0,     0,     0,    16,     0,    17,     0,     0,
       0,    18,    19,     0,    20,    21,    22,    23,    24,    25,
      26,    27,    28,    29,     0,    30,    33,    31,    34,    32,
      33,     0,    34,     0,    35,     0,     0,     0,   137,   138,
       0,   192,    36,     0,   193,    37,     0,     0,    38,     0,
       0,     0,     0,     0,    39,     0,     0,     1,    40,    -4,
       2,     0,     3,     4,     5,     6,     0,     7,     0,     0,
       0,     0,     8,     9,    10,    11,     0,    12,    13,    14,
      15,   173,     0,     0,    16,     0,    17,     0,   177,   178,
      18,    19,     0,    20,    21,    22,    23,    24,    25,    26,
      27,    28,    29,     0,    30,     0,    31,     0,    32,    33,
       0,    34,     0,    35,     0,     0,     0,     0,     0,     0,
       0,    36,     0,     0,    37,     0,    55,    38,     0,     0,
       0,     0,     4,    39,     6,     0,     7,    40,   219,     0,
       0,     8,     0,    10,    11,     0,    12,    13,    14,     0,
       0,     0,     0,    16,     0,    17,     0,     0,     0,    18,
       0,     0,    20,     0,     0,     0,     0,     0,     0,     0,
      28,    29,     0,    30,     0,    31,     0,     0,    33,     0,
      34,     0,    35,     0,     0,     0,     0,     0,     0,     0,
      36,     0,     0,    37,     0,     0,    38,     0,     0,     0,
       0,     0,    39,     0,     0,   115,    40,  -108,     1,     0,
       0,     2,     0,     3,     4,     5,     6,     0,     7,     0,
       0,     0,     0,     8,     9,    10,    11,     0,    12,    13,
      14,    15,     0,     0,     0,    16,     0,    17,     0,     0,
       0,    18,    19,     0,    20,    21,    22,    23,    24,    25,
      26,    27,    28,    29,     0,    30,     0,    31,     0,    32,
      33,     0,    34,     0,    35,     0,     0,     0,     0,     0,
       0,     0,    36,     0,     0,    37,     0,    55,    38,     0,
       0,     0,     0,     4,    39,     6,     0,     7,    40,     0,
       0,     0,     8,     0,    10,    11,     0,    12,    13,    14,
       0,     0,     0,     0,    16,     0,    17,     0,     0,     0,
      18,     0,     0,    20,     0,     0,     0,     0,     0,     0,
       0,    28,    29,     0,    30,     0,    31,     0,    93,    33,
       0,    34,     0,    35,     0,     0,     0,     0,     0,     0,
      95,    36,     0,     0,    37,    96,     0,    38,     0,     0,
       0,     0,     0,    39,    98,     0,    99,    40,   100,     0,
      55,   101,     0,     0,     0,     0,     4,     0,     6,     0,
       0,     0,     0,     0,     0,     0,   239,    10,     0,     0,
      12,     0,     0,   103,   104,   105,   106,   107,   108,   109,
       0,     0,     0,    18,     0,     0,   110,     0,     0,    55,
       0,   111,     0,    55,     0,     4,    40,     6,     0,     4,
       0,     6,    33,     0,    34,     0,    10,     0,     0,    12,
      10,     0,     0,    12,    36,    55,     0,    37,     0,   -45,
      38,     4,    18,     6,     0,     0,    18,   -45,     0,     0,
       0,     0,    10,     0,     0,    12,     0,     0,     0,     0,
       0,    33,     0,    34,    55,    33,     0,    34,    18,     0,
       4,     0,     6,    36,     0,     0,    37,    36,     0,    38,
      37,    10,     0,    38,    12,     0,    56,    33,     0,    34,
      59,     0,     0,     0,     0,     0,     0,    18,     0,    36,
      55,     0,    37,     0,     0,    38,     4,     0,     6,     0,
       0,     0,    67,     0,     0,     0,    33,    10,    34,     0,
      12,     0,     0,    93,     0,     0,     0,     0,    36,     0,
       0,    37,     0,    18,    38,    95,     0,     0,     0,     0,
      96,   -45,     0,     0,     0,     0,     0,     0,     0,    98,
       0,    99,    33,   100,    34,     0,   101,     0,     0,     0,
       0,     0,     0,     0,    36,     0,     0,    37,     0,     0,
      38,     0,     0,    93,     0,     0,     0,    78,   103,   104,
     105,   106,   107,   108,   109,    95,     0,     0,     0,   131,
      96,   110,     0,     0,     0,     0,   111,     0,   132,    98,
       0,    99,     0,   100,     0,     0,   101,     0,     0,    93,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    95,     0,     0,     0,     0,    96,     0,   103,   104,
     105,   106,   107,   108,   109,    98,     0,    99,     0,   100,
       0,   110,   101,     0,     0,    93,   111,     0,   121,     0,
       0,     0,     0,     0,     0,     0,     0,    95,     0,     0,
       0,     0,    96,     0,   103,   104,   105,   106,   107,   108,
     109,    98,     0,    99,     0,   100,     0,   110,   101,     0,
       0,    93,   111,     0,   123,     0,     0,     0,     0,     0,
       0,     0,     0,    95,     0,     0,     0,     0,    96,     0,
     103,   104,   105,   106,   107,   108,   109,    98,     0,    99,
       0,   100,     0,   110,   101,     0,     0,    93,   111,     0,
     130,     0,     0,     0,     0,     0,     0,     0,     0,    95,
       0,     0,     0,     0,    96,     0,   103,   104,   105,   106,
     107,   108,   109,    98,     0,    99,     0,   100,     0,   110,
     101,     0,     0,    93,   111,     0,   139,     0,     0,     0,
       0,     0,     0,     0,     0,    95,     0,     0,     0,     0,
      96,     0,   103,   104,   105,   106,   107,   108,   109,    98,
       0,    99,     0,   100,     0,   110,   101,     0,     0,    93,
     111,     0,   140,     0,     0,     0,     0,     0,     0,     0,
       0,    95,     0,     0,     0,     0,    96,     0,   103,   104,
     105,   106,   107,   108,   109,    98,     0,    99,     0,   100,
       0,   110,   101,     0,     0,    93,   111,     0,   196,     0,
       0,     0,     0,     0,     0,     0,     0,    95,     0,     0,
       0,     0,    96,     0,   103,   104,   105,   106,   107,   108,
     109,    98,     0,    99,     0,   100,     0,   110,   101,     0,
       0,    93,   111,     0,   197,     0,     0,     0,     0,     0,
       0,     0,     0,    95,     0,     0,     0,     0,    96,     0,
     103,   104,   105,   106,   107,   108,   109,    98,     0,    99,
       0,   100,     0,   110,   101,     0,     0,    93,   111,     0,
     198,     0,     0,     0,     0,     0,     0,     0,     0,    95,
       0,     0,     0,     0,    96,     0,   103,   104,   105,   106,
     107,   108,   109,    98,     0,    99,     0,   100,     0,   110,
     101,     0,     0,    93,   111,     0,   204,     0,     0,     0,
       0,     0,     0,     0,     0,    95,     0,     0,     0,     0,
      96,     0,   103,   104,   105,   106,   107,   108,   109,    98,
       0,    99,     0,   100,     0,   110,   101,     0,     0,    93,
     111,     0,   208,     0,     0,     0,     0,     0,     0,     0,
       0,    95,     0,     0,     0,     0,    96,     0,   103,   104,
     105,   106,   107,   108,   109,    98,     0,    99,     0,   100,
       0,   110,   101,     0,     0,    93,   111,     0,   209,     0,
       0,     0,     0,     0,     0,     0,     0,    95,     0,     0,
       0,     0,    96,     0,   103,   104,   105,   106,   107,   108,
     109,    98,     0,    99,   200,   100,     0,   110,   101,     0,
       0,     0,   111,     0,   230,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    93,     0,    94,
     103,   104,   105,   106,   107,   108,   109,     0,     0,    95,
       0,     0,     0,   110,    96,   201,   202,   203,   111,    97,
       0,     0,     0,    98,     0,    99,     0,   100,     0,     0,
     101,     0,     0,    93,     0,     0,     0,     0,     0,     0,
       0,   102,     0,     0,     0,    95,     0,     0,     0,     0,
      96,     0,   103,   104,   105,   106,   107,   108,   109,    98,
       0,    99,     0,   100,     0,   110,   101,     0,     0,     0,
     111,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    93,     0,     0,     0,     0,   103,   104,
     105,   106,   107,   108,   109,    95,     0,     0,     0,   128,
      96,   110,    93,     0,     0,     0,   111,     0,     0,    98,
       0,    99,     0,   100,    95,     0,   101,     0,     0,    96,
       0,     0,     0,     0,     0,     0,     0,     0,    98,     0,
      99,     0,   100,     0,     0,   101,     0,     0,   103,   104,
     105,   106,   107,   108,   109,     0,     0,     0,     0,   135,
       0,   110,     0,     0,    93,     0,   111,   103,   104,   105,
     106,   107,   108,   109,     0,     0,    95,     0,     0,   144,
     110,    96,     0,    93,     0,   111,     0,     0,     0,     0,
      98,     0,    99,     0,   100,    95,     0,   101,     0,     0,
      96,     0,     0,     0,     0,     0,     0,     0,     0,    98,
       0,    99,     0,   100,     0,   211,   101,     0,     0,   103,
     104,   105,   106,   107,   108,   109,     0,     0,     0,     0,
       0,     0,   110,    93,     0,     0,     0,   111,   103,   104,
     105,   106,   107,   108,   109,    95,     0,     0,     0,     0,
      96,   110,    93,     0,   229,     0,   111,     0,     0,    98,
       0,    99,     0,   100,    95,     0,   101,     0,     0,    96,
       0,     0,     0,     0,     0,     0,     0,     0,    98,     0,
      99,     0,   100,     0,     0,   101,     0,     0,   103,   104,
     105,   106,   107,   108,   109,     0,     0,     0,     0,     0,
       0,   110,    93,     0,   235,     0,   111,   103,   104,   105,
     106,   107,   108,   109,    95,     0,     0,     0,     0,    96,
     110,    93,     0,   236,     0,   111,     0,     0,    98,     0,
      99,     0,   100,  -109,     0,   101,     0,     0,  -109,     0,
       0,     0,     0,     0,     0,     0,     0,  -109,     0,    99,
       0,  -109,     0,     0,   101,     0,     0,   103,   104,   105,
     106,   107,   108,   109,     0,     0,     0,     0,     0,     0,
     110,    93,     0,   237,     0,   111,   103,  -109,  -109,   106,
     107,   108,   109,    95,     0,     0,     0,     0,    96,   110,
       0,     0,     0,     0,   111,     0,     0,    98,     0,    99,
      55,   100,     0,     0,   101,     0,     4,     0,     6,     0,
       0,     0,     0,     0,     0,     0,     0,    10,     0,     0,
      12,     0,     0,     0,     0,     0,   103,   104,   105,   106,
     107,   108,   109,    18,     0,     0,     0,     0,     0,   110,
      55,    83,     0,     0,   111,     0,     4,     4,     6,     6,
       0,     0,    33,     0,    34,     0,     0,    10,    10,     0,
      12,    12,     0,     0,    36,     0,     0,    37,     0,   -45,
      38,     0,     0,    18,    18,   183,     0,     0,     2,     0,
       3,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    33,    33,    34,    34,     0,     0,    15,     0,
       0,     0,     0,     0,    36,    36,     0,    37,    37,     0,
      38,    38,     0,    22,     0,    24,    25,    26,    27,     0,
       0,     0,     0,     0,     0,     0,    32,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   -94
};

static const yytype_int16 yycheck[] =
{
       7,     8,    64,    37,    38,     3,    13,    14,    13,    16,
      17,    18,    35,    20,    46,   137,   138,    40,    50,    81,
      40,     0,    29,    30,   133,    21,     5,    78,    35,    36,
      37,    38,    11,    31,    78,    14,     0,     4,    13,     6,
      19,    68,    21,    68,    23,    72,    68,    72,    56,    79,
      72,   173,    79,    78,    79,    68,    78,    24,    79,    72,
      39,    40,    67,    61,    62,    63,    64,    46,    47,    89,
      70,    50,    39,    71,    41,    42,    43,    44,    76,    68,
      68,    31,    61,    62,    78,    52,    93,    94,    95,    96,
      97,    98,    99,   100,   101,   102,   103,   104,   105,   106,
     107,   108,   109,   110,   111,   112,   113,   114,   217,   143,
      89,    31,   119,   120,     1,   122,    69,     3,   180,   126,
       7,    71,     9,    82,    12,    81,    76,    70,   135,    15,
      70,    18,    81,    78,    20,    70,    78,    69,   145,    70,
      70,    70,    78,    29,    64,    31,   217,    33,    82,   128,
      36,    71,   131,    78,    78,   187,    76,    -1,   192,   193,
      -1,    89,    -1,   170,    -1,   172,    53,    -1,    55,   231,
      31,    -1,    58,    59,    60,    61,    62,    63,    64,   241,
      -1,    68,    -1,    -1,    71,    71,    -1,    -1,    -1,    -1,
      76,    -1,    -1,   200,   201,    81,   203,   112,    -1,    -1,
      61,    62,    63,    64,   211,   184,     1,   122,   187,     4,
      71,     6,     7,     8,     9,    76,    11,    -1,    13,    -1,
     135,    16,    17,    18,    19,    -1,    21,    22,    23,    24,
     145,    -1,   239,    28,    31,    30,    -1,    -1,    -1,    34,
      35,    -1,    37,    38,    39,    40,    41,    42,    43,    44,
      45,    46,    -1,    48,    -1,    50,    -1,    52,    53,    -1,
      55,    -1,    57,    -1,    -1,    62,    63,    64,    -1,    -1,
      65,    -1,    -1,    68,    71,    -1,    71,    -1,    -1,    76,
      -1,    -1,    77,    -1,     1,    80,    81,    82,     1,    -1,
       7,     4,     9,     6,     7,     8,     9,    -1,    11,    -1,
      13,    18,    -1,    16,    17,    18,    19,    -1,    21,    22,
      23,    24,    -1,    -1,    -1,    28,    -1,    30,    -1,    -1,
      -1,    34,    35,    -1,    37,    38,    39,    40,    41,    42,
      43,    44,    45,    46,    -1,    48,    53,    50,    55,    52,
      53,    -1,    55,    -1,    57,    -1,    -1,    -1,    74,    75,
      -1,    68,    65,    -1,    71,    68,    -1,    -1,    71,    -1,
      -1,    -1,    -1,    -1,    77,    -1,    -1,     1,    81,    82,
       4,    -1,     6,     7,     8,     9,    -1,    11,    -1,    -1,
      -1,    -1,    16,    17,    18,    19,    -1,    21,    22,    23,
      24,   117,    -1,    -1,    28,    -1,    30,    -1,   124,   125,
      34,    35,    -1,    37,    38,    39,    40,    41,    42,    43,
      44,    45,    46,    -1,    48,    -1,    50,    -1,    52,    53,
      -1,    55,    -1,    57,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    65,    -1,    -1,    68,    -1,     1,    71,    -1,    -1,
      -1,    -1,     7,    77,     9,    -1,    11,    81,    82,    -1,
      -1,    16,    -1,    18,    19,    -1,    21,    22,    23,    -1,
      -1,    -1,    -1,    28,    -1,    30,    -1,    -1,    -1,    34,
      -1,    -1,    37,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      45,    46,    -1,    48,    -1,    50,    -1,    -1,    53,    -1,
      55,    -1,    57,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      65,    -1,    -1,    68,    -1,    -1,    71,    -1,    -1,    -1,
      -1,    -1,    77,    -1,    -1,    80,    81,    82,     1,    -1,
      -1,     4,    -1,     6,     7,     8,     9,    -1,    11,    -1,
      -1,    -1,    -1,    16,    17,    18,    19,    -1,    21,    22,
      23,    24,    -1,    -1,    -1,    28,    -1,    30,    -1,    -1,
      -1,    34,    35,    -1,    37,    38,    39,    40,    41,    42,
      43,    44,    45,    46,    -1,    48,    -1,    50,    -1,    52,
      53,    -1,    55,    -1,    57,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    65,    -1,    -1,    68,    -1,     1,    71,    -1,
      -1,    -1,    -1,     7,    77,     9,    -1,    11,    81,    -1,
      -1,    -1,    16,    -1,    18,    19,    -1,    21,    22,    23,
      -1,    -1,    -1,    -1,    28,    -1,    30,    -1,    -1,    -1,
      34,    -1,    -1,    37,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    45,    46,    -1,    48,    -1,    50,    -1,     3,    53,
      -1,    55,    -1,    57,    -1,    -1,    -1,    -1,    -1,    -1,
      15,    65,    -1,    -1,    68,    20,    -1,    71,    -1,    -1,
      -1,    -1,    -1,    77,    29,    -1,    31,    81,    33,    -1,
       1,    36,    -1,    -1,    -1,    -1,     7,    -1,     9,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    51,    18,    -1,    -1,
      21,    -1,    -1,    58,    59,    60,    61,    62,    63,    64,
      -1,    -1,    -1,    34,    -1,    -1,    71,    -1,    -1,     1,
      -1,    76,    -1,     1,    -1,     7,    81,     9,    -1,     7,
      -1,     9,    53,    -1,    55,    -1,    18,    -1,    -1,    21,
      18,    -1,    -1,    21,    65,     1,    -1,    68,    -1,    70,
      71,     7,    34,     9,    -1,    -1,    34,    78,    -1,    -1,
      -1,    -1,    18,    -1,    -1,    21,    -1,    -1,    -1,    -1,
      -1,    53,    -1,    55,     1,    53,    -1,    55,    34,    -1,
       7,    -1,     9,    65,    -1,    -1,    68,    65,    -1,    71,
      68,    18,    -1,    71,    21,    -1,    78,    53,    -1,    55,
      78,    -1,    -1,    -1,    -1,    -1,    -1,    34,    -1,    65,
       1,    -1,    68,    -1,    -1,    71,     7,    -1,     9,    -1,
      -1,    -1,    78,    -1,    -1,    -1,    53,    18,    55,    -1,
      21,    -1,    -1,     3,    -1,    -1,    -1,    -1,    65,    -1,
      -1,    68,    -1,    34,    71,    15,    -1,    -1,    -1,    -1,
      20,    78,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    29,
      -1,    31,    53,    33,    55,    -1,    36,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    65,    -1,    -1,    68,    -1,    -1,
      71,    -1,    -1,     3,    -1,    -1,    -1,    78,    58,    59,
      60,    61,    62,    63,    64,    15,    -1,    -1,    -1,    69,
      20,    71,    -1,    -1,    -1,    -1,    76,    -1,    78,    29,
      -1,    31,    -1,    33,    -1,    -1,    36,    -1,    -1,     3,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    15,    -1,    -1,    -1,    -1,    20,    -1,    58,    59,
      60,    61,    62,    63,    64,    29,    -1,    31,    -1,    33,
      -1,    71,    36,    -1,    -1,     3,    76,    -1,    78,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    15,    -1,    -1,
      -1,    -1,    20,    -1,    58,    59,    60,    61,    62,    63,
      64,    29,    -1,    31,    -1,    33,    -1,    71,    36,    -1,
      -1,     3,    76,    -1,    78,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    15,    -1,    -1,    -1,    -1,    20,    -1,
      58,    59,    60,    61,    62,    63,    64,    29,    -1,    31,
      -1,    33,    -1,    71,    36,    -1,    -1,     3,    76,    -1,
      78,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    15,
      -1,    -1,    -1,    -1,    20,    -1,    58,    59,    60,    61,
      62,    63,    64,    29,    -1,    31,    -1,    33,    -1,    71,
      36,    -1,    -1,     3,    76,    -1,    78,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    15,    -1,    -1,    -1,    -1,
      20,    -1,    58,    59,    60,    61,    62,    63,    64,    29,
      -1,    31,    -1,    33,    -1,    71,    36,    -1,    -1,     3,
      76,    -1,    78,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    15,    -1,    -1,    -1,    -1,    20,    -1,    58,    59,
      60,    61,    62,    63,    64,    29,    -1,    31,    -1,    33,
      -1,    71,    36,    -1,    -1,     3,    76,    -1,    78,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    15,    -1,    -1,
      -1,    -1,    20,    -1,    58,    59,    60,    61,    62,    63,
      64,    29,    -1,    31,    -1,    33,    -1,    71,    36,    -1,
      -1,     3,    76,    -1,    78,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    15,    -1,    -1,    -1,    -1,    20,    -1,
      58,    59,    60,    61,    62,    63,    64,    29,    -1,    31,
      -1,    33,    -1,    71,    36,    -1,    -1,     3,    76,    -1,
      78,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    15,
      -1,    -1,    -1,    -1,    20,    -1,    58,    59,    60,    61,
      62,    63,    64,    29,    -1,    31,    -1,    33,    -1,    71,
      36,    -1,    -1,     3,    76,    -1,    78,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    15,    -1,    -1,    -1,    -1,
      20,    -1,    58,    59,    60,    61,    62,    63,    64,    29,
      -1,    31,    -1,    33,    -1,    71,    36,    -1,    -1,     3,
      76,    -1,    78,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    15,    -1,    -1,    -1,    -1,    20,    -1,    58,    59,
      60,    61,    62,    63,    64,    29,    -1,    31,    -1,    33,
      -1,    71,    36,    -1,    -1,     3,    76,    -1,    78,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    15,    -1,    -1,
      -1,    -1,    20,    -1,    58,    59,    60,    61,    62,    63,
      64,    29,    -1,    31,    32,    33,    -1,    71,    36,    -1,
      -1,    -1,    76,    -1,    78,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,     3,    -1,     5,
      58,    59,    60,    61,    62,    63,    64,    -1,    -1,    15,
      -1,    -1,    -1,    71,    20,    73,    74,    75,    76,    25,
      -1,    -1,    -1,    29,    -1,    31,    -1,    33,    -1,    -1,
      36,    -1,    -1,     3,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    47,    -1,    -1,    -1,    15,    -1,    -1,    -1,    -1,
      20,    -1,    58,    59,    60,    61,    62,    63,    64,    29,
      -1,    31,    -1,    33,    -1,    71,    36,    -1,    -1,    -1,
      76,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,     3,    -1,    -1,    -1,    -1,    58,    59,
      60,    61,    62,    63,    64,    15,    -1,    -1,    -1,    69,
      20,    71,     3,    -1,    -1,    -1,    76,    -1,    -1,    29,
      -1,    31,    -1,    33,    15,    -1,    36,    -1,    -1,    20,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    29,    -1,
      31,    -1,    33,    -1,    -1,    36,    -1,    -1,    58,    59,
      60,    61,    62,    63,    64,    -1,    -1,    -1,    -1,    69,
      -1,    71,    -1,    -1,     3,    -1,    76,    58,    59,    60,
      61,    62,    63,    64,    -1,    -1,    15,    -1,    -1,    70,
      71,    20,    -1,     3,    -1,    76,    -1,    -1,    -1,    -1,
      29,    -1,    31,    -1,    33,    15,    -1,    36,    -1,    -1,
      20,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    29,
      -1,    31,    -1,    33,    -1,    54,    36,    -1,    -1,    58,
      59,    60,    61,    62,    63,    64,    -1,    -1,    -1,    -1,
      -1,    -1,    71,     3,    -1,    -1,    -1,    76,    58,    59,
      60,    61,    62,    63,    64,    15,    -1,    -1,    -1,    -1,
      20,    71,     3,    -1,    74,    -1,    76,    -1,    -1,    29,
      -1,    31,    -1,    33,    15,    -1,    36,    -1,    -1,    20,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    29,    -1,
      31,    -1,    33,    -1,    -1,    36,    -1,    -1,    58,    59,
      60,    61,    62,    63,    64,    -1,    -1,    -1,    -1,    -1,
      -1,    71,     3,    -1,    74,    -1,    76,    58,    59,    60,
      61,    62,    63,    64,    15,    -1,    -1,    -1,    -1,    20,
      71,     3,    -1,    74,    -1,    76,    -1,    -1,    29,    -1,
      31,    -1,    33,    15,    -1,    36,    -1,    -1,    20,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    29,    -1,    31,
      -1,    33,    -1,    -1,    36,    -1,    -1,    58,    59,    60,
      61,    62,    63,    64,    -1,    -1,    -1,    -1,    -1,    -1,
      71,     3,    -1,    74,    -1,    76,    58,    59,    60,    61,
      62,    63,    64,    15,    -1,    -1,    -1,    -1,    20,    71,
      -1,    -1,    -1,    -1,    76,    -1,    -1,    29,    -1,    31,
       1,    33,    -1,    -1,    36,    -1,     7,    -1,     9,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    18,    -1,    -1,
      21,    -1,    -1,    -1,    -1,    -1,    58,    59,    60,    61,
      62,    63,    64,    34,    -1,    -1,    -1,    -1,    -1,    71,
       1,     1,    -1,    -1,    76,    -1,     7,     7,     9,     9,
      -1,    -1,    53,    -1,    55,    -1,    -1,    18,    18,    -1,
      21,    21,    -1,    -1,    65,    -1,    -1,    68,    -1,    70,
      71,    -1,    -1,    34,    34,     1,    -1,    -1,     4,    -1,
       6,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    53,    53,    55,    55,    -1,    -1,    24,    -1,
      -1,    -1,    -1,    -1,    65,    65,    -1,    68,    68,    -1,
      71,    71,    -1,    39,    -1,    41,    42,    43,    44,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    52,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    70
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,     1,     4,     6,     7,     8,     9,    11,    16,    17,
      18,    19,    21,    22,    23,    24,    28,    30,    34,    35,
      37,    38,    39,    40,    41,    42,    43,    44,    45,    46,
      48,    50,    52,    53,    55,    57,    65,    68,    71,    77,
      81,    84,    85,    86,    87,    89,    90,    91,    92,    93,
      98,    99,    13,    67,    89,     1,    78,    87,    89,    78,
      87,    35,    40,    89,    87,    87,    89,    78,    87,    87,
      87,    89,    87,    88,    89,    89,    78,    87,    78,    87,
      78,    87,    87,     1,    86,    87,    86,    87,    89,    90,
     100,     0,    13,     3,     5,    15,    20,    25,    29,    31,
      33,    36,    47,    58,    59,    60,    61,    62,    63,    64,
      71,    76,    68,    72,    79,    80,    85,    89,    85,    56,
      79,    78,    68,    78,    89,    89,    79,    99,    69,    78,
      78,    69,    78,    68,    96,    69,    78,    96,    96,    78,
      78,    99,    70,    69,    70,    68,   100,    82,    87,    87,
      87,    87,    87,    87,    87,    87,    87,    87,    87,    87,
      87,    87,    87,    87,    87,    87,    87,    88,    87,    87,
      72,    78,    79,    96,    87,    87,    88,    96,    96,    87,
      12,    89,    89,     1,    91,    94,    95,    81,    97,    88,
      97,    97,    68,    71,    86,    88,    78,    78,    78,    70,
      32,    73,    74,    75,    78,    87,    87,    97,    78,    78,
      70,    54,    99,    78,    78,    70,    89,    69,    70,    82,
      85,    86,    86,    70,    70,    78,    87,    87,    87,    74,
      78,    87,    95,    82,    78,    74,    74,    74,    78,    51,
      99,    87,    99
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
   Once GCC version 2 has supplanted version 1, this can go.  */

#define YYFAIL		goto yyerrlab

#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)					\
do								\
  if (yychar == YYEMPTY && yylen == 1)				\
    {								\
      yychar = (Token);						\
      yylval = (Value);						\
      yytoken = YYTRANSLATE (yychar);				\
      YYPOPSTACK (1);						\
      goto yybackup;						\
    }								\
  else								\
    {								\
      yyerror (YY_("syntax error: cannot back up")); \
      YYERROR;							\
    }								\
while (YYID (0))


#define YYTERROR	1
#define YYERRCODE	256


/* YYLLOC_DEFAULT -- Set CURRENT to span from RHS[1] to RHS[N].
   If N is 0, then set CURRENT to the empty location which ends
   the previous symbol: RHS[0] (always defined).  */

#define YYRHSLOC(Rhs, K) ((Rhs)[K])
#ifndef YYLLOC_DEFAULT
# define YYLLOC_DEFAULT(Current, Rhs, N)				\
    do									\
      if (YYID (N))                                                    \
	{								\
	  (Current).first_line   = YYRHSLOC (Rhs, 1).first_line;	\
	  (Current).first_column = YYRHSLOC (Rhs, 1).first_column;	\
	  (Current).last_line    = YYRHSLOC (Rhs, N).last_line;		\
	  (Current).last_column  = YYRHSLOC (Rhs, N).last_column;	\
	}								\
      else								\
	{								\
	  (Current).first_line   = (Current).last_line   =		\
	    YYRHSLOC (Rhs, 0).last_line;				\
	  (Current).first_column = (Current).last_column =		\
	    YYRHSLOC (Rhs, 0).last_column;				\
	}								\
    while (YYID (0))
#endif


/* YY_LOCATION_PRINT -- Print the location on the stream.
   This macro was not mandated originally: define only if we know
   we won't break user code: when these are the locations we know.  */

#ifndef YY_LOCATION_PRINT
# if YYLTYPE_IS_TRIVIAL
#  define YY_LOCATION_PRINT(File, Loc)			\
     fprintf (File, "%d.%d-%d.%d",			\
	      (Loc).first_line, (Loc).first_column,	\
	      (Loc).last_line,  (Loc).last_column)
# else
#  define YY_LOCATION_PRINT(File, Loc) ((void) 0)
# endif
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
yy_stack_print (yytype_int16 *bottom, yytype_int16 *top)
#else
static void
yy_stack_print (bottom, top)
    yytype_int16 *bottom;
    yytype_int16 *top;
#endif
{
  YYFPRINTF (stderr, "Stack now");
  for (; bottom <= top; ++bottom)
    YYFPRINTF (stderr, " %d", *bottom);
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
      fprintf (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr, yyrhs[yyprhs[yyrule] + yyi],
		       &(yyvsp[(yyi + 1) - (yynrhs)])
		       		       );
      fprintf (stderr, "\n");
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

/* Copy into YYRESULT an error message about the unexpected token
   YYCHAR while in state YYSTATE.  Return the number of bytes copied,
   including the terminating null byte.  If YYRESULT is null, do not
   copy anything; just return the number of bytes that would be
   copied.  As a special case, return 0 if an ordinary "syntax error"
   message will do.  Return YYSIZE_MAXIMUM if overflow occurs during
   size calculation.  */
static YYSIZE_T
yysyntax_error (char *yyresult, int yystate, int yychar)
{
  int yyn = yypact[yystate];

  if (! (YYPACT_NINF < yyn && yyn <= YYLAST))
    return 0;
  else
    {
      int yytype = YYTRANSLATE (yychar);
      YYSIZE_T yysize0 = yytnamerr (0, yytname[yytype]);
      YYSIZE_T yysize = yysize0;
      YYSIZE_T yysize1;
      int yysize_overflow = 0;
      enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
      char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];
      int yyx;

# if 0
      /* This is so xgettext sees the translatable formats that are
	 constructed on the fly.  */
      YY_("syntax error, unexpected %s");
      YY_("syntax error, unexpected %s, expecting %s");
      YY_("syntax error, unexpected %s, expecting %s or %s");
      YY_("syntax error, unexpected %s, expecting %s or %s or %s");
      YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s");
# endif
      char *yyfmt;
      char const *yyf;
      static char const yyunexpected[] = "syntax error, unexpected %s";
      static char const yyexpecting[] = ", expecting %s";
      static char const yyor[] = " or %s";
      char yyformat[sizeof yyunexpected
		    + sizeof yyexpecting - 1
		    + ((YYERROR_VERBOSE_ARGS_MAXIMUM - 2)
		       * (sizeof yyor - 1))];
      char const *yyprefix = yyexpecting;

      /* Start YYX at -YYN if negative to avoid negative indexes in
	 YYCHECK.  */
      int yyxbegin = yyn < 0 ? -yyn : 0;

      /* Stay within bounds of both yycheck and yytname.  */
      int yychecklim = YYLAST - yyn + 1;
      int yyxend = yychecklim < YYNTOKENS ? yychecklim : YYNTOKENS;
      int yycount = 1;

      yyarg[0] = yytname[yytype];
      yyfmt = yystpcpy (yyformat, yyunexpected);

      for (yyx = yyxbegin; yyx < yyxend; ++yyx)
	if (yycheck[yyx + yyn] == yyx && yyx != YYTERROR)
	  {
	    if (yycount == YYERROR_VERBOSE_ARGS_MAXIMUM)
	      {
		yycount = 1;
		yysize = yysize0;
		yyformat[sizeof yyunexpected - 1] = '\0';
		break;
	      }
	    yyarg[yycount++] = yytname[yyx];
	    yysize1 = yysize + yytnamerr (0, yytname[yyx]);
	    yysize_overflow |= (yysize1 < yysize);
	    yysize = yysize1;
	    yyfmt = yystpcpy (yyfmt, yyprefix);
	    yyprefix = yyor;
	  }

      yyf = YY_(yyformat);
      yysize1 = yysize + yystrlen (yyf);
      yysize_overflow |= (yysize1 < yysize);
      yysize = yysize1;

      if (yysize_overflow)
	return YYSIZE_MAXIMUM;

      if (yyresult)
	{
	  /* Avoid sprintf, as that infringes on the user's name space.
	     Don't have undefined behavior even if the translation
	     produced a string with the wrong number of "%s"s.  */
	  char *yyp = yyresult;
	  int yyi = 0;
	  while ((*yyp = *yyf) != '\0')
	    {
	      if (*yyp == '%' && yyf[1] == 's' && yyi < yycount)
		{
		  yyp += yytnamerr (yyp, yyarg[yyi++]);
		  yyf += 2;
		}
	      else
		{
		  yyp++;
		  yyf++;
		}
	    }
	}
      return yysize;
    }
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


/* Prevent warnings from -Wmissing-prototypes.  */

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



/* The look-ahead symbol.  */
int yychar;

/* The semantic value of the look-ahead symbol.  */
YYSTYPE yylval;

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
  int yyn;
  int yyresult;
  /* Number of tokens to shift before error messages enabled.  */
  int yyerrstatus;
  /* Look-ahead token as an internal (translated) token number.  */
  int yytoken = 0;
#if YYERROR_VERBOSE
  /* Buffer for error messages, and its allocated size.  */
  char yymsgbuf[128];
  char *yymsg = yymsgbuf;
  YYSIZE_T yymsg_alloc = sizeof yymsgbuf;
#endif

  /* Three stacks and their tools:
     `yyss': related to states,
     `yyvs': related to semantic values,
     `yyls': related to locations.

     Refer to the stacks thru separate pointers, to allow yyoverflow
     to reallocate them elsewhere.  */

  /* The state stack.  */
  yytype_int16 yyssa[YYINITDEPTH];
  yytype_int16 *yyss = yyssa;
  yytype_int16 *yyssp;

  /* The semantic value stack.  */
  YYSTYPE yyvsa[YYINITDEPTH];
  YYSTYPE *yyvs = yyvsa;
  YYSTYPE *yyvsp;



#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N))

  YYSIZE_T yystacksize = YYINITDEPTH;

  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;


  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yystate = 0;
  yyerrstatus = 0;
  yynerrs = 0;
  yychar = YYEMPTY;		/* Cause a token to be read.  */

  /* Initialize stack pointers.
     Waste one element of value and location stack
     so that they stay on the same level as the state stack.
     The wasted elements are never initialized.  */

  yyssp = yyss;
  yyvsp = yyvs;

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
	YYSTACK_RELOCATE (yyss);
	YYSTACK_RELOCATE (yyvs);

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

  goto yybackup;

/*-----------.
| yybackup.  |
`-----------*/
yybackup:

  /* Do appropriate processing given the current state.  Read a
     look-ahead token if we need one and don't already have one.  */

  /* First try to decide what to do without reference to look-ahead token.  */
  yyn = yypact[yystate];
  if (yyn == YYPACT_NINF)
    goto yydefault;

  /* Not known => get a look-ahead token if don't already have one.  */

  /* YYCHAR is either YYEMPTY or YYEOF or a valid look-ahead symbol.  */
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
      if (yyn == 0 || yyn == YYTABLE_NINF)
	goto yyerrlab;
      yyn = -yyn;
      goto yyreduce;
    }

  if (yyn == YYFINAL)
    YYACCEPT;

  /* Count tokens shifted since error; after three, turn off error
     status.  */
  if (yyerrstatus)
    yyerrstatus--;

  /* Shift the look-ahead token.  */
  YY_SYMBOL_PRINT ("Shifting", yytoken, &yylval, &yylloc);

  /* Discard the shifted token unless it is eof.  */
  if (yychar != YYEOF)
    yychar = YYEMPTY;

  yystate = yyn;
  *++yyvsp = yylval;

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
#line 115 "qcl.y"
    { *mainSymbol = (yyvsp[(1) - (2)].symbol); return 1;;}
    break;

  case 3:
#line 118 "qcl.y"
    { (yyval.symbol) = (yyvsp[(1) - (1)].symbol); ;}
    break;

  case 4:
#line 119 "qcl.y"
    { (yyval.symbol) = (yyvsp[(1) - (1)].symbol); ;}
    break;

  case 5:
#line 120 "qcl.y"
    { (yyvsp[(1) - (2)].symbol)->addNext((yyvsp[(2) - (2)].symbol)); (yyval.symbol) = (yyvsp[(1) - (2)].symbol); ;}
    break;

  case 6:
#line 121 "qcl.y"
    { (yyvsp[(1) - (2)].symbol)->addNext((yyvsp[(2) - (2)].symbol)); (yyval.symbol) = (yyvsp[(1) - (2)].symbol); ;}
    break;

  case 7:
#line 122 "qcl.y"
    { (yyval.symbol) = new Error(); ;}
    break;

  case 8:
#line 123 "qcl.y"
    { (yyval.symbol) = new Error(); ;}
    break;

  case 9:
#line 131 "qcl.y"
    { (yyval.value) = new Complex((yyvsp[(2) - (5)].value),(yyvsp[(4) - (5)].value)); ;}
    break;

  case 10:
#line 132 "qcl.y"
    { (yyvsp[(2) - (2)].value)->minus(); (yyval.value)=(yyvsp[(2) - (2)].value); ;}
    break;

  case 11:
#line 133 "qcl.y"
    { (yyval.value) = new Real(yylval.REAL); ;}
    break;

  case 12:
#line 134 "qcl.y"
    { (yyval.value) = new Integer(yylval.INT); ;}
    break;

  case 13:
#line 135 "qcl.y"
    { (yyval.value) = new Boolean(true); ;}
    break;

  case 14:
#line 136 "qcl.y"
    { (yyval.value) = new Boolean(false); ;}
    break;

  case 15:
#line 137 "qcl.y"
    { (yyval.value) = new String(*(yylval.STRING)); ;}
    break;

  case 16:
#line 138 "qcl.y"
    { (yyval.value) = new ErrorVal(); ;}
    break;

  case 17:
#line 139 "qcl.y"
    { (yyval.value) = new ErrorVal(); ;}
    break;

  case 18:
#line 144 "qcl.y"
    { (yyval.expression) = new Constant((yyvsp[(1) - (1)].value)); ;}
    break;

  case 19:
#line 145 "qcl.y"
    { (yyval.expression) = new IdQExpression((yyvsp[(1) - (6)].ident),(yyvsp[(3) - (6)].expression),(yyvsp[(5) - (6)].expression),FROMTO); ;}
    break;

  case 20:
#line 146 "qcl.y"
    { (yyval.expression) = new IdQExpression((yyvsp[(1) - (6)].ident),(yyvsp[(3) - (6)].expression),(yyvsp[(5) - (6)].expression),FROMTO); ;}
    break;

  case 21:
#line 147 "qcl.y"
    { (yyval.expression) = new IdQExpression((yyvsp[(1) - (6)].ident),(yyvsp[(3) - (6)].expression),(yyvsp[(5) - (6)].expression),FROMN); ;}
    break;

  case 22:
#line 148 "qcl.y"
    { (yyval.expression) = new IdQExpression((yyvsp[(1) - (4)].ident),(yyvsp[(3) - (4)].expression)); ;}
    break;

  case 23:
#line 149 "qcl.y"
    { (yyval.expression) = new IdExpression((yyvsp[(1) - (1)].ident)); ;}
    break;

  case 24:
#line 150 "qcl.y"
    { (yyval.expression) = new FunctCall( (yyvsp[(1) - (4)].ident), (yyvsp[(3) - (4)].expression) ); ;}
    break;

  case 25:
#line 151 "qcl.y"
    { (yyval.expression) = (yyvsp[(2) - (3)].expression); ;}
    break;

  case 26:
#line 152 "qcl.y"
    { (yyval.expression) = new RegSizeExpression((yyvsp[(2) - (2)].expression)); ;}
    break;

  case 27:
#line 153 "qcl.y"
    { (yyval.expression) = new PowExpression((yyvsp[(1) - (3)].expression),(yyvsp[(3) - (3)].expression)); ;}
    break;

  case 28:
#line 154 "qcl.y"
    { (yyval.expression) = new NegExpression((yyvsp[(2) - (2)].expression)); ;}
    break;

  case 29:
#line 155 "qcl.y"
    { (yyval.expression) = new MultExpression((yyvsp[(1) - (3)].expression),(yyvsp[(3) - (3)].expression)); ;}
    break;

  case 30:
#line 156 "qcl.y"
    { (yyval.expression) = new DivExpression((yyvsp[(1) - (3)].expression),(yyvsp[(3) - (3)].expression)); ;}
    break;

  case 31:
#line 157 "qcl.y"
    { (yyval.expression) = new ModExpression((yyvsp[(1) - (3)].expression),(yyvsp[(3) - (3)].expression)); ;}
    break;

  case 32:
#line 158 "qcl.y"
    { (yyval.expression) = new AddExpression((yyvsp[(1) - (3)].expression),(yyvsp[(3) - (3)].expression)); ;}
    break;

  case 33:
#line 159 "qcl.y"
    { (yyval.expression) = new SubExpression((yyvsp[(1) - (3)].expression),(yyvsp[(3) - (3)].expression)); ;}
    break;

  case 34:
#line 160 "qcl.y"
    { (yyval.expression) = new ConExpression((yyvsp[(1) - (3)].expression),(yyvsp[(3) - (3)].expression)); ;}
    break;

  case 35:
#line 161 "qcl.y"
    { (yyval.expression) = new IsEqExpression((yyvsp[(1) - (3)].expression),(yyvsp[(3) - (3)].expression)); ;}
    break;

  case 36:
#line 162 "qcl.y"
    { (yyval.expression) = new IsNEqExpression((yyvsp[(1) - (3)].expression),(yyvsp[(3) - (3)].expression)); ;}
    break;

  case 37:
#line 163 "qcl.y"
    { (yyval.expression) = new IsLessExpression((yyvsp[(1) - (3)].expression),(yyvsp[(3) - (3)].expression)); ;}
    break;

  case 38:
#line 164 "qcl.y"
    { (yyval.expression) = new IsLessOrEqExpression((yyvsp[(1) - (3)].expression),(yyvsp[(3) - (3)].expression)); ;}
    break;

  case 39:
#line 165 "qcl.y"
    { (yyval.expression) = new IsGrExpression((yyvsp[(1) - (3)].expression),(yyvsp[(3) - (3)].expression)); ;}
    break;

  case 40:
#line 166 "qcl.y"
    { (yyval.expression) = new IsGrOrEqExpression((yyvsp[(1) - (3)].expression),(yyvsp[(3) - (3)].expression)); ;}
    break;

  case 41:
#line 167 "qcl.y"
    { (yyval.expression) = new NotExpression((yyvsp[(2) - (2)].expression)); ;}
    break;

  case 42:
#line 168 "qcl.y"
    { (yyval.expression) = new AndExpression((yyvsp[(1) - (3)].expression),(yyvsp[(3) - (3)].expression)); ;}
    break;

  case 43:
#line 169 "qcl.y"
    { (yyval.expression) = new OrExpression((yyvsp[(1) - (3)].expression),(yyvsp[(3) - (3)].expression)); ;}
    break;

  case 44:
#line 170 "qcl.y"
    { (yyval.expression) = new XorExpression((yyvsp[(1) - (3)].expression),(yyvsp[(3) - (3)].expression)); ;}
    break;

  case 45:
#line 173 "qcl.y"
    { (yyval.expression) = 0; ;}
    break;

  case 46:
#line 174 "qcl.y"
    { (yyval.expression) = (yyvsp[(1) - (1)].expression);;}
    break;

  case 47:
#line 175 "qcl.y"
    { (yyvsp[(1) - (3)].expression)->addNext((yyvsp[(3) - (3)].expression)); (yyval.expression)=(yyvsp[(1) - (3)].expression); ;}
    break;

  case 48:
#line 179 "qcl.y"
    { (yyval.ident) = new Identifier(::qcltext);;}
    break;

  case 49:
#line 189 "qcl.y"
    { (yyval.symbol) = new RoutineCall((yyvsp[(2) - (6)].ident),(yyvsp[(4) - (6)].expression),true) ; ;}
    break;

  case 50:
#line 190 "qcl.y"
    {  (yyval.symbol) = new RoutineCall((yyvsp[(1) - (5)].ident),(yyvsp[(3) - (5)].expression)) ; ;}
    break;

  case 51:
#line 191 "qcl.y"
    { (yyval.symbol) = new VarAssig((yyvsp[(1) - (4)].ident),(yyvsp[(3) - (4)].expression)); ;}
    break;

  case 52:
#line 192 "qcl.y"
    { (yyval.symbol) = new FanoutOperator((yyvsp[(3) - (4)].expression),(yyvsp[(1) - (4)].expression)) ; ;}
    break;

  case 53:
#line 193 "qcl.y"
    { (yyval.symbol) = new FanoutOperator((yyvsp[(1) - (4)].expression),(yyvsp[(3) - (4)].expression)) ; ;}
    break;

  case 54:
#line 194 "qcl.y"
    { (yyval.symbol) = new SwapOperator((yyvsp[(1) - (4)].expression),(yyvsp[(3) - (4)].expression)) ; ;}
    break;

  case 55:
#line 196 "qcl.y"
    { (yyval.symbol) = new ForStmt((yyvsp[(2) - (9)].ident),(yyvsp[(4) - (9)].expression),(yyvsp[(6) - (9)].expression),(yyvsp[(9) - (9)].symbol),(yyvsp[(8) - (9)].expression)) ; ;}
    break;

  case 56:
#line 197 "qcl.y"
    { (yyval.symbol) = new ForStmt((yyvsp[(2) - (7)].ident),(yyvsp[(4) - (7)].expression),(yyvsp[(6) - (7)].expression),(yyvsp[(7) - (7)].symbol)); ;}
    break;

  case 57:
#line 198 "qcl.y"
    { (yyval.symbol) = new WhileStmt((yyvsp[(2) - (3)].expression),(yyvsp[(3) - (3)].symbol)) ; ;}
    break;

  case 58:
#line 199 "qcl.y"
    { (yyval.symbol) = new UntilStmt((yyvsp[(3) - (4)].expression),(yyvsp[(1) - (4)].symbol)) ; ;}
    break;

  case 59:
#line 200 "qcl.y"
    { (yyval.symbol) = new IfStmt((yyvsp[(2) - (5)].expression),(yyvsp[(3) - (5)].symbol),(yyvsp[(5) - (5)].symbol)) ; ;}
    break;

  case 60:
#line 201 "qcl.y"
    { (yyval.symbol) = new IfStmt((yyvsp[(2) - (3)].expression),(yyvsp[(3) - (3)].symbol)); ;}
    break;

  case 61:
#line 202 "qcl.y"
    { (yyval.symbol) = new ReturnStmt((yyvsp[(2) - (3)].expression)) ; ;}
    break;

  case 62:
#line 203 "qcl.y"
    { (yyval.symbol) = new Input((yyvsp[(2) - (3)].ident)) ; ;}
    break;

  case 63:
#line 204 "qcl.y"
    { (yyval.symbol) = new Input((yyvsp[(4) - (5)].ident),(yyvsp[(2) - (5)].expression)); ;}
    break;

  case 64:
#line 205 "qcl.y"
    { (yyval.symbol) = new PrintStmt((yyvsp[(2) - (3)].expression)); ;}
    break;

  case 65:
#line 206 "qcl.y"
    { (yyval.symbol) = new Exit((yyvsp[(2) - (3)].expression)) ; ;}
    break;

  case 66:
#line 207 "qcl.y"
    { (yyval.symbol) = new Exit() ; ;}
    break;

  case 67:
#line 208 "qcl.y"
    { (yyval.symbol) = new Measure((yyvsp[(2) - (3)].expression)) ; ;}
    break;

  case 68:
#line 209 "qcl.y"
    { (yyval.symbol) = new Measure((yyvsp[(2) - (5)].expression),(yyvsp[(4) - (5)].ident)) ; ;}
    break;

  case 69:
#line 210 "qcl.y"
    { (yyval.symbol) = new Reset() ; ;}
    break;

  case 70:
#line 211 "qcl.y"
    { (yyval.symbol) = new Dump() ; ;}
    break;

  case 71:
#line 212 "qcl.y"
    { (yyval.symbol) = new Dump((yyvsp[(2) - (3)].expression)) ; ;}
    break;

  case 72:
#line 213 "qcl.y"
    { (yyval.symbol) = new Load() ; ;}
    break;

  case 73:
#line 214 "qcl.y"
    { (yyval.symbol) = new Load((yyvsp[(2) - (3)].expression)) ; ;}
    break;

  case 74:
#line 215 "qcl.y"
    { (yyval.symbol) = new Save() ; ;}
    break;

  case 75:
#line 216 "qcl.y"
    { (yyval.symbol) = new Save((yyvsp[(2) - (3)].expression)) ; ;}
    break;

  case 76:
#line 217 "qcl.y"
    { (yyval.symbol) = new Shell() ; ;}
    break;

  case 77:
#line 220 "qcl.y"
    { (yyval.symbol) = (yyvsp[(1) - (2)].symbol); ;}
    break;

  case 78:
#line 229 "qcl.y"
    { (yyval.stype) = BOOLEAN ; ;}
    break;

  case 79:
#line 230 "qcl.y"
    { (yyval.stype) = INTEGER; ;}
    break;

  case 80:
#line 231 "qcl.y"
    { (yyval.stype) = REAL; ;}
    break;

  case 81:
#line 232 "qcl.y"
    { (yyval.stype) = COMPLEX; ;}
    break;

  case 82:
#line 233 "qcl.y"
    { (yyval.stype) = STRING; ;}
    break;

  case 83:
#line 234 "qcl.y"
    { (yyval.stype) = QUREG; ;}
    break;

  case 84:
#line 235 "qcl.y"
    { (yyval.stype) = QUVOID; ;}
    break;

  case 85:
#line 236 "qcl.y"
    { (yyval.stype) = QUCONST; ;}
    break;

  case 86:
#line 237 "qcl.y"
    { (yyval.stype) = QUSCRATCH; ;}
    break;

  case 87:
#line 240 "qcl.y"
    { (yyval.definition) = new Def((yyvsp[(2) - (5)].ident),CONST,(yyvsp[(4) - (5)].expression));;}
    break;

  case 88:
#line 242 "qcl.y"
    { (yyval.definition) = new Defq((yyvsp[(2) - (6)].ident),(yyvsp[(1) - (6)].stype),(yyvsp[(4) - (6)].expression)); ;}
    break;

  case 89:
#line 243 "qcl.y"
    { (yyval.definition) = new Def((yyvsp[(2) - (5)].ident),(yyvsp[(1) - (5)].stype),(yyvsp[(4) - (5)].expression)); ;}
    break;

  case 90:
#line 244 "qcl.y"
    { (yyval.definition) = new Def((yyvsp[(2) - (3)].ident),(yyvsp[(1) - (3)].stype)); ;}
    break;

  case 91:
#line 247 "qcl.y"
    { (yyval.definition) = new Def((yyvsp[(2) - (2)].ident),(yyvsp[(1) - (2)].stype)); ;}
    break;

  case 92:
#line 250 "qcl.y"
    { (yyvsp[(1) - (3)].definition)->addNext((yyvsp[(3) - (3)].definition)); (yyval.definition)=(yyvsp[(1) - (3)].definition);;}
    break;

  case 93:
#line 251 "qcl.y"
    { (yyval.definition) = (yyvsp[(1) - (1)].definition);;}
    break;

  case 94:
#line 252 "qcl.y"
    { (yyval.definition) = 0;;}
    break;

  case 95:
#line 255 "qcl.y"
    { (yyval.definition) = (yyvsp[(2) - (3)].definition); ;}
    break;

  case 96:
#line 256 "qcl.y"
    { (yyval.definition) = 0;;}
    break;

  case 97:
#line 259 "qcl.y"
    { (yyval.symbol)=(yyvsp[(2) - (3)].symbol); ;}
    break;

  case 98:
#line 260 "qcl.y"
    { (yyval.symbol)=0;;}
    break;

  case 99:
#line 264 "qcl.y"
    { (yyval.symbol) = (yyvsp[(1) - (1)].definition); ;}
    break;

  case 100:
#line 265 "qcl.y"
    { (yyval.symbol) = (yyvsp[(1) - (1)].definition); ;}
    break;

  case 101:
#line 266 "qcl.y"
    { (yyval.symbol) = new FunctDef((yyvsp[(2) - (4)].ident),(yyvsp[(1) - (4)].stype),(yyvsp[(3) - (4)].definition),(yyvsp[(4) - (4)].symbol)); ;}
    break;

  case 102:
#line 267 "qcl.y"
    { (yyval.symbol) = new ProcDef((yyvsp[(2) - (4)].ident),(yyvsp[(3) - (4)].definition),(yyvsp[(4) - (4)].symbol));;}
    break;

  case 103:
#line 268 "qcl.y"
    { (yyval.symbol) = new OperDef((yyvsp[(2) - (4)].ident),(yyvsp[(3) - (4)].definition),(yyvsp[(4) - (4)].symbol));;}
    break;

  case 104:
#line 269 "qcl.y"
    { (yyval.symbol) = new QufuncDef((yyvsp[(2) - (4)].ident),(yyvsp[(3) - (4)].definition),(yyvsp[(4) - (4)].symbol)); ;}
    break;

  case 105:
#line 270 "qcl.y"
    { (yyval.symbol) = new ExOperDef((yyvsp[(3) - (4)].ident),(yyvsp[(4) - (4)].definition)); ;}
    break;

  case 106:
#line 271 "qcl.y"
    { (yyval.symbol) = new ExQufuncDef((yyvsp[(3) - (4)].ident),(yyvsp[(4) - (4)].definition)); ;}
    break;

  case 107:
#line 274 "qcl.y"
    { (yyval.symbol) = (yyvsp[(2) - (3)].symbol); ;}
    break;

  case 108:
#line 277 "qcl.y"
    { (yyval.symbol) = (yyvsp[(1) - (1)].symbol); ;}
    break;

  case 109:
#line 278 "qcl.y"
    { (yyvsp[(1) - (2)].symbol)->addNext((yyvsp[(2) - (2)].symbol)); (yyval.symbol)=(yyvsp[(1) - (2)].symbol); ;}
    break;


/* Line 1267 of yacc.c.  */
#line 2543 "qcl.tab.c"
      default: break;
    }
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
  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
#if ! YYERROR_VERBOSE
      yyerror (YY_("syntax error"));
#else
      {
	YYSIZE_T yysize = yysyntax_error (0, yystate, yychar);
	if (yymsg_alloc < yysize && yymsg_alloc < YYSTACK_ALLOC_MAXIMUM)
	  {
	    YYSIZE_T yyalloc = 2 * yysize;
	    if (! (yysize <= yyalloc && yyalloc <= YYSTACK_ALLOC_MAXIMUM))
	      yyalloc = YYSTACK_ALLOC_MAXIMUM;
	    if (yymsg != yymsgbuf)
	      YYSTACK_FREE (yymsg);
	    yymsg = (char *) YYSTACK_ALLOC (yyalloc);
	    if (yymsg)
	      yymsg_alloc = yyalloc;
	    else
	      {
		yymsg = yymsgbuf;
		yymsg_alloc = sizeof yymsgbuf;
	      }
	  }

	if (0 < yysize && yysize <= yymsg_alloc)
	  {
	    (void) yysyntax_error (yymsg, yystate, yychar);
	    yyerror (yymsg);
	  }
	else
	  {
	    yyerror (YY_("syntax error"));
	    if (yysize != 0)
	      goto yyexhaustedlab;
	  }
      }
#endif
    }



  if (yyerrstatus == 3)
    {
      /* If just tried and failed to reuse look-ahead token after an
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

  /* Else will try to reuse look-ahead token after shifting the error
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
      if (yyn != YYPACT_NINF)
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

  if (yyn == YYFINAL)
    YYACCEPT;

  *++yyvsp = yylval;


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

#ifndef yyoverflow
/*-------------------------------------------------.
| yyexhaustedlab -- memory exhaustion comes here.  |
`-------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  /* Fall through.  */
#endif

yyreturn:
  if (yychar != YYEOF && yychar != YYEMPTY)
     yydestruct ("Cleanup: discarding lookahead",
		 yytoken, &yylval);
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


#line 293 "qcl.y"







