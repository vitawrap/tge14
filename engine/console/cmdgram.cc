/* A Bison parser, made by GNU Bison 3.8.2.  */

/* Bison implementation for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015, 2018-2021 Free Software Foundation,
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
   along with this program.  If not, see <https://www.gnu.org/licenses/>.  */

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

/* DO NOT RELY ON FEATURES THAT ARE NOT DOCUMENTED in the manual,
   especially those whose name start with YY_ or yy_.  They are
   private implementation details that can be changed or removed.  */

/* All symbols defined below should begin with yy or YY, to avoid
   infringing on user name space.  This should be done even for local
   variables, as they might otherwise be expanded by user macros.
   There are some unavoidable exceptions within include files to
   define necessary library symbols; they are noted "INFRINGES ON
   USER NAME SPACE" below.  */

/* Identify Bison output, and Bison version.  */
#define YYBISON 30802

/* Bison version string.  */
#define YYBISON_VERSION "3.8.2"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1

/* Substitute the type names.  */
#define YYSTYPE         CMDSTYPE
/* Substitute the variable and function names.  */
#define yyparse         cmdparse
#define yylex           cmdlex
#define yyerror         cmderror
#define yydebug         cmddebug
#define yynerrs         cmdnerrs
#define yylval          cmdlval
#define yychar          cmdchar

/* First part of user prologue.  */
#line 1 "CMDgram.y"


// Make sure we don't get gram.h twice.
#define _CMDGRAM_H_

#include <stdlib.h>
#include <stdio.h>
#include "console/console.h"
#include "console/compiler.h"
#include "console/consoleInternal.h"

#ifndef YYDEBUG
#define YYDEBUG 0
#endif

#define YYSSIZE 350

int outtext(char *fmt, ...);
extern int serrors;

#define nil 0
#undef YY_ARGS
#define YY_ARGS(x)   x
 
int CMDlex();
void cmderror(char *, ...); 

#define alloca dMalloc

/* Prefix arbitrarily switches cases between defines... */
#ifdef yyparse
#undef yyparse
#define yyparse CMDparse
#endif

/* Prefix arbitrarily switches cases between defines... */
#ifdef yylex
#undef yylex
#define yylex CMDlex
#endif


#line 122 "CMDgram.cc"

# ifndef YY_CAST
#  ifdef __cplusplus
#   define YY_CAST(Type, Val) static_cast<Type> (Val)
#   define YY_REINTERPRET_CAST(Type, Val) reinterpret_cast<Type> (Val)
#  else
#   define YY_CAST(Type, Val) ((Type) (Val))
#   define YY_REINTERPRET_CAST(Type, Val) ((Type) (Val))
#  endif
# endif
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

#include "CMDgram.hh"
/* Symbol kind.  */
enum yysymbol_kind_t
{
  YYSYMBOL_YYEMPTY = -2,
  YYSYMBOL_YYEOF = 0,                      /* "end of file"  */
  YYSYMBOL_YYerror = 1,                    /* error  */
  YYSYMBOL_YYUNDEF = 2,                    /* "invalid token"  */
  YYSYMBOL_rwDEFINE = 3,                   /* rwDEFINE  */
  YYSYMBOL_rwDECLARE = 4,                  /* rwDECLARE  */
  YYSYMBOL_rwBREAK = 5,                    /* rwBREAK  */
  YYSYMBOL_rwELSE = 6,                     /* rwELSE  */
  YYSYMBOL_rwCONTINUE = 7,                 /* rwCONTINUE  */
  YYSYMBOL_rwIF = 8,                       /* rwIF  */
  YYSYMBOL_rwRETURN = 9,                   /* rwRETURN  */
  YYSYMBOL_rwWHILE = 10,                   /* rwWHILE  */
  YYSYMBOL_rwDO = 11,                      /* rwDO  */
  YYSYMBOL_rwDEFAULT = 12,                 /* rwDEFAULT  */
  YYSYMBOL_rwNAMESPACE = 13,               /* rwNAMESPACE  */
  YYSYMBOL_rwFOR = 14,                     /* rwFOR  */
  YYSYMBOL_rwDATABLOCK = 15,               /* rwDATABLOCK  */
  YYSYMBOL_rwSWITCH = 16,                  /* rwSWITCH  */
  YYSYMBOL_rwCASE = 17,                    /* rwCASE  */
  YYSYMBOL_rwSWITCHSTR = 18,               /* rwSWITCHSTR  */
  YYSYMBOL_rwCASEOR = 19,                  /* rwCASEOR  */
  YYSYMBOL_rwPACKAGE = 20,                 /* rwPACKAGE  */
  YYSYMBOL_ILLEGAL_TOKEN = 21,             /* ILLEGAL_TOKEN  */
  YYSYMBOL_INTCONST = 22,                  /* INTCONST  */
  YYSYMBOL_TTAG = 23,                      /* TTAG  */
  YYSYMBOL_VAR = 24,                       /* VAR  */
  YYSYMBOL_IDENT = 25,                     /* IDENT  */
  YYSYMBOL_STRATOM = 26,                   /* STRATOM  */
  YYSYMBOL_TAGATOM = 27,                   /* TAGATOM  */
  YYSYMBOL_FLTCONST = 28,                  /* FLTCONST  */
  YYSYMBOL_29_ = 29,                       /* '+'  */
  YYSYMBOL_30_ = 30,                       /* '-'  */
  YYSYMBOL_31_ = 31,                       /* '*'  */
  YYSYMBOL_32_ = 32,                       /* '/'  */
  YYSYMBOL_33_ = 33,                       /* '<'  */
  YYSYMBOL_34_ = 34,                       /* '>'  */
  YYSYMBOL_35_ = 35,                       /* '='  */
  YYSYMBOL_36_ = 36,                       /* '.'  */
  YYSYMBOL_37_ = 37,                       /* '|'  */
  YYSYMBOL_38_ = 38,                       /* '&'  */
  YYSYMBOL_39_ = 39,                       /* '%'  */
  YYSYMBOL_40_ = 40,                       /* '('  */
  YYSYMBOL_41_ = 41,                       /* ')'  */
  YYSYMBOL_42_ = 42,                       /* ','  */
  YYSYMBOL_43_ = 43,                       /* ':'  */
  YYSYMBOL_44_ = 44,                       /* ';'  */
  YYSYMBOL_45_ = 45,                       /* '{'  */
  YYSYMBOL_46_ = 46,                       /* '}'  */
  YYSYMBOL_47_ = 47,                       /* '^'  */
  YYSYMBOL_48_ = 48,                       /* '~'  */
  YYSYMBOL_49_ = 49,                       /* '!'  */
  YYSYMBOL_50_ = 50,                       /* '@'  */
  YYSYMBOL_opMINUSMINUS = 51,              /* opMINUSMINUS  */
  YYSYMBOL_opPLUSPLUS = 52,                /* opPLUSPLUS  */
  YYSYMBOL_opSHL = 53,                     /* opSHL  */
  YYSYMBOL_opSHR = 54,                     /* opSHR  */
  YYSYMBOL_opPLASN = 55,                   /* opPLASN  */
  YYSYMBOL_opMIASN = 56,                   /* opMIASN  */
  YYSYMBOL_opMLASN = 57,                   /* opMLASN  */
  YYSYMBOL_opDVASN = 58,                   /* opDVASN  */
  YYSYMBOL_opMODASN = 59,                  /* opMODASN  */
  YYSYMBOL_opANDASN = 60,                  /* opANDASN  */
  YYSYMBOL_opXORASN = 61,                  /* opXORASN  */
  YYSYMBOL_opORASN = 62,                   /* opORASN  */
  YYSYMBOL_opSLASN = 63,                   /* opSLASN  */
  YYSYMBOL_opSRASN = 64,                   /* opSRASN  */
  YYSYMBOL_opEQ = 65,                      /* opEQ  */
  YYSYMBOL_opNE = 66,                      /* opNE  */
  YYSYMBOL_opGE = 67,                      /* opGE  */
  YYSYMBOL_opLE = 68,                      /* opLE  */
  YYSYMBOL_opAND = 69,                     /* opAND  */
  YYSYMBOL_opOR = 70,                      /* opOR  */
  YYSYMBOL_opSTREQ = 71,                   /* opSTREQ  */
  YYSYMBOL_opCOLONCOLON = 72,              /* opCOLONCOLON  */
  YYSYMBOL_73_ = 73,                       /* '['  */
  YYSYMBOL_opMDASN = 74,                   /* opMDASN  */
  YYSYMBOL_opNDASN = 75,                   /* opNDASN  */
  YYSYMBOL_opNTASN = 76,                   /* opNTASN  */
  YYSYMBOL_77_ = 77,                       /* '?'  */
  YYSYMBOL_opCAT = 78,                     /* opCAT  */
  YYSYMBOL_opSTRNE = 79,                   /* opSTRNE  */
  YYSYMBOL_UNARY = 80,                     /* UNARY  */
  YYSYMBOL_81_ = 81,                       /* ']'  */
  YYSYMBOL_YYACCEPT = 82,                  /* $accept  */
  YYSYMBOL_start = 83,                     /* start  */
  YYSYMBOL_decl_list = 84,                 /* decl_list  */
  YYSYMBOL_decl = 85,                      /* decl  */
  YYSYMBOL_package_decl = 86,              /* package_decl  */
  YYSYMBOL_fn_decl_list = 87,              /* fn_decl_list  */
  YYSYMBOL_statement_list = 88,            /* statement_list  */
  YYSYMBOL_stmt = 89,                      /* stmt  */
  YYSYMBOL_fn_decl_stmt = 90,              /* fn_decl_stmt  */
  YYSYMBOL_var_list_decl = 91,             /* var_list_decl  */
  YYSYMBOL_var_list = 92,                  /* var_list  */
  YYSYMBOL_datablock_decl = 93,            /* datablock_decl  */
  YYSYMBOL_object_decl = 94,               /* object_decl  */
  YYSYMBOL_parent_block = 95,              /* parent_block  */
  YYSYMBOL_object_name = 96,               /* object_name  */
  YYSYMBOL_object_args = 97,               /* object_args  */
  YYSYMBOL_object_declare_block = 98,      /* object_declare_block  */
  YYSYMBOL_object_decl_list = 99,          /* object_decl_list  */
  YYSYMBOL_stmt_block = 100,               /* stmt_block  */
  YYSYMBOL_switch_stmt = 101,              /* switch_stmt  */
  YYSYMBOL_case_block = 102,               /* case_block  */
  YYSYMBOL_case_expr = 103,                /* case_expr  */
  YYSYMBOL_if_stmt = 104,                  /* if_stmt  */
  YYSYMBOL_while_stmt = 105,               /* while_stmt  */
  YYSYMBOL_for_stmt = 106,                 /* for_stmt  */
  YYSYMBOL_expression_stmt = 107,          /* expression_stmt  */
  YYSYMBOL_expr = 108,                     /* expr  */
  YYSYMBOL_slot_acc = 109,                 /* slot_acc  */
  YYSYMBOL_class_name_expr = 110,          /* class_name_expr  */
  YYSYMBOL_assign_op_struct = 111,         /* assign_op_struct  */
  YYSYMBOL_stmt_expr = 112,                /* stmt_expr  */
  YYSYMBOL_funcall_expr = 113,             /* funcall_expr  */
  YYSYMBOL_expr_list_decl = 114,           /* expr_list_decl  */
  YYSYMBOL_expr_list = 115,                /* expr_list  */
  YYSYMBOL_slot_assign_list = 116,         /* slot_assign_list  */
  YYSYMBOL_slot_assign = 117,              /* slot_assign  */
  YYSYMBOL_aidx_expr = 118                 /* aidx_expr  */
};
typedef enum yysymbol_kind_t yysymbol_kind_t;




#ifdef short
# undef short
#endif

/* On compilers that do not define __PTRDIFF_MAX__ etc., make sure
   <limits.h> and (if available) <stdint.h> are included
   so that the code can choose integer types of a good width.  */

#ifndef __PTRDIFF_MAX__
# include <limits.h> /* INFRINGES ON USER NAME SPACE */
# if defined __STDC_VERSION__ && 199901 <= __STDC_VERSION__
#  include <stdint.h> /* INFRINGES ON USER NAME SPACE */
#  define YY_STDINT_H
# endif
#endif

/* Narrow types that promote to a signed type and that can represent a
   signed or unsigned integer of at least N bits.  In tables they can
   save space and decrease cache pressure.  Promoting to a signed type
   helps avoid bugs in integer arithmetic.  */

#ifdef __INT_LEAST8_MAX__
typedef __INT_LEAST8_TYPE__ yytype_int8;
#elif defined YY_STDINT_H
typedef int_least8_t yytype_int8;
#else
typedef signed char yytype_int8;
#endif

#ifdef __INT_LEAST16_MAX__
typedef __INT_LEAST16_TYPE__ yytype_int16;
#elif defined YY_STDINT_H
typedef int_least16_t yytype_int16;
#else
typedef short yytype_int16;
#endif

/* Work around bug in HP-UX 11.23, which defines these macros
   incorrectly for preprocessor constants.  This workaround can likely
   be removed in 2023, as HPE has promised support for HP-UX 11.23
   (aka HP-UX 11i v2) only through the end of 2022; see Table 2 of
   <https://h20195.www2.hpe.com/V2/getpdf.aspx/4AA4-7673ENW.pdf>.  */
#ifdef __hpux
# undef UINT_LEAST8_MAX
# undef UINT_LEAST16_MAX
# define UINT_LEAST8_MAX 255
# define UINT_LEAST16_MAX 65535
#endif

#if defined __UINT_LEAST8_MAX__ && __UINT_LEAST8_MAX__ <= __INT_MAX__
typedef __UINT_LEAST8_TYPE__ yytype_uint8;
#elif (!defined __UINT_LEAST8_MAX__ && defined YY_STDINT_H \
       && UINT_LEAST8_MAX <= INT_MAX)
typedef uint_least8_t yytype_uint8;
#elif !defined __UINT_LEAST8_MAX__ && UCHAR_MAX <= INT_MAX
typedef unsigned char yytype_uint8;
#else
typedef short yytype_uint8;
#endif

#if defined __UINT_LEAST16_MAX__ && __UINT_LEAST16_MAX__ <= __INT_MAX__
typedef __UINT_LEAST16_TYPE__ yytype_uint16;
#elif (!defined __UINT_LEAST16_MAX__ && defined YY_STDINT_H \
       && UINT_LEAST16_MAX <= INT_MAX)
