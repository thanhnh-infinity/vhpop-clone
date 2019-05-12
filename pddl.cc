/* A Bison parser, made by GNU Bison 1.875b.  */

/* Skeleton parser for Yacc-like parsing with Bison,
   Copyright (C) 1984, 1989, 1990, 2000, 2001, 2002, 2003 Free Software Foundation, Inc.

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
   Foundation, Inc., 59 Temple Place - Suite 330,
   Boston, MA 02111-1307, USA.  */

/* As a special exception, when this file is copied by Bison into a
   Bison output file, you may use that output file without restriction.
   This special exception was added by the Free Software Foundation
   in version 1.24 of Bison.  */

/* Written by Richard Stallman by simplifying the original so called
   ``semantic'' parser.  */

/* All symbols defined below should begin with yy or YY, to avoid
   infringing on user name space.  This should be done even for local
   variables, as they might otherwise be expanded by user macros.
   There are some unavoidable exceptions within include files to
   define necessary library symbols; they are noted "INFRINGES ON
   USER NAME SPACE" below.  */

/* Identify Bison output.  */
#define YYBISON 1

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Using locations.  */
#define YYLSP_NEEDED 0



/* Tokens.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
   /* Put the tokens into the symbol table, so that GDB and other debuggers
      know about them.  */
   enum yytokentype {
     DEFINE = 258,
     DOMAIN_TOKEN = 259,
     PROBLEM = 260,
     REQUIREMENTS = 261,
     STRIPS = 262,
     TYPING = 263,
     NEGATIVE_PRECONDITIONS = 264,
     DISJUNCTIVE_PRECONDITIONS = 265,
     EQUALITY = 266,
     EXISTENTIAL_PRECONDITIONS = 267,
     UNIVERSAL_PRECONDITIONS = 268,
     QUANTIFIED_PRECONDITIONS = 269,
     CONDITIONAL_EFFECTS = 270,
     FLUENTS = 271,
     ADL = 272,
     DURATIVE_ACTIONS = 273,
     DURATION_INEQUALITIES = 274,
     CONTINUOUS_EFFECTS = 275,
     TYPES = 276,
     CONSTANTS = 277,
     PREDICATES = 278,
     ACTION = 279,
     DURATIVE_ACTION = 280,
     DURATION = 281,
     PARAMETERS = 282,
     PRECONDITION = 283,
     CONDITION = 284,
     EFFECT = 285,
     PDOMAIN = 286,
     OBJECTS = 287,
     INIT = 288,
     GOAL = 289,
     METRIC = 290,
     WHEN = 291,
     NOT = 292,
     AND = 293,
     OR = 294,
     IMPLY = 295,
     EXISTS = 296,
     FORALL = 297,
     OBJECT_TOKEN = 298,
     EITHER = 299,
     AT = 300,
     OVER = 301,
     START = 302,
     END = 303,
     ALL = 304,
     MINIMIZE = 305,
     MAXIMIZE = 306,
     TOTAL_TIME = 307,
     LE = 308,
     GE = 309,
     NAME = 310,
     DURATION_VAR = 311,
     VARIABLE = 312,
     NUMBER = 313,
     ILLEGAL_TOKEN = 314,
     AVOID_LINKS = 315
   };
#endif
#define DEFINE 258
#define DOMAIN_TOKEN 259
#define PROBLEM 260
#define REQUIREMENTS 261
#define STRIPS 262
#define TYPING 263
#define NEGATIVE_PRECONDITIONS 264
#define DISJUNCTIVE_PRECONDITIONS 265
#define EQUALITY 266
#define EXISTENTIAL_PRECONDITIONS 267
#define UNIVERSAL_PRECONDITIONS 268
#define QUANTIFIED_PRECONDITIONS 269
#define CONDITIONAL_EFFECTS 270
#define FLUENTS 271
#define ADL 272
#define DURATIVE_ACTIONS 273
#define DURATION_INEQUALITIES 274
#define CONTINUOUS_EFFECTS 275
#define TYPES 276
#define CONSTANTS 277
#define PREDICATES 278
#define ACTION 279
#define DURATIVE_ACTION 280
#define DURATION 281
#define PARAMETERS 282
#define PRECONDITION 283
#define CONDITION 284
#define EFFECT 285
#define PDOMAIN 286
#define OBJECTS 287
#define INIT 288
#define GOAL 289
#define METRIC 290
#define WHEN 291
#define NOT 292
#define AND 293
#define OR 294
#define IMPLY 295
#define EXISTS 296
#define FORALL 297
#define OBJECT_TOKEN 298
#define EITHER 299
#define AT 300
#define OVER 301
#define START 302
#define END 303
#define ALL 304
#define MINIMIZE 305
#define MAXIMIZE 306
#define TOTAL_TIME 307
#define LE 308
#define GE 309
#define NAME 310
#define DURATION_VAR 311
#define VARIABLE 312
#define NUMBER 313
#define ILLEGAL_TOKEN 314
#define AVOID_LINKS 315




/* Copy the first part of user declarations.  */
#line 26 "pddl.yy"

#include "requirements.h"
#include "problems.h"
#include "domains.h"
#include "formulas.h"
#include "types.h"
#include "exceptions.h"
#include "mathport.h"
#include <typeinfo>
#include <utility>
#include <cstdlib>
#include <iostream>


/* Workaround for bug in Bison 1.35 that disables stack growth. */
#define YYLTYPE_IS_TRIVIAL 1

/* The lexer. */
extern int yylex();
/* Current line number. */
extern size_t line_number;


/*
 * Context of free variables.
 */
struct Context {
  void push_frame() {
    frames_.push_back(VariableMap());
  }

  void pop_frame() {
    frames_.pop_back();
  }

  void insert(const Variable* v) {
    frames_.back()[v->name()] = v;
  }

  const Variable* shallow_find(const std::string& name) const {
    VariableMap::const_iterator vi = frames_.back().find(name);
    return (vi != frames_.back().end()) ? (*vi).second : NULL;
  }

  const Variable* find(const std::string& name) const {
    for (std::vector<VariableMap>::const_reverse_iterator fi =
	   frames_.rbegin(); fi != frames_.rend(); fi++) {
      VariableMap::const_iterator vi = (*fi).find(name);
      if (vi != (*fi).end()) {
	return (*vi).second;
      }
    }
    return NULL;
  }

private:
  struct VariableMap : public std::map<std::string, const Variable*> {
  };

  std::vector<VariableMap> frames_;
};


/* Name of current file. */
std::string current_file; 
/* Level of warnings. */
int warning_level;

bool parsing_av_list = false;

/* Whether the last parsing attempt succeeded. */
static bool success = true;
/* Domain being parsed, or NULL if no domain is being parsed. */
static Domain* domain;
/* Problem being parsed, or NULL if no problem is being parsed. */
static Problem* problem;
/* Domain of problem being parsed, or NULL if no problem is being parsed. */
static const Domain* pdomain;
/* Current requirements. */
static Requirements* requirements;
/* Predicate being parsed, or NULL if no predicate is being parsed. */
static Predicate* predicate;
/* Action being parsed, or NULL if no action is being parsed. */
static ActionSchema* action;
/* Effect being parsed, or NULL if no effect is being parsed. */
static Effect* effect;
/* Condition for effect being parsed, or NULL if unconditional effect. */
static const Formula* effect_condition;
/* Quantified variables for effect or formula being parsed. */
VariableList quantified;
/* Atom being parsed, or NULL if no atom is being parsed. */
static Atom* atom;
/* Time stap of current formula. */
static Formula::FormulaTime formula_time;
/* Current variable context. */
static Context context;
/* Kind of name map being parsed. */
static enum { TYPE_MAP, CONSTANT_MAP, OBJECT_MAP, NOTHING } name_map_kind;

/* Outputs an error message. */
static void yyerror(const std::string& s); 
/* Outputs a warning message. */
static void yywarning(const std::string& s);
/* Returns the simple type with the given name, or NULL if undefined. */
static const SimpleType* find_type(const std::string& name);
/* Returns the constant with the given name, or NULL if undefined. */
static const Name* find_constant(const std::string& name);
/* Returns the predicate with the given name, or NULL if undefined. */
static const Predicate* find_predicate(const std::string& name);
/* Creates an empty domain with the given name. */
static void make_domain(const std::string* name);
/* Creates an empty problem with the given name. */
static void make_problem(const std::string* name,
			 const std::string* domain_name);
/* Adds :typing to the requirements. */
static void require_typing();
/* Adds :duration-inequalities to the requirements. */
static void require_duration_inequalities();
/* Returns a simple type with the given name. */
static const SimpleType& make_type(const std::string* name);
/* Returns a simple term with the given name. */
static const Term& make_term(const std::string* name);
/* Creates a predicate with the given name. */
static void make_predicate(const std::string* name);
/* Creates an action with the given name. */
static void make_action(const std::string* name, bool durative);
/* Prepares for the parsing of a universally quantified effect. */ 
static void prepare_forall_effect();
/* Prepares for the parsing of a conditional effect. */ 
static void prepare_conditional_effect(const Formula* condition);
/* Creates an equality formula. */
static const Formula* make_equality(const Term& t1, const Term& t2);
/* Creates a negation. */
static const Formula* make_negation(const Formula& f);
/* Prepares for the parsing of a disjunction. */
static void prepare_disjunction();
/* Prepares for the parsing of an existentially quantified formula. */
static void prepare_exists();
/* Prepares for the parsing of a universally quantified formula. */
static void prepare_forall();
/* Creates an existentially quantified formula. */
static const Formula* make_exists(const Formula& body);
/* Creates a universally quantified formula. */
static const Formula* make_forall(const Formula& body);
/* Adds types, constants, or objects to the current domain or problem. */
static void add_names(const std::vector<std::string>* names, const Type& type);
/* Adds variables to the current variable list. */
static void add_variables(const std::vector<std::string>* names,
			  const Type& type);
/* Adds the current predicate to the current domain. */
static void add_predicate();
/* Adds the current action to the current domain. */ 
static void add_action();
/* Adds the given atom to the add list of the current effect. */
static void add_positive(const Atom& atom);
/* Adds the given atom to the delete list of the current effect. */
static void add_negative(const Atom& atom);
/* Adds the current effect to the currect action. */
static void add_effect();
/* Adds the current universally quantified effect to the currect action. */
static void add_forall_effect();
/* Adds the current conditional effect to the currect action. */
static void add_conditional_effect();
/* Prepares for the parsning of an atomic formula. */ 
static void prepare_atom(const std::string* name);
/* Adds a term with the given name to the current atomic formula. */
static void add_term(const std::string* name);
/* Creates the atomic formula just parsed. */
static const Atom* make_atom();

static void add_link_to_avoid(const std::string* name1, const Formula& cond, const std::string* name2);


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

#if ! defined (YYSTYPE) && ! defined (YYSTYPE_IS_DECLARED)
#line 216 "pddl.yy"
typedef union YYSTYPE {
  const Formula* formula;
  const Atom* atom;
  const std::string* str;
  std::vector<std::string>* strs;
  const Term* term;
  const Type* type;
  UnionType* types;
  float num;
} YYSTYPE;
/* Line 191 of yacc.c.  */
#line 380 "pddl.cc"
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
# define YYSTYPE_IS_TRIVIAL 1
#endif



/* Copy the second part of user declarations.  */


/* Line 214 of yacc.c.  */
#line 392 "pddl.cc"

#if ! defined (yyoverflow) || YYERROR_VERBOSE

/* The parser invokes alloca or malloc; define the necessary symbols.  */

# if YYSTACK_USE_ALLOCA
#  define YYSTACK_ALLOC alloca
# else
#  ifndef YYSTACK_USE_ALLOCA
#   if defined (alloca) || defined (_ALLOCA_H)
#    define YYSTACK_ALLOC alloca
#   else
#    ifdef __GNUC__
#     define YYSTACK_ALLOC __builtin_alloca
#    endif
#   endif
#  endif
# endif

# ifdef YYSTACK_ALLOC
   /* Pacify GCC's `empty if-body' warning. */
