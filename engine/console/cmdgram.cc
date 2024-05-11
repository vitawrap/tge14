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
  YYSYMBOL_opINSTANCE = 80,                /* opINSTANCE  */
  YYSYMBOL_UNARY = 81,                     /* UNARY  */
  YYSYMBOL_82_ = 82,                       /* ']'  */
  YYSYMBOL_YYACCEPT = 83,                  /* $accept  */
  YYSYMBOL_start = 84,                     /* start  */
  YYSYMBOL_decl_list = 85,                 /* decl_list  */
  YYSYMBOL_decl = 86,                      /* decl  */
  YYSYMBOL_package_decl = 87,              /* package_decl  */
  YYSYMBOL_fn_decl_list = 88,              /* fn_decl_list  */
  YYSYMBOL_statement_list = 89,            /* statement_list  */
  YYSYMBOL_stmt = 90,                      /* stmt  */
  YYSYMBOL_fn_decl_stmt = 91,              /* fn_decl_stmt  */
  YYSYMBOL_var_list_decl = 92,             /* var_list_decl  */
  YYSYMBOL_var_list = 93,                  /* var_list  */
  YYSYMBOL_datablock_decl = 94,            /* datablock_decl  */
  YYSYMBOL_object_decl = 95,               /* object_decl  */
  YYSYMBOL_parent_block = 96,              /* parent_block  */
  YYSYMBOL_object_name = 97,               /* object_name  */
  YYSYMBOL_object_args = 98,               /* object_args  */
  YYSYMBOL_object_declare_block = 99,      /* object_declare_block  */
  YYSYMBOL_object_decl_list = 100,         /* object_decl_list  */
  YYSYMBOL_stmt_block = 101,               /* stmt_block  */
  YYSYMBOL_switch_stmt = 102,              /* switch_stmt  */
  YYSYMBOL_case_block = 103,               /* case_block  */
  YYSYMBOL_case_expr = 104,                /* case_expr  */
  YYSYMBOL_if_stmt = 105,                  /* if_stmt  */
  YYSYMBOL_while_stmt = 106,               /* while_stmt  */
  YYSYMBOL_for_stmt = 107,                 /* for_stmt  */
  YYSYMBOL_expression_stmt = 108,          /* expression_stmt  */
  YYSYMBOL_expr = 109,                     /* expr  */
  YYSYMBOL_slot_acc = 110,                 /* slot_acc  */
  YYSYMBOL_class_name_expr = 111,          /* class_name_expr  */
  YYSYMBOL_assign_op_struct = 112,         /* assign_op_struct  */
  YYSYMBOL_stmt_expr = 113,                /* stmt_expr  */
  YYSYMBOL_funcall_expr = 114,             /* funcall_expr  */
  YYSYMBOL_expr_list_decl = 115,           /* expr_list_decl  */
  YYSYMBOL_expr_list = 116,                /* expr_list  */
  YYSYMBOL_slot_assign_list = 117,         /* slot_assign_list  */
  YYSYMBOL_slot_assign = 118,              /* slot_assign  */
  YYSYMBOL_aidx_expr = 119                 /* aidx_expr  */
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
#define YYLAST   2309

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  83
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  37
/* YYNRULES -- Number of rules.  */
#define YYNRULES  146
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  324

/* YYMAXUTOK -- Last valid token kind.  */
#define YYMAXUTOK   312


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
       2,    73,     2,    82,    47,     2,     2,     2,     2,     2,
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
      79,    80,    81
};

