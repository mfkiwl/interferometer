/* A Bison parser, made by GNU Bison 3.4.2.  */

/* Bison implementation for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015, 2018-2019 Free Software Foundation,
   Inc.

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

/* Undocumented macros, especially those whose name start with YY_,
   are private implementation details.  Do not rely on them.  */

/* Identify Bison output.  */
#define YYBISON 1

/* Bison version.  */
#define YYBISON_VERSION "3.4.2"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 1

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1


/* Substitute the variable and function names.  */
#define yyparse         urj_vhdl_parse
#define yylex           urj_vhdl_lex
#define yyerror         urj_vhdl_error
#define yydebug         urj_vhdl_debug
#define yynerrs         urj_vhdl_nerrs


/* First part of user prologue.  */
#line 127 "vhdl_bison.y"

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <ctype.h>

#include <urjtag/part.h>

#include "bsdl_sysdep.h"

#include "bsdl_types.h"
#include "bsdl_msg.h"

/* interface to flex */
#include "vhdl_bison.h"
#include "vhdl_parser.h"

#ifdef DMALLOC
#include "dmalloc.h"
#endif

#define HACK priv_data->scanner
int yylex (YYSTYPE *, void *);

#if 1
#define ERROR_LIMIT 15
#define BUMP_ERROR \
    do { \
        if (urj_vhdl_flex_postinc_compile_errors (priv_data->scanner) > ERROR_LIMIT) \
        { \
            Give_Up_And_Quit (priv_data); \
            YYABORT; \
        } \
    } while (0)
#else
#define BUMP_ERROR \
    do { \
        Give_Up_And_Quit (priv_data); \
        YYABORT; \
    } while (0)
#endif

static void Init_Text (urj_vhdl_parser_priv_t *);
static void Store_Text (urj_vhdl_parser_priv_t *, char *);
static void Print_Error (urj_vhdl_parser_priv_t *, const char *);
static void Give_Up_And_Quit (urj_vhdl_parser_priv_t *);

/* VHDL semantic action interface */
static void urj_vhdl_set_entity (urj_vhdl_parser_priv_t *, char *);
static void urj_vhdl_port_add_name (urj_vhdl_parser_priv_t *, char *);
static void urj_vhdl_port_add_bit (urj_vhdl_parser_priv_t *);
static void urj_vhdl_port_add_range (urj_vhdl_parser_priv_t *, int, int);
static void urj_vhdl_port_apply_port (urj_vhdl_parser_priv_t *);

//static void set_attr_bool (urj_vhdl_parser_priv_t *, char *, int);
static void set_attr_decimal (urj_vhdl_parser_priv_t *, char *, int);
static void set_attr_string (urj_vhdl_parser_priv_t *, char *, char *);
//static void set_attr_real (urj_vhdl_parser_priv_t *, char *, char *);
//static void set_attr_const (urj_vhdl_parser_priv_t *, char *, char *);

void yyerror (urj_vhdl_parser_priv_t *, const char *);

#line 139 "vhdl_bison.c"

# ifndef YY_NULLPTR
#  if defined __cplusplus
#   if 201103L <= __cplusplus
#    define YY_NULLPTR nullptr
#   else
#    define YY_NULLPTR 0
#   endif
#  else
#   define YY_NULLPTR ((void*)0)
#  endif
# endif

/* Enabling verbose error messages.  */
#ifdef YYERROR_VERBOSE
# undef YYERROR_VERBOSE
# define YYERROR_VERBOSE 1
#else
# define YYERROR_VERBOSE 0
#endif

/* Use api.header.include to #include this header
   instead of duplicating it here.  */
#ifndef YY_URJ_VHDL_VHDL_BISON_H_INCLUDED
# define YY_URJ_VHDL_VHDL_BISON_H_INCLUDED
/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif
#if YYDEBUG
extern int urj_vhdl_debug;
#endif

/* Token type.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    ENTITY = 258,
    PORT = 259,
    GENERIC = 260,
    USE = 261,
    ATTRIBUTE = 262,
    IS = 263,
    OF = 264,
    CONSTANT = 265,
    STRING = 266,
    END = 267,
    ALL = 268,
    PHYSICAL_PIN_MAP = 269,
    PIN_MAP_STRING = 270,
    TRUE = 271,
    FALSE = 272,
    SIGNAL = 273,
    LOW = 274,
    BOTH = 275,
    IN = 276,
    OUT = 277,
    INOUT = 278,
    BUFFER = 279,
    LINKAGE = 280,
    BIT = 281,
    BIT_VECTOR = 282,
    TO = 283,
    DOWNTO = 284,
    PACKAGE = 285,
    BODY = 286,
    TYPE = 287,
    SUBTYPE = 288,
    RECORD = 289,
    ARRAY = 290,
    POSITIVE = 291,
    RANGE = 292,
    CELL_INFO = 293,
    INPUT = 294,
    OUTPUT2 = 295,
    OUTPUT3 = 296,
    CONTROL = 297,
    CONTROLR = 298,
    INTERNAL = 299,
    CLOCK = 300,
    BIDIR = 301,
    BIDIR_IN = 302,
    BIDIR_OUT = 303,
    EXTEST = 304,
    SAMPLE = 305,
    INTEST = 306,
    RUNBIST = 307,
    PI = 308,
    PO = 309,
    UPD = 310,
    CAP = 311,
    X = 312,
    BIN_X_PATTERN = 313,
    ZERO = 314,
    ONE = 315,
    Z = 316,
    IDENTIFIER = 317,
    SINGLE_QUOTE = 318,
    QUOTED_STRING = 319,
    DECIMAL_NUMBER = 320,
    REAL_NUMBER = 321,
    CONCATENATE = 322,
    SEMICOLON = 323,
    COMMA = 324,
    LPAREN = 325,
    RPAREN = 326,
    COLON = 327,
    BOX = 328,
    COLON_EQUAL = 329,
    PERIOD = 330,
    ILLEGAL = 331,
    BSDL_EXTENSION = 332,
    OBSERVE_ONLY = 333,
    STD_1532_2001 = 334,
    STD_1532_2002 = 335
  };
#endif
/* Tokens.  */
#define ENTITY 258
#define PORT 259
#define GENERIC 260
#define USE 261
#define ATTRIBUTE 262
#define IS 263
#define OF 264
#define CONSTANT 265
#define STRING 266
#define END 267
#define ALL 268
#define PHYSICAL_PIN_MAP 269
#define PIN_MAP_STRING 270
#define TRUE 271
#define FALSE 272
#define SIGNAL 273
#define LOW 274
#define BOTH 275
#define IN 276
#define OUT 277
#define INOUT 278
#define BUFFER 279
#define LINKAGE 280
#define BIT 281
#define BIT_VECTOR 282
#define TO 283
#define DOWNTO 284
#define PACKAGE 285
#define BODY 286
#define TYPE 287
#define SUBTYPE 288
#define RECORD 289
#define ARRAY 290
#define POSITIVE 291
#define RANGE 292
#define CELL_INFO 293
#define INPUT 294
#define OUTPUT2 295
#define OUTPUT3 296
#define CONTROL 297
#define CONTROLR 298
#define INTERNAL 299
#define CLOCK 300
#define BIDIR 301
#define BIDIR_IN 302
#define BIDIR_OUT 303
#define EXTEST 304
#define SAMPLE 305
#define INTEST 306
#define RUNBIST 307
#define PI 308
#define PO 309
#define UPD 310
#define CAP 311
#define X 312
#define BIN_X_PATTERN 313
#define ZERO 314
#define ONE 315
#define Z 316
#define IDENTIFIER 317
#define SINGLE_QUOTE 318
#define QUOTED_STRING 319
#define DECIMAL_NUMBER 320
#define REAL_NUMBER 321
#define CONCATENATE 322
#define SEMICOLON 323
#define COMMA 324
#define LPAREN 325
#define RPAREN 326
#define COLON 327
#define BOX 328
#define COLON_EQUAL 329
#define PERIOD 330
#define ILLEGAL 331
#define BSDL_EXTENSION 332
#define OBSERVE_ONLY 333
#define STD_1532_2001 334
#define STD_1532_2002 335

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
union YYSTYPE
{
#line 191 "vhdl_bison.y"

  int   integer;
  char *str;

#line 347 "vhdl_bison.c"

};
typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif



int urj_vhdl_parse (urj_vhdl_parser_priv_t *priv_data);

#endif /* !YY_URJ_VHDL_VHDL_BISON_H_INCLUDED  */



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
typedef unsigned short yytype_uint16;
#endif

