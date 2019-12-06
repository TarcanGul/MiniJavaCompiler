/* A Bison parser, made by GNU Bison 3.0.4.  */

/* Bison implementation for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015 Free Software Foundation, Inc.

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
#define YYBISON_VERSION "3.0.4"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* Copy the first part of user declarations.  */
#line 1 "parser.y" /* yacc.c:339  */

  #include <stdio.h>
  #include <stdlib.h>
  #include "AST.h"
  #include <assert.h>
  #include <string.h>
  #define YYDEBUG 1
  #define MAXSIZE 50
  #define GLOBAL_STACK_SIZE 200


  int g_label_counter[5] = {0};

  extern int yylex();
  extern int yylineno;
  extern FILE* yyin;
  void yyerror(char const* msg);
  void type_error(int line_num);
  void update_scope_hierarchy(stmt_node_t * stmt);
  stmt_node_t * main_stmt_list;

  //Function prototypes for statements.
  void s_print(void * arg);
  void s_println(void * arg);
  void s_decl(void * arg);
  void s_asgn(void * arg);
  void s_invoke(void * arg);

  //Expression prototypes.
  void * s_add(struct exp_node * op1, struct exp_node * op2, enum type type);
  void * s_sub(struct exp_node * op1, struct exp_node * op2, enum type type);
  void * s_mul(struct exp_node * op1, struct exp_node * op2, enum type type);
  void * s_div(struct exp_node * op1, struct exp_node * op2, enum type type);
  void * s_plu(struct exp_node * op, enum type type);
  void * s_min(struct exp_node * op, enum type type);
  void * s_less(struct exp_node * op1, struct exp_node * op2);
  void * s_greater(struct exp_node * op1, struct exp_node * op2);
  void * s_leq(struct exp_node * op1, struct exp_node * op2);
  void * s_seq(struct exp_node * op1, struct exp_node * op2);
  void * s_neq(struct exp_node * op1, struct exp_node * op2);
  void * s_eq(struct exp_node * op1, struct exp_node * op2);
  void * s_and(struct exp_node * op1, struct exp_node * op2);
  void * s_or(struct exp_node * op1, struct exp_node * op2);
  void * s_negate(struct exp_node * op, enum type type);
  void * s_len(struct exp_node * op);
  int find_value_of_index(index_list_t * index_list, index_list_t * capacity_list);

  class_t * get_class_info(char * class_name);
  struct exp_node * stack[GLOBAL_STACK_SIZE];
  int stack_header = -1;
  stmt_node_t * current_stmt_list = NULL;
  int execute(stmt_node_t * stmt);

  int type_violation_found = 0;
  int construct_name_table = 1; //global var for setting name table.

  scope_t * current_scope;
  scope_t * global_scope;
 
  program_t * program;

  FILE * gen_file;

  char ** data_section = NULL;
  char ** text_section = NULL;
  int calc_method_size(stmt_node_t * list);
  void method_first_codegen(stmt_node_t * list);
  char * generate_label(label_purpose_t purpose);
  char * generate_str_literal();
  void declare_label(char * label);
  static int temp_counter = 0;
  static int str_literal_counter = 0;
  static char * main_args_name = NULL;

#line 141 "y.tab.c" /* yacc.c:339  */

# ifndef YY_NULLPTR
#  if defined __cplusplus && 201103L <= __cplusplus
#   define YY_NULLPTR nullptr
#  else
#   define YY_NULLPTR 0
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
   by #include "y.tab.h".  */
#ifndef YY_YY_Y_TAB_H_INCLUDED
# define YY_YY_Y_TAB_H_INCLUDED
/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif
#if YYDEBUG
extern int yydebug;
#endif

/* Token type.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    STRING_LITERAL = 258,
    INTEGER_LITERAL = 259,
    ID = 260,
    D_AMPERSAND = 261,
    D_LINES = 262,
    SMALL_EQUAL = 263,
    LARGE_EQUAL = 264,
    D_EQUAL = 265,
    EXC_EQUAL = 266,
    PLUS = 267,
    MINUS = 268,
    STAR = 269,
    SLASH = 270,
    K_CLASS = 271,
    K_INT = 272,
    K_STRING = 273,
    K_BOOLEAN = 274,
    K_IF = 275,
    K_WHILE = 276,
    K_RETURN = 277,
    K_NEW = 278,
    K_THIS = 279,
    K_TRUE = 280,
    K_FALSE = 281,
    K_PRINTLN = 282,
    K_PRINT = 283,
    K_ELSE = 284,
    K_EXTENDS = 285,
    K_PUBLIC = 286,
    K_LENGTH = 287,
    K_STATIC = 288,
    K_VOID = 289,
    K_MAIN = 290,
    LEFT_BRACE = 291,
    RIGHT_BRACE = 292,
    LEFT_PAR = 293,
    RIGHT_PAR = 294,
    LEFT_BRACKET = 295,
    RIGHT_BRACKET = 296,
    EQUAL = 297,
    SEMICOLON = 298,
    COMMA = 299,
    EXC = 300,
    DOT = 301,
    LESS = 302,
    GREATER = 303,
    K_PARSEINT = 304
  };
#endif
/* Tokens.  */
#define STRING_LITERAL 258
#define INTEGER_LITERAL 259
#define ID 260
#define D_AMPERSAND 261
#define D_LINES 262
#define SMALL_EQUAL 263
#define LARGE_EQUAL 264
#define D_EQUAL 265
#define EXC_EQUAL 266
#define PLUS 267
#define MINUS 268
#define STAR 269
#define SLASH 270
#define K_CLASS 271
#define K_INT 272
#define K_STRING 273
#define K_BOOLEAN 274
#define K_IF 275
#define K_WHILE 276
#define K_RETURN 277
#define K_NEW 278
#define K_THIS 279
#define K_TRUE 280
#define K_FALSE 281
#define K_PRINTLN 282
#define K_PRINT 283
#define K_ELSE 284
#define K_EXTENDS 285
#define K_PUBLIC 286
#define K_LENGTH 287
#define K_STATIC 288
#define K_VOID 289
#define K_MAIN 290
#define LEFT_BRACE 291
#define RIGHT_BRACE 292
#define LEFT_PAR 293
#define RIGHT_PAR 294
#define LEFT_BRACKET 295
#define RIGHT_BRACKET 296
#define EQUAL 297
#define SEMICOLON 298
#define COMMA 299
#define EXC 300
#define DOT 301
#define LESS 302
#define GREATER 303
#define K_PARSEINT 304

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED

union YYSTYPE
{
#line 77 "parser.y" /* yacc.c:355  */

  char *string_val;
  int integer_val;
  index_list_t * dimension_list;
  struct exp_node *  exp_node;
  struct var_decl_list_t * vardecllist;
  struct var_decl_t * var_decl;
  stmt_node_t * stmt_node;
  type_info_t * type;
  argument_t * method_arg;
  argument_list_t * arg_list;
  method_t * method;
  method_list_t * method_list;
  exp_list_t * exp_list;
  class_t * class;
  class_list_t * class_list;

#line 297 "y.tab.c" /* yacc.c:355  */
};

typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_Y_TAB_H_INCLUDED  */

/* Copy the second part of user declarations.  */

#line 314 "y.tab.c" /* yacc.c:358  */

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
#else
typedef signed char yytype_int8;
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
# elif ! defined YYSIZE_T
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

#ifndef YY_ATTRIBUTE
# if (defined __GNUC__                                               \
      && (2 < __GNUC__ || (__GNUC__ == 2 && 96 <= __GNUC_MINOR__)))  \
     || defined __SUNPRO_C && 0x5110 <= __SUNPRO_C
#  define YY_ATTRIBUTE(Spec) __attribute__(Spec)
# else
#  define YY_ATTRIBUTE(Spec) /* empty */
# endif
#endif

#ifndef YY_ATTRIBUTE_PURE
# define YY_ATTRIBUTE_PURE   YY_ATTRIBUTE ((__pure__))
#endif

#ifndef YY_ATTRIBUTE_UNUSED
# define YY_ATTRIBUTE_UNUSED YY_ATTRIBUTE ((__unused__))
#endif

#if !defined _Noreturn \
     && (!defined __STDC_VERSION__ || __STDC_VERSION__ < 201112)
# if defined _MSC_VER && 1200 <= _MSC_VER
#  define _Noreturn __declspec (noreturn)
# else
#  define _Noreturn YY_ATTRIBUTE ((__noreturn__))
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YYUSE(E) ((void) (E))
#else
# define YYUSE(E) /* empty */
#endif

#if defined __GNUC__ && 407 <= __GNUC__ * 100 + __GNUC_MINOR__
/* Suppress an incorrect diagnostic about yylval being uninitialized.  */
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN \
    _Pragma ("GCC diagnostic push") \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")\
    _Pragma ("GCC diagnostic ignored \"-Wmaybe-uninitialized\"")
# define YY_IGNORE_MAYBE_UNINITIALIZED_END \
    _Pragma ("GCC diagnostic pop")
#else
# define YY_INITIAL_VALUE(Value) Value
#endif
#ifndef YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_END
#endif
#ifndef YY_INITIAL_VALUE
# define YY_INITIAL_VALUE(Value) /* Nothing. */
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
#    if ! defined _ALLOCA_H && ! defined EXIT_SUCCESS
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
   /* Pacify GCC's 'empty if-body' warning.  */
#  define YYSTACK_FREE(Ptr) do { /* empty */; } while (0)
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
#   if ! defined malloc && ! defined EXIT_SUCCESS
void *malloc (YYSIZE_T); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
#  ifndef YYFREE
#   define YYFREE free
#   if ! defined free && ! defined EXIT_SUCCESS
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
# define YYSTACK_RELOCATE(Stack_alloc, Stack)                           \
    do                                                                  \
      {                                                                 \
        YYSIZE_T yynewbytes;                                            \
        YYCOPY (&yyptr->Stack_alloc, Stack, yysize);                    \
        Stack = &yyptr->Stack_alloc;                                    \
        yynewbytes = yystacksize * sizeof (*Stack) + YYSTACK_GAP_MAXIMUM; \
        yyptr += yynewbytes / sizeof (*yyptr);                          \
      }                                                                 \
    while (0)

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
      while (0)
#  endif
# endif
#endif /* !YYCOPY_NEEDED */

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  5
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   581

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  50
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  30
/* YYNRULES -- Number of rules.  */
#define YYNRULES  90
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  215

/* YYTRANSLATE[YYX] -- Symbol number corresponding to YYX as returned
   by yylex, with out-of-bounds checking.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   304

#define YYTRANSLATE(YYX)                                                \
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, without out-of-bounds checking.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
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
      45,    46,    47,    48,    49
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,   130,   130,   139,   147,   155,   163,   171,   178,   186,
     194,   202,   210,   218,   225,   232,   239,   246,   253,   259,
     265,   269,   273,   288,   305,   306,   310,   322,   330,   347,
     374,   391,   395,   458,   479,   482,   498,   516,   518,   532,
     547,   552,   556,   573,   592,   615,   638,   646,   657,   673,
     681,   683,   686,   696,   713,   715,   720,   720,   722,   731,
     740,   759,   761,   762,   769,   780,   788,   796,   806,   850,
     864,   868,   903,   926,   937,   949,   963,   967,   980,   986,
     994,  1016,  1025,  1036,  1040,  1046,  1057,  1065,  1078,  1079,
    1086
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 0
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "STRING_LITERAL", "INTEGER_LITERAL",
  "ID", "D_AMPERSAND", "D_LINES", "SMALL_EQUAL", "LARGE_EQUAL", "D_EQUAL",
  "EXC_EQUAL", "PLUS", "MINUS", "STAR", "SLASH", "K_CLASS", "K_INT",
  "K_STRING", "K_BOOLEAN", "K_IF", "K_WHILE", "K_RETURN", "K_NEW",
  "K_THIS", "K_TRUE", "K_FALSE", "K_PRINTLN", "K_PRINT", "K_ELSE",
  "K_EXTENDS", "K_PUBLIC", "K_LENGTH", "K_STATIC", "K_VOID", "K_MAIN",
  "LEFT_BRACE", "RIGHT_BRACE", "LEFT_PAR", "RIGHT_PAR", "LEFT_BRACKET",
  "RIGHT_BRACKET", "EQUAL", "SEMICOLON", "COMMA", "EXC", "DOT", "LESS",
  "GREATER", "K_PARSEINT", "$accept", "program", "Expression", "MainClass",
  "ClassDeclList", "ClassDecl", "VarDeclList", "MethodDeclList",
  "MethodDecl", "MethodDeclWithPublic", "Opt_Inheritance", "VarDecl",
  "VarLongerDecl", "VarDeclTail", "Opt_ExpressionList", "ExpressionList",
  "ExpressionTailList", "ExpressionTail", "Opt_FormalList", "FormalList",
  "FormalListTail", "FormalListTailList", "Type", "PrimeType", "Statement",
  "StatementList", "MethodCall", "Index", "IndexNoExpr", "LeftValue", YY_NULLPTR
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[NUM] -- (External) token number corresponding to the
   (internal) symbol number NUM (which must be that of a token).  */
static const yytype_uint16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
     285,   286,   287,   288,   289,   290,   291,   292,   293,   294,
     295,   296,   297,   298,   299,   300,   301,   302,   303,   304
};
# endif

#define YYPACT_NINF -137

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-137)))

#define YYTABLE_NINF -1

#define yytable_value_is_error(Yytable_value) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
      -5,    16,    50,  -137,    21,  -137,    38,    37,    72,  -137,
      49,    41,    54,    90,    62,    65,  -137,  -137,    64,    55,
      86,    15,  -137,  -137,  -137,   154,  -137,    18,  -137,    83,
      88,   137,    92,  -137,    97,    75,  -137,  -137,  -137,    19,
     104,  -137,    87,   191,   -15,  -137,  -137,   111,   191,   191,
     107,   108,  -137,  -137,   191,  -137,   191,   115,   212,  -137,
     -33,   164,    22,   120,   191,    -6,   159,   427,  -137,   160,
    -137,   191,   126,    76,    76,   -22,    97,   111,   165,   235,
     185,   191,   191,   191,   191,   191,   191,   191,   191,   191,
     191,   191,  -137,   191,   191,   191,     3,  -137,   255,   136,
      75,   427,  -137,   140,    66,   139,   191,   141,    92,   126,
    -137,  -137,   278,   185,   185,   185,   185,   185,   185,    76,
      76,  -137,  -137,   185,   185,   427,   144,  -137,  -137,  -137,
    -137,    75,   145,  -137,    25,    71,   156,  -137,   191,   147,
    -137,   157,  -137,   167,   171,  -137,  -137,   545,   427,   203,
     191,  -137,   174,   545,   168,    15,   173,   190,   191,   138,
     192,   193,   440,  -137,  -137,   461,   189,   106,  -137,   427,
     545,   482,    75,  -137,    92,   191,   191,   298,   195,   111,
     191,   191,  -137,   503,   197,  -137,  -137,   191,   230,   524,
    -137,    26,   321,   341,  -137,   198,   364,   384,  -137,  -137,
     407,  -137,  -137,   545,   545,   147,   196,   208,  -137,   209,
    -137,  -137,  -137,   545,  -137
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,     0,     0,    31,     0,     1,     2,     0,     0,    30,
       0,    41,     0,     0,     0,     0,    40,    34,     0,    37,
       0,     0,    65,    66,    67,     0,    33,     0,    62,     0,
      49,     0,     0,    64,     0,     0,    32,    35,    36,     0,
      49,    63,     0,     0,     0,    26,    27,    85,     0,     0,
       0,     0,    18,    19,     0,    84,     0,     0,     0,    20,
      21,     0,     0,     0,     0,     0,     0,    49,    43,     0,
      48,     0,    86,    16,    17,     0,     0,     0,     0,     0,
      15,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    81,     0,     0,    51,     0,    83,     0,     0,
      57,    49,    42,     0,     0,    47,     0,     0,    24,    89,
      90,    25,     0,     5,     6,     7,     8,     9,    10,     3,
       4,    11,    12,    13,    14,    54,     0,    50,    87,    22,
      82,    57,     0,    56,     0,     0,     0,    45,     0,    23,
      28,    52,    80,     0,     0,    61,    44,     0,    46,     0,
       0,    53,     0,     0,    58,    85,     0,     0,     0,     0,
       0,     0,     0,    68,    79,     0,     0,     0,    88,    55,
       0,     0,     0,    60,    86,     0,     0,     0,     0,     0,
       0,     0,    70,     0,     0,    78,    77,     0,     0,     0,
      38,     0,     0,     0,    76,     0,     0,     0,    69,    29,
       0,    39,    59,     0,     0,     0,     0,     0,    75,     0,
      72,    73,    74,     0,    71
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -137,  -137,   -42,  -137,  -137,  -137,  -137,  -137,  -137,  -137,
    -137,   233,  -137,   -31,  -137,  -137,  -137,  -137,   123,  -137,
    -137,  -137,   -25,   -46,   -82,  -136,   -86,   -44,   -19,   -84
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     2,    58,     3,     6,     9,    19,    25,    37,    38,
      14,   163,    70,    44,   126,   127,   141,   151,   132,   133,
     173,   154,    27,    28,   164,   165,    59,    32,    41,    60
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_uint8 yytable[] =
{
      39,    67,    33,    72,    77,    95,    73,    74,   128,    65,
      62,     1,    79,    96,    80,    33,   107,   171,    31,    98,
      30,     4,   101,    40,    63,    76,   183,    99,    68,    69,
     145,   202,   108,   109,   189,   129,   104,   102,    69,   112,
     113,   114,   115,   116,   117,   118,   119,   120,   121,   122,
       5,   123,   124,   125,     8,    31,    33,     7,    31,    31,
      21,   166,    31,   167,    98,    31,    31,   166,    10,   167,
     135,    13,    22,    23,    24,   134,   166,    11,   167,   166,
      34,   167,    12,   185,   166,   166,   167,   167,    15,   185,
      90,    91,    22,    23,    24,    16,   148,   166,    17,   167,
      18,   185,    20,   166,    29,   167,   134,   185,   169,   137,
      69,   174,    75,   179,   146,    69,   177,   166,   166,   167,
     167,   209,   210,    42,    22,    23,    24,   166,    66,   167,
      43,   214,    61,   192,   193,   109,    33,    31,   196,   197,
      45,    46,    47,   178,    95,   200,    64,   191,   187,    48,
      49,    71,   188,    81,    78,    22,    23,    24,   100,    34,
      50,    51,    52,    53,   103,   105,   106,    45,    46,    47,
     110,    22,    23,    24,   131,    54,    48,    49,    55,   136,
     139,   138,    56,   142,   144,    35,    57,    50,    51,    52,
      53,    36,   147,   149,    45,    46,    47,    88,    89,    90,
      91,   150,    54,    48,    49,    97,   152,   153,   168,    56,
     170,   175,   172,    57,    50,    51,    52,    53,    82,    83,
      84,    85,    86,    87,    88,    89,    90,    91,   176,    54,
     180,   181,   186,   195,   199,   128,    56,   205,   213,   211,
      57,    82,    83,    84,    85,    86,    87,    88,    89,    90,
      91,   212,    26,    92,   143,     0,     0,     0,     0,    93,
      94,    82,    83,    84,    85,    86,    87,    88,    89,    90,
      91,     0,     0,     0,   111,     0,     0,     0,     0,     0,
       0,     0,    93,    94,    82,    83,    84,    85,    86,    87,
      88,    89,    90,    91,     0,     0,   130,     0,     0,     0,
       0,     0,    93,    94,    82,    83,    84,    85,    86,    87,
      88,    89,    90,    91,     0,     0,     0,   140,     0,     0,
       0,     0,     0,     0,     0,    93,    94,    82,    83,    84,
      85,    86,    87,    88,    89,    90,    91,     0,     0,     0,
       0,   194,     0,     0,     0,    93,    94,    82,    83,    84,
      85,    86,    87,    88,    89,    90,    91,     0,     0,     0,
     203,     0,     0,     0,     0,     0,     0,     0,    93,    94,
      82,    83,    84,    85,    86,    87,    88,    89,    90,    91,
     204,     0,     0,     0,     0,     0,     0,     0,    93,    94,
      82,    83,    84,    85,    86,    87,    88,    89,    90,    91,
       0,     0,     0,   206,     0,     0,     0,     0,     0,     0,
       0,    93,    94,    82,    83,    84,    85,    86,    87,    88,
      89,    90,    91,   207,     0,     0,     0,     0,     0,     0,
       0,    93,    94,    82,    83,    84,    85,    86,    87,    88,
      89,    90,    91,     0,     0,   155,     0,     0,     0,     0,
     208,     0,     0,     0,    93,    94,     0,    22,    23,    24,
     156,   157,   158,   159,    51,     0,   155,   160,   161,     0,
       0,     0,     0,     0,    93,    94,   162,   182,    22,    23,
      24,   156,   157,   158,   159,    51,     0,   155,   160,   161,
       0,     0,     0,     0,     0,     0,     0,   162,   184,    22,
      23,    24,   156,   157,   158,   159,    51,     0,   155,   160,
     161,     0,     0,     0,     0,     0,     0,     0,   162,   190,
      22,    23,    24,   156,   157,   158,   159,    51,     0,   155,
     160,   161,     0,     0,     0,     0,     0,     0,     0,   162,
     198,    22,    23,    24,   156,   157,   158,   159,    51,     0,
     155,   160,   161,     0,     0,     0,     0,     0,     0,     0,
     162,   201,    22,    23,    24,   156,   157,   158,   159,    51,
       0,     0,   160,   161,     0,     0,     0,     0,     0,     0,
       0,   162
};