typedef uint_least16_t yytype_uint16;
#elif !defined __UINT_LEAST16_MAX__ && USHRT_MAX <= INT_MAX
typedef unsigned short yytype_uint16;
#else
typedef int yytype_uint16;
#endif

#ifndef YYPTRDIFF_T
# if defined __PTRDIFF_TYPE__ && defined __PTRDIFF_MAX__
#  define YYPTRDIFF_T __PTRDIFF_TYPE__
#  define YYPTRDIFF_MAXIMUM __PTRDIFF_MAX__
# elif defined PTRDIFF_MAX
#  ifndef ptrdiff_t
#   include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  endif
#  define YYPTRDIFF_T ptrdiff_t
#  define YYPTRDIFF_MAXIMUM PTRDIFF_MAX
# else
#  define YYPTRDIFF_T long
#  define YYPTRDIFF_MAXIMUM LONG_MAX
# endif
#endif

#ifndef YYSIZE_T
# ifdef __SIZE_TYPE__
#  define YYSIZE_T __SIZE_TYPE__
# elif defined size_t
#  define YYSIZE_T size_t
# elif defined __STDC_VERSION__ && 199901 <= __STDC_VERSION__
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# else
#  define YYSIZE_T unsigned
# endif
#endif

#define YYSIZE_MAXIMUM                                  \
  YY_CAST (YYPTRDIFF_T,                                 \
           (YYPTRDIFF_MAXIMUM < YY_CAST (YYSIZE_T, -1)  \
            ? YYPTRDIFF_MAXIMUM                         \
            : YY_CAST (YYSIZE_T, -1)))

#define YYSIZEOF(X) YY_CAST (YYPTRDIFF_T, sizeof (X))


/* Stored state numbers (used for stacks). */
typedef yytype_int16 yy_state_t;

/* State numbers in computations.  */
typedef int yy_state_fast_t;

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


#ifndef YY_ATTRIBUTE_PURE
# if defined __GNUC__ && 2 < __GNUC__ + (96 <= __GNUC_MINOR__)
#  define YY_ATTRIBUTE_PURE __attribute__ ((__pure__))
# else
#  define YY_ATTRIBUTE_PURE
# endif
#endif

#ifndef YY_ATTRIBUTE_UNUSED
# if defined __GNUC__ && 2 < __GNUC__ + (7 <= __GNUC_MINOR__)
#  define YY_ATTRIBUTE_UNUSED __attribute__ ((__unused__))
# else
#  define YY_ATTRIBUTE_UNUSED
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YY_USE(E) ((void) (E))
#else
# define YY_USE(E) /* empty */
#endif

/* Suppress an incorrect diagnostic about yylval being uninitialized.  */
#if defined __GNUC__ && ! defined __ICC && 406 <= __GNUC__ * 100 + __GNUC_MINOR__
# if __GNUC__ * 100 + __GNUC_MINOR__ < 407
#  define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN                           \
    _Pragma ("GCC diagnostic push")                                     \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")
# else
#  define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN                           \
    _Pragma ("GCC diagnostic push")                                     \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")              \
    _Pragma ("GCC diagnostic ignored \"-Wmaybe-uninitialized\"")
# endif
# define YY_IGNORE_MAYBE_UNINITIALIZED_END      \
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

#if defined __cplusplus && defined __GNUC__ && ! defined __ICC && 6 <= __GNUC__
# define YY_IGNORE_USELESS_CAST_BEGIN                          \
    _Pragma ("GCC diagnostic push")                            \
    _Pragma ("GCC diagnostic ignored \"-Wuseless-cast\"")
# define YY_IGNORE_USELESS_CAST_END            \
    _Pragma ("GCC diagnostic pop")
#endif
#ifndef YY_IGNORE_USELESS_CAST_BEGIN
# define YY_IGNORE_USELESS_CAST_BEGIN
# define YY_IGNORE_USELESS_CAST_END
#endif


#define YY_ASSERT(E) ((void) (0 && (E)))

#if !defined yyoverflow

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
#endif /* !defined yyoverflow */