#ifdef YYTYPE_INT16
typedef YYTYPE_INT16 yytype_int16;
#else
typedef short yytype_int16;
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
#  define YYSIZE_T unsigned
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

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YYUSE(E) ((void) (E))
#else
# define YYUSE(E) /* empty */
#endif

#if defined __GNUC__ && ! defined __ICC && 407 <= __GNUC__ * 100 + __GNUC_MINOR__
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


#define YY_ASSERT(E) ((void) (0 && (E)))

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
#define YYFINAL  6
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   310

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  81
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  65
/* YYNRULES -- Number of rules.  */
#define YYNRULES  145
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  328

#define YYUNDEFTOK  2
#define YYMAXUTOK   335

/* YYTRANSLATE(TOKEN-NUM) -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, with out-of-bounds checking.  */
#define YYTRANSLATE(YYX)                                                \
  ((unsigned) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex.  */
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
      45,    46,    47,    48,    49,    50,    51,    52,    53,    54,
      55,    56,    57,    58,    59,    60,    61,    62,    63,    64,
      65,    66,    67,    68,    69,    70,    71,    72,    73,    74,
      75,    76,    77,    78,    79,    80
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,   227,   227,   229,   231,   238,   242,   248,   250,   256,
     259,   260,   266,   267,   269,   272,   274,   277,   277,   277,
     277,   277,   279,   281,   283,   285,   288,   289,   290,   291,
     292,   299,   304,   298,   314,   317,   323,   324,   326,   328,
     330,   333,   334,   335,   341,   343,   344,   345,   346,   352,
     353,   354,   355,   358,   361,   362,   368,   369,   371,   373,
     376,   378,   384,   385,   387,   389,   395,   396,   398,   400,
     402,   408,   409,   412,   411,   414,   420,   421,   423,   426,
     432,   433,   435,   437,   443,   443,   443,   443,   443,   444,
     444,   444,   444,   445,   446,   452,   452,   452,   452,   453,
     459,   459,   459,   459,   459,   459,   459,   460,   467,   472,
     466,   482,   485,   489,   490,   491,   497,   498,   500,   502,
     507,   509,   510,   511,   512,   513,   514,   520,   528,   530,
     533,   539,   547,   547,   549,   555,   558,   564,   571,   570,
     581,   585,   590,   594,   592,   600
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 0
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "ENTITY", "PORT", "GENERIC", "USE",
  "ATTRIBUTE", "IS", "OF", "CONSTANT", "STRING", "END", "ALL",
  "PHYSICAL_PIN_MAP", "PIN_MAP_STRING", "TRUE", "FALSE", "SIGNAL", "LOW",
  "BOTH", "IN", "OUT", "INOUT", "BUFFER", "LINKAGE", "BIT", "BIT_VECTOR",
  "TO", "DOWNTO", "PACKAGE", "BODY", "TYPE", "SUBTYPE", "RECORD", "ARRAY",
  "POSITIVE", "RANGE", "CELL_INFO", "INPUT", "OUTPUT2", "OUTPUT3",
  "CONTROL", "CONTROLR", "INTERNAL", "CLOCK", "BIDIR", "BIDIR_IN",
  "BIDIR_OUT", "EXTEST", "SAMPLE", "INTEST", "RUNBIST", "PI", "PO", "UPD",
  "CAP", "X", "BIN_X_PATTERN", "ZERO", "ONE", "Z", "IDENTIFIER",
  "SINGLE_QUOTE", "QUOTED_STRING", "DECIMAL_NUMBER", "REAL_NUMBER",
  "CONCATENATE", "SEMICOLON", "COMMA", "LPAREN", "RPAREN", "COLON", "BOX",
  "COLON_EQUAL", "PERIOD", "ILLEGAL", "BSDL_EXTENSION", "OBSERVE_ONLY",
  "STD_1532_2001", "STD_1532_2002", "$accept", "BSDL_Program",
  "Begin_BSDL", "BSDL_Body", "End_BSDL", "VHDL_Generic", "VHDL_Port",
  "Port_Specifier_List", "Port_Specifier", "Port_List", "Function",
  "Scaler_Or_Vector", "Vector_Range", "VHDL_Use_Part", "Standard_Use",
  "$@1", "$@2", "Standard_Package", "Standard_Decls", "Standard_Decl",
  "Attribute_Type", "Type_Body", "ID_Bits", "ID_List", "ID_Bit",
  "Record_Body", "Record_Element", "Defered_Constants", "Defered_Constant",
  "Constant_Body", "VHDL_Use_List", "Package_Body", "$@3", "Constant_List",
  "Cell_Constant", "Triples_List", "Triple", "Triple_Function",
  "Triple_Inst", "CAP_Data", "VHDL_Use", "$@4", "$@5", "User_Package",
  "VHDL_Elements", "VHDL_Element", "VHDL_Constant", "VHDL_Constant_Part",
  "VHDL_Attribute", "VHDL_Attribute_Types", "VHDL_Attr_Boolean", "Boolean",
  "VHDL_Attr_Decimal", "VHDL_Attr_Real", "Stop", "VHDL_Attr_String",
  "VHDL_Attr_PhysicalPinMap", "Quoted_String", "ISC_Use", "$@6",
  "ISC_Packages", "ISC_Package", "ISC_Package_Header", "$@7",
  "ISC_Package_Body", YY_NULLPTR
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
     295,   296,   297,   298,   299,   300,   301,   302,   303,   304,
     305,   306,   307,   308,   309,   310,   311,   312,   313,   314,
     315,   316,   317,   318,   319,   320,   321,   322,   323,   324,
     325,   326,   327,   328,   329,   330,   331,   332,   333,   334,
     335
};
# endif

#define YYPACT_NINF -159

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-159)))

#define YYTABLE_NINF -1

