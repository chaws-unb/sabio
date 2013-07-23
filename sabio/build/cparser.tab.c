
/* A Bison parser, made by GNU Bison 2.4.1.  */

/* Skeleton implementation for Bison's Yacc-like parsers in C
   
      Copyright (C) 1984, 1989, 1990, 2000, 2001, 2002, 2003, 2004, 2005, 2006
   Free Software Foundation, Inc.
   
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
#define YYBISON_VERSION "2.4.1"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1

/* Using locations.  */
#define YYLSP_NEEDED 0



/* Copy the first part of user declarations.  */

/* Line 189 of yacc.c  */
#line 5 "par/cparser.y"

#include <stdio.h>
#include <stdlib.h>

#include <dataType.h>
#include <abstractTree.h>
#include <clexer.h>


/* Line 189 of yacc.c  */
#line 83 "cparser.tab.c"

/* Enabling traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
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


/* Tokens.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
   /* Put the tokens into the symbol table, so that GDB and other debuggers
      know about them.  */
   enum yytokentype {
     IDENTIFIER = 258,
     CONSTANT = 259,
     STRING_LITERAL = 260,
     SIZEOF = 261,
     PTR_OP = 262,
     INC_OP = 263,
     DEC_OP = 264,
     LEFT_OP = 265,
     RIGHT_OP = 266,
     LE_OP = 267,
     GE_OP = 268,
     EQ_OP = 269,
     NE_OP = 270,
     AND_OP = 271,
     OR_OP = 272,
     MUL_ASSIGN = 273,
     DIV_ASSIGN = 274,
     MOD_ASSIGN = 275,
     ADD_ASSIGN = 276,
     SUB_ASSIGN = 277,
     LEFT_ASSIGN = 278,
     RIGHT_ASSIGN = 279,
     AND_ASSIGN = 280,
     XOR_ASSIGN = 281,
     OR_ASSIGN = 282,
     TYPE_NAME = 283,
     TYPEDEF = 284,
     EXTERN = 285,
     STATIC = 286,
     AUTO = 287,
     REGISTER = 288,
     CHAR = 289,
     SHORT = 290,
     INT = 291,
     LONG = 292,
     SIGNED = 293,
     UNSIGNED = 294,
     FLOAT = 295,
     DOUBLE = 296,
     CONST = 297,
     VOLATILE = 298,
     VOID = 299,
     STRUCT = 300,
     UNION = 301,
     ENUM = 302,
     ELLIPSIS = 303,
     CASE = 304,
     DEFAULT = 305,
     IF = 306,
     ELSE = 307,
     SWITCH = 308,
     WHILE = 309,
     DO = 310,
     FOR = 311,
     GOTO = 312,
     CONTINUE = 313,
     BREAK = 314,
     RETURN = 315
   };
#endif



#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef int YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
#endif


/* Copy the second part of user declarations.  */


/* Line 264 of yacc.c  */
#line 185 "cparser.tab.c"

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

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  61
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   1301

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  85
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  64
/* YYNRULES -- Number of rules.  */
#define YYNRULES  212
/* YYNRULES -- Number of states.  */
#define YYNSTATES  350

/* YYTRANSLATE(YYLEX) -- Bison symbol number corresponding to YYLEX.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   315

#define YYTRANSLATE(YYX)						\
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[YYLEX] -- Bison symbol number corresponding to YYLEX.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    72,     2,     2,     2,    74,    67,     2,
      61,    62,    68,    69,    66,    70,    65,    73,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,    80,    82,
      75,    81,    76,    79,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,    63,     2,    64,    77,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    83,    78,    84,    71,     2,     2,     2,
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
      55,    56,    57,    58,    59,    60
};

#if YYDEBUG
/* YYPRHS[YYN] -- Index of the first RHS symbol of rule number YYN in
   YYRHS.  */
static const yytype_uint16 yyprhs[] =
{
       0,     0,     3,     5,     7,     9,    13,    15,    20,    24,
      29,    33,    37,    40,    43,    45,    49,    51,    54,    57,
      60,    63,    68,    70,    72,    74,    76,    78,    80,    82,
      87,    89,    93,    97,   101,   103,   107,   111,   113,   117,
     121,   123,   127,   131,   135,   139,   141,   145,   149,   151,
     155,   157,   161,   163,   167,   169,   173,   175,   179,   181,
     187,   189,   193,   195,   197,   199,   201,   203,   205,   207,
     209,   211,   213,   215,   217,   221,   223,   226,   230,   232,
     235,   237,   240,   242,   245,   247,   251,   253,   257,   259,
     261,   263,   265,   267,   269,   271,   273,   275,   277,   279,
     281,   283,   285,   287,   289,   291,   297,   302,   305,   307,
     309,   311,   314,   318,   321,   323,   326,   328,   330,   334,
     336,   339,   343,   348,   354,   357,   359,   363,   365,   369,
     371,   373,   376,   378,   380,   384,   389,   393,   398,   403,
     407,   409,   412,   415,   419,   421,   424,   426,   430,   432,
     436,   439,   442,   444,   446,   450,   452,   455,   457,   459,
     462,   466,   469,   473,   477,   482,   485,   489,   493,   498,
     500,   504,   509,   511,   515,   517,   519,   521,   523,   525,
     527,   531,   536,   540,   543,   547,   551,   556,   558,   561,
     563,   566,   568,   571,   577,   585,   591,   597,   605,   612,
     620,   624,   627,   630,   633,   637,   639,   642,   644,   646,
     651,   655,   659
};