static const yytype_int16 yycheck[] =
{
      25,    43,    21,    47,    50,    38,    48,    49,     5,    40,
      35,    16,    54,    46,    56,    34,    38,   153,    40,    61,
       5,     5,    64,     5,     5,    50,   162,     5,    43,    44,
       5,     5,    76,    77,   170,    32,    67,    43,    44,    81,
      82,    83,    84,    85,    86,    87,    88,    89,    90,    91,
       0,    93,    94,    95,    16,    40,    75,    36,    40,    40,
       5,   147,    40,   147,   106,    40,    40,   153,    31,   153,
     101,    30,    17,    18,    19,   100,   162,     5,   162,   165,
       5,   165,    33,   165,   170,   171,   170,   171,    34,   171,
      14,    15,    17,    18,    19,     5,   138,   183,    36,   183,
      35,   183,    38,   189,    18,   189,   131,   189,   150,    43,
      44,   155,     5,   159,    43,    44,   158,   203,   204,   203,
     204,   203,   204,    40,    17,    18,    19,   213,    41,   213,
      42,   213,    40,   175,   176,   179,   155,    40,   180,   181,
       3,     4,     5,     5,    38,   187,    42,   172,    42,    12,
      13,    40,    46,    38,    46,    17,    18,    19,    38,     5,
      23,    24,    25,    26,     5,     5,    40,     3,     4,     5,
       5,    17,    18,    19,    38,    38,    12,    13,    41,    39,
      39,    42,    45,    39,    39,    31,    49,    23,    24,    25,
      26,    37,    36,    46,     3,     4,     5,    12,    13,    14,
      15,    44,    38,    12,    13,    41,    39,    36,     5,    45,
      36,    38,    44,    49,    23,    24,    25,    26,     6,     7,
       8,     9,    10,    11,    12,    13,    14,    15,    38,    38,
      38,    38,    43,    38,    37,     5,    45,    39,    29,    43,
      49,     6,     7,     8,     9,    10,    11,    12,    13,    14,
      15,    43,    19,    41,   131,    -1,    -1,    -1,    -1,    47,
      48,     6,     7,     8,     9,    10,    11,    12,    13,    14,
      15,    -1,    -1,    -1,    39,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    47,    48,     6,     7,     8,     9,    10,    11,
      12,    13,    14,    15,    -1,    -1,    41,    -1,    -1,    -1,
      -1,    -1,    47,    48,     6,     7,     8,     9,    10,    11,
      12,    13,    14,    15,    -1,    -1,    -1,    39,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    47,    48,     6,     7,     8,
       9,    10,    11,    12,    13,    14,    15,    -1,    -1,    -1,
      -1,    43,    -1,    -1,    -1,    47,    48,     6,     7,     8,
       9,    10,    11,    12,    13,    14,    15,    -1,    -1,    -1,
      39,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    47,    48,
       6,     7,     8,     9,    10,    11,    12,    13,    14,    15,
      39,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    47,    48,
       6,     7,     8,     9,    10,    11,    12,    13,    14,    15,
      -1,    -1,    -1,    39,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    47,    48,     6,     7,     8,     9,    10,    11,    12,
      13,    14,    15,    39,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    47,    48,     6,     7,     8,     9,    10,    11,    12,
      13,    14,    15,    -1,    -1,     5,    -1,    -1,    -1,    -1,
      43,    -1,    -1,    -1,    47,    48,    -1,    17,    18,    19,
      20,    21,    22,    23,    24,    -1,     5,    27,    28,    -1,
      -1,    -1,    -1,    -1,    47,    48,    36,    37,    17,    18,
      19,    20,    21,    22,    23,    24,    -1,     5,    27,    28,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    36,    37,    17,
      18,    19,    20,    21,    22,    23,    24,    -1,     5,    27,
      28,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    36,    37,
      17,    18,    19,    20,    21,    22,    23,    24,    -1,     5,
      27,    28,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    36,
      37,    17,    18,    19,    20,    21,    22,    23,    24,    -1,
       5,    27,    28,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      36,    37,    17,    18,    19,    20,    21,    22,    23,    24,
      -1,    -1,    27,    28,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    36
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,    16,    51,    53,     5,     0,    54,    36,    16,    55,
      31,     5,    33,    30,    60,    34,     5,    36,    35,    56,
      38,     5,    17,    18,    19,    57,    61,    72,    73,    18,
       5,    40,    77,    78,     5,    31,    37,    58,    59,    72,
       5,    78,    40,    42,    63,     3,     4,     5,    12,    13,
      23,    24,    25,    26,    38,    41,    45,    49,    52,    76,
      79,    40,    72,     5,    42,    63,    41,    52,    43,    44,
      62,    40,    77,    52,    52,     5,    72,    73,    46,    52,
      52,    38,     6,     7,     8,     9,    10,    11,    12,    13,
      14,    15,    41,    47,    48,    38,    46,    41,    52,     5,
      38,    52,    43,     5,    63,     5,    40,    38,    77,    77,
       5,    39,    52,    52,    52,    52,    52,    52,    52,    52,
      52,    52,    52,    52,    52,    52,    64,    65,     5,    32,
      41,    38,    68,    69,    72,    63,    39,    43,    42,    39,
      39,    66,    39,    68,    39,     5,    43,    36,    52,    46,
      44,    67,    39,    36,    71,     5,    20,    21,    22,    23,
      27,    28,    36,    61,    74,    75,    76,    79,     5,    52,
      36,    75,    44,    70,    77,    38,    38,    52,     5,    73,
      38,    38,    37,    75,    37,    74,    43,    42,    46,    75,
      37,    72,    52,    52,    43,    38,    52,    52,    37,    37,
      52,    37,     5,    39,    39,    39,    39,    39,    43,    74,
      74,    43,    43,    29,    74
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    50,    51,    52,    52,    52,    52,    52,    52,    52,
      52,    52,    52,    52,    52,    52,    52,    52,    52,    52,
      52,    52,    52,    52,    52,    52,    52,    52,    52,    53,
      54,    54,    55,    56,    56,    57,    57,    57,    58,    59,
      60,    60,    61,    61,    61,    61,    62,    62,    63,    63,
      64,    64,    65,    66,    66,    67,    68,    68,    69,    70,
      71,    71,    72,    72,    72,    73,    73,    73,    74,    74,
      74,    74,    74,    74,    74,    74,    74,    74,    75,    75,
      76,    77,    77,    78,    78,    79,    79,    79,    79,    79,
      79
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     2,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     3,     2,     2,     2,     1,     1,
       1,     1,     3,     4,     3,     3,     1,     1,     4,    17,
       2,     0,     7,     2,     0,     2,     2,     0,     8,     9,
       2,     0,     4,     4,     6,     6,     4,     2,     2,     0,
       1,     0,     2,     2,     0,     2,     1,     0,     3,     3,
       2,     0,     1,     2,     2,     1,     1,     1,     1,     3,
       2,     7,     5,     5,     5,     4,     3,     2,     2,     1,
       4,     3,     4,     3,     2,     1,     2,     3,     6,     3,
       3
};


#define yyerrok         (yyerrstatus = 0)
#define yyclearin       (yychar = YYEMPTY)
#define YYEMPTY         (-2)
#define YYEOF           0

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab


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
      YYERROR;                                                  \
    }                                                           \
while (0)

/* Error token number */
#define YYTERROR        1
#define YYERRCODE       256



/* Enable debugging if requested.  */
#if YYDEBUG

# ifndef YYFPRINTF
#  include <stdio.h> /* INFRINGES ON USER NAME SPACE */
#  define YYFPRINTF fprintf
# endif

# define YYDPRINTF(Args)                        \
do {                                            \
  if (yydebug)                                  \
    YYFPRINTF Args;                             \
} while (0)

/* This macro is provided for backward compatibility. */
#ifndef YY_LOCATION_PRINT
# define YY_LOCATION_PRINT(File, Loc) ((void) 0)
#endif


# define YY_SYMBOL_PRINT(Title, Type, Value, Location)                    \
do {                                                                      \
  if (yydebug)                                                            \
    {                                                                     \
      YYFPRINTF (stderr, "%s ", Title);                                   \
      yy_symbol_print (stderr,                                            \
                  Type, Value); \
      YYFPRINTF (stderr, "\n");                                           \
    }                                                                     \
} while (0)


/*----------------------------------------.
| Print this symbol's value on YYOUTPUT.  |
`----------------------------------------*/

static void
yy_symbol_value_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
{
  FILE *yyo = yyoutput;
  YYUSE (yyo);
  if (!yyvaluep)
    return;
# ifdef YYPRINT
  if (yytype < YYNTOKENS)
    YYPRINT (yyoutput, yytoknum[yytype], *yyvaluep);
# endif
  YYUSE (yytype);
}


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

static void
yy_symbol_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
{
  YYFPRINTF (yyoutput, "%s %s (",
             yytype < YYNTOKENS ? "token" : "nterm", yytname[yytype]);

  yy_symbol_value_print (yyoutput, yytype, yyvaluep);
  YYFPRINTF (yyoutput, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

static void
yy_stack_print (yytype_int16 *yybottom, yytype_int16 *yytop)
{
  YYFPRINTF (stderr, "Stack now");
  for (; yybottom <= yytop; yybottom++)
    {
      int yybot = *yybottom;
      YYFPRINTF (stderr, " %d", yybot);
    }
  YYFPRINTF (stderr, "\n");
}

# define YY_STACK_PRINT(Bottom, Top)                            \
do {                                                            \
  if (yydebug)                                                  \
    yy_stack_print ((Bottom), (Top));                           \
} while (0)


/*------------------------------------------------.
| Report that the YYRULE is going to be reduced.  |
`------------------------------------------------*/

static void
yy_reduce_print (yytype_int16 *yyssp, YYSTYPE *yyvsp, int yyrule)
{
  unsigned long int yylno = yyrline[yyrule];
  int yynrhs = yyr2[yyrule];
  int yyi;
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %lu):\n",
             yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr,
                       yystos[yyssp[yyi + 1 - yynrhs]],
                       &(yyvsp[(yyi + 1) - (yynrhs)])
                                              );
      YYFPRINTF (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)          \
do {                                    \
  if (yydebug)                          \
    yy_reduce_print (yyssp, yyvsp, Rule); \
} while (0)

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
#ifndef YYINITDEPTH
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
static YYSIZE_T
yystrlen (const char *yystr)
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
static char *
yystpcpy (char *yydest, const char *yysrc)
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
  YYSIZE_T yysize0 = yytnamerr (YY_NULLPTR, yytname[yytoken]);
  YYSIZE_T yysize = yysize0;
  enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
  /* Internationalized format string. */
  const char *yyformat = YY_NULLPTR;
  /* Arguments of yyformat. */
  char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];
  /* Number of reported tokens (one for the "unexpected", one per
     "expected"). */
  int yycount = 0;

  /* There are many possibilities here to consider:
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
                  YYSIZE_T yysize1 = yysize + yytnamerr (YY_NULLPTR, yytname[yyx]);
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

static void
yydestruct (const char *yymsg, int yytype, YYSTYPE *yyvaluep)
{
  YYUSE (yyvaluep);
  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yytype, yyvaluep, yylocationp);

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YYUSE (yytype);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}




/* The lookahead symbol.  */
int yychar;

/* The semantic value of the lookahead symbol.  */
YYSTYPE yylval;
/* Number of syntax errors so far.  */
int yynerrs;


/*----------.
| yyparse.  |
`----------*/

