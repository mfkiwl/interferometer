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
#define YYPURE 1

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1


/* Substitute the variable and function names.  */
#define yyparse         urj_bsdl_parse
#define yylex           urj_bsdl_lex
#define yyerror         urj_bsdl_error
#define yydebug         urj_bsdl_debug
#define yynerrs         urj_bsdl_nerrs


/* Copy the first part of user declarations.  */
#line 127 "bsdl_bison.y" /* yacc.c:339  */

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <ctype.h>

#include "bsdl_sysdep.h"

#include "bsdl_types.h"
#include "bsdl_msg.h"

/* interface to flex */
#include "bsdl_bison.h"
#include "bsdl_parser.h"

#ifdef DMALLOC
#include "dmalloc.h"
#endif

#define HACK priv_data->scanner
int yylex (YYSTYPE *, void *);

#if 1
#define ERROR_LIMIT 0
#define BUMP_ERROR \
    do { \
        if (urj_bsdl_flex_postinc_compile_errors (priv_data->scanner) > ERROR_LIMIT) \
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

static void Print_Error (urj_bsdl_parser_priv_t *, const char *);
static void Print_Warning (urj_bsdl_parser_priv_t *, const char *);
static void Give_Up_And_Quit (urj_bsdl_parser_priv_t *);

/* semantic functions */
static void add_instruction (urj_bsdl_parser_priv_t *, char *, char *);
static void ac_set_register (urj_bsdl_parser_priv_t *, char *, int);
static void ac_add_instruction (urj_bsdl_parser_priv_t *, char *);
static void ac_apply_assoc (urj_bsdl_parser_priv_t *);
static void prt_add_name (urj_bsdl_parser_priv_t *, char *);
static void prt_add_bit (urj_bsdl_parser_priv_t *);
static void prt_add_range (urj_bsdl_parser_priv_t *, int, int);
static void ci_no_disable (urj_bsdl_parser_priv_t *);
static void ci_set_cell_spec_disable (urj_bsdl_parser_priv_t *, int, int,
                                      int);
static void ci_set_cell_spec (urj_bsdl_parser_priv_t *, int, char *);
static void ci_append_cell_info (urj_bsdl_parser_priv_t *, int);

void yyerror (urj_bsdl_parser_priv_t *, const char *);

#line 133 "bsdl_bison.c" /* yacc.c:339  */

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
#ifndef YY_URJ_BSDL_BSDL_BISON_H_INCLUDED
# define YY_URJ_BSDL_BSDL_BISON_H_INCLUDED
/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif
#if YYDEBUG
extern int urj_bsdl_debug;
#endif

/* Token type.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    CONSTANT = 258,
    PIN_MAP = 259,
    PHYSICAL_PIN_MAP = 260,
    PIN_MAP_STRING = 261,
    TAP_SCAN_IN = 262,
    TAP_SCAN_OUT = 263,
    TAP_SCAN_MODE = 264,
    TAP_SCAN_RESET = 265,
    TAP_SCAN_CLOCK = 266,
    INSTRUCTION_LENGTH = 267,
    INSTRUCTION_OPCODE = 268,
    INSTRUCTION_CAPTURE = 269,
    INSTRUCTION_DISABLE = 270,
    INSTRUCTION_GUARD = 271,
    INSTRUCTION_PRIVATE = 272,
    REGISTER_ACCESS = 273,
    BOUNDARY_LENGTH = 274,
    BOUNDARY_REGISTER = 275,
    IDCODE_REGISTER = 276,
    USERCODE_REGISTER = 277,
    BOUNDARY = 278,
    DEVICE_ID = 279,
    INPUT = 280,
    OUTPUT2 = 281,
    OUTPUT3 = 282,
    CONTROL = 283,
    CONTROLR = 284,
    INTERNAL = 285,
    CLOCK = 286,
    BIDIR = 287,
    BIDIR_IN = 288,
    BIDIR_OUT = 289,
    Z = 290,
    WEAK0 = 291,
    WEAK1 = 292,
    IDENTIFIER = 293,
    PULL0 = 294,
    PULL1 = 295,
    KEEPER = 296,
    DECIMAL_NUMBER = 297,
    BINARY_PATTERN = 298,
    BIN_X_PATTERN = 299,
    COMMA = 300,
    LPAREN = 301,
    RPAREN = 302,
    LBRACKET = 303,
    RBRACKET = 304,
    COLON = 305,
    ASTERISK = 306,
    COMPLIANCE_PATTERNS = 307,
    OBSERVE_ONLY = 308,
    BYPASS = 309,
    CLAMP = 310,
    EXTEST = 311,
    HIGHZ = 312,
    IDCODE = 313,
    INTEST = 314,
    PRELOAD = 315,
    RUNBIST = 316,
    SAMPLE = 317,
    USERCODE = 318,
    COMPONENT_CONFORMANCE = 319,
    STD_1149_1_1990 = 320,
    STD_1149_1_1993 = 321,
    STD_1149_1_2001 = 322,
    ISC_CONFORMANCE = 323,
    STD_1532_2001 = 324,
    STD_1532_2002 = 325,
    ISC_PIN_BEHAVIOR = 326,
    ISC_FIXED_SYSTEM_PINS = 327,
    ISC_STATUS = 328,
    IMPLEMENTED = 329,
    ISC_BLANK_USERCODE = 330,
    ISC_SECURITY = 331,
    ISC_DISABLE_READ = 332,
    ISC_DISABLE_PROGRAM = 333,
    ISC_DISABLE_ERASE = 334,
    ISC_DISABLE_KEY = 335,
    ISC_FLOW = 336,
    UNPROCESSED = 337,
    EXIT_ON_ERROR = 338,
    ARRAY = 339,
    SECURITY = 340,
    INITIALIZE = 341,
    REPEAT = 342,
    TERMINATE = 343,
    LOOP = 344,
    MIN = 345,
    MAX = 346,
    DOLLAR = 347,
    EQUAL = 348,
    HEX_STRING = 349,
    WAIT = 350,
    REAL_NUMBER = 351,
    PLUS = 352,
    MINUS = 353,
    SH_RIGHT = 354,
    SH_LEFT = 355,
    TILDE = 356,
    QUESTION_MARK = 357,
    EXCLAMATION_MARK = 358,
    QUESTION_EXCLAMATION = 359,
    CRC = 360,
    OST = 361,
    ISC_PROCEDURE = 362,
    ISC_ACTION = 363,
    PROPRIETARY = 364,
    OPTIONAL = 365,
    RECOMMENDED = 366,
    ISC_ILLEGAL_EXIT = 367,
    ILLEGAL = 368
  };
#endif
/* Tokens.  */
#define CONSTANT 258
#define PIN_MAP 259
#define PHYSICAL_PIN_MAP 260
#define PIN_MAP_STRING 261
#define TAP_SCAN_IN 262
#define TAP_SCAN_OUT 263
#define TAP_SCAN_MODE 264
#define TAP_SCAN_RESET 265
#define TAP_SCAN_CLOCK 266
#define INSTRUCTION_LENGTH 267
#define INSTRUCTION_OPCODE 268
#define INSTRUCTION_CAPTURE 269
#define INSTRUCTION_DISABLE 270
#define INSTRUCTION_GUARD 271
#define INSTRUCTION_PRIVATE 272
#define REGISTER_ACCESS 273
#define BOUNDARY_LENGTH 274
#define BOUNDARY_REGISTER 275
#define IDCODE_REGISTER 276
#define USERCODE_REGISTER 277
#define BOUNDARY 278
#define DEVICE_ID 279
#define INPUT 280
#define OUTPUT2 281
#define OUTPUT3 282
#define CONTROL 283
#define CONTROLR 284
#define INTERNAL 285
#define CLOCK 286
#define BIDIR 287
#define BIDIR_IN 288
#define BIDIR_OUT 289
#define Z 290
#define WEAK0 291
#define WEAK1 292
#define IDENTIFIER 293
#define PULL0 294
#define PULL1 295
#define KEEPER 296
#define DECIMAL_NUMBER 297
#define BINARY_PATTERN 298
#define BIN_X_PATTERN 299
#define COMMA 300
#define LPAREN 301
#define RPAREN 302
#define LBRACKET 303
#define RBRACKET 304
#define COLON 305
#define ASTERISK 306
#define COMPLIANCE_PATTERNS 307
#define OBSERVE_ONLY 308
#define BYPASS 309
#define CLAMP 310
#define EXTEST 311
#define HIGHZ 312
#define IDCODE 313
#define INTEST 314
#define PRELOAD 315
#define RUNBIST 316
#define SAMPLE 317
#define USERCODE 318
#define COMPONENT_CONFORMANCE 319
#define STD_1149_1_1990 320
#define STD_1149_1_1993 321
#define STD_1149_1_2001 322
#define ISC_CONFORMANCE 323
#define STD_1532_2001 324
#define STD_1532_2002 325
#define ISC_PIN_BEHAVIOR 326
#define ISC_FIXED_SYSTEM_PINS 327
#define ISC_STATUS 328
#define IMPLEMENTED 329
#define ISC_BLANK_USERCODE 330
#define ISC_SECURITY 331
#define ISC_DISABLE_READ 332
#define ISC_DISABLE_PROGRAM 333
#define ISC_DISABLE_ERASE 334
#define ISC_DISABLE_KEY 335
#define ISC_FLOW 336
#define UNPROCESSED 337
#define EXIT_ON_ERROR 338
#define ARRAY 339
#define SECURITY 340
#define INITIALIZE 341
#define REPEAT 342
#define TERMINATE 343
#define LOOP 344
#define MIN 345
#define MAX 346
#define DOLLAR 347
#define EQUAL 348
#define HEX_STRING 349
#define WAIT 350
#define REAL_NUMBER 351
#define PLUS 352
#define MINUS 353
#define SH_RIGHT 354
#define SH_LEFT 355
#define TILDE 356
#define QUESTION_MARK 357
#define EXCLAMATION_MARK 358
#define QUESTION_EXCLAMATION 359
#define CRC 360
#define OST 361
#define ISC_PROCEDURE 362
#define ISC_ACTION 363
#define PROPRIETARY 364
#define OPTIONAL 365
#define RECOMMENDED 366
#define ISC_ILLEGAL_EXIT 367
#define ILLEGAL 368

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED

union YYSTYPE
{
#line 188 "bsdl_bison.y" /* yacc.c:355  */

  int   integer;
  char *str;

#line 404 "bsdl_bison.c" /* yacc.c:355  */
};

typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif



int urj_bsdl_parse (urj_bsdl_parser_priv_t *priv_data);

#endif /* !YY_URJ_BSDL_BSDL_BISON_H_INCLUDED  */

/* Copy the second part of user declarations.  */

#line 420 "bsdl_bison.c" /* yacc.c:358  */

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
#define YYFINAL  138
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   434

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  114
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  124
/* YYNRULES -- Number of rules.  */
#define YYNRULES  285
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  441

/* YYTRANSLATE[YYX] -- Symbol number corresponding to YYX as returned
   by yylex, with out-of-bounds checking.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   368

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
      45,    46,    47,    48,    49,    50,    51,    52,    53,    54,
      55,    56,    57,    58,    59,    60,    61,    62,    63,    64,
      65,    66,    67,    68,    69,    70,    71,    72,    73,    74,
      75,    76,    77,    78,    79,    80,    81,    82,    83,    84,
      85,    86,    87,    88,    89,    90,    91,    92,    93,    94,
      95,    96,    97,    98,    99,   100,   101,   102,   103,   104,
     105,   106,   107,   108,   109,   110,   111,   112,   113
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,   247,   247,   248,   249,   250,   251,   252,   253,   254,
     255,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   277,   281,   282,   284,   287,   288,
     290,   291,   293,   295,   297,   301,   305,   309,   313,   317,
     321,   326,   328,   329,   330,   338,   341,   343,   351,   356,
     361,   366,   371,   373,   374,   375,   382,   387,   392,   397,
     399,   400,   402,   405,   407,   410,   412,   414,   416,   418,
     421,   422,   424,   426,   428,   430,   432,   434,   436,   438,
     440,   442,   444,   447,   453,   458,   460,   461,   462,   466,
     469,   471,   473,   480,   485,   490,   496,   498,   500,   502,
     504,   506,   508,   510,   512,   515,   517,   527,   530,   532,
     534,   536,   538,   540,   545,   548,   547,   551,   553,   558,
     560,   562,   566,   567,   568,   569,   570,   571,   572,   573,
     574,   575,   578,   579,   582,   584,   585,   586,   594,   596,
     597,   598,   605,   607,   611,   613,   614,   618,   622,   624,
     625,   632,   634,   636,   638,   640,   641,   643,   644,   647,
     649,   650,   652,   653,   654,   655,   656,   657,   658,   659,
     666,   668,   670,   672,   674,   676,   678,   681,   682,   685,
     685,   685,   685,   685,   687,   689,   691,   693,   694,   696,
     697,   699,   701,   702,   704,   706,   707,   709,   711,   713,
     715,   718,   719,   721,   723,   722,   727,   729,   730,   732,
     733,   734,   737,   736,   743,   745,   746,   748,   749,   751,
     752,   755,   754,   759,   760,   761,   762,   764,   765,   767,
     768,   769,   770,   772,   773,   774,   775,   777,   778,   779,
     781,   782,   784,   787,   789,   792,   794,   796,   798,   801,
     803,   805,   807,   809,   811,   814,   816,   817,   819,   821,
     823,   830,   831,   834,   836,   837,   839,   841,   843,   845,
     847,   854,   855,   857,   859,   861,   863,   865,   867,   869,
     871,   874,   874,   877,   879,   881
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 0
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "CONSTANT", "PIN_MAP",
  "PHYSICAL_PIN_MAP", "PIN_MAP_STRING", "TAP_SCAN_IN", "TAP_SCAN_OUT",
  "TAP_SCAN_MODE", "TAP_SCAN_RESET", "TAP_SCAN_CLOCK",
  "INSTRUCTION_LENGTH", "INSTRUCTION_OPCODE", "INSTRUCTION_CAPTURE",
  "INSTRUCTION_DISABLE", "INSTRUCTION_GUARD", "INSTRUCTION_PRIVATE",
  "REGISTER_ACCESS", "BOUNDARY_LENGTH", "BOUNDARY_REGISTER",
  "IDCODE_REGISTER", "USERCODE_REGISTER", "BOUNDARY", "DEVICE_ID", "INPUT",
  "OUTPUT2", "OUTPUT3", "CONTROL", "CONTROLR", "INTERNAL", "CLOCK",
  "BIDIR", "BIDIR_IN", "BIDIR_OUT", "Z", "WEAK0", "WEAK1", "IDENTIFIER",
  "PULL0", "PULL1", "KEEPER", "DECIMAL_NUMBER", "BINARY_PATTERN",
  "BIN_X_PATTERN", "COMMA", "LPAREN", "RPAREN", "LBRACKET", "RBRACKET",
  "COLON", "ASTERISK", "COMPLIANCE_PATTERNS", "OBSERVE_ONLY", "BYPASS",
  "CLAMP", "EXTEST", "HIGHZ", "IDCODE", "INTEST", "PRELOAD", "RUNBIST",
  "SAMPLE", "USERCODE", "COMPONENT_CONFORMANCE", "STD_1149_1_1990",
  "STD_1149_1_1993", "STD_1149_1_2001", "ISC_CONFORMANCE", "STD_1532_2001",
  "STD_1532_2002", "ISC_PIN_BEHAVIOR", "ISC_FIXED_SYSTEM_PINS",
  "ISC_STATUS", "IMPLEMENTED", "ISC_BLANK_USERCODE", "ISC_SECURITY",
  "ISC_DISABLE_READ", "ISC_DISABLE_PROGRAM", "ISC_DISABLE_ERASE",
  "ISC_DISABLE_KEY", "ISC_FLOW", "UNPROCESSED", "EXIT_ON_ERROR", "ARRAY",
  "SECURITY", "INITIALIZE", "REPEAT", "TERMINATE", "LOOP", "MIN", "MAX",
  "DOLLAR", "EQUAL", "HEX_STRING", "WAIT", "REAL_NUMBER", "PLUS", "MINUS",
  "SH_RIGHT", "SH_LEFT", "TILDE", "QUESTION_MARK", "EXCLAMATION_MARK",
  "QUESTION_EXCLAMATION", "CRC", "OST", "ISC_PROCEDURE", "ISC_ACTION",
  "PROPRIETARY", "OPTIONAL", "RECOMMENDED", "ISC_ILLEGAL_EXIT", "ILLEGAL",
  "$accept", "BSDL_Statement", "BSDL_Pin_Map", "BSDL_Map_String",
  "Pin_Mapping", "Physical_Pin_Desc", "Physical_Pin_List", "Physical_Pin",
  "BSDL_Tap_Scan_In", "BSDL_Tap_Scan_Out", "BSDL_Tap_Scan_Mode",
  "BSDL_Tap_Scan_Reset", "BSDL_Tap_Scan_Clock", "BSDL_Inst_Length",
  "BSDL_Opcode", "BSDL_Opcode_Table", "Opcode_Desc", "Binary_Pattern_List",
  "Binary_Pattern", "BSDL_Inst_Capture", "BSDL_Inst_Disable",
  "BSDL_Inst_Guard", "BSDL_Inst_Private", "Private_Opcode_List",
  "Private_Opcode", "BSDL_Idcode_Register", "BSDL_Usercode_Register",
  "BSDL_Register_Access", "Register_String", "Register_Assoc",
  "Register_Decl", "Standard_Reg", "Reg_Opcode_List", "Instruction_Name",
  "Reg_Opcode", "BSDL_Boundary_Length", "BSDL_Boundary_Register",
  "BSDL_Cell_Table", "Cell_Entry", "Cell_Info", "Cell_Spec", "Port_Name",
  "Cell_Function", "Safe_Value", "Disable_Spec", "Disable_Value",
  "BSDL_Compliance_Patterns", "BSDL_Compliance_Pattern", "$@1",
  "Bin_X_Pattern_List", "BSDL_Component_Conformance", "ISC_Extension",
  "ISC_Conformance", "ISC_Pin_Behavior", "Pin_Behavior_Option",
  "ISC_Fixed_System_Pins", "Fixed_Pin_List", "Port_Id", "ISC_Status",
  "Status_Modifier", "ISC_Blank_Usercode", "ISC_Security",
  "Protection_Spec", "Read_Spec", "Program_Spec", "Erase_Spec", "Key_Spec",
  "Bit_Spec", "Bit_Range", "ISC_Flow", "Flow_Definition_List",
  "Flow_Definition", "Flow_Descriptor", "Data_Name", "Standard_Data_Name",
  "Initialize_Block", "Repeat_Block", "Terminate_Block", "Activity_List",
  "Activity_Element", "Loop_Block", "Loop_Min_Spec", "Loop_Max_Spec",
  "Loop_Activity_List", "Activity", "Update_Field_List", "Update_Field",
  "$@2", "Data_Expression", "Variable_Expression", "Variable_Assignment",
  "$@3", "Variable_Update", "Input_Specifier", "Capture_Field_List",
  "Capture_Field", "$@4", "Capture_Field_Rest", "Capture_Specification",
  "Expected_Data", "Compare_Mask", "Wait_Specification",
  "Duration_Specification", "Clock_Cycles", "Variable", "Binary_Operator",
  "Complement_Operator", "Input_Operator", "Output_Operator",
  "IO_Operator", "CRC_Tag", "OST_Tag", "ISC_Procedure", "Procedure_List",
  "Procedure", "Flow_Descriptor_List", "ISC_Action", "Action_List",
  "Action", "Action_Specification_List", "Action_Specification",
  "Option_Specification", "ISC_Illegal_Exit", "Exit_Instruction_List", YY_NULLPTR
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
     335,   336,   337,   338,   339,   340,   341,   342,   343,   344,
     345,   346,   347,   348,   349,   350,   351,   352,   353,   354,
     355,   356,   357,   358,   359,   360,   361,   362,   363,   364,
     365,   366,   367,   368
};
# endif

#define YYPACT_NINF -326

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-326)))

#define YYTABLE_NINF -1

#define yytable_value_is_error(Yytable_value) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
       1,  -326,   125,    97,    96,   138,   142,   150,   155,   180,
      66,   183,   186,   190,    69,    87,   187,    29,   188,   189,
     184,   -24,    74,    28,   101,   193,   191,     2,   111,   114,
     115,   196,   236,  -326,   192,  -326,  -326,  -326,  -326,  -326,
    -326,  -326,  -326,  -326,  -326,  -326,  -326,  -326,  -326,  -326,
    -326,  -326,  -326,  -326,  -326,  -326,  -326,  -326,  -326,  -326,
    -326,  -326,  -326,  -326,  -326,   194,  -326,  -326,  -326,  -326,
    -326,  -326,  -326,  -326,   195,   197,  -326,  -326,  -326,  -326,
    -326,  -326,   198,  -326,  -326,  -326,   199,  -326,  -326,  -326,
     200,  -326,   202,  -326,  -326,  -326,   203,   201,  -326,  -326,
    -326,    20,  -326,  -326,  -326,  -326,  -326,  -326,  -326,  -326,
    -326,  -326,  -326,   204,   206,  -326,  -326,   166,  -326,  -326,
      -4,  -326,   207,  -326,    17,   208,  -326,    60,  -326,     3,
     209,  -326,  -326,   -15,   210,  -326,  -326,   211,  -326,    97,
      91,   214,   220,   221,   218,    87,   113,   223,   222,   216,
    -326,    72,  -326,   224,   225,  -326,  -326,  -326,  -326,   205,
      43,   182,  -326,   185,   111,   -14,   226,   -14,   151,   181,
    -326,   227,   146,   114,   228,   177,   -58,   115,   233,  -326,
      20,  -326,  -326,  -326,   136,  -326,  -326,  -326,   229,  -326,
    -326,  -326,  -326,  -326,  -326,  -326,  -326,  -326,  -326,  -326,
    -326,   156,  -326,  -326,   230,   232,   231,  -326,   235,    20,
    -326,   234,  -326,    -4,   237,   238,  -326,  -326,  -326,  -326,
    -326,   239,  -326,   212,  -326,   113,   213,   -14,  -326,  -326,
    -326,   -14,   -14,   181,  -326,   242,   241,  -326,   246,   243,
     244,   179,  -326,  -326,   157,   214,  -326,  -326,   113,  -326,
      -1,  -326,   249,   245,  -326,   247,  -326,  -326,   215,  -326,
    -326,  -326,    -8,   254,   217,  -326,   -14,  -326,  -326,   160,
     242,   -21,   161,  -326,   246,   246,   251,  -326,  -326,  -326,
     252,  -326,   255,   256,  -326,  -326,   258,    -4,   259,   257,
     -12,    -9,  -326,    -2,  -326,   263,   253,   242,  -326,   164,
     -50,  -326,  -326,    68,  -326,   246,  -326,   165,   168,   246,
     264,   132,   267,  -326,   169,  -326,   240,  -326,  -326,   268,
     248,   266,   270,    10,   265,  -326,   172,  -326,  -326,   271,
    -326,  -326,  -326,   -50,  -326,  -326,  -326,  -326,   173,   269,
    -326,  -326,  -326,  -326,  -326,  -326,  -326,  -326,  -326,   273,
     274,   277,  -326,    -3,  -326,    30,  -326,   272,   250,  -326,
    -326,   176,  -326,   281,  -326,   119,  -326,  -326,  -326,  -326,
      98,   159,  -326,   260,  -326,  -326,   275,  -326,  -326,  -326,
    -326,  -326,  -326,  -326,  -326,    89,  -326,  -326,   -12,  -326,
    -326,   -48,  -326,  -326,  -326,  -326,  -326,  -326,  -326,  -326,
    -326,  -326,  -326,  -326,  -326,   282,  -326,  -326,  -326,  -326,
    -326,  -326,  -326,  -326,   283,  -326,   261,  -326,  -326,  -326,
     276,   278,    30,  -326,   262,  -326,  -326,   120,   280,  -326,
     -48,  -326,  -326,  -326,  -326,  -326,   279,  -326,  -326,    30,
    -326
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint16 yydefact[] =
{
       0,    23,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   145,     0,     0,     0,     0,
       0,     0,     0,     2,     3,     4,     5,     6,     7,     8,
       9,    10,    11,    12,    13,    14,    15,    16,    17,    18,
      19,    20,    21,    22,   122,   123,   124,   125,   126,   127,
     128,   129,   130,   131,    24,     0,    25,    35,    36,    37,
      38,    39,    40,    44,     0,    41,    42,    49,    50,    51,
      55,    56,    52,    53,    65,    69,     0,    66,    67,    68,
      59,    60,     0,    63,    84,    88,     0,    85,    86,    57,
      58,     0,   114,   119,   120,   121,   132,   133,   137,   136,
     135,   134,   141,   142,   138,   139,   146,     0,   147,   150,
       0,   148,     0,   169,   170,   159,   160,   162,   260,     0,
     255,   256,   270,     0,   263,   264,   284,   283,     1,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    32,
      34,     0,    30,     0,     0,   144,   156,   155,   151,     0,
       0,   174,   176,   171,     0,     0,     0,     0,   163,   166,
     168,     0,     0,     0,     0,     0,     0,     0,     0,    26,
       0,    27,    28,    48,     0,    46,    43,    54,     0,    61,
      82,    72,    73,    74,    75,    76,    77,    78,    79,    80,
      81,     0,    83,    70,     0,     0,    90,    87,     0,     0,
     115,     0,   140,     0,     0,     0,   182,   183,   180,   179,
     181,     0,   175,   172,   161,     0,   192,   184,   187,   190,
     189,     0,   186,   164,   167,     0,     0,   257,     0,     0,
       0,     0,   265,   285,     0,     0,    45,    64,     0,    62,
       0,    89,     0,     0,    31,     0,   143,   152,     0,   178,
     177,   173,     0,     0,     0,   188,   185,   165,   261,     0,
       0,   273,     0,   271,     0,     0,     0,    29,    47,    71,
      93,    95,     0,     0,    91,    33,     0,     0,     0,   203,
       0,     0,   201,     0,   193,     0,     0,     0,   258,     0,
     278,   281,   282,   274,   280,     0,   266,     0,     0,     0,
       0,     0,     0,   117,     0,   153,     0,   204,   241,     0,
     237,   240,     0,     0,     0,   197,     0,   219,   194,     0,
     262,   259,   279,   275,   276,   272,   268,   267,     0,     0,
      96,    97,    98,    99,   100,   101,   102,   103,   104,     0,
       0,     0,   116,     0,   149,     0,   243,   238,     0,   202,
     198,     0,   221,     0,   199,     0,   195,   277,   269,    94,
       0,     0,   118,     0,   157,   154,     0,   206,   250,   252,
     205,   208,   210,   211,   207,   209,   217,   218,     0,   242,
     200,   229,   220,   191,   196,   105,   106,    92,   108,   109,
     110,   111,   112,   113,   107,     0,   244,   212,   245,   246,
     247,   248,   249,   214,     0,   215,     0,   251,   232,   222,
     223,   227,   230,   158,     0,   216,   239,     0,   224,   226,
     233,   228,   231,   213,   253,   254,     0,   225,   236,   234,
     235
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -326,  -326,  -326,  -326,   149,  -326,   134,  -116,  -326,  -326,
    -326,  -326,  -326,  -326,  -326,  -326,   219,  -326,    82,  -326,
    -326,  -326,  -326,  -326,   284,  -326,  -326,  -326,  -326,   285,
    -326,  -326,  -326,   103,    83,  -326,  -326,  -326,   286,  -326,
    -326,  -326,  -326,  -326,  -326,  -326,  -326,  -326,  -326,  -326,
    -326,  -326,  -326,  -326,  -326,  -326,  -326,   -23,  -326,  -326,
    -326,  -326,  -326,  -326,  -326,  -326,  -326,  -207,  -326,  -326,
    -326,   170,  -202,  -129,  -326,  -326,   167,  -142,  -139,  -168,
    -326,  -326,  -326,  -326,  -211,  -326,    11,  -326,  -325,  -326,
    -326,  -326,  -326,   -53,    13,   -26,  -326,  -326,  -326,  -326,
    -326,    48,   -47,  -326,  -326,  -326,  -326,  -326,   -90,  -326,
    -326,   -86,  -326,  -326,   171,    73,  -326,  -326,   174,  -154,
      40,  -177,  -326,  -326
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,    32,    33,    34,    66,   181,   151,   152,    35,    36,
      37,    38,    39,    40,    41,    75,    76,   184,   185,    42,
      43,    44,    45,    82,    83,    46,    47,    48,    90,    91,
      92,    93,   201,   202,   203,    49,    50,    97,    98,   205,
     206,   282,   349,   397,   284,   404,    51,   102,   255,   314,
      52,    53,    54,    55,   111,    56,   114,   319,    57,   117,
      58,    59,   121,   122,   214,   288,   354,   158,   375,    60,
     125,   126,   127,   163,   221,   168,   169,   170,   227,   228,
     229,   264,   296,   365,   230,   291,   292,   355,   380,   381,
     382,   424,   383,   384,   326,   327,   391,   419,   420,   421,
     431,   293,   320,   321,   385,   414,   415,   386,   422,   387,
     428,   429,    61,   130,   131,   269,    62,   134,   135,   272,
     273,   304,    63,   137
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_uint16 yytable[] =
{
     172,   115,     1,   119,   176,     2,   257,     3,     4,     5,
       6,     7,     8,     9,    10,    11,    12,    13,    14,    15,
      16,    17,    18,    19,   182,   160,   113,   234,   232,   108,
      95,   160,   225,   268,   289,   240,   322,   280,   156,   373,
     324,   103,   104,   105,   376,   325,   377,   157,   374,   160,
     281,   241,   324,    20,   378,   417,   379,   360,   149,   265,
     301,   302,   150,   160,   265,    21,   418,    73,   268,    22,
      80,    96,    23,    24,    25,   226,    26,    27,   174,   120,
     315,   215,    28,   109,   318,   110,   290,   290,   300,   301,
     302,   267,   266,   254,   175,   330,   171,   432,   265,   161,
     162,   216,   112,   217,    74,   438,   218,    81,    29,    30,
      84,    85,   123,    31,   440,   128,   132,   209,   366,   210,
     307,   308,   376,   332,   377,    86,   334,   219,   220,   149,
      64,   212,   378,   150,   379,    65,   395,   180,    67,   113,
     396,    87,   303,   106,   107,    88,   165,   166,   167,   124,
      89,   190,   129,   133,   394,   338,   367,   340,   341,   342,
     343,   344,   345,   346,   347,   225,   393,   191,   192,   193,
     194,   195,   196,   197,   198,   199,   200,   333,   301,   302,
      68,   245,   407,   246,    69,   348,   408,   409,   410,   411,
     412,   378,    70,   379,   398,   399,   400,    71,   401,   402,
     403,   248,   209,   249,   277,   297,   305,   298,   306,   297,
     305,   331,   336,   305,   351,   337,   352,   363,   305,   364,
     368,   363,    72,   390,    78,   434,   435,    77,    79,    94,
     101,   116,    99,   100,   136,   118,   138,   139,   166,   236,
     155,   141,   142,   143,   140,   145,   148,   144,   146,   147,
     153,   154,   159,   164,   173,   177,   178,   183,    74,    81,
     188,   204,   208,   113,    96,   222,   211,   223,   231,   167,
     239,   243,   276,   235,   238,   250,   252,   253,   247,   251,
     124,   256,   258,   213,   271,   259,   260,   270,   179,   274,
     275,   283,   285,   286,   287,   261,   294,   309,   310,   329,
     311,   312,   313,   263,   316,   328,   339,   317,   295,   350,
     356,   358,   289,   406,   244,   362,   369,   225,   370,   371,
     353,   372,   388,   324,   423,   425,   427,   278,   262,   430,
     436,   279,   413,   359,   224,   233,   361,   392,   357,   323,
     439,   416,   437,   299,   237,   335,   389,     0,     0,     0,
       0,   242,   426,     0,     0,     0,   433,     0,   405,     0,
       0,   186,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   435,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   187,     0,     0,
     189,     0,     0,     0,   207
};

static const yytype_int16 yycheck[] =
{
     129,    24,     1,     1,   133,     4,   213,     6,     7,     8,
       9,    10,    11,    12,    13,    14,    15,    16,    17,    18,
      19,    20,    21,    22,   140,    46,    38,   169,   167,     1,
       1,    46,    46,   235,    42,    93,    45,    38,    42,    42,
      42,    65,    66,    67,    92,    47,    94,    51,    51,    46,
      51,   109,    42,    52,   102,   103,   104,    47,    38,   227,
     110,   111,    42,    46,   232,    64,   391,     1,   270,    68,
       1,    42,    71,    72,    73,    89,    75,    76,    93,    77,
     287,    38,    81,    55,    96,    57,    95,    95,   109,   110,
     111,   233,   231,   209,   109,   297,    93,   422,   266,    82,
      83,    58,     1,    60,    38,   430,    63,    38,   107,   108,
      23,    24,     1,   112,   439,     1,     1,    45,   329,    47,
     274,   275,    92,   300,    94,    38,   303,    84,    85,    38,
       5,   154,   102,    42,   104,    38,    38,    46,    42,    38,
      42,    54,   271,    69,    70,    58,    86,    87,    88,    38,
      63,    38,    38,    38,   365,   309,   333,    25,    26,    27,
      28,    29,    30,    31,    32,    46,    47,    54,    55,    56,
      57,    58,    59,    60,    61,    62,    63,   109,   110,   111,
      42,    45,    93,    47,    42,    53,    97,    98,    99,   100,
     101,   102,    42,   104,    35,    36,    37,    42,    39,    40,
      41,    45,    45,    47,    47,    45,    45,    47,    47,    45,
      45,    47,    47,    45,    45,    47,    47,    45,    45,    47,
      47,    45,    42,    47,    38,   105,   106,    44,    38,    42,
      46,    38,    44,    44,    38,    44,     0,    45,    87,    93,
      74,    46,    45,    45,    50,    45,    45,    48,    46,    46,
      46,    45,    45,    45,    45,    45,    45,    43,    38,    38,
      42,    38,    46,    38,    42,    83,    42,    82,    42,    88,
      93,    38,    93,    46,    46,    45,    45,    42,    49,    47,
      38,    47,    45,    78,    38,    47,    47,    46,   139,    46,
      46,    42,    47,    46,    79,    83,    42,    46,    46,    46,
      45,    45,    44,    90,    45,    42,    42,    50,    91,    42,
      42,    45,    42,    38,   180,    50,    47,    46,    45,    45,
      80,    44,    50,    42,    42,    42,    50,   245,   225,    51,
      50,   248,   385,   322,   164,   168,   323,   363,    90,   291,
     430,   388,   428,   270,   173,   305,    96,    -1,    -1,    -1,
      -1,   177,    91,    -1,    -1,    -1,    94,    -1,    98,    -1,
      -1,   142,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   106,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   143,    -1,    -1,
     145,    -1,    -1,    -1,   148
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,     1,     4,     6,     7,     8,     9,    10,    11,    12,
      13,    14,    15,    16,    17,    18,    19,    20,    21,    22,
      52,    64,    68,    71,    72,    73,    75,    76,    81,   107,
     108,   112,   115,   116,   117,   122,   123,   124,   125,   126,
     127,   128,   133,   134,   135,   136,   139,   140,   141,   149,
     150,   160,   164,   165,   166,   167,   169,   172,   174,   175,
     183,   226,   230,   236,     5,    38,   118,    42,    42,    42,
      42,    42,    42,     1,    38,   129,   130,    44,    38,    38,
       1,    38,   137,   138,    23,    24,    38,    54,    58,    63,
     142,   143,   144,   145,    42,     1,    42,   151,   152,    44,
      44,    46,   161,    65,    66,    67,    69,    70,     1,    55,
      57,   168,     1,    38,   170,   171,    38,   173,    44,     1,
      77,   176,   177,     1,    38,   184,   185,   186,     1,    38,
     227,   228,     1,    38,   231,   232,    38,   237,     0,    45,
      50,    46,    45,    45,    48,    45,    46,    46,    45,    38,
      42,   120,   121,    46,    45,    74,    42,    51,   181,    45,
      46,    82,    83,   187,    45,    86,    87,    88,   189,   190,
     191,    93,   187,    45,    93,   109,   187,    45,    45,   118,
      46,   119,   121,    43,   131,   132,   130,   138,    42,   143,
      38,    54,    55,    56,    57,    58,    59,    60,    61,    62,
      63,   146,   147,   148,    38,   153,   154,   152,    46,    45,
      47,    42,   171,    78,   178,    38,    58,    60,    63,    84,
      85,   188,    83,    82,   185,    46,    89,   192,   193,   194,
     198,    42,   192,   190,   191,    46,    93,   228,    46,    93,
      93,   109,   232,    38,   120,    45,    47,    49,    45,    47,
      45,    47,    45,    42,   121,   162,    47,   181,    45,    47,
      47,    83,   147,    90,   195,   193,   192,   191,   186,   229,
      46,    38,   233,   234,    46,    46,    93,    47,   132,   148,
      38,    51,   155,    42,   158,    47,    46,    79,   179,    42,
      95,   199,   200,   215,    42,    91,   196,    45,    47,   229,
     109,   110,   111,   187,   235,    45,    47,   233,   233,    46,
      46,    45,    45,    44,   163,   181,    45,    50,    96,   171,
     216,   217,    45,   215,    42,    47,   208,   209,    42,    46,
     186,    47,   235,   109,   235,   234,    47,    47,   233,    42,
      25,    26,    27,    28,    29,    30,    31,    32,    53,   156,
      42,    45,    47,    80,   180,   201,    42,    90,    45,   200,
      47,   208,    50,    45,    47,   197,   198,   235,    47,    47,
      45,    45,    44,    42,    51,   182,    92,    94,   102,   104,
     202,   203,   204,   206,   207,   218,   221,   223,    50,    96,
      47,   210,   209,    47,   198,    38,    42,   157,    35,    36,
      37,    39,    40,    41,   159,    98,    38,    93,    97,    98,
      99,   100,   101,   207,   219,   220,   216,   103,   202,   211,
     212,   213,   222,    42,   205,    42,    91,    50,   224,   225,
      51,   214,   202,    94,   105,   106,    50,   225,   202,   222,
     202
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,   114,   115,   115,   115,   115,   115,   115,   115,   115,
     115,   115,   115,   115,   115,   115,   115,   115,   115,   115,
     115,   115,   115,   115,   116,   117,   117,   118,   119,   119,
     120,   120,   121,   121,   121,   122,   123,   124,   125,   126,
     127,   128,   129,   129,   129,   130,   131,   131,   132,   133,
     134,   135,   136,   137,   137,   137,   138,   139,   140,   141,
     142,   142,   143,   144,   144,   145,   145,   145,   145,   145,
     146,   146,   147,   147,   147,   147,   147,   147,   147,   147,
     147,   147,   147,   148,   149,   150,   151,   151,   151,   152,
     153,   153,   154,   155,   155,   155,   156,   156,   156,   156,
     156,   156,   156,   156,   156,   157,   157,   158,   159,   159,
     159,   159,   159,   159,   160,   162,   161,   163,   163,   164,
     164,   164,   165,   165,   165,   165,   165,   165,   165,   165,
     165,   165,   166,   166,   167,   168,   168,   168,   169,   170,
     170,   170,   171,   171,   172,   173,   173,   174,   175,   176,
     176,   177,   178,   179,   180,   181,   181,   182,   182,   183,
     184,   184,   185,   185,   185,   185,   185,   185,   185,   185,
     186,   186,   186,   186,   186,   186,   186,   187,   187,   188,
     188,   188,   188,   188,   189,   190,   191,   192,   192,   193,
     193,   194,   195,   195,   196,   197,   197,   198,   198,   198,
     198,   199,   199,   200,   201,   200,   202,   202,   202,   203,
     203,   203,   205,   204,   204,   206,   206,   207,   207,   208,
     208,   210,   209,   211,   211,   211,   211,   212,   212,   213,
     213,   213,   213,   214,   214,   214,   214,   215,   215,   215,
     216,   216,   216,   217,   218,   219,   219,   219,   219,   220,
     221,   222,   223,   224,   225,   226,   227,   227,   228,   228,
     228,   229,   229,   230,   231,   231,   232,   232,   232,   232,
     232,   233,   233,   234,   234,   234,   234,   234,   234,   234,
     234,   235,   235,   236,   237,   237
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     2,     2,     3,     3,     1,     3,
       1,     3,     1,     4,     1,     2,     2,     2,     2,     2,
       2,     2,     1,     3,     1,     4,     1,     3,     1,     2,
       2,     2,     2,     1,     3,     1,     1,     2,     2,     2,
       1,     3,     4,     1,     4,     1,     1,     1,     1,     1,
       1,     3,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     2,     2,     1,     3,     1,     4,
       1,     3,     7,     1,     4,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     5,     1,     1,
       1,     1,     1,     1,     2,     0,     7,     1,     3,     2,
       2,     2,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     2,     2,     2,     1,     1,     1,     2,     1,
       3,     1,     1,     4,     3,     0,     1,     2,     2,     7,
       1,     2,     2,     2,     2,     1,     1,     1,     3,     2,
       1,     3,     1,     2,     3,     4,     2,     3,     2,     1,
       1,     2,     3,     4,     2,     3,     2,     3,     3,     1,
       1,     1,     1,     1,     2,     3,     2,     1,     2,     1,
       1,     6,     0,     2,     2,     1,     2,     4,     5,     5,
       6,     1,     3,     1,     0,     4,     1,     1,     1,     1,
       1,     1,     0,     4,     2,     2,     3,     1,     1,     1,
       3,     0,     4,     1,     2,     3,     2,     1,     2,     0,
       1,     2,     1,     1,     2,     3,     2,     2,     3,     6,
       1,     1,     3,     2,     2,     1,     1,     1,     1,     1,
       1,     1,     1,     2,     2,     2,     1,     3,     5,     6,
       1,     1,     3,     2,     1,     3,     5,     6,     6,     7,
       1,     1,     3,     1,     2,     3,     3,     4,     2,     3,
       2,     1,     1,     2,     1,     3
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


/*----------------------------------------.
| Print this symbol's value on YYOUTPUT.  |
`----------------------------------------*/

static void
yy_symbol_value_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep, urj_bsdl_parser_priv_t *priv_data)
{
  FILE *yyo = yyoutput;
  YYUSE (yyo);
  YYUSE (priv_data);
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
yy_symbol_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep, urj_bsdl_parser_priv_t *priv_data)
{
  YYFPRINTF (yyoutput, "%s %s (",
             yytype < YYNTOKENS ? "token" : "nterm", yytname[yytype]);

  yy_symbol_value_print (yyoutput, yytype, yyvaluep, priv_data);
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
yy_reduce_print (yytype_int16 *yyssp, YYSTYPE *yyvsp, int yyrule, urj_bsdl_parser_priv_t *priv_data)
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
yydestruct (const char *yymsg, int yytype, YYSTYPE *yyvaluep, urj_bsdl_parser_priv_t *priv_data)
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
yyparse (urj_bsdl_parser_priv_t *priv_data)
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
        case 23:
#line 269 "bsdl_bison.y" /* yacc.c:1646  */
    {
                     Print_Error (priv_data, _("Unsupported BSDL construct found"));
                     BUMP_ERROR;
                     YYABORT;
                   }
#line 1899 "bsdl_bison.c" /* yacc.c:1646  */
    break;

  case 27:
#line 285 "bsdl_bison.y" /* yacc.c:1646  */
    { free ((yyvsp[-2].str)); }
#line 1905 "bsdl_bison.c" /* yacc.c:1646  */
    break;

  case 32:
#line 294 "bsdl_bison.y" /* yacc.c:1646  */
    { free ((yyvsp[0].str)); }
#line 1911 "bsdl_bison.c" /* yacc.c:1646  */
    break;

  case 33:
#line 296 "bsdl_bison.y" /* yacc.c:1646  */
    { free ((yyvsp[-3].str)); }
#line 1917 "bsdl_bison.c" /* yacc.c:1646  */
    break;

  case 40:
#line 322 "bsdl_bison.y" /* yacc.c:1646  */
    { priv_data->jtag_ctrl->instr_len = (yyvsp[0].integer); }
#line 1923 "bsdl_bison.c" /* yacc.c:1646  */
    break;

  case 44:
#line 331 "bsdl_bison.y" /* yacc.c:1646  */
    {
                        Print_Error (priv_data,
                                     _("Error in Instruction_Opcode attribute statement"));
                        BUMP_ERROR;
                        YYABORT;
                      }
#line 1934 "bsdl_bison.c" /* yacc.c:1646  */
    break;

  case 45:
#line 339 "bsdl_bison.y" /* yacc.c:1646  */
    { add_instruction (priv_data, (yyvsp[-3].str), (yyvsp[-1].str)); }
#line 1940 "bsdl_bison.c" /* yacc.c:1646  */
    break;

  case 46:
#line 342 "bsdl_bison.y" /* yacc.c:1646  */
    { (yyval.str) = (yyvsp[0].str); }
#line 1946 "bsdl_bison.c" /* yacc.c:1646  */
    break;

  case 47:
#line 344 "bsdl_bison.y" /* yacc.c:1646  */
    {
                        Print_Warning (priv_data,
                                       _("Multiple opcode patterns are not supported, first pattern will be used"));
                        (yyval.str) = (yyvsp[-2].str);
                        free ((yyvsp[0].str));
                      }
#line 1957 "bsdl_bison.c" /* yacc.c:1646  */
    break;

  case 48:
#line 352 "bsdl_bison.y" /* yacc.c:1646  */
    { (yyval.str) = (yyvsp[0].str); }
#line 1963 "bsdl_bison.c" /* yacc.c:1646  */
    break;

  case 49:
#line 357 "bsdl_bison.y" /* yacc.c:1646  */
    { free ((yyvsp[0].str)); }
#line 1969 "bsdl_bison.c" /* yacc.c:1646  */
    break;

  case 50:
#line 362 "bsdl_bison.y" /* yacc.c:1646  */
    { free ((yyvsp[0].str)); }
#line 1975 "bsdl_bison.c" /* yacc.c:1646  */
    break;

  case 51:
#line 367 "bsdl_bison.y" /* yacc.c:1646  */
    { free ((yyvsp[0].str)); }
#line 1981 "bsdl_bison.c" /* yacc.c:1646  */
    break;

  case 55:
#line 376 "bsdl_bison.y" /* yacc.c:1646  */
    {
                        Print_Error (priv_data, _("Error in Opcode List"));
                        BUMP_ERROR;
                        YYABORT;
                      }
#line 1991 "bsdl_bison.c" /* yacc.c:1646  */
    break;

  case 56:
#line 383 "bsdl_bison.y" /* yacc.c:1646  */
    { free ((yyvsp[0].str)); }
#line 1997 "bsdl_bison.c" /* yacc.c:1646  */
    break;

  case 57:
#line 388 "bsdl_bison.y" /* yacc.c:1646  */
    { priv_data->jtag_ctrl->idcode = (yyvsp[0].str); }
#line 2003 "bsdl_bison.c" /* yacc.c:1646  */
    break;

  case 58:
#line 393 "bsdl_bison.y" /* yacc.c:1646  */
    { priv_data->jtag_ctrl->usercode = (yyvsp[0].str); }
#line 2009 "bsdl_bison.c" /* yacc.c:1646  */
    break;

  case 62:
#line 403 "bsdl_bison.y" /* yacc.c:1646  */
    { ac_apply_assoc (priv_data); }
#line 2015 "bsdl_bison.c" /* yacc.c:1646  */
    break;

  case 63:
#line 406 "bsdl_bison.y" /* yacc.c:1646  */
    { ac_set_register (priv_data, (yyvsp[0].str), 0); }
#line 2021 "bsdl_bison.c" /* yacc.c:1646  */
    break;

  case 64:
#line 408 "bsdl_bison.y" /* yacc.c:1646  */
    { ac_set_register (priv_data, (yyvsp[-3].str), (yyvsp[-1].integer)); }
#line 2027 "bsdl_bison.c" /* yacc.c:1646  */
    break;

  case 65:
#line 411 "bsdl_bison.y" /* yacc.c:1646  */
    { (yyval.str) = strdup ("BOUNDARY"); }
#line 2033 "bsdl_bison.c" /* yacc.c:1646  */
    break;

  case 66:
#line 413 "bsdl_bison.y" /* yacc.c:1646  */
    { (yyval.str) = strdup ("BYPASS"); }
#line 2039 "bsdl_bison.c" /* yacc.c:1646  */
    break;

  case 67:
#line 415 "bsdl_bison.y" /* yacc.c:1646  */
    { (yyval.str) = strdup ("IDCODE"); }
#line 2045 "bsdl_bison.c" /* yacc.c:1646  */
    break;

  case 68:
#line 417 "bsdl_bison.y" /* yacc.c:1646  */
    { (yyval.str) = strdup ("USERCODE"); }
#line 2051 "bsdl_bison.c" /* yacc.c:1646  */
    break;

  case 69:
#line 419 "bsdl_bison.y" /* yacc.c:1646  */
    { (yyval.str) = strdup ("DEVICE_ID"); }
#line 2057 "bsdl_bison.c" /* yacc.c:1646  */
    break;

  case 72:
#line 425 "bsdl_bison.y" /* yacc.c:1646  */
    { (yyval.str) = strdup ("BYPASS"); }
#line 2063 "bsdl_bison.c" /* yacc.c:1646  */
    break;

  case 73:
#line 427 "bsdl_bison.y" /* yacc.c:1646  */
    { (yyval.str) = strdup ("CLAMP"); }
#line 2069 "bsdl_bison.c" /* yacc.c:1646  */
    break;

  case 74:
#line 429 "bsdl_bison.y" /* yacc.c:1646  */
    { (yyval.str) = strdup ("EXTEST"); }
#line 2075 "bsdl_bison.c" /* yacc.c:1646  */
    break;

  case 75:
#line 431 "bsdl_bison.y" /* yacc.c:1646  */
    { (yyval.str) = strdup ("HIGHZ"); }
#line 2081 "bsdl_bison.c" /* yacc.c:1646  */
    break;

  case 76:
#line 433 "bsdl_bison.y" /* yacc.c:1646  */
    { (yyval.str) = strdup ("IDCODE"); }
#line 2087 "bsdl_bison.c" /* yacc.c:1646  */
    break;

  case 77:
#line 435 "bsdl_bison.y" /* yacc.c:1646  */
    { (yyval.str) = strdup ("INTEST"); }
#line 2093 "bsdl_bison.c" /* yacc.c:1646  */
    break;

  case 78:
#line 437 "bsdl_bison.y" /* yacc.c:1646  */
    { (yyval.str) = strdup ("PRELOAD"); }
#line 2099 "bsdl_bison.c" /* yacc.c:1646  */
    break;

  case 79:
#line 439 "bsdl_bison.y" /* yacc.c:1646  */
    { (yyval.str) = strdup ("RUNBIST"); }
#line 2105 "bsdl_bison.c" /* yacc.c:1646  */
    break;

  case 80:
#line 441 "bsdl_bison.y" /* yacc.c:1646  */
    { (yyval.str) = strdup ("SAMPLE"); }
#line 2111 "bsdl_bison.c" /* yacc.c:1646  */
    break;

  case 81:
#line 443 "bsdl_bison.y" /* yacc.c:1646  */
    { (yyval.str) = strdup ("USERCODE"); }
#line 2117 "bsdl_bison.c" /* yacc.c:1646  */
    break;

  case 82:
#line 445 "bsdl_bison.y" /* yacc.c:1646  */
    { (yyval.str) = (yyvsp[0].str); }
#line 2123 "bsdl_bison.c" /* yacc.c:1646  */
    break;

  case 83:
#line 448 "bsdl_bison.y" /* yacc.c:1646  */
    { ac_add_instruction (priv_data, (yyvsp[0].str)); }
#line 2129 "bsdl_bison.c" /* yacc.c:1646  */
    break;

  case 84:
#line 454 "bsdl_bison.y" /* yacc.c:1646  */
    { priv_data->jtag_ctrl->bsr_len = (yyvsp[0].integer); }
#line 2135 "bsdl_bison.c" /* yacc.c:1646  */
    break;

  case 88:
#line 463 "bsdl_bison.y" /* yacc.c:1646  */
    {Print_Error (priv_data, _("Error in Boundary Cell description"));
                   BUMP_ERROR; YYABORT; }
#line 2142 "bsdl_bison.c" /* yacc.c:1646  */
    break;

  case 89:
#line 467 "bsdl_bison.y" /* yacc.c:1646  */
    { ci_append_cell_info (priv_data, (yyvsp[-3].integer)); }
#line 2148 "bsdl_bison.c" /* yacc.c:1646  */
    break;

  case 90:
#line 470 "bsdl_bison.y" /* yacc.c:1646  */
    { ci_no_disable (priv_data); }
#line 2154 "bsdl_bison.c" /* yacc.c:1646  */
    break;

  case 92:
#line 475 "bsdl_bison.y" /* yacc.c:1646  */
    {
                    free ((yyvsp[-6].str));
                    ci_set_cell_spec (priv_data, (yyvsp[-2].integer), (yyvsp[0].str));
                  }
#line 2163 "bsdl_bison.c" /* yacc.c:1646  */
    break;

  case 93:
#line 481 "bsdl_bison.y" /* yacc.c:1646  */
    {
                    prt_add_name (priv_data, (yyvsp[0].str));
                    prt_add_bit (priv_data);
                  }
#line 2172 "bsdl_bison.c" /* yacc.c:1646  */
    break;

  case 94:
#line 486 "bsdl_bison.y" /* yacc.c:1646  */
    {
                    prt_add_name (priv_data, (yyvsp[-3].str));
                    prt_add_range (priv_data, (yyvsp[-1].integer), (yyvsp[-1].integer));
                  }
#line 2181 "bsdl_bison.c" /* yacc.c:1646  */
    break;

  case 95:
#line 491 "bsdl_bison.y" /* yacc.c:1646  */
    {
                    prt_add_name (priv_data, strdup ("*"));
                    prt_add_bit (priv_data);
                  }
#line 2190 "bsdl_bison.c" /* yacc.c:1646  */
    break;

  case 96:
#line 497 "bsdl_bison.y" /* yacc.c:1646  */
    { (yyval.integer) = INPUT; }
#line 2196 "bsdl_bison.c" /* yacc.c:1646  */
    break;

  case 97:
#line 499 "bsdl_bison.y" /* yacc.c:1646  */
    { (yyval.integer) = OUTPUT2; }
#line 2202 "bsdl_bison.c" /* yacc.c:1646  */
    break;

  case 98:
#line 501 "bsdl_bison.y" /* yacc.c:1646  */
    { (yyval.integer) = OUTPUT3; }
#line 2208 "bsdl_bison.c" /* yacc.c:1646  */
    break;

  case 99:
#line 503 "bsdl_bison.y" /* yacc.c:1646  */
    { (yyval.integer) = CONTROL; }
#line 2214 "bsdl_bison.c" /* yacc.c:1646  */
    break;

  case 100:
#line 505 "bsdl_bison.y" /* yacc.c:1646  */
    { (yyval.integer) = CONTROLR; }
#line 2220 "bsdl_bison.c" /* yacc.c:1646  */
    break;

  case 101:
#line 507 "bsdl_bison.y" /* yacc.c:1646  */
    { (yyval.integer) = INTERNAL; }
#line 2226 "bsdl_bison.c" /* yacc.c:1646  */
    break;

  case 102:
#line 509 "bsdl_bison.y" /* yacc.c:1646  */
    { (yyval.integer) = CLOCK; }
#line 2232 "bsdl_bison.c" /* yacc.c:1646  */
    break;

  case 103:
#line 511 "bsdl_bison.y" /* yacc.c:1646  */
    { (yyval.integer) = BIDIR; }
#line 2238 "bsdl_bison.c" /* yacc.c:1646  */
    break;

  case 104:
#line 513 "bsdl_bison.y" /* yacc.c:1646  */
    { (yyval.integer) = OBSERVE_ONLY; }
#line 2244 "bsdl_bison.c" /* yacc.c:1646  */
    break;

  case 105:
#line 516 "bsdl_bison.y" /* yacc.c:1646  */
    { (yyval.str) = (yyvsp[0].str); }
#line 2250 "bsdl_bison.c" /* yacc.c:1646  */
    break;

  case 106:
#line 518 "bsdl_bison.y" /* yacc.c:1646  */
    {
                    char *tmp;
                    /* @@@@ RFHH check malloc result */
                    tmp = malloc (2);
                    snprintf (tmp, 2, "%i", (yyvsp[0].integer));
                    tmp[1] = '\0';
                    (yyval.str) = tmp;
                  }
#line 2263 "bsdl_bison.c" /* yacc.c:1646  */
    break;

  case 107:
#line 528 "bsdl_bison.y" /* yacc.c:1646  */
    { ci_set_cell_spec_disable (priv_data, (yyvsp[-4].integer), (yyvsp[-2].integer), (yyvsp[0].integer)); }
#line 2269 "bsdl_bison.c" /* yacc.c:1646  */
    break;

  case 108:
#line 531 "bsdl_bison.y" /* yacc.c:1646  */
    { (yyval.integer) = Z; }
#line 2275 "bsdl_bison.c" /* yacc.c:1646  */
    break;

  case 109:
#line 533 "bsdl_bison.y" /* yacc.c:1646  */
    { (yyval.integer) = WEAK0; }
#line 2281 "bsdl_bison.c" /* yacc.c:1646  */
    break;

  case 110:
#line 535 "bsdl_bison.y" /* yacc.c:1646  */
    { (yyval.integer) = WEAK1; }
#line 2287 "bsdl_bison.c" /* yacc.c:1646  */
    break;

  case 111:
#line 537 "bsdl_bison.y" /* yacc.c:1646  */
    { (yyval.integer) = PULL0; }
#line 2293 "bsdl_bison.c" /* yacc.c:1646  */
    break;

  case 112:
#line 539 "bsdl_bison.y" /* yacc.c:1646  */
    { (yyval.integer) = PULL1; }
#line 2299 "bsdl_bison.c" /* yacc.c:1646  */
    break;

  case 113:
#line 541 "bsdl_bison.y" /* yacc.c:1646  */
    { (yyval.integer) = KEEPER; }
#line 2305 "bsdl_bison.c" /* yacc.c:1646  */
    break;

  case 115:
#line 548 "bsdl_bison.y" /* yacc.c:1646  */
    { urj_bsdl_flex_set_bin_x (priv_data->scanner); }
#line 2311 "bsdl_bison.c" /* yacc.c:1646  */
    break;

  case 117:
#line 552 "bsdl_bison.y" /* yacc.c:1646  */
    { free ((yyvsp[0].str)); }
#line 2317 "bsdl_bison.c" /* yacc.c:1646  */
    break;

  case 118:
#line 554 "bsdl_bison.y" /* yacc.c:1646  */
    { free ((yyvsp[0].str)); }
#line 2323 "bsdl_bison.c" /* yacc.c:1646  */
    break;

  case 119:
#line 559 "bsdl_bison.y" /* yacc.c:1646  */
    { priv_data->jtag_ctrl->conformance = URJ_BSDL_CONF_1990; }
#line 2329 "bsdl_bison.c" /* yacc.c:1646  */
    break;

  case 120:
#line 561 "bsdl_bison.y" /* yacc.c:1646  */
    { priv_data->jtag_ctrl->conformance = URJ_BSDL_CONF_1993; }
#line 2335 "bsdl_bison.c" /* yacc.c:1646  */
    break;

  case 121:
#line 563 "bsdl_bison.y" /* yacc.c:1646  */
    { priv_data->jtag_ctrl->conformance = URJ_BSDL_CONF_2001; }
#line 2341 "bsdl_bison.c" /* yacc.c:1646  */
    break;

  case 137:
#line 587 "bsdl_bison.y" /* yacc.c:1646  */
    {
                        Print_Error (priv_data, _("Error in ISC_Pin_Behavior Definition"));
                        BUMP_ERROR;
                        YYABORT;
                      }
#line 2351 "bsdl_bison.c" /* yacc.c:1646  */
    break;

  case 141:
#line 599 "bsdl_bison.y" /* yacc.c:1646  */
    {
                          Print_Error (priv_data, _("Error in ISC_Fixed_System_Pins Definition"));
                          BUMP_ERROR;
                          YYABORT;
                        }
#line 2361 "bsdl_bison.c" /* yacc.c:1646  */
    break;

  case 142:
#line 606 "bsdl_bison.y" /* yacc.c:1646  */
    { free ((yyvsp[0].str)); }
#line 2367 "bsdl_bison.c" /* yacc.c:1646  */
    break;

  case 143:
#line 608 "bsdl_bison.y" /* yacc.c:1646  */
    { free ((yyvsp[-3].str)); }
#line 2373 "bsdl_bison.c" /* yacc.c:1646  */
    break;

  case 146:
#line 615 "bsdl_bison.y" /* yacc.c:1646  */
    { free ((yyvsp[0].str)); }
#line 2379 "bsdl_bison.c" /* yacc.c:1646  */
    break;

  case 147:
#line 619 "bsdl_bison.y" /* yacc.c:1646  */
    { free ((yyvsp[0].str)); }
#line 2385 "bsdl_bison.c" /* yacc.c:1646  */
    break;

  case 150:
#line 626 "bsdl_bison.y" /* yacc.c:1646  */
    {
                    Print_Error (priv_data, _("Error in ISC_Security Definition"));
                    BUMP_ERROR;
                    YYABORT;
                  }
#line 2395 "bsdl_bison.c" /* yacc.c:1646  */
    break;

  case 169:
#line 660 "bsdl_bison.y" /* yacc.c:1646  */
    {
                           Print_Error (priv_data, _("Error in ISC_Flow Definition"));
                           BUMP_ERROR;
                           YYABORT;
                         }
#line 2405 "bsdl_bison.c" /* yacc.c:1646  */
    break;

  case 170:
#line 667 "bsdl_bison.y" /* yacc.c:1646  */
    { free ((yyvsp[0].str)); }
#line 2411 "bsdl_bison.c" /* yacc.c:1646  */
    break;

  case 171:
#line 669 "bsdl_bison.y" /* yacc.c:1646  */
    { free ((yyvsp[-1].str)); }
#line 2417 "bsdl_bison.c" /* yacc.c:1646  */
    break;

  case 172:
#line 671 "bsdl_bison.y" /* yacc.c:1646  */
    { free ((yyvsp[-2].str)); }
#line 2423 "bsdl_bison.c" /* yacc.c:1646  */
    break;

  case 173:
#line 673 "bsdl_bison.y" /* yacc.c:1646  */
    { free ((yyvsp[-3].str)); }
#line 2429 "bsdl_bison.c" /* yacc.c:1646  */
    break;

  case 174:
#line 675 "bsdl_bison.y" /* yacc.c:1646  */
    { free ((yyvsp[-1].str)); }
#line 2435 "bsdl_bison.c" /* yacc.c:1646  */
    break;

  case 175:
#line 677 "bsdl_bison.y" /* yacc.c:1646  */
    { free ((yyvsp[-2].str)); }
#line 2441 "bsdl_bison.c" /* yacc.c:1646  */
    break;

  case 176:
#line 679 "bsdl_bison.y" /* yacc.c:1646  */
    { free ((yyvsp[-1].str)); }
#line 2447 "bsdl_bison.c" /* yacc.c:1646  */
    break;

  case 178:
#line 683 "bsdl_bison.y" /* yacc.c:1646  */
    { free ((yyvsp[-1].str)); }
#line 2453 "bsdl_bison.c" /* yacc.c:1646  */
    break;

  case 197:
#line 710 "bsdl_bison.y" /* yacc.c:1646  */
    { free ((yyvsp[-2].str)); }
#line 2459 "bsdl_bison.c" /* yacc.c:1646  */
    break;

  case 198:
#line 712 "bsdl_bison.y" /* yacc.c:1646  */
    { free ((yyvsp[-3].str)); }
#line 2465 "bsdl_bison.c" /* yacc.c:1646  */
    break;

  case 199:
#line 714 "bsdl_bison.y" /* yacc.c:1646  */
    { free ((yyvsp[-3].str)); }
#line 2471 "bsdl_bison.c" /* yacc.c:1646  */
    break;

  case 200:
#line 716 "bsdl_bison.y" /* yacc.c:1646  */
    { free ((yyvsp[-4].str)); }
#line 2477 "bsdl_bison.c" /* yacc.c:1646  */
    break;

  case 204:
#line 723 "bsdl_bison.y" /* yacc.c:1646  */
    { urj_bsdl_flex_set_hex (priv_data->scanner); }
#line 2483 "bsdl_bison.c" /* yacc.c:1646  */
    break;

  case 205:
#line 725 "bsdl_bison.y" /* yacc.c:1646  */
    { urj_bsdl_flex_set_decimal (priv_data->scanner); }
#line 2489 "bsdl_bison.c" /* yacc.c:1646  */
    break;

  case 206:
#line 728 "bsdl_bison.y" /* yacc.c:1646  */
    { free ((yyvsp[0].str)); }
#line 2495 "bsdl_bison.c" /* yacc.c:1646  */
    break;

  case 212:
#line 737 "bsdl_bison.y" /* yacc.c:1646  */
    { urj_bsdl_flex_set_hex (priv_data->scanner); }
#line 2501 "bsdl_bison.c" /* yacc.c:1646  */
    break;

  case 213:
#line 739 "bsdl_bison.y" /* yacc.c:1646  */
    {
                           free ((yyvsp[0].str));
                           urj_bsdl_flex_set_decimal (priv_data->scanner);
                         }
#line 2510 "bsdl_bison.c" /* yacc.c:1646  */
    break;

  case 221:
#line 755 "bsdl_bison.y" /* yacc.c:1646  */
    { urj_bsdl_flex_set_hex (priv_data->scanner); }
#line 2516 "bsdl_bison.c" /* yacc.c:1646  */
    break;

  case 222:
#line 757 "bsdl_bison.y" /* yacc.c:1646  */
    { urj_bsdl_flex_set_decimal (priv_data->scanner); }
#line 2522 "bsdl_bison.c" /* yacc.c:1646  */
    break;

  case 241:
#line 783 "bsdl_bison.y" /* yacc.c:1646  */
    { free ((yyvsp[0].str)); }
#line 2528 "bsdl_bison.c" /* yacc.c:1646  */
    break;

  case 242:
#line 785 "bsdl_bison.y" /* yacc.c:1646  */
    { free ((yyvsp[0].str)); }
#line 2534 "bsdl_bison.c" /* yacc.c:1646  */
    break;

  case 244:
#line 790 "bsdl_bison.y" /* yacc.c:1646  */
    { free ((yyvsp[0].str)); }
#line 2540 "bsdl_bison.c" /* yacc.c:1646  */
    break;

  case 245:
#line 793 "bsdl_bison.y" /* yacc.c:1646  */
    { urj_bsdl_flex_set_decimal (priv_data->scanner); }
#line 2546 "bsdl_bison.c" /* yacc.c:1646  */
    break;

  case 246:
#line 795 "bsdl_bison.y" /* yacc.c:1646  */
    { urj_bsdl_flex_set_decimal (priv_data->scanner); }
#line 2552 "bsdl_bison.c" /* yacc.c:1646  */
    break;

  case 247:
#line 797 "bsdl_bison.y" /* yacc.c:1646  */
    { urj_bsdl_flex_set_decimal (priv_data->scanner); }
#line 2558 "bsdl_bison.c" /* yacc.c:1646  */
    break;

  case 248:
#line 799 "bsdl_bison.y" /* yacc.c:1646  */
    { urj_bsdl_flex_set_decimal (priv_data->scanner); }
#line 2564 "bsdl_bison.c" /* yacc.c:1646  */
    break;

  case 258:
#line 820 "bsdl_bison.y" /* yacc.c:1646  */
    { free ((yyvsp[-4].str)); }
#line 2570 "bsdl_bison.c" /* yacc.c:1646  */
    break;

  case 259:
#line 822 "bsdl_bison.y" /* yacc.c:1646  */
    { free ((yyvsp[-5].str)); }
#line 2576 "bsdl_bison.c" /* yacc.c:1646  */
    break;

  case 260:
#line 824 "bsdl_bison.y" /* yacc.c:1646  */
    {
                         Print_Error (priv_data, _("Error in ISC_Procedure Definition"));
                         BUMP_ERROR;
                         YYABORT;
                       }
#line 2586 "bsdl_bison.c" /* yacc.c:1646  */
    break;

  case 266:
#line 840 "bsdl_bison.y" /* yacc.c:1646  */
    { free ((yyvsp[-4].str)); }
#line 2592 "bsdl_bison.c" /* yacc.c:1646  */
    break;

  case 267:
#line 842 "bsdl_bison.y" /* yacc.c:1646  */
    { free ((yyvsp[-5].str)); }
#line 2598 "bsdl_bison.c" /* yacc.c:1646  */
    break;

  case 268:
#line 844 "bsdl_bison.y" /* yacc.c:1646  */
    { free ((yyvsp[-5].str)); }
#line 2604 "bsdl_bison.c" /* yacc.c:1646  */
    break;

  case 269:
#line 846 "bsdl_bison.y" /* yacc.c:1646  */
    { free ((yyvsp[-6].str)); }
#line 2610 "bsdl_bison.c" /* yacc.c:1646  */
    break;

  case 270:
#line 848 "bsdl_bison.y" /* yacc.c:1646  */
    {
                              Print_Error (priv_data, _("Error in ISC_Action Definition"));
                              BUMP_ERROR;
                              YYABORT;
                            }
#line 2620 "bsdl_bison.c" /* yacc.c:1646  */
    break;

  case 273:
#line 858 "bsdl_bison.y" /* yacc.c:1646  */
    { free ((yyvsp[0].str)); }
#line 2626 "bsdl_bison.c" /* yacc.c:1646  */
    break;

  case 274:
#line 860 "bsdl_bison.y" /* yacc.c:1646  */
    { free ((yyvsp[-1].str)); }
#line 2632 "bsdl_bison.c" /* yacc.c:1646  */
    break;

  case 275:
#line 862 "bsdl_bison.y" /* yacc.c:1646  */
    { free ((yyvsp[-2].str)); }
#line 2638 "bsdl_bison.c" /* yacc.c:1646  */
    break;

  case 276:
#line 864 "bsdl_bison.y" /* yacc.c:1646  */
    { free ((yyvsp[-2].str)); }
#line 2644 "bsdl_bison.c" /* yacc.c:1646  */
    break;

  case 277:
#line 866 "bsdl_bison.y" /* yacc.c:1646  */
    { free ((yyvsp[-3].str)); }
#line 2650 "bsdl_bison.c" /* yacc.c:1646  */
    break;

  case 278:
#line 868 "bsdl_bison.y" /* yacc.c:1646  */
    { free ((yyvsp[-1].str)); }
#line 2656 "bsdl_bison.c" /* yacc.c:1646  */
    break;

  case 279:
#line 870 "bsdl_bison.y" /* yacc.c:1646  */
    { free ((yyvsp[-2].str)); }
#line 2662 "bsdl_bison.c" /* yacc.c:1646  */
    break;

  case 280:
#line 872 "bsdl_bison.y" /* yacc.c:1646  */
    { free ((yyvsp[-1].str)); }
#line 2668 "bsdl_bison.c" /* yacc.c:1646  */
    break;

  case 284:
#line 880 "bsdl_bison.y" /* yacc.c:1646  */
    { free ((yyvsp[0].str)); }
#line 2674 "bsdl_bison.c" /* yacc.c:1646  */
    break;

  case 285:
#line 882 "bsdl_bison.y" /* yacc.c:1646  */
    { free ((yyvsp[0].str)); }
#line 2680 "bsdl_bison.c" /* yacc.c:1646  */
    break;


#line 2684 "bsdl_bison.c" /* yacc.c:1646  */
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
#line 885 "bsdl_bison.y" /* yacc.c:1906  */
  /* End rules, begin programs  */

/*----------------------------------------------------------------------*/
static void
Print_Error (urj_bsdl_parser_priv_t *priv_data, const char *Errmess)
{
    urj_bsdl_err (priv_data->jtag_ctrl->proc_mode,
                  _("Line %d, %s.\n"), priv_data->lineno, Errmess);

    /* set an error if nothing else is pending */
    if (urj_error_get () == URJ_ERROR_OK)
        urj_bsdl_err_set (priv_data->jtag_ctrl->proc_mode,
                          URJ_ERROR_BSDL_BSDL,
                          "Parser error, see log for details");
}

/*----------------------------------------------------------------------*/
static void
Print_Warning (urj_bsdl_parser_priv_t *priv_data, const char *Warnmess)
{
    urj_bsdl_warn (priv_data->jtag_ctrl->proc_mode,
                   _("Line %d, %s.\n"), priv_data->lineno, Warnmess);
}

/*----------------------------------------------------------------------*/
static void
Give_Up_And_Quit (urj_bsdl_parser_priv_t *priv_data)
{
    //Print_Error( priv_data, "Too many errors" );
    urj_bsdl_flex_stop_buffer (priv_data->scanner);
}

/*----------------------------------------------------------------------*/
void
yyerror (urj_bsdl_parser_priv_t *priv_data, const char *error_string)
{
}


/*****************************************************************************
 * void urj_bsdl_sem_init( urj_bsdl_parser_priv_t *priv )
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
urj_bsdl_sem_init (urj_bsdl_parser_priv_t *priv)
{
    urj_bsdl_jtag_ctrl_t *jc = priv->jtag_ctrl;

    jc->instr_len = -1;
    jc->bsr_len = -1;
    jc->conformance = URJ_BSDL_CONF_UNKNOWN;
    jc->idcode = NULL;
    jc->usercode = NULL;

    jc->instr_list = NULL;

    priv->ainfo.next = NULL;
    priv->ainfo.reg = NULL;
    priv->ainfo.instr_list = NULL;
    jc->ainfo_list = NULL;

    priv->tmp_cell_info.next = NULL;
    priv->tmp_cell_info.port_name = NULL;
    priv->tmp_cell_info.basic_safe_value = NULL;
    jc->cell_info_first = NULL;
    jc->cell_info_last = NULL;

    priv->tmp_port_desc.names_list = NULL;
    priv->tmp_port_desc.next = NULL;
}


/*****************************************************************************
 * void free_instr_list( struct instr_elem *il )
 *
 * Deallocates the given list of instr_elem.
 *
 * Parameters
 *   il : first instr_elem to deallocate
 *
 * Returns
 *   void
 ****************************************************************************/
static void
free_instr_list (urj_bsdl_instr_elem_t *il)
{
    if (il)
    {
        if (il->instr)
            free (il->instr);
        if (il->opcode)
            free (il->opcode);
        free_instr_list (il->next);
        free (il);
    }
}


/*****************************************************************************
 * void free_ainfo_list( urj_bsdl_types_ainfo_elem_t *ai, int free_me )
 *
 * Deallocates the given list of ainfo_elem.
 *
 * Parameters
 *  ai      : first ainfo_elem to deallocate
 *  free_me : set to 1 to free memory for ai as well
 *
 * Returns
 *  void
 ****************************************************************************/
static void
free_ainfo_list (urj_bsdl_types_ainfo_elem_t *ai, int free_me)
{
    if (ai)
    {
        if (ai->reg)
            free (ai->reg);

        free_instr_list (ai->instr_list);
        free_ainfo_list (ai->next, 1);

        if (free_me)
            free (ai);
    }
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
 * void free_c_list( urj_bsdl_cell_info_t *ci, int free_me )
 *
 * Deallocates the given list of cell_info items.
 *
 * Parameters
 *  ci      : first cell_info item to deallocate
 *  free_me : 1 -> free memory for *ci as well
 *            0 -> don't free *ci memory
 *
 * Returns
 *  void
 ****************************************************************************/
static void
free_ci_list (urj_bsdl_cell_info_t *ci, int free_me)
{
    if (ci)
    {
        free_ci_list (ci->next, 1);

        if (ci->port_name)
            free (ci->port_name);

        if (ci->basic_safe_value)
            free (ci->basic_safe_value);

        if (free_me)
            free (ci);
    }
}


/*****************************************************************************
 * void urj_bsdl_sem_deinit( urj_bsdl_parser_priv_t *priv )
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
urj_bsdl_sem_deinit (urj_bsdl_parser_priv_t *priv)
{
    urj_bsdl_jtag_ctrl_t *jc = priv->jtag_ctrl;

    if (jc->idcode)
    {
        free (jc->idcode);
        jc->idcode = NULL;
    }

    if (jc->usercode)
    {
        free (jc->usercode);
        jc->usercode = NULL;
    }

    /* free cell_info list */
    free_ci_list (jc->cell_info_first, 1);
    jc->cell_info_first = jc->cell_info_last = NULL;
    free_ci_list (&(priv->tmp_cell_info), 0);

    /* free instr_list */
    free_instr_list (jc->instr_list);
    jc->instr_list = NULL;

    /* free ainfo_list */
    free_ainfo_list (jc->ainfo_list, 1);
    jc->ainfo_list = NULL;
    free_ainfo_list (&(priv->ainfo), 0);

    /* free string list in temporary port descritor */
    free_string_list (priv->tmp_port_desc.names_list);
    priv->tmp_port_desc.names_list = NULL;
}


/*****************************************************************************
 * urj_bsdl_parser_priv_t *urj_bsdl_parser_init( urj_bsdl_jtag_ctrl_t *jtag_ctrl )
 *
 * Initializes storage elements in the private parser structure that are
 * used for parser maintenance purposes.
 * Subsequently calls initializer functions for the scanner and the semantic
 * parts.
 *
 * Parameters
 *   jtag_ctrl : pointer to jtag control structure
 *
 * Returns
 *   pointer to private parser structure
 ****************************************************************************/
urj_bsdl_parser_priv_t *
urj_bsdl_parser_init (urj_bsdl_jtag_ctrl_t *jtag_ctrl)
{
    urj_bsdl_parser_priv_t *new_priv;

    if (!(new_priv = malloc (sizeof (urj_bsdl_parser_priv_t))))
    {
        urj_bsdl_ftl_set (jtag_ctrl->proc_mode, URJ_ERROR_OUT_OF_MEMORY,
                          "No memory");
        return NULL;
    }

    new_priv->jtag_ctrl = jtag_ctrl;

    if (!(new_priv->scanner = urj_bsdl_flex_init (jtag_ctrl->proc_mode)))
    {
        free (new_priv);
        new_priv = NULL;
    }

    urj_bsdl_sem_init (new_priv);

    return new_priv;
}


/*****************************************************************************
 * void urj_bsdl_parser_deinit( urj_bsdl_parser_priv_t *priv )
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
urj_bsdl_parser_deinit (urj_bsdl_parser_priv_t *priv_data)
{
    urj_bsdl_sem_deinit (priv_data);
    urj_bsdl_flex_deinit (priv_data->scanner);
    free (priv_data);
}


/*****************************************************************************
 * void add_instruction( urj_bsdl_parser_priv_t *priv, char *instr, char *opcode )
 *
 * Converts the instruction specification into a member of the main
 * list of instructions at priv->jtag_ctrl->instr_list.
 *
 * Parameters
 *   priv   : private data container for parser related tasks
 *   instr  : instruction name
 *   opcode : instruction opcode
 *
 * Returns
 *   void
 ****************************************************************************/
static void
add_instruction (urj_bsdl_parser_priv_t *priv, char *instr, char *opcode)
{
    urj_bsdl_instr_elem_t *new_instr;

    new_instr = malloc (sizeof (urj_bsdl_instr_elem_t));
    if (new_instr)
    {
        new_instr->next = priv->jtag_ctrl->instr_list;
        new_instr->instr = instr;
        new_instr->opcode = opcode;

        priv->jtag_ctrl->instr_list = new_instr;
    }
    else
        urj_bsdl_ftl_set (priv->jtag_ctrl->proc_mode, URJ_ERROR_OUT_OF_MEMORY,
                          "No memory");
}


/*****************************************************************************
 * void ac_set_register( urj_bsdl_parser_priv_t *priv, char *reg, int reg_len )
 * Register Access management function
 *
 * Stores the register specification values for the current register access
 * specification in the temporary storage region for later usage.
 *
 * Parameters
 *   priv    : private data container for parser related tasks
 *   reg     : register name
 *   reg_len : optional register length
 *
 * Returns
 *   void
 ****************************************************************************/
static void
ac_set_register (urj_bsdl_parser_priv_t *priv, char *reg, int reg_len)
{
    urj_bsdl_types_ainfo_elem_t *tmp_ai = &(priv->ainfo);

    tmp_ai->reg = reg;
    tmp_ai->reg_len = reg_len;
}


/*****************************************************************************
 * void ac_add_instruction( urj_bsdl_parser_priv_t *priv, char *instr )
 * Register Access management function
 *
 * Appends the specified instruction to the list of instructions for the
 * current register access specification in the temporary storage region
 * for later usage.
 *
 * Parameters
 *   priv  : private data container for parser related tasks
 *   instr : instruction name
 *
 * Returns
 *   void
 ****************************************************************************/
static void
ac_add_instruction (urj_bsdl_parser_priv_t *priv, char *instr)
{
    urj_bsdl_types_ainfo_elem_t *tmp_ai = &(priv->ainfo);
    urj_bsdl_instr_elem_t *new_instr;

    new_instr = malloc (sizeof (urj_bsdl_instr_elem_t));
    if (new_instr)
    {
        new_instr->next = tmp_ai->instr_list;
        new_instr->instr = instr;
        new_instr->opcode = NULL;

        tmp_ai->instr_list = new_instr;
    }
    else
        urj_bsdl_ftl_set (priv->jtag_ctrl->proc_mode, URJ_ERROR_OUT_OF_MEMORY,
                          "No memory");
}


/*****************************************************************************
 * void ac_apply_assoc( urj_bsdl_parser_priv_t *priv )
 * Register Access management function
 *
 * Appends the collected register access specification from the temporary
 * storage region to the main ainfo list.
 *
 * Parameters
 *   priv : private data container for parser related tasks
 *
 * Returns
 *   void
 ****************************************************************************/
static void
ac_apply_assoc (urj_bsdl_parser_priv_t *priv)
{
    urj_bsdl_jtag_ctrl_t *jc = priv->jtag_ctrl;
    urj_bsdl_types_ainfo_elem_t *tmp_ai = &(priv->ainfo);
    urj_bsdl_types_ainfo_elem_t *new_ai;

    new_ai = malloc (sizeof (urj_bsdl_types_ainfo_elem_t));
    if (new_ai)
    {
        new_ai->next = jc->ainfo_list;
        new_ai->reg = tmp_ai->reg;
        new_ai->reg_len = tmp_ai->reg_len;
        new_ai->instr_list = tmp_ai->instr_list;

        jc->ainfo_list = new_ai;
    }
    else
        urj_bsdl_ftl_set (jc->proc_mode, URJ_ERROR_OUT_OF_MEMORY,
                          "No memory");

    /* clean up obsolete temporary entries */
    tmp_ai->reg = NULL;
    tmp_ai->reg_len = 0;
    tmp_ai->instr_list = NULL;
}


/*****************************************************************************
 * void prt_add_name( urj_bsdl_parser_priv_t *priv, char *name )
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
prt_add_name (urj_bsdl_parser_priv_t *priv, char *name)
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
 * void prt_add_bit( urj_bsdl_parser_priv_t *priv )
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
prt_add_bit (urj_bsdl_parser_priv_t *priv)
{
    urj_bsdl_port_desc_t *pd = &(priv->tmp_port_desc);

    pd->is_vector = 0;
    pd->low_idx = 0;
    pd->high_idx = 0;
}


/*****************************************************************************
 * void prt_add_range( urj_bsdl_parser_priv_t *priv, int low, int high )
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
prt_add_range (urj_bsdl_parser_priv_t *priv, int low, int high)
{
    urj_bsdl_port_desc_t *pd = &(priv->tmp_port_desc);

    pd->is_vector = 1;
    pd->low_idx = low;
    pd->high_idx = high;
}


/*****************************************************************************
 * void ci_no_disable( urj_bsdl_parser_priv_t *priv )
 * Cell Info management function
 *
 * Tracks that there is no disable term for the current cell info.
 *
 * Parameters
 *   priv : private data container for parser related tasks
 *
 * Returns
 *   void
 ****************************************************************************/
static void
ci_no_disable (urj_bsdl_parser_priv_t *priv)
{
    priv->tmp_cell_info.ctrl_bit_num = -1;
}


/*****************************************************************************
 * void ci_set_cell_spec_disable( urj_bsdl_parser_priv_t *priv, int ctrl_bit_num,
 *                                int safe_value, int disable_value )
 * Cell Info management function
 *
 * Applies the disable specification of the current cell spec to the variables
 * for temporary storage of these information elements.
 *
 * Parameters
 *   priv          : private data container for parser related tasks
 *   ctrl_bit_num  : bit number of related control cell
 *   safe_value    : safe value for initialization of this cell
 *   disable_value : currently ignored
 *
 * Returns
 *   void
 ****************************************************************************/
static void
ci_set_cell_spec_disable (urj_bsdl_parser_priv_t *priv, int ctrl_bit_num,
                          int safe_value, int disable_value)
{
    urj_bsdl_cell_info_t *ci = &(priv->tmp_cell_info);

    ci->ctrl_bit_num = ctrl_bit_num;
    ci->disable_safe_value = safe_value;
    /* disable value is ignored at the moment */
}


/*****************************************************************************
 * void ci_set_cell_spec( urj_bsdl_parser_priv_t *priv,
 *                        int function, char *safe_value )
 * Cell Info management function
 *
 * Sets the specified values of the current cell_spec (without disable term)
 * to the variables for temporary storage of these information elements.
 * The name of the related port is taken from the port_desc structure that
 * was filled in previously by the rule Port_Name.
 *
 * Parameters
 *   priv       : private data container for parser related tasks
 *   function   : cell function indentificator
 *   safe_value : safe value for initialization of this cell
 *
 * Returns
 *   void
 ****************************************************************************/
static void
ci_set_cell_spec (urj_bsdl_parser_priv_t *priv,
                  int function, char *safe_value)
{
    urj_bsdl_cell_info_t *ci = &(priv->tmp_cell_info);
    urj_bsdl_port_desc_t *pd = &(priv->tmp_port_desc);
    urj_bsdl_string_elem_t *name = priv->tmp_port_desc.names_list;
    char *port_string;
    size_t str_len, name_len;

    ci->cell_function = function;
    ci->basic_safe_value = safe_value;

    /* handle indexed port name:
       - names of scalar ports are simply copied from the port_desc structure
       to the final string that goes into ci
       - names of vectored ports are expanded with their decimal index as
       collected earlier earlier in rule Port_Name
     */
    name_len = strlen (name->string);
    str_len = name_len + 1 + 10 + 1 + 1;
    if ((port_string = malloc (str_len)) != NULL)
    {
        if (pd->is_vector)
            snprintf (port_string, str_len - 1, "%s(%d)", name->string,
                      pd->low_idx);
        else
            strncpy (port_string, name->string, str_len - 1);
        port_string[str_len - 1] = '\0';

        ci->port_name = port_string;
    }
    else
    {
        urj_bsdl_ftl_set (priv->jtag_ctrl->proc_mode, URJ_ERROR_OUT_OF_MEMORY,
                          "No memory");
        ci->port_name = NULL;
    }

    free_string_list (priv->tmp_port_desc.names_list);
    priv->tmp_port_desc.names_list = NULL;
}


/*****************************************************************************
 * void ci_append_cell_info( urj_bsdl_parser_priv_t *priv, int bit_num )
 * Cell Info management function
 *
 * Appends the temporary cell info to the global list of cell infos.
 *
 * Parameters
 *   priv    : private data container for parser related tasks
 *   bit_num : bit number of current cell
 *
 * Returns
 *   void
 ****************************************************************************/
static void
ci_append_cell_info (urj_bsdl_parser_priv_t *priv, int bit_num)
{
    urj_bsdl_cell_info_t *tmp_ci = &(priv->tmp_cell_info);
    urj_bsdl_cell_info_t *ci;
    urj_bsdl_jtag_ctrl_t *jc = priv->jtag_ctrl;

    ci = malloc (sizeof (urj_bsdl_cell_info_t));
    if (ci)
    {
        ci->next = NULL;
        if (jc->cell_info_last)
            jc->cell_info_last->next = ci;
        else
            jc->cell_info_first = ci;
        jc->cell_info_last = ci;

        ci->bit_num = bit_num;
        ci->port_name = tmp_ci->port_name;
        ci->cell_function = tmp_ci->cell_function;
        ci->basic_safe_value = tmp_ci->basic_safe_value;
        ci->ctrl_bit_num = tmp_ci->ctrl_bit_num;
        ci->disable_safe_value = tmp_ci->disable_safe_value;

        tmp_ci->port_name = NULL;
        tmp_ci->basic_safe_value = NULL;
    }
    else
        urj_bsdl_ftl_set (jc->proc_mode, URJ_ERROR_OUT_OF_MEMORY,
                          "No memory");
}


/*
 Local Variables:
 mode:C
 c-default-style:java
 indent-tabs-mode:nil
 End:
*/