#if CMDDEBUG
/* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_int16 yyrline[] =
{
       0,   148,   148,   154,   155,   160,   162,   164,   169,   174,
     176,   182,   183,   188,   189,   190,   191,   192,   193,   195,
     197,   199,   201,   203,   205,   210,   212,   218,   219,   224,
     226,   231,   233,   238,   240,   246,   247,   253,   254,   260,
     261,   267,   268,   270,   272,   277,   279,   284,   286,   291,
     293,   298,   300,   302,   307,   309,   314,   316,   321,   323,
     328,   330,   332,   334,   336,   338,   340,   342,   347,   352,
     354,   356,   358,   360,   362,   364,   366,   368,   370,   372,
     374,   376,   378,   380,   382,   384,   386,   388,   390,   392,
     394,   396,   398,   400,   402,   404,   406,   408,   410,   412,
     414,   416,   418,   420,   422,   424,   426,   428,   433,   435,
     440,   442,   447,   449,   451,   453,   455,   457,   459,   461,
     463,   465,   467,   469,   474,   476,   478,   480,   482,   484,
     486,   488,   490,   495,   497,   499,   505,   506,   511,   513,
     518,   520,   525,   527,   529,   534,   536
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
  "opMDASN", "opNDASN", "opNTASN", "'?'", "opCAT", "opSTRNE", "opINSTANCE",
  "UNARY", "']'", "$accept", "start", "decl_list", "decl", "package_decl",
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

#define YYPACT_NINF (-266)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-69)

#define yytable_value_is_error(Yyn) \
  0

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int16 yypact[] =
{
    -266,    24,  1779,  -266,    10,     1,   -11,    28,    34,   144,
      35,  1853,    38,    55,    41,    42,    63,  -266,    56,  1706,
     -18,  -266,  -266,  -266,  2228,  2228,  2228,  2228,  2228,  -266,
    -266,  -266,  -266,  -266,  -266,  -266,  -266,  -266,  -266,    46,
    1396,  2227,    73,  -266,    -4,  -266,  2228,    78,  -266,  -266,
    2228,  -266,  -266,  -266,   356,  -266,  2228,  -266,  -266,   103,
    2047,    79,  2228,  2228,    83,  2228,  2228,  -266,  -266,  2228,
    2228,  2228,  2228,  2228,  2228,  2228,  2228,  2228,  2228,  2228,
    -266,  2228,   125,   116,   116,   408,   116,   116,  -266,  2228,
    2228,  2228,  2228,  2228,  2228,   133,  2228,  2228,  2228,  2228,
    2228,  2228,  2228,  2228,  2228,  2228,  2228,  2228,  2228,  2228,
    2228,  2228,  2228,  2058,  -266,   137,   139,   460,  2228,   512,
    -266,   564,  1881,   122,  2088,   616,   140,   668,   720,   175,
     304,  1396,  1396,  1396,  1396,  1396,  1396,  1396,  1396,  1396,
    1396,  1396,  1396,   -34,  1396,   141,   143,   146,  -266,     8,
       8,   116,   116,  1701,  1701,   -28,  1604,   243,   116,  1656,
     178,   124,   124,   -16,   -16,  1701,  1701,  1552,  1500,   178,
     772,   178,   178,  2228,  1396,  -266,   142,   145,   149,  -266,
     147,  1396,  1853,  1853,  -266,  -266,  2228,  1677,   824,  2116,
     147,   150,   151,     7,  -266,  2228,  -266,  2228,  2245,  -266,
    2228,  2228,  2228,  2228,  2228,   -14,   152,   167,   137,   169,
     156,   194,  -266,   876,  1853,   928,  2144,  2172,   980,   162,
     187,   187,   161,  -266,  1032,  1396,  2228,  -266,  1396,   170,
     172,   -17,  1448,  -266,  -266,  -266,   177,  -266,  2228,   180,
    1853,  -266,  -266,  1853,  1853,  1084,  1853,  1136,  2200,   171,
    2228,   179,   181,  -266,  -266,  1396,  -266,  -266,  -266,  1927,
     184,   143,   195,  -266,  -266,  -266,  1853,  -266,  1853,  1853,
    1188,    31,     0,  1396,  -266,  -266,  -266,  -266,    69,  -266,
    -266,  -266,  1853,   188,   -24,   182,    51,  -266,  2228,  -266,
    1973,   199,   193,   220,    69,  -266,  2228,  2228,  2228,  -266,
     201,  -266,  1396,  1825,  -266,  -266,  -266,   202,   220,  1240,
    1292,   -15,  -266,   204,  -266,  -266,  -266,  -266,   213,  -266,
    2228,  2019,  1344,  -266
};

/* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE does not specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       3,     0,     2,     1,     0,     0,   102,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   101,    81,   106,
     104,   105,    99,   100,     0,     0,     0,     0,     0,     4,
       7,     5,     6,    16,   125,    17,    13,    14,    15,     0,
       0,   103,    69,   124,     0,   110,     0,     0,    18,    19,
       0,   102,    81,    20,     0,    69,     0,    11,    48,     0,
       0,     0,     0,     0,     0,     0,     0,   113,   112,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     128,   136,     0,    79,    80,     0,    98,    97,    22,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   130,    27,     0,     0,    37,     0,
      21,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   126,   114,   115,   116,   117,   118,   119,   120,   121,
     122,   123,   145,     0,   138,     0,   137,     0,    70,    75,
      76,    77,    78,    83,    84,   108,    74,    73,    72,    71,
      95,    90,    91,    87,    88,    85,    86,    92,    89,    93,
       0,    94,    96,     0,   131,    29,     0,    28,     0,   111,
      35,    38,     0,     0,    47,    12,     0,     0,     0,     0,
      35,     0,     0,     0,     9,     0,    23,     0,   107,   133,
       0,   136,   136,     0,     0,     0,     0,     0,    27,     0,
      39,    56,    58,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    10,     0,   146,     0,   129,   139,     0,
       0,     0,    82,   132,    11,    30,     0,    36,     0,     0,
       0,    59,    67,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     8,    24,   127,   134,   135,   109,     0,
       0,    40,    34,    57,    66,    65,     0,    63,     0,     0,
       0,     0,     0,    54,    49,    50,    25,    11,    41,    64,
      62,    61,     0,     0,     0,     0,     0,   140,     0,    11,
       0,     0,     0,    43,    42,    60,     0,     0,     0,    32,
       0,   141,    55,    51,    26,    45,    33,     0,    44,     0,
       0,     0,    31,     0,    53,    46,   143,   142,     0,    11,
       0,    52,     0,   144
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -266,  -266,  -266,  -266,  -266,  -266,  -227,    -1,  -123,    43,
    -266,  -266,  -207,    62,  -266,  -266,  -266,   -41,   -67,  -266,
    -218,  -266,  -266,  -266,  -266,  -266,    33,  -266,  -266,   -39,
      -2,  -266,  -171,  -169,   -23,  -265,  -198
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
       0,     1,     2,    29,    30,   193,   122,    58,    32,   176,
     177,    33,    34,   210,   180,   239,   292,   293,    59,    35,
     251,   272,    36,    37,    38,    39,    40,    41,    47,    80,
      55,    43,   145,   146,   286,   287,   143
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      42,    31,   114,   252,   205,   231,   194,   259,   197,    42,
       4,   297,   202,    89,    90,    91,    92,    93,    94,   288,
      95,   301,    81,    98,     3,   197,    45,   197,   200,   301,
     229,   230,   233,    48,   100,    44,   115,   101,   102,    91,
      92,    46,    54,   289,    95,   203,   283,    98,   198,   298,
     290,   105,   106,   222,    82,   109,   284,    83,    84,    85,
      86,    87,   303,   111,   112,   258,   283,   318,   116,   261,
     223,   291,    49,     5,    50,    56,   284,   285,    60,   117,
      61,    62,    63,   119,   283,   314,   307,   291,    64,   121,
      88,    65,   321,   125,   284,   127,   128,   300,   130,   131,
     311,   307,   132,   133,   134,   135,   136,   137,   138,   139,
     140,   141,   142,   123,   144,   211,   212,   -68,   118,   126,
      42,   185,   149,   150,   151,   152,   153,   154,   129,   156,
     157,   158,   159,   160,   161,   162,   163,   164,   165,   166,
     167,   168,   169,   170,   171,   172,   174,   242,     5,    51,
     147,   181,    95,    89,    90,    91,    92,   188,   155,   227,
      95,   175,   186,    98,   178,   190,    17,    52,    19,    20,
      21,    22,    23,   263,    24,    25,   264,   265,     4,   267,
      42,    42,   199,   206,    26,   200,   201,   207,    53,   208,
     209,   235,    27,    28,   237,   220,   221,   234,   238,   279,
     240,   280,   281,   249,   250,   253,   144,    89,    90,    91,
      92,   256,    42,   257,    95,   295,   271,    98,   260,   213,
     215,   262,   218,   296,     5,   274,   299,   275,   224,   277,
     225,   101,   102,   228,   144,   144,   142,   232,    42,   306,
     278,    42,    42,   305,    42,   312,   315,   319,   320,   245,
     247,   236,   219,   308,     0,   294,     0,    42,   185,   255,
       0,     0,     0,     0,    42,     0,    42,    42,     0,     0,
       0,   144,    89,    90,    91,    92,    93,    94,     0,    95,
      42,   270,    98,   273,     0,     0,     0,     0,    42,   185,
       0,     0,     0,   100,     0,     0,   101,   102,     0,     0,
       0,    42,   185,     0,     0,     0,     0,     0,   103,   104,
     105,   106,     0,     0,   109,     0,     0,     0,     0,    42,
     185,   302,   111,   112,     0,     0,     0,     0,     0,   309,
     310,   142,     0,    89,    90,    91,    92,    93,    94,     0,
      95,    96,    97,    98,     0,     0,   195,     0,   196,     0,
       0,    99,     0,   322,   100,     0,     0,   101,   102,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   103,
     104,   105,   106,   107,   108,   109,     0,     0,     0,     0,
       0,   110,     0,   111,   112,    89,    90,    91,    92,    93,
      94,     0,    95,    96,    97,    98,     0,     0,     0,     0,
     120,     0,     0,    99,     0,     0,   100,     0,     0,   101,
     102,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   103,   104,   105,   106,   107,   108,   109,     0,     0,
       0,     0,     0,   110,     0,   111,   112,    89,    90,    91,
      92,    93,    94,     0,    95,    96,    97,    98,     0,   148,
       0,     0,     0,     0,     0,    99,     0,     0,   100,     0,
       0,   101,   102,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   103,   104,   105,   106,   107,   108,   109,
       0,     0,     0,     0,     0,   110,     0,   111,   112,    89,
      90,    91,    92,    93,    94,     0,    95,    96,    97,    98,
       0,   179,     0,     0,     0,     0,     0,    99,     0,     0,
     100,     0,     0,   101,   102,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   103,   104,   105,   106,   107,
     108,   109,     0,     0,     0,     0,     0,   110,     0,   111,
     112,    89,    90,    91,    92,    93,    94,     0,    95,    96,
      97,    98,     0,   182,     0,     0,     0,     0,     0,    99,
       0,     0,   100,     0,     0,   101,   102,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   103,   104,   105,
     106,   107,   108,   109,     0,     0,     0,     0,     0,   110,
       0,   111,   112,    89,    90,    91,    92,    93,    94,     0,
      95,    96,    97,    98,     0,   183,     0,     0,     0,     0,
       0,    99,     0,     0,   100,     0,     0,   101,   102,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   103,
     104,   105,   106,   107,   108,   109,     0,     0,     0,     0,
       0,   110,     0,   111,   112,    89,    90,    91,    92,    93,
      94,     0,    95,    96,    97,    98,     0,     0,     0,     0,
     189,     0,     0,    99,     0,     0,   100,     0,     0,   101,
     102,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   103,   104,   105,   106,   107,   108,   109,     0,     0,
       0,     0,     0,   110,     0,   111,   112,    89,    90,    91,
      92,    93,    94,     0,    95,    96,    97,    98,     0,   191,
       0,     0,     0,     0,     0,    99,     0,     0,   100,     0,
       0,   101,   102,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   103,   104,   105,   106,   107,   108,   109,
       0,     0,     0,     0,     0,   110,     0,   111,   112,    89,
      90,    91,    92,    93,    94,     0,    95,    96,    97,    98,
       0,   192,     0,     0,     0,     0,     0,    99,     0,     0,
     100,     0,     0,   101,   102,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   103,   104,   105,   106,   107,
     108,   109,     0,     0,     0,     0,     0,   110,     0,   111,
     112,    89,    90,    91,    92,    93,    94,     0,    95,    96,
      97,    98,     0,     0,     0,   204,     0,     0,     0,    99,
       0,     0,   100,     0,     0,   101,   102,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   103,   104,   105,
     106,   107,   108,   109,     0,     0,     0,     0,     0,   110,
       0,   111,   112,    89,    90,    91,    92,    93,    94,     0,
      95,    96,    97,    98,     0,     0,     0,     0,   216,     0,
       0,    99,     0,     0,   100,     0,     0,   101,   102,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   103,
     104,   105,   106,   107,   108,   109,     0,     0,     0,     0,
       0,   110,     0,   111,   112,    89,    90,    91,    92,    93,
      94,     0,    95,    96,    97,    98,     0,   241,     0,     0,
       0,     0,     0,    99,     0,     0,   100,     0,     0,   101,
     102,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   103,   104,   105,   106,   107,   108,   109,     0,     0,
       0,     0,     0,   110,     0,   111,   112,    89,    90,    91,
      92,    93,    94,     0,    95,    96,    97,    98,     0,   243,
       0,     0,     0,     0,     0,    99,     0,     0,   100,     0,
       0,   101,   102,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   103,   104,   105,   106,   107,   108,   109,
       0,     0,     0,     0,     0,   110,     0,   111,   112,    89,
      90,    91,    92,    93,    94,     0,    95,    96,    97,    98,
       0,     0,     0,     0,   248,     0,     0,    99,     0,     0,
     100,     0,     0,   101,   102,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   103,   104,   105,   106,   107,
     108,   109,     0,     0,     0,     0,     0,   110,     0,   111,
     112,    89,    90,    91,    92,    93,    94,     0,    95,    96,
      97,    98,     0,     0,     0,     0,   254,     0,     0,    99,
       0,     0,   100,     0,     0,   101,   102,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   103,   104,   105,
     106,   107,   108,   109,     0,     0,     0,     0,     0,   110,
       0,   111,   112,    89,    90,    91,    92,    93,    94,     0,
      95,    96,    97,    98,     0,   266,     0,     0,     0,     0,
       0,    99,     0,     0,   100,     0,     0,   101,   102,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   103,
     104,   105,   106,   107,   108,   109,     0,     0,     0,     0,
       0,   110,     0,   111,   112,    89,    90,    91,    92,    93,
      94,     0,    95,    96,    97,    98,     0,   268,     0,     0,
       0,     0,     0,    99,     0,     0,   100,     0,     0,   101,
     102,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   103,   104,   105,   106,   107,   108,   109,     0,     0,
       0,     0,     0,   110,     0,   111,   112,    89,    90,    91,
      92,    93,    94,     0,    95,    96,    97,    98,     0,   282,
       0,     0,     0,     0,     0,    99,     0,     0,   100,     0,
       0,   101,   102,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   103,   104,   105,   106,   107,   108,   109,
       0,     0,     0,     0,     0,   110,     0,   111,   112,    89,
      90,    91,    92,    93,    94,     0,    95,    96,    97,    98,
       0,     0,     0,     0,   316,     0,     0,    99,     0,     0,
     100,     0,     0,   101,   102,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   103,   104,   105,   106,   107,
     108,   109,     0,     0,     0,     0,     0,   110,     0,   111,
     112,    89,    90,    91,    92,    93,    94,     0,    95,    96,
      97,    98,     0,     0,     0,     0,   317,     0,     0,    99,
       0,     0,   100,     0,     0,   101,   102,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   103,   104,   105,
     106,   107,   108,   109,     0,     0,     0,     0,     0,   110,
       0,   111,   112,    89,    90,    91,    92,    93,    94,     0,
      95,    96,    97,    98,     0,     0,     0,     0,   323,     0,
       0,    99,     0,     0,   100,     0,     0,   101,   102,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   103,
     104,   105,   106,   107,   108,   109,     0,     0,     0,     0,
       0,   110,     0,   111,   112,    89,    90,    91,    92,    93,
      94,     0,    95,    96,    97,    98,     0,     0,     0,     0,
       0,     0,     0,    99,     0,     0,   100,     0,     0,   101,
     102,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   103,   104,   105,   106,   107,   108,   109,     0,     0,
       0,     0,     0,   110,     0,   111,   112,    89,    90,    91,
      92,    93,    94,     0,    95,    96,    97,    98,     0,     0,
       0,     0,     0,     0,     0,    99,     0,     0,   100,     0,
       0,   101,   102,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   103,   104,   105,   106,   107,   108,   109,
       0,     0,     0,     0,     0,     0,     0,   111,   112,    89,
      90,    91,    92,    93,    94,     0,    95,    96,    97,    98,
       0,     0,     0,     0,     0,     0,     0,    99,     0,     0,
     100,     0,     0,   101,   102,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   103,   104,   105,   106,   107,
       0,   109,     0,     0,     0,     0,     0,     0,     0,   111,
     112,    89,    90,    91,    92,    93,    94,     0,    95,    96,
      97,    98,     0,     0,     0,     0,     0,     0,     0,    99,
       0,     0,   100,     0,     0,   101,   102,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   103,   104,   105,
     106,     0,     0,   109,     0,     0,     0,     0,     0,     0,
       0,   111,   112,    89,    90,    91,    92,    93,    94,     0,
      95,     0,    97,    98,     0,     0,     0,     0,     0,     0,
       0,    99,     0,     0,   100,     0,     0,   101,   102,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   103,
     104,   105,   106,     0,     0,   109,     0,     0,     0,     0,
       0,     5,    51,   111,   112,    89,    90,    91,    92,    93,
      94,     0,    95,     0,    97,    98,     0,     0,     0,    17,
      52,    19,    20,    21,    22,    23,   100,    24,    25,   101,
     102,     0,     0,     0,     0,     0,     0,    26,   214,     0,
       0,   103,   104,   105,   106,    27,    28,   109,     0,     0,
      89,    90,    91,    92,     0,   111,   112,    95,     0,     0,
      98,    66,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   100,     0,     0,   101,   102,     0,    67,    68,     0,
       0,    69,    70,    71,    72,    73,    74,    75,    76,    77,
      78,     0,   109,     0,     0,     0,     0,     0,     0,    79,
     111,   112,     4,     5,     6,     0,     7,     8,     9,    10,
      11,     0,     0,    12,    13,    14,     0,    15,     0,    16,
       0,    17,    18,    19,    20,    21,    22,    23,     0,    24,
      25,     0,     0,     0,     0,     0,     0,     0,     0,    26,
       0,     0,     0,     0,     0,     0,     0,    27,    28,     5,
       6,     0,     7,     8,     9,    10,    11,   313,     0,    12,
      13,    14,   250,    15,     0,     0,     0,    17,    18,    19,
      20,    21,    22,    23,     0,    24,    25,     5,     6,     0,
       7,     8,     9,    10,    11,    26,     0,    12,    13,    14,
       0,    15,     0,    27,    28,    17,    18,    19,    20,    21,
      22,    23,     0,    24,    25,     5,     6,     0,     7,     8,
       9,    10,    11,    26,     0,    12,    13,    14,    57,    15,
       0,    27,    28,    17,    18,    19,    20,    21,    22,    23,
       0,    24,    25,     0,     0,     0,     0,     0,     0,     0,
       0,    26,     0,     0,     0,     0,     0,   184,     0,    27,
      28,     5,     6,     0,     7,     8,     9,    10,    11,     0,
       0,    12,    13,    14,     0,    15,     0,     0,     0,    17,
      18,    19,    20,    21,    22,    23,     0,    24,    25,     0,
       0,     0,     0,     0,     0,     0,     0,    26,     0,     0,
       0,     0,     0,   276,     0,    27,    28,     5,     6,     0,
       7,     8,     9,    10,    11,     0,     0,    12,    13,    14,
       0,    15,     0,     0,     0,    17,    18,    19,    20,    21,
      22,    23,     0,    24,    25,     0,     0,     0,     0,     0,
       0,     0,     0,    26,     0,     0,     0,     0,     0,   304,
       0,    27,    28,     5,     6,     0,     7,     8,     9,    10,
      11,     0,     0,    12,    13,    14,     0,    15,     0,     0,
       0,    17,    18,    19,    20,    21,    22,    23,     0,    24,
      25,     5,    51,     0,     0,     0,     0,     0,     0,    26,
       0,     0,     5,    51,     0,     0,     0,    27,    28,    17,
      52,    19,    20,    21,    22,    23,     0,    24,    25,     0,
      17,    52,    19,    20,    21,    22,    23,    26,    24,    25,
       0,   124,     5,    51,     0,    27,    28,     0,    26,     0,
       0,     0,     0,   173,     0,     0,    27,    28,     0,     0,
      17,    52,    19,    20,    21,    22,    23,     0,    24,    25,
       5,    51,     0,     0,     0,     0,     0,     0,    26,     0,
       0,     0,   187,     0,     0,     0,    27,    28,    17,    52,
      19,    20,    21,    22,    23,     0,    24,    25,     5,    51,
       0,     0,     0,     0,     0,     0,    26,     0,     0,     0,
     217,     0,     0,     0,    27,    28,    17,    52,    19,    20,
      21,    22,    23,     0,    24,    25,     5,    51,     0,     0,
       0,     0,     0,     0,    26,   244,     0,     0,     0,     0,
       0,     0,    27,    28,    17,    52,    19,    20,    21,    22,
      23,     0,    24,    25,     5,    51,     0,     0,     0,     0,
       0,     0,    26,   246,     0,     0,     0,     0,     0,     0,
      27,    28,    17,    52,    19,    20,    21,    22,    23,     0,
      24,    25,     5,    51,     0,     0,     0,     0,     0,     0,
      26,   269,     0,     0,     0,     0,     0,     0,    27,    28,
      17,    52,    19,    20,    21,    22,    23,     0,    24,    25,
       0,     0,   113,     0,     0,     0,     0,     0,    26,     0,
       0,     0,     0,     0,     0,     0,    27,    28,    67,    68,
     226,     0,    69,    70,    71,    72,    73,    74,    75,    76,
      77,    78,     0,     0,     0,     0,    67,    68,     0,     0,
      69,    70,    71,    72,    73,    74,    75,    76,    77,    78
};

static const yytype_int16 yycheck[] =
{
       2,     2,    41,   221,   173,   203,   129,   234,    42,    11,
       3,    35,    40,    29,    30,    31,    32,    33,    34,    19,
      36,   286,    40,    39,     0,    42,    25,    42,    42,   294,
     201,   202,    46,    44,    50,    25,    40,    53,    54,    31,
      32,    40,     9,    43,    36,    73,    15,    39,    82,    73,
     277,    67,    68,    46,    72,    71,    25,    24,    25,    26,
      27,    28,   289,    79,    80,    82,    15,    82,    72,   238,
     193,   278,    44,     4,    40,    40,    25,    46,    40,    46,
      25,    40,    40,    50,    15,   303,   293,   294,    25,    56,
      44,    35,   319,    60,    25,    62,    63,    46,    65,    66,
     298,   308,    69,    70,    71,    72,    73,    74,    75,    76,
      77,    78,    79,    10,    81,   182,   183,    44,    40,    40,
     122,   122,    89,    90,    91,    92,    93,    94,    45,    96,
      97,    98,    99,   100,   101,   102,   103,   104,   105,   106,
     107,   108,   109,   110,   111,   112,   113,   214,     4,     5,
      25,   118,    36,    29,    30,    31,    32,   124,    25,   198,
      36,    24,    40,    39,    25,    25,    22,    23,    24,    25,
      26,    27,    28,   240,    30,    31,   243,   244,     3,   246,
     182,   183,    41,    41,    40,    42,    40,    42,    44,    40,
      43,    24,    48,    49,    25,    45,    45,    45,    42,   266,
       6,   268,   269,    41,    17,    44,   173,    29,    30,    31,
      32,    41,   214,    41,    36,   282,    45,    39,    41,   186,
     187,    41,   189,    35,     4,    46,    44,    46,   195,    45,
     197,    53,    54,   200,   201,   202,   203,   204,   240,    46,
      45,   243,   244,    44,   246,    44,    44,    43,    35,   216,
     217,   208,   190,   294,    -1,   278,    -1,   259,   259,   226,
      -1,    -1,    -1,    -1,   266,    -1,   268,   269,    -1,    -1,
      -1,   238,    29,    30,    31,    32,    33,    34,    -1,    36,
     282,   248,    39,   250,    -1,    -1,    -1,    -1,   290,   290,
      -1,    -1,    -1,    50,    -1,    -1,    53,    54,    -1,    -1,
      -1,   303,   303,    -1,    -1,    -1,    -1,    -1,    65,    66,
      67,    68,    -1,    -1,    71,    -1,    -1,    -1,    -1,   321,
     321,   288,    79,    80,    -1,    -1,    -1,    -1,    -1,   296,
     297,   298,    -1,    29,    30,    31,    32,    33,    34,    -1,
      36,    37,    38,    39,    -1,    -1,    42,    -1,    44,    -1,
      -1,    47,    -1,   320,    50,    -1,    -1,    53,    54,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    65,
      66,    67,    68,    69,    70,    71,    -1,    -1,    -1,    -1,
      -1,    77,    -1,    79,    80,    29,    30,    31,    32,    33,
      34,    -1,    36,    37,    38,    39,    -1,    -1,    -1,    -1,
      44,    -1,    -1,    47,    -1,    -1,    50,    -1,    -1,    53,
      54,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    65,    66,    67,    68,    69,    70,    71,    -1,    -1,
      -1,    -1,    -1,    77,    -1,    79,    80,    29,    30,    31,
      32,    33,    34,    -1,    36,    37,    38,    39,    -1,    41,
      -1,    -1,    -1,    -1,    -1,    47,    -1,    -1,    50,    -1,
      -1,    53,    54,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    65,    66,    67,    68,    69,    70,    71,
      -1,    -1,    -1,    -1,    -1,    77,    -1,    79,    80,    29,
      30,    31,    32,    33,    34,    -1,    36,    37,    38,    39,
      -1,    41,    -1,    -1,    -1,    -1,    -1,    47,    -1,    -1,
      50,    -1,    -1,    53,    54,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    65,    66,    67,    68,    69,
      70,    71,    -1,    -1,    -1,    -1,    -1,    77,    -1,    79,
      80,    29,    30,    31,    32,    33,    34,    -1,    36,    37,
      38,    39,    -1,    41,    -1,    -1,    -1,    -1,    -1,    47,
      -1,    -1,    50,    -1,    -1,    53,    54,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    65,    66,    67,
      68,    69,    70,    71,    -1,    -1,    -1,    -1,    -1,    77,
      -1,    79,    80,    29,    30,    31,    32,    33,    34,    -1,
      36,    37,    38,    39,    -1,    41,    -1,    -1,    -1,    -1,
      -1,    47,    -1,    -1,    50,    -1,    -1,    53,    54,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    65,
      66,    67,    68,    69,    70,    71,    -1,    -1,    -1,    -1,
      -1,    77,    -1,    79,    80,    29,    30,    31,    32,    33,
      34,    -1,    36,    37,    38,    39,    -1,    -1,    -1,    -1,
      44,    -1,    -1,    47,    -1,    -1,    50,    -1,    -1,    53,
      54,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    65,    66,    67,    68,    69,    70,    71,    -1,    -1,
      -1,    -1,    -1,    77,    -1,    79,    80,    29,    30,    31,
      32,    33,    34,    -1,    36,    37,    38,    39,    -1,    41,
      -1,    -1,    -1,    -1,    -1,    47,    -1,    -1,    50,    -1,
      -1,    53,    54,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    65,    66,    67,    68,    69,    70,    71,
      -1,    -1,    -1,    -1,    -1,    77,    -1,    79,    80,    29,
      30,    31,    32,    33,    34,    -1,    36,    37,    38,    39,
      -1,    41,    -1,    -1,    -1,    -1,    -1,    47,    -1,    -1,
      50,    -1,    -1,    53,    54,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    65,    66,    67,    68,    69,
      70,    71,    -1,    -1,    -1,    -1,    -1,    77,    -1,    79,
      80,    29,    30,    31,    32,    33,    34,    -1,    36,    37,
      38,    39,    -1,    -1,    -1,    43,    -1,    -1,    -1,    47,
      -1,    -1,    50,    -1,    -1,    53,    54,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    65,    66,    67,
      68,    69,    70,    71,    -1,    -1,    -1,    -1,    -1,    77,
      -1,    79,    80,    29,    30,    31,    32,    33,    34,    -1,
      36,    37,    38,    39,    -1,    -1,    -1,    -1,    44,    -1,
      -1,    47,    -1,    -1,    50,    -1,    -1,    53,    54,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    65,
      66,    67,    68,    69,    70,    71,    -1,    -1,    -1,    -1,
      -1,    77,    -1,    79,    80,    29,    30,    31,    32,    33,
      34,    -1,    36,    37,    38,    39,    -1,    41,    -1,    -1,
      -1,    -1,    -1,    47,    -1,    -1,    50,    -1,    -1,    53,
      54,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    65,    66,    67,    68,    69,    70,    71,    -1,    -1,
      -1,    -1,    -1,    77,    -1,    79,    80,    29,    30,    31,
      32,    33,    34,    -1,    36,    37,    38,    39,    -1,    41,
      -1,    -1,    -1,    -1,    -1,    47,    -1,    -1,    50,    -1,
      -1,    53,    54,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    65,    66,    67,    68,    69,    70,    71,
      -1,    -1,    -1,    -1,    -1,    77,    -1,    79,    80,    29,
      30,    31,    32,    33,    34,    -1,    36,    37,    38,    39,
      -1,    -1,    -1,    -1,    44,    -1,    -1,    47,    -1,    -1,
      50,    -1,    -1,    53,    54,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    65,    66,    67,    68,    69,
      70,    71,    -1,    -1,    -1,    -1,    -1,    77,    -1,    79,
      80,    29,    30,    31,    32,    33,    34,    -1,    36,    37,
      38,    39,    -1,    -1,    -1,    -1,    44,    -1,    -1,    47,
      -1,    -1,    50,    -1,    -1,    53,    54,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    65,    66,    67,
      68,    69,    70,    71,    -1,    -1,    -1,    -1,    -1,    77,
      -1,    79,    80,    29,    30,    31,    32,    33,    34,    -1,
      36,    37,    38,    39,    -1,    41,    -1,    -1,    -1,    -1,
      -1,    47,    -1,    -1,    50,    -1,    -1,    53,    54,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    65,
      66,    67,    68,    69,    70,    71,    -1,    -1,    -1,    -1,
      -1,    77,    -1,    79,    80,    29,    30,    31,    32,    33,
      34,    -1,    36,    37,    38,    39,    -1,    41,    -1,    -1,
      -1,    -1,    -1,    47,    -1,    -1,    50,    -1,    -1,    53,
      54,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    65,    66,    67,    68,    69,    70,    71,    -1,    -1,
      -1,    -1,    -1,    77,    -1,    79,    80,    29,    30,    31,
      32,    33,    34,    -1,    36,    37,    38,    39,    -1,    41,
      -1,    -1,    -1,    -1,    -1,    47,    -1,    -1,    50,    -1,
      -1,    53,    54,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    65,    66,    67,    68,    69,    70,    71,
      -1,    -1,    -1,    -1,    -1,    77,    -1,    79,    80,    29,
      30,    31,    32,    33,    34,    -1,    36,    37,    38,    39,
      -1,    -1,    -1,    -1,    44,    -1,    -1,    47,    -1,    -1,
      50,    -1,    -1,    53,    54,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    65,    66,    67,    68,    69,
      70,    71,    -1,    -1,    -1,    -1,    -1,    77,    -1,    79,
      80,    29,    30,    31,    32,    33,    34,    -1,    36,    37,
      38,    39,    -1,    -1,    -1,    -1,    44,    -1,    -1,    47,
      -1,    -1,    50,    -1,    -1,    53,    54,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    65,    66,    67,
      68,    69,    70,    71,    -1,    -1,    -1,    -1,    -1,    77,
      -1,    79,    80,    29,    30,    31,    32,    33,    34,    -1,
      36,    37,    38,    39,    -1,    -1,    -1,    -1,    44,    -1,
      -1,    47,    -1,    -1,    50,    -1,    -1,    53,    54,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    65,
      66,    67,    68,    69,    70,    71,    -1,    -1,    -1,    -1,
      -1,    77,    -1,    79,    80,    29,    30,    31,    32,    33,
      34,    -1,    36,    37,    38,    39,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    47,    -1,    -1,    50,    -1,    -1,    53,
      54,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    65,    66,    67,    68,    69,    70,    71,    -1,    -1,
      -1,    -1,    -1,    77,    -1,    79,    80,    29,    30,    31,
      32,    33,    34,    -1,    36,    37,    38,    39,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    47,    -1,    -1,    50,    -1,
      -1,    53,    54,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    65,    66,    67,    68,    69,    70,    71,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    79,    80,    29,
      30,    31,    32,    33,    34,    -1,    36,    37,    38,    39,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    47,    -1,    -1,
      50,    -1,    -1,    53,    54,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    65,    66,    67,    68,    69,
      -1,    71,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    79,
      80,    29,    30,    31,    32,    33,    34,    -1,    36,    37,
      38,    39,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    47,
      -1,    -1,    50,    -1,    -1,    53,    54,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    65,    66,    67,
      68,    -1,    -1,    71,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    79,    80,    29,    30,    31,    32,    33,    34,    -1,
      36,    -1,    38,    39,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    47,    -1,    -1,    50,    -1,    -1,    53,    54,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    65,
      66,    67,    68,    -1,    -1,    71,    -1,    -1,    -1,    -1,
      -1,     4,     5,    79,    80,    29,    30,    31,    32,    33,
      34,    -1,    36,    -1,    38,    39,    -1,    -1,    -1,    22,
      23,    24,    25,    26,    27,    28,    50,    30,    31,    53,
      54,    -1,    -1,    -1,    -1,    -1,    -1,    40,    41,    -1,
      -1,    65,    66,    67,    68,    48,    49,    71,    -1,    -1,
      29,    30,    31,    32,    -1,    79,    80,    36,    -1,    -1,
      39,    35,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    50,    -1,    -1,    53,    54,    -1,    51,    52,    -1,
      -1,    55,    56,    57,    58,    59,    60,    61,    62,    63,
      64,    -1,    71,    -1,    -1,    -1,    -1,    -1,    -1,    73,
      79,    80,     3,     4,     5,    -1,     7,     8,     9,    10,
      11,    -1,    -1,    14,    15,    16,    -1,    18,    -1,    20,
      -1,    22,    23,    24,    25,    26,    27,    28,    -1,    30,
      31,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    40,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    48,    49,     4,
       5,    -1,     7,     8,     9,    10,    11,    12,    -1,    14,
      15,    16,    17,    18,    -1,    -1,    -1,    22,    23,    24,
      25,    26,    27,    28,    -1,    30,    31,     4,     5,    -1,
       7,     8,     9,    10,    11,    40,    -1,    14,    15,    16,
      -1,    18,    -1,    48,    49,    22,    23,    24,    25,    26,
      27,    28,    -1,    30,    31,     4,     5,    -1,     7,     8,
       9,    10,    11,    40,    -1,    14,    15,    16,    45,    18,
      -1,    48,    49,    22,    23,    24,    25,    26,    27,    28,
      -1,    30,    31,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    40,    -1,    -1,    -1,    -1,    -1,    46,    -1,    48,
      49,     4,     5,    -1,     7,     8,     9,    10,    11,    -1,
      -1,    14,    15,    16,    -1,    18,    -1,    -1,    -1,    22,
      23,    24,    25,    26,    27,    28,    -1,    30,    31,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    40,    -1,    -1,
      -1,    -1,    -1,    46,    -1,    48,    49,     4,     5,    -1,
       7,     8,     9,    10,    11,    -1,    -1,    14,    15,    16,
      -1,    18,    -1,    -1,    -1,    22,    23,    24,    25,    26,
      27,    28,    -1,    30,    31,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    40,    -1,    -1,    -1,    -1,    -1,    46,
      -1,    48,    49,     4,     5,    -1,     7,     8,     9,    10,
      11,    -1,    -1,    14,    15,    16,    -1,    18,    -1,    -1,
      -1,    22,    23,    24,    25,    26,    27,    28,    -1,    30,
      31,     4,     5,    -1,    -1,    -1,    -1,    -1,    -1,    40,
      -1,    -1,     4,     5,    -1,    -1,    -1,    48,    49,    22,
      23,    24,    25,    26,    27,    28,    -1,    30,    31,    -1,
      22,    23,    24,    25,    26,    27,    28,    40,    30,    31,
      -1,    44,     4,     5,    -1,    48,    49,    -1,    40,    -1,
      -1,    -1,    -1,    45,    -1,    -1,    48,    49,    -1,    -1,
      22,    23,    24,    25,    26,    27,    28,    -1,    30,    31,
       4,     5,    -1,    -1,    -1,    -1,    -1,    -1,    40,    -1,
      -1,    -1,    44,    -1,    -1,    -1,    48,    49,    22,    23,
      24,    25,    26,    27,    28,    -1,    30,    31,     4,     5,
      -1,    -1,    -1,    -1,    -1,    -1,    40,    -1,    -1,    -1,
      44,    -1,    -1,    -1,    48,    49,    22,    23,    24,    25,
      26,    27,    28,    -1,    30,    31,     4,     5,    -1,    -1,
      -1,    -1,    -1,    -1,    40,    41,    -1,    -1,    -1,    -1,
      -1,    -1,    48,    49,    22,    23,    24,    25,    26,    27,
      28,    -1,    30,    31,     4,     5,    -1,    -1,    -1,    -1,
      -1,    -1,    40,    41,    -1,    -1,    -1,    -1,    -1,    -1,
      48,    49,    22,    23,    24,    25,    26,    27,    28,    -1,
      30,    31,     4,     5,    -1,    -1,    -1,    -1,    -1,    -1,
      40,    41,    -1,    -1,    -1,    -1,    -1,    -1,    48,    49,
      22,    23,    24,    25,    26,    27,    28,    -1,    30,    31,
      -1,    -1,    35,    -1,    -1,    -1,    -1,    -1,    40,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    48,    49,    51,    52,
      35,    -1,    55,    56,    57,    58,    59,    60,    61,    62,
      63,    64,    -1,    -1,    -1,    -1,    51,    52,    -1,    -1,
      55,    56,    57,    58,    59,    60,    61,    62,    63,    64
};

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,    84,    85,     0,     3,     4,     5,     7,     8,     9,
      10,    11,    14,    15,    16,    18,    20,    22,    23,    24,
      25,    26,    27,    28,    30,    31,    40,    48,    49,    86,
      87,    90,    91,    94,    95,   102,   105,   106,   107,   108,
     109,   110,   113,   114,    25,    25,    40,   111,    44,    44,
      40,     5,    23,    44,   109,   113,    40,    45,    90,   101,
      40,    25,    40,    40,    25,    35,    35,    51,    52,    55,
      56,    57,    58,    59,    60,    61,    62,    63,    64,    73,
     112,    40,    72,   109,   109,   109,   109,   109,    44,    29,
      30,    31,    32,    33,    34,    36,    37,    38,    39,    47,
      50,    53,    54,    65,    66,    67,    68,    69,    70,    71,
      77,    79,    80,    35,   112,    40,    72,   109,    40,   109,
      44,   109,    89,    10,    44,   109,    40,   109,   109,    45,
     109,   109,   109,   109,   109,   109,   109,   109,   109,   109,
     109,   109,   109,   119,   109,   115,   116,    25,    41,   109,
     109,   109,   109,   109,   109,    25,   109,   109,   109,   109,
     109,   109,   109,   109,   109,   109,   109,   109,   109,   109,
     109,   109,   109,    45,   109,    24,    92,    93,    25,    41,
      97,   109,    41,    41,    46,    90,    40,    44,   109,    44,
      25,    41,    41,    88,    91,    42,    44,    42,    82,    41,
      42,    40,    40,    73,    43,   116,    41,    42,    40,    43,
      96,   101,   101,   109,    41,   109,    44,    44,   109,    96,
      45,    45,    46,    91,   109,   109,    35,   112,   109,   115,
     115,   119,   109,    46,    45,    24,    92,    25,    42,    98,
       6,    41,   101,    41,    41,   109,    41,   109,    44,    41,
      17,   103,   103,    44,    44,   109,    41,    41,    82,    89,
      41,   116,    41,   101,   101,   101,    41,   101,    41,    41,
     109,    45,   104,   109,    46,    46,    46,    45,    45,   101,
     101,   101,    41,    15,    25,    46,   117,   118,    19,    43,
      89,    95,    99,   100,   117,   101,    35,    35,    73,    44,
      46,   118,   109,    89,    46,    44,    46,    95,   100,   109,
     109,   119,    44,    12,   103,    44,    44,    44,    82,    43,
      35,    89,   109,    44
};

/* YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr1[] =
{
       0,    83,    84,    85,    85,    86,    86,    86,    87,    88,
      88,    89,    89,    90,    90,    90,    90,    90,    90,    90,
      90,    90,    90,    90,    90,    91,    91,    92,    92,    93,
      93,    94,    94,    95,    95,    96,    96,    97,    97,    98,
      98,    99,    99,    99,    99,   100,   100,   101,   101,   102,
     102,   103,   103,   103,   104,   104,   105,   105,   106,   106,
     107,   107,   107,   107,   107,   107,   107,   107,   108,   109,
     109,   109,   109,   109,   109,   109,   109,   109,   109,   109,
     109,   109,   109,   109,   109,   109,   109,   109,   109,   109,
     109,   109,   109,   109,   109,   109,   109,   109,   109,   109,
     109,   109,   109,   109,   109,   109,   109,   109,   110,   110,
     111,   111,   112,   112,   112,   112,   112,   112,   112,   112,
     112,   112,   112,   112,   113,   113,   113,   113,   113,   113,
     113,   113,   113,   114,   114,   114,   115,   115,   116,   116,
     117,   117,   118,   118,   118,   119,   119
};

/* YYR2[RULE-NUM] -- Number of symbols on the right-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     1,     0,     2,     1,     1,     1,     6,     1,
       2,     0,     2,     1,     1,     1,     1,     1,     2,     2,
       2,     3,     2,     4,     6,     8,    10,     0,     1,     1,
       3,    10,     9,    10,     7,     0,     2,     0,     1,     0,
       2,     0,     1,     1,     2,     2,     3,     3,     1,     7,
       7,     4,     7,     5,     1,     3,     5,     7,     5,     6,
       9,     8,     8,     7,     8,     7,     7,     6,     1,     1,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     2,
       2,     1,     5,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     2,     2,     1,
       1,     1,     1,     1,     1,     1,     1,     4,     3,     6,
       1,     3,     1,     1,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     1,     1,     3,     6,     2,     5,
       2,     3,     5,     4,     6,     6,     0,     1,     1,     3,
       1,     2,     4,     4,     7,     1,     3
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
#line 1843 "CMDgram.cc"
    break;

  case 3: /* decl_list: %empty  */