#define yytable_value_is_error(Yytable_value) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
     142,  -159,   -13,   109,   129,    66,  -159,  -159,    62,    11,
     132,  -159,   138,  -159,    96,  -159,  -159,    97,   101,    98,
      93,   106,  -159,    15,   107,   160,  -159,   158,  -159,  -159,
      69,  -159,    70,  -159,  -159,  -159,    99,  -159,    13,   110,
     131,  -159,  -159,  -159,    31,   165,  -159,  -159,   102,   106,
     105,   113,   104,   108,   164,  -159,   169,  -159,  -159,  -159,
    -159,  -159,  -159,   112,  -159,  -159,  -159,   117,  -159,   116,
    -159,  -159,  -159,  -159,  -159,  -159,  -159,  -159,    74,   168,
     114,   123,   171,   115,  -159,    64,  -159,   118,  -159,   119,
    -159,   120,   121,   176,   127,   125,   133,  -159,   166,    94,
     116,   126,  -159,  -159,    90,   128,    16,    75,  -159,   167,
     192,   193,    92,  -159,   139,   140,  -159,  -159,   141,  -159,
     194,   175,  -159,    -5,    17,  -159,    21,  -159,  -159,   199,
     202,    75,   143,   144,    95,  -159,  -159,   147,   146,  -159,
     148,  -159,    30,   153,  -159,   201,  -159,  -159,  -159,   149,
    -159,   208,  -159,   155,   -12,    -7,    89,  -159,    30,   207,
     137,   210,   150,   213,   215,   216,   217,    14,  -159,    89,
    -159,    20,    75,  -159,  -159,   156,   134,     2,   191,     1,
     218,   219,  -159,   159,  -159,    91,  -159,    75,   170,   172,
     173,  -159,  -159,  -159,  -159,  -159,   174,   162,  -159,    19,
     163,     6,   177,   178,   179,   190,   181,   180,  -159,  -159,
     182,  -159,   198,  -159,   183,     4,  -159,   184,  -159,   185,
    -159,   186,    78,    79,  -159,  -159,  -159,  -159,   188,   189,
    -159,    28,   200,   196,   205,  -159,   136,   221,   197,     9,
    -159,   203,  -159,  -159,    28,  -159,   220,  -159,   195,   204,
    -159,   187,   206,   209,  -159,  -159,  -159,  -159,   211,   212,
    -159,   214,   222,  -159,   228,   244,   250,   252,    18,   224,
     225,   226,  -159,   227,   103,  -159,   223,  -159,  -159,   229,
     230,  -159,  -159,   231,  -159,   232,   234,   233,  -159,     3,
    -159,     0,    82,  -159,  -159,  -159,  -159,  -159,  -159,  -159,
    -159,  -159,  -159,  -159,  -159,   235,     3,   237,     5,  -159,
    -159,  -159,  -159,  -159,  -159,  -159,   238,    29,  -159,  -159,
    -159,  -159,  -159,  -159,  -159,  -159,   239,  -159
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,     4,     0,     0,     0,     0,     1,     6,     0,     0,
       0,     3,     0,     8,     0,     2,    11,     0,     0,     0,
       0,     0,    30,     0,     0,    27,    26,     0,     7,    15,
       0,    12,     0,    31,   140,   141,     0,   115,     0,     0,
       5,   113,   116,   117,     0,    29,    71,    28,     0,     0,
       0,     0,     0,     0,     0,   126,     0,   120,   121,   122,
     123,   124,   125,     0,   118,   114,   108,     0,    72,     0,
      13,    10,    16,    17,    18,    19,    20,    21,     0,     0,
       0,     0,     0,     0,   136,     0,    22,     0,    14,     0,
     138,     0,     0,     0,     0,     0,     0,    32,     0,     0,
       0,     0,   137,     9,     0,     0,     0,     0,   139,     0,
       0,     0,     0,   109,     0,     0,    23,    35,     0,    33,
       0,     0,   142,     0,     0,   119,     0,    24,    25,     0,
       0,     0,     0,     0,     0,   128,   129,     0,     0,   112,
       0,   110,     0,     0,   143,     0,   135,   130,   134,     0,
     127,     0,    43,     0,     0,     0,     0,    36,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    37,     0,
      66,     0,     0,   132,   133,     0,     0,     0,     0,     0,
       0,     0,    70,     0,    68,     0,    67,     0,     0,     0,
       0,    48,    45,    44,    46,    47,     0,     0,    55,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   145,   131,
       0,    38,     0,    65,     0,     0,    62,     0,    61,     0,
      58,     0,     0,     0,    56,    39,    41,    42,     0,     0,
     144,     0,     0,     0,     0,    63,     0,     0,     0,     0,
      49,     0,    50,    69,     0,    75,     0,   111,     0,     0,
      54,     0,     0,     0,    60,    57,    59,    34,     0,     0,
      64,     0,     0,    51,     0,     0,     0,     0,     0,     0,
       0,     0,    79,     0,     0,    76,     0,    52,    53,     0,
       0,    77,    40,     0,    73,     0,     0,     0,    74,     0,
      83,     0,     0,    80,    94,    84,    85,    86,    88,    89,
      87,    90,    91,    92,    93,     0,     0,     0,     0,    81,
      78,    99,    95,    96,    97,    98,     0,     0,   107,   100,
     101,   102,   103,   104,   105,   106,     0,    82
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -159,  -159,  -159,  -159,  -159,  -159,  -159,  -159,   241,  -159,
    -159,  -159,  -159,  -159,   145,  -159,  -159,  -159,   -53,   -65,
    -159,  -159,  -159,  -159,    23,  -159,    48,   135,  -158,  -159,
    -159,    22,  -159,  -159,   -10,  -159,   -39,  -159,  -159,  -159,
     236,  -159,  -159,  -159,  -159,   242,  -159,  -159,  -159,  -159,
    -159,  -159,  -159,  -159,  -159,  -159,  -159,   -62,   245,  -159,
    -107,  -159,  -159,  -159,  -159
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     3,     4,     9,    15,    10,    18,    30,    31,    32,
      78,    88,   105,    24,    25,    53,   106,   119,   156,   157,
     196,   202,   222,   223,   224,   215,   216,   169,   170,   184,
      45,   247,   286,   274,   275,   292,   293,   305,   316,   326,
      46,    83,   126,   141,    40,    41,    42,    64,    43,    57,
      58,   138,    59,    60,   175,    61,    62,    85,    26,    98,
      36,   108,   109,   158,   122
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_uint16 yytable[] =
{
     120,   294,   198,   191,   290,   213,   311,   218,   165,   132,
     218,   186,    13,   192,    55,   182,   234,   117,   186,   272,
     213,   152,   139,    14,   145,   219,   163,   153,   273,   245,
     318,   152,   187,   135,   136,   199,   200,   153,   112,   295,
     296,   297,   298,   299,   300,   301,   118,   302,   303,     5,
     164,   140,   154,   155,   312,   313,   314,   315,   246,    84,
     133,   134,   154,   155,   193,   188,   214,   194,   220,   221,
     166,   201,   221,   291,    11,    56,   183,    33,   304,   195,
     207,   214,   319,   320,   321,   322,   323,   137,   324,   325,
     152,   168,   152,    66,    34,    35,   153,   110,   153,   167,
      86,    87,    22,   206,   272,   171,   168,    23,    37,     6,
      34,    35,   111,   273,    38,   280,   185,    39,   114,   115,
     168,   154,   155,   154,   155,    73,    74,    75,    76,    77,
       7,    94,    12,    16,     8,    95,    17,    49,    38,    51,
      50,    39,    52,     1,   167,     2,   190,   239,   241,   240,
     242,   306,    19,   307,    34,    35,   173,   174,    20,    94,
     125,    28,    94,   148,   251,   252,    44,    21,    29,    48,
      27,    67,    63,    71,    54,    72,    69,    80,    81,    66,
      84,    89,    90,    79,    82,    91,    92,    97,    96,   101,
      93,   102,    99,   103,   113,   100,   107,   121,   104,   116,
     123,   124,   130,   129,   127,   128,   131,   142,   143,   159,
     151,   146,   147,   149,   150,    33,   161,   162,   160,   172,
     167,   178,   177,   179,   180,   181,   197,   189,   228,   203,
     204,   205,   212,   217,   232,   210,   268,   248,   208,   250,
     209,   253,   211,   229,   238,   225,   226,   227,   230,   236,
     231,   258,   261,   269,   237,   233,   243,   244,   249,   270,
     254,   271,   255,   235,   281,   256,   257,   309,   259,   285,
      47,   262,   260,   264,     0,   144,     0,     0,     0,     0,
     263,    68,    65,   265,     0,   266,   276,   277,   278,   279,
      70,   282,   284,   267,     0,     0,   176,     0,     0,     0,
       0,   283,   288,   289,   308,   310,   287,   317,     0,     0,
     327
};