#  define YYSTACK_FREE(Ptr) do { /* empty */; } while (0)
# else
#  if defined (__STDC__) || defined (__cplusplus)
#   include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#   define YYSIZE_T size_t
#  endif
#  define YYSTACK_ALLOC malloc
#  define YYSTACK_FREE free
# endif
#endif /* ! defined (yyoverflow) || YYERROR_VERBOSE */


#if (! defined (yyoverflow) \
     && (! defined (__cplusplus) \
	 || (YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  short yyss;
  YYSTYPE yyvs;
  };

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (sizeof (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (sizeof (short) + sizeof (YYSTYPE))				\
      + YYSTACK_GAP_MAXIMUM)

/* Copy COUNT objects from FROM to TO.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if 1 < __GNUC__
#   define YYCOPY(To, From, Count) \
      __builtin_memcpy (To, From, (Count) * sizeof (*(From)))
#  else
#   define YYCOPY(To, From, Count)		\
      do					\
	{					\
	  register YYSIZE_T yyi;		\
	  for (yyi = 0; yyi < (Count); yyi++)	\
	    (To)[yyi] = (From)[yyi];		\
	}					\
      while (0)
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
    while (0)

#endif

#if defined (__STDC__) || defined (__cplusplus)
   typedef signed char yysigned_char;
#else
   typedef short yysigned_char;
#endif

/* YYFINAL -- State number of the termination state. */
#define YYFINAL  3
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   560

/* YYNTOKENS -- Number of terminals. */
#define YYNTOKENS  68
/* YYNNTS -- Number of nonterminals. */
#define YYNNTS  123
/* YYNRULES -- Number of rules. */
#define YYNRULES  243
/* YYNRULES -- Number of states. */
#define YYNSTATES  404

/* YYTRANSLATE(YYLEX) -- Bison symbol number corresponding to YYLEX.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   315

#define YYTRANSLATE(YYX) 						\
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[YYLEX] -- Bison symbol number corresponding to YYLEX.  */
static const unsigned char yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
      61,    62,    66,    64,     2,    65,     2,    67,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,    63,     2,     2,     2,     2,     2,     2,     2,     2,
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
static const unsigned short yyprhs[] =
{
       0,     0,     3,     4,     7,     8,    11,    14,    15,    25,
      26,    28,    31,    33,    35,    38,    40,    43,    47,    49,
      51,    54,    56,    58,    61,    63,    65,    68,    73,    75,
      78,    80,    82,    84,    86,    88,    90,    92,    94,    96,
      98,   100,   102,   104,   106,   107,   113,   114,   120,   125,
     127,   130,   131,   137,   138,   149,   150,   163,   166,   168,
     169,   171,   172,   176,   179,   183,   185,   186,   189,   191,
     196,   202,   208,   214,   215,   218,   220,   225,   226,   229,
     230,   237,   238,   245,   246,   253,   255,   260,   261,   270,
     271,   272,   280,   281,   284,   286,   291,   293,   298,   299,
     302,   304,   309,   310,   319,   320,   327,   328,   331,   332,
     339,   340,   347,   348,   362,   365,   367,   370,   372,   375,
     377,   379,   380,   387,   388,   394,   399,   401,   404,   406,
     411,   412,   418,   419,   422,   424,   425,   431,   433,   436,
     442,   444,   449,   451,   457,   462,   467,   468,   474,   475,
     482,   483,   492,   493,   502,   503,   506,   507,   510,   511,
     517,   518,   521,   524,   526,   528,   529,   531,   533,   534,
     539,   540,   542,   544,   547,   549,   550,   555,   556,   558,
     560,   563,   566,   568,   570,   575,   577,   579,   582,   585,
     587,   589,   591,   593,   595,   597,   599,   601,   603,   605,
     607,   609,   611,   613,   615,   617,   619,   621,   623,   625,
     627,   629,   631,   633,   635,   637,   639,   641,   643,   645,
     647,   649,   651,   653,   655,   657,   659,   661,   663,   665,
     667,   669,   671,   673,   675,   677,   679,   681,   683,   685,
     687,   689,   691,   693
};

/* YYRHS -- A `-1'-separated list of the rules' RHS. */
static const short yyrhs[] =
{
      69,     0,    -1,    -1,    70,    71,    -1,    -1,    71,    72,
      -1,    71,   125,    -1,    -1,    61,   169,    61,   170,   189,
      62,    73,    74,    62,    -1,    -1,    80,    -1,    80,    75,
      -1,    75,    -1,    83,    -1,    83,    76,    -1,    76,    -1,
      87,    85,    -1,    87,    85,    79,    -1,    77,    -1,    85,
      -1,    85,    78,    -1,    78,    -1,    87,    -1,    87,    79,
      -1,    79,    -1,    91,    -1,    79,    91,    -1,    61,     6,
      81,    62,    -1,    82,    -1,    81,    82,    -1,     7,    -1,
       8,    -1,     9,    -1,    10,    -1,    11,    -1,    12,    -1,
      13,    -1,    14,    -1,    15,    -1,    16,    -1,    17,    -1,
      18,    -1,    19,    -1,    20,    -1,    -1,    61,    21,    84,
     157,    62,    -1,    -1,    61,    22,    86,   157,    62,    -1,
      61,    23,    88,    62,    -1,    89,    -1,    88,    89,    -1,
      -1,    61,   188,    90,   160,    62,    -1,    -1,    61,    24,
     189,    92,    27,    61,   160,    62,    94,    62,    -1,    -1,
      61,    25,   189,    93,    27,    61,   160,    62,    26,   101,
      99,    62,    -1,    96,    95,    -1,    95,    -1,    -1,    98,
      -1,    -1,    28,    97,   146,    -1,    30,   110,    -1,    29,
     104,   100,    -1,   100,    -1,    -1,    30,   118,    -1,   102,
      -1,    61,   174,   103,    62,    -1,    61,    53,   186,    58,
      62,    -1,    61,    54,   186,    58,    62,    -1,    61,    63,
     186,    58,    62,    -1,    -1,   103,   102,    -1,   106,    -1,
      61,   174,   105,    62,    -1,    -1,   105,   106,    -1,    -1,
      61,   181,   183,   107,   146,    62,    -1,    -1,    61,   181,
     184,   108,   146,    62,    -1,    -1,    61,   182,   185,   109,
     146,    62,    -1,   116,    -1,    61,   174,   114,    62,    -1,
      -1,    61,   178,   111,    61,   160,    62,   110,    62,    -1,
      -1,    -1,    61,   172,   112,   146,   113,   115,    62,    -1,
      -1,   114,   110,    -1,   116,    -1,    61,   174,   117,    62,
      -1,   153,    -1,    61,   173,   153,    62,    -1,    -1,   117,
     116,    -1,   122,    -1,    61,   174,   121,    62,    -1,    -1,
      61,   178,   119,    61,   160,    62,   118,    62,    -1,    -1,
      61,   172,   104,   120,   122,    62,    -1,    -1,   121,   118,
      -1,    -1,    61,   181,   183,   123,   115,    62,    -1,    -1,
      61,   181,   184,   124,   115,    62,    -1,    -1,    61,   169,
      61,   171,   189,    62,    61,    31,   189,    62,   126,   127,
      62,    -1,    80,   128,    -1,   128,    -1,   132,   129,    -1,
     129,    -1,   134,   130,    -1,   130,    -1,   140,    -1,    -1,
     140,   131,    61,    60,   143,    62,    -1,    -1,    61,    32,
     133,   157,    62,    -1,    61,    33,   135,    62,    -1,   136,
      -1,   135,   136,    -1,   137,    -1,    61,   173,   137,    62,
      -1,    -1,    61,   188,   138,   139,    62,    -1,    -1,   139,
     189,    -1,   141,    -1,    -1,    61,    34,   142,   146,    62,
      -1,   144,    -1,   143,   144,    -1,    61,   189,   145,   189,
      62,    -1,   153,    -1,    61,   173,   153,    62,    -1,   153,
      -1,    61,    63,   156,   156,    62,    -1,    61,   173,   146,
      62,    -1,    61,   174,   151,    62,    -1,    -1,    61,   175,
     147,   152,    62,    -1,    -1,    61,   176,   148,   146,   146,
      62,    -1,    -1,    61,   177,   149,    61,   160,    62,   146,
      62,    -1,    -1,    61,   178,   150,    61,   160,    62,   146,
      62,    -1,    -1,   151,   146,    -1,    -1,   152,   146,    -1,
      -1,    61,   188,   154,   155,    62,    -1,    -1,   155,   189,
      -1,   155,   190,    -1,   189,    -1,   190,    -1,    -1,   162,
      -1,   161,    -1,    -1,   161,   166,   159,   160,    -1,    -1,
     158,    -1,   190,    -1,   161,   190,    -1,   165,    -1,    -1,
     165,   166,   163,   164,    -1,    -1,   162,    -1,   189,    -1,
     165,   189,    -1,    65,   167,    -1,   179,    -1,   187,    -1,
      61,   180,   168,    62,    -1,   179,    -1,   187,    -1,   168,
     179,    -1,   168,   187,    -1,     3,    -1,     4,    -1,     5,
      -1,    36,    -1,    37,    -1,    38,    -1,    39,    -1,    40,
      -1,    41,    -1,    42,    -1,    43,    -1,    44,    -1,    45,
      -1,    46,    -1,    47,    -1,    48,    -1,    49,    -1,    56,
      -1,     3,    -1,     4,    -1,     5,    -1,    44,    -1,    45,
      -1,    46,    -1,    47,    -1,    48,    -1,    49,    -1,    50,
      -1,    51,    -1,    52,    -1,    55,    -1,   187,    -1,    43,
      -1,     3,    -1,     4,    -1,     5,    -1,    43,    -1,    44,
      -1,    36,    -1,    37,    -1,    38,    -1,    39,    -1,    40,
      -1,    41,    -1,    42,    -1,    45,    -1,    46,    -1,    47,
      -1,    48,    -1,    49,    -1,    50,    -1,    51,    -1,    52,
      -1,    55,    -1,    57,    -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const unsigned short yyrline[] =
{
       0,   246,   246,   246,   250,   251,   252,   260,   260,   264,
     265,   266,   267,   270,   271,   272,   275,   276,   277,   280,
     281,   282,   285,   286,   287,   290,   291,   294,   297,   298,
     301,   302,   303,   305,   307,   308,   310,   312,   314,   315,
     316,   317,   318,   320,   324,   324,   328,   328,   332,   339,
     340,   343,   343,   351,   351,   354,   354,   359,   360,   363,
     364,   367,   367,   371,   374,   375,   378,   379,   386,   387,
     391,   396,   401,   405,   406,   414,   415,   418,   419,   422,
     422,   424,   424,   426,   426,   434,   435,   436,   436,   438,
     439,   438,   443,   444,   447,   448,   451,   452,   455,   456,
     459,   460,   461,   461,   463,   463,   467,   468,   471,   471,
     473,   473,   482,   481,   486,   487,   490,   491,   494,   495,
     498,   499,   499,   502,   502,   505,   508,   509,   512,   513,
     516,   516,   520,   521,   524,   528,   528,   556,   557,   561,
     565,   566,   575,   576,   577,   578,   579,   579,   580,   580,
     582,   582,   584,   584,   588,   589,   592,   593,   596,   596,
     604,   605,   606,   609,   610,   613,   614,   617,   618,   618,
     621,   622,   625,   627,   631,   632,   632,   635,   636,   639,
     640,   643,   646,   647,   648,   651,   652,   653,   654,   657,
     660,   663,   666,   669,   672,   675,   678,   681,   684,   687,
     690,   693,   696,   699,   702,   705,   708,   711,   711,   711,
     712,   713,   713,   713,   713,   713,   714,   714,   714,   715,
     718,   719,   725,   725,   725,   726,   726,   727,   727,   727,
     727,   727,   727,   727,   728,   728,   728,   728,   728,   729,
     729,   729,   730,   733
};
#endif

#if YYDEBUG || YYERROR_VERBOSE
/* YYTNME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals. */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "DEFINE", "DOMAIN_TOKEN", "PROBLEM", 
  "REQUIREMENTS", "STRIPS", "TYPING", "NEGATIVE_PRECONDITIONS", 
  "DISJUNCTIVE_PRECONDITIONS", "EQUALITY", "EXISTENTIAL_PRECONDITIONS", 
  "UNIVERSAL_PRECONDITIONS", "QUANTIFIED_PRECONDITIONS", 
  "CONDITIONAL_EFFECTS", "FLUENTS", "ADL", "DURATIVE_ACTIONS", 
  "DURATION_INEQUALITIES", "CONTINUOUS_EFFECTS", "TYPES", "CONSTANTS", 
  "PREDICATES", "ACTION", "DURATIVE_ACTION", "DURATION", "PARAMETERS", 
  "PRECONDITION", "CONDITION", "EFFECT", "PDOMAIN", "OBJECTS", "INIT", 
  "GOAL", "METRIC", "WHEN", "NOT", "AND", "OR", "IMPLY", "EXISTS", 
  "FORALL", "OBJECT_TOKEN", "EITHER", "AT", "OVER", "START", "END", "ALL", 
  "MINIMIZE", "MAXIMIZE", "TOTAL_TIME", "LE", "GE", "NAME", 
  "DURATION_VAR", "VARIABLE", "NUMBER", "ILLEGAL_TOKEN", "AVOID_LINKS", 
  "'('", "')'", "'='", "'+'", "'-'", "'*'", "'/'", "$accept", "pddl_file", 
  "@1", "domains_and_problems", "domain_def", "@2", "domain_body", 
  "domain_body2", "domain_body3", "domain_body4", "domain_body5", 
  "actions_def", "require_def", "require_keys", "require_key", 
  "types_def", "@3", "constants_def", "@4", "predicates_def", 
  "atomic_formula_skeletons", "atomic_formula_skeleton", "@5", 
  "action_def", "@6", "@7", "action_body", "action_body2", "precondition", 
  "@8", "effect", "da_body", "da_body2", "duration_constraint", 
  "simple_duration_constraint", "simple_duration_constraints", "da_gd", 
  "timed_gds", "timed_gd", "@9", "@10", "@11", "eff_formula", "@12", 
  "@13", "@14", "eff_formulas", "one_eff_formula", "term_literal", 
  "term_literals", "da_effect", "@15", "@16", "da_effects", 
  "timed_effect", "@17", "@18", "problem_def", "@19", "problem_body", 
  "problem_body2", "problem_body3", "problem_body4", "@20", "object_decl", 
  "@21", "init", "name_literals", "name_literal", "atomic_name_formula", 
  "@22", "names", "goal_spec", "goal", "@23", "links_to_avoid", 
  "link_to_avoid", "cl_literal", "formula", "@24", "@25", "@26", "@27", 
  "conjuncts", "disjuncts", "atomic_term_formula", "@28", "terms", "term", 
  "name_map", "variables", "@29", "opt_variables", "variable_seq", 
  "typed_names", "@30", "opt_typed_names", "name_seq", "type_spec", 
  "type", "types", "define", "domain", "problem", "when", "not", "and", 
  "or", "imply", "exists", "forall", "object", "either", "at", "over", 
  "start", "end", "all", "duration_var", "type_name", "predicate", "name", 
  "variable", 0
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[YYLEX-NUM] -- Internal token number corresponding to
   token YYLEX-NUM.  */
static const unsigned short yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
     285,   286,   287,   288,   289,   290,   291,   292,   293,   294,
     295,   296,   297,   298,   299,   300,   301,   302,   303,   304,
     305,   306,   307,   308,   309,   310,   311,   312,   313,   314,
     315,    40,    41,    61,    43,    45,    42,    47
};
# endif

/* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const unsigned char yyr1[] =
{
       0,    68,    70,    69,    71,    71,    71,    73,    72,    74,
      74,    74,    74,    75,    75,    75,    76,    76,    76,    77,
      77,    77,    78,    78,    78,    79,    79,    80,    81,    81,
      82,    82,    82,    82,    82,    82,    82,    82,    82,    82,
      82,    82,    82,    82,    84,    83,    86,    85,    87,    88,
      88,    90,    89,    92,    91,    93,    91,    94,    94,    95,
      95,    97,    96,    98,    99,    99,   100,   100,   101,   101,
     102,   102,   102,   103,   103,   104,   104,   105,   105,   107,
     106,   108,   106,   109,   106,   110,   110,   111,   110,   112,
     113,   110,   114,   114,   115,   115,   116,   116,   117,   117,
     118,   118,   119,   118,   120,   118,   121,   121,   123,   122,
     124,   122,   126,   125,   127,   127,   128,   128,   129,   129,
     130,   131,   130,   133,   132,   134,   135,   135,   136,   136,
     138,   137,   139,   139,   140,   142,   141,   143,   143,   144,
     145,   145,   146,   146,   146,   146,   147,   146,   148,   146,
     149,   146,   150,   146,   151,   151,   152,   152,   154,   153,
     155,   155,   155,   156,   156,   157,   157,   158,   159,   158,
     160,   160,   161,   161,   162,   163,   162,   164,   164,   165,
     165,   166,   167,   167,   167,   168,   168,   168,   168,   169,
     170,   171,   172,   173,   174,   175,   176,   177,   178,   179,
     180,   181,   182,   183,   184,   185,   186,   187,   187,   187,
     187,   187,   187,   187,   187,   187,   187,   187,   187,   187,
     188,   188,   189,   189,   189,   189,   189,   189,   189,   189,
     189,   189,   189,   189,   189,   189,   189,   189,   189,   189,
     189,   189,   189,   190
};

/* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
static const unsigned char yyr2[] =
{
       0,     2,     0,     2,     0,     2,     2,     0,     9,     0,
       1,     2,     1,     1,     2,     1,     2,     3,     1,     1,
       2,     1,     1,     2,     1,     1,     2,     4,     1,     2,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     0,     5,     0,     5,     4,     1,
       2,     0,     5,     0,    10,     0,    12,     2,     1,     0,
       1,     0,     3,     2,     3,     1,     0,     2,     1,     4,
       5,     5,     5,     0,     2,     1,     4,     0,     2,     0,
       6,     0,     6,     0,     6,     1,     4,     0,     8,     0,
       0,     7,     0,     2,     1,     4,     1,     4,     0,     2,
       1,     4,     0,     8,     0,     6,     0,     2,     0,     6,
       0,     6,     0,    13,     2,     1,     2,     1,     2,     1,
       1,     0,     6,     0,     5,     4,     1,     2,     1,     4,
       0,     5,     0,     2,     1,     0,     5,     1,     2,     5,
       1,     4,     1,     5,     4,     4,     0,     5,     0,     6,
       0,     8,     0,     8,     0,     2,     0,     2,     0,     5,
       0,     2,     2,     1,     1,     0,     1,     1,     0,     4,
       0,     1,     1,     2,     1,     0,     4,     0,     1,     1,
       2,     2,     1,     1,     4,     1,     1,     2,     2,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1
};

/* YYDEFACT[STATE-NAME] -- Default rule to reduce with in state
   STATE-NUM when YYTABLE doesn't specify something else to do.  Zero
   means the default is an error.  */
static const unsigned char yydefact[] =
{
       2,     0,     4,     1,     3,     0,     5,     6,   189,     0,
       0,   190,   191,     0,     0,   222,   223,   224,   227,   228,
     229,   230,   231,   232,   233,   225,   226,   234,   235,   236,
     237,   238,   239,   240,   241,   242,     0,     0,     7,     0,
       9,     0,     0,     0,    12,    15,    18,    21,    24,    10,
      13,    19,    22,    25,     0,     0,    44,    46,     0,     0,
       0,     8,     0,    26,     0,    11,     0,    14,     0,    20,
      22,     0,    23,    16,     0,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    39,    40,    41,    42,    43,     0,
      28,   165,   165,     0,     0,    49,    53,    55,    17,   112,
      27,    29,     0,   166,   174,   179,     0,   207,   208,   209,
     221,   210,   211,   212,   213,   214,   215,   216,   217,   218,
     219,   220,    51,    48,    50,     0,     0,     0,    45,     0,
     175,   180,    47,   170,     0,     0,     0,     0,     0,   115,
     117,   119,     0,     0,   120,   134,   199,     0,   181,   182,
     183,   177,   243,   171,     0,   167,   172,   170,   170,   123,
       0,   135,     0,   114,   113,     0,   116,     0,   118,     0,
     200,     0,   178,   176,    52,   168,   173,     0,     0,   165,
       0,     0,   126,   128,     0,     0,     0,   185,   186,   170,
      59,     0,     0,   193,     0,   130,   125,   127,     0,     0,
     142,     0,   184,   187,   188,   169,    61,     0,     0,    58,
      59,    60,     0,   124,     0,     0,   132,   194,   195,   196,
     197,   198,     0,     0,   154,   146,   148,   150,   152,   158,
     136,     0,     0,   137,     0,     0,    63,    85,    96,    54,
      57,     0,    66,    68,   129,     0,     0,   163,   164,     0,
       0,   156,     0,     0,     0,   160,     0,   122,   138,    62,
     192,    89,     0,    92,    87,     0,     0,     0,    73,     0,
       0,     0,    65,   131,   133,     0,   144,   145,   155,     0,
       0,   170,   170,     0,     0,     0,   140,     0,     0,     0,
       0,     0,   206,     0,     0,     0,     0,     0,    66,    75,
       0,    67,   100,    56,   143,   147,   157,     0,     0,     0,
     159,   161,   162,     0,     0,    90,    97,    86,    93,   170,
       0,     0,     0,     0,    69,    74,   201,   202,    77,     0,
       0,    64,     0,   106,   102,     0,   149,     0,     0,     0,
     139,     0,     0,    70,    71,    72,     0,   203,   204,    79,
      81,   205,    83,   104,     0,     0,   108,   110,     0,     0,
     141,     0,     0,    94,     0,     0,    76,    78,     0,     0,
       0,     0,   101,   107,   170,     0,     0,   151,   153,    98,
      91,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    88,    80,    82,    84,   105,     0,   109,   111,     0,
      95,    99,     0,   103
};

/* YYDEFGOTO[NTERM-NUM]. */
static const short yydefgoto[] =
{
      -1,     1,     2,     4,     6,    40,    43,    44,    45,    46,
      47,    48,    49,    89,    90,    50,    91,    51,    92,    52,
      94,    95,   133,    53,   125,   126,   208,   209,   210,   234,
     211,   271,   272,   242,   243,   296,   298,   346,   299,   368,
     369,   370,   236,   291,   287,   341,   290,   362,   237,   390,
     301,   355,   371,   354,   302,   375,   376,     7,   127,   138,
     139,   140,   141,   169,   142,   179,   143,   181,   182,   183,
     216,   245,   144,   145,   184,   232,   233,   285,   199,   251,
     252,   253,   254,   250,   279,   200,   255,   283,   246,   102,
     153,   189,   154,   155,   103,   151,   173,   104,   130,   148,
     186,     9,    13,    14,   261,   262,   224,   225,   226,   227,
     228,   149,   171,   329,   330,   349,   350,   352,   293,   121,
     229,   105,   156
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -337
static const short yypact[] =
{
    -337,    45,  -337,  -337,   -10,    58,  -337,  -337,  -337,    14,
      63,  -337,  -337,   399,   399,  -337,  -337,  -337,  -337,  -337,
    -337,  -337,  -337,  -337,  -337,  -337,  -337,  -337,  -337,  -337,
    -337,  -337,  -337,  -337,  -337,  -337,    31,    49,  -337,    73,
      93,   108,    59,    80,  -337,  -337,  -337,  -337,    99,   106,
     107,   109,   110,  -337,   399,   527,  -337,  -337,   113,   399,
     399,  -337,    65,  -337,    78,  -337,    82,  -337,     7,  -337,
      99,    54,    99,    99,   114,  -337,  -337,  -337,  -337,  -337,
    -337,  -337,  -337,  -337,  -337,  -337,  -337,  -337,  -337,   372,
    -337,   399,   399,   478,    47,  -337,  -337,  -337,    99,  -337,
    -337,  -337,   115,  -337,   152,  -337,   116,  -337,  -337,  -337,
    -337,  -337,  -337,  -337,  -337,  -337,  -337,  -337,  -337,  -337,
    -337,  -337,  -337,  -337,  -337,   142,   148,   118,  -337,   317,
    -337,  -337,  -337,   123,   120,   124,    16,   125,   143,  -337,
    -337,  -337,   145,   147,   149,  -337,  -337,   170,  -337,  -337,
    -337,   399,  -337,  -337,   153,   -21,  -337,   123,   123,  -337,
     159,  -337,    81,  -337,  -337,    83,  -337,   187,  -337,   174,
    -337,   505,  -337,  -337,  -337,  -337,  -337,   175,   176,   399,
     179,    57,  -337,  -337,   178,   183,   292,  -337,  -337,   123,
      -5,   210,   182,  -337,   200,  -337,  -337,  -337,   208,   202,
    -337,   201,  -337,  -337,  -337,  -337,  -337,   204,   228,  -337,
     236,  -337,   230,  -337,   478,   231,  -337,  -337,  -337,  -337,
    -337,  -337,   370,   178,  -337,  -337,  -337,  -337,  -337,  -337,
    -337,   399,    61,  -337,   178,   425,  -337,  -337,  -337,  -337,
    -337,   -11,    95,  -337,  -337,   264,   370,  -337,  -337,   255,
      68,  -337,   178,   257,   262,  -337,   263,  -337,  -337,  -337,
    -337,  -337,   266,  -337,  -337,   242,   242,   242,  -337,   267,
     268,   269,  -337,  -337,  -337,   270,  -337,  -337,  -337,    70,
     178,   123,   123,   237,   179,   399,  -337,   178,   478,   271,
      75,   273,  -337,   272,   287,   288,    79,   -17,   295,  -337,
      50,  -337,  -337,  -337,  -337,  -337,  -337,   286,   289,   290,
    -337,  -337,  -337,   266,   291,  -337,  -337,  -337,  -337,   123,
     293,   294,   296,     3,  -337,  -337,  -337,  -337,  -337,    96,
     300,  -337,   267,  -337,  -337,    96,  -337,   178,   178,   297,
    -337,   309,   314,  -337,  -337,  -337,    84,  -337,  -337,  -337,
    -337,  -337,  -337,  -337,    86,   310,  -337,  -337,   315,   331,
    -337,   452,   332,  -337,   204,   104,  -337,  -337,   178,   178,
     178,   334,  -337,  -337,   123,   309,   309,  -337,  -337,  -337,
    -337,   335,   336,   337,   338,   305,   339,   343,   361,   362,
      97,  -337,  -337,  -337,  -337,  -337,   268,  -337,  -337,   179,
    -337,  -337,   364,  -337
};

/* YYPGOTO[NTERM-NUM].  */
static const short yypgoto[] =
{
    -337,  -337,  -337,  -337,  -337,  -337,  -337,   308,   346,  -337,
     380,   -33,   306,  -337,   363,  -337,  -337,   401,  -337,   381,
    -337,   365,  -337,   -34,  -337,  -337,  -337,   248,  -337,  -337,
    -337,  -337,   162,  -337,   168,  -337,   133,  -337,   132,  -337,
    -337,  -337,  -279,  -337,  -337,  -337,  -337,  -213,  -321,  -337,
    -336,  -337,  -337,  -337,   117,  -337,  -337,  -337,  -337,  -337,
     329,   342,   344,  -337,  -337,  -337,  -337,  -337,   298,   299,
    -337,  -337,  -337,  -337,  -337,  -337,   253,  -337,  -217,  -337,
    -337,  -337,  -337,  -337,  -337,  -203,  -337,  -337,   240,   -82,
    -337,  -337,  -155,  -337,   340,  -337,  -337,  -337,   350,  -337,
    -337,  -337,  -337,  -337,   192,  -172,  -226,  -337,  -337,  -337,
    -223,  -147,  -337,  -287,  -337,   171,   177,  -337,  -101,  -113,
     -86,   -13,  -150
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If zero, do what YYDEFACT says.
   If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -122
static const short yytable[] =
{
      36,    37,   177,   178,   238,   176,   249,   122,   194,   263,
     106,   318,   264,   335,    63,   268,   150,   259,   373,    72,
     363,   217,    55,   206,   187,   207,   223,   217,   326,   327,
      58,    59,    60,   278,   205,   280,   152,    72,    63,   203,
      98,    74,   265,   266,   129,     3,    96,    97,   159,   160,
     161,     5,   267,   286,   363,   363,   265,   266,   188,   289,
     402,     8,   306,   307,    63,    55,   267,    11,    12,   401,
     315,   328,   248,   204,   333,    10,    57,   334,    59,    60,
      56,    57,    58,    59,    60,   381,   260,   238,   217,    59,
      60,   131,   221,    38,   195,   326,   248,   192,   335,    56,
      57,    58,    59,    60,    57,    58,    59,    60,    93,   123,
     339,    39,   313,   159,   160,   161,   160,   161,   180,   196,
     358,   359,   231,   257,   269,   270,   308,   309,   195,   198,
     277,   198,   305,   312,    41,   379,   235,   317,   238,    54,
     323,   324,    61,   347,   348,   365,   366,   300,   372,   326,
     327,   382,   383,   384,    42,    15,    16,    17,   399,   400,
      62,   238,   388,   389,   342,   294,   295,    64,    66,   134,
      68,    71,   238,   238,    93,   135,    99,   128,   132,   136,
     152,   157,   107,   108,   109,   158,   162,   238,    18,    19,
      20,    21,    22,    23,    24,    25,    26,    27,    28,    29,
      30,    31,    32,    33,    34,   164,   165,    35,   167,   247,
    -121,   107,   108,   109,   170,   174,   193,   129,   256,   387,
     180,   161,   110,   111,   112,   113,   114,   115,   116,   117,
     118,   119,   274,   247,   120,   185,   212,   190,   191,   198,
      15,    16,    17,   201,   213,   193,   217,   218,   219,   220,
     221,   110,   111,   112,   113,   114,   115,   116,   117,   118,
     119,   214,   231,   120,   230,   235,   207,    15,    16,    17,
     311,   222,   314,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
     239,   241,    35,   244,   152,   107,   108,   109,   292,   310,
      18,    19,    20,    21,    22,    23,    24,    25,    26,    27,
      28,    29,    30,    31,    32,    33,    34,   276,   281,    35,
     107,   108,   109,   282,   284,   270,   273,   288,   297,   300,
     320,   303,   304,   316,   319,   146,   111,   112,   113,   114,
     115,   116,   117,   118,   119,   321,   322,   120,   336,   351,
     326,   337,   338,   340,   202,   343,   344,    65,   345,   360,
     146,   111,   112,   113,   114,   115,   116,   117,   118,   119,
     361,   374,   120,    15,    16,    17,   364,   377,   147,    75,
      76,    77,    78,    79,    80,    81,    82,    83,    84,    85,
      86,    87,    88,   378,   380,   385,    67,   391,   392,   393,
     394,   395,    15,    16,    17,   396,    18,    19,    20,    21,
      22,    23,    24,    25,    26,    27,    28,    29,    30,    31,
      32,    33,    34,   397,   398,    35,   403,   152,   107,   108,
     109,    69,    70,   137,   100,    18,    19,    20,    21,    22,
      23,    24,    25,    26,    27,    28,    29,    30,    31,    32,
      33,    34,   101,    73,    35,   107,   108,   109,   240,   124,
     331,   260,   193,   217,   325,   353,   163,   221,   110,   111,
     112,   113,   114,   115,   116,   117,   118,   119,   367,   197,
     120,   107,   108,   109,   166,   258,   275,   168,   386,   193,
     217,   172,   332,   215,     0,   110,   111,   112,   113,   114,
     115,   116,   117,   118,   119,   175,   356,   120,   107,   108,
     109,     0,   357,     0,     0,     0,     0,     0,     0,     0,
       0,   110,   111,   112,   113,   114,   115,   116,   117,   118,
     119,     0,     0,   120,    75,    76,    77,    78,    79,    80,
      81,    82,    83,    84,    85,    86,    87,    88,   146,   111,
     112,   113,   114,   115,   116,   117,   118,   119,     0,     0,
     120
};

static const short yycheck[] =
{
      13,    14,   157,   158,   207,   155,   223,    93,   180,   235,
      92,   290,   235,   300,    48,   241,   129,   234,   354,    52,
     341,    38,     6,    28,   171,    30,   198,    38,    45,    46,
      23,    24,    25,   250,   189,   252,    57,    70,    72,   186,
      73,    54,    53,    54,    65,     0,    59,    60,    32,    33,
      34,    61,    63,   256,   375,   376,    53,    54,   171,   262,
     396,     3,   279,   280,    98,     6,    63,     4,     5,   390,
     287,   297,   222,   186,   300,    61,    22,   300,    24,    25,
      21,    22,    23,    24,    25,   364,    36,   290,    38,    24,
      25,   104,    42,    62,   180,    45,   246,   179,   385,    21,
      22,    23,    24,    25,    22,    23,    24,    25,    61,    62,
     313,    62,   284,    32,    33,    34,    33,    34,    61,    62,
     337,   338,    61,    62,    29,    30,   281,   282,   214,    61,
      62,    61,    62,   283,    61,   361,    61,    62,   341,    31,
      61,    62,    62,    47,    48,    61,    62,    61,    62,    45,
      46,   368,   369,   370,    61,     3,     4,     5,    61,    62,
      61,   364,   375,   376,   319,   266,   267,    61,    61,    27,
      61,    61,   375,   376,    61,    27,    62,    62,    62,    61,
      57,    61,     3,     4,     5,    61,    61,   390,    36,    37,
      38,    39,    40,    41,    42,    43,    44,    45,    46,    47,
      48,    49,    50,    51,    52,    62,    61,    55,    61,   222,
      61,     3,     4,     5,    44,    62,    37,    65,   231,   374,
      61,    34,    43,    44,    45,    46,    47,    48,    49,    50,
      51,    52,   245,   246,    55,    61,    26,    62,    62,    61,
       3,     4,     5,    60,    62,    37,    38,    39,    40,    41,
      42,    43,    44,    45,    46,    47,    48,    49,    50,    51,
      52,    61,    61,    55,    62,    61,    30,     3,     4,     5,
     283,    63,   285,    36,    37,    38,    39,    40,    41,    42,
      43,    44,    45,    46,    47,    48,    49,    50,    51,    52,
      62,    61,    55,    62,    57,     3,     4,     5,    56,    62,
      36,    37,    38,    39,    40,    41,    42,    43,    44,    45,
      46,    47,    48,    49,    50,    51,    52,    62,    61,    55,
       3,     4,     5,    61,    61,    30,    62,    61,    61,    61,
      58,    62,    62,    62,    61,    43,    44,    45,    46,    47,
      48,    49,    50,    51,    52,    58,    58,    55,    62,    49,
      45,    62,    62,    62,    62,    62,    62,    49,    62,    62,
      43,    44,    45,    46,    47,    48,    49,    50,    51,    52,
      61,    61,    55,     3,     4,     5,    62,    62,    61,     7,
       8,     9,    10,    11,    12,    13,    14,    15,    16,    17,
      18,    19,    20,    62,    62,    61,    50,    62,    62,    62,
      62,    62,     3,     4,     5,    62,    36,    37,    38,    39,
      40,    41,    42,    43,    44,    45,    46,    47,    48,    49,
      50,    51,    52,    62,    62,    55,    62,    57,     3,     4,
       5,    51,    51,   127,    62,    36,    37,    38,    39,    40,
      41,    42,    43,    44,    45,    46,    47,    48,    49,    50,
      51,    52,    89,    52,    55,     3,     4,     5,   210,    94,
     298,    36,    37,    38,   296,   332,   137,    42,    43,    44,
      45,    46,    47,    48,    49,    50,    51,    52,   346,   181,
      55,     3,     4,     5,   142,   232,   246,   143,   371,    37,
      38,   151,   300,   194,    -1,    43,    44,    45,    46,    47,
      48,    49,    50,    51,    52,   155,   335,    55,     3,     4,
       5,    -1,   335,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    43,    44,    45,    46,    47,    48,    49,    50,    51,
      52,    -1,    -1,    55,     7,     8,     9,    10,    11,    12,
      13,    14,    15,    16,    17,    18,    19,    20,    43,    44,
      45,    46,    47,    48,    49,    50,    51,    52,    -1,    -1,
      55
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const unsigned char yystos[] =
{
       0,    69,    70,     0,    71,    61,    72,   125,     3,   169,
      61,     4,     5,   170,   171,     3,     4,     5,    36,    37,
      38,    39,    40,    41,    42,    43,    44,    45,    46,    47,
      48,    49,    50,    51,    52,    55,   189,   189,    62,    62,
      73,    61,    61,    74,    75,    76,    77,    78,    79,    80,
      83,    85,    87,    91,    31,     6,    21,    22,    23,    24,
      25,    62,    61,    91,    61,    75,    61,    76,    61,    78,
      87,    61,    79,    85,   189,     7,     8,     9,    10,    11,
      12,    13,    14,    15,    16,    17,    18,    19,    20,    81,
      82,    84,    86,    61,    88,    89,   189,   189,    79,    62,
      62,    82,   157,   162,   165,   189,   157,     3,     4,     5,
      43,    44,    45,    46,    47,    48,    49,    50,    51,    52,
      55,   187,   188,    62,    89,    92,    93,   126,    62,    65,
     166,   189,    62,    90,    27,    27,    61,    80,   127,   128,
     129,   130,   132,   134,   140,   141,    43,    61,   167,   179,
     187,   163,    57,   158,   160,   161,   190,    61,    61,    32,
      33,    34,    61,   128,    62,    61,   129,    61,   130,   131,
      44,   180,   162,   164,    62,   166,   190,   160,   160,   133,
      61,   135,   136,   137,   142,    61,   168,   179,   187,   159,
      62,    62,   157,    37,   173,   188,    62,   136,    61,   146,
     153,    60,    62,   179,   187,   160,    28,    30,    94,    95,
      96,    98,    26,    62,    61,   137,   138,    38,    39,    40,
      41,    42,    63,   173,   174,   175,   176,   177,   178,   188,
      62,    61,   143,   144,    97,    61,   110,   116,   153,    62,
      95,    61,   101,   102,    62,   139,   156,   189,   190,   146,
     151,   147,   148,   149,   150,   154,   189,    62,   144,   146,
      36,   172,   173,   174,   178,    53,    54,    63,   174,    29,
      30,    99,   100,    62,   189,   156,    62,    62,   146,   152,
     146,    61,    61,   155,    61,   145,   153,   112,    61,   153,
     114,   111,    56,   186,   186,   186,   103,    61,   104,   106,
      61,   118,   122,    62,    62,    62,   146,   146,   160,   160,
      62,   189,   190,   173,   189,   146,    62,    62,   110,    61,
      58,    58,    58,    61,    62,   102,    45,    46,   174,   181,
     182,   100,   172,   174,   178,   181,    62,    62,    62,   153,
      62,   113,   160,    62,    62,    62,   105,    47,    48,   183,
     184,    49,   185,   104,   121,   119,   183,   184,   146,   146,
      62,    61,   115,   116,    62,    61,    62,   106,   107,   108,
     109,   120,    62,   118,    61,   123,   124,    62,    62,   174,
      62,   110,   146,   146,   146,    61,   122,   160,   115,   115,
     117,    62,    62,    62,    62,    62,    62,    62,    62,    61,
      62,   116,   118,    62
};

#if ! defined (YYSIZE_T) && defined (__SIZE_TYPE__)
# define YYSIZE_T __SIZE_TYPE__
#endif
#if ! defined (YYSIZE_T) && defined (size_t)
# define YYSIZE_T size_t
#endif
#if ! defined (YYSIZE_T)
# if defined (__STDC__) || defined (__cplusplus)
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# endif
#endif
#if ! defined (YYSIZE_T)
# define YYSIZE_T unsigned int
#endif

#define yyerrok		(yyerrstatus = 0)
#define yyclearin	(yychar = YYEMPTY)
#define YYEMPTY		(-2)
#define YYEOF		0

#define YYACCEPT	goto yyacceptlab
#define YYABORT		goto yyabortlab
#define YYERROR		goto yyerrlab1


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
      YYPOPSTACK;						\
      goto yybackup;						\
    }								\
  else								\
    { 								\
      yyerror ("syntax error: cannot back up");\
      YYERROR;							\
    }								\
while (0)

#define YYTERROR	1
#define YYERRCODE	256

/* YYLLOC_DEFAULT -- Compute the default location (before the actions
   are run).  */

#ifndef YYLLOC_DEFAULT
# define YYLLOC_DEFAULT(Current, Rhs, N)         \
  Current.first_line   = Rhs[1].first_line;      \
  Current.first_column = Rhs[1].first_column;    \
  Current.last_line    = Rhs[N].last_line;       \
  Current.last_column  = Rhs[N].last_column;
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
} while (0)

# define YYDSYMPRINT(Args)			\
do {						\
  if (yydebug)					\
    yysymprint Args;				\
} while (0)

# define YYDSYMPRINTF(Title, Token, Value, Location)		\
do {								\
  if (yydebug)							\
    {								\
      YYFPRINTF (stderr, "%s ", Title);				\
      yysymprint (stderr, 					\
                  Token, Value);	\
      YYFPRINTF (stderr, "\n");					\
    }								\
} while (0)

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (cinluded).                                                   |
`------------------------------------------------------------------*/

#if defined (__STDC__) || defined (__cplusplus)
static void
yy_stack_print (short *bottom, short *top)
#else
static void
yy_stack_print (bottom, top)
    short *bottom;
    short *top;
#endif
{
  YYFPRINTF (stderr, "Stack now");
  for (/* Nothing. */; bottom <= top; ++bottom)
    YYFPRINTF (stderr, " %d", *bottom);
  YYFPRINTF (stderr, "\n");
}

# define YY_STACK_PRINT(Bottom, Top)				\
do {								\
  if (yydebug)							\
    yy_stack_print ((Bottom), (Top));				\
} while (0)


/*------------------------------------------------.
| Report that the YYRULE is going to be reduced.  |
`------------------------------------------------*/

#if defined (__STDC__) || defined (__cplusplus)
static void
yy_reduce_print (int yyrule)
#else
static void
yy_reduce_print (yyrule)
    int yyrule;
#endif
{
  int yyi;
  unsigned int yylno = yyrline[yyrule];
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %u), ",
             yyrule - 1, yylno);
  /* Print the symbols being reduced, and their result.  */
  for (yyi = yyprhs[yyrule]; 0 <= yyrhs[yyi]; yyi++)
    YYFPRINTF (stderr, "%s ", yytname [yyrhs[yyi]]);
  YYFPRINTF (stderr, "-> %s\n", yytname [yyr1[yyrule]]);
}

# define YY_REDUCE_PRINT(Rule)		\
do {					\
  if (yydebug)				\
    yy_reduce_print (Rule);		\
} while (0)

/* Nonzero means print parse trace.  It is left uninitialized so that
   multiple parsers can coexist.  */
int yydebug;
#else /* !YYDEBUG */
# define YYDPRINTF(Args)
# define YYDSYMPRINT(Args)
# define YYDSYMPRINTF(Title, Token, Value, Location)
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
   SIZE_MAX < YYSTACK_BYTES (YYMAXDEPTH)
   evaluated with infinite-precision integer arithmetic.  */

#if YYMAXDEPTH == 0
# undef YYMAXDEPTH
#endif

#ifndef YYMAXDEPTH
# define YYMAXDEPTH 10000
#endif



#if YYERROR_VERBOSE

# ifndef yystrlen
#  if defined (__GLIBC__) && defined (_STRING_H)
#   define yystrlen strlen
#  else
/* Return the length of YYSTR.  */
static YYSIZE_T
#   if defined (__STDC__) || defined (__cplusplus)
yystrlen (const char *yystr)
#   else
yystrlen (yystr)
     const char *yystr;
#   endif
{
  register const char *yys = yystr;

  while (*yys++ != '\0')
    continue;

  return yys - yystr - 1;
}
#  endif
# endif

# ifndef yystpcpy
#  if defined (__GLIBC__) && defined (_STRING_H) && defined (_GNU_SOURCE)
#   define yystpcpy stpcpy
#  else
/* Copy YYSRC to YYDEST, returning the address of the terminating '\0' in
   YYDEST.  */
static char *
#   if defined (__STDC__) || defined (__cplusplus)
yystpcpy (char *yydest, const char *yysrc)
#   else
yystpcpy (yydest, yysrc)
     char *yydest;
     const char *yysrc;
#   endif
{
  register char *yyd = yydest;
  register const char *yys = yysrc;

  while ((*yyd++ = *yys++) != '\0')
    continue;

  return yyd - 1;
}
#  endif
# endif

#endif /* !YYERROR_VERBOSE */



#if YYDEBUG
/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

#if defined (__STDC__) || defined (__cplusplus)
static void
yysymprint (FILE *yyoutput, int yytype, YYSTYPE *yyvaluep)
#else
static void
yysymprint (yyoutput, yytype, yyvaluep)
    FILE *yyoutput;
    int yytype;
    YYSTYPE *yyvaluep;
#endif
{
  /* Pacify ``unused variable'' warnings.  */
  (void) yyvaluep;

  if (yytype < YYNTOKENS)
    {
      YYFPRINTF (yyoutput, "token %s (", yytname[yytype]);
# ifdef YYPRINT
      YYPRINT (yyoutput, yytoknum[yytype], *yyvaluep);
# endif
    }
  else
    YYFPRINTF (yyoutput, "nterm %s (", yytname[yytype]);

  switch (yytype)
    {
      default:
        break;
    }
  YYFPRINTF (yyoutput, ")");
}

#endif /* ! YYDEBUG */
/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

#if defined (__STDC__) || defined (__cplusplus)
static void
yydestruct (int yytype, YYSTYPE *yyvaluep)
#else
static void
yydestruct (yytype, yyvaluep)
    int yytype;
    YYSTYPE *yyvaluep;
#endif
{
  /* Pacify ``unused variable'' warnings.  */
  (void) yyvaluep;

  switch (yytype)
    {

      default:
        break;
    }
}


/* Prevent warnings from -Wmissing-prototypes.  */

#ifdef YYPARSE_PARAM
# if defined (__STDC__) || defined (__cplusplus)
int yyparse (void *YYPARSE_PARAM);
# else
int yyparse ();
# endif
#else /* ! YYPARSE_PARAM */
#if defined (__STDC__) || defined (__cplusplus)
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



/*----------.
| yyparse.  |
`----------*/

#ifdef YYPARSE_PARAM
# if defined (__STDC__) || defined (__cplusplus)
int yyparse (void *YYPARSE_PARAM)
# else
int yyparse (YYPARSE_PARAM)
  void *YYPARSE_PARAM;
# endif
#else /* ! YYPARSE_PARAM */
#if defined (__STDC__) || defined (__cplusplus)
int
yyparse (void)
#else
int
yyparse ()

#endif
#endif
{
  
  register int yystate;
  register int yyn;
  int yyresult;
  /* Number of tokens to shift before error messages enabled.  */
  int yyerrstatus;
  /* Lookahead token as an internal (translated) token number.  */
  int yytoken = 0;

  /* Three stacks and their tools:
     `yyss': related to states,
     `yyvs': related to semantic values,
     `yyls': related to locations.

     Refer to the stacks thru separate pointers, to allow yyoverflow
     to reallocate them elsewhere.  */

  /* The state stack.  */
  short	yyssa[YYINITDEPTH];
  short *yyss = yyssa;
  register short *yyssp;

  /* The semantic value stack.  */
  YYSTYPE yyvsa[YYINITDEPTH];
  YYSTYPE *yyvs = yyvsa;
  register YYSTYPE *yyvsp;



#define YYPOPSTACK   (yyvsp--, yyssp--)

  YYSIZE_T yystacksize = YYINITDEPTH;

  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;


  /* When reducing, the number of symbols on the RHS of the reduced
     rule.  */
  int yylen;

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
     have just been pushed. so pushing a state here evens the stacks.
     */
  yyssp++;

 yysetstate:
  *yyssp = yystate;

  if (yyss + yystacksize - 1 <= yyssp)
    {
      /* Get the current used size of the three stacks, in elements.  */
      YYSIZE_T yysize = yyssp - yyss + 1;

#ifdef yyoverflow
      {
	/* Give user a chance to reallocate the stack. Use copies of
	   these so that the &'s don't force the real ones into
	   memory.  */
	YYSTYPE *yyvs1 = yyvs;
	short *yyss1 = yyss;


	/* Each stack pointer address is followed by the size of the
	   data in use in that stack, in bytes.  This used to be a
	   conditional around just the two extra args, but that might
	   be undefined if yyoverflow is a macro.  */
	yyoverflow ("parser stack overflow",
		    &yyss1, yysize * sizeof (*yyssp),
		    &yyvs1, yysize * sizeof (*yyvsp),

		    &yystacksize);

	yyss = yyss1;
	yyvs = yyvs1;
      }
#else /* no yyoverflow */
# ifndef YYSTACK_RELOCATE
      goto yyoverflowlab;
# else
      /* Extend the stack our own way.  */
      if (YYMAXDEPTH <= yystacksize)
	goto yyoverflowlab;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
	yystacksize = YYMAXDEPTH;

      {
	short *yyss1 = yyss;
	union yyalloc *yyptr =
	  (union yyalloc *) YYSTACK_ALLOC (YYSTACK_BYTES (yystacksize));
	if (! yyptr)
	  goto yyoverflowlab;
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

/* Do appropriate processing given the current state.  */
/* Read a lookahead token if we need one and don't already have one.  */
/* yyresume: */

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
      YYDSYMPRINTF ("Next token is", yytoken, &yylval, &yylloc);
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

  /* Shift the lookahead token.  */
  YYDPRINTF ((stderr, "Shifting token %s, ", yytname[yytoken]));

  /* Discard the token being shifted unless it is eof.  */
  if (yychar != YYEOF)
    yychar = YYEMPTY;

  *++yyvsp = yylval;


  /* Count tokens shifted since error; after three, turn off error
     status.  */
  if (yyerrstatus)
    yyerrstatus--;

  yystate = yyn;
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
#line 246 "pddl.yy"
    { success = true; line_number = 1; }
    break;

  case 3:
#line 247 "pddl.yy"
    { if (!success) YYERROR; }
    break;

  case 7:
#line 260 "pddl.yy"
    { make_domain(yyvsp[-1].str); }
    break;

  case 30:
#line 301 "pddl.yy"
    { requirements->strips = true; }
    break;

  case 31:
#line 302 "pddl.yy"
    { requirements->typing = true; }
    break;

  case 32:
#line 304 "pddl.yy"
    { requirements->negative_preconditions = true; }
    break;

  case 33:
#line 306 "pddl.yy"
    { requirements->disjunctive_preconditions = true; }
    break;

  case 34:
#line 307 "pddl.yy"
    { requirements->equality = true; }
    break;

  case 35:
#line 309 "pddl.yy"
    { requirements->existential_preconditions = true; }
    break;

  case 36:
#line 311 "pddl.yy"
    { requirements->universal_preconditions = true; }
    break;

  case 37:
#line 313 "pddl.yy"
    { requirements->quantified_preconditions(); }
    break;

  case 38:
#line 314 "pddl.yy"
    { requirements->conditional_effects = true; }
    break;

  case 39:
#line 315 "pddl.yy"
    { throw Exception("`:fluents' not supported"); }
    break;

  case 40:
#line 316 "pddl.yy"
    { requirements->adl(); }
    break;

  case 41:
#line 317 "pddl.yy"
    { requirements->durative_actions = true; }
    break;

  case 42:
#line 319 "pddl.yy"
    { requirements->duration_inequalities = true; }
    break;

  case 43:
#line 321 "pddl.yy"
    { throw Exception("`:continuous-effects' not supported"); }
    break;

  case 44:
#line 324 "pddl.yy"
    { require_typing(); }
    break;

  case 45:
#line 325 "pddl.yy"
    { name_map_kind = NOTHING; }
    break;

  case 46:
#line 328 "pddl.yy"
    { name_map_kind = CONSTANT_MAP; }
    break;

  case 47:
#line 329 "pddl.yy"
    { name_map_kind = NOTHING; }
    break;

  case 51:
#line 343 "pddl.yy"
    { make_predicate(yyvsp[0].str); }
    break;

  case 52:
#line 344 "pddl.yy"
    { add_predicate(); }
    break;

  case 53:
#line 351 "pddl.yy"
    { make_action(yyvsp[0].str, false); }
    break;

  case 54:
#line 353 "pddl.yy"
    { add_action(); }
    break;

  case 55:
#line 354 "pddl.yy"
    { make_action(yyvsp[0].str, true); }
    break;

  case 56:
#line 356 "pddl.yy"
    { add_action(); }
    break;

  case 61:
#line 367 "pddl.yy"
    { formula_time = Formula::OVER_ALL; }
    break;

  case 62:
#line 368 "pddl.yy"
    { action->set_precondition(*yyvsp[0].formula); }
    break;

  case 63:
#line 371 "pddl.yy"
    { add_effect(); }
    break;

  case 64:
#line 374 "pddl.yy"
    { action->set_precondition(*yyvsp[-1].formula); }
    break;

  case 67:
#line 379 "pddl.yy"
    { add_effect(); }
    break;

  case 69:
#line 388 "pddl.yy"
    { require_duration_inequalities(); }
    break;

  case 70:
#line 392 "pddl.yy"
    {
				 require_duration_inequalities();
				 action->set_max_duration(yyvsp[-1].num);
			       }
    break;

  case 71:
#line 397 "pddl.yy"
    {
				 require_duration_inequalities();
				 action->set_min_duration(yyvsp[-1].num);
			       }
    break;

  case 72:
#line 402 "pddl.yy"
    { action->set_duration(yyvsp[-1].num); }
    break;

  case 76:
#line 415 "pddl.yy"
    { yyval.formula = yyvsp[-1].formula; }
    break;

  case 77:
#line 418 "pddl.yy"
    { yyval.formula = &Formula::TRUE; }
    break;

  case 78:
#line 419 "pddl.yy"
    { yyval.formula = &(*yyvsp[-1].formula && *yyvsp[0].formula); }
    break;

  case 79:
#line 422 "pddl.yy"
    { formula_time = Formula::AT_START; }
    break;

  case 80:
#line 423 "pddl.yy"
    { yyval.formula = yyvsp[-1].formula; }
    break;

  case 81:
#line 424 "pddl.yy"
    { formula_time = Formula::AT_END; }
    break;

  case 82:
#line 425 "pddl.yy"
    { yyval.formula = yyvsp[-1].formula; }
    break;

  case 83:
#line 426 "pddl.yy"
    { formula_time = Formula::OVER_ALL; }
    break;

  case 84:
#line 427 "pddl.yy"
    { yyval.formula = yyvsp[-1].formula; }
    break;

  case 87:
#line 436 "pddl.yy"
    { prepare_forall_effect(); }
    break;

  case 88:
#line 437 "pddl.yy"
    { add_forall_effect(); }
    break;

  case 89:
#line 438 "pddl.yy"
    { formula_time = Formula::OVER_ALL; }
    break;

  case 90:
#line 439 "pddl.yy"
    { prepare_conditional_effect(yyvsp[0].formula); }
    break;

  case 91:
#line 440 "pddl.yy"
    { add_conditional_effect(); }
    break;

  case 96:
#line 451 "pddl.yy"
    { add_positive(*yyvsp[0].atom); }
    break;

  case 97:
#line 452 "pddl.yy"
    { add_negative(*yyvsp[-1].atom); }
    break;

  case 102:
#line 461 "pddl.yy"
    { prepare_forall_effect(); }
    break;

  case 103:
#line 462 "pddl.yy"
    { add_forall_effect(); }
    break;

  case 104:
#line 463 "pddl.yy"
    { prepare_conditional_effect(yyvsp[0].formula); }
    break;

  case 105:
#line 464 "pddl.yy"
    { add_conditional_effect(); }
    break;

  case 108:
#line 471 "pddl.yy"
    { formula_time = Formula::AT_START; }
    break;

  case 109:
#line 472 "pddl.yy"
    { add_effect(); }
    break;

  case 110:
#line 473 "pddl.yy"
    { formula_time = Formula::AT_END; }
    break;

  case 111:
#line 474 "pddl.yy"
    { add_effect(); }
    break;

  case 112:
#line 482 "pddl.yy"
    { make_problem(yyvsp[-5].str, yyvsp[-1].str); }
    break;

  case 113:
#line 483 "pddl.yy"
    { delete requirements; }
    break;

  case 121:
#line 499 "pddl.yy"
    { parsing_av_list = true; context.push_frame();  }
    break;

  case 122:
#line 499 "pddl.yy"
    { context.pop_frame(); parsing_av_list = false;}
    break;

  case 123:
#line 502 "pddl.yy"
    { name_map_kind = OBJECT_MAP; }
    break;

  case 128:
#line 512 "pddl.yy"
    { problem->add_init(*yyvsp[0].atom); }
    break;

  case 130:
#line 516 "pddl.yy"
    { prepare_atom(yyvsp[0].str); }
    break;

  case 131:
#line 517 "pddl.yy"
    { yyval.atom = make_atom(); }
    break;

  case 133:
#line 521 "pddl.yy"
    { add_term(yyvsp[0].str); }
    break;

  case 135:
#line 528 "pddl.yy"
    { formula_time = Formula::AT_START; }
    break;

  case 136:
#line 529 "pddl.yy"
    { problem->set_goal(*yyvsp[-1].formula); }
    break;

  case 139:
#line 562 "pddl.yy"
    { add_link_to_avoid(yyvsp[-3].str, *yyvsp[-2].formula, yyvsp[-1].str); }
    break;

  case 140:
#line 565 "pddl.yy"
    { yyval.formula = yyvsp[0].atom; }
    break;

  case 141:
#line 566 "pddl.yy"
    { yyval.formula = make_negation(*yyvsp[-1].atom); }
    break;

  case 142:
#line 575 "pddl.yy"
    { yyval.formula = yyvsp[0].atom; }
    break;

  case 143:
#line 576 "pddl.yy"
    { yyval.formula = make_equality(*yyvsp[-2].term, *yyvsp[-1].term); }
    break;

  case 144:
#line 577 "pddl.yy"
    { yyval.formula = make_negation(*yyvsp[-1].formula); }
    break;

  case 145:
#line 578 "pddl.yy"
    { yyval.formula = yyvsp[-1].formula; }
    break;

  case 146:
#line 579 "pddl.yy"
    { prepare_disjunction(); }
    break;

  case 147:
#line 579 "pddl.yy"
    { yyval.formula = yyvsp[-1].formula; }
    break;

  case 148:
#line 580 "pddl.yy"
    { prepare_disjunction(); }
    break;

  case 149:
#line 581 "pddl.yy"
    { yyval.formula = &(!*yyvsp[-2].formula || *yyvsp[-1].formula); }
    break;

  case 150:
#line 582 "pddl.yy"
    { prepare_exists(); }
    break;

  case 151:
#line 583 "pddl.yy"
    { yyval.formula = make_exists(*yyvsp[-1].formula); }
    break;

  case 152:
#line 584 "pddl.yy"
    { prepare_forall(); }
    break;

  case 153:
#line 585 "pddl.yy"
    { yyval.formula = make_forall(*yyvsp[-1].formula); }
    break;

  case 154:
#line 588 "pddl.yy"
    { yyval.formula = &Formula::TRUE; }
    break;

  case 155:
#line 589 "pddl.yy"
    { yyval.formula = &(*yyvsp[-1].formula && *yyvsp[0].formula); }
    break;

  case 156:
#line 592 "pddl.yy"
    { yyval.formula = &Formula::FALSE; }
    break;

  case 157:
#line 593 "pddl.yy"
    { yyval.formula = &(*yyvsp[-1].formula || *yyvsp[0].formula); }
    break;

  case 158:
#line 596 "pddl.yy"
    { prepare_atom(yyvsp[0].str); }
    break;

  case 159:
#line 597 "pddl.yy"
    {  yyval.atom = make_atom(); }
    break;

  case 161:
#line 605 "pddl.yy"
    {add_term(yyvsp[0].str); }
    break;

  case 162:
#line 606 "pddl.yy"
    {add_term(yyvsp[0].str); }
    break;

  case 163:
#line 609 "pddl.yy"
    { yyval.term = &make_term(yyvsp[0].str); }
    break;

  case 164:
#line 610 "pddl.yy"
    { yyval.term = &make_term(yyvsp[0].str); }
    break;

  case 167:
#line 617 "pddl.yy"
    { add_variables(yyvsp[0].strs, Type::OBJECT); }
    break;

  case 168:
#line 618 "pddl.yy"
    { add_variables(yyvsp[-1].strs, *yyvsp[0].type); }
    break;

  case 172:
#line 626 "pddl.yy"
    { yyval.strs = new std::vector<std::string>(1, *yyvsp[0].str); delete yyvsp[0].str; }
    break;

  case 173:
#line 628 "pddl.yy"
    { yyval.strs = yyvsp[-1].strs; yyval.strs->push_back(*yyvsp[0].str); delete yyvsp[0].str; }
    break;

  case 174:
#line 631 "pddl.yy"
    { add_names(yyvsp[0].strs, Type::OBJECT); }
    break;

  case 175:
#line 632 "pddl.yy"
    { add_names(yyvsp[-1].strs, *yyvsp[0].type); }
    break;

  case 179:
#line 639 "pddl.yy"
    { yyval.strs = new std::vector<std::string>(1, *yyvsp[0].str); delete yyvsp[0].str; }
    break;

  case 180:
#line 640 "pddl.yy"
    { yyval.strs = yyvsp[-1].strs; yyval.strs->push_back(*yyvsp[0].str); delete yyvsp[0].str; }
    break;

  case 181:
#line 643 "pddl.yy"
    { yyval.type = yyvsp[0].type; }
    break;

  case 182:
#line 646 "pddl.yy"
    { yyval.type = &Type::OBJECT; }
    break;

  case 183:
#line 647 "pddl.yy"
    { yyval.type = &make_type(yyvsp[0].str); }
    break;

  case 184:
#line 648 "pddl.yy"
    { yyval.type = &UnionType::simplify(*yyvsp[-1].types); }
    break;

  case 185:
#line 651 "pddl.yy"
    { yyval.types = new UnionType(); }
    break;

  case 186:
#line 652 "pddl.yy"
    { yyval.types = new UnionType(make_type(yyvsp[0].str)); }
    break;

  case 187:
#line 653 "pddl.yy"
    { yyval.types = yyvsp[-1].types; }
    break;

  case 188:
#line 654 "pddl.yy"
    { yyval.types = yyvsp[-1].types; yyval.types->add(make_type(yyvsp[0].str)); }
    break;

  case 189:
#line 657 "pddl.yy"
    { delete yyvsp[0].str; }
    break;

  case 190:
#line 660 "pddl.yy"
    { delete yyvsp[0].str; }
    break;

  case 191:
#line 663 "pddl.yy"
    { delete yyvsp[0].str; }
    break;

  case 192:
#line 666 "pddl.yy"
    { delete yyvsp[0].str; }
    break;

  case 193:
#line 669 "pddl.yy"
    { delete yyvsp[0].str; }
    break;

  case 194:
#line 672 "pddl.yy"
    { delete yyvsp[0].str; }
    break;

  case 195:
#line 675 "pddl.yy"
    { delete yyvsp[0].str; }
    break;

  case 196:
#line 678 "pddl.yy"
    { delete yyvsp[0].str; }
    break;

  case 197:
#line 681 "pddl.yy"
    { delete yyvsp[0].str; }
    break;

  case 198:
#line 684 "pddl.yy"
    { delete yyvsp[0].str; }
    break;

  case 199:
#line 687 "pddl.yy"
    { delete yyvsp[0].str; }
    break;

  case 200:
#line 690 "pddl.yy"
    { delete yyvsp[0].str; }
    break;

  case 201:
#line 693 "pddl.yy"
    { delete yyvsp[0].str; }
    break;

  case 202:
#line 696 "pddl.yy"
    { delete yyvsp[0].str; }
    break;

  case 203:
#line 699 "pddl.yy"
    { delete yyvsp[0].str; }
    break;

  case 204:
#line 702 "pddl.yy"
    { delete yyvsp[0].str; }
    break;

  case 205:
#line 705 "pddl.yy"
    { delete yyvsp[0].str; }
    break;

  case 206:
#line 708 "pddl.yy"
    { delete yyvsp[0].str; }
    break;


    }

/* Line 999 of yacc.c.  */
#line 2376 "pddl.cc"

  yyvsp -= yylen;
  yyssp -= yylen;


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
#if YYERROR_VERBOSE
      yyn = yypact[yystate];

      if (YYPACT_NINF < yyn && yyn < YYLAST)
	{
	  YYSIZE_T yysize = 0;
	  int yytype = YYTRANSLATE (yychar);
	  const char* yyprefix;
	  char *yymsg;
	  int yyx;

	  /* Start YYX at -YYN if negative to avoid negative indexes in
	     YYCHECK.  */
	  int yyxbegin = yyn < 0 ? -yyn : 0;

	  /* Stay within bounds of both yycheck and yytname.  */
	  int yychecklim = YYLAST - yyn;
	  int yyxend = yychecklim < YYNTOKENS ? yychecklim : YYNTOKENS;
	  int yycount = 0;

	  yyprefix = ", expecting ";
	  for (yyx = yyxbegin; yyx < yyxend; ++yyx)
	    if (yycheck[yyx + yyn] == yyx && yyx != YYTERROR)
	      {
		yysize += yystrlen (yyprefix) + yystrlen (yytname [yyx]);
		yycount += 1;
		if (yycount == 5)
		  {
		    yysize = 0;
		    break;
		  }
	      }
	  yysize += (sizeof ("syntax error, unexpected ")
		     + yystrlen (yytname[yytype]));
	  yymsg = (char *) YYSTACK_ALLOC (yysize);
	  if (yymsg != 0)
	    {
	      char *yyp = yystpcpy (yymsg, "syntax error, unexpected ");
	      yyp = yystpcpy (yyp, yytname[yytype]);

	      if (yycount < 5)
		{
		  yyprefix = ", expecting ";
		  for (yyx = yyxbegin; yyx < yyxend; ++yyx)
		    if (yycheck[yyx + yyn] == yyx && yyx != YYTERROR)
		      {
			yyp = yystpcpy (yyp, yyprefix);
			yyp = yystpcpy (yyp, yytname[yyx]);
			yyprefix = " or ";
		      }
		}
	      yyerror (yymsg);
	      YYSTACK_FREE (yymsg);
	    }
	  else
	    yyerror ("syntax error; also virtual memory exhausted");
	}
      else
#endif /* YYERROR_VERBOSE */
	yyerror ("syntax error");
    }



  if (yyerrstatus == 3)
    {
      /* If just tried and failed to reuse lookahead token after an
	 error, discard it.  */

      /* Return failure if at end of input.  */
      if (yychar == YYEOF)
        {
	  /* Pop the error token.  */
          YYPOPSTACK;
	  /* Pop the rest of the stack.  */
	  while (yyss < yyssp)
	    {
	      YYDSYMPRINTF ("Error: popping", yystos[*yyssp], yyvsp, yylsp);
	      yydestruct (yystos[*yyssp], yyvsp);
	      YYPOPSTACK;
	    }
	  YYABORT;
        }

      YYDSYMPRINTF ("Error: discarding", yytoken, &yylval, &yylloc);
      yydestruct (yytoken, &yylval);
      yychar = YYEMPTY;

    }

  /* Else will try to reuse lookahead token after shifting the error
     token.  */
  goto yyerrlab1;


/*----------------------------------------------------.
| yyerrlab1 -- error raised explicitly by an action.  |
`----------------------------------------------------*/
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

      YYDSYMPRINTF ("Error: popping", yystos[*yyssp], yyvsp, yylsp);
      yydestruct (yystos[yystate], yyvsp);
      yyvsp--;
      yystate = *--yyssp;

      YY_STACK_PRINT (yyss, yyssp);
    }

  if (yyn == YYFINAL)
    YYACCEPT;

  YYDPRINTF ((stderr, "Shifting error token, "));

  *++yyvsp = yylval;


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
/*----------------------------------------------.
| yyoverflowlab -- parser overflow comes here.  |
`----------------------------------------------*/
yyoverflowlab:
  yyerror ("parser stack overflow");
  yyresult = 2;
  /* Fall through.  */
#endif

yyreturn:
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif
  return yyresult;
}