#if (! defined yyoverflow \
     && (! defined __cplusplus \
         || (defined CMDSTYPE_IS_TRIVIAL && CMDSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  yy_state_t yyss_alloc;
  YYSTYPE yyvs_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (YYSIZEOF (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (YYSIZEOF (yy_state_t) + YYSIZEOF (YYSTYPE)) \
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
        YYPTRDIFF_T yynewbytes;                                         \
        YYCOPY (&yyptr->Stack_alloc, Stack, yysize);                    \
        Stack = &yyptr->Stack_alloc;                                    \
        yynewbytes = yystacksize * YYSIZEOF (*Stack) + YYSTACK_GAP_MAXIMUM; \
        yyptr += yynewbytes / YYSIZEOF (*yyptr);                        \
      }                                                                 \
    while (0)

#endif

#if defined YYCOPY_NEEDED && YYCOPY_NEEDED
/* Copy COUNT objects from SRC to DST.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(Dst, Src, Count) \
      __builtin_memcpy (Dst, Src, YY_CAST (YYSIZE_T, (Count)) * sizeof (*(Src)))
#  else
#   define YYCOPY(Dst, Src, Count)              \
      do                                        \
        {                                       \
          YYPTRDIFF_T yyi;                      \
          for (yyi = 0; yyi < (Count); yyi++)   \
            (Dst)[yyi] = (Src)[yyi];            \
        }                                       \
      while (0)
#  endif
# endif
#endif /* !YYCOPY_NEEDED */

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  3
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   2213

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  82
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  37
/* YYNRULES -- Number of rules.  */
#define YYNRULES  144
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  320

/* YYMAXUTOK -- Last valid token kind.  */
#define YYMAXUTOK   311


/* YYTRANSLATE(TOKEN-NUM) -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, with out-of-bounds checking.  */
#define YYTRANSLATE(YYX)                                \
  (0 <= (YYX) && (YYX) <= YYMAXUTOK                     \
   ? YY_CAST (yysymbol_kind_t, yytranslate[YYX])        \
   : YYSYMBOL_YYUNDEF)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex.  */
static const yytype_int8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    49,     2,     2,     2,    39,    38,     2,
      40,    41,    31,    29,    42,    30,    36,    32,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,    43,    44,
      33,    35,    34,    77,    50,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,    73,     2,    81,    47,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    45,    37,    46,    48,     2,     2,     2,
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
      25,    26,    27,    28,    51,    52,    53,    54,    55,    56,
      57,    58,    59,    60,    61,    62,    63,    64,    65,    66,
      67,    68,    69,    70,    71,    72,    74,    75,    76,    78,
      79,    80
};

#if CMDDEBUG
/* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_int16 yyrline[] =
{
       0,   148,   148,   154,   155,   160,   162,   164,   169,   174,
     176,   182,   183,   188,   189,   190,   191,   192,   193,   195,
     197,   199,   201,   203,   205,   210,   212,   218,   219,   224,
     226,   231,   236,   238,   244,   245,   251,   252,   258,   259,
     265,   266,   268,   270,   275,   277,   282,   284,   289,   291,
     296,   298,   300,   305,   307,   312,   314,   319,   321,   326,
     328,   330,   332,   334,   336,   338,   340,   345,   350,   352,
     354,   356,   358,   360,   362,   364,   366,   368,   370,   372,
     374,   376,   378,   380,   382,   384,   386,   388,   390,   392,
     394,   396,   398,   400,   402,   404,   406,   408,   410,   412,
     414,   416,   418,   420,   422,   424,   429,   431,   436,   438,
     443,   445,   447,   449,   451,   453,   455,   457,   459,   461,
     463,   465,   470,   472,   474,   476,   478,   480,   482,   484,
     486,   491,   493,   495,   501,   502,   507,   509,   514,   516,
     521,   523,   525,   530,   532
};
#endif

/** Accessing symbol of state STATE.  */
#define YY_ACCESSING_SYMBOL(State) YY_CAST (yysymbol_kind_t, yystos[State])

#if CMDDEBUG || 0
/* The user-facing name of the symbol whose (internal) number is
   YYSYMBOL.  No bounds checking.  */
static const char *yysymbol_name (yysymbol_kind_t yysymbol) YY_ATTRIBUTE_UNUSED;

/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "\"end of file\"", "error", "\"invalid token\"", "rwDEFINE",
  "rwDECLARE", "rwBREAK", "rwELSE", "rwCONTINUE", "rwIF", "rwRETURN",
  "rwWHILE", "rwDO", "rwDEFAULT", "rwNAMESPACE", "rwFOR", "rwDATABLOCK",
  "rwSWITCH", "rwCASE", "rwSWITCHSTR", "rwCASEOR", "rwPACKAGE",
  "ILLEGAL_TOKEN", "INTCONST", "TTAG", "VAR", "IDENT", "STRATOM",
  "TAGATOM", "FLTCONST", "'+'", "'-'", "'*'", "'/'", "'<'", "'>'", "'='",
  "'.'", "'|'", "'&'", "'%'", "'('", "')'", "','", "':'", "';'", "'{'",
  "'}'", "'^'", "'~'", "'!'", "'@'", "opMINUSMINUS", "opPLUSPLUS", "opSHL",
  "opSHR", "opPLASN", "opMIASN", "opMLASN", "opDVASN", "opMODASN",
  "opANDASN", "opXORASN", "opORASN", "opSLASN", "opSRASN", "opEQ", "opNE",
  "opGE", "opLE", "opAND", "opOR", "opSTREQ", "opCOLONCOLON", "'['",
  "opMDASN", "opNDASN", "opNTASN", "'?'", "opCAT", "opSTRNE", "UNARY",
  "']'", "$accept", "start", "decl_list", "decl", "package_decl",
  "fn_decl_list", "statement_list", "stmt", "fn_decl_stmt",
  "var_list_decl", "var_list", "datablock_decl", "object_decl",
  "parent_block", "object_name", "object_args", "object_declare_block",
  "object_decl_list", "stmt_block", "switch_stmt", "case_block",
  "case_expr", "if_stmt", "while_stmt", "for_stmt", "expression_stmt",
  "expr", "slot_acc", "class_name_expr", "assign_op_struct", "stmt_expr",
  "funcall_expr", "expr_list_decl", "expr_list", "slot_assign_list",
  "slot_assign", "aidx_expr", YY_NULLPTR
};

static const char *
yysymbol_name (yysymbol_kind_t yysymbol)
{
  return yytname[yysymbol];
}
#endif

#define YYPACT_NINF (-243)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-68)

#define yytable_value_is_error(Yyn) \
  0

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int16 yypact[] =
{
    -243,    13,  1668,  -243,    42,   -13,   -19,    28,    35,     6,
      45,  1742,    48,    69,    61,    73,    90,  -243,    81,  2116,
       4,  -243,  -243,  -243,  2117,  2117,  2117,  2117,  2117,  -243,
    -243,  -243,  -243,  -243,  -243,  -243,  -243,  -243,  -243,    74,
    1324,  2135,    84,  -243,     8,  -243,  2117,    77,  -243,  -243,
    2117,  -243,  -243,  -243,   304,  -243,  2117,  -243,  -243,   138,
    1936,   109,  2117,  2117,   107,  2117,  2117,  -243,  -243,  2117,
    2117,  2117,  2117,  2117,  2117,  2117,  2117,  2117,  2117,  2117,
    -243,  2117,   128,   119,   119,   355,   119,   119,  -243,  2117,
    2117,  2117,  2117,  2117,  2117,   133,  2117,  2117,  2117,  2117,
    2117,  2117,  2117,  2117,  2117,  2117,  2117,  2117,  2117,  2117,
    2117,  2117,  1947,  -243,   141,   145,   406,  2117,   457,  -243,
     508,  1770,   131,  1977,   559,   148,   610,   661,   173,   130,
    1324,  1324,  1324,  1324,  1324,  1324,  1324,  1324,  1324,  1324,
    1324,  1324,   -16,  1324,   140,   143,   142,  -243,   115,   115,
     119,   119,   222,   222,     0,  1507,  1595,   119,  1551,   260,
     183,   183,   -15,   -15,   222,   222,  1463,  1419,   260,   712,
     260,  2117,  1324,  -243,   146,   144,   151,  -243,   149,  1324,
    1742,  1742,  -243,  -243,  2117,  1572,   763,  2005,   149,   157,
     160,    17,  -243,  2117,  -243,  2117,  2149,  -243,  2117,  2117,
    2117,  2117,  2117,    32,   161,   164,   141,   168,   152,   202,
    -243,   814,  1742,   865,  2033,  2061,   916,   170,   199,   199,
     177,  -243,   967,  1324,  2117,  -243,  1324,   182,   184,     1,
    1375,  -243,  -243,  -243,   186,  -243,  2117,   188,  1742,  -243,
    -243,  1742,  1742,  1018,  1742,  1069,  2089,   179,  2117,   191,
     192,  -243,  -243,  1324,  -243,  -243,  -243,  1816,   185,   143,
     196,  -243,  -243,  -243,  1742,  -243,  1742,  1742,  1120,    56,
      49,  1324,  -243,  -243,  -243,  -243,    62,  -243,  -243,  -243,
    1742,   208,   -28,    75,  -243,  2117,  -243,  1862,   200,   203,
     246,    62,  -243,  2117,  2117,  2117,   215,  -243,  1324,  1714,
    -243,  -243,  -243,   216,   246,  1171,  1222,     5,  -243,   220,
    -243,  -243,  -243,  -243,   231,  -243,  2117,  1908,  1273,  -243
};

/* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE does not specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       3,     0,     2,     1,     0,     0,   100,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    99,    80,   104,
     102,   103,    97,    98,     0,     0,     0,     0,     0,     4,
       7,     5,     6,    16,   123,    17,    13,    14,    15,     0,
       0,   101,    68,   122,     0,   108,     0,     0,    18,    19,
       0,   100,    80,    20,     0,    68,     0,    11,    47,     0,
       0,     0,     0,     0,     0,     0,     0,   111,   110,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     126,   134,     0,    78,    79,     0,    96,    95,    22,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   128,    27,     0,     0,    36,     0,    21,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     124,   112,   113,   114,   115,   116,   117,   118,   119,   120,
     121,   143,     0,   136,     0,   135,     0,    69,    74,    75,
      76,    77,    82,    83,   106,    73,    72,    71,    70,    94,
      89,    90,    86,    87,    84,    85,    91,    88,    92,     0,
      93,     0,   129,    29,     0,    28,     0,   109,    34,    37,
       0,     0,    46,    12,     0,     0,     0,     0,    34,     0,
       0,     0,     9,     0,    23,     0,   105,   131,     0,   134,
     134,     0,     0,     0,     0,     0,    27,     0,    38,    55,
      57,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    10,     0,   144,     0,   127,   137,     0,     0,     0,
      81,   130,    11,    30,     0,    35,     0,     0,     0,    58,
      66,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     8,    24,   125,   132,   133,   107,     0,     0,    39,
      33,    56,    65,    64,     0,    62,     0,     0,     0,     0,
       0,    53,    48,    49,    25,    11,    40,    63,    61,    60,
       0,     0,     0,     0,   138,     0,    11,     0,     0,     0,
      42,    41,    59,     0,     0,     0,     0,   139,    54,    50,
      26,    44,    32,     0,    43,     0,     0,     0,    31,     0,
      52,    45,   141,   140,     0,    11,     0,    51,     0,   142
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -243,  -243,  -243,  -243,  -243,  -243,  -224,    -1,  -122,    64,
    -243,  -243,  -101,    79,  -243,  -243,  -243,   -23,    65,  -243,
    -215,  -243,  -243,  -243,  -243,  -243,    33,  -243,  -243,   -39,
      -2,  -243,  -177,  -166,    -5,  -242,  -198
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
       0,     1,     2,    29,    30,   191,   121,    58,    32,   174,
     175,    33,    34,   208,   178,   237,   289,   290,    59,    35,
     249,   270,    36,    37,    38,    39,    40,    41,    47,    80,
      55,    43,   144,   145,   283,   284,   142
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      42,    31,   113,   229,   250,   203,   192,   294,   257,    42,
       5,    51,    45,     3,    89,    90,    91,    92,    93,    94,
       4,    95,   227,   228,    98,    48,   195,    46,    17,    52,
      19,    20,    21,    22,    23,   100,    24,    25,   101,   102,
     200,   297,    54,   195,    81,   295,    26,   195,   114,   297,
      53,   287,   105,   106,    27,    28,   109,    83,    84,    85,
      86,    87,   299,   220,   111,   196,     5,    44,   285,   221,
     259,   281,    49,   201,   198,    50,    82,   281,   231,   116,
     115,   282,   256,   118,   310,    56,   314,   282,    60,   120,
     281,   317,   286,   124,    61,   126,   127,   307,   129,   130,
     282,    62,   131,   132,   133,   134,   135,   136,   137,   138,
     139,   140,   141,    63,   143,    64,    65,   117,    88,    42,
     183,   296,   148,   149,   150,   151,   152,   153,   -67,   155,
     156,   157,   158,   159,   160,   161,   162,   163,   164,   165,
     166,   167,   168,   169,   170,   172,    91,    92,   122,   125,
     179,    95,   128,   146,    98,    95,   186,   225,   154,    89,
      90,    91,    92,    93,    94,   173,    95,    96,    97,    98,
     176,   184,   193,   188,   194,   288,     4,    99,    42,    42,
     100,   197,   199,   101,   102,   198,   205,   204,   233,   303,
     288,   206,   207,   235,   236,   103,   104,   105,   106,   107,
     108,   109,   218,   303,   143,   219,   232,   110,   238,   111,
      42,   247,    89,    90,    91,    92,   248,   211,   213,    95,
     216,   251,    98,   254,   269,   255,   222,   258,   223,   260,
     275,   226,   143,   143,   141,   230,    42,   272,   273,    42,
      42,   276,    42,   293,   301,   209,   210,   243,   245,   302,
       5,    89,    90,    91,    92,    42,   183,   253,    95,   308,
     311,    98,    42,   315,    42,    42,   316,   217,   304,   143,
     234,   291,   100,     0,     0,   101,   102,   240,    42,   268,
       0,   271,     0,     0,     0,    42,   183,     0,     0,    89,
      90,    91,    92,   109,     0,     0,    95,    42,   183,    98,
       0,   111,     0,   261,     0,     0,   262,   263,     0,   265,
       0,     0,     0,   101,   102,    42,   183,     0,   298,     0,
       0,     0,     0,     0,     0,     0,   305,   306,   141,   277,
       0,   278,   279,    89,    90,    91,    92,    93,    94,     0,
      95,    96,    97,    98,     0,   292,     0,     0,   119,   318,
       0,    99,     0,     0,   100,     0,     0,   101,   102,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   103,
     104,   105,   106,   107,   108,   109,     0,     0,     0,     0,
       0,   110,     0,   111,    89,    90,    91,    92,    93,    94,
       0,    95,    96,    97,    98,     0,   147,     0,     0,     0,
       0,     0,    99,     0,     0,   100,     0,     0,   101,   102,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     103,   104,   105,   106,   107,   108,   109,     0,     0,     0,
       0,     0,   110,     0,   111,    89,    90,    91,    92,    93,
      94,     0,    95,    96,    97,    98,     0,   177,     0,     0,
       0,     0,     0,    99,     0,     0,   100,     0,     0,   101,
     102,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   103,   104,   105,   106,   107,   108,   109,     0,     0,
       0,     0,     0,   110,     0,   111,    89,    90,    91,    92,
      93,    94,     0,    95,    96,    97,    98,     0,   180,     0,
       0,     0,     0,     0,    99,     0,     0,   100,     0,     0,
     101,   102,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   103,   104,   105,   106,   107,   108,   109,     0,
       0,     0,     0,     0,   110,     0,   111,    89,    90,    91,
      92,    93,    94,     0,    95,    96,    97,    98,     0,   181,
       0,     0,     0,     0,     0,    99,     0,     0,   100,     0,
       0,   101,   102,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   103,   104,   105,   106,   107,   108,   109,
       0,     0,     0,     0,     0,   110,     0,   111,    89,    90,
      91,    92,    93,    94,     0,    95,    96,    97,    98,     0,
       0,     0,     0,   187,     0,     0,    99,     0,     0,   100,
       0,     0,   101,   102,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   103,   104,   105,   106,   107,   108,
     109,     0,     0,     0,     0,     0,   110,     0,   111,    89,
      90,    91,    92,    93,    94,     0,    95,    96,    97,    98,
       0,   189,     0,     0,     0,     0,     0,    99,     0,     0,
     100,     0,     0,   101,   102,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   103,   104,   105,   106,   107,
     108,   109,     0,     0,     0,     0,     0,   110,     0,   111,
      89,    90,    91,    92,    93,    94,     0,    95,    96,    97,
      98,     0,   190,     0,     0,     0,     0,     0,    99,     0,
       0,   100,     0,     0,   101,   102,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   103,   104,   105,   106,
     107,   108,   109,     0,     0,     0,     0,     0,   110,     0,
     111,    89,    90,    91,    92,    93,    94,     0,    95,    96,
      97,    98,     0,     0,     0,   202,     0,     0,     0,    99,
       0,     0,   100,     0,     0,   101,   102,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   103,   104,   105,
     106,   107,   108,   109,     0,     0,     0,     0,     0,   110,
       0,   111,    89,    90,    91,    92,    93,    94,     0,    95,
      96,    97,    98,     0,     0,     0,     0,   214,     0,     0,
      99,     0,     0,   100,     0,     0,   101,   102,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   103,   104,
     105,   106,   107,   108,   109,     0,     0,     0,     0,     0,
     110,     0,   111,    89,    90,    91,    92,    93,    94,     0,
      95,    96,    97,    98,     0,   239,     0,     0,     0,     0,
       0,    99,     0,     0,   100,     0,     0,   101,   102,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   103,
     104,   105,   106,   107,   108,   109,     0,     0,     0,     0,
       0,   110,     0,   111,    89,    90,    91,    92,    93,    94,
       0,    95,    96,    97,    98,     0,   241,     0,     0,     0,
       0,     0,    99,     0,     0,   100,     0,     0,   101,   102,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     103,   104,   105,   106,   107,   108,   109,     0,     0,     0,
       0,     0,   110,     0,   111,    89,    90,    91,    92,    93,
      94,     0,    95,    96,    97,    98,     0,     0,     0,     0,
     246,     0,     0,    99,     0,     0,   100,     0,     0,   101,
     102,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   103,   104,   105,   106,   107,   108,   109,     0,     0,
       0,     0,     0,   110,     0,   111,    89,    90,    91,    92,
      93,    94,     0,    95,    96,    97,    98,     0,     0,     0,
       0,   252,     0,     0,    99,     0,     0,   100,     0,     0,
     101,   102,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   103,   104,   105,   106,   107,   108,   109,     0,
       0,     0,     0,     0,   110,     0,   111,    89,    90,    91,
      92,    93,    94,     0,    95,    96,    97,    98,     0,   264,
       0,     0,     0,     0,     0,    99,     0,     0,   100,     0,
       0,   101,   102,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   103,   104,   105,   106,   107,   108,   109,
       0,     0,     0,     0,     0,   110,     0,   111,    89,    90,
      91,    92,    93,    94,     0,    95,    96,    97,    98,     0,
     266,     0,     0,     0,     0,     0,    99,     0,     0,   100,
       0,     0,   101,   102,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   103,   104,   105,   106,   107,   108,
     109,     0,     0,     0,     0,     0,   110,     0,   111,    89,
      90,    91,    92,    93,    94,     0,    95,    96,    97,    98,
       0,   280,     0,     0,     0,     0,     0,    99,     0,     0,
     100,     0,     0,   101,   102,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   103,   104,   105,   106,   107,
     108,   109,     0,     0,     0,     0,     0,   110,     0,   111,
      89,    90,    91,    92,    93,    94,     0,    95,    96,    97,
      98,     0,     0,     0,     0,   312,     0,     0,    99,     0,
       0,   100,     0,     0,   101,   102,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   103,   104,   105,   106,
     107,   108,   109,     0,     0,     0,     0,     0,   110,     0,
     111,    89,    90,    91,    92,    93,    94,     0,    95,    96,
      97,    98,     0,     0,     0,     0,   313,     0,     0,    99,
       0,     0,   100,     0,     0,   101,   102,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   103,   104,   105,
     106,   107,   108,   109,     0,     0,     0,     0,     0,   110,
       0,   111,    89,    90,    91,    92,    93,    94,     0,    95,
      96,    97,    98,     0,     0,     0,     0,   319,     0,     0,
      99,     0,     0,   100,     0,     0,   101,   102,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   103,   104,
     105,   106,   107,   108,   109,     0,     0,     0,     0,     0,
     110,     0,   111,    89,    90,    91,    92,    93,    94,     0,
      95,    96,    97,    98,     0,     0,     0,     0,     0,     0,
       0,    99,     0,     0,   100,     0,     0,   101,   102,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   103,
     104,   105,   106,   107,   108,   109,     0,     0,     0,     0,
       0,   110,     0,   111,    89,    90,    91,    92,    93,    94,
       0,    95,    96,    97,    98,     0,     0,     0,     0,     0,
       0,     0,    99,     0,     0,   100,     0,     0,   101,   102,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     103,   104,   105,   106,   107,   108,   109,     0,    89,    90,
      91,    92,    93,    94,   111,    95,    96,    97,    98,     0,
       0,     0,     0,     0,     0,     0,    99,     0,     0,   100,
       0,     0,   101,   102,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   103,   104,   105,   106,   107,     0,
     109,     0,    89,    90,    91,    92,    93,    94,   111,    95,
      96,    97,    98,     0,     0,     0,     0,     0,     0,     0,
      99,     0,     0,   100,     0,     0,   101,   102,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   103,   104,
     105,   106,     0,     0,   109,     0,    89,    90,    91,    92,
      93,    94,   111,    95,     0,    97,    98,     0,     0,     0,
       0,     0,     0,     0,    99,     0,     0,   100,     0,     0,
     101,   102,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   103,   104,   105,   106,     5,    51,   109,     0,
      89,    90,    91,    92,    93,    94,   111,    95,     0,    97,
      98,     0,     0,     0,    17,    52,    19,    20,    21,    22,
      23,   100,    24,    25,   101,   102,     0,     0,     0,     0,
       0,     0,    26,   212,     0,     0,   103,   104,   105,   106,
      27,    28,   109,     0,    89,    90,    91,    92,    93,    94,
     111,    95,     0,     0,    98,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   100,     0,     0,   101,   102,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     103,   104,   105,   106,     0,     0,   109,     0,     0,     0,
       0,     4,     5,     6,   111,     7,     8,     9,    10,    11,
       0,     0,    12,    13,    14,     0,    15,     0,    16,     0,
      17,    18,    19,    20,    21,    22,    23,     0,    24,    25,
       0,     0,     0,     0,     0,     0,     0,     0,    26,     0,
       0,     0,     0,     0,     0,     0,    27,    28,     5,     6,
       0,     7,     8,     9,    10,    11,   309,     0,    12,    13,
      14,   248,    15,     0,     0,     0,    17,    18,    19,    20,
      21,    22,    23,     0,    24,    25,     5,     6,     0,     7,
       8,     9,    10,    11,    26,     0,    12,    13,    14,     0,
      15,     0,    27,    28,    17,    18,    19,    20,    21,    22,
      23,     0,    24,    25,     5,     6,     0,     7,     8,     9,
      10,    11,    26,     0,    12,    13,    14,    57,    15,     0,
      27,    28,    17,    18,    19,    20,    21,    22,    23,     0,
      24,    25,     0,     0,     0,     0,     0,     0,     0,     0,
      26,     0,     0,     0,     0,     0,   182,     0,    27,    28,
       5,     6,     0,     7,     8,     9,    10,    11,     0,     0,
      12,    13,    14,     0,    15,     0,     0,     0,    17,    18,
      19,    20,    21,    22,    23,     0,    24,    25,     0,     0,
       0,     0,     0,     0,     0,     0,    26,     0,     0,     0,
       0,     0,   274,     0,    27,    28,     5,     6,     0,     7,
       8,     9,    10,    11,     0,     0,    12,    13,    14,     0,
      15,     0,     0,     0,    17,    18,    19,    20,    21,    22,
      23,     0,    24,    25,     0,     0,     0,     0,     0,     0,
       0,     0,    26,     0,     0,     0,     0,     0,   300,     0,
      27,    28,     5,     6,     0,     7,     8,     9,    10,    11,
       0,     0,    12,    13,    14,     0,    15,     0,     0,     0,
      17,    18,    19,    20,    21,    22,    23,     0,    24,    25,
       5,    51,     0,     0,     0,     0,     0,     0,    26,     0,
       0,     5,    51,     0,     0,     0,    27,    28,    17,    52,
      19,    20,    21,    22,    23,     0,    24,    25,     0,    17,
      52,    19,    20,    21,    22,    23,    26,    24,    25,     0,
     123,     5,    51,     0,    27,    28,     0,    26,     0,     0,
       0,     0,   171,     0,     0,    27,    28,     0,     0,    17,
      52,    19,    20,    21,    22,    23,     0,    24,    25,     5,
      51,     0,     0,     0,     0,     0,     0,    26,     0,     0,
       0,   185,     0,     0,     0,    27,    28,    17,    52,    19,
      20,    21,    22,    23,     0,    24,    25,     5,    51,     0,
       0,     0,     0,     0,     0,    26,     0,     0,     0,   215,
       0,     0,     0,    27,    28,    17,    52,    19,    20,    21,
      22,    23,     0,    24,    25,     5,    51,     0,     0,     0,
       0,     0,     0,    26,   242,     0,     0,     0,     0,     0,
       0,    27,    28,    17,    52,    19,    20,    21,    22,    23,
       0,    24,    25,     5,    51,     0,     0,     0,     0,     0,
       0,    26,   244,     0,     0,     0,     0,     0,     0,    27,
      28,    17,    52,    19,    20,    21,    22,    23,     0,    24,
      25,     5,    51,     0,     0,     0,     0,     0,     0,    26,
     267,     0,     0,     0,     0,     0,     0,    27,    28,    17,
      52,    19,    20,    21,    22,    23,     0,    24,    25,     0,
       0,    66,     0,     0,     0,     0,     0,    26,     0,     0,
       0,     0,     0,     0,     0,    27,    28,    67,    68,     0,
     112,    69,    70,    71,    72,    73,    74,    75,    76,    77,
      78,     0,     0,     0,   224,     0,    67,    68,     0,    79,
      69,    70,    71,    72,    73,    74,    75,    76,    77,    78,
      67,    68,     0,     0,    69,    70,    71,    72,    73,    74,
      75,    76,    77,    78
};

static const yytype_int16 yycheck[] =
{
       2,     2,    41,   201,   219,   171,   128,    35,   232,    11,
       4,     5,    25,     0,    29,    30,    31,    32,    33,    34,
       3,    36,   199,   200,    39,    44,    42,    40,    22,    23,
      24,    25,    26,    27,    28,    50,    30,    31,    53,    54,
      40,   283,     9,    42,    40,    73,    40,    42,    40,   291,
      44,   275,    67,    68,    48,    49,    71,    24,    25,    26,
      27,    28,   286,    46,    79,    81,     4,    25,    19,   191,
     236,    15,    44,    73,    42,    40,    72,    15,    46,    46,
      72,    25,    81,    50,   299,    40,    81,    25,    40,    56,
      15,   315,    43,    60,    25,    62,    63,   295,    65,    66,
      25,    40,    69,    70,    71,    72,    73,    74,    75,    76,
      77,    78,    79,    40,    81,    25,    35,    40,    44,   121,
     121,    46,    89,    90,    91,    92,    93,    94,    44,    96,
      97,    98,    99,   100,   101,   102,   103,   104,   105,   106,
     107,   108,   109,   110,   111,   112,    31,    32,    10,    40,
     117,    36,    45,    25,    39,    36,   123,   196,    25,    29,
      30,    31,    32,    33,    34,    24,    36,    37,    38,    39,
      25,    40,    42,    25,    44,   276,     3,    47,   180,   181,
      50,    41,    40,    53,    54,    42,    42,    41,    24,   290,
     291,    40,    43,    25,    42,    65,    66,    67,    68,    69,
      70,    71,    45,   304,   171,    45,    45,    77,     6,    79,
     212,    41,    29,    30,    31,    32,    17,   184,   185,    36,
     187,    44,    39,    41,    45,    41,   193,    41,   195,    41,
      45,   198,   199,   200,   201,   202,   238,    46,    46,   241,
     242,    45,   244,    35,    44,   180,   181,   214,   215,    46,
       4,    29,    30,    31,    32,   257,   257,   224,    36,    44,
      44,    39,   264,    43,   266,   267,    35,   188,   291,   236,
     206,   276,    50,    -1,    -1,    53,    54,   212,   280,   246,
      -1,   248,    -1,    -1,    -1,   287,   287,    -1,    -1,    29,
      30,    31,    32,    71,    -1,    -1,    36,   299,   299,    39,
      -1,    79,    -1,   238,    -1,    -1,   241,   242,    -1,   244,
      -1,    -1,    -1,    53,    54,   317,   317,    -1,   285,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   293,   294,   295,   264,
      -1,   266,   267,    29,    30,    31,    32,    33,    34,    -1,
      36,    37,    38,    39,    -1,   280,    -1,    -1,    44,   316,
      -1,    47,    -1,    -1,    50,    -1,    -1,    53,    54,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    65,
      66,    67,    68,    69,    70,    71,    -1,    -1,    -1,    -1,
      -1,    77,    -1,    79,    29,    30,    31,    32,    33,    34,
      -1,    36,    37,    38,    39,    -1,    41,    -1,    -1,    -1,
      -1,    -1,    47,    -1,    -1,    50,    -1,    -1,    53,    54,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      65,    66,    67,    68,    69,    70,    71,    -1,    -1,    -1,
      -1,    -1,    77,    -1,    79,    29,    30,    31,    32,    33,
      34,    -1,    36,    37,    38,    39,    -1,    41,    -1,    -1,
      -1,    -1,    -1,    47,    -1,    -1,    50,    -1,    -1,    53,
      54,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    65,    66,    67,    68,    69,    70,    71,    -1,    -1,
      -1,    -1,    -1,    77,    -1,    79,    29,    30,    31,    32,
      33,    34,    -1,    36,    37,    38,    39,    -1,    41,    -1,
      -1,    -1,    -1,    -1,    47,    -1,    -1,    50,    -1,    -1,
      53,    54,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    65,    66,    67,    68,    69,    70,    71,    -1,
      -1,    -1,    -1,    -1,    77,    -1,    79,    29,    30,    31,
      32,    33,    34,    -1,    36,    37,    38,    39,    -1,    41,
      -1,    -1,    -1,    -1,    -1,    47,    -1,    -1,    50,    -1,
      -1,    53,    54,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    65,    66,    67,    68,    69,    70,    71,
      -1,    -1,    -1,    -1,    -1,    77,    -1,    79,    29,    30,
      31,    32,    33,    34,    -1,    36,    37,    38,    39,    -1,
      -1,    -1,    -1,    44,    -1,    -1,    47,    -1,    -1,    50,
      -1,    -1,    53,    54,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    65,    66,    67,    68,    69,    70,
      71,    -1,    -1,    -1,    -1,    -1,    77,    -1,    79,    29,
      30,    31,    32,    33,    34,    -1,    36,    37,    38,    39,
      -1,    41,    -1,    -1,    -1,    -1,    -1,    47,    -1,    -1,
      50,    -1,    -1,    53,    54,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    65,    66,    67,    68,    69,
      70,    71,    -1,    -1,    -1,    -1,    -1,    77,    -1,    79,
      29,    30,    31,    32,    33,    34,    -1,    36,    37,    38,
      39,    -1,    41,    -1,    -1,    -1,    -1,    -1,    47,    -1,
      -1,    50,    -1,    -1,    53,    54,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    65,    66,    67,    68,
      69,    70,    71,    -1,    -1,    -1,    -1,    -1,    77,    -1,
      79,    29,    30,    31,    32,    33,    34,    -1,    36,    37,
      38,    39,    -1,    -1,    -1,    43,    -1,    -1,    -1,    47,
      -1,    -1,    50,    -1,    -1,    53,    54,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    65,    66,    67,
      68,    69,    70,    71,    -1,    -1,    -1,    -1,    -1,    77,
      -1,    79,    29,    30,    31,    32,    33,    34,    -1,    36,
      37,    38,    39,    -1,    -1,    -1,    -1,    44,    -1,    -1,
      47,    -1,    -1,    50,    -1,    -1,    53,    54,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    65,    66,
      67,    68,    69,    70,    71,    -1,    -1,    -1,    -1,    -1,
      77,    -1,    79,    29,    30,    31,    32,    33,    34,    -1,
      36,    37,    38,    39,    -1,    41,    -1,    -1,    -1,    -1,
      -1,    47,    -1,    -1,    50,    -1,    -1,    53,    54,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    65,
      66,    67,    68,    69,    70,    71,    -1,    -1,    -1,    -1,
      -1,    77,    -1,    79,    29,    30,    31,    32,    33,    34,
      -1,    36,    37,    38,    39,    -1,    41,    -1,    -1,    -1,
      -1,    -1,    47,    -1,    -1,    50,    -1,    -1,    53,    54,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      65,    66,    67,    68,    69,    70,    71,    -1,    -1,    -1,
      -1,    -1,    77,    -1,    79,    29,    30,    31,    32,    33,
      34,    -1,    36,    37,    38,    39,    -1,    -1,    -1,    -1,
      44,    -1,    -1,    47,    -1,    -1,    50,    -1,    -1,    53,
      54,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    65,    66,    67,    68,    69,    70,    71,    -1,    -1,
      -1,    -1,    -1,    77,    -1,    79,    29,    30,    31,    32,
      33,    34,    -1,    36,    37,    38,    39,    -1,    -1,    -1,
      -1,    44,    -1,    -1,    47,    -1,    -1,    50,    -1,    -1,
      53,    54,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    65,    66,    67,    68,    69,    70,    71,    -1,
      -1,    -1,    -1,    -1,    77,    -1,    79,    29,    30,    31,
      32,    33,    34,    -1,    36,    37,    38,    39,    -1,    41,
      -1,    -1,    -1,    -1,    -1,    47,    -1,    -1,    50,    -1,
      -1,    53,    54,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    65,    66,    67,    68,    69,    70,    71,
      -1,    -1,    -1,    -1,    -1,    77,    -1,    79,    29,    30,
      31,    32,    33,    34,    -1,    36,    37,    38,    39,    -1,
      41,    -1,    -1,    -1,    -1,    -1,    47,    -1,    -1,    50,
      -1,    -1,    53,    54,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    65,    66,    67,    68,    69,    70,
      71,    -1,    -1,    -1,    -1,    -1,    77,    -1,    79,    29,
      30,    31,    32,    33,    34,    -1,    36,    37,    38,    39,
      -1,    41,    -1,    -1,    -1,    -1,    -1,    47,    -1,    -1,
      50,    -1,    -1,    53,    54,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    65,    66,    67,    68,    69,
      70,    71,    -1,    -1,    -1,    -1,    -1,    77,    -1,    79,
      29,    30,    31,    32,    33,    34,    -1,    36,    37,    38,
      39,    -1,    -1,    -1,    -1,    44,    -1,    -1,    47,    -1,
      -1,    50,    -1,    -1,    53,    54,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    65,    66,    67,    68,
      69,    70,    71,    -1,    -1,    -1,    -1,    -1,    77,    -1,
      79,    29,    30,    31,    32,    33,    34,    -1,    36,    37,
      38,    39,    -1,    -1,    -1,    -1,    44,    -1,    -1,    47,
      -1,    -1,    50,    -1,    -1,    53,    54,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    65,    66,    67,
      68,    69,    70,    71,    -1,    -1,    -1,    -1,    -1,    77,
      -1,    79,    29,    30,    31,    32,    33,    34,    -1,    36,
      37,    38,    39,    -1,    -1,    -1,    -1,    44,    -1,    -1,
      47,    -1,    -1,    50,    -1,    -1,    53,    54,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    65,    66,
      67,    68,    69,    70,    71,    -1,    -1,    -1,    -1,    -1,
      77,    -1,    79,    29,    30,    31,    32,    33,    34,    -1,
      36,    37,    38,    39,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    47,    -1,    -1,    50,    -1,    -1,    53,    54,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    65,
      66,    67,    68,    69,    70,    71,    -1,    -1,    -1,    -1,
      -1,    77,    -1,    79,    29,    30,    31,    32,    33,    34,
      -1,    36,    37,    38,    39,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    47,    -1,    -1,    50,    -1,    -1,    53,    54,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      65,    66,    67,    68,    69,    70,    71,    -1,    29,    30,
      31,    32,    33,    34,    79,    36,    37,    38,    39,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    47,    -1,    -1,    50,
      -1,    -1,    53,    54,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    65,    66,    67,    68,    69,    -1,
      71,    -1,    29,    30,    31,    32,    33,    34,    79,    36,
      37,    38,    39,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      47,    -1,    -1,    50,    -1,    -1,    53,    54,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    65,    66,
      67,    68,    -1,    -1,    71,    -1,    29,    30,    31,    32,
      33,    34,    79,    36,    -1,    38,    39,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    47,    -1,    -1,    50,    -1,    -1,
      53,    54,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    65,    66,    67,    68,     4,     5,    71,    -1,
      29,    30,    31,    32,    33,    34,    79,    36,    -1,    38,
      39,    -1,    -1,    -1,    22,    23,    24,    25,    26,    27,
      28,    50,    30,    31,    53,    54,    -1,    -1,    -1,    -1,
      -1,    -1,    40,    41,    -1,    -1,    65,    66,    67,    68,
      48,    49,    71,    -1,    29,    30,    31,    32,    33,    34,
      79,    36,    -1,    -1,    39,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    50,    -1,    -1,    53,    54,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      65,    66,    67,    68,    -1,    -1,    71,    -1,    -1,    -1,
      -1,     3,     4,     5,    79,     7,     8,     9,    10,    11,
      -1,    -1,    14,    15,    16,    -1,    18,    -1,    20,    -1,
      22,    23,    24,    25,    26,    27,    28,    -1,    30,    31,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    40,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    48,    49,     4,     5,
      -1,     7,     8,     9,    10,    11,    12,    -1,    14,    15,
      16,    17,    18,    -1,    -1,    -1,    22,    23,    24,    25,
      26,    27,    28,    -1,    30,    31,     4,     5,    -1,     7,
       8,     9,    10,    11,    40,    -1,    14,    15,    16,    -1,
      18,    -1,    48,    49,    22,    23,    24,    25,    26,    27,
      28,    -1,    30,    31,     4,     5,    -1,     7,     8,     9,
      10,    11,    40,    -1,    14,    15,    16,    45,    18,    -1,
      48,    49,    22,    23,    24,    25,    26,    27,    28,    -1,
      30,    31,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      40,    -1,    -1,    -1,    -1,    -1,    46,    -1,    48,    49,
       4,     5,    -1,     7,     8,     9,    10,    11,    -1,    -1,
      14,    15,    16,    -1,    18,    -1,    -1,    -1,    22,    23,
      24,    25,    26,    27,    28,    -1,    30,    31,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    40,    -1,    -1,    -1,
      -1,    -1,    46,    -1,    48,    49,     4,     5,    -1,     7,
       8,     9,    10,    11,    -1,    -1,    14,    15,    16,    -1,
      18,    -1,    -1,    -1,    22,    23,    24,    25,    26,    27,
      28,    -1,    30,    31,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    40,    -1,    -1,    -1,    -1,    -1,    46,    -1,
      48,    49,     4,     5,    -1,     7,     8,     9,    10,    11,
      -1,    -1,    14,    15,    16,    -1,    18,    -1,    -1,    -1,
      22,    23,    24,    25,    26,    27,    28,    -1,    30,    31,
       4,     5,    -1,    -1,    -1,    -1,    -1,    -1,    40,    -1,
      -1,     4,     5,    -1,    -1,    -1,    48,    49,    22,    23,
      24,    25,    26,    27,    28,    -1,    30,    31,    -1,    22,
      23,    24,    25,    26,    27,    28,    40,    30,    31,    -1,
      44,     4,     5,    -1,    48,    49,    -1,    40,    -1,    -1,
      -1,    -1,    45,    -1,    -1,    48,    49,    -1,    -1,    22,
      23,    24,    25,    26,    27,    28,    -1,    30,    31,     4,
       5,    -1,    -1,    -1,    -1,    -1,    -1,    40,    -1,    -1,
      -1,    44,    -1,    -1,    -1,    48,    49,    22,    23,    24,
      25,    26,    27,    28,    -1,    30,    31,     4,     5,    -1,
      -1,    -1,    -1,    -1,    -1,    40,    -1,    -1,    -1,    44,
      -1,    -1,    -1,    48,    49,    22,    23,    24,    25,    26,
      27,    28,    -1,    30,    31,     4,     5,    -1,    -1,    -1,
      -1,    -1,    -1,    40,    41,    -1,    -1,    -1,    -1,    -1,
      -1,    48,    49,    22,    23,    24,    25,    26,    27,    28,
      -1,    30,    31,     4,     5,    -1,    -1,    -1,    -1,    -1,
      -1,    40,    41,    -1,    -1,    -1,    -1,    -1,    -1,    48,
      49,    22,    23,    24,    25,    26,    27,    28,    -1,    30,
      31,     4,     5,    -1,    -1,    -1,    -1,    -1,    -1,    40,
      41,    -1,    -1,    -1,    -1,    -1,    -1,    48,    49,    22,
      23,    24,    25,    26,    27,    28,    -1,    30,    31,    -1,
      -1,    35,    -1,    -1,    -1,    -1,    -1,    40,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    48,    49,    51,    52,    -1,
      35,    55,    56,    57,    58,    59,    60,    61,    62,    63,
      64,    -1,    -1,    -1,    35,    -1,    51,    52,    -1,    73,
      55,    56,    57,    58,    59,    60,    61,    62,    63,    64,
      51,    52,    -1,    -1,    55,    56,    57,    58,    59,    60,
      61,    62,    63,    64
};

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,    83,    84,     0,     3,     4,     5,     7,     8,     9,
      10,    11,    14,    15,    16,    18,    20,    22,    23,    24,
      25,    26,    27,    28,    30,    31,    40,    48,    49,    85,
      86,    89,    90,    93,    94,   101,   104,   105,   106,   107,
     108,   109,   112,   113,    25,    25,    40,   110,    44,    44,
      40,     5,    23,    44,   108,   112,    40,    45,    89,   100,
      40,    25,    40,    40,    25,    35,    35,    51,    52,    55,
      56,    57,    58,    59,    60,    61,    62,    63,    64,    73,
     111,    40,    72,   108,   108,   108,   108,   108,    44,    29,
      30,    31,    32,    33,    34,    36,    37,    38,    39,    47,
      50,    53,    54,    65,    66,    67,    68,    69,    70,    71,
      77,    79,    35,   111,    40,    72,   108,    40,   108,    44,
     108,    88,    10,    44,   108,    40,   108,   108,    45,   108,
     108,   108,   108,   108,   108,   108,   108,   108,   108,   108,
     108,   108,   118,   108,   114,   115,    25,    41,   108,   108,
     108,   108,   108,   108,    25,   108,   108,   108,   108,   108,
     108,   108,   108,   108,   108,   108,   108,   108,   108,   108,
     108,    45,   108,    24,    91,    92,    25,    41,    96,   108,
      41,    41,    46,    89,    40,    44,   108,    44,    25,    41,
      41,    87,    90,    42,    44,    42,    81,    41,    42,    40,
      40,    73,    43,   115,    41,    42,    40,    43,    95,   100,
     100,   108,    41,   108,    44,    44,   108,    95,    45,    45,
      46,    90,   108,   108,    35,   111,   108,   114,   114,   118,
     108,    46,    45,    24,    91,    25,    42,    97,     6,    41,
     100,    41,    41,   108,    41,   108,    44,    41,    17,   102,
     102,    44,    44,   108,    41,    41,    81,    88,    41,   115,
      41,   100,   100,   100,    41,   100,    41,    41,   108,    45,
     103,   108,    46,    46,    46,    45,    45,   100,   100,   100,
      41,    15,    25,   116,   117,    19,    43,    88,    94,    98,
      99,   116,   100,    35,    35,    73,    46,   117,   108,    88,
      46,    44,    46,    94,    99,   108,   108,   118,    44,    12,
     102,    44,    44,    44,    81,    43,    35,    88,   108,    44
};

/* YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr1[] =
{
       0,    82,    83,    84,    84,    85,    85,    85,    86,    87,
      87,    88,    88,    89,    89,    89,    89,    89,    89,    89,
      89,    89,    89,    89,    89,    90,    90,    91,    91,    92,
      92,    93,    94,    94,    95,    95,    96,    96,    97,    97,
      98,    98,    98,    98,    99,    99,   100,   100,   101,   101,
     102,   102,   102,   103,   103,   104,   104,   105,   105,   106,
     106,   106,   106,   106,   106,   106,   106,   107,   108,   108,
     108,   108,   108,   108,   108,   108,   108,   108,   108,   108,
     108,   108,   108,   108,   108,   108,   108,   108,   108,   108,
     108,   108,   108,   108,   108,   108,   108,   108,   108,   108,
     108,   108,   108,   108,   108,   108,   109,   109,   110,   110,
     111,   111,   111,   111,   111,   111,   111,   111,   111,   111,
     111,   111,   112,   112,   112,   112,   112,   112,   112,   112,
     112,   113,   113,   113,   114,   114,   115,   115,   116,   116,
     117,   117,   117,   118,   118
};

/* YYR2[RULE-NUM] -- Number of symbols on the right-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     1,     0,     2,     1,     1,     1,     6,     1,
       2,     0,     2,     1,     1,     1,     1,     1,     2,     2,
       2,     3,     2,     4,     6,     8,    10,     0,     1,     1,
       3,    10,    10,     7,     0,     2,     0,     1,     0,     2,
       0,     1,     1,     2,     2,     3,     3,     1,     7,     7,
       4,     7,     5,     1,     3,     5,     7,     5,     6,     9,
       8,     8,     7,     8,     7,     7,     6,     1,     1,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     2,     2,
       1,     5,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     3,     2,     2,     1,     1,     1,
       1,     1,     1,     1,     1,     4,     3,     6,     1,     3,
       1,     1,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     1,     1,     3,     6,     2,     5,     2,     3,
       5,     4,     6,     6,     0,     1,     1,     3,     1,     2,
       4,     4,     7,     1,     3
};


enum { YYENOMEM = -2 };

#define yyerrok         (yyerrstatus = 0)
#define yyclearin       (yychar = CMDEMPTY)

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab
#define YYNOMEM         goto yyexhaustedlab


#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)                                    \
  do                                                              \
    if (yychar == CMDEMPTY)                                        \
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

/* Backward compatibility with an undocumented macro.
   Use CMDerror or CMDUNDEF. */
#define YYERRCODE CMDUNDEF


/* Enable debugging if requested.  */
#if CMDDEBUG

# ifndef YYFPRINTF
#  include <stdio.h> /* INFRINGES ON USER NAME SPACE */
#  define YYFPRINTF fprintf
# endif

# define YYDPRINTF(Args)                        \
do {                                            \
  if (yydebug)                                  \
    YYFPRINTF Args;                             \
} while (0)




# define YY_SYMBOL_PRINT(Title, Kind, Value, Location)                    \
do {                                                                      \
  if (yydebug)                                                            \
    {                                                                     \
      YYFPRINTF (stderr, "%s ", Title);                                   \
      yy_symbol_print (stderr,                                            \
                  Kind, Value); \
      YYFPRINTF (stderr, "\n");                                           \
    }                                                                     \
} while (0)


/*-----------------------------------.
| Print this symbol's value on YYO.  |
`-----------------------------------*/

static void
yy_symbol_value_print (FILE *yyo,
                       yysymbol_kind_t yykind, YYSTYPE const * const yyvaluep)
{
  FILE *yyoutput = yyo;
  YY_USE (yyoutput);
  if (!yyvaluep)
    return;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YY_USE (yykind);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}


/*---------------------------.
| Print this symbol on YYO.  |
`---------------------------*/

static void
yy_symbol_print (FILE *yyo,
                 yysymbol_kind_t yykind, YYSTYPE const * const yyvaluep)
{
  YYFPRINTF (yyo, "%s %s (",
             yykind < YYNTOKENS ? "token" : "nterm", yysymbol_name (yykind));

  yy_symbol_value_print (yyo, yykind, yyvaluep);
  YYFPRINTF (yyo, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

static void
yy_stack_print (yy_state_t *yybottom, yy_state_t *yytop)
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
yy_reduce_print (yy_state_t *yyssp, YYSTYPE *yyvsp,
                 int yyrule)
{
  int yylno = yyrline[yyrule];
  int yynrhs = yyr2[yyrule];
  int yyi;
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %d):\n",
             yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr,
                       YY_ACCESSING_SYMBOL (+yyssp[yyi + 1 - yynrhs]),
                       &yyvsp[(yyi + 1) - (yynrhs)]);
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
#else /* !CMDDEBUG */
# define YYDPRINTF(Args) ((void) 0)
# define YY_SYMBOL_PRINT(Title, Kind, Value, Location)
# define YY_STACK_PRINT(Bottom, Top)
# define YY_REDUCE_PRINT(Rule)
#endif /* !CMDDEBUG */


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






/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

static void
yydestruct (const char *yymsg,
            yysymbol_kind_t yykind, YYSTYPE *yyvaluep)
{
  YY_USE (yyvaluep);
  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yykind, yyvaluep, yylocationp);

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YY_USE (yykind);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}


/* Lookahead token kind.  */
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
    yy_state_fast_t yystate = 0;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus = 0;

    /* Refer to the stacks through separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* Their size.  */
    YYPTRDIFF_T yystacksize = YYINITDEPTH;

    /* The state stack: array, bottom, top.  */
    yy_state_t yyssa[YYINITDEPTH];
    yy_state_t *yyss = yyssa;
    yy_state_t *yyssp = yyss;

    /* The semantic value stack: array, bottom, top.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs = yyvsa;
    YYSTYPE *yyvsp = yyvs;

  int yyn;
  /* The return value of yyparse.  */
  int yyresult;
  /* Lookahead symbol kind.  */
  yysymbol_kind_t yytoken = YYSYMBOL_YYEMPTY;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;



#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yychar = CMDEMPTY; /* Cause a token to be read.  */

  goto yysetstate;


/*------------------------------------------------------------.
| yynewstate -- push a new state, which is found in yystate.  |
`------------------------------------------------------------*/
yynewstate:
  /* In all cases, when you get here, the value and location stacks
     have just been pushed.  So pushing a state here evens the stacks.  */
  yyssp++;


/*--------------------------------------------------------------------.
| yysetstate -- set current state (the top of the stack) to yystate.  |
`--------------------------------------------------------------------*/
yysetstate:
  YYDPRINTF ((stderr, "Entering state %d\n", yystate));
  YY_ASSERT (0 <= yystate && yystate < YYNSTATES);
  YY_IGNORE_USELESS_CAST_BEGIN
  *yyssp = YY_CAST (yy_state_t, yystate);
  YY_IGNORE_USELESS_CAST_END
  YY_STACK_PRINT (yyss, yyssp);

  if (yyss + yystacksize - 1 <= yyssp)
#if !defined yyoverflow && !defined YYSTACK_RELOCATE
    YYNOMEM;
#else
    {
      /* Get the current used size of the three stacks, in elements.  */
      YYPTRDIFF_T yysize = yyssp - yyss + 1;

# if defined yyoverflow
      {
        /* Give user a chance to reallocate the stack.  Use copies of
           these so that the &'s don't force the real ones into
           memory.  */
        yy_state_t *yyss1 = yyss;
        YYSTYPE *yyvs1 = yyvs;

        /* Each stack pointer address is followed by the size of the
           data in use in that stack, in bytes.  This used to be a
           conditional around just the two extra args, but that might
           be undefined if yyoverflow is a macro.  */
        yyoverflow (YY_("memory exhausted"),
                    &yyss1, yysize * YYSIZEOF (*yyssp),
                    &yyvs1, yysize * YYSIZEOF (*yyvsp),
                    &yystacksize);
        yyss = yyss1;
        yyvs = yyvs1;
      }
# else /* defined YYSTACK_RELOCATE */
      /* Extend the stack our own way.  */
      if (YYMAXDEPTH <= yystacksize)
        YYNOMEM;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
        yystacksize = YYMAXDEPTH;

      {
        yy_state_t *yyss1 = yyss;
        union yyalloc *yyptr =
          YY_CAST (union yyalloc *,
                   YYSTACK_ALLOC (YY_CAST (YYSIZE_T, YYSTACK_BYTES (yystacksize))));
        if (! yyptr)
          YYNOMEM;
        YYSTACK_RELOCATE (yyss_alloc, yyss);
        YYSTACK_RELOCATE (yyvs_alloc, yyvs);
#  undef YYSTACK_RELOCATE
        if (yyss1 != yyssa)
          YYSTACK_FREE (yyss1);
      }
# endif

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;

      YY_IGNORE_USELESS_CAST_BEGIN
      YYDPRINTF ((stderr, "Stack size increased to %ld\n",
                  YY_CAST (long, yystacksize)));
      YY_IGNORE_USELESS_CAST_END

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

  /* YYCHAR is either empty, or end-of-input, or a valid lookahead.  */
  if (yychar == CMDEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token\n"));
      yychar = yylex ();
    }

  if (yychar <= CMDEOF)
    {
      yychar = CMDEOF;
      yytoken = YYSYMBOL_YYEOF;
      YYDPRINTF ((stderr, "Now at end of input.\n"));
    }
  else if (yychar == CMDerror)
    {
      /* The scanner already issued an error message, process directly
         to error recovery.  But do not keep the error token as
         lookahead, it is too special and may lead us to an endless
         loop in error recovery. */
      yychar = CMDUNDEF;
      yytoken = YYSYMBOL_YYerror;
      goto yyerrlab1;
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
  yystate = yyn;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END

  /* Discard the shifted token.  */
  yychar = CMDEMPTY;
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
  case 2: /* start: decl_list  */
#line 149 "CMDgram.y"
      { }
#line 1821 "CMDgram.cc"
    break;

  case 3: /* decl_list: %empty  */
#line 154 "CMDgram.y"
      { (yyval.stmt) = nil; }
#line 1827 "CMDgram.cc"
    break;

  case 4: /* decl_list: decl_list decl  */
#line 156 "CMDgram.y"
      { if(!statementList) { statementList = (yyvsp[0].stmt); } else { statementList->append((yyvsp[0].stmt)); } }
#line 1833 "CMDgram.cc"
    break;

  case 5: /* decl: stmt  */
#line 161 "CMDgram.y"
      { (yyval.stmt) = (yyvsp[0].stmt); }
#line 1839 "CMDgram.cc"
    break;

  case 6: /* decl: fn_decl_stmt  */
#line 163 "CMDgram.y"
      { (yyval.stmt) = (yyvsp[0].stmt); }
#line 1845 "CMDgram.cc"
    break;

  case 7: /* decl: package_decl  */
#line 165 "CMDgram.y"
     { (yyval.stmt) = (yyvsp[0].stmt); }
#line 1851 "CMDgram.cc"
    break;

  case 8: /* package_decl: rwPACKAGE IDENT '{' fn_decl_list '}' ';'  */
#line 170 "CMDgram.y"
      { (yyval.stmt) = (yyvsp[-2].stmt); for(StmtNode *walk = ((yyvsp[-2].stmt));walk;walk = walk->getNext() ) walk->setPackage((yyvsp[-4].s)); }
#line 1857 "CMDgram.cc"
    break;

  case 9: /* fn_decl_list: fn_decl_stmt  */
#line 175 "CMDgram.y"
      { (yyval.stmt) = (yyvsp[0].stmt); }
#line 1863 "CMDgram.cc"
    break;

  case 10: /* fn_decl_list: fn_decl_list fn_decl_stmt  */
#line 177 "CMDgram.y"
      { (yyval.stmt) = (yyvsp[-1].stmt); ((yyvsp[-1].stmt))->append((yyvsp[0].stmt));  }
#line 1869 "CMDgram.cc"
    break;

  case 11: /* statement_list: %empty  */
#line 182 "CMDgram.y"
      { (yyval.stmt) = nil; }
#line 1875 "CMDgram.cc"
    break;

  case 12: /* statement_list: statement_list stmt  */
#line 184 "CMDgram.y"
      { if(!(yyvsp[-1].stmt)) { (yyval.stmt) = (yyvsp[0].stmt); } else { ((yyvsp[-1].stmt))->append((yyvsp[0].stmt)); (yyval.stmt) = (yyvsp[-1].stmt); } }
#line 1881 "CMDgram.cc"
    break;

  case 18: /* stmt: rwBREAK ';'  */
#line 194 "CMDgram.y"
      { (yyval.stmt) = BreakStmtNode::alloc(); }
#line 1887 "CMDgram.cc"
    break;

  case 19: /* stmt: rwCONTINUE ';'  */
#line 196 "CMDgram.y"
      { (yyval.stmt) = ContinueStmtNode::alloc(); }
#line 1893 "CMDgram.cc"
    break;

  case 20: /* stmt: rwRETURN ';'  */
#line 198 "CMDgram.y"
      { (yyval.stmt) = ReturnStmtNode::alloc(NULL); }
#line 1899 "CMDgram.cc"
    break;

  case 21: /* stmt: rwRETURN expr ';'  */
#line 200 "CMDgram.y"
      { (yyval.stmt) = ReturnStmtNode::alloc((yyvsp[-1].expr)); }
#line 1905 "CMDgram.cc"
    break;

  case 22: /* stmt: expression_stmt ';'  */
#line 202 "CMDgram.y"
      { (yyval.stmt) = (yyvsp[-1].stmt); }
#line 1911 "CMDgram.cc"
    break;

  case 23: /* stmt: TTAG '=' expr ';'  */
#line 204 "CMDgram.y"
      { (yyval.stmt) = TTagSetStmtNode::alloc((yyvsp[-3].s), (yyvsp[-1].expr), NULL); }
#line 1917 "CMDgram.cc"
    break;

  case 24: /* stmt: TTAG '=' expr ',' expr ';'  */
#line 206 "CMDgram.y"
      { (yyval.stmt) = TTagSetStmtNode::alloc((yyvsp[-5].s), (yyvsp[-3].expr), (yyvsp[-1].expr)); }
#line 1923 "CMDgram.cc"
    break;

  case 25: /* fn_decl_stmt: rwDEFINE IDENT '(' var_list_decl ')' '{' statement_list '}'  */
#line 211 "CMDgram.y"
      { (yyval.stmt) = FunctionDeclStmtNode::alloc((yyvsp[-6].s), NULL, (yyvsp[-4].var), (yyvsp[-1].stmt)); }
#line 1929 "CMDgram.cc"
    break;

  case 26: /* fn_decl_stmt: rwDEFINE IDENT opCOLONCOLON IDENT '(' var_list_decl ')' '{' statement_list '}'  */
#line 213 "CMDgram.y"
     { (yyval.stmt) = FunctionDeclStmtNode::alloc((yyvsp[-6].s), (yyvsp[-8].s), (yyvsp[-4].var), (yyvsp[-1].stmt)); }
#line 1935 "CMDgram.cc"
    break;

  case 27: /* var_list_decl: %empty  */
#line 218 "CMDgram.y"
     { (yyval.var) = NULL; }
#line 1941 "CMDgram.cc"
    break;

  case 28: /* var_list_decl: var_list  */
#line 220 "CMDgram.y"
     { (yyval.var) = (yyvsp[0].var); }
#line 1947 "CMDgram.cc"
    break;

  case 29: /* var_list: VAR  */
#line 225 "CMDgram.y"
      { (yyval.var) = VarNode::alloc((yyvsp[0].s), NULL); }
#line 1953 "CMDgram.cc"
    break;

  case 30: /* var_list: var_list ',' VAR  */
#line 227 "CMDgram.y"
      { (yyval.var) = (yyvsp[-2].var); ((StmtNode*)((yyvsp[-2].var)))->append((StmtNode*)VarNode::alloc((yyvsp[0].s), NULL)); }
#line 1959 "CMDgram.cc"
    break;

  case 31: /* datablock_decl: rwDATABLOCK IDENT '(' IDENT parent_block ')' '{' slot_assign_list '}' ';'  */
#line 232 "CMDgram.y"
      { (yyval.stmt) = ObjectDeclNode::alloc(ConstantNode::alloc((yyvsp[-8].s)), ConstantNode::alloc((yyvsp[-6].s)), NULL, (yyvsp[-5].s), (yyvsp[-2].slist), NULL, true); }
#line 1965 "CMDgram.cc"
    break;

  case 32: /* object_decl: rwDECLARE class_name_expr '(' object_name parent_block object_args ')' '{' object_declare_block '}'  */
#line 237 "CMDgram.y"
      { (yyval.od) = ObjectDeclNode::alloc((yyvsp[-8].expr), (yyvsp[-6].expr), (yyvsp[-4].expr), (yyvsp[-5].s), (yyvsp[-1].odcl).slots, (yyvsp[-1].odcl).decls, false); }
#line 1971 "CMDgram.cc"
    break;

  case 33: /* object_decl: rwDECLARE class_name_expr '(' object_name parent_block object_args ')'  */
#line 239 "CMDgram.y"
      { (yyval.od) = ObjectDeclNode::alloc((yyvsp[-5].expr), (yyvsp[-3].expr), (yyvsp[-1].expr), (yyvsp[-2].s), NULL, NULL, false); }
#line 1977 "CMDgram.cc"
    break;

  case 34: /* parent_block: %empty  */
#line 244 "CMDgram.y"
      { (yyval.s) = NULL; }
#line 1983 "CMDgram.cc"
    break;

  case 35: /* parent_block: ':' IDENT  */
#line 246 "CMDgram.y"
      { (yyval.s) = (yyvsp[0].s); }
#line 1989 "CMDgram.cc"
    break;

  case 36: /* object_name: %empty  */
#line 251 "CMDgram.y"
      { (yyval.expr) = StrConstNode::alloc("", false); }
#line 1995 "CMDgram.cc"
    break;

  case 37: /* object_name: expr  */
#line 253 "CMDgram.y"
      { (yyval.expr) = (yyvsp[0].expr); }
#line 2001 "CMDgram.cc"
    break;

  case 38: /* object_args: %empty  */
#line 258 "CMDgram.y"
      { (yyval.expr) = NULL; }
#line 2007 "CMDgram.cc"
    break;

  case 39: /* object_args: ',' expr_list  */
#line 260 "CMDgram.y"
      { (yyval.expr) = (yyvsp[0].expr); }
#line 2013 "CMDgram.cc"
    break;

  case 40: /* object_declare_block: %empty  */
#line 265 "CMDgram.y"
      { (yyval.odcl).slots = NULL; (yyval.odcl).decls = NULL; }
#line 2019 "CMDgram.cc"
    break;

  case 41: /* object_declare_block: slot_assign_list  */
#line 267 "CMDgram.y"
      { (yyval.odcl).slots = (yyvsp[0].slist); (yyval.odcl).decls = NULL; }
#line 2025 "CMDgram.cc"
    break;

  case 42: /* object_declare_block: object_decl_list  */
#line 269 "CMDgram.y"
      { (yyval.odcl).slots = NULL; (yyval.odcl).decls = (yyvsp[0].od); }
#line 2031 "CMDgram.cc"
    break;

  case 43: /* object_declare_block: slot_assign_list object_decl_list  */
#line 271 "CMDgram.y"
      { (yyval.odcl).slots = (yyvsp[-1].slist); (yyval.odcl).decls = (yyvsp[0].od); }
#line 2037 "CMDgram.cc"
    break;

  case 44: /* object_decl_list: object_decl ';'  */
#line 276 "CMDgram.y"
      { (yyval.od) = (yyvsp[-1].od); }
#line 2043 "CMDgram.cc"
    break;

  case 45: /* object_decl_list: object_decl_list object_decl ';'  */
#line 278 "CMDgram.y"
      { (yyvsp[-2].od)->append((yyvsp[-1].od)); (yyval.od) = (yyvsp[-2].od); }
#line 2049 "CMDgram.cc"
    break;

  case 46: /* stmt_block: '{' statement_list '}'  */
#line 283 "CMDgram.y"
      { (yyval.stmt) = (yyvsp[-1].stmt); }
#line 2055 "CMDgram.cc"
    break;

  case 47: /* stmt_block: stmt  */
#line 285 "CMDgram.y"
      { (yyval.stmt) = (yyvsp[0].stmt); }
#line 2061 "CMDgram.cc"
    break;

  case 48: /* switch_stmt: rwSWITCH '(' expr ')' '{' case_block '}'  */
#line 290 "CMDgram.y"
      { (yyval.stmt) = (yyvsp[-1].ifnode); (yyvsp[-1].ifnode)->propagateSwitchExpr((yyvsp[-4].expr), false); }
#line 2067 "CMDgram.cc"
    break;

  case 49: /* switch_stmt: rwSWITCHSTR '(' expr ')' '{' case_block '}'  */
#line 292 "CMDgram.y"
      { (yyval.stmt) = (yyvsp[-1].ifnode); (yyvsp[-1].ifnode)->propagateSwitchExpr((yyvsp[-4].expr), true); }
#line 2073 "CMDgram.cc"
    break;

  case 50: /* case_block: rwCASE case_expr ':' statement_list  */
#line 297 "CMDgram.y"
      { (yyval.ifnode) = IfStmtNode::alloc((yyvsp[-3].i), (yyvsp[-2].expr), (yyvsp[0].stmt), NULL, false); }
#line 2079 "CMDgram.cc"
    break;

  case 51: /* case_block: rwCASE case_expr ':' statement_list rwDEFAULT ':' statement_list  */
#line 299 "CMDgram.y"
      { (yyval.ifnode) = IfStmtNode::alloc((yyvsp[-6].i), (yyvsp[-5].expr), (yyvsp[-3].stmt), (yyvsp[0].stmt), false); }
#line 2085 "CMDgram.cc"
    break;

  case 52: /* case_block: rwCASE case_expr ':' statement_list case_block  */
#line 301 "CMDgram.y"
      { (yyval.ifnode) = IfStmtNode::alloc((yyvsp[-4].i), (yyvsp[-3].expr), (yyvsp[-1].stmt), (yyvsp[0].ifnode), true); }
#line 2091 "CMDgram.cc"
    break;

  case 53: /* case_expr: expr  */
#line 306 "CMDgram.y"
      { (yyval.expr) = (yyvsp[0].expr);}
#line 2097 "CMDgram.cc"
    break;

  case 54: /* case_expr: case_expr rwCASEOR expr  */
#line 308 "CMDgram.y"
      { ((yyvsp[-2].expr))->append((yyvsp[0].expr)); (yyval.expr)=(yyvsp[-2].expr); }
#line 2103 "CMDgram.cc"
    break;

  case 55: /* if_stmt: rwIF '(' expr ')' stmt_block  */
#line 313 "CMDgram.y"
      { (yyval.stmt) = IfStmtNode::alloc((yyvsp[-4].i), (yyvsp[-2].expr), (yyvsp[0].stmt), NULL, false); }
#line 2109 "CMDgram.cc"
    break;

  case 56: /* if_stmt: rwIF '(' expr ')' stmt_block rwELSE stmt_block  */
#line 315 "CMDgram.y"
      { (yyval.stmt) = IfStmtNode::alloc((yyvsp[-6].i), (yyvsp[-4].expr), (yyvsp[-2].stmt), (yyvsp[0].stmt), false); }
#line 2115 "CMDgram.cc"
    break;

  case 57: /* while_stmt: rwWHILE '(' expr ')' stmt_block  */
#line 320 "CMDgram.y"
      { (yyval.stmt) = LoopStmtNode::alloc((yyvsp[-4].i), nil, (yyvsp[-2].expr), nil, (yyvsp[0].stmt), false); }
#line 2121 "CMDgram.cc"
    break;

  case 58: /* while_stmt: rwDO stmt_block rwWHILE '(' expr ')'  */
#line 322 "CMDgram.y"
      { (yyval.stmt) = LoopStmtNode::alloc((yyvsp[-3].i), nil, (yyvsp[-1].expr), nil, (yyvsp[-4].stmt), true); }
#line 2127 "CMDgram.cc"
    break;

  case 59: /* for_stmt: rwFOR '(' expr ';' expr ';' expr ')' stmt_block  */
#line 327 "CMDgram.y"
      { (yyval.stmt) = LoopStmtNode::alloc((yyvsp[-8].i), (yyvsp[-6].expr), (yyvsp[-4].expr), (yyvsp[-2].expr), (yyvsp[0].stmt), false); }
#line 2133 "CMDgram.cc"
    break;

  case 60: /* for_stmt: rwFOR '(' expr ';' expr ';' ')' stmt_block  */
#line 329 "CMDgram.y"
      { (yyval.stmt) = LoopStmtNode::alloc((yyvsp[-7].i), (yyvsp[-5].expr), (yyvsp[-3].expr), NULL, (yyvsp[0].stmt), false); }
#line 2139 "CMDgram.cc"
    break;

  case 61: /* for_stmt: rwFOR '(' expr ';' ';' expr ')' stmt_block  */
#line 331 "CMDgram.y"
      { (yyval.stmt) = LoopStmtNode::alloc((yyvsp[-7].i), (yyvsp[-5].expr), NULL, (yyvsp[-2].expr), (yyvsp[0].stmt), false); }
#line 2145 "CMDgram.cc"
    break;

  case 62: /* for_stmt: rwFOR '(' expr ';' ';' ')' stmt_block  */
#line 333 "CMDgram.y"
      { (yyval.stmt) = LoopStmtNode::alloc((yyvsp[-6].i), (yyvsp[-4].expr), NULL, NULL, (yyvsp[0].stmt), false); }
#line 2151 "CMDgram.cc"
    break;

  case 63: /* for_stmt: rwFOR '(' ';' expr ';' expr ')' stmt_block  */
#line 335 "CMDgram.y"
      { (yyval.stmt) = LoopStmtNode::alloc((yyvsp[-7].i), NULL, (yyvsp[-4].expr), (yyvsp[-2].expr), (yyvsp[0].stmt), false); }
#line 2157 "CMDgram.cc"
    break;

  case 64: /* for_stmt: rwFOR '(' ';' expr ';' ')' stmt_block  */
#line 337 "CMDgram.y"
      { (yyval.stmt) = LoopStmtNode::alloc((yyvsp[-6].i), NULL, (yyvsp[-3].expr), NULL, (yyvsp[0].stmt), false); }
#line 2163 "CMDgram.cc"
    break;

  case 65: /* for_stmt: rwFOR '(' ';' ';' expr ')' stmt_block  */
#line 339 "CMDgram.y"
      { (yyval.stmt) = LoopStmtNode::alloc((yyvsp[-6].i), NULL, NULL, (yyvsp[-2].expr), (yyvsp[0].stmt), false); }
#line 2169 "CMDgram.cc"
    break;

  case 66: /* for_stmt: rwFOR '(' ';' ';' ')' stmt_block  */
#line 341 "CMDgram.y"
      { (yyval.stmt) = LoopStmtNode::alloc((yyvsp[-5].i), NULL, NULL, NULL, (yyvsp[0].stmt), false); }
#line 2175 "CMDgram.cc"
    break;

  case 67: /* expression_stmt: stmt_expr  */
#line 346 "CMDgram.y"
      { (yyval.stmt) = (yyvsp[0].expr); }
#line 2181 "CMDgram.cc"
    break;

  case 68: /* expr: stmt_expr  */
#line 351 "CMDgram.y"
      { (yyval.expr) = (yyvsp[0].expr); }
#line 2187 "CMDgram.cc"
    break;

  case 69: /* expr: '(' expr ')'  */
#line 353 "CMDgram.y"
      { (yyval.expr) = (yyvsp[-1].expr); }
#line 2193 "CMDgram.cc"
    break;

  case 70: /* expr: expr '^' expr  */
#line 355 "CMDgram.y"
      { (yyval.expr) = IntBinaryExprNode::alloc((yyvsp[-1].i), (yyvsp[-2].expr), (yyvsp[0].expr)); }
#line 2199 "CMDgram.cc"
    break;

  case 71: /* expr: expr '%' expr  */
#line 357 "CMDgram.y"
      { (yyval.expr) = IntBinaryExprNode::alloc((yyvsp[-1].i), (yyvsp[-2].expr), (yyvsp[0].expr)); }
#line 2205 "CMDgram.cc"
    break;

  case 72: /* expr: expr '&' expr  */
#line 359 "CMDgram.y"
      { (yyval.expr) = IntBinaryExprNode::alloc((yyvsp[-1].i), (yyvsp[-2].expr), (yyvsp[0].expr)); }
#line 2211 "CMDgram.cc"
    break;

  case 73: /* expr: expr '|' expr  */
#line 361 "CMDgram.y"
      { (yyval.expr) = IntBinaryExprNode::alloc((yyvsp[-1].i), (yyvsp[-2].expr), (yyvsp[0].expr)); }
#line 2217 "CMDgram.cc"
    break;

  case 74: /* expr: expr '+' expr  */
#line 363 "CMDgram.y"
      { (yyval.expr) = FloatBinaryExprNode::alloc((yyvsp[-1].i), (yyvsp[-2].expr), (yyvsp[0].expr)); }
#line 2223 "CMDgram.cc"
    break;

  case 75: /* expr: expr '-' expr  */
#line 365 "CMDgram.y"
      { (yyval.expr) = FloatBinaryExprNode::alloc((yyvsp[-1].i), (yyvsp[-2].expr), (yyvsp[0].expr)); }
#line 2229 "CMDgram.cc"
    break;

  case 76: /* expr: expr '*' expr  */
#line 367 "CMDgram.y"
      { (yyval.expr) = FloatBinaryExprNode::alloc((yyvsp[-1].i), (yyvsp[-2].expr), (yyvsp[0].expr)); }
#line 2235 "CMDgram.cc"
    break;

  case 77: /* expr: expr '/' expr  */
#line 369 "CMDgram.y"
      { (yyval.expr) = FloatBinaryExprNode::alloc((yyvsp[-1].i), (yyvsp[-2].expr), (yyvsp[0].expr)); }
#line 2241 "CMDgram.cc"
    break;

  case 78: /* expr: '-' expr  */
#line 371 "CMDgram.y"
      { (yyval.expr) = FloatUnaryExprNode::alloc((yyvsp[-1].i), (yyvsp[0].expr)); }
#line 2247 "CMDgram.cc"
    break;

  case 79: /* expr: '*' expr  */
#line 373 "CMDgram.y"
      { (yyval.expr) = TTagDerefNode::alloc((yyvsp[0].expr)); }
#line 2253 "CMDgram.cc"
    break;

  case 80: /* expr: TTAG  */
#line 375 "CMDgram.y"
      { (yyval.expr) = TTagExprNode::alloc((yyvsp[0].s)); }
#line 2259 "CMDgram.cc"
    break;

  case 81: /* expr: expr '?' expr ':' expr  */
#line 377 "CMDgram.y"
      { (yyval.expr) = ConditionalExprNode::alloc((yyvsp[-4].expr), (yyvsp[-2].expr), (yyvsp[0].expr)); }
#line 2265 "CMDgram.cc"
    break;

  case 82: /* expr: expr '<' expr  */
#line 379 "CMDgram.y"
      { (yyval.expr) = IntBinaryExprNode::alloc((yyvsp[-1].i), (yyvsp[-2].expr), (yyvsp[0].expr)); }
#line 2271 "CMDgram.cc"
    break;

  case 83: /* expr: expr '>' expr  */
#line 381 "CMDgram.y"
      { (yyval.expr) = IntBinaryExprNode::alloc((yyvsp[-1].i), (yyvsp[-2].expr), (yyvsp[0].expr)); }
#line 2277 "CMDgram.cc"
    break;

  case 84: /* expr: expr opGE expr  */
#line 383 "CMDgram.y"
      { (yyval.expr) = IntBinaryExprNode::alloc((yyvsp[-1].i), (yyvsp[-2].expr), (yyvsp[0].expr)); }
#line 2283 "CMDgram.cc"
    break;

  case 85: /* expr: expr opLE expr  */
#line 385 "CMDgram.y"
      { (yyval.expr) = IntBinaryExprNode::alloc((yyvsp[-1].i), (yyvsp[-2].expr), (yyvsp[0].expr)); }
#line 2289 "CMDgram.cc"
    break;

  case 86: /* expr: expr opEQ expr  */
#line 387 "CMDgram.y"
      { (yyval.expr) = IntBinaryExprNode::alloc((yyvsp[-1].i), (yyvsp[-2].expr), (yyvsp[0].expr)); }
#line 2295 "CMDgram.cc"
    break;

  case 87: /* expr: expr opNE expr  */
#line 389 "CMDgram.y"
      { (yyval.expr) = IntBinaryExprNode::alloc((yyvsp[-1].i), (yyvsp[-2].expr), (yyvsp[0].expr)); }
#line 2301 "CMDgram.cc"
    break;

  case 88: /* expr: expr opOR expr  */
#line 391 "CMDgram.y"
      { (yyval.expr) = IntBinaryExprNode::alloc((yyvsp[-1].i), (yyvsp[-2].expr), (yyvsp[0].expr)); }
#line 2307 "CMDgram.cc"
    break;

  case 89: /* expr: expr opSHL expr  */
#line 393 "CMDgram.y"
      { (yyval.expr) = IntBinaryExprNode::alloc((yyvsp[-1].i), (yyvsp[-2].expr), (yyvsp[0].expr)); }
#line 2313 "CMDgram.cc"
    break;

  case 90: /* expr: expr opSHR expr  */
#line 395 "CMDgram.y"
      { (yyval.expr) = IntBinaryExprNode::alloc((yyvsp[-1].i), (yyvsp[-2].expr), (yyvsp[0].expr)); }
#line 2319 "CMDgram.cc"
    break;

  case 91: /* expr: expr opAND expr  */
#line 397 "CMDgram.y"
      { (yyval.expr) = IntBinaryExprNode::alloc((yyvsp[-1].i), (yyvsp[-2].expr), (yyvsp[0].expr)); }
#line 2325 "CMDgram.cc"
    break;

  case 92: /* expr: expr opSTREQ expr  */
#line 399 "CMDgram.y"
      { (yyval.expr) = StreqExprNode::alloc((yyvsp[-2].expr), (yyvsp[0].expr), true); }
#line 2331 "CMDgram.cc"
    break;

  case 93: /* expr: expr opSTRNE expr  */
#line 401 "CMDgram.y"
      { (yyval.expr) = StreqExprNode::alloc((yyvsp[-2].expr), (yyvsp[0].expr), false); }
#line 2337 "CMDgram.cc"
    break;

  case 94: /* expr: expr '@' expr  */
#line 403 "CMDgram.y"
      { (yyval.expr) = StrcatExprNode::alloc((yyvsp[-2].expr), (yyvsp[0].expr), (yyvsp[-1].i)); }
#line 2343 "CMDgram.cc"
    break;

  case 95: /* expr: '!' expr  */
#line 405 "CMDgram.y"
      { (yyval.expr) = IntUnaryExprNode::alloc((yyvsp[-1].i), (yyvsp[0].expr)); }
#line 2349 "CMDgram.cc"
    break;

  case 96: /* expr: '~' expr  */
#line 407 "CMDgram.y"
      { (yyval.expr) = IntUnaryExprNode::alloc((yyvsp[-1].i), (yyvsp[0].expr)); }
#line 2355 "CMDgram.cc"
    break;

  case 97: /* expr: TAGATOM  */
#line 409 "CMDgram.y"
      { (yyval.expr) = StrConstNode::alloc((yyvsp[0].str), true); }
#line 2361 "CMDgram.cc"
    break;

  case 98: /* expr: FLTCONST  */
#line 411 "CMDgram.y"
      { (yyval.expr) = FloatNode::alloc((yyvsp[0].f)); }
#line 2367 "CMDgram.cc"
    break;

  case 99: /* expr: INTCONST  */
#line 413 "CMDgram.y"
      { (yyval.expr) = IntNode::alloc((yyvsp[0].i)); }
#line 2373 "CMDgram.cc"
    break;

  case 100: /* expr: rwBREAK  */
#line 415 "CMDgram.y"
      { (yyval.expr) = ConstantNode::alloc(StringTable->insert("break")); }
#line 2379 "CMDgram.cc"
    break;

  case 101: /* expr: slot_acc  */
#line 417 "CMDgram.y"
      { (yyval.expr) = SlotAccessNode::alloc((yyvsp[0].slot).object, (yyvsp[0].slot).array, (yyvsp[0].slot).slotName); }
#line 2385 "CMDgram.cc"
    break;

  case 102: /* expr: IDENT  */
#line 419 "CMDgram.y"
      { (yyval.expr) = ConstantNode::alloc((yyvsp[0].s)); }
#line 2391 "CMDgram.cc"
    break;

  case 103: /* expr: STRATOM  */
#line 421 "CMDgram.y"
      { (yyval.expr) = StrConstNode::alloc((yyvsp[0].str), false); }
#line 2397 "CMDgram.cc"
    break;

  case 104: /* expr: VAR  */
#line 423 "CMDgram.y"
      { (yyval.expr) = (ExprNode*)VarNode::alloc((yyvsp[0].s), NULL); }
#line 2403 "CMDgram.cc"
    break;

  case 105: /* expr: VAR '[' aidx_expr ']'  */
#line 425 "CMDgram.y"
      { (yyval.expr) = (ExprNode*)VarNode::alloc((yyvsp[-3].s), (yyvsp[-1].expr)); }
#line 2409 "CMDgram.cc"
    break;

  case 106: /* slot_acc: expr '.' IDENT  */
#line 430 "CMDgram.y"
      { (yyval.slot).object = (yyvsp[-2].expr); (yyval.slot).slotName = (yyvsp[0].s); (yyval.slot).array = NULL; }
#line 2415 "CMDgram.cc"
    break;

  case 107: /* slot_acc: expr '.' IDENT '[' aidx_expr ']'  */
#line 432 "CMDgram.y"
      { (yyval.slot).object = (yyvsp[-5].expr); (yyval.slot).slotName = (yyvsp[-3].s); (yyval.slot).array = (yyvsp[-1].expr); }
#line 2421 "CMDgram.cc"
    break;

  case 108: /* class_name_expr: IDENT  */
#line 437 "CMDgram.y"
      { (yyval.expr) = ConstantNode::alloc((yyvsp[0].s)); }
#line 2427 "CMDgram.cc"
    break;

  case 109: /* class_name_expr: '(' expr ')'  */
#line 439 "CMDgram.y"
      { (yyval.expr) = (yyvsp[-1].expr); }
#line 2433 "CMDgram.cc"
    break;

  case 110: /* assign_op_struct: opPLUSPLUS  */
#line 444 "CMDgram.y"
      { (yyval.asn).token = '+'; (yyval.asn).expr = FloatNode::alloc(1); }
#line 2439 "CMDgram.cc"
    break;

  case 111: /* assign_op_struct: opMINUSMINUS  */
#line 446 "CMDgram.y"
      { (yyval.asn).token = '-'; (yyval.asn).expr = FloatNode::alloc(1); }
#line 2445 "CMDgram.cc"
    break;

  case 112: /* assign_op_struct: opPLASN expr  */
#line 448 "CMDgram.y"
      { (yyval.asn).token = '+'; (yyval.asn).expr = (yyvsp[0].expr); }
#line 2451 "CMDgram.cc"
    break;

  case 113: /* assign_op_struct: opMIASN expr  */
#line 450 "CMDgram.y"
      { (yyval.asn).token = '-'; (yyval.asn).expr = (yyvsp[0].expr); }
#line 2457 "CMDgram.cc"
    break;

  case 114: /* assign_op_struct: opMLASN expr  */
#line 452 "CMDgram.y"
      { (yyval.asn).token = '*'; (yyval.asn).expr = (yyvsp[0].expr); }
#line 2463 "CMDgram.cc"
    break;

  case 115: /* assign_op_struct: opDVASN expr  */
#line 454 "CMDgram.y"
      { (yyval.asn).token = '/'; (yyval.asn).expr = (yyvsp[0].expr); }
#line 2469 "CMDgram.cc"
    break;

  case 116: /* assign_op_struct: opMODASN expr  */
#line 456 "CMDgram.y"
      { (yyval.asn).token = '%'; (yyval.asn).expr = (yyvsp[0].expr); }
#line 2475 "CMDgram.cc"
    break;

  case 117: /* assign_op_struct: opANDASN expr  */
#line 458 "CMDgram.y"
      { (yyval.asn).token = '&'; (yyval.asn).expr = (yyvsp[0].expr); }
#line 2481 "CMDgram.cc"
    break;

  case 118: /* assign_op_struct: opXORASN expr  */
#line 460 "CMDgram.y"
      { (yyval.asn).token = '^'; (yyval.asn).expr = (yyvsp[0].expr); }
#line 2487 "CMDgram.cc"
    break;

  case 119: /* assign_op_struct: opORASN expr  */
#line 462 "CMDgram.y"
      { (yyval.asn).token = '|'; (yyval.asn).expr = (yyvsp[0].expr); }
#line 2493 "CMDgram.cc"
    break;

  case 120: /* assign_op_struct: opSLASN expr  */
#line 464 "CMDgram.y"
      { (yyval.asn).token = opSHL; (yyval.asn).expr = (yyvsp[0].expr); }
#line 2499 "CMDgram.cc"
    break;

  case 121: /* assign_op_struct: opSRASN expr  */
#line 466 "CMDgram.y"
      { (yyval.asn).token = opSHR; (yyval.asn).expr = (yyvsp[0].expr); }
#line 2505 "CMDgram.cc"
    break;

  case 122: /* stmt_expr: funcall_expr  */
#line 471 "CMDgram.y"
      { (yyval.expr) = (yyvsp[0].expr); }
#line 2511 "CMDgram.cc"
    break;

  case 123: /* stmt_expr: object_decl  */
#line 473 "CMDgram.y"
      { (yyval.expr) = (yyvsp[0].od); }
#line 2517 "CMDgram.cc"
    break;

  case 124: /* stmt_expr: VAR '=' expr  */
#line 475 "CMDgram.y"
      { (yyval.expr) = AssignExprNode::alloc((yyvsp[-2].s), NULL, (yyvsp[0].expr)); }
#line 2523 "CMDgram.cc"
    break;

  case 125: /* stmt_expr: VAR '[' aidx_expr ']' '=' expr  */
#line 477 "CMDgram.y"
      { (yyval.expr) = AssignExprNode::alloc((yyvsp[-5].s), (yyvsp[-3].expr), (yyvsp[0].expr)); }
#line 2529 "CMDgram.cc"
    break;

  case 126: /* stmt_expr: VAR assign_op_struct  */
#line 479 "CMDgram.y"
      { (yyval.expr) = AssignOpExprNode::alloc((yyvsp[-1].s), NULL, (yyvsp[0].asn).expr, (yyvsp[0].asn).token); }
#line 2535 "CMDgram.cc"
    break;

  case 127: /* stmt_expr: VAR '[' aidx_expr ']' assign_op_struct  */
#line 481 "CMDgram.y"
      { (yyval.expr) = AssignOpExprNode::alloc((yyvsp[-4].s), (yyvsp[-2].expr), (yyvsp[0].asn).expr, (yyvsp[0].asn).token); }
#line 2541 "CMDgram.cc"
    break;

  case 128: /* stmt_expr: slot_acc assign_op_struct  */
#line 483 "CMDgram.y"
      { (yyval.expr) = SlotAssignOpNode::alloc((yyvsp[-1].slot).object, (yyvsp[-1].slot).slotName, (yyvsp[-1].slot).array, (yyvsp[0].asn).token, (yyvsp[0].asn).expr); }
#line 2547 "CMDgram.cc"
    break;

  case 129: /* stmt_expr: slot_acc '=' expr  */
#line 485 "CMDgram.y"
      { (yyval.expr) = SlotAssignNode::alloc((yyvsp[-2].slot).object, (yyvsp[-2].slot).array, (yyvsp[-2].slot).slotName, (yyvsp[0].expr)); }
#line 2553 "CMDgram.cc"
    break;

  case 130: /* stmt_expr: slot_acc '=' '{' expr_list '}'  */
#line 487 "CMDgram.y"
      { (yyval.expr) = SlotAssignNode::alloc((yyvsp[-4].slot).object, (yyvsp[-4].slot).array, (yyvsp[-4].slot).slotName, (yyvsp[-1].expr)); }
#line 2559 "CMDgram.cc"
    break;

  case 131: /* funcall_expr: IDENT '(' expr_list_decl ')'  */
#line 492 "CMDgram.y"
     { (yyval.expr) = FuncCallExprNode::alloc((yyvsp[-3].s), NULL, (yyvsp[-1].expr), false); }
#line 2565 "CMDgram.cc"
    break;

  case 132: /* funcall_expr: IDENT opCOLONCOLON IDENT '(' expr_list_decl ')'  */
#line 494 "CMDgram.y"
     { (yyval.expr) = FuncCallExprNode::alloc((yyvsp[-3].s), (yyvsp[-5].s), (yyvsp[-1].expr), false); }
#line 2571 "CMDgram.cc"
    break;

  case 133: /* funcall_expr: expr '.' IDENT '(' expr_list_decl ')'  */
#line 496 "CMDgram.y"
      { (yyvsp[-5].expr)->append((yyvsp[-1].expr)); (yyval.expr) = FuncCallExprNode::alloc((yyvsp[-3].s), NULL, (yyvsp[-5].expr), true); }
#line 2577 "CMDgram.cc"
    break;

  case 134: /* expr_list_decl: %empty  */
#line 501 "CMDgram.y"
      { (yyval.expr) = NULL; }
#line 2583 "CMDgram.cc"
    break;

  case 135: /* expr_list_decl: expr_list  */
#line 503 "CMDgram.y"
      { (yyval.expr) = (yyvsp[0].expr); }
#line 2589 "CMDgram.cc"
    break;

  case 136: /* expr_list: expr  */
#line 508 "CMDgram.y"
      { (yyval.expr) = (yyvsp[0].expr); }
#line 2595 "CMDgram.cc"
    break;

  case 137: /* expr_list: expr_list ',' expr  */
#line 510 "CMDgram.y"
      { ((yyvsp[-2].expr))->append((yyvsp[0].expr)); (yyval.expr) = (yyvsp[-2].expr); }
#line 2601 "CMDgram.cc"
    break;

  case 138: /* slot_assign_list: slot_assign  */
#line 515 "CMDgram.y"
      { (yyval.slist) = (yyvsp[0].slist); }
#line 2607 "CMDgram.cc"
    break;

  case 139: /* slot_assign_list: slot_assign_list slot_assign  */
#line 517 "CMDgram.y"
      { (yyvsp[-1].slist)->append((yyvsp[0].slist)); (yyval.slist) = (yyvsp[-1].slist); }
#line 2613 "CMDgram.cc"
    break;

  case 140: /* slot_assign: IDENT '=' expr ';'  */
#line 522 "CMDgram.y"
      { (yyval.slist) = SlotAssignNode::alloc(NULL, NULL, (yyvsp[-3].s), (yyvsp[-1].expr)); }
#line 2619 "CMDgram.cc"
    break;

  case 141: /* slot_assign: rwDATABLOCK '=' expr ';'  */
#line 524 "CMDgram.y"
      { (yyval.slist) = SlotAssignNode::alloc(NULL, NULL, StringTable->insert("datablock"), (yyvsp[-1].expr)); }
#line 2625 "CMDgram.cc"
    break;

  case 142: /* slot_assign: IDENT '[' aidx_expr ']' '=' expr ';'  */
#line 526 "CMDgram.y"
      { (yyval.slist) = SlotAssignNode::alloc(NULL, (yyvsp[-4].expr), (yyvsp[-6].s), (yyvsp[-1].expr)); }
#line 2631 "CMDgram.cc"
    break;

  case 143: /* aidx_expr: expr  */
#line 531 "CMDgram.y"
      { (yyval.expr) = (yyvsp[0].expr); }
#line 2637 "CMDgram.cc"
    break;

  case 144: /* aidx_expr: aidx_expr ',' expr  */
#line 533 "CMDgram.y"
      { (yyval.expr) = CommaCatExprNode::alloc((yyvsp[-2].expr), (yyvsp[0].expr)); }
#line 2643 "CMDgram.cc"
    break;


#line 2647 "CMDgram.cc"

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
  YY_SYMBOL_PRINT ("-> $$ =", YY_CAST (yysymbol_kind_t, yyr1[yyn]), &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;

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
  yytoken = yychar == CMDEMPTY ? YYSYMBOL_YYEMPTY : YYTRANSLATE (yychar);
  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
      yyerror (YY_("syntax error"));
    }

  if (yyerrstatus == 3)
    {
      /* If just tried and failed to reuse lookahead token after an
         error, discard it.  */

      if (yychar <= CMDEOF)
        {
          /* Return failure if at end of input.  */
          if (yychar == CMDEOF)
            YYABORT;
        }
      else
        {
          yydestruct ("Error: discarding",
                      yytoken, &yylval);
          yychar = CMDEMPTY;
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
  ++yynerrs;

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

  /* Pop stack until we find a state that shifts the error token.  */
  for (;;)
    {
      yyn = yypact[yystate];
      if (!yypact_value_is_default (yyn))
        {
          yyn += YYSYMBOL_YYerror;
          if (0 <= yyn && yyn <= YYLAST && yycheck[yyn] == YYSYMBOL_YYerror)
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
                  YY_ACCESSING_SYMBOL (yystate), yyvsp);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END


  /* Shift the error token.  */
  YY_SYMBOL_PRINT ("Shifting", YY_ACCESSING_SYMBOL (yyn), yyvsp, yylsp);

  yystate = yyn;
  goto yynewstate;


/*-------------------------------------.
| yyacceptlab -- YYACCEPT comes here.  |
`-------------------------------------*/
yyacceptlab:
  yyresult = 0;
  goto yyreturnlab;


/*-----------------------------------.
| yyabortlab -- YYABORT comes here.  |
`-----------------------------------*/
yyabortlab:
  yyresult = 1;
  goto yyreturnlab;


/*-----------------------------------------------------------.
| yyexhaustedlab -- YYNOMEM (memory exhaustion) comes here.  |
`-----------------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  goto yyreturnlab;


/*----------------------------------------------------------.
| yyreturnlab -- parsing is finished, clean up and return.  |
`----------------------------------------------------------*/
yyreturnlab:
  if (yychar != CMDEMPTY)
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
                  YY_ACCESSING_SYMBOL (+*yyssp), yyvsp);
      YYPOPSTACK (1);
    }
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif

  return yyresult;
}

#line 535 "CMDgram.y"