#line 154 "CMDgram.y"
      { (yyval.stmt) = nil; }
#line 1849 "CMDgram.cc"
    break;

  case 4: /* decl_list: decl_list decl  */
#line 156 "CMDgram.y"
      { if(!statementList) { statementList = (yyvsp[0].stmt); } else { statementList->append((yyvsp[0].stmt)); } }
#line 1855 "CMDgram.cc"
    break;

  case 5: /* decl: stmt  */
#line 161 "CMDgram.y"
      { (yyval.stmt) = (yyvsp[0].stmt); }
#line 1861 "CMDgram.cc"
    break;

  case 6: /* decl: fn_decl_stmt  */
#line 163 "CMDgram.y"
      { (yyval.stmt) = (yyvsp[0].stmt); }
#line 1867 "CMDgram.cc"
    break;

  case 7: /* decl: package_decl  */
#line 165 "CMDgram.y"
     { (yyval.stmt) = (yyvsp[0].stmt); }
#line 1873 "CMDgram.cc"
    break;

  case 8: /* package_decl: rwPACKAGE IDENT '{' fn_decl_list '}' ';'  */
#line 170 "CMDgram.y"
      { (yyval.stmt) = (yyvsp[-2].stmt); for(StmtNode *walk = ((yyvsp[-2].stmt));walk;walk = walk->getNext() ) walk->setPackage((yyvsp[-4].s)); }