#line 736 "pddl.yy"



/* Outputs an error message. */
static void yyerror(const std::string& s) {
  std::cerr << PACKAGE ":" << current_file << ':' << line_number << ": " << s
	    << std::endl;
  success = false;
}


/* Outputs a warning. */
static void yywarning(const std::string& s) {
  if (warning_level > 0) {
    std::cerr << PACKAGE ":" << current_file << ':' << line_number << ": " << s
	      << std::endl;
    if (warning_level > 1) {
      success = false;
    }
  }
}


/* Returns the type with the given name, or NULL if undefined. */
static const SimpleType* find_type(const std::string& name) {
  if (pdomain != NULL) {
    return pdomain->find_type(name);
  } else if (domain != NULL) {
    return domain->find_type(name);
  } else {
    return NULL;
  }
}


/* Returns the constant with the given name, or NULL if undefined.  */
static const Name* find_constant(const std::string& name) {
  const Name* c = NULL;
  if (pdomain != NULL) {
    c = pdomain->find_constant(name);
  }
  if (c == NULL && domain != NULL) {
    c = domain->find_constant(name);
  }
  if (c == NULL && problem != NULL) {
    c = problem->find_object(name);
  }
  return c;
}


/* Returns the predicate with the given name, or NULL if undefined. */
static const Predicate* find_predicate(const std::string& name) {
  if (pdomain != NULL) {
    return pdomain->find_predicate(name);
  } else if (domain != NULL) {
    return domain->find_predicate(name);
  } else {
    return NULL;
  }
}