/* YYRHS -- A `-1'-separated list of the rules' RHS.  */
static const yytype_int16 yyrhs[] =
{
     146,     0,    -1,     3,    -1,     4,    -1,     5,    -1,    61,
     105,    62,    -1,    86,    -1,    87,    63,   105,    64,    -1,
      87,    61,    62,    -1,    87,    61,    88,    62,    -1,    87,
      65,     3,    -1,    87,     7,     3,    -1,    87,     8,    -1,
      87,     9,    -1,   103,    -1,    88,    66,   103,    -1,    87,
      -1,     8,    89,    -1,     9,    89,    -1,    90,    91,    -1,
       6,    89,    -1,     6,    61,   132,    62,    -1,    67,    -1,
      68,    -1,    69,    -1,    70,    -1,    71,    -1,    72,    -1,
      89,    -1,    61,   132,    62,    91,    -1,    91,    -1,    92,
      68,    91,    -1,    92,    73,    91,    -1,    92,    74,    91,
      -1,    92,    -1,    93,    69,    92,    -1,    93,    70,    92,
      -1,    93,    -1,    94,    10,    93,    -1,    94,    11,    93,
      -1,    94,    -1,    95,    75,    94,    -1,    95,    76,    94,
      -1,    95,    12,    94,    -1,    95,    13,    94,    -1,    95,
      -1,    96,    14,    95,    -1,    96,    15,    95,    -1,    96,
      -1,    97,    67,    96,    -1,    97,    -1,    98,    77,    97,
      -1,    98,    -1,    99,    78,    98,    -1,    99,    -1,   100,
      16,    99,    -1,   100,    -1,   101,    17,   100,    -1,   101,
      -1,   101,    79,   105,    80,   102,    -1,   102,    -1,    89,
     104,   103,    -1,    81,    -1,    18,    -1,    19,    -1,    20,
      -1,    21,    -1,    22,    -1,    23,    -1,    24,    -1,    25,
      -1,    26,    -1,    27,    -1,   103,    -1,   105,    66,   103,
      -1,   102,    -1,   108,    82,    -1,   108,   109,    82,    -1,
     111,    -1,   111,   108,    -1,   112,    -1,   112,   108,    -1,
     123,    -1,   123,   108,    -1,   110,    -1,   109,    66,   110,
      -1,   124,    -1,   124,    81,   135,    -1,    29,    -1,    30,
      -1,    31,    -1,    32,    -1,    33,    -1,    44,    -1,    34,
      -1,    35,    -1,    36,    -1,    37,    -1,    40,    -1,    41,
      -1,    38,    -1,    39,    -1,   113,    -1,   120,    -1,    28,
      -1,   114,     3,    83,   115,    84,    -1,   114,    83,   115,
      84,    -1,   114,     3,    -1,    45,    -1,    46,    -1,   116,
      -1,   115,   116,    -1,   117,   118,    82,    -1,   112,   117,
      -1,   112,    -1,   123,   117,    -1,   123,    -1,   119,    -1,
     118,    66,   119,    -1,   124,    -1,    80,   106,    -1,   124,
      80,   106,    -1,    47,    83,   121,    84,    -1,    47,     3,
      83,   121,    84,    -1,    47,     3,    -1,   122,    -1,   121,
      66,   122,    -1,     3,    -1,     3,    81,   106,    -1,    42,
      -1,    43,    -1,   126,   125,    -1,   125,    -1,     3,    -1,
      61,   124,    62,    -1,   125,    63,   106,    64,    -1,   125,
      63,    64,    -1,   125,    61,   128,    62,    -1,   125,    61,
     131,    62,    -1,   125,    61,    62,    -1,    68,    -1,    68,
     127,    -1,    68,   126,    -1,    68,   127,   126,    -1,   123,
      -1,   127,   123,    -1,   129,    -1,   129,    66,    48,    -1,
     130,    -1,   129,    66,   130,    -1,   108,   124,    -1,   108,
     133,    -1,   108,    -1,     3,    -1,   131,    66,     3,    -1,
     117,    -1,   117,   133,    -1,   126,    -1,   134,    -1,   126,
     134,    -1,    61,   133,    62,    -1,    63,    64,    -1,    63,
     106,    64,    -1,   134,    63,    64,    -1,   134,    63,   106,
      64,    -1,    61,    62,    -1,    61,   128,    62,    -1,   134,
      61,    62,    -1,   134,    61,   128,    62,    -1,   103,    -1,
      83,   136,    84,    -1,    83,   136,    66,    84,    -1,   135,
      -1,   136,    66,   135,    -1,   138,    -1,   139,    -1,   142,
      -1,   143,    -1,   144,    -1,   145,    -1,     3,    80,   137,
      -1,    49,   106,    80,   137,    -1,    50,    80,   137,    -1,
      83,    84,    -1,    83,   141,    84,    -1,    83,   140,    84,
      -1,    83,   140,   141,    84,    -1,   107,    -1,   140,   107,
      -1,   137,    -1,   141,   137,    -1,    82,    -1,   105,    82,
      -1,    51,    61,   105,    62,   137,    -1,    51,    61,   105,
      62,   137,    52,   137,    -1,    53,    61,   105,    62,   137,
      -1,    54,    61,   105,    62,   137,    -1,    55,   137,    54,
      61,   105,    62,    82,    -1,    56,    61,   142,   142,    62,
     137,    -1,    56,    61,   142,   142,   105,    62,   137,    -1,
      57,     3,    82,    -1,    58,    82,    -1,    59,    82,    -1,
      60,    82,    -1,    60,   105,    82,    -1,   147,    -1,   146,
     147,    -1,   148,    -1,   107,    -1,   108,   124,   140,   139,
      -1,   108,   124,   139,    -1,   124,   140,   139,    -1,   124,
     139,    -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,    30,    30,    31,    32,    33,    37,    38,    39,    40,
      41,    42,    43,    44,    48,    49,    53,    54,    55,    56,
      57,    58,    62,    63,    64,    65,    66,    67,    71,    72,
      76,    77,    78,    79,    83,    84,    85,    89,    90,    91,
      95,    96,    97,    98,    99,   103,   104,   105,   109,   110,
     114,   115,   119,   120,   124,   125,   129,   130,   134,   135,
     139,   140,   144,   145,   146,   147,   148,   149,   150,   151,
     152,   153,   154,   158,   159,   163,   167,   168,   172,   173,
     174,   175,   176,   177,   181,   182,   186,   187,   191,   192,
     193,   194,   195,   199,   200,   201,   202,   203,   204,   205,
     206,   207,   208,   209,   210,   214,   215,   216,   220,   221,
     225,   226,   230,   234,   235,   236,   237,   241,   242,   246,
     247,   248,   252,   253,   254,   258,   259,   263,   264,   268,
     269,   273,   274,   278,   279,   280,   281,   282,   283,   284,
     288,   289,   290,   291,   295,   296,   301,   302,   306,   307,
     311,   312,   313,   317,   318,   322,   323,   327,   328,   329,
     333,   334,   335,   336,   337,   338,   339,   340,   341,   345,
     346,   347,   351,   352,   356,   357,   358,   359,   360,   361,
     365,   366,   367,   371,   372,   373,   374,   378,   379,   383,
     384,   388,   389,   393,   394,   395,   399,   400,   401,   402,
     406,   407,   408,   409,   410,   414,   415,   419,   420,   424,
     425,   426,   427
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || YYTOKEN_TABLE
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "IDENTIFIER", "CONSTANT",
  "STRING_LITERAL", "SIZEOF", "PTR_OP", "INC_OP", "DEC_OP", "LEFT_OP",
  "RIGHT_OP", "LE_OP", "GE_OP", "EQ_OP", "NE_OP", "AND_OP", "OR_OP",
  "MUL_ASSIGN", "DIV_ASSIGN", "MOD_ASSIGN", "ADD_ASSIGN", "SUB_ASSIGN",
  "LEFT_ASSIGN", "RIGHT_ASSIGN", "AND_ASSIGN", "XOR_ASSIGN", "OR_ASSIGN",
  "TYPE_NAME", "TYPEDEF", "EXTERN", "STATIC", "AUTO", "REGISTER", "CHAR",
  "SHORT", "INT", "LONG", "SIGNED", "UNSIGNED", "FLOAT", "DOUBLE", "CONST",
  "VOLATILE", "VOID", "STRUCT", "UNION", "ENUM", "ELLIPSIS", "CASE",
  "DEFAULT", "IF", "ELSE", "SWITCH", "WHILE", "DO", "FOR", "GOTO",
  "CONTINUE", "BREAK", "RETURN", "'('", "')'", "'['", "']'", "'.'", "','",
  "'&'", "'*'", "'+'", "'-'", "'~'", "'!'", "'/'", "'%'", "'<'", "'>'",
  "'^'", "'|'", "'?'", "':'", "'='", "';'", "'{'", "'}'", "$accept",
  "primary_expression", "postfix_expression", "argument_expression_list",
  "unary_expression", "unary_operator", "cast_expression",
  "multiplicative_expression", "additive_expression", "shift_expression",
  "relational_expression", "equality_expression", "and_expression",
  "exclusive_or_expression", "inclusive_or_expression",
  "logical_and_expression", "logical_or_expression",
  "conditional_expression", "assignment_expression", "assignment_operator",
  "expression", "constant_expression", "declaration",
  "declaration_specifiers", "init_declarator_list", "init_declarator",
  "storage_class_specifier", "type_specifier", "struct_or_union_specifier",
  "struct_or_union", "struct_declaration_list", "struct_declaration",
  "specifier_qualifier_list", "struct_declarator_list",
  "struct_declarator", "enum_specifier", "enumerator_list", "enumerator",
  "type_qualifier", "declarator", "direct_declarator", "pointer",
  "type_qualifier_list", "parameter_type_list", "parameter_list",
  "parameter_declaration", "identifier_list", "type_name",
  "abstract_declarator", "direct_abstract_declarator", "initializer",
  "initializer_list", "statement", "labeled_statement",
  "compound_statement", "declaration_list", "statement_list",
  "expression_statement", "selection_statement", "iteration_statement",
  "jump_statement", "translation_unit", "external_declaration",
  "function_definition", 0
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
     305,   306,   307,   308,   309,   310,   311,   312,   313,   314,
     315,    40,    41,    91,    93,    46,    44,    38,    42,    43,
      45,   126,    33,    47,    37,    60,    62,    94,   124,    63,
      58,    61,    59,   123,   125
};
# endif

/* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    85,    86,    86,    86,    86,    87,    87,    87,    87,
      87,    87,    87,    87,    88,    88,    89,    89,    89,    89,
      89,    89,    90,    90,    90,    90,    90,    90,    91,    91,
      92,    92,    92,    92,    93,    93,    93,    94,    94,    94,
      95,    95,    95,    95,    95,    96,    96,    96,    97,    97,
      98,    98,    99,    99,   100,   100,   101,   101,   102,   102,
     103,   103,   104,   104,   104,   104,   104,   104,   104,   104,
     104,   104,   104,   105,   105,   106,   107,   107,   108,   108,
     108,   108,   108,   108,   109,   109,   110,   110,   111,   111,
     111,   111,   111,   112,   112,   112,   112,   112,   112,   112,
     112,   112,   112,   112,   112,   113,   113,   113,   114,   114,
     115,   115,   116,   117,   117,   117,   117,   118,   118,   119,
     119,   119,   120,   120,   120,   121,   121,   122,   122,   123,
     123,   124,   124,   125,   125,   125,   125,   125,   125,   125,
     126,   126,   126,   126,   127,   127,   128,   128,   129,   129,
     130,   130,   130,   131,   131,   132,   132,   133,   133,   133,
     134,   134,   134,   134,   134,   134,   134,   134,   134,   135,
     135,   135,   136,   136,   137,   137,   137,   137,   137,   137,
     138,   138,   138,   139,   139,   139,   139,   140,   140,   141,
     141,   142,   142,   143,   143,   143,   144,   144,   144,   144,
     145,   145,   145,   145,   145,   146,   146,   147,   147,   148,
     148,   148,   148
};

/* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     1,     1,     1,     3,     1,     4,     3,     4,
       3,     3,     2,     2,     1,     3,     1,     2,     2,     2,
       2,     4,     1,     1,     1,     1,     1,     1,     1,     4,
       1,     3,     3,     3,     1,     3,     3,     1,     3,     3,
       1,     3,     3,     3,     3,     1,     3,     3,     1,     3,
       1,     3,     1,     3,     1,     3,     1,     3,     1,     5,
       1,     3,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     3,     1,     2,     3,     1,     2,
       1,     2,     1,     2,     1,     3,     1,     3,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     5,     4,     2,     1,     1,
       1,     2,     3,     2,     1,     2,     1,     1,     3,     1,
       2,     3,     4,     5,     2,     1,     3,     1,     3,     1,
       1,     2,     1,     1,     3,     4,     3,     4,     4,     3,
       1,     2,     2,     3,     1,     2,     1,     3,     1,     3,
       2,     2,     1,     1,     3,     1,     2,     1,     1,     2,
       3,     2,     3,     3,     4,     2,     3,     3,     4,     1,
       3,     4,     1,     3,     1,     1,     1,     1,     1,     1,
       3,     4,     3,     2,     3,     3,     4,     1,     2,     1,
       2,     1,     2,     5,     7,     5,     5,     7,     6,     7,
       3,     2,     2,     2,     3,     1,     2,     1,     1,     4,
       3,     3,     2
};

/* YYDEFACT[STATE-NAME] -- Default rule to reduce with in state
   STATE-NUM when YYTABLE doesn't specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,   133,   104,    88,    89,    90,    91,    92,    94,    95,
      96,    97,   100,   101,    98,    99,   129,   130,    93,   108,
     109,     0,     0,   140,   208,     0,    78,    80,   102,     0,
     103,    82,     0,   132,     0,     0,   205,   207,   124,     0,
       0,   144,   142,   141,    76,     0,    84,    86,    79,    81,
     107,     0,    83,     0,   187,     0,   212,     0,     0,     0,
     131,     1,   206,     0,   127,     0,   125,   134,   145,   143,
       0,    77,     0,   210,     0,     0,   114,     0,   110,     0,
     116,     2,     3,     4,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    22,
      23,    24,    25,    26,    27,   191,   183,     6,    16,    28,
       0,    30,    34,    37,    40,    45,    48,    50,    52,    54,
      56,    58,    60,    73,     0,   189,   174,   175,     0,     0,
     176,   177,   178,   179,    86,   188,   211,   153,   139,   152,
       0,   146,   148,     0,     2,   136,    28,    75,     0,     0,
       0,     0,   122,    85,     0,   169,    87,   209,     0,   113,
     106,   111,     0,     0,   117,   119,   115,     0,     0,    20,
       0,    17,    18,     0,     0,     0,     0,     0,     0,     0,
       0,   201,   202,   203,     0,     0,   155,     0,     0,    12,
      13,     0,     0,     0,    63,    64,    65,    66,    67,    68,
      69,    70,    71,    72,    62,     0,    19,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   192,   185,     0,
     184,   190,     0,     0,   150,   157,   151,   158,   137,     0,
     138,     0,   135,   123,   128,   126,   172,     0,   105,   120,
       0,   112,     0,   180,     0,     0,   182,     0,     0,     0,
       0,     0,   200,   204,     5,     0,   157,   156,     0,    11,
       8,     0,    14,     0,    10,    61,    31,    32,    33,    35,
      36,    38,    39,    43,    44,    41,    42,    46,    47,    49,
      51,    53,    55,    57,     0,    74,   186,   165,     0,     0,
     161,     0,   159,     0,     0,   147,   149,   154,     0,   170,
     118,   121,    21,   181,     0,     0,     0,     0,     0,    29,
       9,     0,     7,     0,   166,   160,   162,   167,     0,   163,
       0,   171,   173,   193,   195,   196,     0,     0,     0,    15,
      59,   168,   164,     0,     0,   198,     0,   194,   197,   199
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,   107,   108,   271,   109,   110,   111,   112,   113,   114,
     115,   116,   117,   118,   119,   120,   121,   122,   123,   205,
     124,   148,    54,    55,    45,    46,    26,    27,    28,    29,
      77,    78,    79,   163,   164,    30,    65,    66,    31,    32,
      33,    34,    43,   298,   141,   142,   143,   187,   299,   237,
     156,   247,   125,   126,   127,    57,   129,   130,   131,   132,
     133,    35,    36,    37
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -223
static const yytype_int16 yypact[] =
{
     969,  -223,  -223,  -223,  -223,  -223,  -223,  -223,  -223,  -223,
    -223,  -223,  -223,  -223,  -223,  -223,  -223,  -223,  -223,  -223,
    -223,     5,    42,     4,  -223,    31,  1254,  1254,  -223,    11,
    -223,  1254,  1101,    88,    26,   879,  -223,  -223,   -60,    51,
      14,  -223,  -223,     4,  -223,    38,  -223,  1081,  -223,  -223,
     -10,  1055,  -223,   278,  -223,    31,  -223,  1101,   408,   666,
      88,  -223,  -223,    51,    69,   -23,  -223,  -223,  -223,  -223,
      42,  -223,   542,  -223,  1101,  1055,  1055,  1004,  -223,    72,
    1055,   -12,  -223,  -223,   785,   806,   806,   830,    17,   123,
     129,   132,   524,   141,   109,   127,   134,   559,   645,  -223,
    -223,  -223,  -223,  -223,  -223,  -223,  -223,  -223,   192,   274,
     830,  -223,   121,    36,   224,   116,   229,   151,   150,   158,
     236,    -2,  -223,  -223,    43,  -223,  -223,  -223,   348,   418,
    -223,  -223,  -223,  -223,   164,  -223,  -223,  -223,  -223,    18,
     198,   188,  -223,    16,  -223,  -223,  -223,  -223,   197,   -15,
     830,    51,  -223,  -223,   542,  -223,  -223,  -223,  1024,  -223,
    -223,  -223,   830,    76,  -223,   184,  -223,   524,   645,  -223,
     830,  -223,  -223,   190,   524,   830,   830,   830,   217,   596,
     191,  -223,  -223,  -223,   114,    49,    85,   212,   273,  -223,
    -223,   690,   830,   275,  -223,  -223,  -223,  -223,  -223,  -223,
    -223,  -223,  -223,  -223,  -223,   830,  -223,   830,   830,   830,
     830,   830,   830,   830,   830,   830,   830,   830,   830,   830,
     830,   830,   830,   830,   830,   830,   830,  -223,  -223,   454,
    -223,  -223,   924,   715,  -223,    22,  -223,   165,  -223,  1233,
    -223,   282,  -223,  -223,  -223,  -223,  -223,    35,  -223,  -223,
      72,  -223,   830,  -223,   215,   524,  -223,    81,   120,   145,
     227,   596,  -223,  -223,  -223,  1157,   170,  -223,   830,  -223,
    -223,   146,  -223,     1,  -223,  -223,  -223,  -223,  -223,   121,
     121,    36,    36,   224,   224,   224,   224,   116,   116,   229,
     151,   150,   158,   236,   -50,  -223,  -223,  -223,   228,   240,
    -223,   225,   165,  1198,   736,  -223,  -223,  -223,   488,  -223,
    -223,  -223,  -223,  -223,   524,   524,   524,   830,   760,  -223,
    -223,   830,  -223,   830,  -223,  -223,  -223,  -223,   242,  -223,
     241,  -223,  -223,   239,  -223,  -223,   148,   524,   155,  -223,
    -223,  -223,  -223,   524,   244,  -223,   524,  -223,  -223,  -223
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -223,  -223,  -223,  -223,   -48,  -223,   -91,    37,    46,     8,
      48,   110,   119,   122,   118,   135,  -223,   -55,   -70,  -223,
     -38,   -54,     6,     0,  -223,   272,  -223,   -27,  -223,  -223,
     268,   -67,   -24,  -223,   108,  -223,   300,   213,    47,   -13,
     -29,    -3,  -223,   -57,  -223,   126,  -223,   199,  -122,  -222,
    -151,  -223,   -74,  -223,   156,   -25,   238,  -172,  -223,  -223,
    -223,  -223,   333,  -223
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If zero, do what YYDEFACT says.
   If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -1
static const yytype_uint16 yytable[] =
{
      25,   140,   155,   246,   147,    60,    24,   261,    38,    40,
     161,   146,    47,   302,    50,   224,   226,   236,   178,   206,
      42,     1,    74,    63,    76,     1,    48,    49,   128,     1,
     323,    52,   147,   173,     1,    25,   169,   171,   172,   146,
      69,    24,   134,   151,   302,     1,    16,    17,    76,    76,
      76,   151,   159,    76,    64,   231,   166,   134,   139,   184,
     185,   152,   146,   135,   267,   322,   165,   226,   167,   243,
      41,    76,    23,    75,   186,     1,    67,   225,   240,   232,
     135,   233,   241,   232,   155,   233,    23,    22,    39,   318,
      68,   161,    22,   253,    51,   147,   244,   174,    80,    23,
     256,   308,   146,    22,    70,   210,   211,   147,   249,   226,
      23,   264,   180,    44,   146,   226,   276,   277,   278,   309,
      71,   272,    80,    80,    80,   227,   234,    80,   214,   215,
     185,    76,   185,    22,   135,   275,   235,   257,   258,   259,
      23,    76,   250,   314,   186,    80,   265,   226,   233,    58,
     150,    59,   162,    23,   273,   231,   295,   332,   251,   146,
     146,   146,   146,   146,   146,   146,   146,   146,   146,   146,
     146,   146,   146,   146,   146,   146,   146,   319,   147,   301,
     226,   313,   315,   266,   175,   146,   226,   294,    56,   207,
     176,   216,   217,   177,   208,   209,   263,   147,   311,   188,
     189,   190,   179,    73,   146,    80,    60,   316,   320,   181,
     344,   226,   321,   136,   226,    80,   182,   346,   220,    40,
     146,   226,   283,   284,   285,   286,   303,   221,   304,   235,
     157,   265,   139,   233,   212,   213,   222,   165,   155,   139,
     333,   334,   335,   218,   219,    72,   328,   279,   280,   147,
     330,   339,   223,   191,   239,   192,   146,   193,   281,   282,
     238,   242,   266,   345,   252,   139,   287,   288,   340,   347,
     255,   260,   349,   262,   268,   146,   269,   312,   274,   336,
     338,    81,    82,    83,    84,   307,    85,    86,   317,   326,
     324,   343,   194,   195,   196,   197,   198,   199,   200,   201,
     202,   203,   325,   139,   341,   342,     2,     3,     4,     5,
       6,     7,     8,     9,    10,    11,    12,    13,    14,    15,
      16,    17,    18,    19,    20,    21,   348,    87,    88,    89,
     289,    90,    91,    92,    93,    94,    95,    96,    97,    98,
     290,   292,   153,   158,   291,    99,   100,   101,   102,   103,
     104,    81,    82,    83,    84,   204,    85,    86,   310,   293,
     105,    53,   106,   149,   245,   306,   229,   254,    62,     0,
       0,     0,     0,     0,     0,     0,     2,     3,     4,     5,
       6,     7,     8,     9,    10,    11,    12,    13,    14,    15,
      16,    17,    18,    19,    20,    21,     0,    87,    88,    89,
       0,    90,    91,    92,    93,    94,    95,    96,    97,    98,
       0,   137,     0,     0,     0,    99,   100,   101,   102,   103,
     104,    81,    82,    83,    84,     0,    85,    86,     0,     0,
     105,    53,   228,     0,     0,     0,     2,     3,     4,     5,
       6,     7,     8,     9,    10,    11,    12,    13,    14,    15,
      16,    17,    18,    19,    20,    21,     0,    81,    82,    83,
      84,     0,    85,    86,     0,     0,     0,    87,    88,    89,
     138,    90,    91,    92,    93,    94,    95,    96,    97,    98,
       0,     0,     0,     0,     0,    99,   100,   101,   102,   103,
     104,   144,    82,    83,    84,     0,    85,    86,     0,     0,
     105,    53,   230,    87,    88,    89,     0,    90,    91,    92,
      93,    94,    95,    96,    97,    98,     0,     0,     0,     0,
       0,    99,   100,   101,   102,   103,   104,    81,    82,    83,
      84,     0,    85,    86,     0,     0,   105,    53,   296,     0,
       0,     0,     0,     0,     0,   144,    82,    83,    84,    98,
      85,    86,     0,     0,     0,    99,   100,   101,   102,   103,
     104,     0,   144,    82,    83,    84,     0,    85,    86,     0,
       0,   154,   331,    87,    88,    89,     0,    90,    91,    92,
      93,    94,    95,    96,    97,    98,     0,     0,     0,     0,
       0,    99,   100,   101,   102,   103,   104,     0,     0,   144,
      82,    83,    84,    98,    85,    86,   105,    53,     0,    99,
     100,   101,   102,   103,   104,     0,     0,     0,     0,     0,
      98,     0,     0,     0,     0,   154,    99,   100,   101,   102,
     103,   104,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   183,     0,     0,     0,     0,     0,     0,   144,    82,
      83,    84,     0,    85,    86,     0,     0,    98,     0,     0,
       0,     0,     0,    99,   100,   101,   102,   103,   104,   144,
      82,    83,    84,     2,    85,    86,     0,     0,   105,     8,
       9,    10,    11,    12,    13,    14,    15,    16,    17,    18,
      19,    20,    21,   144,    82,    83,    84,     0,    85,    86,
       0,     0,     0,     0,     0,     0,    98,     0,     0,     0,
       0,     0,    99,   100,   101,   102,   103,   104,   144,    82,
      83,    84,     0,    85,    86,     0,     0,    98,     0,     0,
     145,     0,     0,    99,   100,   101,   102,   103,   104,   144,
      82,    83,    84,     0,    85,    86,     0,     0,     0,     0,
       0,    98,   270,     0,     0,     0,     0,    99,   100,   101,
     102,   103,   104,   144,    82,    83,    84,     0,    85,    86,
       0,     0,     0,     0,     0,     0,    98,     0,     0,   300,
       0,     0,    99,   100,   101,   102,   103,   104,   144,    82,
      83,    84,     0,    85,    86,     0,     0,    98,     0,     0,
     329,     0,     0,    99,   100,   101,   102,   103,   104,   144,
      82,    83,    84,     0,    85,    86,     0,     0,     0,     0,
       0,    98,   337,     0,     0,     0,     0,    99,   100,   101,
     102,   103,   104,   144,    82,    83,    84,     0,    85,    86,
       0,     0,     0,     0,     0,     0,   168,     0,     0,     0,
       0,     0,    99,   100,   101,   102,   103,   104,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   170,     0,     0,
       0,     0,     0,    99,   100,   101,   102,   103,   104,    61,
       0,     0,     1,     0,     0,     0,     0,     0,     0,     0,
       0,    98,     0,     0,     0,     0,     0,    99,   100,   101,
     102,   103,   104,     0,     0,     0,     0,     2,     3,     4,
       5,     6,     7,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,     1,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      22,     0,     0,     0,     0,     0,     0,    23,     0,     0,
       0,     0,     2,     3,     4,     5,     6,     7,     8,     9,
      10,    11,    12,    13,    14,    15,    16,    17,    18,    19,
      20,    21,     1,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   232,   297,   233,     0,     0,
       0,     0,    23,     0,     0,     0,     0,     2,     3,     4,
       5,     6,     7,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      22,     0,     2,     0,     0,     0,     0,    23,     8,     9,
      10,    11,    12,    13,    14,    15,    16,    17,    18,    19,
      20,    21,     2,     0,     0,     0,     0,     0,     8,     9,
      10,    11,    12,    13,    14,    15,    16,    17,    18,    19,
      20,    21,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     2,     0,     0,     0,     0,   160,     8,
       9,    10,    11,    12,    13,    14,    15,    16,    17,    18,
      19,    20,    21,     0,     0,     0,     0,     0,   248,     2,
       3,     4,     5,     6,     7,     8,     9,    10,    11,    12,
      13,    14,    15,    16,    17,    18,    19,    20,    21,     2,
       3,     4,     5,     6,     7,     8,     9,    10,    11,    12,
      13,    14,    15,    16,    17,    18,    19,    20,    21,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    72,     0,    53,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    53,     2,     3,     4,     5,     6,
       7,     8,     9,    10,    11,    12,    13,    14,    15,    16,
      17,    18,    19,    20,    21,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   265,   297,
     233,     0,     0,     0,     0,    23,     2,     3,     4,     5,
       6,     7,     8,     9,    10,    11,    12,    13,    14,    15,
      16,    17,    18,    19,    20,    21,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     327,     2,     3,     4,     5,     6,     7,     8,     9,    10,
      11,    12,    13,    14,    15,    16,    17,    18,    19,    20,
      21,   305,     2,     3,     4,     5,     6,     7,     8,     9,
      10,    11,    12,    13,    14,    15,    16,    17,    18,    19,
      20,    21
};

static const yytype_int16 yycheck[] =
{
       0,    58,    72,   154,    59,    34,     0,   179,     3,    22,
      77,    59,    25,   235,     3,    17,    66,   139,    92,   110,
      23,     3,    47,    83,    51,     3,    26,    27,    53,     3,
      80,    31,    87,    87,     3,    35,    84,    85,    86,    87,
      43,    35,    55,    66,   266,     3,    42,    43,    75,    76,
      77,    66,    76,    80,     3,   129,    80,    70,    58,    97,
      98,    84,   110,    57,   186,    64,    79,    66,    80,    84,
      23,    98,    68,    83,    98,     3,    62,    79,    62,    61,
      74,    63,    66,    61,   154,    63,    68,    61,    83,   261,
      43,   158,    61,   167,    83,   150,   150,    80,    51,    68,
     174,    66,   150,    61,    66,    69,    70,   162,   162,    66,
      68,    62,     3,    82,   162,    66,   207,   208,   209,    84,
      82,   191,    75,    76,    77,    82,   139,    80,    12,    13,
     168,   158,   170,    61,   128,   205,   139,   175,   176,   177,
      68,   168,    66,    62,   168,    98,    61,    66,    63,    61,
      81,    63,    80,    68,   192,   229,   226,   308,    82,   207,
     208,   209,   210,   211,   212,   213,   214,   215,   216,   217,
     218,   219,   220,   221,   222,   223,   224,   268,   233,   233,
      66,   255,    62,   186,    61,   233,    66,   225,    32,    68,
      61,    75,    76,    61,    73,    74,    82,   252,   252,     7,
       8,     9,    61,    47,   252,   158,   235,    62,    62,    82,
      62,    66,    66,    57,    66,   168,    82,    62,    67,   232,
     268,    66,   214,   215,   216,   217,    61,    77,    63,   232,
      74,    61,   232,    63,    10,    11,    78,   250,   308,   239,
     314,   315,   316,    14,    15,    81,   303,   210,   211,   304,
     304,   321,    16,    61,    66,    63,   304,    65,   212,   213,
      62,    64,   265,   337,    80,   265,   218,   219,   323,   343,
      80,    54,   346,    82,    62,   323,     3,    62,     3,   317,
     318,     3,     4,     5,     6,     3,     8,     9,    61,    64,
      62,    52,    18,    19,    20,    21,    22,    23,    24,    25,
      26,    27,    62,   303,    62,    64,    28,    29,    30,    31,
      32,    33,    34,    35,    36,    37,    38,    39,    40,    41,
      42,    43,    44,    45,    46,    47,    82,    49,    50,    51,
     220,    53,    54,    55,    56,    57,    58,    59,    60,    61,
     221,   223,    70,    75,   222,    67,    68,    69,    70,    71,
      72,     3,     4,     5,     6,    81,     8,     9,   250,   224,
      82,    83,    84,    63,   151,   239,   128,   168,    35,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    28,    29,    30,    31,
      32,    33,    34,    35,    36,    37,    38,    39,    40,    41,
      42,    43,    44,    45,    46,    47,    -1,    49,    50,    51,
      -1,    53,    54,    55,    56,    57,    58,    59,    60,    61,
      -1,     3,    -1,    -1,    -1,    67,    68,    69,    70,    71,
      72,     3,     4,     5,     6,    -1,     8,     9,    -1,    -1,
      82,    83,    84,    -1,    -1,    -1,    28,    29,    30,    31,
      32,    33,    34,    35,    36,    37,    38,    39,    40,    41,
      42,    43,    44,    45,    46,    47,    -1,     3,     4,     5,
       6,    -1,     8,     9,    -1,    -1,    -1,    49,    50,    51,
      62,    53,    54,    55,    56,    57,    58,    59,    60,    61,
      -1,    -1,    -1,    -1,    -1,    67,    68,    69,    70,    71,
      72,     3,     4,     5,     6,    -1,     8,     9,    -1,    -1,
      82,    83,    84,    49,    50,    51,    -1,    53,    54,    55,
      56,    57,    58,    59,    60,    61,    -1,    -1,    -1,    -1,
      -1,    67,    68,    69,    70,    71,    72,     3,     4,     5,
       6,    -1,     8,     9,    -1,    -1,    82,    83,    84,    -1,
      -1,    -1,    -1,    -1,    -1,     3,     4,     5,     6,    61,
       8,     9,    -1,    -1,    -1,    67,    68,    69,    70,    71,
      72,    -1,     3,     4,     5,     6,    -1,     8,     9,    -1,
      -1,    83,    84,    49,    50,    51,    -1,    53,    54,    55,
      56,    57,    58,    59,    60,    61,    -1,    -1,    -1,    -1,
      -1,    67,    68,    69,    70,    71,    72,    -1,    -1,     3,
       4,     5,     6,    61,     8,     9,    82,    83,    -1,    67,
      68,    69,    70,    71,    72,    -1,    -1,    -1,    -1,    -1,
      61,    -1,    -1,    -1,    -1,    83,    67,    68,    69,    70,
      71,    72,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    82,    -1,    -1,    -1,    -1,    -1,    -1,     3,     4,
       5,     6,    -1,     8,     9,    -1,    -1,    61,    -1,    -1,
      -1,    -1,    -1,    67,    68,    69,    70,    71,    72,     3,
       4,     5,     6,    28,     8,     9,    -1,    -1,    82,    34,
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
      45,    46,    47,     3,     4,     5,     6,    -1,     8,     9,
      -1,    -1,    -1,    -1,    -1,    -1,    61,    -1,    -1,    -1,
      -1,    -1,    67,    68,    69,    70,    71,    72,     3,     4,
       5,     6,    -1,     8,     9,    -1,    -1,    61,    -1,    -1,
      64,    -1,    -1,    67,    68,    69,    70,    71,    72,     3,
       4,     5,     6,    -1,     8,     9,    -1,    -1,    -1,    -1,
      -1,    61,    62,    -1,    -1,    -1,    -1,    67,    68,    69,
      70,    71,    72,     3,     4,     5,     6,    -1,     8,     9,
      -1,    -1,    -1,    -1,    -1,    -1,    61,    -1,    -1,    64,
      -1,    -1,    67,    68,    69,    70,    71,    72,     3,     4,
       5,     6,    -1,     8,     9,    -1,    -1,    61,    -1,    -1,
      64,    -1,    -1,    67,    68,    69,    70,    71,    72,     3,
       4,     5,     6,    -1,     8,     9,    -1,    -1,    -1,    -1,
      -1,    61,    62,    -1,    -1,    -1,    -1,    67,    68,    69,
      70,    71,    72,     3,     4,     5,     6,    -1,     8,     9,
      -1,    -1,    -1,    -1,    -1,    -1,    61,    -1,    -1,    -1,
      -1,    -1,    67,    68,    69,    70,    71,    72,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    61,    -1,    -1,
      -1,    -1,    -1,    67,    68,    69,    70,    71,    72,     0,
      -1,    -1,     3,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    61,    -1,    -1,    -1,    -1,    -1,    67,    68,    69,
      70,    71,    72,    -1,    -1,    -1,    -1,    28,    29,    30,
      31,    32,    33,    34,    35,    36,    37,    38,    39,    40,
      41,    42,    43,    44,    45,    46,    47,     3,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      61,    -1,    -1,    -1,    -1,    -1,    -1,    68,    -1,    -1,
      -1,    -1,    28,    29,    30,    31,    32,    33,    34,    35,
      36,    37,    38,    39,    40,    41,    42,    43,    44,    45,
      46,    47,     3,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    61,    62,    63,    -1,    -1,
      -1,    -1,    68,    -1,    -1,    -1,    -1,    28,    29,    30,
      31,    32,    33,    34,    35,    36,    37,    38,    39,    40,
      41,    42,    43,    44,    45,    46,    47,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      61,    -1,    28,    -1,    -1,    -1,    -1,    68,    34,    35,
      36,    37,    38,    39,    40,    41,    42,    43,    44,    45,
      46,    47,    28,    -1,    -1,    -1,    -1,    -1,    34,    35,
      36,    37,    38,    39,    40,    41,    42,    43,    44,    45,
      46,    47,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    28,    -1,    -1,    -1,    -1,    84,    34,
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
      45,    46,    47,    -1,    -1,    -1,    -1,    -1,    84,    28,
      29,    30,    31,    32,    33,    34,    35,    36,    37,    38,
      39,    40,    41,    42,    43,    44,    45,    46,    47,    28,
      29,    30,    31,    32,    33,    34,    35,    36,    37,    38,
      39,    40,    41,    42,    43,    44,    45,    46,    47,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    81,    -1,    83,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    83,    28,    29,    30,    31,    32,
      33,    34,    35,    36,    37,    38,    39,    40,    41,    42,
      43,    44,    45,    46,    47,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    61,    62,
      63,    -1,    -1,    -1,    -1,    68,    28,    29,    30,    31,
      32,    33,    34,    35,    36,    37,    38,    39,    40,    41,
      42,    43,    44,    45,    46,    47,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      62,    28,    29,    30,    31,    32,    33,    34,    35,    36,
      37,    38,    39,    40,    41,    42,    43,    44,    45,    46,
      47,    48,    28,    29,    30,    31,    32,    33,    34,    35,
      36,    37,    38,    39,    40,    41,    42,    43,    44,    45,
      46,    47
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,     3,    28,    29,    30,    31,    32,    33,    34,    35,
      36,    37,    38,    39,    40,    41,    42,    43,    44,    45,
      46,    47,    61,    68,   107,   108,   111,   112,   113,   114,
     120,   123,   124,   125,   126,   146,   147,   148,     3,    83,
     124,   123,   126,   127,    82,   109,   110,   124,   108,   108,
       3,    83,   108,    83,   107,   108,   139,   140,    61,    63,
     125,     0,   147,    83,     3,   121,   122,    62,   123,   126,
      66,    82,    81,   139,   140,    83,   112,   115,   116,   117,
     123,     3,     4,     5,     6,     8,     9,    49,    50,    51,
      53,    54,    55,    56,    57,    58,    59,    60,    61,    67,
      68,    69,    70,    71,    72,    82,    84,    86,    87,    89,
      90,    91,    92,    93,    94,    95,    96,    97,    98,    99,
     100,   101,   102,   103,   105,   137,   138,   139,   140,   141,
     142,   143,   144,   145,   124,   107,   139,     3,    62,   108,
     128,   129,   130,   131,     3,    64,    89,   102,   106,   121,
      81,    66,    84,   110,    83,   103,   135,   139,   115,   117,
      84,   116,    80,   118,   119,   124,   117,    80,    61,    89,
      61,    89,    89,   106,    80,    61,    61,    61,   137,    61,
       3,    82,    82,    82,   105,   105,   117,   132,     7,     8,
       9,    61,    63,    65,    18,    19,    20,    21,    22,    23,
      24,    25,    26,    27,    81,   104,    91,    68,    73,    74,
      69,    70,    10,    11,    12,    13,    75,    76,    14,    15,
      67,    77,    78,    16,    17,    79,    66,    82,    84,   141,
      84,   137,    61,    63,   124,   126,   133,   134,    62,    66,
      62,    66,    64,    84,   106,   122,   135,   136,    84,   106,
      66,    82,    80,   137,   132,    80,   137,   105,   105,   105,
      54,   142,    82,    82,    62,    61,   126,   133,    62,     3,
      62,    88,   103,   105,     3,   103,    91,    91,    91,    92,
      92,    93,    93,    94,    94,    94,    94,    95,    95,    96,
      97,    98,    99,   100,   105,   103,    84,    62,   128,   133,
      64,   106,   134,    61,    63,    48,   130,     3,    66,    84,
     119,   106,    62,   137,    62,    62,    62,    61,   142,    91,
      62,    66,    64,    80,    62,    62,    64,    62,   128,    64,
     106,    84,   135,   137,   137,   137,   105,    62,   105,   103,
     102,    62,    64,    52,    62,   137,    62,   137,    82,   137
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


/* The lookahead symbol.  */
int yychar;