#line 1879 "CMDgram.cc"
    break;

  case 9: /* fn_decl_list: fn_decl_stmt  */
#line 175 "CMDgram.y"
      { (yyval.stmt) = (yyvsp[0].stmt); }
#line 1885 "CMDgram.cc"
    break;

  case 10: /* fn_decl_list: fn_decl_list fn_decl_stmt  */
#line 177 "CMDgram.y"
      { (yyval.stmt) = (yyvsp[-1].stmt); ((yyvsp[-1].stmt))->append((yyvsp[0].stmt));  }
#line 1891 "CMDgram.cc"
    break;

  case 11: /* statement_list: %empty  */
#line 182 "CMDgram.y"
      { (yyval.stmt) = nil; }
#line 1897 "CMDgram.cc"
    break;

  case 12: /* statement_list: statement_list stmt  */
#line 184 "CMDgram.y"
      { if(!(yyvsp[-1].stmt)) { (yyval.stmt) = (yyvsp[0].stmt); } else { ((yyvsp[-1].stmt))->append((yyvsp[0].stmt)); (yyval.stmt) = (yyvsp[-1].stmt); } }
#line 1903 "CMDgram.cc"
    break;

  case 18: /* stmt: rwBREAK ';'  */
#line 194 "CMDgram.y"
      { (yyval.stmt) = BreakStmtNode::alloc(); }