/* Creates an empty domain with the given name. */
static void make_domain(const std::string* name) {
  pdomain = NULL;
  problem = NULL;
  domain = new Domain(*name);
  requirements = &domain->requirements;
  delete name;
}


/* Creates an empty problem with the given name. */
static void make_problem(const std::string* name,
			 const std::string* domain_name) {
  domain = NULL;
  pdomain = Domain::find(*domain_name);
  if (pdomain != NULL) {
    requirements = new Requirements(pdomain->requirements);
  } else {
    pdomain = new Domain(*domain_name);
    requirements = new Requirements();
    yyerror("undeclared domain `" + *domain_name + "' used");
  }
  problem = new Problem(*name, *pdomain);
  delete name;
  delete domain_name;
}



/* Adds :typing to the requirements. */
static void require_typing() {
  if (!requirements->typing) {
    yywarning("assuming `:typing' requirement");
    requirements->typing = true;
  }
  name_map_kind = TYPE_MAP;
}


/* Adds :duration-inequalities to the requirements. */
static void require_duration_inequalities() {
  if (!requirements->duration_inequalities) {
    yywarning("assuming `:duration-inequalities' requirement");
    requirements->duration_inequalities = true;
  }
}


/* Returns a simple type with the given name. */
static const SimpleType& make_type(const std::string* name) {
  const SimpleType* t = find_type(*name);
  if (t == NULL) {
    SimpleType* st = new SimpleType(*name, Type::OBJECT);
    if (domain != NULL) {
      domain->add_type(*st);
      if (name_map_kind != TYPE_MAP) {
	yywarning("implicit declaration of type `" + *name + "'");
      }
    } else {
      yyerror("undeclared type `" + *name + "' used");
    }
    t = st;
  }
  delete name;
  return *t;
}