static const yytype_int16 yycheck[] =
{
     107,     1,     1,     1,     1,     1,     1,     1,    15,    14,
       1,   169,     1,    11,     1,     1,    12,     1,   176,     1,
       1,     1,     1,    12,   131,    19,    38,     7,    10,     1,
       1,     1,    12,    16,    17,    34,    35,     7,   100,    39,
      40,    41,    42,    43,    44,    45,    30,    47,    48,    62,
      62,    30,    32,    33,    49,    50,    51,    52,    30,    64,
      65,   123,    32,    33,    62,   172,    62,    65,    62,    63,
      77,    70,    63,    70,     8,    62,    62,    62,    78,    77,
     187,    62,    53,    54,    55,    56,    57,    70,    59,    60,
       1,   156,     1,    62,    79,    80,     7,     3,     7,    10,
      26,    27,     1,    12,     1,   158,   171,     6,     1,     0,
      79,    80,    18,    10,     7,    12,   169,    10,    28,    29,
     185,    32,    33,    32,    33,    21,    22,    23,    24,    25,
       1,    67,    70,     1,     5,    71,     4,    68,     7,    69,
      71,    10,    72,     1,    10,     3,    12,    69,    69,    71,
      71,    69,    14,    71,    79,    80,    19,    20,    62,    67,
      68,    68,    67,    68,    28,    29,     6,    70,    62,    11,
      72,     6,    62,    68,    75,    62,    74,    13,     9,    62,
      64,    13,    68,    75,    72,    62,    15,    68,    70,    13,
      75,    64,    72,    68,    68,    74,    30,    30,    65,    71,
       8,     8,     8,    62,    65,    65,    31,     8,     6,     8,
      62,    68,    68,    66,    68,    62,     8,    62,    69,    12,
      10,     8,    72,     8,     8,     8,    35,    71,    38,    11,
      11,    72,    70,    70,    36,    62,     8,    37,    68,    34,
      68,    20,    68,    62,    58,    68,    68,    68,    68,    65,
      68,    31,    65,     9,    69,    72,    68,    68,    62,     9,
      63,     9,   239,   215,   274,    62,   244,   306,    73,    38,
      25,    65,    68,    62,    -1,   130,    -1,    -1,    -1,    -1,
      71,    45,    40,    71,    -1,    71,    62,    62,    62,    62,
      49,    68,    62,    71,    -1,    -1,   161,    -1,    -1,    -1,
      -1,    72,    68,    70,    69,    68,    74,    69,    -1,    -1,
      71
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,     1,     3,    82,    83,    62,     0,     1,     5,    84,
      86,     8,    70,     1,    12,    85,     1,     4,    87,    14,
      62,    70,     1,     6,    94,    95,   139,    72,    68,    62,
      88,    89,    90,    62,    79,    80,   141,     1,     7,    10,
     125,   126,   127,   129,     6,   111,   121,   139,    11,    68,
      71,    69,    72,    96,    75,     1,    62,   130,   131,   133,
     134,   136,   137,    62,   128,   126,    62,     6,   121,    74,
      89,    68,    62,    21,    22,    23,    24,    25,    91,    75,
      13,     9,    72,   122,    64,   138,    26,    27,    92,    13,
      68,    62,    15,    75,    67,    71,    70,    68,   140,    72,
      74,    13,    64,    68,    65,    93,    97,    30,   142,   143,
       3,    18,   138,    68,    28,    29,    71,     1,    30,    98,
     141,    30,   145,     8,     8,    68,   123,    65,    65,    62,
       8,    31,    14,    65,   138,    16,    17,    70,   132,     1,
      30,   124,     8,     6,    95,   141,    68,    68,    68,    66,
      68,    62,     1,     7,    32,    33,    99,   100,   144,     8,
      69,     8,    62,    38,    62,    15,    77,    10,   100,   108,
     109,    99,    12,    19,    20,   135,   108,    72,     8,     8,
       8,     8,     1,    62,   110,    99,   109,    12,   141,    71,
      12,     1,    11,    62,    65,    77,   101,    35,     1,    34,
      35,    70,   102,    11,    11,    72,    12,   141,    68,    68,
      62,    68,    70,     1,    62,   106,   107,    70,     1,    19,
      62,    63,   103,   104,   105,    68,    68,    68,    38,    62,
      68,    68,    36,    72,    12,   107,    65,    69,    58,    69,
      71,    69,    71,    68,    68,     1,    30,   112,    37,    62,
      34,    28,    29,    20,    63,   105,    62,   112,    31,    73,
      68,    65,    65,    71,    62,    71,    71,    71,     8,     9,
       9,     9,     1,    10,   114,   115,    62,    62,    62,    62,
      12,   115,    68,    72,    62,    38,   113,    74,    68,    70,
       1,    70,   116,   117,     1,    39,    40,    41,    42,    43,
      44,    45,    47,    48,    78,   118,    69,    71,    69,   117,
      68,     1,    49,    50,    51,    52,   119,    69,     1,    53,
      54,    55,    56,    57,    59,    60,   120,    71
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    81,    82,    83,    83,    84,    84,    85,    85,    86,
      87,    87,    88,    88,    89,    90,    90,    91,    91,    91,
      91,    91,    92,    92,    93,    93,    94,    94,    94,    94,
      94,    96,    97,    95,    98,    98,    99,    99,   100,   100,
     100,   100,   100,   100,   101,   101,   101,   101,   101,   102,
     102,   102,   102,   102,   102,   102,   103,   103,   104,   104,
     105,   105,   106,   106,   107,   107,   108,   108,   109,   110,
     110,   111,   111,   113,   112,   112,   114,   114,   115,   115,
     116,   116,   117,   117,   118,   118,   118,   118,   118,   118,
     118,   118,   118,   118,   118,   119,   119,   119,   119,   119,
     120,   120,   120,   120,   120,   120,   120,   120,   122,   123,
     121,   124,   124,   125,   125,   125,   126,   126,   127,   128,
     129,   130,   130,   130,   130,   130,   130,   131,   132,   132,
     133,   134,   135,   135,   136,   137,   138,   138,   140,   139,
     141,   141,   142,   144,   143,   145
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     3,     3,     1,     4,     1,     3,     1,     9,
       5,     1,     1,     3,     4,     1,     3,     1,     1,     1,
       1,     1,     1,     4,     3,     3,     1,     1,     2,     2,
       1,     0,     0,     8,    10,     1,     1,     2,     5,     5,
      12,     5,     5,     1,     1,     1,     1,     1,     1,     3,
       3,     5,     8,     8,     4,     1,     1,     3,     1,     3,
       3,     1,     1,     2,     4,     1,     1,     2,     2,     4,
       1,     1,     2,     0,     9,     1,     1,     2,     9,     1,
       1,     3,     7,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     0,     0,
       8,     8,     1,     1,     2,     1,     1,     1,     2,     6,
       2,     1,     1,     1,     1,     1,     1,     8,     1,     1,
       8,    12,     1,     1,     8,     8,     1,     3,     0,     7,
       1,     1,     2,     0,     9,     7
};


#define yyerrok         (yyerrstatus = 0)
#define yyclearin       (yychar = YYEMPTY)
#define YYEMPTY         (-2)
#define YYEOF           0

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab


#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)                                    \
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
        yyerror (priv_data, YY_("syntax error: cannot back up")); \
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
                  Type, Value, priv_data); \
      YYFPRINTF (stderr, "\n");                                           \
    }                                                                     \
} while (0)


/*-----------------------------------.
| Print this symbol's value on YYO.  |
`-----------------------------------*/

static void
yy_symbol_value_print (FILE *yyo, int yytype, YYSTYPE const * const yyvaluep, urj_vhdl_parser_priv_t *priv_data)
{
  FILE *yyoutput = yyo;
  YYUSE (yyoutput);
  YYUSE (priv_data);
  if (!yyvaluep)
    return;
# ifdef YYPRINT
  if (yytype < YYNTOKENS)
    YYPRINT (yyo, yytoknum[yytype], *yyvaluep);
# endif
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YYUSE (yytype);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}


/*---------------------------.
| Print this symbol on YYO.  |
`---------------------------*/