#line 1909 "CMDgram.cc"
    break;

  case 19: /* stmt: rwCONTINUE ';'  */
#line 196 "CMDgram.y"
      { (yyval.stmt) = ContinueStmtNode::alloc(); }
#line 1915 "CMDgram.cc"
    break;

  case 20: /* stmt: rwRETURN ';'  */
#line 198 "CMDgram.y"
      { (yyval.stmt) = ReturnStmtNode::alloc(NULL); }
#line 1921 "CMDgram.cc"
    break;

  case 21: /* stmt: rwRETURN expr ';'  */
#line 200 "CMDgram.y"
      { (yyval.stmt) = ReturnStmtNode::alloc((yyvsp[-1].expr)); }
#line 1927 "CMDgram.cc"
    break;

  case 22: /* stmt: expression_stmt ';'  */
#line 202 "CMDgram.y"
      { (yyval.stmt) = (yyvsp[-1].stmt); }
#line 1933 "CMDgram.cc"
    break;

  case 23: /* stmt: TTAG '=' expr ';'  */
#line 204 "CMDgram.y"
      { (yyval.stmt) = TTagSetStmtNode::alloc((yyvsp[-3].s), (yyvsp[-1].expr), NULL); }
#line 1939 "CMDgram.cc"
    break;

  case 24: /* stmt: TTAG '=' expr ',' expr ';'  */
#line 206 "CMDgram.y"
      { (yyval.stmt) = TTagSetStmtNode::alloc((yyvsp[-5].s), (yyvsp[-3].expr), (yyvsp[-1].expr)); }
#line 1945 "CMDgram.cc"
    break;

  case 25: /* fn_decl_stmt: rwDEFINE IDENT '(' var_list_decl ')' '{' statement_list '}'  */
#line 211 "CMDgram.y"
      { (yyval.stmt) = FunctionDeclStmtNode::alloc((yyvsp[-6].s), NULL, (yyvsp[-4].var), (yyvsp[-1].stmt)); }
#line 1951 "CMDgram.cc"
    break;

  case 26: /* fn_decl_stmt: rwDEFINE IDENT opCOLONCOLON IDENT '(' var_list_decl ')' '{' statement_list '}'  */
#line 213 "CMDgram.y"
     { (yyval.stmt) = FunctionDeclStmtNode::alloc((yyvsp[-6].s), (yyvsp[-8].s), (yyvsp[-4].var), (yyvsp[-1].stmt)); }
#line 1957 "CMDgram.cc"
    break;

  case 27: /* var_list_decl: %empty  */
#line 218 "CMDgram.y"
     { (yyval.var) = NULL; }
#line 1963 "CMDgram.cc"
    break;

  case 28: /* var_list_decl: var_list  */
#line 220 "CMDgram.y"
     { (yyval.var) = (yyvsp[0].var); }
#line 1969 "CMDgram.cc"
    break;

  case 29: /* var_list: VAR  */
#line 225 "CMDgram.y"
      { (yyval.var) = VarNode::alloc((yyvsp[0].s), NULL); }
#line 1975 "CMDgram.cc"
    break;

  case 30: /* var_list: var_list ',' VAR  */
#line 227 "CMDgram.y"
      { (yyval.var) = (yyvsp[-2].var); ((StmtNode*)((yyvsp[-2].var)))->append((StmtNode*)VarNode::alloc((yyvsp[0].s), NULL)); }
#line 1981 "CMDgram.cc"
    break;

  case 31: /* datablock_decl: rwDATABLOCK IDENT '(' IDENT parent_block ')' '{' slot_assign_list '}' ';'  */
#line 232 "CMDgram.y"
      { (yyval.stmt) = ObjectDeclNode::alloc(ConstantNode::alloc((yyvsp[-8].s)), ConstantNode::alloc((yyvsp[-6].s)), NULL, (yyvsp[-5].s), (yyvsp[-2].slist), NULL, true); }
#line 1987 "CMDgram.cc"
    break;

  case 32: /* datablock_decl: rwDATABLOCK IDENT '(' IDENT parent_block ')' '{' '}' ';'  */
#line 234 "CMDgram.y"
      { (yyval.stmt) = ObjectDeclNode::alloc(ConstantNode::alloc((yyvsp[-7].s)), ConstantNode::alloc((yyvsp[-5].s)), NULL, (yyvsp[-4].s), NULL, NULL, true); }