/* Returns a simple term with the given name. */
static const Term& make_term(const std::string* name) {
  if ((*name)[0] == '?') {
    const Variable* var = context.find(*name);
    if (var == NULL) {
      var = new Variable(*name, Type::OBJECT);
      context.insert(var);
      
      if(!parsing_av_list)
      	yyerror("free variable `" + *name + "' used");
    }
    delete name;
    return *var;
  } else {
    const Name* c = find_constant(*name);
    if (c == NULL) {
      Name* new_c;
      size_t n = atom->terms().size();
      if (atom != NULL && atom->predicate().arity() > n) {
	new_c = new Name(*name, atom->predicate().type(n));
      } else {
	new_c = new Name(*name, Type::OBJECT);
      }
      if (domain != NULL) {
	domain->add_constant(*new_c);
	yywarning("implicit declaration of constant `" + *name + "'");
      } else {
	problem->add_object(*new_c);
	yywarning("implicit declaration of object `" + *name + "'");
      }
      c = new_c;
    }
    delete name;
    return *c;
  }
}


/* Creates a predicate with the given name. */
static void make_predicate(const std::string* name) {
  predicate = new Predicate(*name);
  delete name;
}


/* Creates an action with the given name. */
static void make_action(const std::string* name, bool durative) {
  if (durative) {
    if (!requirements->durative_actions) {
      yywarning("assuming `:durative-actions' requirement");
      requirements->durative_actions = true;
    }
  }
  context.push_frame();
  action = new ActionSchema(*name, durative);
  delete name;
}