static void
yy_symbol_print (FILE *yyo, int yytype, YYSTYPE const * const yyvaluep, urj_vhdl_parser_priv_t *priv_data)
{
  YYFPRINTF (yyo, "%s %s (",
             yytype < YYNTOKENS ? "token" : "nterm", yytname[yytype]);

  yy_symbol_value_print (yyo, yytype, yyvaluep, priv_data);
  YYFPRINTF (yyo, ")");
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
yy_reduce_print (yytype_int16 *yyssp, YYSTYPE *yyvsp, int yyrule, urj_vhdl_parser_priv_t *priv_data)
{
  unsigned long yylno = yyrline[yyrule];
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
                       &yyvsp[(yyi + 1) - (yynrhs)]
                                              , priv_data);
      YYFPRINTF (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)          \
do {                                    \
  if (yydebug)                          \
    yy_reduce_print (yyssp, yyvsp, Rule, priv_data); \
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
            else
              goto append;

          append:
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

  return (YYSIZE_T) (yystpcpy (yyres, yystr) - yyres);
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
                  if (yysize <= yysize1 && yysize1 <= YYSTACK_ALLOC_MAXIMUM)
                    yysize = yysize1;
                  else
                    return 2;
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
    default: /* Avoid compiler warnings. */
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
    if (yysize <= yysize1 && yysize1 <= YYSTACK_ALLOC_MAXIMUM)
      yysize = yysize1;
    else
      return 2;
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
yydestruct (const char *yymsg, int yytype, YYSTYPE *yyvaluep, urj_vhdl_parser_priv_t *priv_data)
{
  YYUSE (yyvaluep);
  YYUSE (priv_data);
  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yytype, yyvaluep, yylocationp);

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YYUSE (yytype);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}




/*----------.
| yyparse.  |
`----------*/

int
yyparse (urj_vhdl_parser_priv_t *priv_data)
{
/* The lookahead symbol.  */
int yychar;


/* The semantic value of the lookahead symbol.  */
/* Default value used for initialization, for pacifying older GCCs
   or non-GCC compilers.  */
YY_INITIAL_VALUE (static YYSTYPE yyval_default;)
YYSTYPE yylval YY_INITIAL_VALUE (= yyval_default);

    /* Number of syntax errors so far.  */
    int yynerrs;

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
| yynewstate -- push a new state, which is found in yystate.  |
`------------------------------------------------------------*/
yynewstate:
  /* In all cases, when you get here, the value and location stacks
     have just been pushed.  So pushing a state here evens the stacks.  */
  yyssp++;


/*--------------------------------------------------------------------.
| yynewstate -- set current state (the top of the stack) to yystate.  |
`--------------------------------------------------------------------*/
yysetstate:
  YYDPRINTF ((stderr, "Entering state %d\n", yystate));
  YY_ASSERT (0 <= yystate && yystate < YYNSTATES);
  *yyssp = (yytype_int16) yystate;

  if (yyss + yystacksize - 1 <= yyssp)
#if !defined yyoverflow && !defined YYSTACK_RELOCATE
    goto yyexhaustedlab;
#else
    {
      /* Get the current used size of the three stacks, in elements.  */
      YYSIZE_T yysize = (YYSIZE_T) (yyssp - yyss + 1);

# if defined yyoverflow
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
# else /* defined YYSTACK_RELOCATE */
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
# undef YYSTACK_RELOCATE
        if (yyss1 != yyssa)
          YYSTACK_FREE (yyss1);
      }
# endif

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;

      YYDPRINTF ((stderr, "Stack size increased to %lu\n",
                  (unsigned long) yystacksize));

      if (yyss + yystacksize - 1 <= yyssp)
        YYABORT;
    }
#endif /* !defined yyoverflow && !defined YYSTACK_RELOCATE */

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
      yychar = yylex (&yylval, HACK);
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
| yyreduce -- do a reduction.  |
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
  case 3:
#line 230 "vhdl_bison.y"
    { urj_vhdl_set_entity (priv_data, (yyvsp[-1].str)); }
#line 1689 "vhdl_bison.c"
    break;

  case 4:
#line 232 "vhdl_bison.y"
    {
               Print_Error (priv_data, _("Improper Entity declaration"));
               Print_Error (priv_data, _("Check if source file is BSDL"));
               BUMP_ERROR; YYABORT;     /* Probably not a BSDL source file */
             }
#line 1699 "vhdl_bison.c"
    break;

  case 6:
#line 243 "vhdl_bison.y"
    {
              Print_Error (priv_data, _("Syntax Error"));
              BUMP_ERROR; YYABORT;
            }
#line 1708 "vhdl_bison.c"
    break;

  case 7:
#line 249 "vhdl_bison.y"
    { free ((yyvsp[-1].str)); }
#line 1714 "vhdl_bison.c"
    break;

  case 8:
#line 251 "vhdl_bison.y"
    {
             Print_Error (priv_data, _("Syntax Error"));
             BUMP_ERROR; YYABORT;
           }
#line 1723 "vhdl_bison.c"
    break;

  case 11:
#line 261 "vhdl_bison.y"
    {
                        Print_Error (priv_data, _("Improper Port declaration"));
                        BUMP_ERROR; YYABORT;
                      }
#line 1732 "vhdl_bison.c"
    break;

  case 14:
#line 270 "vhdl_bison.y"
    { urj_vhdl_port_apply_port (priv_data); }
#line 1738 "vhdl_bison.c"
    break;

  case 15:
#line 273 "vhdl_bison.y"
    { urj_vhdl_port_add_name (priv_data, (yyvsp[0].str)); }
#line 1744 "vhdl_bison.c"
    break;

  case 16:
#line 275 "vhdl_bison.y"
    { urj_vhdl_port_add_name (priv_data, (yyvsp[0].str)); }
#line 1750 "vhdl_bison.c"
    break;

  case 22:
#line 280 "vhdl_bison.y"
    { urj_vhdl_port_add_bit (priv_data); }
#line 1756 "vhdl_bison.c"
    break;

  case 24:
#line 284 "vhdl_bison.y"
    { urj_vhdl_port_add_range (priv_data, (yyvsp[-2].integer), (yyvsp[0].integer)); }
#line 1762 "vhdl_bison.c"
    break;

  case 25:
#line 286 "vhdl_bison.y"
    { urj_vhdl_port_add_range (priv_data, (yyvsp[0].integer), (yyvsp[-2].integer)); }
#line 1768 "vhdl_bison.c"
    break;

  case 30:
#line 293 "vhdl_bison.y"
    {
                  Print_Error (priv_data, _("Error in Package declaration(s)"));
                  BUMP_ERROR; YYABORT;
                }
#line 1777 "vhdl_bison.c"
    break;

  case 31:
#line 299 "vhdl_bison.y"
    {/* Parse Standard 1149.1 Package */
                  strcpy (priv_data->Package_File_Name, (yyvsp[0].str));
                  free ((yyvsp[0].str));
                }
#line 1786 "vhdl_bison.c"
    break;

  case 32:
#line 304 "vhdl_bison.y"
    {
                  priv_data->Reading_Package = 1;
                  urj_vhdl_flex_switch_file (priv_data->scanner,
                                             priv_data->Package_File_Name);
                }
#line 1796 "vhdl_bison.c"
    break;

  case 33:
#line 310 "vhdl_bison.y"
    {
                  priv_data->Reading_Package = 0;
                }
#line 1804 "vhdl_bison.c"
    break;

  case 34:
#line 316 "vhdl_bison.y"
    { free ((yyvsp[-8].str)); free ((yyvsp[-2].str)); }
#line 1810 "vhdl_bison.c"
    break;

  case 35:
#line 318 "vhdl_bison.y"
    {
                     Print_Error (priv_data, _("Error in Standard Package"));
                     BUMP_ERROR; YYABORT;
                   }
#line 1819 "vhdl_bison.c"
    break;

  case 38:
#line 327 "vhdl_bison.y"
    { free ((yyvsp[-3].str)); }
#line 1825 "vhdl_bison.c"
    break;

  case 39:
#line 329 "vhdl_bison.y"
    { free ((yyvsp[-3].str)); }
#line 1831 "vhdl_bison.c"
    break;

  case 40:
#line 332 "vhdl_bison.y"
    { free ((yyvsp[-1].str)); }
#line 1837 "vhdl_bison.c"
    break;

  case 43:
#line 336 "vhdl_bison.y"
    {
                   Print_Error (priv_data, _("Error in Standard Declarations"));
                   BUMP_ERROR; YYABORT;
                 }
#line 1846 "vhdl_bison.c"
    break;

  case 44:
#line 342 "vhdl_bison.y"
    { free ((yyvsp[0].str)); }
#line 1852 "vhdl_bison.c"
    break;

  case 48:
#line 347 "vhdl_bison.y"
    {
                   Print_Error (priv_data, _("Error in Attribute type identification"));
                   BUMP_ERROR; YYABORT;
                 }
#line 1861 "vhdl_bison.c"
    break;

  case 52:
#line 357 "vhdl_bison.y"
    { free ((yyvsp[0].str)); }
#line 1867 "vhdl_bison.c"
    break;

  case 53:
#line 360 "vhdl_bison.y"
    { free ((yyvsp[0].str)); }
#line 1873 "vhdl_bison.c"
    break;

  case 55:
#line 363 "vhdl_bison.y"
    {
                   Print_Error (priv_data, _("Error in Type definition"));
                   BUMP_ERROR; YYABORT;
                 }
#line 1882 "vhdl_bison.c"
    break;

  case 58:
#line 372 "vhdl_bison.y"
    { free ((yyvsp[0].str)); }
#line 1888 "vhdl_bison.c"
    break;

  case 59:
#line 374 "vhdl_bison.y"
    { free ((yyvsp[0].str)); }
#line 1894 "vhdl_bison.c"
    break;

  case 60:
#line 377 "vhdl_bison.y"
    { free ((yyvsp[-1].str)); }
#line 1900 "vhdl_bison.c"
    break;

  case 61:
#line 379 "vhdl_bison.y"
    {
                   Print_Error (priv_data, _("Error in Bit definition"));
                   BUMP_ERROR; YYABORT;
                 }
#line 1909 "vhdl_bison.c"
    break;

  case 64:
#line 388 "vhdl_bison.y"
    { free ((yyvsp[-3].str)); free ((yyvsp[-1].str)); }
#line 1915 "vhdl_bison.c"
    break;

  case 65:
#line 390 "vhdl_bison.y"
    {
                   Print_Error (priv_data, _("Error in Record Definition"));
                   BUMP_ERROR; YYABORT;
                 }
#line 1924 "vhdl_bison.c"
    break;

  case 69:
#line 401 "vhdl_bison.y"
    { free ((yyvsp[-3].str)); }
#line 1930 "vhdl_bison.c"
    break;

  case 70:
#line 403 "vhdl_bison.y"
    {
                      Print_Error (priv_data, _("Error in defered constant"));
                      BUMP_ERROR; YYABORT;
                    }
#line 1939 "vhdl_bison.c"
    break;

  case 73:
#line 412 "vhdl_bison.y"
    { free ((yyvsp[-4].str)); free ((yyvsp[0].str)); }
#line 1945 "vhdl_bison.c"
    break;

  case 75:
#line 415 "vhdl_bison.y"
    {
                    Print_Error (priv_data, _("Error in Package Body definition"));
                    BUMP_ERROR; YYABORT;
                  }
#line 1954 "vhdl_bison.c"
    break;

  case 78:
#line 425 "vhdl_bison.y"
    { free ((yyvsp[-7].str)); }
#line 1960 "vhdl_bison.c"
    break;

  case 79:
#line 427 "vhdl_bison.y"
    {
                    Print_Error (priv_data, _("Error in Cell Constant definition"));
                    BUMP_ERROR; YYABORT;
                  }
#line 1969 "vhdl_bison.c"
    break;

  case 83:
#line 438 "vhdl_bison.y"
    {
                    Print_Error (priv_data, _("Error in Cell Data Record"));
                    BUMP_ERROR; YYABORT;
                  }
#line 1978 "vhdl_bison.c"
    break;

  case 94:
#line 447 "vhdl_bison.y"
    {
                    Print_Error (priv_data, _("Error in Cell_Type Function field"));
                    BUMP_ERROR; YYABORT;
                  }
#line 1987 "vhdl_bison.c"
    break;

  case 99:
#line 454 "vhdl_bison.y"
    {
                    Print_Error (priv_data, _("Error in BScan_Inst Instruction field"));
                    BUMP_ERROR; YYABORT;
                  }
#line 1996 "vhdl_bison.c"
    break;

  case 107:
#line 461 "vhdl_bison.y"
    {
                    Print_Error (priv_data, _("Error in Constant CAP data source field"));
                    BUMP_ERROR; YYABORT;
                  }
#line 2005 "vhdl_bison.c"
    break;

  case 108:
#line 467 "vhdl_bison.y"
    {/* Parse Standard 1149.1 Package */
                    strcpy(priv_data->Package_File_Name, (yyvsp[0].str));
                    free((yyvsp[0].str));
                   }
#line 2014 "vhdl_bison.c"
    break;

  case 109:
#line 472 "vhdl_bison.y"
    {
                     priv_data->Reading_Package = 1;
                     urj_vhdl_flex_switch_file (priv_data->scanner,
                                                priv_data->Package_File_Name);
                   }
#line 2024 "vhdl_bison.c"
    break;

  case 110:
#line 478 "vhdl_bison.y"
    {
                     priv_data->Reading_Package = 0;
                   }
#line 2032 "vhdl_bison.c"
    break;

  case 111:
#line 484 "vhdl_bison.y"
    { free((yyvsp[-6].str)); free((yyvsp[-2].str)); }
#line 2038 "vhdl_bison.c"
    break;

  case 112:
#line 486 "vhdl_bison.y"
    {Print_Error(priv_data, _("Error in User-Defined Package declarations"));
                    BUMP_ERROR; YYABORT; }
#line 2045 "vhdl_bison.c"
    break;

  case 115:
#line 492 "vhdl_bison.y"
    {
                  Print_Error (priv_data, _("Unknown VHDL statement"));
                  BUMP_ERROR; YYABORT;
                }
#line 2054 "vhdl_bison.c"
    break;

  case 119:
#line 505 "vhdl_bison.y"
    { free ((yyvsp[-5].str)); }
#line 2060 "vhdl_bison.c"
    break;

  case 126:
#line 515 "vhdl_bison.y"
    {
                         Print_Error (priv_data, _("Error in Attribute specification"));
                         BUMP_ERROR; YYABORT;
                       }
#line 2069 "vhdl_bison.c"
    break;

  case 127:
#line 521 "vhdl_bison.y"
    {
                       //set_attr_bool (priv_data, $1, $7);
                       //free ($3);
                       /* skip boolean attributes for the time being */
                       free ((yyvsp[-7].str)); free ((yyvsp[-5].str));
                     }
#line 2080 "vhdl_bison.c"
    break;

  case 128:
#line 529 "vhdl_bison.y"
    { (yyval.integer) = 1; }
#line 2086 "vhdl_bison.c"
    break;

  case 129:
#line 531 "vhdl_bison.y"
    { (yyval.integer) = 0; }
#line 2092 "vhdl_bison.c"
    break;

  case 130:
#line 534 "vhdl_bison.y"
    {
                      set_attr_decimal (priv_data, (yyvsp[-7].str), (yyvsp[-1].integer));
                      free ((yyvsp[-5].str));
                    }
#line 2101 "vhdl_bison.c"
    break;

  case 131:
#line 540 "vhdl_bison.y"
    {
                     //set_attr_real (priv_data, $1, $8);
                     //free ($3);
                     /* skip real attributes for the time being */
                     free ((yyvsp[-11].str)); free ((yyvsp[-9].str)); free ((yyvsp[-4].str));
                   }
#line 2112 "vhdl_bison.c"
    break;

  case 134:
#line 550 "vhdl_bison.y"
    {
                     set_attr_string (priv_data, (yyvsp[-7].str), strdup (priv_data->buffer));
                     free ((yyvsp[-5].str));
                   }
#line 2121 "vhdl_bison.c"
    break;

  case 135:
#line 556 "vhdl_bison.y"
    { free ((yyvsp[-7].str)); free ((yyvsp[-5].str)); }
#line 2127 "vhdl_bison.c"
    break;

  case 136:
#line 559 "vhdl_bison.y"
    {
                     Init_Text (priv_data);
                     Store_Text (priv_data, (yyvsp[0].str));
                     free ((yyvsp[0].str));
                   }
#line 2137 "vhdl_bison.c"
    break;

  case 137:
#line 565 "vhdl_bison.y"
    {
                     Store_Text (priv_data, (yyvsp[0].str));
                     free ((yyvsp[0].str));
                   }
#line 2146 "vhdl_bison.c"
    break;

  case 138:
#line 571 "vhdl_bison.y"
    {
               priv_data->Reading_Package = 1;
               urj_vhdl_flex_switch_file (priv_data->scanner,
                                          priv_data->Package_File_Name);
             }
#line 2156 "vhdl_bison.c"
    break;

  case 139:
#line 577 "vhdl_bison.y"
    {
               priv_data->Reading_Package = 0;
             }
#line 2164 "vhdl_bison.c"
    break;

  case 140:
#line 582 "vhdl_bison.y"
    {
                 strcpy (priv_data->Package_File_Name, "STD_1532_2001");
               }
#line 2172 "vhdl_bison.c"
    break;

  case 141:
#line 586 "vhdl_bison.y"
    {
                 strcpy (priv_data->Package_File_Name, "STD_1532_2002");
               }
#line 2180 "vhdl_bison.c"
    break;

  case 143:
#line 594 "vhdl_bison.y"
    {
                       priv_data->Reading_Package = 1;
                     }
#line 2188 "vhdl_bison.c"
    break;


#line 2192 "vhdl_bison.c"

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
  {
    const int yylhs = yyr1[yyn] - YYNTOKENS;
    const int yyi = yypgoto[yylhs] + *yyssp;
    yystate = (0 <= yyi && yyi <= YYLAST && yycheck[yyi] == *yyssp
               ? yytable[yyi]
               : yydefgoto[yylhs]);
  }

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
      yyerror (priv_data, YY_("syntax error"));
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
        yyerror (priv_data, yymsgp);
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
                      yytoken, &yylval, priv_data);
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
  /* Pacify compilers when the user code never invokes YYERROR and the
     label yyerrorlab therefore never appears in user code.  */
  if (0)
    YYERROR;

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
                  yystos[yystate], yyvsp, priv_data);
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
  yyerror (priv_data, YY_("memory exhausted"));
  yyresult = 2;
  /* Fall through.  */