#line 1993 "CMDgram.cc"
    break;

  case 33: /* object_decl: rwDECLARE class_name_expr '(' object_name parent_block object_args ')' '{' object_declare_block '}'  */
#line 239 "CMDgram.y"
      { (yyval.od) = ObjectDeclNode::alloc((yyvsp[-8].expr), (yyvsp[-6].expr), (yyvsp[-4].expr), (yyvsp[-5].s), (yyvsp[-1].odcl).slots, (yyvsp[-1].odcl).decls, false); }
#line 1999 "CMDgram.cc"
    break;

  case 34: /* object_decl: rwDECLARE class_name_expr '(' object_name parent_block object_args ')'  */
#line 241 "CMDgram.y"
      { (yyval.od) = ObjectDeclNode::alloc((yyvsp[-5].expr), (yyvsp[-3].expr), (yyvsp[-1].expr), (yyvsp[-2].s), NULL, NULL, false); }
#line 2005 "CMDgram.cc"
    break;

  case 35: /* parent_block: %empty  */
#line 246 "CMDgram.y"
      { (yyval.s) = NULL; }
#line 2011 "CMDgram.cc"
    break;

  case 36: /* parent_block: ':' IDENT  */
#line 248 "CMDgram.y"
      { (yyval.s) = (yyvsp[0].s); }
#line 2017 "CMDgram.cc"
    break;

  case 37: /* object_name: %empty  */
#line 253 "CMDgram.y"
      { (yyval.expr) = StrConstNode::alloc("", false); }
#line 2023 "CMDgram.cc"
    break;

  case 38: /* object_name: expr  */
#line 255 "CMDgram.y"
      { (yyval.expr) = (yyvsp[0].expr); }
#line 2029 "CMDgram.cc"
    break;

  case 39: /* object_args: %empty  */
#line 260 "CMDgram.y"
      { (yyval.expr) = NULL; }
#line 2035 "CMDgram.cc"
    break;

  case 40: /* object_args: ',' expr_list  */
#line 262 "CMDgram.y"
      { (yyval.expr) = (yyvsp[0].expr); }
#line 2041 "CMDgram.cc"
    break;

  case 41: /* object_declare_block: %empty  */
#line 267 "CMDgram.y"
      { (yyval.odcl).slots = NULL; (yyval.odcl).decls = NULL; }
#line 2047 "CMDgram.cc"
    break;

  case 42: /* object_declare_block: slot_assign_list  */
#line 269 "CMDgram.y"
      { (yyval.odcl).slots = (yyvsp[0].slist); (yyval.odcl).decls = NULL; }
#line 2053 "CMDgram.cc"
    break;

  case 43: /* object_declare_block: object_decl_list  */
#line 271 "CMDgram.y"
      { (yyval.odcl).slots = NULL; (yyval.odcl).decls = (yyvsp[0].od); }
#line 2059 "CMDgram.cc"
    break;

  case 44: /* object_declare_block: slot_assign_list object_decl_list  */
#line 273 "CMDgram.y"
      { (yyval.odcl).slots = (yyvsp[-1].slist); (yyval.odcl).decls = (yyvsp[0].od); }
#line 2065 "CMDgram.cc"
    break;

  case 45: /* object_decl_list: object_decl ';'  */
#line 278 "CMDgram.y"
      { (yyval.od) = (yyvsp[-1].od); }
#line 2071 "CMDgram.cc"
    break;

  case 46: /* object_decl_list: object_decl_list object_decl ';'  */
#line 280 "CMDgram.y"
      { (yyvsp[-2].od)->append((yyvsp[-1].od)); (yyval.od) = (yyvsp[-2].od); }
#line 2077 "CMDgram.cc"
    break;

  case 47: /* stmt_block: '{' statement_list '}'  */
#line 285 "CMDgram.y"
      { (yyval.stmt) = (yyvsp[-1].stmt); }
#line 2083 "CMDgram.cc"
    break;

  case 48: /* stmt_block: stmt  */
#line 287 "CMDgram.y"
      { (yyval.stmt) = (yyvsp[0].stmt); }
#line 2089 "CMDgram.cc"
    break;

  case 49: /* switch_stmt: rwSWITCH '(' expr ')' '{' case_block '}'  */
#line 292 "CMDgram.y"
      { (yyval.stmt) = (yyvsp[-1].ifnode); (yyvsp[-1].ifnode)->propagateSwitchExpr((yyvsp[-4].expr), false); }
#line 2095 "CMDgram.cc"
    break;

  case 50: /* switch_stmt: rwSWITCHSTR '(' expr ')' '{' case_block '}'  */
#line 294 "CMDgram.y"
      { (yyval.stmt) = (yyvsp[-1].ifnode); (yyvsp[-1].ifnode)->propagateSwitchExpr((yyvsp[-4].expr), true); }
#line 2101 "CMDgram.cc"
    break;

  case 51: /* case_block: rwCASE case_expr ':' statement_list  */
#line 299 "CMDgram.y"
      { (yyval.ifnode) = IfStmtNode::alloc((yyvsp[-3].i), (yyvsp[-2].expr), (yyvsp[0].stmt), NULL, false); }
#line 2107 "CMDgram.cc"
    break;

  case 52: /* case_block: rwCASE case_expr ':' statement_list rwDEFAULT ':' statement_list  */
#line 301 "CMDgram.y"
      { (yyval.ifnode) = IfStmtNode::alloc((yyvsp[-6].i), (yyvsp[-5].expr), (yyvsp[-3].stmt), (yyvsp[0].stmt), false); }
#line 2113 "CMDgram.cc"
    break;

  case 53: /* case_block: rwCASE case_expr ':' statement_list case_block  */
#line 303 "CMDgram.y"
      { (yyval.ifnode) = IfStmtNode::alloc((yyvsp[-4].i), (yyvsp[-3].expr), (yyvsp[-1].stmt), (yyvsp[0].ifnode), true); }
#line 2119 "CMDgram.cc"
    break;

  case 54: /* case_expr: expr  */
#line 308 "CMDgram.y"
      { (yyval.expr) = (yyvsp[0].expr);}
#line 2125 "CMDgram.cc"
    break;

  case 55: /* case_expr: case_expr rwCASEOR expr  */
#line 310 "CMDgram.y"
      { ((yyvsp[-2].expr))->append((yyvsp[0].expr)); (yyval.expr)=(yyvsp[-2].expr); }
#line 2131 "CMDgram.cc"
    break;

  case 56: /* if_stmt: rwIF '(' expr ')' stmt_block  */
#line 315 "CMDgram.y"
      { (yyval.stmt) = IfStmtNode::alloc((yyvsp[-4].i), (yyvsp[-2].expr), (yyvsp[0].stmt), NULL, false); }
#line 2137 "CMDgram.cc"
    break;

  case 57: /* if_stmt: rwIF '(' expr ')' stmt_block rwELSE stmt_block  */
#line 317 "CMDgram.y"
      { (yyval.stmt) = IfStmtNode::alloc((yyvsp[-6].i), (yyvsp[-4].expr), (yyvsp[-2].stmt), (yyvsp[0].stmt), false); }
#line 2143 "CMDgram.cc"
    break;

  case 58: /* while_stmt: rwWHILE '(' expr ')' stmt_block  */
#line 322 "CMDgram.y"
      { (yyval.stmt) = LoopStmtNode::alloc((yyvsp[-4].i), nil, (yyvsp[-2].expr), nil, (yyvsp[0].stmt), false); }
#line 2149 "CMDgram.cc"
    break;

  case 59: /* while_stmt: rwDO stmt_block rwWHILE '(' expr ')'  */
#line 324 "CMDgram.y"
      { (yyval.stmt) = LoopStmtNode::alloc((yyvsp[-3].i), nil, (yyvsp[-1].expr), nil, (yyvsp[-4].stmt), true); }
#line 2155 "CMDgram.cc"
    break;

  case 60: /* for_stmt: rwFOR '(' expr ';' expr ';' expr ')' stmt_block  */
#line 329 "CMDgram.y"
      { (yyval.stmt) = LoopStmtNode::alloc((yyvsp[-8].i), (yyvsp[-6].expr), (yyvsp[-4].expr), (yyvsp[-2].expr), (yyvsp[0].stmt), false); }
#line 2161 "CMDgram.cc"
    break;

  case 61: /* for_stmt: rwFOR '(' expr ';' expr ';' ')' stmt_block  */
#line 331 "CMDgram.y"
      { (yyval.stmt) = LoopStmtNode::alloc((yyvsp[-7].i), (yyvsp[-5].expr), (yyvsp[-3].expr), NULL, (yyvsp[0].stmt), false); }
#line 2167 "CMDgram.cc"
    break;

  case 62: /* for_stmt: rwFOR '(' expr ';' ';' expr ')' stmt_block  */
#line 333 "CMDgram.y"
      { (yyval.stmt) = LoopStmtNode::alloc((yyvsp[-7].i), (yyvsp[-5].expr), NULL, (yyvsp[-2].expr), (yyvsp[0].stmt), false); }
#line 2173 "CMDgram.cc"
    break;

  case 63: /* for_stmt: rwFOR '(' expr ';' ';' ')' stmt_block  */
#line 335 "CMDgram.y"
      { (yyval.stmt) = LoopStmtNode::alloc((yyvsp[-6].i), (yyvsp[-4].expr), NULL, NULL, (yyvsp[0].stmt), false); }
#line 2179 "CMDgram.cc"
    break;

  case 64: /* for_stmt: rwFOR '(' ';' expr ';' expr ')' stmt_block  */
#line 337 "CMDgram.y"
      { (yyval.stmt) = LoopStmtNode::alloc((yyvsp[-7].i), NULL, (yyvsp[-4].expr), (yyvsp[-2].expr), (yyvsp[0].stmt), false); }
#line 2185 "CMDgram.cc"
    break;

  case 65: /* for_stmt: rwFOR '(' ';' expr ';' ')' stmt_block  */
#line 339 "CMDgram.y"
      { (yyval.stmt) = LoopStmtNode::alloc((yyvsp[-6].i), NULL, (yyvsp[-3].expr), NULL, (yyvsp[0].stmt), false); }
#line 2191 "CMDgram.cc"
    break;

  case 66: /* for_stmt: rwFOR '(' ';' ';' expr ')' stmt_block  */
#line 341 "CMDgram.y"
      { (yyval.stmt) = LoopStmtNode::alloc((yyvsp[-6].i), NULL, NULL, (yyvsp[-2].expr), (yyvsp[0].stmt), false); }
#line 2197 "CMDgram.cc"
    break;

  case 67: /* for_stmt: rwFOR '(' ';' ';' ')' stmt_block  */
#line 343 "CMDgram.y"
      { (yyval.stmt) = LoopStmtNode::alloc((yyvsp[-5].i), NULL, NULL, NULL, (yyvsp[0].stmt), false); }
#line 2203 "CMDgram.cc"
    break;

  case 68: /* expression_stmt: stmt_expr  */