/* Prepares for the parsing of a universally quantified effect. */ 
static void prepare_forall_effect() {
  if (!requirements->conditional_effects) {
    yywarning("assuming `:conditional-effects' requirement");
    requirements->conditional_effects = true;
  }
  add_effect();
  context.push_frame();
  quantified.push_back(NULL);
}


/* Prepares for the parsing of a conditional effect. */ 
static void prepare_conditional_effect(const Formula* condition) {
  if (!requirements->conditional_effects) {
    yywarning("assuming `:conditional-effects' requirement");
    requirements->conditional_effects = true;
  }
  add_effect();
  effect_condition = condition;
}


/* Creates an equality formula. */
static const Formula* make_equality(const Term& t1, const Term& t2) {
  if (!requirements->equality) {
    yywarning("assuming `:equality' requirement");
    requirements->equality = true;
  }
  if (t1.type().subtype(t2.type()) || t2.type().subtype(t1.type())) {
    return new Equality(t1, t2);
  } else {
    return &Formula::FALSE;
  }
}


/* Creates a negation. */
static const Formula* make_negation(const Formula& f) {
  if (typeid(f) == typeid(Atom)) {
    if (!requirements->negative_preconditions) {
      yywarning("assuming `:negative-preconditions' requirement");
      requirements->negative_preconditions = true;
    }
  } else if (!requirements->disjunctive_preconditions
	     && typeid(f) != typeid(Equality)) {
    yywarning("assuming `:disjunctive-preconditions' requirement");
    requirements->disjunctive_preconditions = true;
  }
  return &!f;
}