#endif


/*-----------------------------------------------------.
| yyreturn -- parsing is finished, return the result.  |
`-----------------------------------------------------*/
yyreturn:
  if (yychar != YYEMPTY)
    {
      /* Make sure we have latest lookahead translation.  See comments at
         user semantic actions for why this is necessary.  */
      yytoken = YYTRANSLATE (yychar);
      yydestruct ("Cleanup: discarding lookahead",
                  yytoken, &yylval, priv_data);
    }
  /* Do not reclaim the symbols of the rule whose action triggered
     this YYABORT or YYACCEPT.  */
  YYPOPSTACK (yylen);
  YY_STACK_PRINT (yyss, yyssp);
  while (yyssp != yyss)
    {
      yydestruct ("Cleanup: popping",
                  yystos[*yyssp], yyvsp, priv_data);
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
#line 603 "vhdl_bison.y"
  /* End rules, begin programs  */
/*****************************************************************************
 * void Init_Text( urj_vhdl_parser_priv_t *priv )
 *
 * Allocates the internal test buffer if not already existing.
 *
 * Parameters
 *   priv : private data container for parser related tasks
 *
 * Returns
 *   void
 ****************************************************************************/
static void
Init_Text (urj_vhdl_parser_priv_t *priv)
{
    if (priv->len_buffer == 0)
    {
        /* @@@@ RFHH check malloc result */
        priv->buffer = malloc (160);
        priv->len_buffer = 160;
    }
    priv->buffer[0] = '\0';
}


/*****************************************************************************
 * void Store_Text( urj_vhdl_parser_priv_t *priv, char *Source )
 *
 * Appends the given String to the internal text buffer. The buffer
 * is extended if the string does not fit into the current size.
 *
 * Parameters
 *   priv   : private data container for parser related tasks
 *   String : pointer to string that is to be added to buffer
 *
 * Returns
 *   void
 ****************************************************************************/
static void
Store_Text (urj_vhdl_parser_priv_t *priv, char *Source)
{                               /* Save characters from VHDL string in local string buffer.           */
    size_t req_len;
    char *SourceEnd;

    SourceEnd = ++Source;       /* skip leading '"' */
    while (*SourceEnd && (*SourceEnd != '"') && (*SourceEnd != '\n'))
        SourceEnd++;
    /* terminate Source string with NUL character */
    *SourceEnd = '\0';

    req_len = strlen (priv->buffer) + strlen (Source) + 1;
    if (req_len > priv->len_buffer)
    {
        /* @@@@ RFHH check realloc result */
        priv->buffer = realloc (priv->buffer, req_len);
        priv->len_buffer = req_len;
    }
    strcat (priv->buffer, Source);
}

/*----------------------------------------------------------------------*/
static void
Print_Error (urj_vhdl_parser_priv_t *priv_data, const char *Errmess)
{
    urj_bsdl_jtag_ctrl_t *jc = priv_data->jtag_ctrl;

    if (priv_data->Reading_Package)
        urj_bsdl_err (jc->proc_mode,
                      _("In Package %s, Line %d, %s.\n"),
                      priv_data->Package_File_Name,
                      urj_vhdl_flex_get_lineno (priv_data->scanner), Errmess);
    else
        urj_bsdl_err (jc->proc_mode,
                      _("Line %d, %s.\n"),
                      urj_vhdl_flex_get_lineno (priv_data->scanner), Errmess);

    /* set an error if nothing else is pending */
    if (urj_error_get () == URJ_ERROR_OK)
        urj_bsdl_err_set (jc->proc_mode, URJ_ERROR_BSDL_VHDL,
                          "Parser error, see log for details");
}

/*----------------------------------------------------------------------*/
static void
Give_Up_And_Quit (urj_vhdl_parser_priv_t *priv_data)
{
    Print_Error (priv_data, _("Too many errors"));
}

/*----------------------------------------------------------------------*/
void
yyerror (urj_vhdl_parser_priv_t *priv_data, const char *error_string)
{
}


/*****************************************************************************
 * void urj_vhdl_sem_init( urj_vhdl_parser_priv_t *priv )
 *
 * Initializes storage elements in the private parser and jtag control
 * structures that are used for semantic purposes.
 *
 * Parameters
 *   priv : private data container for parser related tasks
 *
 * Returns
 *   void
 ****************************************************************************/
static void
urj_vhdl_sem_init (urj_vhdl_parser_priv_t *priv)
{
    priv->tmp_port_desc.names_list = NULL;
    priv->tmp_port_desc.next = NULL;

    priv->jtag_ctrl->port_desc = NULL;

    priv->jtag_ctrl->vhdl_elem_first = NULL;
    priv->jtag_ctrl->vhdl_elem_last = NULL;
}


/*****************************************************************************
 * void free_string_list( urj_bsdl_string_elem_t *sl )
 *
 * Deallocates the given list of string_elem items.
 *
 * Parameters
 *  sl : first string_elem to deallocate
 *
 * Returns
 *  void
 ****************************************************************************/
static void
free_string_list (urj_bsdl_string_elem_t *sl)
{
    if (sl)
    {
        if (sl->string)
            free (sl->string);
        free_string_list (sl->next);
        free (sl);
    }
}


/*****************************************************************************
 * void free_port_list( urj_bsdl_port_desc_t *pl, int free_me )
 *
 * Deallocates the given list of port_desc.
 *
 * Parameters
 *  pl      : first port_desc to deallocate
 *  free_me : set to 1 to free memory for ai as well
 *
 * Returns
 *  void
 ****************************************************************************/
static void
free_port_list (urj_bsdl_port_desc_t *pl, int free_me)
{
    if (pl)
    {
        free_string_list (pl->names_list);
        free_port_list (pl->next, 1);

        if (free_me)
            free (pl);
    }
}


/*****************************************************************************
 * void free_elem_list( urj_vhdl_elem_t *el )
 *
 * Deallocates the given list of vhdl_elem items.
 *
 * Parameters
 *  el : first vhdl_elem to deallocate
 *
 * Returns
 *  void
 ****************************************************************************/
static void
free_elem_list (urj_vhdl_elem_t *el)
{
    if (el)
    {
        free_elem_list (el->next);

        if (el->name)
            free (el->name);

        if (el->payload)
            free (el->payload);
        free (el);
    }
}


/*****************************************************************************
 * void urj_vhdl_sem_deinit( urj_vhdl_parser_priv_t *priv )
 *
 * Frees and deinitializes storage elements in the private parser and
 * jtag control structures that were filled by semantic rules.
 *
 * Parameters
 *   priv : private data container for parser related tasks
 *
 * Returns
 *   void
 ****************************************************************************/
static void
urj_vhdl_sem_deinit (urj_vhdl_parser_priv_t *priv_data)
{
    urj_bsdl_port_desc_t *pd = priv_data->jtag_ctrl->port_desc;
    urj_vhdl_elem_t *el = priv_data->jtag_ctrl->vhdl_elem_first;

    /* free port_desc list */
    free_port_list (pd, 1);
    free_port_list (&(priv_data->tmp_port_desc), 0);

    /* free VHDL element list */
    free_elem_list (el);

    priv_data->jtag_ctrl = NULL;
}


/*****************************************************************************
 * urj_vhdl_parser_priv_t *urj_vhdl_parser_init( FILE *f, urj_bsdl_jtag_ctrl_t *jtag_ctrl )
 *
 * Initializes storage elements in the private parser structure that are
 * used for parser maintenance purposes.
 * Subsequently calls initializer functions for the scanner and the semantic
 * parts.
 *
 * Parameters
 *   f         : descriptor of file for scanning
 *   jtag_ctrl : pointer to jtag control structure
 *
 * Returns
 *   pointer to private parser structure
 ****************************************************************************/
urj_vhdl_parser_priv_t *
urj_vhdl_parser_init (FILE *f, urj_bsdl_jtag_ctrl_t *jtag_ctrl)
{
    urj_vhdl_parser_priv_t *new_priv;

    if (!(new_priv = malloc (sizeof (urj_vhdl_parser_priv_t))))
    {
        urj_bsdl_ftl_set (jtag_ctrl->proc_mode, URJ_ERROR_OUT_OF_MEMORY,
                          "No memory");
        return NULL;
    }

    new_priv->jtag_ctrl = jtag_ctrl;

    new_priv->Reading_Package = 0;
    new_priv->buffer = NULL;
    new_priv->len_buffer = 0;

    if (!(new_priv->scanner = urj_vhdl_flex_init (f, jtag_ctrl->proc_mode)))
    {
        free (new_priv);
        new_priv = NULL;
    }

    urj_vhdl_sem_init (new_priv);

    return new_priv;
}


/*****************************************************************************
 * void urj_vhdl_parser_deinit( urj_vhdl_parser_priv_t *priv )
 *
 * Frees storage elements in the private parser structure that are
 * used for parser maintenance purposes.
 * Subsequently calls deinitializer functions for the scanner and the semantic
 * parts.
 *
 * Parameters
 *   priv : private data container for parser related tasks
 *
 * Returns
 *   void
 ****************************************************************************/
void
urj_vhdl_parser_deinit (urj_vhdl_parser_priv_t *priv_data)
{
    if (priv_data->buffer)
    {
        free (priv_data->buffer);
        priv_data->buffer = NULL;
    }

    urj_vhdl_sem_deinit (priv_data);
    urj_vhdl_flex_deinit (priv_data->scanner);
    free (priv_data);
}

/*****************************************************************************
 * void urj_vhdl_set_entity( urj_vhdl_parser_priv_t *priv, char *entityname )
 *
 * Applies the entity name from BSDL as the part name.
 *
 * Parameters
 *   priv       : private data container for parser related tasks
 *   entityname : entity name string, memory gets free'd
 *
 * Returns
 *   void
 ****************************************************************************/
static void
urj_vhdl_set_entity (urj_vhdl_parser_priv_t *priv, char *entityname)
{
    if (priv->jtag_ctrl->proc_mode & URJ_BSDL_MODE_INSTR_EXEC)
    {
        strncpy (priv->entity_name, entityname, VHDL_PARSER_ENTITY_NAME_MAXLEN);
        priv->entity_name[VHDL_PARSER_ENTITY_NAME_MAXLEN] = '\0';
    }

    free (entityname);
}

/*****************************************************************************
 * void urj_vhdl_port_add_name( urj_vhdl_parser_priv_t *priv, char *name )
 * Port name management function
 *
 * Sets the name field of the temporary storage area for port description
 * (port_desc) to the parameter name.
 *
 * Parameters
 *   priv : private data container for parser related tasks
 *   name : base name of the port, memory get's free'd lateron
 *
 * Returns
 *   void
 ****************************************************************************/
static void
urj_vhdl_port_add_name (urj_vhdl_parser_priv_t *priv, char *name)
{
    urj_bsdl_port_desc_t *pd = &(priv->tmp_port_desc);
    urj_bsdl_string_elem_t *new_string;

    new_string = malloc (sizeof (urj_bsdl_string_elem_t));
    if (new_string)
    {
        new_string->next = pd->names_list;
        new_string->string = name;

        pd->names_list = new_string;
    }
    else
        urj_bsdl_ftl_set (priv->jtag_ctrl->proc_mode, URJ_ERROR_OUT_OF_MEMORY,
                          "No memory");
}


/*****************************************************************************
 * void urj_vhdl_port_add_bit( urj_vhdl_parser_priv_t *priv )
 * Port name management function
 *
 * Sets the vector and index fields of the temporary storage area for port
 * description (port_desc) to non-vector information. The low and high indice
 * are set to equal numbers (exact value is irrelevant).
 *
 * Parameters
 *   priv : private data container for parser related tasks
 *
 * Returns
 *   void
 ****************************************************************************/
static void
urj_vhdl_port_add_bit (urj_vhdl_parser_priv_t *priv)
{
    urj_bsdl_port_desc_t *pd = &(priv->tmp_port_desc);

    pd->is_vector = 0;
    pd->low_idx = 0;
    pd->high_idx = 0;
}


/*****************************************************************************
 * void urj_vhdl_port_add_range( urj_vhdl_parser_priv_t *priv, int low, int high )
 * Port name management function
 *
 * Sets the vector and index fields of the temporary storage area for port
 * description (port_desc) to the specified vector information.
 *
 * Parameters
 *   priv : private data container for parser related tasks
 *   low  : low index of vector
 *   high : high index of vector
 *
 * Returns
 *   void
 ****************************************************************************/
static void
urj_vhdl_port_add_range (urj_vhdl_parser_priv_t *priv, int low,
                         int high)
{
    urj_bsdl_port_desc_t *pd = &(priv->tmp_port_desc);

    pd->is_vector = 1;
    pd->low_idx = low;
    pd->high_idx = high;
}

/*****************************************************************************
 * void urj_vhdl_port_apply_port( urj_vhdl_parser_priv_t *priv )
 * Port name management function
 *
 * Applies the current temporary port description to the final list
 * of port descriptions.
 *
 * Parameters
 *   priv : private data container for parser related tasks
 *
 * Returns
 *   void
 ****************************************************************************/
static void
urj_vhdl_port_apply_port (urj_vhdl_parser_priv_t *priv)
{
    urj_bsdl_port_desc_t *tmp_pd = &(priv->tmp_port_desc);
    urj_bsdl_port_desc_t *pd = malloc (sizeof (urj_bsdl_port_desc_t));

    if (pd)
    {
        /* insert at top of list */
        pd->next = priv->jtag_ctrl->port_desc;
        priv->jtag_ctrl->port_desc = pd;

        /* copy information from temporary port descriptor */
        pd->names_list = tmp_pd->names_list;
        pd->is_vector = tmp_pd->is_vector;
        pd->low_idx = tmp_pd->low_idx;
        pd->high_idx = tmp_pd->high_idx;

        /* and reset temporary port descriptor */
        tmp_pd->names_list = NULL;
        tmp_pd->next = NULL;
    }
    else
        urj_bsdl_ftl_set (priv->jtag_ctrl->proc_mode, URJ_ERROR_OUT_OF_MEMORY,
                          "No memory");
}

static void
add_elem (urj_vhdl_parser_priv_t *priv, urj_vhdl_elem_t *el)
{
    urj_bsdl_jtag_ctrl_t *jc = priv->jtag_ctrl;

    el->next = NULL;
    if (jc->vhdl_elem_last)
        jc->vhdl_elem_last->next = el;
    jc->vhdl_elem_last = el;

    if (!jc->vhdl_elem_first)
        jc->vhdl_elem_first = el;

    el->line = urj_vhdl_flex_get_lineno (priv->scanner);
}

#if 0
static void
set_attr_bool (urj_vhdl_parser_priv_t *priv, char *name, int value)
{
    urj_vhdl_elem_t *el = malloc (sizeof (urj_vhdl_elem_t));

    if (el)
    {
        el->type = VET_ATTRIBUTE_BOOL;
        el->name = name;
        el->payload.bool = value;

        add_elem (priv, el);
    }
    else
        urj_bsdl_ftl_set (priv->jtag_ctrl->proc_mode, URJ_ERROR_OUT_OF_MEMORY,
                          "No memory");
}
#endif

static void
set_attr_decimal (urj_vhdl_parser_priv_t *priv, char *name, int value)
{
    urj_vhdl_elem_t *el = malloc (sizeof (urj_vhdl_elem_t));
    char *string = malloc (10);

    if (el && string)
    {
        el->type = URJ_BSDL_VET_ATTRIBUTE_DECIMAL;
        el->name = name;
        snprintf (string, 10, "%d", value);
        el->payload = string;

        add_elem (priv, el);
    }
    else
        urj_bsdl_ftl_set (priv->jtag_ctrl->proc_mode, URJ_ERROR_OUT_OF_MEMORY,
                          "No memory");
}

static void
set_attr_string (urj_vhdl_parser_priv_t *priv, char *name, char *string)
{
    urj_vhdl_elem_t *el = malloc (sizeof (urj_vhdl_elem_t));

    /* skip certain attributes */
    if ((strcasecmp (name, "DESIGN_WARNING") == 0)
        || (strcasecmp (name, "BOUNDARY_CELLS") == 0)
        || (strcasecmp (name, "INSTRUCTION_SEQUENCE") == 0)
        || (strcasecmp (name, "INSTRUCTION_USAGE") == 0)
        || (strcasecmp (name, "ISC_DESIGN_WARNING") == 0))
    {
        free (name);
        free (string);
        free (el);
        return;
    }

    if (el)
    {
        el->type = URJ_BSDL_VET_ATTRIBUTE_STRING;
        el->name = name;
        el->payload = string;

        add_elem (priv, el);
    }
    else
        urj_bsdl_ftl_set (priv->jtag_ctrl->proc_mode, URJ_ERROR_OUT_OF_MEMORY,
                          "No memory");
}

#if 0
static void
set_attr_real (urj_vhdl_parser_priv_t *priv, char *name, char *string)
{
    urj_vhdl_elem_t *el = malloc (sizeof (urj_vhdl_elem_t));

    if (el)
    {
        el->type = VET_ATTRIBUTE_REAL;
        el->name = name;
        el->payload.real = string;

        add_elem (priv, el);
    }
    else
        urj_bsdl_ftl_set (priv->jtag_ctrl->proc_mode, URJ_ERROR_OUT_OF_MEMORY,
                          "No memory");
}
#endif

#if 0
static void
set_attr_const (urj_vhdl_parser_priv_t *priv, char *name, char *string)
{
    urj_vhdl_elem_t *el = malloc (sizeof (urj_vhdl_elem_t));

    if (el)
    {
        el->type = URJ_BSDL_VET_CONSTANT;
        el->name = name;
        el->payload = string;

        add_elem (priv, el);
    }
    else
        urj_bsdl_ftl_set (priv->jtag_ctrl->proc_mode, URJ_ERROR_OUT_OF_MEMORY,
                          "No memory");
}
#endif


/*
 Local Variables:
 mode:C
 c-default-style:gnu
 indent-tabs-mode:nil
 End:
*/