/* The semantic value of the lookahead symbol.  */
YYSTYPE yylval;

/* Number of syntax errors so far.  */
int yynerrs;



/*-------------------------.
| yyparse or yypush_parse.  |
`-------------------------*/

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

       Refer to the stacks thru separate pointers, to allow yyoverflow
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
  int yytoken;
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

  yytoken = 0;
  yyss = yyssa;
  yyvs = yyvsa;
  yystacksize = YYINITDEPTH;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yystate = 0;
  yyerrstatus = 0;
  yynerrs = 0;
  yychar = YYEMPTY; /* Cause a token to be read.  */

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
  if (yyn == YYPACT_NINF)
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
      if (yyn == 0 || yyn == YYTABLE_NINF)
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

/* Line 1455 of yacc.c  */
#line 30 "par/cparser.y"
    {printf(": primary_expression->IDENTIFIER\n");;}
    break;

  case 3:

/* Line 1455 of yacc.c  */
#line 31 "par/cparser.y"
    {printf(": primary_expression->CONSTANT\n");;}
    break;

  case 4:

/* Line 1455 of yacc.c  */
#line 32 "par/cparser.y"
    {printf(": primary_expression->STRING_LITERAL\n");;}
    break;

  case 5:

/* Line 1455 of yacc.c  */
#line 33 "par/cparser.y"
    {printf(": primary_expression->(expression)\n");;}
    break;

  case 6:

/* Line 1455 of yacc.c  */
#line 37 "par/cparser.y"
    {printf(": postfix_expression->primary_expression\n");;}
    break;

  case 7:

/* Line 1455 of yacc.c  */
#line 38 "par/cparser.y"
    {printf(": postfix_expression->[expression]\n");;}
    break;

  case 8:

/* Line 1455 of yacc.c  */
#line 39 "par/cparser.y"
    {printf(": postfix_expression->()\n");;}
    break;

  case 9:

/* Line 1455 of yacc.c  */
#line 40 "par/cparser.y"
    {printf(": postfix_expression->(argument_expression_list)\n");;}
    break;

  case 10:

/* Line 1455 of yacc.c  */
#line 41 "par/cparser.y"
    {printf(": postfix_expression->IDENTIFIER\n");;}
    break;

  case 11:

/* Line 1455 of yacc.c  */
#line 42 "par/cparser.y"
    {printf(": postfix_expression->'->'IDENTIFIER\n");;}
    break;

  case 12:

/* Line 1455 of yacc.c  */
#line 43 "par/cparser.y"
    {printf(": postfix_expression->++\n");;}
    break;

  case 13:

/* Line 1455 of yacc.c  */
#line 44 "par/cparser.y"
    {printf(": postfix_expression->--\n");;}
    break;

  case 14:

/* Line 1455 of yacc.c  */
#line 48 "par/cparser.y"
    {printf(": argument_expression_list->assignment_expression \n");;}
    break;

  case 15:

/* Line 1455 of yacc.c  */
#line 49 "par/cparser.y"
    {printf(": argument_expression_list->argument_expression_list,assignment_expression \n");;}
    break;

  case 16:

/* Line 1455 of yacc.c  */
#line 53 "par/cparser.y"
    {printf(": unary_expression->postfix_expression \n");;}
    break;

  case 17:

/* Line 1455 of yacc.c  */
#line 54 "par/cparser.y"
    {printf(": unary_expression->++ unary_expression \n");;}
    break;

  case 18:

/* Line 1455 of yacc.c  */
#line 55 "par/cparser.y"
    {printf(": unary_expression->-- unary_expression \n");;}
    break;

  case 19:

/* Line 1455 of yacc.c  */
#line 56 "par/cparser.y"
    {printf(": unary_expression->unary_operator cast_expression \n");;}
    break;

  case 20:

/* Line 1455 of yacc.c  */
#line 57 "par/cparser.y"
    {printf(": unary_expression->sizeof unary_operator\n");;}
    break;

  case 21:

/* Line 1455 of yacc.c  */
#line 58 "par/cparser.y"
    {printf(": unary_expression->sizeof (type_name)\n");;}
    break;

  case 22:

/* Line 1455 of yacc.c  */
#line 62 "par/cparser.y"
    {printf(": unary_operator->&\n");;}
    break;

  case 23:

/* Line 1455 of yacc.c  */
#line 63 "par/cparser.y"
    {printf(": unary_operator->*\n");;}
    break;

  case 24:

/* Line 1455 of yacc.c  */
#line 64 "par/cparser.y"
    {printf(": unary_operator->+\n");;}
    break;

  case 25:

/* Line 1455 of yacc.c  */
#line 65 "par/cparser.y"
    {printf(": unary_operator->-\n");;}
    break;

  case 26:

/* Line 1455 of yacc.c  */
#line 66 "par/cparser.y"
    {printf(": unary_operator->~\n");;}
    break;

  case 27:

/* Line 1455 of yacc.c  */
#line 67 "par/cparser.y"
    {printf(": unary_operator->!\n");;}
    break;

  case 28:

/* Line 1455 of yacc.c  */
#line 71 "par/cparser.y"
    {printf(": cast_expression->unary_expression\n");;}
    break;

  case 29:

/* Line 1455 of yacc.c  */
#line 72 "par/cparser.y"
    {printf(": cast_expression->(type_name)\n");;}
    break;

  case 30:

/* Line 1455 of yacc.c  */
#line 76 "par/cparser.y"
    {printf(": multiplicative_expression->cast_expression\n");;}
    break;

  case 31:

/* Line 1455 of yacc.c  */
#line 77 "par/cparser.y"
    {printf(": multiplicative_expression->multiplicative_expression * cast_expression\n");;}
    break;

  case 32:

/* Line 1455 of yacc.c  */
#line 78 "par/cparser.y"
    {printf(": multiplicative_expression->multiplicative_expression / cast_expression\n");;}
    break;

  case 33:

/* Line 1455 of yacc.c  */
#line 79 "par/cparser.y"
    {printf(": multiplicative_expression->multiplicative_expression %% cast_expression\n");;}
    break;

  case 34:

/* Line 1455 of yacc.c  */
#line 83 "par/cparser.y"
    {printf(": additive_expression->multiplicative_expression\n");;}
    break;

  case 35:

/* Line 1455 of yacc.c  */
#line 84 "par/cparser.y"
    {printf(": additive_expression->additive_expression + multiplicative_expression\n");;}
    break;

  case 36:

/* Line 1455 of yacc.c  */
#line 85 "par/cparser.y"
    {printf(": additive_expression->additive_expression - multiplicative_expression\n");;}
    break;

  case 37:

/* Line 1455 of yacc.c  */
#line 89 "par/cparser.y"
    {printf(": shift_expression->additive_expression\n");;}
    break;

  case 38:

/* Line 1455 of yacc.c  */
#line 90 "par/cparser.y"
    {printf(": shift_expression->shift_expression << additive_expression\n");;}
    break;

  case 39:

/* Line 1455 of yacc.c  */
#line 91 "par/cparser.y"
    {printf(": shift_expression->shift_expression >> additive_expression\n");;}
    break;

  case 40:

/* Line 1455 of yacc.c  */
#line 95 "par/cparser.y"
    {printf(": relational_expression->shift_expression\n");;}
    break;

  case 41:

/* Line 1455 of yacc.c  */
#line 96 "par/cparser.y"
    {printf(": relational_expression->relational_expression < shift_expression\n");;}
    break;

  case 42:

/* Line 1455 of yacc.c  */
#line 97 "par/cparser.y"
    {printf(": relational_expression->relational_expression > shift_expression\n");;}
    break;

  case 43:

/* Line 1455 of yacc.c  */
#line 98 "par/cparser.y"
    {printf(": relational_expression->relational_expression >= shift_expression\n");;}
    break;

  case 44:

/* Line 1455 of yacc.c  */
#line 99 "par/cparser.y"
    {printf(": relational_expression->relational_expression <= shift_expression\n");;}
    break;

  case 45:

/* Line 1455 of yacc.c  */
#line 103 "par/cparser.y"
    {printf(": equality_expression->relational_expression\n");;}
    break;

  case 46:

/* Line 1455 of yacc.c  */
#line 104 "par/cparser.y"
    {printf(": equality_expression->equality_expression == relational_expression\n");;}
    break;

  case 47:

/* Line 1455 of yacc.c  */
#line 105 "par/cparser.y"
    {printf(": equality_expression->equality_expression != relational_expression\n");;}
    break;

  case 48:

/* Line 1455 of yacc.c  */
#line 109 "par/cparser.y"
    {printf(": and_expression->equality_expression\n");;}
    break;

  case 49:

/* Line 1455 of yacc.c  */
#line 110 "par/cparser.y"
    {printf(": and_expression->and_expression '&' equality_expression\n");;}
    break;

  case 50:

/* Line 1455 of yacc.c  */
#line 114 "par/cparser.y"
    {printf(": exclusive_or_expression->and_expression\n");;}
    break;

  case 51:

/* Line 1455 of yacc.c  */
#line 115 "par/cparser.y"
    {printf(": exclusive_or_expression->exclusive_or_expression ^ and_expression\n");;}
    break;

  case 52:

/* Line 1455 of yacc.c  */
#line 119 "par/cparser.y"
    {printf(": inclusive_or_expression->exclusive_or_expression\n");;}
    break;

  case 53:

/* Line 1455 of yacc.c  */
#line 120 "par/cparser.y"
    {printf(": inclusive_or_expression->inclusive_or_expression | exclusive_or_expression\n");;}
    break;

  case 54:

/* Line 1455 of yacc.c  */
#line 124 "par/cparser.y"
    {printf(": logical_and_expression->inclusive_or_expression\n");;}
    break;

  case 55:

/* Line 1455 of yacc.c  */
#line 125 "par/cparser.y"
    {printf(": logical_and_expression->logical_and_expression && inclusive_or_expression\n");;}
    break;

  case 56:

/* Line 1455 of yacc.c  */
#line 129 "par/cparser.y"
    {printf(": logical_or_expression->logical_and_expression\n");;}
    break;

  case 57:

/* Line 1455 of yacc.c  */
#line 130 "par/cparser.y"
    {printf(": logical_or_expression->logical_or_expression || logical_and_expression\n");;}
    break;

  case 58:

/* Line 1455 of yacc.c  */
#line 134 "par/cparser.y"
    {printf(": conditional_expression->logical_or_expression\n");;}
    break;

  case 59:

/* Line 1455 of yacc.c  */
#line 135 "par/cparser.y"
    {printf(": conditional_expression->logical_or_expression ? expression : conditional_expression\n");;}
    break;

  case 60:

/* Line 1455 of yacc.c  */
#line 139 "par/cparser.y"
    {printf(": assignment_expression->conditional_expression\n");;}
    break;

  case 61:

/* Line 1455 of yacc.c  */
#line 140 "par/cparser.y"
    {printf(": assignment_expression->unary_expression assignment_operator assignment_expression\n");;}
    break;

  case 62:

/* Line 1455 of yacc.c  */
#line 144 "par/cparser.y"
    {printf(": assignment_operator->=\n");;}
    break;

  case 63:

/* Line 1455 of yacc.c  */
#line 145 "par/cparser.y"
    {printf(": assignment_operator->*=\n");;}
    break;

  case 64:

/* Line 1455 of yacc.c  */
#line 146 "par/cparser.y"
    {printf(": assignment_operator->/=\n");;}
    break;

  case 65:

/* Line 1455 of yacc.c  */
#line 147 "par/cparser.y"
    {printf(": assignment_operator->%%=\n");;}
    break;

  case 66:

/* Line 1455 of yacc.c  */
#line 148 "par/cparser.y"
    {printf(": assignment_operator->+=\n");;}
    break;

  case 67:

/* Line 1455 of yacc.c  */
#line 149 "par/cparser.y"
    {printf(": assignment_operator->-=\n");;}
    break;

  case 68:

/* Line 1455 of yacc.c  */
#line 150 "par/cparser.y"
    {printf(": assignment_operator-><<=\n");;}
    break;

  case 69:

/* Line 1455 of yacc.c  */
#line 151 "par/cparser.y"
    {printf(": assignment_operator->>>=\n");;}
    break;

  case 70:

/* Line 1455 of yacc.c  */
#line 152 "par/cparser.y"
    {printf(": assignment_operator->&=\n");;}
    break;

  case 71:

/* Line 1455 of yacc.c  */
#line 153 "par/cparser.y"
    {printf(": assignment_operator->^=\n");;}
    break;

  case 72:

/* Line 1455 of yacc.c  */
#line 154 "par/cparser.y"
    {printf(": assignment_operator->|=\n");;}
    break;

  case 73:

/* Line 1455 of yacc.c  */
#line 158 "par/cparser.y"
    {printf(": expression->assignment_expression\n");;}
    break;

  case 74:

/* Line 1455 of yacc.c  */
#line 159 "par/cparser.y"
    {printf(": expression->expression , assignment_expression\n");;}
    break;

  case 75:

/* Line 1455 of yacc.c  */
#line 163 "par/cparser.y"
    {printf(": constant_expression->conditional_expression\n");;}
    break;

  case 76:

/* Line 1455 of yacc.c  */
#line 167 "par/cparser.y"
    {printf(": declaration->declaration_specifiers ;\n");;}
    break;

  case 77:

/* Line 1455 of yacc.c  */
#line 168 "par/cparser.y"
    {printf(": declaration->declaration_specifiers init_declarator_list ;\n");;}
    break;

  case 78:

/* Line 1455 of yacc.c  */
#line 172 "par/cparser.y"
    {printf(": declaration_specifiers->storage_class_specifier\n");;}
    break;

  case 79:

/* Line 1455 of yacc.c  */
#line 173 "par/cparser.y"
    {printf(": declaration_specifiers->storage_class_specifier declaration_specifiers\n");;}
    break;

  case 80:

/* Line 1455 of yacc.c  */
#line 174 "par/cparser.y"
    {printf(": declaration_specifiers->type_specifier\n");;}
    break;

  case 81:

/* Line 1455 of yacc.c  */
#line 175 "par/cparser.y"
    {printf(": declaration_specifiers->type_specifier declaration_specifiers\n");;}
    break;

  case 82:

/* Line 1455 of yacc.c  */
#line 176 "par/cparser.y"
    {printf(": declaration_specifiers->type_qualifier\n");;}
    break;

  case 83:

/* Line 1455 of yacc.c  */
#line 177 "par/cparser.y"
    {printf(": declaration_specifiers->type_qualifier declaration_specifiers\n");;}
    break;

  case 84:

/* Line 1455 of yacc.c  */
#line 181 "par/cparser.y"
    {printf(": init_declarator_list->init_declarator\n");;}
    break;

  case 85:

/* Line 1455 of yacc.c  */
#line 182 "par/cparser.y"
    {printf(": init_declarator_list->init_declarator_list , init_declarator\n");;}
    break;

  case 86:

/* Line 1455 of yacc.c  */
#line 186 "par/cparser.y"
    {printf(": init_declarator->declarator\n");;}
    break;

  case 87:

/* Line 1455 of yacc.c  */
#line 187 "par/cparser.y"
    {printf(": init_declarator->declarator = initializer\n");;}
    break;

  case 88:

/* Line 1455 of yacc.c  */
#line 191 "par/cparser.y"
    {printf(": storage_class_specifier->TYPEDEF\n");;}
    break;

  case 89:

/* Line 1455 of yacc.c  */
#line 192 "par/cparser.y"
    {printf(": storage_class_specifier->EXTERN\n");;}
    break;

  case 90:

/* Line 1455 of yacc.c  */
#line 193 "par/cparser.y"
    {printf(": storage_class_specifier->STATIC\n");;}
    break;

  case 91:

/* Line 1455 of yacc.c  */
#line 194 "par/cparser.y"
    {printf(": storage_class_specifier->AUTO\n");;}
    break;

  case 92:

/* Line 1455 of yacc.c  */
#line 195 "par/cparser.y"
    {printf(": storage_class_specifier->REGISTER\n");;}
    break;

  case 93:

/* Line 1455 of yacc.c  */
#line 199 "par/cparser.y"
    {printf(": type_specifier->VOID\n");;}
    break;

  case 94:

/* Line 1455 of yacc.c  */
#line 200 "par/cparser.y"
    {printf(": type_specifier->CHAR\n");;}
    break;

  case 95:

/* Line 1455 of yacc.c  */
#line 201 "par/cparser.y"
    {printf(": type_specifier->SHORT\n");;}
    break;

  case 96:

/* Line 1455 of yacc.c  */
#line 202 "par/cparser.y"
    {printf(": type_specifier->INT\n");;}
    break;

  case 97:

/* Line 1455 of yacc.c  */
#line 203 "par/cparser.y"
    {printf(": type_specifier->LONG\n");;}
    break;

  case 98:

/* Line 1455 of yacc.c  */
#line 204 "par/cparser.y"
    {printf(": type_specifier->FLOAT\n");;}
    break;

  case 99:

/* Line 1455 of yacc.c  */
#line 205 "par/cparser.y"
    {printf(": type_specifier->DOUBLE\n");;}
    break;

  case 100:

/* Line 1455 of yacc.c  */
#line 206 "par/cparser.y"
    {printf(": type_specifier->SIGNED\n");;}
    break;

  case 101:

/* Line 1455 of yacc.c  */
#line 207 "par/cparser.y"
    {printf(": type_specifier->UNSIGNED\n");;}
    break;

  case 102:

/* Line 1455 of yacc.c  */
#line 208 "par/cparser.y"
    {printf(": type_specifier->struct_or_union_specifier\n");;}
    break;

  case 103:

/* Line 1455 of yacc.c  */
#line 209 "par/cparser.y"
    {printf(": type_specifier->enum_specifier\n");;}
    break;

  case 104:

/* Line 1455 of yacc.c  */
#line 210 "par/cparser.y"
    {printf(": type_specifier->TYPE_NAME\n");;}
    break;

  case 105:

/* Line 1455 of yacc.c  */
#line 214 "par/cparser.y"
    {printf(": struct_or_union_specifier->struct_or_union IDENTIFIER { struct_declaration_list }\n");;}
    break;

  case 106:

/* Line 1455 of yacc.c  */
#line 215 "par/cparser.y"
    {printf(": struct_or_union_specifier->struct_or_union { struct_declaration_list }\n");;}
    break;

  case 107:

/* Line 1455 of yacc.c  */
#line 216 "par/cparser.y"
    {printf(": struct_or_union_specifier->struct_or_union IDENTIFIER\n");;}
    break;

  case 108:

/* Line 1455 of yacc.c  */
#line 220 "par/cparser.y"
    {printf(": struct_or_union->STRUCT\n");;}
    break;

  case 109:

/* Line 1455 of yacc.c  */
#line 221 "par/cparser.y"
    {printf(": struct_or_union->UNION\n");;}
    break;

  case 110:

/* Line 1455 of yacc.c  */
#line 225 "par/cparser.y"
    {printf(": struct_declaration_list->struct_declaration\n");;}
    break;

  case 111:

/* Line 1455 of yacc.c  */
#line 226 "par/cparser.y"
    {printf(": struct_declaration_list->struct_declaration_list struct_declaration\n");;}
    break;

  case 112:

/* Line 1455 of yacc.c  */
#line 230 "par/cparser.y"
    {printf(": struct_declaration->specifier_qualifier_list struct_declarator_list ;\n");;}
    break;

  case 113:

/* Line 1455 of yacc.c  */
#line 234 "par/cparser.y"
    {printf(": specifier_qualifier_list->type_specifier specifier_qualifier_list\n");;}
    break;

  case 114:

/* Line 1455 of yacc.c  */
#line 235 "par/cparser.y"
    {printf(": specifier_qualifier_list->type_specifier\n");;}
    break;

  case 115:

/* Line 1455 of yacc.c  */
#line 236 "par/cparser.y"
    {printf(": specifier_qualifier_list->type_qualifier specifier_qualifier_list\n");;}
    break;

  case 116:

/* Line 1455 of yacc.c  */
#line 237 "par/cparser.y"
    {printf(": specifier_qualifier_list->type_qualifier\n");;}
    break;

  case 117:

/* Line 1455 of yacc.c  */
#line 241 "par/cparser.y"
    {printf(": struct_declarator_list->struct_declarator\n");;}
    break;

  case 118:

/* Line 1455 of yacc.c  */
#line 242 "par/cparser.y"
    {printf(": struct_declarator_list->struct_declarator_list , struct_declarator\n");;}
    break;

  case 119:

/* Line 1455 of yacc.c  */
#line 246 "par/cparser.y"
    {printf(": struct_declarator->declarator\n");;}
    break;

  case 120:

/* Line 1455 of yacc.c  */
#line 247 "par/cparser.y"
    {printf(": struct_declarator->: constant_expression\n");;}
    break;

  case 121:

/* Line 1455 of yacc.c  */
#line 248 "par/cparser.y"
    {printf(": struct_declarator->declarator : constant_expression\n");;}
    break;

  case 122:

/* Line 1455 of yacc.c  */
#line 252 "par/cparser.y"
    {printf(": enum_specifier->ENUM { enumerator_list }\n");;}
    break;

  case 123:

/* Line 1455 of yacc.c  */
#line 253 "par/cparser.y"
    {printf(": enum_specifier->ENUM IDENTIFIER { enumerator_list }\n");;}
    break;

  case 124:

/* Line 1455 of yacc.c  */
#line 254 "par/cparser.y"
    {printf(": enum_specifier->ENUM IDENTIFIER\n");;}
    break;

  case 125:

/* Line 1455 of yacc.c  */
#line 258 "par/cparser.y"
    {printf(": enumerator_list->enumerator\n");;}
    break;

  case 126:

/* Line 1455 of yacc.c  */
#line 259 "par/cparser.y"
    {printf(": enumerator_list->enumerator_list , enumerator\n");;}
    break;

  case 127:

/* Line 1455 of yacc.c  */
#line 263 "par/cparser.y"
    {printf(": enumerator->IDENTIFIER\n");;}
    break;

  case 128:

/* Line 1455 of yacc.c  */
#line 264 "par/cparser.y"
    {printf(": enumerator->IDENTIFIER = constant_expression\n");;}
    break;

  case 129:

/* Line 1455 of yacc.c  */
#line 268 "par/cparser.y"
    {printf(": type_qualifier->CONST\n");;}
    break;

  case 130:

/* Line 1455 of yacc.c  */
#line 269 "par/cparser.y"
    {printf(": type_qualifier->VOLATILE\n");;}
    break;

  case 131:

/* Line 1455 of yacc.c  */
#line 273 "par/cparser.y"
    {printf(": declarator->pointer direct_declarator\n");;}
    break;

  case 132:

/* Line 1455 of yacc.c  */
#line 274 "par/cparser.y"
    {printf(": declarator->direct_declarator\n");;}
    break;

  case 133:

/* Line 1455 of yacc.c  */
#line 278 "par/cparser.y"
    {printf(": direct_declarator->IDENTIFIER\n");;}
    break;

  case 134:

/* Line 1455 of yacc.c  */
#line 279 "par/cparser.y"
    {printf(": direct_declarator->( declarator )\n");;}
    break;

  case 135:

/* Line 1455 of yacc.c  */
#line 280 "par/cparser.y"
    {printf(": direct_declarator->direct_declarator [ constant_expression ]\n");;}
    break;

  case 136:

/* Line 1455 of yacc.c  */
#line 281 "par/cparser.y"
    {printf(": direct_declarator->direct_declarator [ ]\n");;}
    break;

  case 137:

/* Line 1455 of yacc.c  */
#line 282 "par/cparser.y"
    {printf(": direct_declarator->direct_declarator ( parameter_type_list )\n");;}
    break;

  case 138:

/* Line 1455 of yacc.c  */
#line 283 "par/cparser.y"
    {printf(": direct_declarator->direct_declarator ( identifier_list )\n");;}
    break;

  case 139:

/* Line 1455 of yacc.c  */
#line 284 "par/cparser.y"
    {printf(": direct_declarator->direct_declarator ( )\n");;}
    break;

  case 140:

/* Line 1455 of yacc.c  */
#line 288 "par/cparser.y"
    {printf(": pointer->*\n");;}
    break;

  case 141:

/* Line 1455 of yacc.c  */
#line 289 "par/cparser.y"
    {printf(": pointer->* type_qualifier_list\n");;}
    break;

  case 142:

/* Line 1455 of yacc.c  */
#line 290 "par/cparser.y"
    {printf(": pointer->* pointer\n");;}
    break;

  case 143:

/* Line 1455 of yacc.c  */
#line 291 "par/cparser.y"
    {printf(": pointer->* type_qualifier_list pointer\n");;}
    break;

  case 144:

/* Line 1455 of yacc.c  */
#line 295 "par/cparser.y"
    {printf(": type_qualifier_list->type_qualifier\n");;}
    break;

  case 145:

/* Line 1455 of yacc.c  */
#line 296 "par/cparser.y"
    {printf(": type_qualifier_list->type_qualifier_list type_qualifier\n");;}
    break;

  case 146:

/* Line 1455 of yacc.c  */
#line 301 "par/cparser.y"
    {printf(": parameter_type_list->parameter_list\n");;}
    break;

  case 147:

/* Line 1455 of yacc.c  */
#line 302 "par/cparser.y"
    {printf(": parameter_type_list->parameter_list , ...\n");;}
    break;

  case 148:

/* Line 1455 of yacc.c  */
#line 306 "par/cparser.y"
    {printf(": parameter_list->parameter_declaration\n");;}
    break;

  case 149:

/* Line 1455 of yacc.c  */
#line 307 "par/cparser.y"
    {printf(": parameter_list->parameter_list , parameter_declaration\n");;}
    break;

  case 150:

/* Line 1455 of yacc.c  */
#line 311 "par/cparser.y"
    {printf(": parameter_declaration->declaration_specifiers declarator\n");;}
    break;

  case 151:

/* Line 1455 of yacc.c  */
#line 312 "par/cparser.y"
    {printf(": parameter_declaration->declaration_specifiers abstract_declarator\n");;}
    break;

  case 152:

/* Line 1455 of yacc.c  */
#line 313 "par/cparser.y"
    {printf(": parameter_declaration->declaration_specifiers\n");;}
    break;

  case 153:

/* Line 1455 of yacc.c  */
#line 317 "par/cparser.y"
    {printf(": identifier_list->IDENTIFIER\n");;}
    break;

  case 154:

/* Line 1455 of yacc.c  */
#line 318 "par/cparser.y"
    {printf(": identifier_list->identifier_list , IDENTIFIER\n");;}
    break;

  case 155:

/* Line 1455 of yacc.c  */
#line 322 "par/cparser.y"
    {printf(": type_name->specifier_qualifier_list\n");;}
    break;

  case 156:

/* Line 1455 of yacc.c  */
#line 323 "par/cparser.y"
    {printf(": type_name->specifier_qualifier_list abstract_declarator\n");;}
    break;

  case 157:

/* Line 1455 of yacc.c  */
#line 327 "par/cparser.y"
    {printf(": abstract_declarator->pointer\n");;}
    break;

  case 158:

/* Line 1455 of yacc.c  */
#line 328 "par/cparser.y"
    {printf(": abstract_declarator->direct_abstract_declarator\n");;}
    break;

  case 159:

/* Line 1455 of yacc.c  */
#line 329 "par/cparser.y"
    {printf(": abstract_declarator->pointer direct_abstract_declarator\n");;}
    break;

  case 160:

/* Line 1455 of yacc.c  */
#line 333 "par/cparser.y"
    {printf(": direct_abstract_declarator->( abstract_declarator )\n");;}
    break;

  case 161:

/* Line 1455 of yacc.c  */
#line 334 "par/cparser.y"
    {printf(": direct_abstract_declarator->[ ]\n");;}
    break;

  case 162:

/* Line 1455 of yacc.c  */
#line 335 "par/cparser.y"
    {printf(": direct_abstract_declarator->[ constant_expression ]\n");;}
    break;

  case 163:

/* Line 1455 of yacc.c  */
#line 336 "par/cparser.y"
    {printf(": direct_abstract_declarator->direct_abstract_declarator [ ]\n");;}
    break;

  case 164:

/* Line 1455 of yacc.c  */
#line 337 "par/cparser.y"
    {printf(": direct_abstract_declarator->direct_abstract_declarator [ constant_expression ]\n");;}
    break;

  case 165:

/* Line 1455 of yacc.c  */
#line 338 "par/cparser.y"
    {printf(": direct_abstract_declarator->( )\n");;}
    break;

  case 166:

/* Line 1455 of yacc.c  */
#line 339 "par/cparser.y"
    {printf(": direct_abstract_declarator->( parameter_type_list )\n");;}
    break;

  case 167:

/* Line 1455 of yacc.c  */
#line 340 "par/cparser.y"
    {printf(": direct_abstract_declarator->direct_abstract_declarator ( )\n");;}
    break;

  case 168:

/* Line 1455 of yacc.c  */
#line 341 "par/cparser.y"
    {printf(": direct_abstract_declarator->direct_abstract_declarator ( parameter_type_list )\n");;}
    break;

  case 169:

/* Line 1455 of yacc.c  */
#line 345 "par/cparser.y"
    {printf(": initializer->assignment_expression\n");;}
    break;

  case 170:

/* Line 1455 of yacc.c  */
#line 346 "par/cparser.y"
    {printf(": initializer->{ initializer_list }\n");;}
    break;

  case 171:

/* Line 1455 of yacc.c  */
#line 347 "par/cparser.y"
    {printf(": initializer->{ initializer_list , }\n");;}
    break;

  case 172:

/* Line 1455 of yacc.c  */
#line 351 "par/cparser.y"
    {printf(": initializer_list->initializer\n");;}
    break;

  case 173:

/* Line 1455 of yacc.c  */
#line 352 "par/cparser.y"
    {printf(": initializer_list->initializer_list , initializer\n");;}
    break;

  case 174:

/* Line 1455 of yacc.c  */
#line 356 "par/cparser.y"
    {printf(": statement->labeled_statement\n");;}
    break;

  case 175:

/* Line 1455 of yacc.c  */
#line 357 "par/cparser.y"
    {printf(": statement->compound_statement\n");;}
    break;

  case 176:

/* Line 1455 of yacc.c  */
#line 358 "par/cparser.y"
    {printf(": statement->expression_statement\n");;}
    break;

  case 177:

/* Line 1455 of yacc.c  */
#line 359 "par/cparser.y"
    {printf(": statement->selection_statement\n");;}
    break;

  case 178:

/* Line 1455 of yacc.c  */
#line 360 "par/cparser.y"
    {printf(": statement->iteration_statement\n");;}
    break;

  case 179:

/* Line 1455 of yacc.c  */
#line 361 "par/cparser.y"
    {printf(": statement->jump_statement\n");;}
    break;

  case 180:

/* Line 1455 of yacc.c  */
#line 365 "par/cparser.y"
    {printf(": labeled_statement->IDENTIFIER : statement\n");;}
    break;

  case 181:

/* Line 1455 of yacc.c  */
#line 366 "par/cparser.y"
    {printf(": labeled_statement->CASE constant_expression : statement\n");;}
    break;

  case 182:

/* Line 1455 of yacc.c  */
#line 367 "par/cparser.y"
    {printf(": labeled_statement->DEFAULT : statement\n");;}
    break;

  case 183:

/* Line 1455 of yacc.c  */
#line 371 "par/cparser.y"
    {printf(": compound_statement->{ }\n");;}
    break;

  case 184:

/* Line 1455 of yacc.c  */
#line 372 "par/cparser.y"
    {printf(": compound_statement->{ statement_list }\n");;}
    break;

  case 185:

/* Line 1455 of yacc.c  */
#line 373 "par/cparser.y"
    {printf(": compound_statement->{ declaration_list }\n");;}
    break;

  case 186:

/* Line 1455 of yacc.c  */
#line 374 "par/cparser.y"
    {printf(": compound_statement->{ declaration_list statement_list }\n");;}
    break;

  case 187:

/* Line 1455 of yacc.c  */
#line 378 "par/cparser.y"
    {printf(": declaration_list->declaration\n");;}
    break;

  case 188:

/* Line 1455 of yacc.c  */
#line 379 "par/cparser.y"
    {printf(": declaration_list->declaration_list declaration\n");;}
    break;

  case 189:

/* Line 1455 of yacc.c  */
#line 383 "par/cparser.y"
    {printf(": statement_list->statement\n");;}
    break;

  case 190:

/* Line 1455 of yacc.c  */
#line 384 "par/cparser.y"
    {printf(": statement_list->statement_list statement\n");;}
    break;

  case 191:

/* Line 1455 of yacc.c  */
#line 388 "par/cparser.y"
    {printf(": expression_statement->;\n");;}
    break;

  case 192:

/* Line 1455 of yacc.c  */
#line 389 "par/cparser.y"
    {printf(": expression_statement->expression ;\n");;}
    break;

  case 193:

/* Line 1455 of yacc.c  */
#line 393 "par/cparser.y"
    {printf(": selection_statement->IF ( expression ) statement\n");;}
    break;

  case 194:

/* Line 1455 of yacc.c  */
#line 394 "par/cparser.y"
    {printf(": selection_statement->IF ( expression ) statement ELSE statement\n");;}
    break;

  case 195:

/* Line 1455 of yacc.c  */
#line 395 "par/cparser.y"
    {printf(": selection_statement->SWITCH ( expression ) statement\n");;}
    break;

  case 196:

/* Line 1455 of yacc.c  */
#line 399 "par/cparser.y"
    {printf(": iteration_statement->WHILE ( expression ) statement\n");;}
    break;

  case 197:

/* Line 1455 of yacc.c  */
#line 400 "par/cparser.y"
    {printf(": iteration_statement->DO statement WHILE ( expression ) ;\n");;}
    break;

  case 198:

/* Line 1455 of yacc.c  */
#line 401 "par/cparser.y"
    {printf(": iteration_statement->FOR ( expression_statement expression_statement ) statement\n");;}
    break;

  case 199:

/* Line 1455 of yacc.c  */
#line 402 "par/cparser.y"
    {printf(": iteration_statement->FOR ( expression_statement expression_statement expression ) statement\n");;}
    break;

  case 200:

/* Line 1455 of yacc.c  */
#line 406 "par/cparser.y"
    {printf(": jump_statement->GOTO IDENTIFIER ;\n");;}
    break;

  case 201:

/* Line 1455 of yacc.c  */
#line 407 "par/cparser.y"
    {printf(": jump_statement->CONTINUE ;\n");;}
    break;

  case 202:

/* Line 1455 of yacc.c  */
#line 408 "par/cparser.y"
    {printf(": jump_statement->BREAK ;\n");;}
    break;

  case 203:

/* Line 1455 of yacc.c  */
#line 409 "par/cparser.y"
    {printf(": jump_statement->RETURN ;\n");;}
    break;

  case 204:

/* Line 1455 of yacc.c  */
#line 410 "par/cparser.y"
    {printf(": jump_statement->RETURN expression ;\n");;}
    break;

  case 205:

/* Line 1455 of yacc.c  */
#line 414 "par/cparser.y"
    {printf(": translation_unit->external_declaration\n");;}
    break;

  case 206:

/* Line 1455 of yacc.c  */
#line 415 "par/cparser.y"
    {printf(": translation_unit->translation_unit external_declaration\n");;}
    break;

  case 207:

/* Line 1455 of yacc.c  */
#line 419 "par/cparser.y"
    {printf(": external_declaration->function_definition\n");;}
    break;

  case 208:

/* Line 1455 of yacc.c  */
#line 420 "par/cparser.y"
    {printf(": external_declaration->declaration\n");;}
    break;

  case 209:

/* Line 1455 of yacc.c  */
#line 424 "par/cparser.y"
    {printf(": function_definition->declaration_specifiers declarator declaration_list compound_statement\n");;}
    break;

  case 210:

/* Line 1455 of yacc.c  */
#line 425 "par/cparser.y"
    {printf(": function_definition->declaration_specifiers declarator compound_statement\n");;}
    break;

  case 211:

/* Line 1455 of yacc.c  */
#line 426 "par/cparser.y"
    {printf(": function_definition->declarator declaration_list compound_statement\n");;}
    break;

  case 212:

/* Line 1455 of yacc.c  */
#line 427 "par/cparser.y"
    {printf(": function_definition->declarator compound_statement\n");;}
    break;



/* Line 1455 of yacc.c  */
#line 3409 "cparser.tab.c"
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

#if !defined(yyoverflow) || YYERROR_VERBOSE
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



/* Line 1675 of yacc.c  */
#line 429 "par/cparser.y"