/* Prepares for the parsing of a disjunction. */
static void prepare_disjunction() {
  if (!requirements->disjunctive_preconditions) {
    yywarning("assuming `:disjunctive-preconditions' requirement");
    requirements->disjunctive_preconditions = true;
  }
}


/* Prepares for the parsing of an existentially quantified formula. */
static void prepare_exists() {
  if (!requirements->existential_preconditions) {
    yywarning("assuming `:existential-preconditions' requirement");
    requirements->existential_preconditions = true;
  }
  context.push_frame();
  quantified.push_back(NULL);
}


/* Prepares for the parsing of a universally quantified formula. */
static void prepare_forall() {
  if (!requirements->universal_preconditions) {
    yywarning("assuming `:universal-preconditions' requirement");
    requirements->universal_preconditions = true;
  }
  context.push_frame();
  quantified.push_back(NULL);
}


/* Creates an existentially quantified formula. */
static const Formula* make_exists(const Formula& body) {
  context.pop_frame();
  size_t m = quantified.size() - 1;
  size_t n = m;
  while (quantified[n] != NULL) {
    n--;
  }
  if (n < m) {
    ExistsFormula& exists = *(new ExistsFormula());
    for (size_t i = n + 1; i <= m; i++) {
      exists.add_parameter(*quantified[i]);
    }
    exists.set_body(body);
    quantified.resize(n);
    return &exists;
  } else {
    quantified.pop_back();
    return &body;
  }
}