#line 348 "CMDgram.y"
      { (yyval.stmt) = (yyvsp[0].expr); }
#line 2209 "CMDgram.cc"
    break;

  case 69: /* expr: stmt_expr  */
#line 353 "CMDgram.y"
      { (yyval.expr) = (yyvsp[0].expr); }
#line 2215 "CMDgram.cc"
    break;

  case 70: /* expr: '(' expr ')'  */
#line 355 "CMDgram.y"
      { (yyval.expr) = (yyvsp[-1].expr); }
#line 2221 "CMDgram.cc"
    break;

  case 71: /* expr: expr '^' expr  */
#line 357 "CMDgram.y"
      { (yyval.expr) = IntBinaryExprNode::alloc((yyvsp[-1].i), (yyvsp[-2].expr), (yyvsp[0].expr)); }
#line 2227 "CMDgram.cc"
    break;

  case 72: /* expr: expr '%' expr  */
#line 359 "CMDgram.y"
      { (yyval.expr) = IntBinaryExprNode::alloc((yyvsp[-1].i), (yyvsp[-2].expr), (yyvsp[0].expr)); }
#line 2233 "CMDgram.cc"
    break;

  case 73: /* expr: expr '&' expr  */
#line 361 "CMDgram.y"
      { (yyval.expr) = IntBinaryExprNode::alloc((yyvsp[-1].i), (yyvsp[-2].expr), (yyvsp[0].expr)); }
#line 2239 "CMDgram.cc"
    break;

  case 74: /* expr: expr '|' expr  */
#line 363 "CMDgram.y"
      { (yyval.expr) = IntBinaryExprNode::alloc((yyvsp[-1].i), (yyvsp[-2].expr), (yyvsp[0].expr)); }
#line 2245 "CMDgram.cc"
    break;

  case 75: /* expr: expr '+' expr  */
#line 365 "CMDgram.y"
      { (yyval.expr) = FloatBinaryExprNode::alloc((yyvsp[-1].i), (yyvsp[-2].expr), (yyvsp[0].expr)); }
#line 2251 "CMDgram.cc"
    break;

  case 76: /* expr: expr '-' expr  */
#line 367 "CMDgram.y"
      { (yyval.expr) = FloatBinaryExprNode::alloc((yyvsp[-1].i), (yyvsp[-2].expr), (yyvsp[0].expr)); }
#line 2257 "CMDgram.cc"
    break;

  case 77: /* expr: expr '*' expr  */
#line 369 "CMDgram.y"
      { (yyval.expr) = FloatBinaryExprNode::alloc((yyvsp[-1].i), (yyvsp[-2].expr), (yyvsp[0].expr)); }
#line 2263 "CMDgram.cc"
    break;

  case 78: /* expr: expr '/' expr  */
#line 371 "CMDgram.y"
      { (yyval.expr) = FloatBinaryExprNode::alloc((yyvsp[-1].i), (yyvsp[-2].expr), (yyvsp[0].expr)); }
#line 2269 "CMDgram.cc"
    break;

  case 79: /* expr: '-' expr  */
#line 373 "CMDgram.y"
      { (yyval.expr) = FloatUnaryExprNode::alloc((yyvsp[-1].i), (yyvsp[0].expr)); }
#line 2275 "CMDgram.cc"
    break;

  case 80: /* expr: '*' expr  */
#line 375 "CMDgram.y"
      { (yyval.expr) = TTagDerefNode::alloc((yyvsp[0].expr)); }
#line 2281 "CMDgram.cc"
    break;

  case 81: /* expr: TTAG  */
#line 377 "CMDgram.y"
      { (yyval.expr) = TTagExprNode::alloc((yyvsp[0].s)); }
#line 2287 "CMDgram.cc"
    break;

  case 82: /* expr: expr '?' expr ':' expr  */
#line 379 "CMDgram.y"
      { (yyval.expr) = ConditionalExprNode::alloc((yyvsp[-4].expr), (yyvsp[-2].expr), (yyvsp[0].expr)); }
#line 2293 "CMDgram.cc"
    break;

  case 83: /* expr: expr '<' expr  */
#line 381 "CMDgram.y"
      { (yyval.expr) = IntBinaryExprNode::alloc((yyvsp[-1].i), (yyvsp[-2].expr), (yyvsp[0].expr)); }
#line 2299 "CMDgram.cc"
    break;

  case 84: /* expr: expr '>' expr  */
#line 383 "CMDgram.y"
      { (yyval.expr) = IntBinaryExprNode::alloc((yyvsp[-1].i), (yyvsp[-2].expr), (yyvsp[0].expr)); }
#line 2305 "CMDgram.cc"
    break;

  case 85: /* expr: expr opGE expr  */
#line 385 "CMDgram.y"
      { (yyval.expr) = IntBinaryExprNode::alloc((yyvsp[-1].i), (yyvsp[-2].expr), (yyvsp[0].expr)); }
#line 2311 "CMDgram.cc"
    break;

  case 86: /* expr: expr opLE expr  */
#line 387 "CMDgram.y"
      { (yyval.expr) = IntBinaryExprNode::alloc((yyvsp[-1].i), (yyvsp[-2].expr), (yyvsp[0].expr)); }
#line 2317 "CMDgram.cc"
    break;

  case 87: /* expr: expr opEQ expr  */
#line 389 "CMDgram.y"
      { (yyval.expr) = IntBinaryExprNode::alloc((yyvsp[-1].i), (yyvsp[-2].expr), (yyvsp[0].expr)); }
#line 2323 "CMDgram.cc"
    break;

  case 88: /* expr: expr opNE expr  */
#line 391 "CMDgram.y"
      { (yyval.expr) = IntBinaryExprNode::alloc((yyvsp[-1].i), (yyvsp[-2].expr), (yyvsp[0].expr)); }
#line 2329 "CMDgram.cc"
    break;

  case 89: /* expr: expr opOR expr  */
#line 393 "CMDgram.y"
      { (yyval.expr) = IntBinaryExprNode::alloc((yyvsp[-1].i), (yyvsp[-2].expr), (yyvsp[0].expr)); }
#line 2335 "CMDgram.cc"
    break;

  case 90: /* expr: expr opSHL expr  */
#line 395 "CMDgram.y"
      { (yyval.expr) = IntBinaryExprNode::alloc((yyvsp[-1].i), (yyvsp[-2].expr), (yyvsp[0].expr)); }
#line 2341 "CMDgram.cc"
    break;

  case 91: /* expr: expr opSHR expr  */
#line 397 "CMDgram.y"
      { (yyval.expr) = IntBinaryExprNode::alloc((yyvsp[-1].i), (yyvsp[-2].expr), (yyvsp[0].expr)); }
#line 2347 "CMDgram.cc"
    break;

  case 92: /* expr: expr opAND expr  */
#line 399 "CMDgram.y"
      { (yyval.expr) = IntBinaryExprNode::alloc((yyvsp[-1].i), (yyvsp[-2].expr), (yyvsp[0].expr)); }
#line 2353 "CMDgram.cc"
    break;

  case 93: /* expr: expr opSTREQ expr  */
#line 401 "CMDgram.y"
      { (yyval.expr) = StreqExprNode::alloc((yyvsp[-2].expr), (yyvsp[0].expr), true); }
#line 2359 "CMDgram.cc"
    break;

  case 94: /* expr: expr opSTRNE expr  */
#line 403 "CMDgram.y"
      { (yyval.expr) = StreqExprNode::alloc((yyvsp[-2].expr), (yyvsp[0].expr), false); }
#line 2365 "CMDgram.cc"
    break;

  case 95: /* expr: expr '@' expr  */
#line 405 "CMDgram.y"
      { (yyval.expr) = StrcatExprNode::alloc((yyvsp[-2].expr), (yyvsp[0].expr), (yyvsp[-1].i)); }
#line 2371 "CMDgram.cc"
    break;

  case 96: /* expr: expr opINSTANCE expr  */
#line 407 "CMDgram.y"
      { (yyval.expr) = InstanceOfExprNode::alloc((yyvsp[-2].expr), (yyvsp[0].expr)); }
#line 2377 "CMDgram.cc"
    break;

  case 97: /* expr: '!' expr  */
#line 409 "CMDgram.y"
      { (yyval.expr) = IntUnaryExprNode::alloc((yyvsp[-1].i), (yyvsp[0].expr)); }
#line 2383 "CMDgram.cc"
    break;

  case 98: /* expr: '~' expr  */
#line 411 "CMDgram.y"
      { (yyval.expr) = IntUnaryExprNode::alloc((yyvsp[-1].i), (yyvsp[0].expr)); }
#line 2389 "CMDgram.cc"
    break;

  case 99: /* expr: TAGATOM  */
#line 413 "CMDgram.y"
      { (yyval.expr) = StrConstNode::alloc((yyvsp[0].str), true); }
#line 2395 "CMDgram.cc"
    break;

  case 100: /* expr: FLTCONST  */
#line 415 "CMDgram.y"
      { (yyval.expr) = FloatNode::alloc((yyvsp[0].f)); }
#line 2401 "CMDgram.cc"
    break;

  case 101: /* expr: INTCONST  */
#line 417 "CMDgram.y"
      { (yyval.expr) = IntNode::alloc((yyvsp[0].i)); }
#line 2407 "CMDgram.cc"
    break;

  case 102: /* expr: rwBREAK  */
#line 419 "CMDgram.y"
      { (yyval.expr) = ConstantNode::alloc(StringTable->insert("break")); }
#line 2413 "CMDgram.cc"
    break;

  case 103: /* expr: slot_acc  */
#line 421 "CMDgram.y"
      { (yyval.expr) = SlotAccessNode::alloc((yyvsp[0].slot).object, (yyvsp[0].slot).array, (yyvsp[0].slot).slotName); }
#line 2419 "CMDgram.cc"
    break;

  case 104: /* expr: IDENT  */
#line 423 "CMDgram.y"
      { (yyval.expr) = ConstantNode::alloc((yyvsp[0].s)); }
#line 2425 "CMDgram.cc"
    break;

  case 105: /* expr: STRATOM  */
#line 425 "CMDgram.y"
      { (yyval.expr) = StrConstNode::alloc((yyvsp[0].str), false); }
#line 2431 "CMDgram.cc"
    break;

  case 106: /* expr: VAR  */
#line 427 "CMDgram.y"
      { (yyval.expr) = (ExprNode*)VarNode::alloc((yyvsp[0].s), NULL); }
#line 2437 "CMDgram.cc"
    break;

  case 107: /* expr: VAR '[' aidx_expr ']'  */
#line 429 "CMDgram.y"
      { (yyval.expr) = (ExprNode*)VarNode::alloc((yyvsp[-3].s), (yyvsp[-1].expr)); }
#line 2443 "CMDgram.cc"
    break;

  case 108: /* slot_acc: expr '.' IDENT  */