int
yyparse (void)
{
    int yystate;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus;

    /* The stacks and their tools:
       'yyss': related to states.
       'yyvs': related to semantic values.

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
      yychar = yylex ();
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
     '$$ = $1'.

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
#line 131 "parser.y" /* yacc.c:1646  */
    {
        program_t * cur_prog = (program_t *) malloc(sizeof(program_t));
	cur_prog->main_class = (yyvsp[-1].class);
	cur_prog->class_list = (yyvsp[0].class_list);
	program = cur_prog;
}
#line 1616 "y.tab.c" /* yacc.c:1646  */
    break;

  case 3:
#line 140 "parser.y" /* yacc.c:1646  */
    {
	  	  struct exp_node * add_node = create_exp_node(ADD, (yyvsp[-2].exp_node), (yyvsp[0].exp_node));
		  add_node->type = (yyvsp[-2].exp_node)->type;
		  add_node->line_num = yylineno;
	  	  (yyval.exp_node) = add_node;

	}
#line 1628 "y.tab.c" /* yacc.c:1646  */
    break;

  case 4:
#line 148 "parser.y" /* yacc.c:1646  */
    {
	  	  struct exp_node * sub_node = create_exp_node(SUB, (yyvsp[-2].exp_node), (yyvsp[0].exp_node));
		  sub_node->type = (yyvsp[-2].exp_node)->type;
		  sub_node->line_num = yylineno;
		  (yyval.exp_node) = sub_node;

	}
#line 1640 "y.tab.c" /* yacc.c:1646  */
    break;

  case 5:
#line 156 "parser.y" /* yacc.c:1646  */
    {

 	 	  struct exp_node * node = create_exp_node(AND, (yyvsp[-2].exp_node), (yyvsp[0].exp_node));
		  node->type = (yyvsp[-2].exp_node)->type;
		  node->line_num = yylineno;
	  	  (yyval.exp_node) = node;
	}
#line 1652 "y.tab.c" /* yacc.c:1646  */
    break;

  case 6:
#line 164 "parser.y" /* yacc.c:1646  */
    {

 	 	  struct exp_node * node = create_exp_node(OR, (yyvsp[-2].exp_node), (yyvsp[0].exp_node));
		  node->line_num = yylineno;
		  node->type = (yyvsp[-2].exp_node)->type;
	  	  (yyval.exp_node) = node;
	}
#line 1664 "y.tab.c" /* yacc.c:1646  */
    break;

  case 7:
#line 172 "parser.y" /* yacc.c:1646  */
    {
 	 	  struct exp_node * node = create_exp_node(SME, (yyvsp[-2].exp_node), (yyvsp[0].exp_node));
		  node->line_num = yylineno;
		  node->type = (yyvsp[-2].exp_node)->type;
	  	  (yyval.exp_node) = node;
	}
#line 1675 "y.tab.c" /* yacc.c:1646  */
    break;

  case 8:
#line 179 "parser.y" /* yacc.c:1646  */
    {

 	 	  struct exp_node * node = create_exp_node(LRE, (yyvsp[-2].exp_node), (yyvsp[0].exp_node));
		  node->line_num = yylineno;
		  node->type = (yyvsp[-2].exp_node)->type;
	  	  (yyval.exp_node) = node;
	}
#line 1687 "y.tab.c" /* yacc.c:1646  */
    break;

  case 9:
#line 187 "parser.y" /* yacc.c:1646  */
    {

 	 	  struct exp_node * node = create_exp_node(EQU, (yyvsp[-2].exp_node), (yyvsp[0].exp_node));
		  node->type = (yyvsp[-2].exp_node)->type;
		  node->line_num = yylineno;
	  	  (yyval.exp_node) = node;
	}
#line 1699 "y.tab.c" /* yacc.c:1646  */
    break;

  case 10:
#line 195 "parser.y" /* yacc.c:1646  */
    {

 	 	  struct exp_node * node = create_exp_node(NEQ, (yyvsp[-2].exp_node), (yyvsp[0].exp_node));
		  node->type = (yyvsp[-2].exp_node)->type;
		  node->line_num = yylineno;
	  	  (yyval.exp_node) = node;
	}
#line 1711 "y.tab.c" /* yacc.c:1646  */
    break;

  case 11:
#line 203 "parser.y" /* yacc.c:1646  */
    {
		  struct exp_node * mult_node = create_exp_node(MUL, (yyvsp[-2].exp_node), (yyvsp[0].exp_node));
		  mult_node->type = (yyvsp[-2].exp_node)->type;
		  mult_node->line_num = yylineno;
		  (yyval.exp_node) = mult_node;

	}
#line 1723 "y.tab.c" /* yacc.c:1646  */
    break;

  case 12:
#line 211 "parser.y" /* yacc.c:1646  */
    {	
	  	  struct exp_node * div_node = create_exp_node(DIV, (yyvsp[-2].exp_node), (yyvsp[0].exp_node));
		  div_node->line_num = yylineno;
	          div_node->type = (yyvsp[-2].exp_node)->type;
	          (yyval.exp_node) = div_node;

	}
#line 1735 "y.tab.c" /* yacc.c:1646  */
    break;

  case 13:
#line 219 "parser.y" /* yacc.c:1646  */
    {
		  struct exp_node * node = create_exp_node(LE, (yyvsp[-2].exp_node), (yyvsp[0].exp_node));
		  node->type = BOOL;
		  node->line_num = yylineno;
		  (yyval.exp_node) = node;
	}
#line 1746 "y.tab.c" /* yacc.c:1646  */
    break;

  case 14:
#line 226 "parser.y" /* yacc.c:1646  */
    {
		  struct exp_node * node = create_exp_node(GR, (yyvsp[-2].exp_node), (yyvsp[0].exp_node));
		  node->type = BOOL;
		  node->line_num = yylineno;
		  (yyval.exp_node) = node;
	}
#line 1757 "y.tab.c" /* yacc.c:1646  */
    break;

  case 15:
#line 233 "parser.y" /* yacc.c:1646  */
    {
		  struct exp_node * node = create_exp_node(NGT, (yyvsp[0].exp_node), NULL);
		  node->type = BOOL;
		  node->line_num = yylineno;
		  (yyval.exp_node) = node;
	}
#line 1768 "y.tab.c" /* yacc.c:1646  */
    break;

  case 16:
#line 240 "parser.y" /* yacc.c:1646  */
    {
		  struct exp_node * node = create_exp_node(PLU, (yyvsp[0].exp_node), NULL);
		  node->type = (yyvsp[0].exp_node)->type;
		  node->line_num = yylineno;
		  (yyval.exp_node) = node;
	}
#line 1779 "y.tab.c" /* yacc.c:1646  */
    break;

  case 17:
#line 247 "parser.y" /* yacc.c:1646  */
    {
		  struct exp_node * node = create_exp_node(MIN, (yyvsp[0].exp_node), NULL);
		  node->type = (yyvsp[0].exp_node)->type;
		  node->line_num = yylineno;
		  (yyval.exp_node) = node;
	}
#line 1790 "y.tab.c" /* yacc.c:1646  */
    break;

  case 18:
#line 254 "parser.y" /* yacc.c:1646  */
    {	
		struct exp_node * leaf = create_bool_leaf(1);
		leaf->line_num = yylineno;
		(yyval.exp_node) = leaf;
	}
#line 1800 "y.tab.c" /* yacc.c:1646  */
    break;

  case 19:
#line 260 "parser.y" /* yacc.c:1646  */
    {	
		struct exp_node * leaf = create_bool_leaf(0);
		leaf->line_num = yylineno;
		(yyval.exp_node) = leaf;
	}
#line 1810 "y.tab.c" /* yacc.c:1646  */
    break;

  case 20:
#line 266 "parser.y" /* yacc.c:1646  */
    {	
		(yyval.exp_node) = (yyvsp[0].exp_node);
	}
#line 1818 "y.tab.c" /* yacc.c:1646  */
    break;

  case 21:
#line 270 "parser.y" /* yacc.c:1646  */
    {
		(yyval.exp_node) = (yyvsp[0].exp_node);
	}
#line 1826 "y.tab.c" /* yacc.c:1646  */
    break;

  case 22:
#line 274 "parser.y" /* yacc.c:1646  */
    {
		/*if(!$1->is_array)
		{ 
			ERROR; 
		}
		else
		{*/
		/* TODO: Edit here to have a exp node with int type.
		    struct exp_node * node = create_exp_node(GR, $1, $3);
		    node->type = $1->type;
		    $$ = node;
		  */
		//}
	}
#line 1845 "y.tab.c" /* yacc.c:1646  */
    break;

  case 23:
#line 289 "parser.y" /* yacc.c:1646  */
    {
		//The constructor should be called, so this a method.
		struct exp_node * node = (struct exp_node *) malloc(sizeof(struct exp_node));
		node->type = CLASS;
		node->associated_class = (yyvsp[-2].string_val);
		node->is_constructed = 1; //Has new operator.
		node->is_array = 0;
		node->is_array_entry = 0;
		node->is_id = 0;
		node->is_leaf = 1;
		node->is_method = 0;
		node->is_property = 0; 
		node->line_num = yylineno;
		(yyval.exp_node) = node;
				
	}
#line 1866 "y.tab.c" /* yacc.c:1646  */
    break;

  case 25:
#line 307 "parser.y" /* yacc.c:1646  */
    {
		(yyval.exp_node) = (yyvsp[-1].exp_node);
	}
#line 1874 "y.tab.c" /* yacc.c:1646  */
    break;

  case 26:
#line 311 "parser.y" /* yacc.c:1646  */
    {
		char * str = (yyvsp[0].string_val);
		int len = strlen(str);
		char * result = (char *) malloc((len-1) * sizeof(char));
		strncpy(result, &str[1], len-2);
		result[len-2] = 0;
	   
	  struct exp_node * leaf = create_string_leaf(result);
	  leaf->line_num = yylineno;
	  (yyval.exp_node) = leaf;		
	}
#line 1890 "y.tab.c" /* yacc.c:1646  */
    break;

  case 27:
#line 323 "parser.y" /* yacc.c:1646  */
    {
	  int * result = (int *) malloc(sizeof(int));
	  *result = (yyvsp[0].integer_val);	
	  struct exp_node * leaf = create_int_leaf(result);
	  leaf->line_num = yylineno;
	  (yyval.exp_node) = leaf;
	}
#line 1902 "y.tab.c" /* yacc.c:1646  */
    break;

  case 28:
#line 331 "parser.y" /* yacc.c:1646  */
    {
/*		switch($3.type)
		{
			case INT: 
				$$.value = $3.value;
				$$.type =  INT;
				break;
			case STR:
				$$.value = atoi(extractString($3.text));
				$$.type = INT;
				break;
		}*/
	}
#line 1920 "y.tab.c" /* yacc.c:1646  */
    break;

  case 29:
#line 348 "parser.y" /* yacc.c:1646  */
    {
		class_t * cl = (class_t *) malloc(sizeof(class_t));
		scope_t * class_scope = (scope_t *) malloc(sizeof(scope_t));
		class_scope->name_table = (LinkedList *) malloc(sizeof(LinkedList));
		class_scope->parent = NULL;
		scope_t * main_scope = (scope_t *) malloc(sizeof(scope_t));	
  		LinkedList * main_name_table = (LinkedList *) malloc(sizeof(LinkedList));
		llist_init(main_name_table);
		main_scope->name_table = main_name_table;
		main_scope->parent = class_scope;
		method_t * main_method = (method_t *) malloc(sizeof(method_t));
		main_method->statement = (yyvsp[-2].stmt_node); 
		main_method->statement->scope = main_scope;
		main_args_name = (yyvsp[-5].string_val);
		add_var_to_table(main_scope->name_table, main_args_name, STR, NULL);
		update_scope_hierarchy(main_method->statement);
		//method_list_t * method_list = (method_list_t *) malloc(sizeof(method_list_t));
		add_var_to_table(class_scope->name_table, "main", UNDEF, main_method); 
		//method_list->head = main_method;
		cl->scope = class_scope;
		(yyval.class) = cl;
	    }
#line 1947 "y.tab.c" /* yacc.c:1646  */
    break;

  case 30:
#line 375 "parser.y" /* yacc.c:1646  */
    {
		if((yyvsp[-1].class_list) == NULL)
		{
			class_list_t * list = (class_list_t *) malloc(sizeof(class_list_t));
			list->head = (yyvsp[0].class);
			(yyval.class_list) = list;
		}
		else
		{
			class_t * it = (yyvsp[-1].class_list)->head;
			while(it->next){ it = it->next; }
                 	it->next = (yyvsp[0].class);
		 	(yyval.class_list) = (yyvsp[-1].class_list);
		}
	}
#line 1967 "y.tab.c" /* yacc.c:1646  */
    break;

  case 31:
#line 391 "parser.y" /* yacc.c:1646  */
    {
		(yyval.class_list) = NULL;
	}
#line 1975 "y.tab.c" /* yacc.c:1646  */
    break;

  case 32:
#line 396 "parser.y" /* yacc.c:1646  */
    {
	//No inheritance.
	if((yyvsp[-4].string_val) == NULL)
	{
		class_t * cl = (class_t *) malloc(sizeof(class_t));
		scope_t * cl_scope = (scope_t *) malloc(sizeof(scope_t));	
  		LinkedList * name_table = (LinkedList *) malloc(sizeof(LinkedList));
  		llist_init(name_table);
		cl_scope->parent = NULL;
		cl_scope->name_table = name_table;
		if((yyvsp[-2].vardecllist) != NULL)
		{
			struct var_decl_t * it_var = (yyvsp[-2].vardecllist)->id_list;
			while(it_var)
			{
				ListNode * node = (ListNode *) malloc(sizeof(ListNode));
				node->value = it_var->id;
				//Determine value before adding to symbol table.
				//traverse(it_var->value);
				node->type = it_var->type;
				node->class_id = (yyvsp[-2].vardecllist)->class_id;
				node->symbol_type = PROPERTY;
				add_node_to_table(cl_scope->name_table, node);
				it_var = it_var->next;
			}

		}

		//Add every method to the name table of the class.
		if((yyvsp[-1].method_list) != NULL)
		{
			method_t * it = (yyvsp[-1].method_list)->head;
			while(it)
			{
				ListNode * node = (ListNode *) malloc(sizeof(ListNode));
				node->value = it->id;
				//node->real_value = it;
				node->symbol_type = METHOD;
				node->type = it->type->type;
				node->class_id = it->type->class_id;
				add_node_to_table(cl_scope->name_table, node);
				//Update parent scope.
				it->statement->scope->parent = cl_scope;
				it = it->next;
			}

		}


		//cl->methods = $6;
		//cl->properties = $5;
		cl->scope = cl_scope;
		cl->id = (yyvsp[-5].string_val);
		(yyval.class) = cl;
	}
	else
	{
		printf("Inheritance: to be implemented");
	}
}
#line 2040 "y.tab.c" /* yacc.c:1646  */
    break;

  case 33:
#line 459 "parser.y" /* yacc.c:1646  */
    {
		if((yyvsp[-1].vardecllist) == NULL)
		{
			struct var_decl_list_t * list = (struct var_decl_list_t *) malloc(sizeof(struct var_decl_list_t));
			list->type = (type_info_t *) malloc(sizeof(type_info_t));
			list->type = (yyvsp[0].vardecllist)->type;
			list->id_list = (yyvsp[0].vardecllist)->id_list;
			(yyval.vardecllist) = list;
		}
		else
		{
			struct var_decl_t * it = (yyvsp[-1].vardecllist)->id_list;
			while(it->next)
			{
				it = it->next;
			}
			it->next = (yyvsp[0].vardecllist)->id_list;
			(yyval.vardecllist) = (yyvsp[-1].vardecllist);
		}
	}
#line 2065 "y.tab.c" /* yacc.c:1646  */
    break;

  case 34:
#line 479 "parser.y" /* yacc.c:1646  */
    { (yyval.vardecllist) = NULL; }
#line 2071 "y.tab.c" /* yacc.c:1646  */
    break;

  case 35:
#line 483 "parser.y" /* yacc.c:1646  */
    {
		if((yyvsp[-1].method_list) == NULL)
		{
		  method_list_t * list = (method_list_t *) malloc(sizeof(method_list_t));
		  list->head = (yyvsp[0].method);
		  (yyval.method_list) = list;
		}
		else
		{
		  method_t * it = (yyvsp[-1].method_list)->head;
		  while(it->next){ it = it->next; }
                  it->next = (yyvsp[0].method);
		  (yyval.method_list) = (yyvsp[-1].method_list);
		}
	}
#line 2091 "y.tab.c" /* yacc.c:1646  */
    break;

  case 36:
#line 499 "parser.y" /* yacc.c:1646  */
    {
		if((yyvsp[-1].method_list) == NULL)
		{
		  method_list_t * list = (method_list_t *) malloc(sizeof(method_list_t));
		  list->head = (yyvsp[0].method);
		  (yyval.method_list) = list;
		}
		else
		{
		  method_list_t * ac_list = (yyvsp[-1].method_list);
		  method_t * it = ac_list->head; 
		  while(it->next){ it = it->next; }
                  it->next = (yyvsp[0].method);
		  (yyval.method_list) = (yyvsp[-1].method_list);
		}

	}
#line 2113 "y.tab.c" /* yacc.c:1646  */
    break;

  case 37:
#line 516 "parser.y" /* yacc.c:1646  */
    {(yyval.method_list) = NULL;}
#line 2119 "y.tab.c" /* yacc.c:1646  */
    break;

  case 38:
#line 519 "parser.y" /* yacc.c:1646  */
    {
  method_t * method = (method_t*) malloc(sizeof(method_t));	
  scope_t * method_scope = (scope_t *) malloc(sizeof(scope_t));	
  method_scope->name_table = (LinkedList *) malloc(sizeof(LinkedList));
  method->type = (yyvsp[-7].type);
  method->id = (yyvsp[-6].string_val);
  method->arg_list = (yyvsp[-4].arg_list);
  method->statement = (yyvsp[-1].stmt_node);
  method->statement->scope = method_scope;
  update_scope_hierarchy((yyvsp[-1].stmt_node));
  (yyval.method) = method;
}
#line 2136 "y.tab.c" /* yacc.c:1646  */
    break;

  case 39:
#line 533 "parser.y" /* yacc.c:1646  */
    {
  method_t * method = (method_t*) malloc(sizeof(method_t));
  scope_t * method_scope = (scope_t *) malloc(sizeof(scope_t));	
  method_scope->name_table = (LinkedList *) malloc(sizeof(LinkedList));
  method->type = (yyvsp[-7].type);
  method->id = (yyvsp[-6].string_val);
  method->arg_list = (yyvsp[-4].arg_list);
  method->statement = (yyvsp[-1].stmt_node);
  method->statement->scope = method_scope;
  update_scope_hierarchy((yyvsp[-1].stmt_node));
  (yyval.method) = method;
}
#line 2153 "y.tab.c" /* yacc.c:1646  */
    break;

  case 40:
#line 548 "parser.y" /* yacc.c:1646  */
    {
		(yyval.string_val) = (yyvsp[0].string_val);
	}
#line 2161 "y.tab.c" /* yacc.c:1646  */
    break;

  case 41:
#line 552 "parser.y" /* yacc.c:1646  */
    {
		(yyval.string_val) = NULL;
	}
#line 2169 "y.tab.c" /* yacc.c:1646  */
    break;

  case 42:
#line 557 "parser.y" /* yacc.c:1646  */
    {
	        struct var_decl_list_t * list = (struct var_decl_list_t *) malloc(sizeof(struct var_decl_list_t)); 
		list->type = (yyvsp[-3].type);
		struct var_decl_t * var_decl = (struct var_decl_t *) malloc(sizeof(struct var_decl_t));
		var_decl->id = (yyvsp[-2].string_val);
		assert((yyvsp[-2].string_val) != NULL);
		var_decl->value = NULL;
		var_decl->line_num = yylineno;
		var_decl->type = (yyvsp[-3].type)->type;
		list->id_list = var_decl;
		if((yyvsp[-1].vardecllist) != NULL)
		{
		  var_decl->next = (yyvsp[-1].vardecllist)->id_list;
		}
		(yyval.vardecllist) = list;
	  }
#line 2190 "y.tab.c" /* yacc.c:1646  */
    break;

  case 43:
#line 574 "parser.y" /* yacc.c:1646  */
    {
	        struct var_decl_list_t * list = (struct var_decl_list_t *) malloc(sizeof(struct var_decl_list_t)); 
		list->type = malloc(sizeof(type_info_t));
		list->type->type = CLASS;
		list->type->class_id = (yyvsp[-3].string_val);
		list->type->dim_len = 0;
		struct var_decl_t * var_decl = (struct var_decl_t *) malloc(sizeof(struct var_decl_t));
		var_decl->id = (yyvsp[-2].string_val);
		var_decl->value = NULL;
		var_decl->line_num = yylineno;
		list->id_list = var_decl;
		if((yyvsp[-1].vardecllist) != NULL)
		{
		  var_decl->next = (yyvsp[-1].vardecllist)->id_list;
		}
		(yyval.vardecllist) = list;

          }
#line 2213 "y.tab.c" /* yacc.c:1646  */
    break;

  case 44:
#line 593 "parser.y" /* yacc.c:1646  */
    {
		//if($1->type != $4->type) ERROR;
	        struct var_decl_list_t * list = (struct var_decl_list_t *) malloc(sizeof(struct var_decl_list_t)); 
		list->type = (yyvsp[-5].type);
		struct var_decl_t * var_decl = (struct var_decl_t *) malloc(sizeof(struct var_decl_t));
		var_decl->id = (yyvsp[-4].string_val);
		assert((yyvsp[-4].string_val) != NULL);

		var_decl->line_num = yylineno;
		
		var_decl->value = (yyvsp[-2].exp_node);
		var_decl->type = (yyvsp[-5].type)->type;
		list->id_list = var_decl;
		if((yyvsp[-1].vardecllist) != NULL)
		{
		  var_decl->next = (yyvsp[-1].vardecllist)->id_list;
		}

		(yyval.vardecllist) = list;
		

	  }
#line 2240 "y.tab.c" /* yacc.c:1646  */
    break;

  case 45:
#line 616 "parser.y" /* yacc.c:1646  */
    {
	        struct var_decl_list_t * list = (struct var_decl_list_t *) malloc(sizeof(struct var_decl_list_t)); 
		list->type = malloc(sizeof(type_info_t));
		list->type->type = CLASS;
		list->type->class_id = (yyvsp[-5].string_val);
		list->type->dim_len = 0;
		struct var_decl_t * var_decl = (struct var_decl_t *) malloc(sizeof(struct var_decl_t));
		var_decl->id = (yyvsp[-4].string_val);
		var_decl->value = (yyvsp[-2].exp_node);
		var_decl->line_num = yylineno;
		list->id_list = var_decl;
		if((yyvsp[-1].vardecllist) != NULL)
		{
		  var_decl->next = (yyvsp[-1].vardecllist)->id_list;
		}
		(yyval.vardecllist) = list;
 
	  }
#line 2263 "y.tab.c" /* yacc.c:1646  */
    break;

  case 46:
#line 639 "parser.y" /* yacc.c:1646  */
    { 
			struct var_decl_t * decl = (struct var_decl_t *) malloc(sizeof(struct var_decl_t));
			decl->id = (yyvsp[-2].string_val);
			decl->value = (yyvsp[0].exp_node);
			decl->line_num = yylineno;
			(yyval.var_decl) = decl; 
		}
#line 2275 "y.tab.c" /* yacc.c:1646  */
    break;

  case 47:
#line 647 "parser.y" /* yacc.c:1646  */
    { 
			struct var_decl_t * decl = (struct var_decl_t *) malloc(sizeof(struct var_decl_t));
			decl->id = (yyvsp[0].string_val);
			decl->line_num = yylineno;
			decl->value = NULL;
			(yyval.var_decl) = decl;
		}
#line 2287 "y.tab.c" /* yacc.c:1646  */
    break;

  case 48:
#line 658 "parser.y" /* yacc.c:1646  */
    {
		if((yyvsp[-1].vardecllist) == NULL)
		{
			struct var_decl_list_t * list = (struct var_decl_list_t *) malloc(sizeof(struct var_decl_list_t));
			list->id_list = (yyvsp[0].var_decl);
			(yyval.vardecllist) = list;	
		}
		else
		{
			struct var_decl_t * decl = (yyvsp[-1].vardecllist)->id_list;
			while(decl->next){decl = decl->next;}
			decl->next = (yyvsp[0].var_decl);
		}
	}
#line 2306 "y.tab.c" /* yacc.c:1646  */
    break;

  case 49:
#line 673 "parser.y" /* yacc.c:1646  */
    {
		(yyval.vardecllist) = NULL;
	}
#line 2314 "y.tab.c" /* yacc.c:1646  */
    break;

  case 50:
#line 681 "parser.y" /* yacc.c:1646  */
    {(yyval.exp_list) = (yyvsp[0].exp_list);}
#line 2320 "y.tab.c" /* yacc.c:1646  */
    break;

  case 51:
#line 683 "parser.y" /* yacc.c:1646  */
    { (yyval.exp_list) = NULL; }
#line 2326 "y.tab.c" /* yacc.c:1646  */
    break;

  case 52:
#line 687 "parser.y" /* yacc.c:1646  */
    {
	(yyvsp[-1].exp_node)->next = (yyvsp[0].exp_list)->head;
	exp_list_t * list = (exp_list_t *) malloc(sizeof(exp_list_t));
	list->head = (yyvsp[-1].exp_node);
	(yyval.exp_list) = list;
	
}
#line 2338 "y.tab.c" /* yacc.c:1646  */
    break;

  case 53:
#line 697 "parser.y" /* yacc.c:1646  */
    {
		if((yyvsp[-1].exp_list) == NULL)
		{
			exp_list_t * list = (exp_list_t *) malloc(sizeof(exp_list_t));
			list->head = (yyvsp[0].exp_node);
		}
		else
		{
			struct exp_node * it = (yyvsp[-1].exp_list)->head;
			while(it->next)
			{
				it=it->next;
			}
			it->next = (yyvsp[0].exp_node);
		}
	}
#line 2359 "y.tab.c" /* yacc.c:1646  */
    break;

  case 54:
#line 713 "parser.y" /* yacc.c:1646  */
    {(yyval.exp_list) = NULL;}
#line 2365 "y.tab.c" /* yacc.c:1646  */
    break;

  case 55:
#line 716 "parser.y" /* yacc.c:1646  */
    {
	(yyval.exp_node) = (yyvsp[0].exp_node);
}
#line 2373 "y.tab.c" /* yacc.c:1646  */
    break;

  case 56:
#line 720 "parser.y" /* yacc.c:1646  */
    {(yyval.arg_list) = (yyvsp[0].arg_list);}
#line 2379 "y.tab.c" /* yacc.c:1646  */
    break;

  case 57:
#line 720 "parser.y" /* yacc.c:1646  */
    {(yyval.arg_list) = NULL;}
#line 2385 "y.tab.c" /* yacc.c:1646  */
    break;

  case 58:
#line 723 "parser.y" /* yacc.c:1646  */
    {
	argument_t * arg = (argument_t *) malloc(sizeof(argument_t));
	arg->next = (yyvsp[0].arg_list)->head;
	argument_list_t * list = (argument_list_t *) malloc(sizeof(argument_list_t));
	list->head = arg;
	(yyval.arg_list) = list;
}
#line 2397 "y.tab.c" /* yacc.c:1646  */
    break;

  case 59:
#line 732 "parser.y" /* yacc.c:1646  */
    {
	argument_t * arg = (argument_t *) malloc(sizeof(argument_t));
	arg->type = (yyvsp[-1].type);
	arg->id = (yyvsp[0].string_val);
	(yyval.method_arg) = arg;	 
}
#line 2408 "y.tab.c" /* yacc.c:1646  */
    break;

  case 60:
#line 741 "parser.y" /* yacc.c:1646  */
    {
		if((yyvsp[-1].arg_list) == NULL)
		{
			argument_list_t * list = (argument_list_t *) malloc(sizeof(argument_list_t));
			list->head = (yyvsp[0].method_arg);
			(yyval.arg_list) = list; 
		}
		else
		{
			argument_t * it = (yyvsp[-1].arg_list)->head;
			while(it->next)
			{
				it = it->next;
			}
			it->next = (yyvsp[0].method_arg);
			(yyval.arg_list) = (yyvsp[-1].arg_list);
		}
	}
#line 2431 "y.tab.c" /* yacc.c:1646  */
    break;

  case 61:
#line 759 "parser.y" /* yacc.c:1646  */
    {(yyval.arg_list) = NULL;}
#line 2437 "y.tab.c" /* yacc.c:1646  */
    break;

  case 62:
#line 761 "parser.y" /* yacc.c:1646  */
    {(yyval.type) = (yyvsp[0].type);}
#line 2443 "y.tab.c" /* yacc.c:1646  */
    break;

  case 63:
#line 763 "parser.y" /* yacc.c:1646  */
    {
		type_info_t * type = (yyvsp[-1].type);
		assert((yyvsp[-1].type) != NULL);
		(yyvsp[-1].type)->dim_len++;
		(yyval.type) = (yyvsp[-1].type);
	}
#line 2454 "y.tab.c" /* yacc.c:1646  */
    break;

  case 64:
#line 770 "parser.y" /* yacc.c:1646  */
    {
		type_info_t * type = (type_info_t *) malloc(sizeof(type_info_t));
		type->type = CLASS;
		type->class_id = (yyvsp[-1].string_val);
		type->dim_len = (yyvsp[0].integer_val);
		(yyval.type) = type;
	}
#line 2466 "y.tab.c" /* yacc.c:1646  */
    break;

  case 65:
#line 781 "parser.y" /* yacc.c:1646  */
    {
		type_info_t * type = (type_info_t *) malloc(sizeof(type_info_t));
		type->type = INT;
		type->dim_len = 0;
		type->class_id = NULL;
		(yyval.type) = type;
	}
#line 2478 "y.tab.c" /* yacc.c:1646  */
    break;

  case 66:
#line 789 "parser.y" /* yacc.c:1646  */
    {
		type_info_t * type = (type_info_t *) malloc(sizeof(type_info_t));
		type->type = STR;
		type->class_id = NULL;
		type->dim_len = 0;
		(yyval.type) = type;
	}
#line 2490 "y.tab.c" /* yacc.c:1646  */
    break;

  case 67:
#line 797 "parser.y" /* yacc.c:1646  */
    {
		type_info_t * type = (type_info_t *) malloc(sizeof(type_info_t));
		type->type = BOOL;
		type->class_id = NULL;
		type->dim_len = 0;
		(yyval.type) = type;
	}
#line 2502 "y.tab.c" /* yacc.c:1646  */
    break;

  case 68:
#line 807 "parser.y" /* yacc.c:1646  */
    {
		exp_node_list_t * asgn_list = (exp_node_list_t*) malloc(sizeof(exp_node_list_t));
		elist_init(asgn_list);
		struct var_decl_t * var_it = (yyvsp[0].vardecllist)->id_list;
		type_info_t * var_type = (yyvsp[0].vardecllist)->type;
		while(var_it)
		{
		  struct exp_node * asgn_node = NULL; 

		  if(var_it->value != NULL)
		  {	
			  asgn_node = create_exp_node(ASGN, create_id_leaf(var_it->id), var_it->value);
		  }
		  else
	 	  {
			  asgn_node = create_exp_node(ASGN, create_id_leaf(var_it->id), NULL);
		  } 
		  asgn_node -> type = var_type->type;
		  asgn_node->line_num = var_it->line_num;
		  //Adding type of the variable in the id leaf if exists. 
		  if(asgn_node->data.left != NULL && asgn_node->data.left->is_id)
		  {
			asgn_node->data.left->type = var_type->type;
			asgn_node->data.left->line_num = var_it->line_num;
			if(var_type->type == CLASS)
			{
				asgn_node->data.left->associated_class = var_type->class_id;
			}

		  }
		  exp_node_link_t * link = (exp_node_link_t *) malloc(sizeof(exp_node_link_t));
		  link->current = asgn_node;
	 	  elist_add(asgn_list, link);
		  var_it = var_it->next;
		}
		stmt_node_t * stmt = (stmt_node_t *) malloc(sizeof(stmt_node_t));
		stmt->invoke = s_decl;
		stmt->arg = (void *) asgn_list;
		stmt->line_no = yylineno;
                stmt->arg_is_expr = 0;
		stmt->scope = NULL;
		(yyval.stmt_node) = stmt; 
	}
#line 2550 "y.tab.c" /* yacc.c:1646  */
    break;

  case 69:
#line 851 "parser.y" /* yacc.c:1646  */
    {
		scope_t * scope = (scope_t *) malloc(sizeof(scope_t));
		scope->name_table = (LinkedList *) malloc(sizeof(LinkedList));
		scope->updated = 0;
		stmt_node_t * ref = NULL;

		(yyvsp[-1].stmt_node)->scope = scope;
		scope->parent = global_scope;
		ref = (yyvsp[-1].stmt_node);
		ref->line_no = yylineno;
		update_scope_hierarchy((yyvsp[-1].stmt_node));
		(yyval.stmt_node) = ref;
	}
#line 2568 "y.tab.c" /* yacc.c:1646  */
    break;

  case 70:
#line 865 "parser.y" /* yacc.c:1646  */
    {
		(yyval.stmt_node) = NULL;
	}
#line 2576 "y.tab.c" /* yacc.c:1646  */
    break;

  case 71:
#line 869 "parser.y" /* yacc.c:1646  */
    {
		if_node_t * node = (if_node_t *) malloc(sizeof(if_node_t));
		node->expression = (yyvsp[-4].exp_node);
		if((yyvsp[-2].stmt_node) != NULL && (yyvsp[-2].stmt_node)->type == PRO)
		{
			stmt_node_t * list = (stmt_node_t *) malloc(sizeof(stmt_node_t));
			list->type = LIST;
			list->list_head = (yyvsp[-2].stmt_node);
			node->if_list = list;
		}
		else
		{
			node->if_list = (yyvsp[-2].stmt_node);
		}
		if((yyvsp[0].stmt_node) != NULL && (yyvsp[0].stmt_node)->type == PRO)
		{
			stmt_node_t * list = (stmt_node_t *) malloc(sizeof(stmt_node_t));
			list->type = LIST;
			list->list_head = (yyvsp[0].stmt_node);
			node->else_list = list;
		}
		else
		{
			node->else_list = (yyvsp[0].stmt_node);
		}

		stmt_node_t * stmt = (stmt_node_t *) malloc(sizeof(stmt_node_t));
		stmt->type = IF;
		stmt->if_node = node;
		stmt->arg = NULL;
		stmt->arg_is_expr = 0;
		stmt->line_no = yylineno;
		(yyval.stmt_node) = stmt;
	}
#line 2615 "y.tab.c" /* yacc.c:1646  */
    break;

  case 72:
#line 904 "parser.y" /* yacc.c:1646  */
    {
		while_node_t * node = (while_node_t *) malloc(sizeof(while_node_t));
		node->expression = (yyvsp[-2].exp_node);
		if((yyvsp[0].stmt_node) != NULL && (yyvsp[0].stmt_node)->type == PRO)
		{
			stmt_node_t * list = (stmt_node_t *) malloc(sizeof(stmt_node_t));
			list->type = LIST;
			list->list_head = (yyvsp[0].stmt_node);
			node->list = list;
		}
		else
		{
			node->list = (yyvsp[0].stmt_node);
		}
		stmt_node_t * stmt = (stmt_node_t *) malloc(sizeof(stmt_node_t));
		stmt->type = WHILE;
		stmt->while_node = node;
		stmt->arg = NULL;
		stmt->line_no = yylineno;
		stmt->arg_is_expr = 0;
		(yyval.stmt_node) = stmt;
	}
#line 2642 "y.tab.c" /* yacc.c:1646  */
    break;

  case 73:
#line 927 "parser.y" /* yacc.c:1646  */
    {
		stmt_node_t * stmt = (stmt_node_t * )malloc(sizeof(stmt_node_t));
		stmt->invoke = s_println;
		stmt->arg = (yyvsp[-2].exp_node);
		stmt->arg_is_expr = 1;
		stmt->type = PRO;
		stmt->line_no = yylineno;

		(yyval.stmt_node) = stmt;		
	  }
#line 2657 "y.tab.c" /* yacc.c:1646  */
    break;

  case 74:
#line 938 "parser.y" /* yacc.c:1646  */
    {

		stmt_node_t * stmt = (stmt_node_t * )malloc(sizeof(stmt_node_t));
		stmt->invoke = s_print;
		stmt->arg = (yyvsp[-2].exp_node);
		stmt->arg_is_expr = 1;
		stmt->type = PRO;
		stmt->line_no = yylineno;
		(yyval.stmt_node) = stmt;		
		
	  }
#line 2673 "y.tab.c" /* yacc.c:1646  */
    break;

  case 75:
#line 950 "parser.y" /* yacc.c:1646  */
    {

		stmt_node_t * stmt = (stmt_node_t * )malloc(sizeof(stmt_node_t));
		stmt->invoke = s_asgn;
		struct exp_node * asgn_node = create_exp_node(ASGN, (yyvsp[-3].exp_node), (yyvsp[-1].exp_node));
		asgn_node->type = (yyvsp[-3].exp_node)->type;
		asgn_node->line_num = yylineno;
		stmt->arg = asgn_node;
		stmt->arg_is_expr = 1;
		stmt->type = PRO;
		stmt->line_no = yylineno;
		(yyval.stmt_node) = stmt;		
	  }
#line 2691 "y.tab.c" /* yacc.c:1646  */
    break;

  case 76:
#line 964 "parser.y" /* yacc.c:1646  */
    {
		stack_push((yyvsp[-1].exp_node));
	}
#line 2699 "y.tab.c" /* yacc.c:1646  */
    break;

  case 77:
#line 968 "parser.y" /* yacc.c:1646  */
    {
		stmt_node_t * stmt = (stmt_node_t *) malloc(sizeof(stmt_node_t));
		stmt->type = PRO;
		stmt->arg_is_expr = 1;
		stmt->line_no = yylineno;
		stmt->invoke = s_invoke;
		stmt->arg = (yyvsp[-1].exp_node); //Setting the method as the argument.
		(yyval.stmt_node) = stmt;
	}
#line 2713 "y.tab.c" /* yacc.c:1646  */
    break;

  case 78:
#line 981 "parser.y" /* yacc.c:1646  */
    {
		assert((yyvsp[-1].stmt_node)->type == LIST);
	        slist_add((yyvsp[-1].stmt_node), (yyvsp[0].stmt_node));
		(yyval.stmt_node) = (yyvsp[-1].stmt_node);
	}
#line 2723 "y.tab.c" /* yacc.c:1646  */
    break;

  case 79:
#line 987 "parser.y" /* yacc.c:1646  */
    {
		(yyval.stmt_node) = (stmt_node_t *) malloc(sizeof(stmt_node_t));
		(yyval.stmt_node)->type = LIST;
		assert((yyvsp[0].stmt_node)->type == LIST || (yyvsp[0].stmt_node)->type == PRO || (yyvsp[0].stmt_node)->type == IF || (yyvsp[0].stmt_node)->type == WHILE);
		slist_add((yyval.stmt_node), (yyvsp[0].stmt_node));
 	  }
#line 2734 "y.tab.c" /* yacc.c:1646  */
    break;

  case 80:
#line 995 "parser.y" /* yacc.c:1646  */
    {
		struct exp_node * leaf = (struct exp_node *) malloc(sizeof(struct exp_node));
                leaf->is_method = 1;

		//assert(leaf->associated_class != NULL);
		//leaf->data.method = (method_t *) malloc(sizeof(method_t));
		//leaf->data.method->id = $1->data.var_name;
		leaf->data.left = (yyvsp[-3].exp_node);
		//left->data.right = FOR ARGUMENTS.
		leaf->data.right = NULL;
  		leaf->operation = (yyvsp[-3].exp_node)->operation;
  		leaf->is_leaf = 0;
  		leaf->is_id = 1;
  		leaf->is_array = 0;
		leaf->is_property = 1;
		leaf->line_num = yylineno;
		(yyval.exp_node) = leaf;

}
#line 2758 "y.tab.c" /* yacc.c:1646  */
    break;

  case 81:
#line 1017 "parser.y" /* yacc.c:1646  */
    {
		index_t * dimension = (index_t *) malloc(sizeof(index_t));
		dimension->size = (yyvsp[-1].exp_node);
		index_list_t * list = (index_list_t *) malloc(sizeof(index_list_t));
		list->sentinel = NULL;
		index_list_add(list, dimension);
		(yyval.dimension_list) = list;
	}
#line 2771 "y.tab.c" /* yacc.c:1646  */
    break;

  case 82:
#line 1026 "parser.y" /* yacc.c:1646  */
    {
		index_t * dimension = (index_t *) malloc(sizeof(index_t));
		dimension->size = (yyvsp[-1].exp_node);
		assert((yyvsp[-3].dimension_list)->sentinel != NULL);
		index_list_add((yyvsp[-3].dimension_list), dimension);
		(yyval.dimension_list) = (yyvsp[-3].dimension_list);
	}
#line 2783 "y.tab.c" /* yacc.c:1646  */
    break;

  case 83:
#line 1037 "parser.y" /* yacc.c:1646  */
    {
		(yyval.integer_val) = (yyvsp[-2].dimension_list) + 1;
	}
#line 2791 "y.tab.c" /* yacc.c:1646  */
    break;

  case 84:
#line 1041 "parser.y" /* yacc.c:1646  */
    {
		(yyval.integer_val) = 1;
	}
#line 2799 "y.tab.c" /* yacc.c:1646  */
    break;

  case 85:
#line 1047 "parser.y" /* yacc.c:1646  */
    {
		char * var = (yyvsp[0].string_val);
		//Find the id leaf and update parent right.
		//FIND A WAY TO UPDATE THE TYPE HERE IF THE VAR EXISTS.

		struct exp_node * leaf = create_id_leaf(var);
		leaf->line_num = yylineno;
		(yyval.exp_node) = leaf;

	}
#line 2814 "y.tab.c" /* yacc.c:1646  */
    break;

  case 86:
#line 1058 "parser.y" /* yacc.c:1646  */
    {
		char * array_name = (yyvsp[-1].string_val);
                index_list_t * index_list = (yyvsp[0].dimension_list);
		struct exp_node * leaf = create_array_entry_leaf(array_name, index_list, NULL);
		leaf->line_num = yylineno;
		(yyval.exp_node) = leaf;		
	}
#line 2826 "y.tab.c" /* yacc.c:1646  */
    break;

  case 87:
#line 1066 "parser.y" /* yacc.c:1646  */
    {
		//Look from name table.
		//Property reading or method reading.
		struct exp_node * right = create_id_leaf((yyvsp[0].string_val));
		right->is_property = 1;
		right->is_id = 1;
		struct exp_node * node = create_exp_node(IN, (yyvsp[-2].exp_node), right);
		//Only compatible with class names
		node->line_num = yylineno;
		(yyval.exp_node) = node;
		
	}
#line 2843 "y.tab.c" /* yacc.c:1646  */
    break;

  case 89:
#line 1080 "parser.y" /* yacc.c:1646  */
    {
		index_list_t * dim_list = (yyvsp[0].dimension_list);
		struct exp_node * node = create_array_leaf((yyvsp[-1].type)->type, (yyvsp[0].dimension_list), NULL);	
		node->line_num = yylineno;
		(yyval.exp_node) = node;	
	}
#line 2854 "y.tab.c" /* yacc.c:1646  */
    break;


#line 2858 "y.tab.c" /* yacc.c:1646  */
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

  /* Now 'shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */

  yyn = yyr1[yyn];

  yystate = yypgoto[yyn - YYNTOKENS] + *yyssp;
  if (0 <= yystate && yystate <= YYLAST && yycheck[yystate] == *yyssp)
    yystate = yytable[yystate];
  else
    yystate = yydefgoto[yyn - YYNTOKENS];

  goto yynewstate;


/*--------------------------------------.
| yyerrlab -- here on detecting error.  |
`--------------------------------------*/
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

  /* Do not reclaim the symbols of the rule whose action triggered
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
  yyerrstatus = 3;      /* Each real token shifted decrements this.  */

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
  /* Do not reclaim the symbols of the rule whose action triggered
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
  return yyresult;
}
#line 1089 "parser.y" /* yacc.c:1906  */



void yyerror(char const* msg)
{
  if(msg != NULL)
  {
	fprintf(stderr, "%s in line %d\n", msg, yylineno);
  }
  else
  {
        fprintf(stderr, "Syntax error in %d\n", yylineno);
  }
  if(!type_violation_found)
  {
    type_violation_found = 1;
  }
}

void type_error(int line_num)
{
  //No type error for project 3.
  /*fprintf(stderr, "Type violation at line %d\n", line_num);
  if(!type_violation_found)
  {
    type_violation_found = 1;
  }*/
}

void update_scope_hierarchy(stmt_node_t * stmt)
{

		if(stmt->type == LIST)
		{
		  stmt_node_t * it = stmt->list_head;
		  while(it)
		  {
		        if(it->type == LIST)
			{
				it->scope->parent = stmt->scope;

			}
			else if(it->type == IF)
			{
				it->if_node->if_list->scope->parent = stmt->scope;
				it->if_node->else_list->scope->parent = stmt->scope;
			}
			else if(it->type == WHILE)
			{
				it->while_node->list->scope->parent = stmt->scope;
			}
			it = it->next;
		  }	
		}	
}

int get_capacity(index_list_t * capacity)
{
  int result = 1;
  index_t * it = capacity->sentinel->next;
  while(it != capacity->sentinel)
  {
    traverse(it->size);
    result = result * (*(int *)it->size->current_value);
  }
}

int calculate_right_capacity(index_list_t * capacity, int dim_index)
{
  index_t * it = capacity->sentinel->next;
  for(int i = 0; i< dim_index; i++)
  {
    it = it->next;
  }
  it = it->next;
  if(it == capacity->sentinel) return 1;
  int result = 1;
  while(it != capacity->sentinel)
  { 
    traverse(it->size);
    result = result * (*(int *)it->size->current_value);
    it = it->next;
  }
  return result;
}

/*Helper methods.*/
//Returns the real location of the dimension.
int find_value_of_index(index_list_t * index_list, index_list_t * capacity_list)
{
  //Start iterating from last.
  index_t * it = index_list -> sentinel -> next;
  int result = 0;
  int dim_index = 0;
  while(it != index_list->sentinel)
  {
    if(it->size->type != INT)
    {
	return -1;
    }
    traverse(it->size); //Updating value of size.
    if(it->size->current_value == NULL)
    {
	return -1;
    }
    result = result + (*(int *)it->size->current_value * calculate_right_capacity(capacity_list, dim_index)); 

    it = it->next;
    dim_index++;
  }
  return result;
}

/*Add new var to given name table,*/
int add_var_to_table(LinkedList * table, char * var, enum type type,  void * value)
{
	if(llist_exists(table, var))
	{
		/*int len = 26 + strlen(var);
		char error[len + 1];
		sprintf(error, "Symbol \"%s\" already declared", var);
		error[len] = 0;
		yyerror(error);	
		return 1;*/
		if(construct_name_table) return 1;
		else update_var(table, var, value); 
	} 
	else
	{
		llist_add(table, var, type, value); 
		return 0;
	}
}

int add_node_to_table(LinkedList * table, ListNode * node)
{
	if(llist_exists(table, node->value))
	{
		/*int len = 26 + strlen(var);
		char error[len + 1];
		sprintf(error, "Symbol \"%s\" already declared", var);
		error[len] = 0;
		yyerror(error);	
		return 1;*/
		if(construct_name_table) return 1;
		else update_var(table, node->value, node->real_value); 
	} 
	else
	{
		llist_add_node(table, node); 
		return 0;
	}

}

/*Updates var value if exists.*/
int update_var(LinkedList * list, char * var, void * value)
{ 
	if(!llist_exists(current_scope->name_table, var))
	{
		  //23 is the length of the remainder of the message 
		  /*int len = 23 + strlen(var);
		  char errorMessage[len];
		  sprintf(errorMessage, "Cannot find symbol \"%s\"", var);
		  errorMessage[len - 1] = 0;
		  yyerror(errorMessage);*/
		  //type_error();
		  return 1;	
	}
	llist_addValue(current_scope->name_table, var, value); 
	return 0;	
}

index_list_t * dup_sub_index_list(index_list_t * list, int sub)
{
  index_t * it = list->sentinel;
  for(int i =0; i < sub; i++)
  {
    it=it->next;
  }
  it = it->next; //Shifting right for calculating right capacity. 
  index_list_t * right_capacity = (index_list_t *) malloc(sizeof(index_list_t));
  right_capacity->sentinel=NULL;
  while(it != NULL && it->size != NULL)
  {
    index_list_add(right_capacity, it);
    it = it->next;
  }
  return right_capacity;
}

struct exp_node * lookup_array(array_entry_t * entry)
{
     ListNode * array_node = llist_find_node(current_scope->name_table, entry->array_name);
     assert(entry != NULL);
     if(array_node == NULL)
     {
	return NULL;
     }
     int real_index = find_value_of_index(entry->index, array_node->dim_capacity_list);
     if(real_index < 0)
     {
	return NULL;
     }
     void * array = array_node->real_value;

     int c_len = find_index_len(array_node->dim_capacity_list);
     int i_len = find_index_len(entry->index);
     assert(c_len >= i_len);
     struct exp_node * result = (struct exp_node *) malloc(sizeof(struct exp_node));
     result->is_array_entry = 0;
     result->is_id = 0;
     result->is_leaf = 1;
     result->operation = UNDEF;
     array_entry_t * array_entry = (array_entry_t *) malloc(sizeof(array_entry_t));
     switch(array_node->type)
     {
	case BOOL:
	{
		//If true, it is just a value.
		if(c_len == i_len)
		{
		  int * int_array = (int *) array;
		  result->current_value =(void *) &int_array[real_index];
		  result->is_array = 0;
		}
		else
		{
                  int dif = c_len - i_len;
		  int * int_array = (int *) array;
		  result->current_value =(void *) &int_array[real_index];
		  index_list_t * sub_list = dup_sub_index_list(array_node->dim_capacity_list, dif);
		  result->data.dimensions = sub_list;
		  result->is_array = 1;	
		}
		result->type = BOOL;
		return result;

	}
	case INT: 
	{ 
		//If true, it is just a value.
		if(c_len == i_len)
		{
		  int * int_array = (int *) array;
		  result->current_value =(void *) &int_array[real_index];
		  result->is_array = 0;
		}
		else
		{
                  int dif = c_len - i_len;
		  int * int_array = (int *) array;
		  result->current_value =(void *) &int_array[real_index];
		  index_list_t * sub_list = dup_sub_index_list(array_node->dim_capacity_list, dif);
		  result->data.dimensions = sub_list;
		  result->is_array = 1;	
		}
		result->type = INT;
		return result;
	}
	case STR:
	{ 
		//If true, it is just a value.
		if(c_len == i_len)
		{
		  char** str_array = (char **) array;
		  result->current_value =(void *) &str_array[real_index];
		  result->is_array = 0;
		}
		else
		{
                  int dif = c_len - i_len;
		  char ** str_array = (char**) array;
		  result->current_value =(void *) &str_array[real_index];
		  index_list_t * sub_list = dup_sub_index_list(array_node->dim_capacity_list, dif);
		  result->data.dimensions = sub_list;
		  result->is_array = 1;	
		}
		result->type = STR;
		return result;
	}
	default: return NULL;
     }	
}


class_t * get_class_info(char * id)
{
  class_t * it = program->class_list->head;
  while(it)
  {
    if(!strcmp(it->id, id))
    {
	return it;
    }
    it = it->next;
  }
  return NULL;
}

//Wrapper code.
int setup_execute(stmt_node_t * current)
{
	add_to(text_section, "push {fp}\n");
	add_to(text_section, "mov fp, sp\n");

	int current_method_size = calc_method_size(current);
	char alloc_method[40];
	sprintf(alloc_method, "sub sp, sp, #%d\n", current_method_size);
	add_to(text_section, alloc_method);
	method_first_codegen(current);
	
	execute(current);

	add_to(text_section, "mov sp, fp\n");
	add_to(text_section, "pop {fp}\n");

}

/* Execute statements. This is where the code generated for statements. */
int execute(stmt_node_t * list)
{
  if(list == NULL) return 0;
  assert(list->type == LIST || list->type == PRO);
  stmt_node_t * current; 
  scope_t * prev_scope = NULL;
  if(list->type == LIST)
  {
          current = list->list_head;
	  if(list->scope != current_scope)
	  {
	      if(list->scope->parent == current_scope)
	      {
		  scope_inherit_updates(current_scope, list->scope);
		  prev_scope = current_scope;
		  current_scope = list->scope;	
	      }
	      else //Method or class scope.
	      {
		prev_scope = current_scope;
		current_scope = list->scope;
	      }

	      if(current_scope->parent != NULL)
	      {
		  scope_inherit_updates(current_scope->parent, current_scope);
	      }
	  }

  }
  else
  {
    current = list;
  }

 
  assert(current_scope != NULL);


  while(current)
  {
    switch(current->type)
    {
	case PRO: 
	{
	    if(current->invoke != NULL)
	    {
	      if(current->arg_is_expr)
	      {
		expr_codegen((struct exp_node *) current->arg);
	      }
	      if(current->invoke != s_invoke)
	          current->invoke(current->arg);
	    }
	    break;
	}
	case LIST: 
	{
	    setup_execute(current);
	    break;
	}
	case IF:
	{
	    if_node_t * node = current->if_node;
	    assert(node != NULL);
	    traverse(node->expression);
	    if(node->expression->type != BOOL)
	    {
		break;
            }
	    struct exp_node * exp = node->expression;
	    expr_codegen(exp);
            //r0 should have the right value.
	    char * if_l = generate_label(TRUE_P);
	    char * else_l = generate_label(FALSE_P);
	    char * endif_l = generate_label(ENDIF_P);

	    add_to(text_section, "cmp r0, #0\n");
	    char false_br[80];
	    sprintf(false_br, "beq %s\n", else_l);
	    add_to(text_section, false_br);
	    declare_label(if_l);
	    setup_execute(node->if_list);
            char true_jump[80];
	    sprintf(true_jump, "b %s\n", endif_l);
	    add_to(text_section, true_jump);
	    declare_label(else_l);
	    setup_execute(node->else_list);
	    declare_label(endif_l);
	    break;
	}
	case WHILE: 
	{
		while_node_t * node = current->while_node;
		assert(node !=NULL);
		traverse(node->expression);
	    	if(node->expression->type != BOOL)
	    	{
			break;
            	}
	    	struct exp_node * exp = node->expression;
		expr_codegen(exp);
		char * while_l = generate_label(WHILE_P);
		char * endwhile_l = generate_label(ENDWHILE_P);

	    	add_to(text_section, "cmp r0, #0\n");
		char init_jump[80];
		sprintf(init_jump, "beq %s\n", endwhile_l);
		add_to(text_section, init_jump);
  	    	add_to(text_section, "push {fp}\n");
  	    	add_to(text_section, "mov fp, sp\n");

		int current_method_size = calc_method_size(node->list);
		char alloc_method[40];
		sprintf(alloc_method, "sub sp, sp, #%d\n", current_method_size);
		add_to(text_section, alloc_method);
		method_first_codegen(node->list);
		declare_label(while_l);
		execute(node->list);
		current_scope = node->list->scope;
		expr_codegen(exp);
		current_scope = current_scope->parent; //Backtrack. The reason we changed the scope is that traverse exp will now look at the right symbol table.
		char jump_back[80];
	    	add_to(text_section, "cmp r0, #0\n");
		sprintf(jump_back, "bne %s\n", while_l);
		add_to(text_section, jump_back);
  	    	add_to(text_section, "mov sp, fp\n");
  	    	add_to(text_section, "pop {fp}\n");
		declare_label(endwhile_l);	
		/*while(*(int *) exp->current_value)
		{
			execute(node->list);
			current_scope = node->list->scope;
			assert(current_scope != NULL);
			traverse(exp);
			current_scope = current_scope->parent; //Backtrack. The reason we changed the scope is that traverse exp will now look at the right symbol table.
		}*/
		break;
	}
	default: /*type_error();*/ break;
		
    }

    current = current->next;
  }
  /*if(current_scope->parent != NULL)
  {
	current_scope = current_scope->parent;
  } 
  else
  {
  	current_scope = global_scope; 
  }*/
  if(prev_scope != NULL)
  {
    current_scope = prev_scope;
  }


}



/* Traverse expr tree. Every traversal updates the reference of the object.*/
int traverse(struct exp_node * root)
{
  if(root != NULL)
  {
    /*if(root->is_property)
    {
	class_t * info = get_class_info(root->associated_class);
	if(info == NULL)
	{	
		type_error(root->line_num);
		return 1;
	}
	
	ListNode * node = llist_find_node(info->scope->name_table, root->data.var_name);
	if(node == NULL)
	{
		type_error(root->line_num);
		return 1;
	}
	if(node->symbol_type == PROPERTY)
	{
		if(root->is_method)
		{
			type_error(root->line_num);
			return 1;
		}
		void * property_value = llist_find(info->scope->name_table, node->value);
		if(property_value == NULL)
		{
			type_error(root->line_num);
			return 1;
		}
		root->current_value = property_value;
		return 0;
		
	}
	else if(node->symbol_type == METHOD)
	{
		if(!root->is_method)
		{
			type_error(root->line_num);
			return 1;
		}

		method_t * method = (method_t *) node->real_value;
		stmt_node_t * routine = method->statement;
		if(routine == NULL)
		{
			type_error(root->line_num);
			return 1;
		}
		//Call method.

		//Implement arguments here. TODO 
		if(construct_name_table)
		{
			traverse_for_errors(routine);
		}
		else
		{	
			execute(routine);
		}
		if(routine->type != UNDEF)
		{
			//When return is used.
			//root->current_value = stack_pop();
		}
	}

    }*/
    if(root->is_id)
    {
	     //ListNode * node =  llist_find_node(current_scope->name_table, root->data.var_name);
	     //root->current_value = node->real_value;
	     //root->type = node->type;

	     return 0;
    }
    else if(!root->is_leaf && !root->is_array_entry)
    {
	    struct exp_node * left = root->data.left;
	    struct exp_node * right = root->data.right;
	    //Traverse will return error.
	    //We put this here for cases where the array entry is being assigned.
	    if(root->type != ASGN || !left->is_array_entry)
	    {
	    	if(traverse(left)) return 1;
	    }

	    if(traverse(right)) return 1;
	    if(left == NULL && right == NULL) 
	    {
		type_error(root->line_num);
		return 1;
	    }
	    if(construct_name_table)
	    {
		//TODO: Error check.
		if(left == NULL)
		{
			type_error(root->line_num);
			return 1;
		}
		//Left can be null when op is ASGN.
		else if(root->operation != IN && root->operation != ASGN && left->type != CLASS && left->current_value == NULL)
		{
			type_error(root->line_num);
			return 1;

		}
		if(root->operation != MIN && root->operation != PLU && right == NULL)
		{
			type_error(root->line_num);
			return 1;	
		}
		else if(root->operation != IN && right != NULL && right->type != CLASS && right->current_value == NULL)
		{
			type_error(root->line_num);
			return 1;

		}
		if(root->operation != IN && left != NULL && right !=NULL && !left->is_array_entry && left->type != right->type)
		{
		 	type_error(root->line_num);
			return 1;
		} 
		
	    }
	    root->type = left->type;
	    switch(root->operation)
	    {
		
		case ADD:  
			root->current_value = s_add(left, right, root->type);
			if(root->current_value == NULL) return 1; //Type error.
			break;
		case SUB:  
			root->current_value = s_sub(left, right, root->type); 
			if(root->current_value == NULL) return 1; //Type error. 
			break;
		case MUL:  
			root->current_value = s_mul(left, right, root->type);
			if(root->current_value == NULL) return 1; //Type error.
			break;
		case DIV:  
			root->current_value = s_div(left, right, root->type); 
			if(root->current_value == NULL) return 1; //Type error.
			break;
		case NGT:
			root->current_value = s_negate(left, root->type);
			if(root->current_value == NULL) return 1; //Type error.
			root->is_leaf = 1;
			break; 
		case PLU:
			root->current_value = s_plu(left, root->type);
			if(root->current_value == NULL) return 1; //Type error.
			break;
		case MIN:
			root->current_value = s_min(left, root->type);
			if(root->current_value == NULL) return 1; //Type error.
			break;  
		case AND:
			root->current_value = s_and(left, right);
			if(root->current_value == NULL) return 1; //Type error.
			root->type = BOOL; 
			break;
		case OR:
			root->current_value = s_or(left, right);
			if(root->current_value == NULL) return 1; //Type error.
			root->type = BOOL; 
			break;
		case SME:
			root->current_value = s_seq(left, right);
			if(root->current_value == NULL) return 1; //Type error.
			root->type = BOOL; 
			break;
		case LRE:
			root->current_value = s_leq(left, right);
			if(root->current_value == NULL) return 1; //Type error.
			root->type = BOOL; 
			break;
		case EQU:
			root->current_value = s_eq(left, right);
			if(root->current_value == NULL) return 1; //Type error.
			root->type = BOOL; 
			break;
		case NEQ:
			root->current_value = s_neq(left, right);
			if(root->current_value == NULL) return 1; //Type error.
			root->type = BOOL; 
			break;
		case LE:
			root->current_value = s_less(left, right);
			if(root->current_value == NULL) return 1; //Type error.
			root->type = BOOL; 
			break;
		case GR:
			root->current_value = s_greater(left, right);
			if(root->current_value == NULL) return 1; //Type error. 
			root->type = BOOL; 
			break;
		case IN: 
		{
			if(left->is_array && right->data.var_name == "length")
			{
			}
			else
			{
				s_find_property(root);
				//if(root->current_value == NULL) return 1; //Type error. 
				root->type = right->type;
				break;
			}
		}
		case ASGN: return 1;
                case UNDEF: return 1;
	
		default: /*type_error();*/ break;	
	    }

    }
    else if(root->is_array_entry)
    {
		/*array_entry_t * array_entry = root->data.array_entry;
		struct exp_node * result = lookup_array(array_entry);	
	        if(result == NULL)
		{
			type_error(root->line_num);
			return 1;
		}	
		if(!result->is_array)
		{
		  if(traverse(result))
		  {
			return 1;
		  }
		}
		root->current_value = result -> current_value;
		root->is_array = result->is_array;
		root->type = result->type;*/
    }
  }
}


/*Library methods*/
void s_print(void * arg)
{
	struct exp_node * node = (struct exp_node *) arg;
        assert(node != NULL);
	assert(node != ASGN);

	void * value;
	enum type type;
	ListNode * list_node;
	if(node->is_id)
	{
		//list_node = llist_find_node(current_scope->name_table, node->data.var_name);
		//type = list_node->type;
		//value = list_node->real_value;
//		type = node->type;
//		value = node->current_value;
	}
	else if(node->is_array)
	{
		type_error(node->line_num);
		return;
	}
	else
	{
		value = node->current_value;
		type = node->type;
	}
	
	switch(type)
	{

		case INT : 
		{
			//Move value from ro to r1.
			add_to(text_section, "mov r1, r0\n");
			add_to(text_section, "ldr r0, =print_int_format\n");
			add_to(text_section, "bl printf\n");		
			break;
		} 
		case STR :
		{
			add_to(text_section, "mov r1, r0\n"); 
			add_to(text_section, "ldr r0, =print_str_format\n");
			add_to(text_section, "bl printf\n");
			break;
		}
		case BOOL :
		{
			char * true_l = generate_label(TRUE_P);
			char * false_l = generate_label(FALSE_P);
			char * endif_l = generate_label(ENDIF_P);
		
			add_to(text_section, "cmp r0, #1\n");
			char branch[50];
			sprintf(branch, "bne %s\n", false_l);
			add_to(text_section, branch);
			declare_label(true_l);
			add_to(text_section, "ldr r0, =print_str_format\n");
			add_to(text_section, "ldr r1, =bool_true\n");
			add_to(text_section, "bl printf\n");
			char branch2[50];
			sprintf(branch2, "b %s\n", endif_l);
			add_to(text_section, branch2);
			declare_label(false_l);
			add_to(text_section, "ldr r0, =print_str_format\n");
			add_to(text_section, "ldr r1, =bool_false\n");
			add_to(text_section, "bl printf\n");
			declare_label(endif_l);
			break;
		}	
		default: assert(0); break; 
	}	
}

void s_println(void * arg)
{
	struct exp_node * node = (struct exp_node *) arg;
	void * value;
	assert(node != NULL);
	enum type type;
	ListNode * list_node;
	if(node->is_id)
	{
		//Do address computation.
		ListNode * list_node = llist_find_node(current_scope->name_table, node->data.var_name);
		//type = node->type;
		//value = node->current_value;
	}
	else if(node->is_array)
	{
		type_error(node->line_num);
		return;
	}
	else
	{
		value = node->current_value;
	}
	//assert(value != NULL);
	switch(node->type)
	{

		case INT : 
		{
			//Move value from ro to r1.
			add_to(text_section, "mov r1, r0\n");
			add_to(text_section, "ldr r0, =println_int_format\n");
			add_to(text_section, "bl printf\n");		
			break;
		} ;
		case STR :
		{
			add_to(text_section, "mov r1, r0\n"); 
			add_to(text_section, "ldr r0, =println_str_format\n");
			char print_arg[40];
			add_to(text_section, "bl printf\n");
			break;
		}
		case BOOL :
		{
			char * true_l = generate_label(TRUE_P);
			char * false_l = generate_label(FALSE_P);
			char * endif_l = generate_label(ENDIF_P);
		
			add_to(text_section, "cmp r0, #1\n");
			char branch[50];
			sprintf(branch, "bne %s\n", false_l);
			add_to(text_section, branch);
			declare_label(true_l);
			add_to(text_section, "ldr r0, =println_str_format\n");
			add_to(text_section, "ldr r1, =bool_true\n");
			add_to(text_section, "bl printf\n");
			char branch2[50];
			sprintf(branch2, "b %s\n", endif_l);
			add_to(text_section, branch2);
			declare_label(false_l);
			add_to(text_section, "ldr r0, =println_str_format\n");
			add_to(text_section, "ldr r1, =bool_false\n");
			add_to(text_section, "bl printf\n");
			declare_label(endif_l);
			break;
		}	
		default: assert(0); break; 
	}	
}

//Root has operation IN. Left side is the associated class and right side is the id that has the method or property name.
int s_find_property(struct exp_node * root)
{
	struct exp_node * op1 = root->data.left;
	struct exp_node * op2 = root->data.right;
	//Find var from current scope.
	ListNode * prop_node = llist_find_node(current_scope->name_table, op1->data.var_name);
	assert(prop_node->type == CLASS);
	assert(prop_node->class_id != NULL);
	//Somehow left should have class name.
	class_t * info = get_class_info(prop_node->class_id);
  	assert(info != NULL);
	ListNode * node = llist_find_node(info->scope->name_table, op2->data.var_name);
	assert(node != NULL);
	if(node->symbol_type == PROPERTY)
	{
		struct exp_node * property_value = (struct exp_node *) llist_find(info->scope->name_table, node->value);
		if(property_value == NULL)
		{
			type_error(root->line_num);
			return 1;
		}
		root->current_value = property_value->current_value;
		return 0;	
	}
	else if(node->symbol_type == METHOD)
	{

		method_t * method = (method_t *) node->real_value;
		stmt_node_t * routine = method->statement;
		if(routine == NULL)
		{
			type_error(root->line_num);
			return 1;
		}
		//Call method.

		//Implement arguments here. TODO 
		if(construct_name_table)
		{
			traverse_for_errors(routine);
		}
		else
		{	
			execute(routine);
		}
		if(routine->type != UNDEF)
		{
			//When return is used.
			//root->current_value = stack_pop();
		}
		return 0;
	}
	
}

void * s_add(struct exp_node * op1, struct exp_node * op2, enum type type)
{
  assert(op1 != NULL);
  assert(op2 != NULL);

  switch(type)
  {
    case INT:
    {
	int result = *(int *) op1->current_value + (*(int *)op2->current_value);
        int * res_point = (int *) malloc(sizeof(int));
	*res_point = result; 
	return res_point;
    }	
    case STR: 
    {
	char * operand1 = (char*)op1->current_value;
	char * operand2 = (char*)op2->current_value;
	int len1 = strlen(operand1);
	int len2 = strlen(operand2);
	char * result = (char *) malloc((len1 + len2 + 1) * sizeof(char));
	strncpy(result, operand1, len1);
	strncpy(&result[len1], operand2, len2);
	result[len1+len2] = 0;
	return result;	
	
    }
    default: type_error(op1->line_num); return NULL;
  }
}

void * s_sub(struct exp_node * op1, struct exp_node * op2, enum type type)
{
  assert(op1 != NULL);
  assert(op2 != NULL);


  switch(type)
  {
    case INT:
    {
	int result = *(int *) op1->current_value - (*(int *)op2->current_value);
        int * res_point = (int *) malloc(sizeof(int));
	*res_point = result; 
	return res_point;
    }
    default: type_error(op1->line_num); return NULL;
  }
}

void * s_mul(struct exp_node * op1, struct exp_node * op2, enum type type)
{
  assert(op1 != NULL);
  assert(op2 != NULL);
  switch(type)
  {
    case INT:
    {
	int result = *(int *) op1->current_value * (*(int *)op2->current_value);
        int * res_point = (int *) malloc(sizeof(int));
	*res_point = result; 
	return res_point;
    }
    default: type_error(op1->line_num); return NULL;
  }
}


void * s_div(struct exp_node * op1, struct exp_node * op2, enum type type)
{
  assert(op1 != NULL);
  assert(op2 != NULL);
  switch(type)
  {
    case INT: 
    {
	int result = *(int *) op1->current_value / *(int *) op2->current_value;
        int * res_point = (int *) malloc(sizeof(int));
	*res_point = result; 
	return res_point;
    }
    default: type_error(op1->line_num); return NULL;
  }
}

// !(bool) operation
void * s_negate(struct exp_node * op, enum type type)
{
  assert(op != NULL);
  switch(type)
  {
    case BOOL:
    {
	int result = *(int *) op->current_value == 0 ? 1 : 0;
        int * res_point = (int *) malloc(sizeof(int));
	*res_point = result; 
	return res_point;
    }
    default:   type_error(op->line_num); return NULL;
  }

}

void * s_plu(struct exp_node * op, enum type type)
{
  assert(op != NULL);
  switch(type)
  {
    case INT: 
    {
	int result = (*(int *) op->current_value);
        int * res_point = (int *) malloc(sizeof(int));
	*res_point = result; 
	return res_point;
    }
    default:   type_error(op->line_num); return NULL;
  }
}

void * s_min(struct exp_node * op, enum type type)
{
  assert(op != NULL);
  if(op->type != type)
  switch(type)
  {
    case INT: 
    {
	int result = -1 * (*(int *) op->current_value);
        int * res_point = (int *) malloc(sizeof(int));
	*res_point = result; 
	return res_point;
    }
    default:   type_error(op->line_num); return NULL;
  }
}

void * s_and(struct exp_node * op1, struct exp_node * op2)
{
  assert(op1 != NULL);
  assert(op2 != NULL);
  enum type type = op1->type;
  switch(type)
  {
    case BOOL:
    {
	int result = *(int *) op1->current_value && *(int *) op2->current_value;
        int * res_point = (int *) malloc(sizeof(int));
	*res_point = result; 
	return res_point;
    }
    default:   type_error(op1->line_num); return NULL;
  }

}

void * s_or(struct exp_node * op1, struct exp_node * op2)
{
  assert(op1 != NULL);
  assert(op2 != NULL);
 enum type type = op1->type;
  switch(type)
  {
    case BOOL:
    {
	int result = *(int *) op1->current_value || *(int *) op2->current_value;
        int * res_point = (int *) malloc(sizeof(int));
	*res_point = result; 
	return res_point;
    }
    default:   type_error(op1->line_num); return NULL;
  }

}


void * s_eq(struct exp_node * op1, struct exp_node * op2)
{
  assert(op1 != NULL);
  assert(op2 != NULL);
  enum type type = op1->type;

  switch(type)
  {
    case INT: 
    {
	int result = *(int *) op1->current_value == *(int *) op2->current_value;
        int * res_point = (int *) malloc(sizeof(int));
	*res_point = result; 
	return res_point;
    }

    case BOOL:
    {
	int result = *(int *) op1->current_value == *(int *) op2->current_value;
        int * res_point = (int *) malloc(sizeof(int));
	*res_point = result; 
	return res_point;
    }
    default:   type_error(op1->line_num); return NULL;
  }

}

void * s_neq(struct exp_node * op1, struct exp_node * op2)
{
  assert(op1 != NULL);
  assert(op2 != NULL);
 enum type type = op1->type;
  switch(type)
  {
    case INT: 
    {
	int result = *(int *) op1->current_value != *(int *) op2->current_value;
        int * res_point = (int *) malloc(sizeof(int));
	*res_point = result; 
	return res_point;
    }
    case BOOL:
    {
	int result = *(int *) op1->current_value != *(int *) op2->current_value;
        int * res_point = (int *) malloc(sizeof(int));
	*res_point = result; 
	return res_point;
    }
    default:   type_error(op1->line_num); return NULL;
  }

}

void * s_seq(struct exp_node * op1, struct exp_node * op2)
{
  assert(op1 != NULL);
  assert(op2 != NULL);
  enum type type = op1->type;
  switch(type)
  {
    case INT:
    {
	int result = *(int *) op1->current_value <= *(int *) op2->current_value;
        int * res_point = (int *) malloc(sizeof(int));
	*res_point = result; 
	return res_point;
    }
    default:   type_error(op1->line_num); return NULL;
  }

}

void * s_leq(struct exp_node * op1, struct exp_node * op2)
{
  assert(op1 != NULL);
  assert(op2 != NULL);
  enum type type = op1->type;
  switch(type)
  {
    case INT:
    {
	int result = *(int *) op1->current_value >= *(int *) op2->current_value;
        int * res_point = (int *) malloc(sizeof(int));
	*res_point = result; 
	return res_point;
    }
    default:   type_error(op1->line_num); return NULL;
  }

}

void * s_less(struct exp_node * op1, struct exp_node * op2)
{
  assert(op1 != NULL);
  assert(op2 != NULL);
  enum type type = op1->type;
  if(construct_name_table) return NULL;
  switch(type)
  {
    case INT:
    {
	int result = *(int *) op1->current_value < *(int *) op2->current_value;
        int * res_point = (int *) malloc(sizeof(int));
	*res_point = result; 
	return res_point;
    }
    default: type_error(op1->line_num); return NULL;
  }

}

void * s_greater(struct exp_node * op1, struct exp_node * op2)
{
  assert(op1 != NULL);
  assert(op2 != NULL);
  switch(op1->type)
  {
    case INT: 
    {
	int result = *(int *) op1->current_value > *(int *) op2->current_value;
        int * res_point = (int *) malloc(sizeof(int));
	*res_point = result; 
	return res_point;
    }
    default: type_error(op1->line_num); return NULL;
  }

}

void allocate_array(struct exp_node * node)
{
  assert(node->is_array);
  index_list_t * dimensions = node->data.dimensions;
  index_t * it = dimensions->sentinel->prev; 
  int total_alloc_size = 1;
  while(it != dimensions->sentinel)
  {
	//If size type is not int, should be error.
	assert(it->size->type == INT);
	traverse(it->size);

        total_alloc_size = total_alloc_size * (* (int *) it->size->current_value);
	it = it->prev;
  }
  switch(node->type)
  {
	case BOOL:
	case INT: 
  	{	//node->current_value = malloc(total_alloc_size * sizeof(int));
		char command[80];
		sprintf(command, "ldr r0, =#%d\n", total_alloc_size * sizeof(int));
		add_to(text_section, command);
		add_to(text_section, "bl malloc\n");

		break;
	}
	case STR:
	{
		char command[80];
		sprintf(command, "ldr r0, =#%d\n", total_alloc_size * sizeof(char *));
		add_to(text_section, command);
		add_to(text_section, "bl malloc\n");
		break;
	}
	default: yyerror("Unhandled array type."); break;

  }
}



void s_asgn(void * abstract_arg)
{
  struct exp_node * arg = (struct exp_node *) abstract_arg;
  struct exp_node * left_value = arg->data.left;
  struct exp_node * right_value = arg->data.right;
  assert(right_value != NULL);
  //assert(left_value->is_id || left_value->is_array_entry);
  if(right_value->is_array)
  {
     allocate_array(right_value);
  }

  if(left_value->is_array_entry)
  {
     ListNode * array_name_entry = llist_find_node(current_scope->name_table, left_value->data.array_entry->array_name);
     assert(array_name_entry != NULL);
     char command[80];
     char *name_array = array_name_entry->value; //Contains the array name.
     sprintf(command, "ldr r4, =%s\n", name_array);
	//We have to find the location of the array entry.
     add_to(text_section, command);
     add_to(text_section, "ldr r4, [r4]\n");
     expr_codegen(left_value->data.array_entry->index->sentinel->next->size); //This outputs content to r0. We are getting the first index here.

     void * array = array_name_entry->real_value;

     switch(array_name_entry->type)
     {
	case BOOL:
	case INT: 
	{ 
		char put_offset[80];
		sprintf(put_offset, "ldr r2, =#%d\n", sizeof(int));
		add_to(text_section, put_offset);
		break;
	}
	case STR:
	{ 
		char put_offset[80];
		sprintf(put_offset, "ldr r2, =#%d\n", sizeof(char *));
		add_to(text_section, put_offset);
		break;

		break;
	}
	default: yyerror("Unknown array type"); return;
     }
        char calc_offset[80];
		//Moving the offset to r1. 
	sprintf(calc_offset, "mul r1, r0, r2\n");
	add_to(text_section, calc_offset);
	add_to(text_section, "add r0, r4, r1\n");
	add_to(text_section, "mov r1, r0\n");
	//r0 have real location. Now we will get the value of the right.
	expr_codegen(right_value);
	add_to(text_section, "str r0, [r1]\n"); //Stores there. 
  }
  else
  {
    //update_var(current_scope->name_table, left_value->data.var_name, right_value->current_value);

    expr_codegen(right_value);
    if(left_value -> operation == IN) //It is a property or method.
    {
	add_to(text_section, "mov r1, r0\n"); //Moving result value to r1 because it will get overwritten otherwise.
	prop_codegen(left_value);
        add_to(text_section, "ldr r1, [r0]\n");
	return;
    }

    ListNode * var_node = llist_find_node(current_scope->name_table, left_value->data.var_name);
    //TODO: Expand to other types.
    switch(var_node->type)
    {
	case BOOL:
	case INT:
	{
    		char load[50];
		//Expression result should be in r0.
		if(right_value->is_array)
		{
			char command[80];
			sprintf(command, "ldr r4, =%s\n", var_node->value);
			add_to(text_section, command);
			add_to("str r0, [r4]\n");
		}
		else
		{
    			sprintf(load, "mov r4, r0\n");
    			add_to(text_section, load);
		}
		break;

	}
	case STR:
	{
		add_to(text_section, "mov r4, r0\n");
		break;
	}
	case CLASS:
	{
		//expr_codegen should handle this. r0 has class address. 
		add_to(text_section, "mov r4, r0\n");
		break;
	}
    }

    
    char store[50];
    sprintf(store, "str r4, [fp, #%d]\n", -1 * var_node->offset);
    add_to(text_section, store);
  }
}

char * find_prop_name(struct exp_node * node)
{
  if(node == NULL) return NULL;
  if(node->operation != IN)
  {
	return node->data.var_name;
  }
  struct exp_node * it = node;
  while(it->data.left)
  {
	it = it->data.left;
  }
  return it->data.var_name;
}


//After code generated, the address will be in r0.
void prop_codegen(struct exp_node * node)
{
  char * var_name = node->data.left->data.var_name;
  char * prop_name = find_prop_name(node->data.right);
  ListNode * class_var_node = llist_find_node(current_scope->name_table, var_name);
  class_t * info = get_class_info(class_var_node->class_id);

  ListNode * var_node = llist_find_node(info->scope->name_table, prop_name);

  //Find offset of prop_name
  char read_var[80];
  sprintf(read_var, "ldr r4, =%s\n", var_name);
  add_to(text_section, read_var);
  add_to(text_section, "ldr r4, [r4]\n"); //Getting base address.
  int prop_offset = var_node->offset;
  char add_offset[80];
  sprintf(add_offset, "ldr r1, =#%d\n", prop_offset);
  //Now the address is in r0.
  add_to(text_section, add_offset);
  add_to(text_section, "add r0, r4, r1\n");


}



void s_decl(void * abstract_arg)
{
  exp_node_list_t * arg = (exp_node_list_t *) abstract_arg;
  //Arg left cannot be null because it is the variable.
  assert(arg != NULL);
  assert(arg->head != NULL);
  exp_node_link_t * current_link = arg->head;
  while(current_link)
  {
    struct exp_node * current_node = current_link -> current;
    //traverse(current_node);
    struct exp_node * id_leaf = current_node->data.left;
    struct exp_node * assign = current_node->data.right;
    if(assign == NULL)
    {
      add_var_to_table(current_scope->name_table, id_leaf->data.var_name, id_leaf->type, NULL);
      if(!construct_name_table)
      {
      	char var_decl[20 + strlen(id_leaf->data.var_name)];
      	sprintf(var_decl, "%s: .word 0\n", id_leaf->data.var_name);
      	add_to(data_section, var_decl);
      }

    }
    else
    {

      if(assign->is_array)
      {
	if(construct_name_table)
	{
		add_var_to_table(current_scope->name_table, id_leaf->data.var_name, id_leaf->type, NULL); //The value is null because we don't know the pointer until runtime.
	}	
	else
	{
		char var_decl[20 + strlen(id_leaf->data.var_name)];
		sprintf(var_decl, "%s: .word 0\n", id_leaf->data.var_name);
		add_to(data_section, var_decl);

		allocate_array(assign);

		char command[80];
		//Load array address.
		sprintf(command, "ldr r4, =%s\n", id_leaf->data.var_name);
		add_to(text_section, command);
		add_to(text_section, "str r0, [r4]\n");

		ListNode * just_added_array = llist_find_node(current_scope->name_table, id_leaf->data.var_name);
		just_added_array->dim_capacity_list = assign -> data.dimensions;
	}		
	
      }
      else
      {
        if(assign->type == CLASS && id_leaf->type == CLASS)
	{
		if(construct_name_table)
		{
			ListNode * node = (ListNode *) malloc(sizeof(ListNode));
			node->value = id_leaf->data.var_name;
			node->type = CLASS;
			node->class_id = assign->associated_class;
			id_leaf->associated_class = assign->associated_class;
			node->real_value = assign->current_value; //Can be null.
			add_node_to_table(current_scope->name_table, node);	
		}
		else
		{
			char var_decl[20 + strlen(id_leaf->data.var_name)];
			sprintf(var_decl, "%s: .word 0\n", id_leaf->data.var_name);
			add_to(data_section, var_decl);

			ListNode * node = llist_find_node(current_scope->name_table, id_leaf->data.var_name);
			char get_var[80];
			sprintf(get_var, "ldr r4, =%s\n", node->value);	
			add_to(text_section, get_var);
			
			class_t * curr_class = get_class_info(node->class_id);
			int obj_size = calc_class_size(curr_class);
				
			char put_size[80];
			sprintf(put_size, "ldr r0, =#%d\n", obj_size);
			add_to(text_section, put_size);
			add_to(text_section, "bl malloc\n");
			add_to(text_section, "str r0, [r4]\n"); //Putting obj into its base address.	
		}

	}
	else
	{
		add_var_to_table(current_scope->name_table, id_leaf->data.var_name, id_leaf->type, assign->current_value);

		if(!construct_name_table)
		{
			ListNode * node = (ListNode *) llist_find_node(current_scope->name_table, id_leaf->data.var_name);

			switch(id_leaf->type)
			{
				//TODO: Add others.
				case BOOL:
				case INT:
				{
					char var_decl[20 + strlen(id_leaf->data.var_name)];
					sprintf(var_decl, "%s: .word %d\n", id_leaf->data.var_name, * (int *) assign->current_value);
					add_to(data_section, var_decl);
					break;
				}
				case STR:
				{
					char * value = (char *) assign->current_value;
					char var_decl[20 + strlen(id_leaf->data.var_name)];
					sprintf(var_decl, "%s: .word 0\n", id_leaf->data.var_name);
					add_to(data_section, var_decl);
					//Malloc space for string.
					int len = strlen(value) + 1;
					char malloc_space[80];
					sprintf(malloc_space, "mov r0, #%d\n", len);
					add_to(text_section, malloc_space);
					add_to(text_section, "bl malloc\n");
					char address[20 + strlen(id_leaf->data.var_name)];
					sprintf(address, "ldr r4, =%s\n", id_leaf->data.var_name);
					add_to(text_section, address);
					//Store pointer to memory pointed by r4.
					add_to(text_section, "str r0, [r4]\n");
					
					//Setting the string
					for(int i = 0; i < len - 1; i++)
					{
					  char get_char[50];
					  sprintf(get_char, "mov r1, #%d\n", (int) value[i]);

					
					  char put_char[50];
					  sprintf(put_char, "strb r1, [r4, #%d]\n", i); //Store char in position i.
			
					  add_to(text_section, get_char);	
					  add_to(text_section, address);
					  add_to(text_section, "ldr r4, [r4]\n");
					  add_to(text_section, put_char);
					}
				        //Null terminate.
					char null_ter[50];
				        sprintf(null_ter, "strb r1, [r4, #%d]\n", len - 1);

				        add_to(text_section, "mov r1, #0\n");
					add_to(text_section, null_ter);
					add_to(text_section, address);
					add_to(text_section, "ldr r4, [r4]\n");
					char update_stack[60];
					sprintf(update_stack, "str r4, [fp, #%d]\n", -1 * node->offset);
					add_to(text_section, update_stack);
					break;
				}		
			}

		}

	}

      }


    }

    current_link = current_link -> next;
  }

}

/*Empty method, declares stmt type.*/
void s_invoke(void * abstract_arg)
{
 /* struct exp_node * node = (struct exp_node *) abstract_arg;
  assert(node->is_method);
  char * method_name = node->data.var_name;
  char * class_name = node->associated_class;
  class_t * info = get_class_info(class_name);
  ListNode * method_node = llist_find_node(info->scope->name_table, method_name);
  assert(method_node != NULL);
  method_t * method_info = (method_t *) method_node->real_value;
  assert(method_info != NULL);
  execute(method_info->statement);*/
}


//Fake executes to see if there is any error.
int traverse_for_errors(stmt_node_t * list)
{
  if(list == NULL) return 0;
  assert(list->type == LIST || list->type == PRO);
  stmt_node_t * current;
  scope_t * prev_scope = NULL;
  if(list->type == LIST)
  {
          current = list->list_head;
	  if(list->scope != current_scope)
	  {
	      if(list->scope->parent == current_scope)
	      {
		  scope_inherit(current_scope, list->scope);
		  prev_scope = current_scope;
		  current_scope = list->scope;	
	      }
	      else //Method or class scope.
	      {
		prev_scope = current_scope;
		current_scope = list->scope;
		if(current_scope->parent != NULL)
		{
		  scope_inherit(current_scope->parent, current_scope);
		}
	      }
	  }
  }
  else
  {
    current = list;
  }

  assert(current_scope != NULL);
  while(current)
  {
    switch(current->type)
    {
	case PRO: 
	{  
	    if(current->invoke != NULL)
	    {
	        if(current->arg_is_expr)
	        {
		  int status = traverse((struct exp_node *) current->arg);
	          if(status != 0) break;
	        }
		int status = check_stmt_errors(current);
	        if(status != 0) break;
		if(current->invoke == s_asgn || current->invoke == s_decl)
		{
	          current->invoke(current->arg);	      
		}
	    }
	    break;
	}
	case LIST: 
	{
	    traverse_for_errors(current);
	    break;
	}
	case IF:
	{
	    if_node_t * node = current->if_node;
	    assert(node != NULL);
	    traverse(node->expression);
	    if(node->expression->type != BOOL)
	    {
		type_error(current->line_no);
		break;
            }
	    struct exp_node * exp = node->expression;
	    if(exp->current_value == NULL)
	    {
		type_error(exp->line_num);
		break;
	    }
	    traverse_for_errors(node->if_list);
	    traverse_for_errors(node->else_list);
	    break;
	}
	case WHILE: 
	{
		while_node_t * node = current->while_node;
		assert(node !=NULL);
		traverse(node->expression);
	    	if(node->expression->type != BOOL)
	    	{
			type_error(node->expression->line_num);
			break;
            	}
	   	traverse_for_errors(node->list);
	}
	default: /*type_error();*/ break;
		
    }
    current = current->next;
  }
  
if(prev_scope != NULL)
  {
    current_scope = prev_scope;
  }

}
//return 0 if not errors, return 1 if error.
int check_stmt_errors(stmt_node_t * stmt)
{
  if(stmt->invoke == s_decl)
  {
	  exp_node_list_t * arg = (exp_node_list_t *) stmt->arg;
	  //Arg left cannot be null because it is the variable.
	  exp_node_link_t * current_link = arg->head;
	  while(current_link)
	  {
	    struct exp_node * current_node = current_link -> current;
	    if(current_node->data.right != NULL)
	    {
	      if(current_node->data.left->type != current_node->data.right->type)
	      {
		  type_error(current_node->line_num);
		  return 1;
	      }
	    }

	    traverse(current_node->data.right);
	    current_link = current_link->next;
	  }

  }
  else if(stmt->invoke == s_asgn)
  {
  	struct exp_node * arg = (struct exp_node *) stmt->arg;
  	struct exp_node * left_value = arg->data.left;
  	struct exp_node * right_value = arg->data.right;
	/*if(left_value->type != right_value->type) Assign node olusurken check ediliyor olmasi lazim.
	{
	    type_error();
	    return;
	}*/
	//You might want to use type info for catching this.
	  /*if(right->is_array && $1->dim_len != $4->data.dim_len)
	  {
	    type_error();
	    return;

	  }*/
  	if(left_value->is_array_entry)
  	{
     		ListNode * array_name_entry = llist_find_node(current_scope->name_table, left_value->data.array_entry->array_name);
    		assert(array_name_entry != NULL);
    		void * array = array_name_entry->real_value;
     		if(right_value->type != array_name_entry->type)
     		{
        		type_error(stmt->line_no);
        		return 1;
     		}

     		int real_index = find_value_of_index(left_value->data.array_entry->index, array_name_entry->dim_capacity_list);
   		if(real_index < 0)
		{
			type_error(stmt->line_no);
			return;
		} 
	}
  }
  else if(stmt->invoke == s_print)
  {	
	struct exp_node * node = (struct exp_node *) stmt->arg;
	if(node->is_array)
	{
		type_error(stmt->line_no);
		return 1;
	}
  }
  else if(stmt->invoke == s_println)
  {
	struct exp_node * node = (struct exp_node *) stmt->arg;
	if(node->is_array)
	{
		type_error(stmt->line_no);
		return 1;
	}
  } 
  else if(stmt->invoke == s_invoke){}
  else
  {
	printf("methof not found\n");
	return 1;
  }
  return 0;
}

void stack_push(struct exp_node * node)
{
  assert(stack_header < GLOBAL_STACK_SIZE);
  stack[stack_header + 1] = node;
  stack_header++;
}

struct exp_node * stack_pop()
{
  //stack is empty.
  if(stack_header == -1)
  {
    return NULL;
  }
  struct exp_node * result = stack[stack_header];
  stack_header--;
  return result;
}

//Add to data section in assembly.
//Section can be data_section or text_section.
void add_to(char ** section, char * str)
{
  if(* section == NULL)
  {
	int len = strlen(str);
	* section = (char *) malloc((len + 1) * sizeof(char));
	strncpy(* section, str, len);
	(*section)[len] = 0;
  }
  else
  {
	int add_len = strlen(str);
	int cur_len = strlen(* section);
	* section = (char *) realloc(* section, (add_len + cur_len + 1) * sizeof(char));
	strncpy(&(* section)[cur_len], str, add_len);
	(* section)[cur_len + add_len] = 0;
  }
}


void init_data_section()
{
	add_to(data_section, "println_int_format: .asciz \"%%d\\n\"\n");
	add_to(data_section, "print_int_format: .asciz \"%%d\"\n");
	add_to(data_section, "println_str_format: .asciz \"%%s\\n\"\n");
	add_to(data_section, "print_str_format: .asciz \"%%s\"\n");
	add_to(data_section, "bool_true: .asciz \"true\"\n");
	add_to(data_section, "bool_false: .asciz \"false\"\n");
}

char * create_temp()
{
   char num_string[30];
   sprintf(num_string, "%d", temp_counter);
   int len = strlen(num_string);
   char * var_name = (char *) malloc((len + 3) * sizeof(len));
   sprintf(var_name, "_t%s", num_string);
   char data_decl[50];
   sprintf(data_decl, "%s: .word 0\n", var_name);
   add_to(data_section, data_decl);
   temp_counter++;
   return var_name;
}

//The value of the symbol will be stored in r0.
//NOTE: Value stored in stack.
void symbol_codegen(ListNode * id_node)
{
  assert(id_node);
  char assembly_load[50];
  int offset = id_node->offset;
  sprintf(assembly_load, "ldr r0, [fp, #%d]\n", -1 * offset);
  add_to(text_section, assembly_load);
}

void expr_codegen(struct exp_node * node)
{
  if(node == NULL) return;

  if(node->operation == IN) //We have to catch properties first. 
  {
	//Put address to r0.
        prop_codegen(node);
	add_to(text_section, "ldr r0, [r0]\n");
	return;
  }
  else if(node->is_leaf)
  {
  	if(node->is_id)
  	{
		ListNode * entry = llist_find_node(current_scope->name_table, node->data.var_name);
		symbol_codegen(entry);
  	}
	else if(node->is_array_entry)
	{
		array_entry_t * entry = node->data.array_entry;
		ListNode * array_entry = llist_find_node(current_scope->name_table, entry->array_name);
		char read_array[80];
		sprintf(read_array, "ldr r4, =%s\n", entry->array_name);
		add_to(text_section, read_array);
		add_to(text_section, "ldr r4, [r4]\n");
		expr_codegen(entry->index->sentinel->next->size);
		//We have array index at r0. Calculate offset.
		int size_type = 0;
		switch(array_entry->type)
		{
			case BOOL : 
			case INT : size_type = sizeof(int); break;
			case STR : size_type = sizeof(char *); break;
			default: assert(0); break;
		}
		node->type = array_entry->type; //Updating type info here for future uses.
		char put_offset[80];	
		sprintf(put_offset, "ldr r1, =#%d\n", size_type);
		add_to(text_section, put_offset);
		add_to(text_section, "mul r1, r1, r0\n");
		//Go to exact array position.
		add_to(text_section, "add r0, r4, r1\n");
		//Read from array and write to result.
		add_to(text_section, "ldr r0, [r0]\n"); 
	}
	else
	{
		switch(node->type)
		{
		  case BOOL:
		  case INT:
		  {
		    int value = * (int * ) node->data.value; 
		    //Split up 32 bit number to be 2 16 bit numbers.
		    char split_right[50];
		    sprintf(split_right, "ldr r0, =#%d\n", value);
		    add_to(text_section, split_right);
		    break;
		  }
		  case STR:
		  {
		    char * value = (char *) node->data.value;
		    char * str_literal = generate_str_literal();
		    node->has_temp_var = 1;
		    node->temp_var = str_literal;
		    char lit_decl[80]; 
		    sprintf(lit_decl, "%s: .asciz \"%s\"\n", str_literal, value);
		    add_to(data_section, lit_decl);
		    char load_ins[80];
		    sprintf(load_ins, "ldr r0, =%s\n", str_literal);
		    add_to(text_section, load_ins);
		    //add_to(text_section, "ldr r0, [r0]\n");
		    break;
	 	  }
		  case CLASS:
		  {
			if(node->is_constructed)
			{	
				class_t * curr_class = get_class_info(node->associated_class);
				int obj_size = calc_class_size(curr_class);
					
				char put_size[80];
				sprintf(put_size, "ldr r0, =#%d\n", obj_size);
				add_to(text_section, put_size);
				add_to(text_section, "bl malloc\n");
				//r0 has class address location
			}	
			//else might be method call. id is already handled in first if. 		
		  }
		}
	}

  }
  else
  {
	struct exp_node * left = node->data.left;
	struct exp_node * right = node->data.right;
	//r0 has the final value of the expression.
	//In assign, we don't care the value of the var in left hand side.
	if(node->operation != ASGN)
	{
	  expr_codegen(left);
	  if(!left->has_temp_var)
	  {
	     add_to(text_section, "mov r1, r0\n");
          }
	  else
	  {
	     char * var = left->temp_var;
	     char stmt[50];
	     sprintf(stmt, "ldr r4, =%s\n", var);
	     add_to(text_section, stmt);
	     if(left != NULL && left->type != STR ) add_to(text_section, "ldr r1, [r4]\n");
 	     else add_to(text_section, "mov r1, r4\n");
	  }

	} 
	if(right != NULL)
	{
		expr_codegen(right);
		if(right->has_temp_var)
		{
		     char * var = right->temp_var;
		     char stmt[50];
		     sprintf(stmt, "ldr r4, =%s\n", var);
		     add_to(text_section, stmt);
		     if(right->type != STR) add_to(text_section, "ldr r0, [r4]\n");
		     else add_to(text_section, "mov r0, r4\n");
		}
	}

	char operation[50];
	char store_temp[50];
	char * var = create_temp();
	enum type type = left->type;
        //r0 have right operand, r1 have left operand.
	switch(node->operation)
	{
		
		case ADD:
		{
			switch(type)
			{
				case INT: add_to(text_section,"add r0, r0, r1\n"); break;
				case STR:
				{
					//Allocate new space for the dest using malloc.
					char * concat_string = generate_str_literal();
					char data_decl[80];
					sprintf(data_decl, "%s: .word 0\n", concat_string);
					add_to(data_section, data_decl);
					//r0 and r1 has the pointers. Move them.
					//r4, r5 => left, right operand.
					//r6, r7 => lengths of strings.
					//r4, r5 will have pc relative addresses.
					add_to(text_section, "mov r4, r1\n");
					add_to(text_section, "mov r5, r0\n");
					add_to(text_section, "mov r0, r4\n");
					add_to(text_section, "bl strlen\n");
					add_to(text_section, "mov r6, r0\n");

					add_to(text_section, "mov r0, r5\n");
					add_to(text_section, "bl strlen\n");
					add_to(text_section, "mov r7, r0\n");
					add_to(text_section, "add r0, r6, r7\n");
					add_to(text_section, "add r0, r0, #1\n");
					add_to(text_section, "bl malloc\n");
					char addr_load[80];
					sprintf(addr_load, "ldr r3, =%s\n", concat_string);
					add_to(text_section, addr_load);
					add_to(text_section, "str r0, [r3]\n");
					//strcpy yap. r0=>dest (malloc pointer) r1=>source (first operand)
					add_to(text_section, "mov r1, r4\n");
					add_to(text_section, "bl strcpy\n");
					add_to(text_section, "mov r1, r5\n");
					add_to(text_section, "bl strcat\n");
					break;
				}
			}

			break;

		} 

		case SUB:  
			add_to(text_section,"sub r0, r1, r0\n");
			break;
		case MUL:  
			add_to(text_section,"mul r0, r0, r1\n");
			break;
		case DIV:  
			break;
		case NGT:
			add_to(text_section,"eor r0, r0, #1\n");
			break; 
		case PLU:
			break;
		case MIN:
			add_to(text_section,"neg r0, r0\n");
			break;  
		case AND:
			add_to(text_section,"and r0, r0, r1\n");
			node->type = BOOL;
			break;
		case OR:
			add_to(text_section,"orr r0, r0, r1\n");
			node->type = BOOL;
			break;
		case SME:
		case LRE:
		case EQU:
		case NEQ:
		case LE:
		case GR:
			logic_op_codegen(node->operation);
			node->type = BOOL; 
			break;
		case IN: 
		{
			assert(0);
			/*struct exp_node * left = node->data.left;
			struct exp_node * right = node->data.right;
			expr_codegen(right);
			//left burada orijinal id, right ise property.
			assert(left->is_id);
			char * obj_name = left->data.var_name;
			char * property_name = right->data.var_name;
			class_t * class_info = get_class_info(right->associated_class);
			ListNode * prop_node = llist_find_node(class_info->scope->name_table, right->data.var_name);	
			//Get only offset info from the name table.
			int offset = prop_node->offset;
			//TODO: Continue from here.
			
			char get_obj[80];
			sprintf(get_obj, "ldr r4, =%s\n", obj_name);
			add_to(text_section, get_obj);
			add_to(text_section, "ldr r4, [r4]\n");
			
			char calc_offset[80];
			sprintf(calc_offset, "add r4, r4, =#%d\n", offset);
			add_to(text_section, calc_offset);

			add_to(text_section, "ldr r0, [r4]\n"); //Reading the value stored.
			break;*/
		}
		case ASGN: return 0;
                case UNDEF: return 1;
	
		default: /*type_error();*/ break;	
	}

	sprintf(store_temp, "ldr r4, =%s\n", var);
	add_to(text_section, store_temp);
	char store[50];
	sprintf(store, "str r0, [r4]\n", var);

	node->has_temp_var = 1;
	node->temp_var = var;
	add_to(text_section, store);
  }
}

//Calculates how much memory we need for the method local variables. Also updates the offset for each variable.
int calc_method_size(stmt_node_t * list)
{
  assert(list->type == LIST);
  //Iterate over list's name table. 
  LinkedList * name_table = list->scope->name_table;
  ListNode * it = name_table->head;
  int current_offset = 4; //Start from four offset because at the bottom of the stack we want to have the frame pointer.
  while(it)
  {
    switch(it->type)
    {
	case BOOL:
	case INT:
	{
		current_offset += 4;
		break;
	}
	case STR:
	{
		//TODO: Store string pointer.
	        current_offset += 4;
		break;
	}
	case CLASS:
	{
		//TODO: Allocate for objects
		break;
	}
	default: assert(0);
    }
    it->offset = current_offset;
    it = it->next;
  }
  //For every variable, update their offset.
  return current_offset;
}

int calc_class_size(class_t * class)
{
  LinkedList * name_table = class->scope->name_table;
  ListNode * it = name_table->head;
  int current_offset = 4;
  while(it)
  {
    switch(it->type)
    {
	case BOOL:
	case INT:
	case STR:
	        current_offset += 4;
		break;
	case CLASS:
	{
		//Find class node by class name metodu yaz.
		//current_offset += calc_class_size(find)
	}
    }
    it->offset = current_offset;
    it = it->next;
  }
  return current_offset;	
}

//Puts the variables in the respective offsets in the assembly code.
void method_first_codegen(stmt_node_t * list)
{
  assert(list->type == LIST);
  //Iterate over list's name table. 
  LinkedList * name_table = list->scope->name_table;
  ListNode * it = name_table->head;
  while(it)
  {
    int current_offset = it->offset;
    char command[50];
    sprintf(command, "ldr r2, =%s\n", it->value); 
    add_to(text_section, command);
    //We are storing the value in stack, thus we have to dereference the address before storing.
    //YOU MIGHT NOT DO THIS IN STRING VARIABLES.
    add_to(text_section, "ldr r2, [r2]\n");
    char command2[50];
    sprintf(command2, "str r2, [fp, #%d]\n", -1 * current_offset); 
    add_to(text_section, command2);
    it = it->next;
  }
}

char * generate_label(label_purpose_t purpose)
{
  //char * to_be_written[50];
  char to_be_written[50];
  switch(purpose)
  {
	case TRUE_P:
	{
		sprintf(to_be_written, "_true%d", g_label_counter[TRUE_P]++);
		break;
	}
	case FALSE_P:
	{
		sprintf(to_be_written, "_false%d", g_label_counter[FALSE_P]++);
		break;
	}
	case WHILE_P:
	{
		sprintf(to_be_written, "_while%d", g_label_counter[WHILE_P]++);
		break;
	}
	case ENDIF_P:
	{
		sprintf(to_be_written, "_endif%d", g_label_counter[ENDIF_P]++);
		break;
	}
	case ENDWHILE_P:
	{
		sprintf(to_be_written, "_endwhile%d", g_label_counter[ENDWHILE_P]++);
		break;
	}

  }
  int len = strlen(to_be_written);
  char * result = malloc((len + 1) * sizeof(char));
  strncpy(result, to_be_written, len);
  result[len] = 0;
  return result;
}

char * generate_str_literal()
{
	char to_be_wr[50];
	sprintf(to_be_wr, "_strlt%d", str_literal_counter++);
  	int len = strlen(to_be_wr);
  	char * result = malloc((len + 1) * sizeof(char));
  	strncpy(result, to_be_wr, len);
  	result[len] = 0;
  	return result;
}

void logic_op_codegen(enum op op)
{
	//Make sure it is logic operations.
	char var_str[80];

	char * endif_label = generate_label(ENDIF_P);
	char * true_label = generate_label(TRUE_P);
	char * false_label = generate_label(FALSE_P);

	switch(op)
	{
		
		case SME:
			sprintf(var_str, "ble %s\n", true_label);
			break;
		case LRE:
			sprintf(var_str, "bge %s\n", true_label);
			break;
		case EQU:
			sprintf(var_str, "beq %s\n", true_label);
			break;
		case NEQ:
			sprintf(var_str, "bne %s\n", true_label);
			break;
		case LE:
			sprintf(var_str, "blt %s\n", true_label);
			break;
		case GR:
			sprintf(var_str, "bgt %s\n", true_label);
			break;
	}




	add_to(text_section,"cmp r1, r0\n");
	add_to(text_section, var_str);
	char label_decl2[50];
	sprintf(label_decl2, "%s:\n", false_label);
	add_to(text_section, label_decl2);
	add_to(text_section, "mov r0, #0\n");
	char jump2[50];
	sprintf(jump2, "b %s\n", endif_label);
	add_to(text_section, jump2);
	char label_decl[50];
	sprintf(label_decl, "%s:\n", true_label);
	add_to(text_section, label_decl);
	add_to(text_section, "mov r0, #1\n");
	char jump[50];
	sprintf(jump, "b %s\n", endif_label);
	add_to(text_section, jump);

	char label_decl3[50];
	sprintf(label_decl3, "%s:\n", endif_label);
	add_to(text_section, label_decl3);
}

void declare_label(char * label)
{
  char decl[80];
  sprintf(decl, "%s:\n", label);
  add_to(text_section, decl);
}

int main(int argc, char** argv)
{
  #ifdef MYDEBUG
	yydebug = 1;
  #endif
  
  yyin = fopen(argv[1], "r");
  yyparse();
  fclose(yyin);
  assert(program != NULL);
  method_t * main_method = llist_find(program->main_class->scope->name_table, "main");
  stmt_node_t * main_stmt_list = main_method->statement;
  current_scope = main_stmt_list->scope;
  traverse_for_errors(main_stmt_list);
  construct_name_table = 0; //Stop doing the name tables.
  current_scope = main_stmt_list->scope;

  if(!type_violation_found)
  {
    char * filename = strdup(argv[1]);
    int len = strlen(filename);
    char * file_without_ext = malloc((len-2) * sizeof(char));
    strncpy(file_without_ext, filename, len - 5);
    strncpy(&file_without_ext[len-5], ".s", 2);
    file_without_ext[len-3] = 0;
    gen_file = fopen(file_without_ext, "w+");

     data_section = (char **) malloc(sizeof(char *));
     text_section = (char **) malloc(sizeof(char *));
     * data_section = NULL;
     * text_section = NULL;

     //Main args should be the first var added to the main table.
     //If not, use llist_find
     ListNode * args_node = llist_find_node(main_stmt_list->scope->name_table, main_args_name);
     assert(args_node != NULL);
     char args_decl[80];
     sprintf(args_decl, "%s: .word 0\n", args_node->value);
     add_to(data_section, args_decl);
     char args_call[80];
     sprintf(args_call, "ldr r4, =%s\n", args_node->value);
     add_to(text_section, args_call);
     add_to(text_section, "str r1, [r4]\n");
    setup_execute(main_stmt_list);
    fprintf(gen_file, ".section .data\n");
    init_data_section();
    if(data_section != NULL) fprintf(gen_file, *data_section);
    fprintf(gen_file, ".section .text\n");
    fprintf(gen_file, ".global main\n");
    fprintf(gen_file, ".balign 4\n");
    //The start (main) routine.
    fprintf(gen_file, "main: \n");
    fprintf(gen_file, "push {lr}\n");
    if(text_section != NULL) fprintf(gen_file, *text_section);
    if(data_section != NULL) free(data_section);
    if(text_section != NULL) free(text_section);
    fprintf(gen_file, "pop {pc}\n");
  }
  fclose(gen_file);
}