/* Creates a universally quantified formula. */
static const Formula* make_forall(const Formula& body) {
  context.pop_frame();
  size_t m = quantified.size() - 1;
  size_t n = m;
  while (quantified[n] != NULL) {
    n--;
  }
  if (n < m) {
    ForallFormula& forall = *(new ForallFormula());
    for (size_t i = n + 1; i <= m; i++) {
      forall.add_parameter(*quantified[i]);
    }
    forall.set_body(body);
    quantified.resize(n);
    return &forall;
  } else {
    quantified.pop_back();
    return &body;
  }
}


/* Adds types, constants, or objects to the current domain or problem. */
static void add_names(const std::vector<std::string>* names,
		      const Type& type) {
  const UnionType* ut = dynamic_cast<const UnionType*>(&type);
  for (std::vector<std::string>::const_iterator si = names->begin();
       si != names->end(); si++) {
    /* Duplicate type if it is a union type so that every name has its
       own copy. */
    const Type* t = (ut != NULL) ? new UnionType(*ut) : &type;
    const std::string& s = *si;
    if (name_map_kind == TYPE_MAP) {
      if (s != "object") {
	SimpleType* old_type = domain->find_type(s);
	if (old_type != NULL) {
	  if (!old_type->add_supertype(*t)) {
	    yyerror("cyclic type hierarchy");
	  }
	  if (ut != NULL) {
	    delete t;
	  }
	} else {
	  domain->add_type(*(new SimpleType(s, *t)));
	}
      } else {
	yywarning("ignoring declaration of reserved type `object'");
      }
    } else if (name_map_kind == CONSTANT_MAP) {
      Name* old_name = domain->find_constant(s);
      if (old_name != NULL) {
	old_name->add_type(*t);
	if (ut != NULL) {
	  delete t;
	}
      } else {
	domain->add_constant(*(new Name(s, *t)));
      }
    } else { /* name_map_kind == OBJECT_MAP */
      if (pdomain->find_constant(s) != NULL) {
	yywarning("ignoring declaration of object `" + s
		  + "' previously declared as constant");
      } else {
	Name* old_name = problem->find_object(s);
	if (old_name != NULL) {
	  old_name->add_type(*t);
	  if (ut != NULL) {
	    delete t;
	  }
	} else {
	  problem->add_object(*(new Name(s, *t)));
	}
      }
    }
  }
  if (ut != NULL) {
    delete ut;
  }
  delete names;
}


/* Adds variables to the current variable list. */
static void add_variables(const std::vector<std::string>* names,
			  const Type& type) {
  const UnionType* ut = dynamic_cast<const UnionType*>(&type);
  for (std::vector<std::string>::const_iterator si = names->begin();
       si != names->end(); si++) {
    /* Duplicate type if it is a union type so that every name has its
       own copy. */
    const Type* t = (ut != NULL) ? new UnionType(*ut) : &type;
    const std::string& s = *si;
    if (predicate != NULL) {
      predicate->add_parameter(*t);
    } else {
      if (context.shallow_find(s) != NULL) {
	yyerror("repetition of parameter `" + s + "'");
      } else if (context.find(s) != NULL) {
	yyerror("shadowing parameter `" + s + "'");
      }
      const Variable* var = new Variable(s, *t);
      context.insert(var);
      if (!quantified.empty()) {
	quantified.push_back(var);
      } else if (action != NULL) {
	action->add_parameter(*var);
      } else {
	yyerror("where do these variables go?");
      }
    }
  }
  if (ut != NULL) {
    delete ut;
  }
  delete names;
}


/* Adds the current predicate to the current domain. */
static void add_predicate() {
  if (find_predicate(predicate->name()) == NULL) {
    domain->add_predicate(*predicate);
  } else {
    yywarning("ignoring repeated declaration of predicate `"
	      + predicate->name() + "'");
    delete predicate;
  }
  predicate = NULL;
}


/* Adds the current action to the current domain. */
static void add_action() {
  context.pop_frame();
  if (domain->find_action(action->name()) == NULL) {
    action->strengthen_effects();
    domain->add_action(*action);
  } else {
    yywarning("ignoring repeated declaration of action `"
	      + action->name() + "'");
    delete action;
  }
  action = NULL;
}


/* Adds the given atom to the add list of the current effect. */
static void add_positive(const Atom& atom) {
  if (effect == NULL) {
    effect = new Effect(formula_time == Formula::AT_START
			? Effect::AT_START : Effect::AT_END);
  }
  effect->add_positive(atom);
}


/* Adds the given atom to the delete list of the current effect. */
static void add_negative(const Atom& atom) {
  if (effect == NULL) {
    effect = new Effect(formula_time == Formula::AT_START
			? Effect::AT_START : Effect::AT_END);
  }
  effect->add_negative(*(new Negation(atom)));
}


/* Adds the current effect to the currect action. */
static void add_effect() {
  if (effect != NULL) {
    for (VarListIter vi = quantified.begin(); vi != quantified.end(); vi++) {
      if (*vi != NULL) {
	effect->add_forall(**vi);
      }
    }
    if (effect_condition != NULL) {
      effect->set_condition(*effect_condition);
    }
    action->add_effect(*effect);
    effect = NULL;
  }
}


/* Adds the current universally quantified effect to the currect action. */
static void add_forall_effect() {
  context.pop_frame();
  add_effect();
  size_t n = quantified.size() - 1;
  while (quantified[n] != NULL) {
    n--;
  }
  quantified.resize(n);
}


/* Adds the current conditional effect to the currect action. */
static void add_conditional_effect() {
  add_effect();
  effect_condition = NULL;
}


/* Prepares for the parsning of an atomic formula. */ 
static void prepare_atom(const std::string* name) {
  const Predicate* p = find_predicate(*name);
  if (p == NULL) {
    p = predicate = new Predicate(*name);
    if (domain != NULL) {
      domain->add_predicate(*predicate);
      yywarning("implicit declaration of predicate `" + *name + "'");
    } else {
      yyerror("undeclared predicate `" + *name + "' used");
    }
  }
  atom = new Atom(*p, formula_time);
  delete name;
}


/* Adds a term with the given name to the current atomic formula. */
static void add_term(const std::string* name) {
  const Term& term = make_term(name);
  size_t n = atom->terms().size();
  
  if (atom->predicate().arity() > n
      && !term.type().subtype(atom->predicate().type(n))) {
    yyerror("type mismatch");
  }
  atom->add_term(term);
}


/* Creates the atomic formula just parsed. */
static const Atom* make_atom() {
  if (atom->predicate().arity() < atom->terms().size()) {
    yyerror("too many parameters passed to predicate `"
	    + atom->predicate().name() + "'");
  } else if (atom->predicate().arity() > atom->terms().size()) {
    yyerror("too few parameters passed to predicate `"
	    + atom->predicate().name() + "'");
  }
  const Atom* a = atom;
  atom = NULL;
  return a;
}

/* ==== J.Peer 29/10/2004 ====
Adds a Causal Link that should be avoided by the planner */
static void add_link_to_avoid(const std::string* name1, const Formula& cond, const std::string* name2) {	    
  CausalLinkToAvoid* clAv = new CausalLinkToAvoid(*name1, (Literal&) cond ,*name2);  	    	   
  clAv->avoids.push_back(clAv);   
}