#line 434 "CMDgram.y"
      { (yyval.slot).object = (yyvsp[-2].expr); (yyval.slot).slotName = (yyvsp[0].s); (yyval.slot).array = NULL; }
#line 2449 "CMDgram.cc"
    break;

  case 109: /* slot_acc: expr '.' IDENT '[' aidx_expr ']'  */
#line 436 "CMDgram.y"
      { (yyval.slot).object = (yyvsp[-5].expr); (yyval.slot).slotName = (yyvsp[-3].s); (yyval.slot).array = (yyvsp[-1].expr); }
#line 2455 "CMDgram.cc"
    break;

  case 110: /* class_name_expr: IDENT  */
#line 441 "CMDgram.y"
      { (yyval.expr) = ConstantNode::alloc((yyvsp[0].s)); }
#line 2461 "CMDgram.cc"
    break;

  case 111: /* class_name_expr: '(' expr ')'  */
#line 443 "CMDgram.y"
      { (yyval.expr) = (yyvsp[-1].expr); }
#line 2467 "CMDgram.cc"
    break;

  case 112: /* assign_op_struct: opPLUSPLUS  */
#line 448 "CMDgram.y"
      { (yyval.asn).token = '+'; (yyval.asn).expr = FloatNode::alloc(1); }
#line 2473 "CMDgram.cc"
    break;

  case 113: /* assign_op_struct: opMINUSMINUS  */
#line 450 "CMDgram.y"
      { (yyval.asn).token = '-'; (yyval.asn).expr = FloatNode::alloc(1); }
#line 2479 "CMDgram.cc"
    break;

  case 114: /* assign_op_struct: opPLASN expr  */
#line 452 "CMDgram.y"
      { (yyval.asn).token = '+'; (yyval.asn).expr = (yyvsp[0].expr); }
#line 2485 "CMDgram.cc"
    break;

  case 115: /* assign_op_struct: opMIASN expr  */
#line 454 "CMDgram.y"
      { (yyval.asn).token = '-'; (yyval.asn).expr = (yyvsp[0].expr); }
#line 2491 "CMDgram.cc"
    break;

  case 116: /* assign_op_struct: opMLASN expr  */
#line 456 "CMDgram.y"
      { (yyval.asn).token = '*'; (yyval.asn).expr = (yyvsp[0].expr); }
#line 2497 "CMDgram.cc"
    break;

  case 117: /* assign_op_struct: opDVASN expr  */
#line 458 "CMDgram.y"
      { (yyval.asn).token = '/'; (yyval.asn).expr = (yyvsp[0].expr); }
#line 2503 "CMDgram.cc"
    break;

  case 118: /* assign_op_struct: opMODASN expr  */
#line 460 "CMDgram.y"
      { (yyval.asn).token = '%'; (yyval.asn).expr = (yyvsp[0].expr); }
#line 2509 "CMDgram.cc"
    break;

  case 119: /* assign_op_struct: opANDASN expr  */
#line 462 "CMDgram.y"
      { (yyval.asn).token = '&'; (yyval.asn).expr = (yyvsp[0].expr); }
#line 2515 "CMDgram.cc"
    break;

  case 120: /* assign_op_struct: opXORASN expr  */
#line 464 "CMDgram.y"
      { (yyval.asn).token = '^'; (yyval.asn).expr = (yyvsp[0].expr); }
#line 2521 "CMDgram.cc"
    break;

  case 121: /* assign_op_struct: opORASN expr  */
#line 466 "CMDgram.y"
      { (yyval.asn).token = '|'; (yyval.asn).expr = (yyvsp[0].expr); }
#line 2527 "CMDgram.cc"
    break;

  case 122: /* assign_op_struct: opSLASN expr  */
#line 468 "CMDgram.y"
      { (yyval.asn).token = opSHL; (yyval.asn).expr = (yyvsp[0].expr); }
#line 2533 "CMDgram.cc"
    break;

  case 123: /* assign_op_struct: opSRASN expr  */
#line 470 "CMDgram.y"
      { (yyval.asn).token = opSHR; (yyval.asn).expr = (yyvsp[0].expr); }
#line 2539 "CMDgram.cc"
    break;

  case 124: /* stmt_expr: funcall_expr  */
#line 475 "CMDgram.y"
      { (yyval.expr) = (yyvsp[0].expr); }
#line 2545 "CMDgram.cc"
    break;

  case 125: /* stmt_expr: object_decl  */
#line 477 "CMDgram.y"
      { (yyval.expr) = (yyvsp[0].od); }
#line 2551 "CMDgram.cc"
    break;

  case 126: /* stmt_expr: VAR '=' expr  */
#line 479 "CMDgram.y"
      { (yyval.expr) = AssignExprNode::alloc((yyvsp[-2].s), NULL, (yyvsp[0].expr)); }
#line 2557 "CMDgram.cc"
    break;

  case 127: /* stmt_expr: VAR '[' aidx_expr ']' '=' expr  */
#line 481 "CMDgram.y"
      { (yyval.expr) = AssignExprNode::alloc((yyvsp[-5].s), (yyvsp[-3].expr), (yyvsp[0].expr)); }
#line 2563 "CMDgram.cc"
    break;

  case 128: /* stmt_expr: VAR assign_op_struct  */
#line 483 "CMDgram.y"
      { (yyval.expr) = AssignOpExprNode::alloc((yyvsp[-1].s), NULL, (yyvsp[0].asn).expr, (yyvsp[0].asn).token); }
#line 2569 "CMDgram.cc"
    break;

  case 129: /* stmt_expr: VAR '[' aidx_expr ']' assign_op_struct  */
#line 485 "CMDgram.y"
      { (yyval.expr) = AssignOpExprNode::alloc((yyvsp[-4].s), (yyvsp[-2].expr), (yyvsp[0].asn).expr, (yyvsp[0].asn).token); }
#line 2575 "CMDgram.cc"
    break;

  case 130: /* stmt_expr: slot_acc assign_op_struct  */
#line 487 "CMDgram.y"
      { (yyval.expr) = SlotAssignOpNode::alloc((yyvsp[-1].slot).object, (yyvsp[-1].slot).slotName, (yyvsp[-1].slot).array, (yyvsp[0].asn).token, (yyvsp[0].asn).expr); }
#line 2581 "CMDgram.cc"
    break;

  case 131: /* stmt_expr: slot_acc '=' expr  */
#line 489 "CMDgram.y"
      { (yyval.expr) = SlotAssignNode::alloc((yyvsp[-2].slot).object, (yyvsp[-2].slot).array, (yyvsp[-2].slot).slotName, (yyvsp[0].expr)); }
#line 2587 "CMDgram.cc"
    break;

  case 132: /* stmt_expr: slot_acc '=' '{' expr_list '}'  */
#line 491 "CMDgram.y"
      { (yyval.expr) = SlotAssignNode::alloc((yyvsp[-4].slot).object, (yyvsp[-4].slot).array, (yyvsp[-4].slot).slotName, (yyvsp[-1].expr)); }
#line 2593 "CMDgram.cc"
    break;

  case 133: /* funcall_expr: IDENT '(' expr_list_decl ')'  */
#line 496 "CMDgram.y"
     { (yyval.expr) = FuncCallExprNode::alloc((yyvsp[-3].s), NULL, (yyvsp[-1].expr), false); }
#line 2599 "CMDgram.cc"
    break;

  case 134: /* funcall_expr: IDENT opCOLONCOLON IDENT '(' expr_list_decl ')'  */
#line 498 "CMDgram.y"
     { (yyval.expr) = FuncCallExprNode::alloc((yyvsp[-3].s), (yyvsp[-5].s), (yyvsp[-1].expr), false); }
#line 2605 "CMDgram.cc"
    break;

  case 135: /* funcall_expr: expr '.' IDENT '(' expr_list_decl ')'  */
#line 500 "CMDgram.y"
      { (yyvsp[-5].expr)->append((yyvsp[-1].expr)); (yyval.expr) = FuncCallExprNode::alloc((yyvsp[-3].s), NULL, (yyvsp[-5].expr), true); }
#line 2611 "CMDgram.cc"
    break;

  case 136: /* expr_list_decl: %empty  */
#line 505 "CMDgram.y"
      { (yyval.expr) = NULL; }
#line 2617 "CMDgram.cc"
    break;

  case 137: /* expr_list_decl: expr_list  */
#line 507 "CMDgram.y"
      { (yyval.expr) = (yyvsp[0].expr); }
#line 2623 "CMDgram.cc"
    break;

  case 138: /* expr_list: expr  */
#line 512 "CMDgram.y"
      { (yyval.expr) = (yyvsp[0].expr); }
#line 2629 "CMDgram.cc"
    break;

  case 139: /* expr_list: expr_list ',' expr  */
#line 514 "CMDgram.y"
      { ((yyvsp[-2].expr))->append((yyvsp[0].expr)); (yyval.expr) = (yyvsp[-2].expr); }
#line 2635 "CMDgram.cc"
    break;

  case 140: /* slot_assign_list: slot_assign  */
#line 519 "CMDgram.y"
      { (yyval.slist) = (yyvsp[0].slist); }
#line 2641 "CMDgram.cc"
    break;

  case 141: /* slot_assign_list: slot_assign_list slot_assign  */
#line 521 "CMDgram.y"
      { (yyvsp[-1].slist)->append((yyvsp[0].slist)); (yyval.slist) = (yyvsp[-1].slist); }
#line 2647 "CMDgram.cc"
    break;

  case 142: /* slot_assign: IDENT '=' expr ';'  */
#line 526 "CMDgram.y"
      { (yyval.slist) = SlotAssignNode::alloc(NULL, NULL, (yyvsp[-3].s), (yyvsp[-1].expr)); }
#line 2653 "CMDgram.cc"
    break;

  case 143: /* slot_assign: rwDATABLOCK '=' expr ';'  */
#line 528 "CMDgram.y"
      { (yyval.slist) = SlotAssignNode::alloc(NULL, NULL, StringTable->insert("datablock"), (yyvsp[-1].expr)); }
#line 2659 "CMDgram.cc"
    break;

  case 144: /* slot_assign: IDENT '[' aidx_expr ']' '=' expr ';'  */
#line 530 "CMDgram.y"
      { (yyval.slist) = SlotAssignNode::alloc(NULL, (yyvsp[-4].expr), (yyvsp[-6].s), (yyvsp[-1].expr)); }
#line 2665 "CMDgram.cc"
    break;

  case 145: /* aidx_expr: expr  */
#line 535 "CMDgram.y"
      { (yyval.expr) = (yyvsp[0].expr); }
#line 2671 "CMDgram.cc"
    break;

  case 146: /* aidx_expr: aidx_expr ',' expr  */
#line 537 "CMDgram.y"
      { (yyval.expr) = CommaCatExprNode::alloc((yyvsp[-2].expr), (yyvsp[0].expr)); }
#line 2677 "CMDgram.cc"
    break;


#line 2681 "CMDgram.cc"

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

#line 539 "CMDgram.y"


