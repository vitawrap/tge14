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
  YYSYMBOL_rwCVLSTART = 5,                 /* rwCVLSTART  */
  YYSYMBOL_rwBREAK = 6,                    /* rwBREAK  */
  YYSYMBOL_rwELSE = 7,                     /* rwELSE  */
  YYSYMBOL_rwCONTINUE = 8,                 /* rwCONTINUE  */
  YYSYMBOL_rwIF = 9,                       /* rwIF  */
  YYSYMBOL_rwRETURN = 10,                  /* rwRETURN  */
  YYSYMBOL_rwWHILE = 11,                   /* rwWHILE  */
  YYSYMBOL_rwDO = 12,                      /* rwDO  */
  YYSYMBOL_rwDEFAULT = 13,                 /* rwDEFAULT  */
  YYSYMBOL_rwNAMESPACE = 14,               /* rwNAMESPACE  */
  YYSYMBOL_rwFOR = 15,                     /* rwFOR  */
  YYSYMBOL_rwDATABLOCK = 16,               /* rwDATABLOCK  */
  YYSYMBOL_rwSWITCH = 17,                  /* rwSWITCH  */
  YYSYMBOL_rwCASE = 18,                    /* rwCASE  */
  YYSYMBOL_rwSWITCHSTR = 19,               /* rwSWITCHSTR  */
  YYSYMBOL_rwCASEOR = 20,                  /* rwCASEOR  */
  YYSYMBOL_rwPACKAGE = 21,                 /* rwPACKAGE  */
  YYSYMBOL_ILLEGAL_TOKEN = 22,             /* ILLEGAL_TOKEN  */
  YYSYMBOL_INTCONST = 23,                  /* INTCONST  */
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
  YYSYMBOL_opRANGE = 72,                   /* opRANGE  */
  YYSYMBOL_opCOLONCOLON = 73,              /* opCOLONCOLON  */
  YYSYMBOL_74_ = 74,                       /* '['  */
  YYSYMBOL_opMDASN = 75,                   /* opMDASN  */
  YYSYMBOL_opNDASN = 76,                   /* opNDASN  */
  YYSYMBOL_opNTASN = 77,                   /* opNTASN  */
  YYSYMBOL_78_ = 78,                       /* '?'  */
  YYSYMBOL_opCAT = 79,                     /* opCAT  */
  YYSYMBOL_opSTRNE = 80,                   /* opSTRNE  */
  YYSYMBOL_opFORGIVE = 81,                 /* opFORGIVE  */
  YYSYMBOL_opINSTANCE = 82,                /* opINSTANCE  */
  YYSYMBOL_UNARY = 83,                     /* UNARY  */
  YYSYMBOL_opIDXSTART = 84,                /* opIDXSTART  */
  YYSYMBOL_85_ = 85,                       /* ']'  */
  YYSYMBOL_YYACCEPT = 86,                  /* $accept  */
  YYSYMBOL_start = 87,                     /* start  */
  YYSYMBOL_decl_list = 88,                 /* decl_list  */
  YYSYMBOL_decl = 89,                      /* decl  */
  YYSYMBOL_package_decl = 90,              /* package_decl  */
  YYSYMBOL_fn_decl_list = 91,              /* fn_decl_list  */
  YYSYMBOL_statement_list = 92,            /* statement_list  */
  YYSYMBOL_stmt = 93,                      /* stmt  */
  YYSYMBOL_fn_decl_stmt = 94,              /* fn_decl_stmt  */
  YYSYMBOL_var_list_decl = 95,             /* var_list_decl  */
  YYSYMBOL_var_list = 96,                  /* var_list  */
  YYSYMBOL_datablock_decl = 97,            /* datablock_decl  */
  YYSYMBOL_object_decl = 98,               /* object_decl  */
  YYSYMBOL_parent_block = 99,              /* parent_block  */
  YYSYMBOL_object_name = 100,              /* object_name  */
  YYSYMBOL_object_args = 101,              /* object_args  */
  YYSYMBOL_object_declare_block = 102,     /* object_declare_block  */
  YYSYMBOL_object_decl_list = 103,         /* object_decl_list  */
  YYSYMBOL_stmt_block = 104,               /* stmt_block  */
  YYSYMBOL_switch_stmt = 105,              /* switch_stmt  */
  YYSYMBOL_case_block = 106,               /* case_block  */
  YYSYMBOL_case_expr = 107,                /* case_expr  */
  YYSYMBOL_if_stmt = 108,                  /* if_stmt  */
  YYSYMBOL_while_stmt = 109,               /* while_stmt  */
  YYSYMBOL_for_stmt = 110,                 /* for_stmt  */
  YYSYMBOL_expression_stmt = 111,          /* expression_stmt  */
  YYSYMBOL_expr = 112,                     /* expr  */
  YYSYMBOL_slot_acc = 113,                 /* slot_acc  */
  YYSYMBOL_class_name_expr = 114,          /* class_name_expr  */
  YYSYMBOL_assign_op_struct = 115,         /* assign_op_struct  */
  YYSYMBOL_stmt_expr = 116,                /* stmt_expr  */
  YYSYMBOL_funcall_expr = 117,             /* funcall_expr  */
  YYSYMBOL_expr_list_decl = 118,           /* expr_list_decl  */
  YYSYMBOL_expr_list = 119,                /* expr_list  */
  YYSYMBOL_slot_assign_list = 120,         /* slot_assign_list  */
  YYSYMBOL_slot_assign = 121,              /* slot_assign  */
  YYSYMBOL_aidx_expr = 122                 /* aidx_expr  */
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
#define YYLAST   2439

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  86
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  37
/* YYNRULES -- Number of rules.  */
#define YYNRULES  145
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  322

/* YYMAXUTOK -- Last valid token kind.  */
#define YYMAXUTOK   315


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
      33,    35,    34,    78,    50,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,    74,     2,    85,    47,     2,     2,     2,     2,     2,
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
      67,    68,    69,    70,    71,    72,    73,    75,    76,    77,
      79,    80,    81,    82,    83,    84
};

#if CMDDEBUG
/* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_int16 yyrline[] =
{
       0,   148,   148,   154,   155,   160,   162,   164,   169,   174,
     176,   182,   183,   188,   189,   190,   191,   192,   193,   195,
     197,   199,   201,   206,   208,   214,   215,   220,   222,   227,
     229,   234,   236,   242,   243,   249,   250,   256,   257,   263,
     264,   266,   268,   273,   275,   280,   282,   287,   289,   294,
     296,   298,   303,   305,   310,   312,   317,   319,   324,   326,
     328,   330,   332,   334,   336,   338,   343,   348,   350,   352,
     354,   356,   358,   360,   362,   364,   366,   368,   370,   372,
     374,   376,   378,   380,   382,   384,   386,   388,   390,   392,
     394,   396,   398,   400,   402,   404,   406,   408,   410,   412,
     414,   416,   418,   420,   422,   424,   426,   428,   433,   435,
     440,   442,   447,   449,   451,   453,   455,   457,   459,   461,
     463,   465,   467,   469,   474,   476,   478,   480,   482,   484,
     486,   488,   493,   495,   497,   503,   504,   509,   511,   516,
     518,   523,   525,   527,   532,   534
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
  "rwDECLARE", "rwCVLSTART", "rwBREAK", "rwELSE", "rwCONTINUE", "rwIF",
  "rwRETURN", "rwWHILE", "rwDO", "rwDEFAULT", "rwNAMESPACE", "rwFOR",
  "rwDATABLOCK", "rwSWITCH", "rwCASE", "rwSWITCHSTR", "rwCASEOR",
  "rwPACKAGE", "ILLEGAL_TOKEN", "INTCONST", "VAR", "IDENT", "STRATOM",
  "TAGATOM", "FLTCONST", "'+'", "'-'", "'*'", "'/'", "'<'", "'>'", "'='",
  "'.'", "'|'", "'&'", "'%'", "'('", "')'", "','", "':'", "';'", "'{'",
  "'}'", "'^'", "'~'", "'!'", "'@'", "opMINUSMINUS", "opPLUSPLUS", "opSHL",
  "opSHR", "opPLASN", "opMIASN", "opMLASN", "opDVASN", "opMODASN",
  "opANDASN", "opXORASN", "opORASN", "opSLASN", "opSRASN", "opEQ", "opNE",
  "opGE", "opLE", "opAND", "opOR", "opSTREQ", "opRANGE", "opCOLONCOLON",
  "'['", "opMDASN", "opNDASN", "opNTASN", "'?'", "opCAT", "opSTRNE",
  "opFORGIVE", "opINSTANCE", "UNARY", "opIDXSTART", "']'", "$accept",
  "start", "decl_list", "decl", "package_decl", "fn_decl_list",
  "statement_list", "stmt", "fn_decl_stmt", "var_list_decl", "var_list",
  "datablock_decl", "object_decl", "parent_block", "object_name",
  "object_args", "object_declare_block", "object_decl_list", "stmt_block",
  "switch_stmt", "case_block", "case_expr", "if_stmt", "while_stmt",
  "for_stmt", "expression_stmt", "expr", "slot_acc", "class_name_expr",
  "assign_op_struct", "stmt_expr", "funcall_expr", "expr_list_decl",
  "expr_list", "slot_assign_list", "slot_assign", "aidx_expr", YY_NULLPTR
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

#define YYTABLE_NINF (-67)

#define yytable_value_is_error(Yyn) \
  0

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int16 yypact[] =
{
    -243,    16,  1904,  -243,     1,    55,  2332,   -16,   -15,    -8,
    2169,     8,  1977,    36,    22,    44,    47,    64,  -243,  2331,
     -22,  -243,  -243,  -243,  2332,  2332,  2332,  2332,  -243,  -243,
    -243,  -243,  -243,  -243,  -243,  -243,  -243,  -243,    46,  1486,
    2361,    48,  -243,    -6,  -243,  2332,    53,  -243,  1486,  -243,
      51,    56,  -243,  -243,  2332,  -243,   364,  2332,  -243,  -243,
      92,  2180,    65,  2332,  2332,    61,  2332,  -243,  -243,  2332,
    2332,  2332,  2332,  2332,  2332,  2332,  2332,  2332,  2332,  2332,
    -243,  2332,    79,   -19,   455,   -19,   -19,  -243,  2332,  2332,
    2332,  2332,  2332,  2332,    83,  2332,  2332,  2332,  2332,  2332,
    2332,  2332,  2332,  2332,  2332,  2332,  2332,  2332,  2332,  2332,
    2332,  2332,  2332,  2332,  2332,  -243,    97,   102,   534,  2332,
    -243,  2332,   590,  -243,   646,  2004,    89,  2210,   702,   107,
     758,   814,   130,  1486,  1486,  1486,  1486,  1486,  1486,  1486,
    1486,  1486,  1486,  1486,  1486,   -31,    95,    98,  -243,    38,
      38,   -19,   -19,   199,   199,   -25,  1710,  1822,   -19,  1766,
     444,     7,     7,    -9,    -9,   199,   199,  1654,  1598,   444,
     870,   444,   444,   444,    81,  1486,  -243,    99,   100,   101,
    -243,    96,  1486,  1486,  1977,  1977,  -243,  -243,  2332,   220,
     926,  2221,    96,   109,   110,     9,  -243,  2332,  2375,  -243,
    2332,  2332,  2332,  2332,  2332,  -243,   111,   119,    97,   120,
     115,   137,  -243,   982,  1977,  1038,  2251,  2278,  1094,   117,
     146,   146,   129,  -243,  1486,  2332,  -243,   139,   140,   -29,
    1542,   138,  -243,  -243,   143,  -243,  2332,   145,  1977,  -243,
    -243,  1977,  1977,  1150,  1977,  1206,  2305,   133,  2332,   141,
     144,  -243,  1486,  -243,  -243,  -243,  -243,  2050,   134,    56,
     148,  -243,  -243,  -243,  1977,  -243,  1977,  1977,  1262,    84,
      59,  1486,  -243,  -243,  -243,  -243,    15,  -243,  -243,  -243,
    1977,   154,   -21,   150,    91,  -243,  2332,  -243,  2096,   151,
     152,   192,    15,  -243,  2332,  2332,  2332,  -243,   153,  -243,
    1486,  1950,  -243,  -243,  -243,   155,   192,  1318,  1374,    -7,
    -243,   157,  -243,  -243,  -243,  -243,   166,  -243,  2332,  2142,
    1430,  -243
};

/* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE does not specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       3,     0,     2,     1,     0,     0,   135,   102,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   101,   106,
     104,   105,    99,   100,     0,     0,     0,     0,     4,     7,
       5,     6,    16,   125,    17,    13,    14,    15,     0,     0,
     103,    67,   124,     0,   110,     0,     0,   102,   137,    67,
       0,   136,    18,    19,     0,    20,     0,     0,    11,    46,
       0,     0,     0,     0,     0,     0,     0,   113,   112,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     128,   135,     0,    78,     0,    98,    97,    22,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   130,    25,     0,     0,    35,
      69,     0,     0,    21,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   126,   114,   115,   116,   117,   118,   119,
     120,   121,   122,   123,   144,     0,     0,     0,    68,    74,
      75,    76,    77,    80,    81,   108,    73,    72,    71,    70,
      93,    87,    88,    84,    85,    82,    83,    89,    86,    90,
       0,    91,    92,    94,     0,   131,    27,     0,    26,     0,
     111,    33,    36,   138,     0,     0,    45,    12,     0,     0,
       0,     0,    33,     0,     0,     0,     9,     0,   107,   132,
     135,   135,     0,     0,     0,    95,     0,     0,    25,     0,
      37,    54,    56,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    10,   145,     0,   129,     0,     0,     0,
      79,     0,    11,    28,     0,    34,     0,     0,     0,    57,
      65,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     8,   127,   133,   134,   109,    96,     0,     0,    38,
      32,    55,    64,    63,     0,    61,     0,     0,     0,     0,
       0,    52,    47,    48,    23,    11,    39,    62,    60,    59,
       0,     0,     0,     0,     0,   139,     0,    11,     0,     0,
       0,    41,    40,    58,     0,     0,     0,    30,     0,   140,
      53,    49,    24,    43,    31,     0,    42,     0,     0,     0,
      29,     0,    51,    44,   142,   141,     0,    11,     0,    50,
       0,   143
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -243,  -243,  -243,  -243,  -243,  -243,  -223,    -1,  -127,     2,
    -243,  -243,  -210,    10,  -243,  -243,  -243,   -81,  -181,  -243,
    -213,  -243,  -243,  -243,  -243,  -243,   265,  -243,  -243,   -38,
      -2,  -243,   -75,   -23,   -62,  -242,  -195
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
       0,     1,     2,    28,    29,   195,   125,    59,    31,   177,
     178,    32,    33,   210,   181,   237,   290,   291,    60,    34,
     249,   270,    35,    36,    37,    38,    39,    40,    46,    80,
      49,    42,    50,    51,   284,   285,   145
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      41,    30,   115,   211,   212,   196,   146,   229,   250,   257,
      41,   197,     4,   197,   295,   201,     3,    94,    81,     5,
      88,    89,    90,    91,    92,    93,    43,    94,    52,    53,
      97,   281,    54,   240,   116,   197,    88,    89,    90,    91,
     282,    99,   299,    94,   100,   101,    97,    62,    57,   202,
     299,    82,   288,   296,   198,   222,   255,   261,   104,   105,
     262,   263,   108,   265,   301,   113,   289,   117,   223,    90,
      91,   110,   111,   112,    94,   113,    61,    97,   316,   286,
      44,   305,   289,   277,    63,   278,   279,    64,   312,    65,
      87,   113,   -66,   119,   319,    45,   305,   120,   121,   293,
     281,   309,   287,   126,   147,   129,   132,   281,   155,   282,
      88,    89,    90,    91,    92,    93,   282,    94,    95,    96,
      97,   176,   113,    41,   187,   227,   228,   179,    98,   188,
     283,    99,   192,     4,   100,   101,   199,   298,   200,   209,
     206,   208,   207,   233,   238,   235,   102,   103,   104,   105,
     106,   107,   108,   204,   220,   221,   232,   236,   247,   109,
     226,   110,   111,   112,   248,   113,   205,    88,    89,    90,
      91,    92,    93,   251,    94,    95,    96,    97,   269,   275,
     253,   254,    41,    41,   258,    98,   260,   272,    99,   294,
     273,   100,   101,   276,   297,   303,     5,   310,   304,   313,
     317,   318,   219,   102,   103,   104,   105,   106,   107,   108,
     234,   306,    41,   259,   292,     0,   109,     0,   110,   111,
     112,     0,   113,   256,     5,     6,    47,     0,    88,    89,
      90,    91,     0,     0,     0,    94,    41,     0,    97,    41,
      41,     0,    41,    18,    19,    20,    21,    22,    23,    99,
      24,     0,   100,   101,     0,    41,   187,     0,     0,     0,
      25,   214,    41,     0,    41,    41,     0,     0,    26,    27,
     108,    48,     0,     0,     0,    56,     0,     0,    41,   110,
     111,   112,     0,   113,     0,     0,    41,   187,     0,    83,
      84,    85,    86,     0,     0,     0,     0,     0,     0,    41,
     187,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     118,     0,     0,     0,     0,     0,     0,    41,   187,   122,
       0,     0,   124,     0,     0,     0,   128,     0,   130,   131,
       0,   133,     0,     0,   134,   135,   136,   137,   138,   139,
     140,   141,   142,   143,   144,     0,    48,     0,     0,     0,
       0,     0,     0,   149,   150,   151,   152,   153,   154,     0,
     156,   157,   158,   159,   160,   161,   162,   163,   164,   165,
     166,   167,   168,   169,   170,   171,   172,   173,   174,   175,
       0,     0,     0,     0,   182,     0,   183,     0,     0,     0,
       0,     0,   190,    88,    89,    90,    91,    92,    93,     0,
      94,    95,    96,    97,     0,     0,     0,     0,   123,     0,
       0,    98,     0,     0,    99,     0,     0,   100,   101,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   102,
     103,   104,   105,   106,   107,   108,     0,     0,     0,     0,
       0,     0,   109,     0,   110,   111,   112,     0,   113,     0,
       0,     0,     0,   213,   215,     0,   218,     0,     0,     0,
       0,     0,   224,     0,     0,    48,    48,   144,   230,   231,
       0,     0,     0,    88,    89,    90,    91,     0,     0,     0,
      94,   243,   245,    97,    88,    89,    90,    91,    92,    93,
     252,    94,    95,    96,    97,     0,   148,   100,   101,     0,
       0,    48,    98,     0,     0,    99,     0,     0,   100,   101,
       0,   268,     0,   271,     0,     0,     0,     0,     0,     0,
     102,   103,   104,   105,   106,   107,   108,     0,   113,     0,
       0,     0,     0,   109,     0,   110,   111,   112,     0,   113,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   300,     0,     0,     0,     0,     0,     0,     0,   307,
     308,   144,     0,    88,    89,    90,    91,    92,    93,     0,
      94,    95,    96,    97,     0,   180,     0,     0,     0,     0,
       0,    98,     0,   320,    99,     0,     0,   100,   101,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   102,
     103,   104,   105,   106,   107,   108,     0,     0,     0,     0,
       0,     0,   109,     0,   110,   111,   112,     0,   113,    88,
      89,    90,    91,    92,    93,     0,    94,    95,    96,    97,
       0,   184,     0,     0,     0,     0,     0,    98,     0,     0,
      99,     0,     0,   100,   101,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   102,   103,   104,   105,   106,
     107,   108,     0,     0,     0,     0,     0,     0,   109,     0,
     110,   111,   112,     0,   113,    88,    89,    90,    91,    92,
      93,     0,    94,    95,    96,    97,     0,   185,     0,     0,
       0,     0,     0,    98,     0,     0,    99,     0,     0,   100,
     101,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   102,   103,   104,   105,   106,   107,   108,     0,     0,
       0,     0,     0,     0,   109,     0,   110,   111,   112,     0,
     113,    88,    89,    90,    91,    92,    93,     0,    94,    95,
      96,    97,     0,     0,     0,     0,   191,     0,     0,    98,
       0,     0,    99,     0,     0,   100,   101,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   102,   103,   104,
     105,   106,   107,   108,     0,     0,     0,     0,     0,     0,
     109,     0,   110,   111,   112,     0,   113,    88,    89,    90,
      91,    92,    93,     0,    94,    95,    96,    97,     0,   193,
       0,     0,     0,     0,     0,    98,     0,     0,    99,     0,
       0,   100,   101,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   102,   103,   104,   105,   106,   107,   108,
       0,     0,     0,     0,     0,     0,   109,     0,   110,   111,
     112,     0,   113,    88,    89,    90,    91,    92,    93,     0,
      94,    95,    96,    97,     0,   194,     0,     0,     0,     0,
       0,    98,     0,     0,    99,     0,     0,   100,   101,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   102,
     103,   104,   105,   106,   107,   108,     0,     0,     0,     0,
       0,     0,   109,     0,   110,   111,   112,     0,   113,    88,
      89,    90,    91,    92,    93,     0,    94,    95,    96,    97,
       0,     0,     0,   203,     0,     0,     0,    98,     0,     0,
      99,     0,     0,   100,   101,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   102,   103,   104,   105,   106,
     107,   108,     0,     0,     0,     0,     0,     0,   109,     0,
     110,   111,   112,     0,   113,    88,    89,    90,    91,    92,
      93,     0,    94,    95,    96,    97,     0,     0,     0,     0,
     216,     0,     0,    98,     0,     0,    99,     0,     0,   100,
     101,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   102,   103,   104,   105,   106,   107,   108,     0,     0,
       0,     0,     0,     0,   109,     0,   110,   111,   112,     0,
     113,    88,    89,    90,    91,    92,    93,     0,    94,    95,
      96,    97,     0,   239,     0,     0,     0,     0,     0,    98,
       0,     0,    99,     0,     0,   100,   101,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   102,   103,   104,
     105,   106,   107,   108,     0,     0,     0,     0,     0,     0,
     109,     0,   110,   111,   112,     0,   113,    88,    89,    90,
      91,    92,    93,     0,    94,    95,    96,    97,     0,   241,
       0,     0,     0,     0,     0,    98,     0,     0,    99,     0,
       0,   100,   101,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   102,   103,   104,   105,   106,   107,   108,
       0,     0,     0,     0,     0,     0,   109,     0,   110,   111,
     112,     0,   113,    88,    89,    90,    91,    92,    93,     0,
      94,    95,    96,    97,     0,     0,     0,     0,   246,     0,
       0,    98,     0,     0,    99,     0,     0,   100,   101,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   102,
     103,   104,   105,   106,   107,   108,     0,     0,     0,     0,
       0,     0,   109,     0,   110,   111,   112,     0,   113,    88,
      89,    90,    91,    92,    93,     0,    94,    95,    96,    97,
       0,   264,     0,     0,     0,     0,     0,    98,     0,     0,
      99,     0,     0,   100,   101,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   102,   103,   104,   105,   106,
     107,   108,     0,     0,     0,     0,     0,     0,   109,     0,
     110,   111,   112,     0,   113,    88,    89,    90,    91,    92,
      93,     0,    94,    95,    96,    97,     0,   266,     0,     0,
       0,     0,     0,    98,     0,     0,    99,     0,     0,   100,
     101,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   102,   103,   104,   105,   106,   107,   108,     0,     0,
       0,     0,     0,     0,   109,     0,   110,   111,   112,     0,
     113,    88,    89,    90,    91,    92,    93,     0,    94,    95,
      96,    97,     0,   280,     0,     0,     0,     0,     0,    98,
       0,     0,    99,     0,     0,   100,   101,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   102,   103,   104,
     105,   106,   107,   108,     0,     0,     0,     0,     0,     0,
     109,     0,   110,   111,   112,     0,   113,    88,    89,    90,
      91,    92,    93,     0,    94,    95,    96,    97,     0,     0,
       0,     0,   314,     0,     0,    98,     0,     0,    99,     0,
       0,   100,   101,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   102,   103,   104,   105,   106,   107,   108,
       0,     0,     0,     0,     0,     0,   109,     0,   110,   111,
     112,     0,   113,    88,    89,    90,    91,    92,    93,     0,
      94,    95,    96,    97,     0,     0,     0,     0,   315,     0,
       0,    98,     0,     0,    99,     0,     0,   100,   101,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   102,
     103,   104,   105,   106,   107,   108,     0,     0,     0,     0,
       0,     0,   109,     0,   110,   111,   112,     0,   113,    88,
      89,    90,    91,    92,    93,     0,    94,    95,    96,    97,
       0,     0,     0,     0,   321,     0,     0,    98,     0,     0,
      99,     0,     0,   100,   101,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   102,   103,   104,   105,   106,
     107,   108,     0,     0,     0,     0,     0,     0,   109,     0,
     110,   111,   112,     0,   113,    88,    89,    90,    91,    92,
      93,     0,    94,    95,    96,    97,     0,     0,     0,     0,
       0,     0,     0,    98,     0,     0,    99,     0,     0,   100,
     101,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   102,   103,   104,   105,   106,   107,   108,     0,     0,
       0,     0,     0,     0,   109,     0,   110,   111,   112,     0,
     113,    88,    89,    90,    91,    92,    93,     0,    94,    95,
      96,    97,     0,     0,     0,     0,     0,     0,     0,    98,
       0,     0,    99,     0,     0,   100,   101,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   102,   103,   104,
     105,   106,   107,   108,     0,     0,     0,     0,     0,     0,
       0,     0,   110,   111,   112,     0,   113,    88,    89,    90,
      91,    92,    93,     0,    94,    95,    96,    97,     0,     0,
       0,     0,     0,     0,     0,    98,     0,     0,    99,     0,
       0,   100,   101,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   102,   103,   104,   105,   106,     0,   108,
       0,     0,     0,     0,     0,     0,     0,     0,   110,   111,
     112,     0,   113,    88,    89,    90,    91,    92,    93,     0,
      94,    95,    96,    97,     0,     0,     0,     0,     0,     0,
       0,    98,     0,     0,    99,     0,     0,   100,   101,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   102,
     103,   104,   105,     0,     0,   108,     0,     0,     0,     0,
       0,     0,     0,     0,   110,   111,   112,     0,   113,    88,
      89,    90,    91,    92,    93,     0,    94,     0,    96,    97,
       0,     0,     0,     0,     0,     0,     0,    98,     0,     0,
      99,     0,     0,   100,   101,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   102,   103,   104,   105,     0,
       0,   108,     0,     0,     0,     0,     0,     0,     0,     0,
     110,   111,   112,     0,   113,    88,    89,    90,    91,    92,
      93,     0,    94,     0,    96,    97,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    99,     0,     0,   100,
     101,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   102,   103,   104,   105,     0,     0,   108,     0,     0,
       0,     0,     0,     0,     0,     0,   110,   111,   112,     0,
     113,    88,    89,    90,    91,    92,    93,     0,    94,     0,
       0,    97,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    99,     0,     0,   100,   101,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   102,   103,   104,
     105,     0,     0,   108,     0,     0,     0,     0,     0,     0,
       0,     0,   110,   111,   112,     0,   113,     4,     5,     6,
       7,     0,     8,     9,    10,    11,    12,     0,     0,    13,
      14,    15,     0,    16,     0,    17,     0,    18,    19,    20,
      21,    22,    23,     0,    24,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    25,     0,     0,     0,     0,     0,
       0,     0,    26,    27,     5,     6,     7,     0,     8,     9,
      10,    11,    12,   311,     0,    13,    14,    15,   248,    16,
       0,     0,     0,    18,    19,    20,    21,    22,    23,     0,
      24,     5,     6,     7,     0,     8,     9,    10,    11,    12,
      25,     0,    13,    14,    15,     0,    16,     0,    26,    27,
      18,    19,    20,    21,    22,    23,     0,    24,     5,     6,
       7,     0,     8,     9,    10,    11,    12,    25,     0,    13,
      14,    15,    58,    16,     0,    26,    27,    18,    19,    20,
      21,    22,    23,     0,    24,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    25,     0,     0,     0,     0,     0,
     186,     0,    26,    27,     5,     6,     7,     0,     8,     9,
      10,    11,    12,     0,     0,    13,    14,    15,     0,    16,
       0,     0,     0,    18,    19,    20,    21,    22,    23,     0,
      24,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      25,     0,     0,     0,     0,     0,   274,     0,    26,    27,
       5,     6,     7,     0,     8,     9,    10,    11,    12,     0,
       0,    13,    14,    15,     0,    16,     0,     0,     0,    18,
      19,    20,    21,    22,    23,     0,    24,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    25,     0,     0,     0,
       0,     0,   302,     0,    26,    27,     5,     6,     7,     0,
       8,     9,    10,    11,    12,     0,     0,    13,    14,    15,
       0,    16,     0,     0,     0,    18,    19,    20,    21,    22,
      23,     0,    24,     5,     6,    47,     0,     0,     0,     0,
       0,     0,    25,     0,     5,     6,    47,     0,     0,     0,
      26,    27,    18,    19,    20,    21,    22,    23,     0,    24,
       0,     0,     0,    18,    19,    20,    21,    22,    23,    25,
      24,     0,     0,    55,     5,     6,    47,    26,    27,     0,
      25,     0,     0,     0,   127,     5,     6,    47,    26,    27,
       0,     0,     0,    18,    19,    20,    21,    22,    23,     0,
      24,     0,     0,     0,    18,    19,    20,    21,    22,    23,
      25,    24,     0,     0,   189,     5,     6,    47,    26,    27,
       0,    25,     0,     0,     0,   217,     0,     0,     0,    26,
      27,     0,     0,     0,    18,    19,    20,    21,    22,    23,
       0,    24,     5,     6,    47,     0,     0,     0,     0,     0,
       0,    25,   242,     0,     0,     0,     0,     0,     0,    26,
      27,    18,    19,    20,    21,    22,    23,     0,    24,     5,
       6,    47,     0,     0,     0,     0,     0,     0,    25,   244,
       0,     0,     0,     0,     0,     0,    26,    27,    18,    19,
      20,    21,    22,    23,     0,    24,     5,     6,    47,     0,
       0,     0,     0,     0,     0,    25,   267,     0,     0,     0,
       0,     0,     0,    26,    27,    18,    19,    20,    21,    22,
      23,     0,    24,     0,     0,     0,    66,     0,     0,     0,
       0,     0,    25,     0,     0,     0,     0,     0,     0,     0,
      26,    27,    67,    68,     0,     0,    69,    70,    71,    72,
      73,    74,    75,    76,    77,    78,   114,     0,     0,     0,
       0,     0,     0,     0,     0,    79,     0,     0,     0,     0,
     225,     0,    67,    68,     0,     0,    69,    70,    71,    72,
      73,    74,    75,    76,    77,    78,    67,    68,     0,     0,
      69,    70,    71,    72,    73,    74,    75,    76,    77,    78
};

static const yytype_int16 yycheck[] =
{
       2,     2,    40,   184,   185,   132,    81,   202,   221,   232,
      12,    42,     3,    42,    35,    40,     0,    36,    40,     4,
      29,    30,    31,    32,    33,    34,    25,    36,    44,    44,
      39,    16,    40,   214,    40,    42,    29,    30,    31,    32,
      25,    50,   284,    36,    53,    54,    39,    25,    40,    74,
     292,    73,   275,    74,    85,    46,    85,   238,    67,    68,
     241,   242,    71,   244,   287,    84,   276,    73,   195,    31,
      32,    80,    81,    82,    36,    84,    40,    39,    85,    20,
      25,   291,   292,   264,    40,   266,   267,    40,   301,    25,
      44,    84,    44,    40,   317,    40,   306,    46,    42,   280,
      16,   296,    43,    11,    25,    40,    45,    16,    25,    25,
      29,    30,    31,    32,    33,    34,    25,    36,    37,    38,
      39,    24,    84,   125,   125,   200,   201,    25,    47,    40,
      46,    50,    25,     3,    53,    54,    41,    46,    40,    43,
      41,    40,    42,    24,     7,    25,    65,    66,    67,    68,
      69,    70,    71,    72,    45,    45,    45,    42,    41,    78,
     198,    80,    81,    82,    18,    84,    85,    29,    30,    31,
      32,    33,    34,    44,    36,    37,    38,    39,    45,    45,
      41,    41,   184,   185,    41,    47,    41,    46,    50,    35,
      46,    53,    54,    45,    44,    44,     4,    44,    46,    44,
      43,    35,   192,    65,    66,    67,    68,    69,    70,    71,
     208,   292,   214,   236,   276,    -1,    78,    -1,    80,    81,
      82,    -1,    84,    85,     4,     5,     6,    -1,    29,    30,
      31,    32,    -1,    -1,    -1,    36,   238,    -1,    39,   241,
     242,    -1,   244,    23,    24,    25,    26,    27,    28,    50,
      30,    -1,    53,    54,    -1,   257,   257,    -1,    -1,    -1,
      40,    41,   264,    -1,   266,   267,    -1,    -1,    48,    49,
      71,     6,    -1,    -1,    -1,    10,    -1,    -1,   280,    80,
      81,    82,    -1,    84,    -1,    -1,   288,   288,    -1,    24,
      25,    26,    27,    -1,    -1,    -1,    -1,    -1,    -1,   301,
     301,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      45,    -1,    -1,    -1,    -1,    -1,    -1,   319,   319,    54,
      -1,    -1,    57,    -1,    -1,    -1,    61,    -1,    63,    64,
      -1,    66,    -1,    -1,    69,    70,    71,    72,    73,    74,
      75,    76,    77,    78,    79,    -1,    81,    -1,    -1,    -1,
      -1,    -1,    -1,    88,    89,    90,    91,    92,    93,    -1,
      95,    96,    97,    98,    99,   100,   101,   102,   103,   104,
     105,   106,   107,   108,   109,   110,   111,   112,   113,   114,
      -1,    -1,    -1,    -1,   119,    -1,   121,    -1,    -1,    -1,
      -1,    -1,   127,    29,    30,    31,    32,    33,    34,    -1,
      36,    37,    38,    39,    -1,    -1,    -1,    -1,    44,    -1,
      -1,    47,    -1,    -1,    50,    -1,    -1,    53,    54,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    65,
      66,    67,    68,    69,    70,    71,    -1,    -1,    -1,    -1,
      -1,    -1,    78,    -1,    80,    81,    82,    -1,    84,    -1,
      -1,    -1,    -1,   188,   189,    -1,   191,    -1,    -1,    -1,
      -1,    -1,   197,    -1,    -1,   200,   201,   202,   203,   204,
      -1,    -1,    -1,    29,    30,    31,    32,    -1,    -1,    -1,
      36,   216,   217,    39,    29,    30,    31,    32,    33,    34,
     225,    36,    37,    38,    39,    -1,    41,    53,    54,    -1,
      -1,   236,    47,    -1,    -1,    50,    -1,    -1,    53,    54,
      -1,   246,    -1,   248,    -1,    -1,    -1,    -1,    -1,    -1,
      65,    66,    67,    68,    69,    70,    71,    -1,    84,    -1,
      -1,    -1,    -1,    78,    -1,    80,    81,    82,    -1,    84,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   286,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   294,
     295,   296,    -1,    29,    30,    31,    32,    33,    34,    -1,
      36,    37,    38,    39,    -1,    41,    -1,    -1,    -1,    -1,
      -1,    47,    -1,   318,    50,    -1,    -1,    53,    54,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    65,
      66,    67,    68,    69,    70,    71,    -1,    -1,    -1,    -1,
      -1,    -1,    78,    -1,    80,    81,    82,    -1,    84,    29,
      30,    31,    32,    33,    34,    -1,    36,    37,    38,    39,
      -1,    41,    -1,    -1,    -1,    -1,    -1,    47,    -1,    -1,
      50,    -1,    -1,    53,    54,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    65,    66,    67,    68,    69,
      70,    71,    -1,    -1,    -1,    -1,    -1,    -1,    78,    -1,
      80,    81,    82,    -1,    84,    29,    30,    31,    32,    33,
      34,    -1,    36,    37,    38,    39,    -1,    41,    -1,    -1,
      -1,    -1,    -1,    47,    -1,    -1,    50,    -1,    -1,    53,
      54,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    65,    66,    67,    68,    69,    70,    71,    -1,    -1,
      -1,    -1,    -1,    -1,    78,    -1,    80,    81,    82,    -1,
      84,    29,    30,    31,    32,    33,    34,    -1,    36,    37,
      38,    39,    -1,    -1,    -1,    -1,    44,    -1,    -1,    47,
      -1,    -1,    50,    -1,    -1,    53,    54,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    65,    66,    67,
      68,    69,    70,    71,    -1,    -1,    -1,    -1,    -1,    -1,
      78,    -1,    80,    81,    82,    -1,    84,    29,    30,    31,
      32,    33,    34,    -1,    36,    37,    38,    39,    -1,    41,
      -1,    -1,    -1,    -1,    -1,    47,    -1,    -1,    50,    -1,
      -1,    53,    54,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    65,    66,    67,    68,    69,    70,    71,
      -1,    -1,    -1,    -1,    -1,    -1,    78,    -1,    80,    81,
      82,    -1,    84,    29,    30,    31,    32,    33,    34,    -1,
      36,    37,    38,    39,    -1,    41,    -1,    -1,    -1,    -1,
      -1,    47,    -1,    -1,    50,    -1,    -1,    53,    54,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    65,
      66,    67,    68,    69,    70,    71,    -1,    -1,    -1,    -1,
      -1,    -1,    78,    -1,    80,    81,    82,    -1,    84,    29,
      30,    31,    32,    33,    34,    -1,    36,    37,    38,    39,
      -1,    -1,    -1,    43,    -1,    -1,    -1,    47,    -1,    -1,
      50,    -1,    -1,    53,    54,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    65,    66,    67,    68,    69,
      70,    71,    -1,    -1,    -1,    -1,    -1,    -1,    78,    -1,
      80,    81,    82,    -1,    84,    29,    30,    31,    32,    33,
      34,    -1,    36,    37,    38,    39,    -1,    -1,    -1,    -1,
      44,    -1,    -1,    47,    -1,    -1,    50,    -1,    -1,    53,
      54,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    65,    66,    67,    68,    69,    70,    71,    -1,    -1,
      -1,    -1,    -1,    -1,    78,    -1,    80,    81,    82,    -1,
      84,    29,    30,    31,    32,    33,    34,    -1,    36,    37,
      38,    39,    -1,    41,    -1,    -1,    -1,    -1,    -1,    47,
      -1,    -1,    50,    -1,    -1,    53,    54,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    65,    66,    67,
      68,    69,    70,    71,    -1,    -1,    -1,    -1,    -1,    -1,
      78,    -1,    80,    81,    82,    -1,    84,    29,    30,    31,
      32,    33,    34,    -1,    36,    37,    38,    39,    -1,    41,
      -1,    -1,    -1,    -1,    -1,    47,    -1,    -1,    50,    -1,
      -1,    53,    54,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    65,    66,    67,    68,    69,    70,    71,
      -1,    -1,    -1,    -1,    -1,    -1,    78,    -1,    80,    81,
      82,    -1,    84,    29,    30,    31,    32,    33,    34,    -1,
      36,    37,    38,    39,    -1,    -1,    -1,    -1,    44,    -1,
      -1,    47,    -1,    -1,    50,    -1,    -1,    53,    54,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    65,
      66,    67,    68,    69,    70,    71,    -1,    -1,    -1,    -1,
      -1,    -1,    78,    -1,    80,    81,    82,    -1,    84,    29,
      30,    31,    32,    33,    34,    -1,    36,    37,    38,    39,
      -1,    41,    -1,    -1,    -1,    -1,    -1,    47,    -1,    -1,
      50,    -1,    -1,    53,    54,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    65,    66,    67,    68,    69,
      70,    71,    -1,    -1,    -1,    -1,    -1,    -1,    78,    -1,
      80,    81,    82,    -1,    84,    29,    30,    31,    32,    33,
      34,    -1,    36,    37,    38,    39,    -1,    41,    -1,    -1,
      -1,    -1,    -1,    47,    -1,    -1,    50,    -1,    -1,    53,
      54,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    65,    66,    67,    68,    69,    70,    71,    -1,    -1,
      -1,    -1,    -1,    -1,    78,    -1,    80,    81,    82,    -1,
      84,    29,    30,    31,    32,    33,    34,    -1,    36,    37,
      38,    39,    -1,    41,    -1,    -1,    -1,    -1,    -1,    47,
      -1,    -1,    50,    -1,    -1,    53,    54,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    65,    66,    67,
      68,    69,    70,    71,    -1,    -1,    -1,    -1,    -1,    -1,
      78,    -1,    80,    81,    82,    -1,    84,    29,    30,    31,
      32,    33,    34,    -1,    36,    37,    38,    39,    -1,    -1,
      -1,    -1,    44,    -1,    -1,    47,    -1,    -1,    50,    -1,
      -1,    53,    54,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    65,    66,    67,    68,    69,    70,    71,
      -1,    -1,    -1,    -1,    -1,    -1,    78,    -1,    80,    81,
      82,    -1,    84,    29,    30,    31,    32,    33,    34,    -1,
      36,    37,    38,    39,    -1,    -1,    -1,    -1,    44,    -1,
      -1,    47,    -1,    -1,    50,    -1,    -1,    53,    54,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    65,
      66,    67,    68,    69,    70,    71,    -1,    -1,    -1,    -1,
      -1,    -1,    78,    -1,    80,    81,    82,    -1,    84,    29,
      30,    31,    32,    33,    34,    -1,    36,    37,    38,    39,
      -1,    -1,    -1,    -1,    44,    -1,    -1,    47,    -1,    -1,
      50,    -1,    -1,    53,    54,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    65,    66,    67,    68,    69,
      70,    71,    -1,    -1,    -1,    -1,    -1,    -1,    78,    -1,
      80,    81,    82,    -1,    84,    29,    30,    31,    32,    33,
      34,    -1,    36,    37,    38,    39,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    47,    -1,    -1,    50,    -1,    -1,    53,
      54,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    65,    66,    67,    68,    69,    70,    71,    -1,    -1,
      -1,    -1,    -1,    -1,    78,    -1,    80,    81,    82,    -1,
      84,    29,    30,    31,    32,    33,    34,    -1,    36,    37,
      38,    39,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    47,
      -1,    -1,    50,    -1,    -1,    53,    54,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    65,    66,    67,
      68,    69,    70,    71,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    80,    81,    82,    -1,    84,    29,    30,    31,
      32,    33,    34,    -1,    36,    37,    38,    39,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    47,    -1,    -1,    50,    -1,
      -1,    53,    54,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    65,    66,    67,    68,    69,    -1,    71,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    80,    81,
      82,    -1,    84,    29,    30,    31,    32,    33,    34,    -1,
      36,    37,    38,    39,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    47,    -1,    -1,    50,    -1,    -1,    53,    54,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    65,
      66,    67,    68,    -1,    -1,    71,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    80,    81,    82,    -1,    84,    29,
      30,    31,    32,    33,    34,    -1,    36,    -1,    38,    39,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    47,    -1,    -1,
      50,    -1,    -1,    53,    54,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    65,    66,    67,    68,    -1,
      -1,    71,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      80,    81,    82,    -1,    84,    29,    30,    31,    32,    33,
      34,    -1,    36,    -1,    38,    39,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    50,    -1,    -1,    53,
      54,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    65,    66,    67,    68,    -1,    -1,    71,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    80,    81,    82,    -1,
      84,    29,    30,    31,    32,    33,    34,    -1,    36,    -1,
      -1,    39,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    50,    -1,    -1,    53,    54,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    65,    66,    67,
      68,    -1,    -1,    71,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    80,    81,    82,    -1,    84,     3,     4,     5,
       6,    -1,     8,     9,    10,    11,    12,    -1,    -1,    15,
      16,    17,    -1,    19,    -1,    21,    -1,    23,    24,    25,
      26,    27,    28,    -1,    30,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    40,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    48,    49,     4,     5,     6,    -1,     8,     9,
      10,    11,    12,    13,    -1,    15,    16,    17,    18,    19,
      -1,    -1,    -1,    23,    24,    25,    26,    27,    28,    -1,
      30,     4,     5,     6,    -1,     8,     9,    10,    11,    12,
      40,    -1,    15,    16,    17,    -1,    19,    -1,    48,    49,
      23,    24,    25,    26,    27,    28,    -1,    30,     4,     5,
       6,    -1,     8,     9,    10,    11,    12,    40,    -1,    15,
      16,    17,    45,    19,    -1,    48,    49,    23,    24,    25,
      26,    27,    28,    -1,    30,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    40,    -1,    -1,    -1,    -1,    -1,
      46,    -1,    48,    49,     4,     5,     6,    -1,     8,     9,
      10,    11,    12,    -1,    -1,    15,    16,    17,    -1,    19,
      -1,    -1,    -1,    23,    24,    25,    26,    27,    28,    -1,
      30,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      40,    -1,    -1,    -1,    -1,    -1,    46,    -1,    48,    49,
       4,     5,     6,    -1,     8,     9,    10,    11,    12,    -1,
      -1,    15,    16,    17,    -1,    19,    -1,    -1,    -1,    23,
      24,    25,    26,    27,    28,    -1,    30,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    40,    -1,    -1,    -1,
      -1,    -1,    46,    -1,    48,    49,     4,     5,     6,    -1,
       8,     9,    10,    11,    12,    -1,    -1,    15,    16,    17,
      -1,    19,    -1,    -1,    -1,    23,    24,    25,    26,    27,
      28,    -1,    30,     4,     5,     6,    -1,    -1,    -1,    -1,
      -1,    -1,    40,    -1,     4,     5,     6,    -1,    -1,    -1,
      48,    49,    23,    24,    25,    26,    27,    28,    -1,    30,
      -1,    -1,    -1,    23,    24,    25,    26,    27,    28,    40,
      30,    -1,    -1,    44,     4,     5,     6,    48,    49,    -1,
      40,    -1,    -1,    -1,    44,     4,     5,     6,    48,    49,
      -1,    -1,    -1,    23,    24,    25,    26,    27,    28,    -1,
      30,    -1,    -1,    -1,    23,    24,    25,    26,    27,    28,
      40,    30,    -1,    -1,    44,     4,     5,     6,    48,    49,
      -1,    40,    -1,    -1,    -1,    44,    -1,    -1,    -1,    48,
      49,    -1,    -1,    -1,    23,    24,    25,    26,    27,    28,
      -1,    30,     4,     5,     6,    -1,    -1,    -1,    -1,    -1,
      -1,    40,    41,    -1,    -1,    -1,    -1,    -1,    -1,    48,
      49,    23,    24,    25,    26,    27,    28,    -1,    30,     4,
       5,     6,    -1,    -1,    -1,    -1,    -1,    -1,    40,    41,
      -1,    -1,    -1,    -1,    -1,    -1,    48,    49,    23,    24,
      25,    26,    27,    28,    -1,    30,     4,     5,     6,    -1,
      -1,    -1,    -1,    -1,    -1,    40,    41,    -1,    -1,    -1,
      -1,    -1,    -1,    48,    49,    23,    24,    25,    26,    27,
      28,    -1,    30,    -1,    -1,    -1,    35,    -1,    -1,    -1,
      -1,    -1,    40,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      48,    49,    51,    52,    -1,    -1,    55,    56,    57,    58,
      59,    60,    61,    62,    63,    64,    35,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    74,    -1,    -1,    -1,    -1,
      35,    -1,    51,    52,    -1,    -1,    55,    56,    57,    58,
      59,    60,    61,    62,    63,    64,    51,    52,    -1,    -1,
      55,    56,    57,    58,    59,    60,    61,    62,    63,    64
};

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,    87,    88,     0,     3,     4,     5,     6,     8,     9,
      10,    11,    12,    15,    16,    17,    19,    21,    23,    24,
      25,    26,    27,    28,    30,    40,    48,    49,    89,    90,
      93,    94,    97,    98,   105,   108,   109,   110,   111,   112,
     113,   116,   117,    25,    25,    40,   114,     6,   112,   116,
     118,   119,    44,    44,    40,    44,   112,    40,    45,    93,
     104,    40,    25,    40,    40,    25,    35,    51,    52,    55,
      56,    57,    58,    59,    60,    61,    62,    63,    64,    74,
     115,    40,    73,   112,   112,   112,   112,    44,    29,    30,
      31,    32,    33,    34,    36,    37,    38,    39,    47,    50,
      53,    54,    65,    66,    67,    68,    69,    70,    71,    78,
      80,    81,    82,    84,    35,   115,    40,    73,   112,    40,
      46,    42,   112,    44,   112,    92,    11,    44,   112,    40,
     112,   112,    45,   112,   112,   112,   112,   112,   112,   112,
     112,   112,   112,   112,   112,   122,   118,    25,    41,   112,
     112,   112,   112,   112,   112,    25,   112,   112,   112,   112,
     112,   112,   112,   112,   112,   112,   112,   112,   112,   112,
     112,   112,   112,   112,   112,   112,    24,    95,    96,    25,
      41,   100,   112,   112,    41,    41,    46,    93,    40,    44,
     112,    44,    25,    41,    41,    91,    94,    42,    85,    41,
      40,    40,    74,    43,    72,    85,    41,    42,    40,    43,
      99,   104,   104,   112,    41,   112,    44,    44,   112,    99,
      45,    45,    46,    94,   112,    35,   115,   118,   118,   122,
     112,   112,    45,    24,    95,    25,    42,   101,     7,    41,
     104,    41,    41,   112,    41,   112,    44,    41,    18,   106,
     106,    44,   112,    41,    41,    85,    85,    92,    41,   119,
      41,   104,   104,   104,    41,   104,    41,    41,   112,    45,
     107,   112,    46,    46,    46,    45,    45,   104,   104,   104,
      41,    16,    25,    46,   120,   121,    20,    43,    92,    98,
     102,   103,   120,   104,    35,    35,    74,    44,    46,   121,
     112,    92,    46,    44,    46,    98,   103,   112,   112,   122,
      44,    13,   106,    44,    44,    44,    85,    43,    35,    92,
     112,    44
};

/* YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr1[] =
{
       0,    86,    87,    88,    88,    89,    89,    89,    90,    91,
      91,    92,    92,    93,    93,    93,    93,    93,    93,    93,
      93,    93,    93,    94,    94,    95,    95,    96,    96,    97,
      97,    98,    98,    99,    99,   100,   100,   101,   101,   102,
     102,   102,   102,   103,   103,   104,   104,   105,   105,   106,
     106,   106,   107,   107,   108,   108,   109,   109,   110,   110,
     110,   110,   110,   110,   110,   110,   111,   112,   112,   112,
     112,   112,   112,   112,   112,   112,   112,   112,   112,   112,
     112,   112,   112,   112,   112,   112,   112,   112,   112,   112,
     112,   112,   112,   112,   112,   112,   112,   112,   112,   112,
     112,   112,   112,   112,   112,   112,   112,   112,   113,   113,
     114,   114,   115,   115,   115,   115,   115,   115,   115,   115,
     115,   115,   115,   115,   116,   116,   116,   116,   116,   116,
     116,   116,   117,   117,   117,   118,   118,   119,   119,   120,
     120,   121,   121,   121,   122,   122
};

/* YYR2[RULE-NUM] -- Number of symbols on the right-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     1,     0,     2,     1,     1,     1,     6,     1,
       2,     0,     2,     1,     1,     1,     1,     1,     2,     2,
       2,     3,     2,     8,    10,     0,     1,     1,     3,    10,
       9,    10,     7,     0,     2,     0,     1,     0,     2,     0,
       1,     1,     2,     2,     3,     3,     1,     7,     7,     4,
       7,     5,     1,     3,     5,     7,     5,     6,     9,     8,
       8,     7,     8,     7,     7,     6,     1,     1,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     2,     5,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     3,     4,     6,     2,     2,     1,
       1,     1,     1,     1,     1,     1,     1,     4,     3,     6,
       1,     3,     1,     1,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     1,     1,     3,     6,     2,     5,
       2,     3,     4,     6,     6,     0,     1,     1,     3,     1,
       2,     4,     4,     7,     1,     3
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
#line 1872 "CMDgram.cc"
    break;

  case 3: /* decl_list: %empty  */
#line 154 "CMDgram.y"
      { (yyval.stmt) = nil; }
#line 1878 "CMDgram.cc"
    break;

  case 4: /* decl_list: decl_list decl  */
#line 156 "CMDgram.y"
      { if(!statementList) { statementList = (yyvsp[0].stmt); } else { statementList->append((yyvsp[0].stmt)); } }
#line 1884 "CMDgram.cc"
    break;

  case 5: /* decl: stmt  */
#line 161 "CMDgram.y"
      { (yyval.stmt) = (yyvsp[0].stmt); }
#line 1890 "CMDgram.cc"
    break;

  case 6: /* decl: fn_decl_stmt  */
#line 163 "CMDgram.y"
      { (yyval.stmt) = (yyvsp[0].stmt); }
#line 1896 "CMDgram.cc"
    break;

  case 7: /* decl: package_decl  */
#line 165 "CMDgram.y"
     { (yyval.stmt) = (yyvsp[0].stmt); }
#line 1902 "CMDgram.cc"
    break;

  case 8: /* package_decl: rwPACKAGE IDENT '{' fn_decl_list '}' ';'  */
#line 170 "CMDgram.y"
      { (yyval.stmt) = (yyvsp[-2].stmt); for(StmtNode *walk = ((yyvsp[-2].stmt));walk;walk = walk->getNext() ) walk->setPackage((yyvsp[-4].s)); }
#line 1908 "CMDgram.cc"
    break;

  case 9: /* fn_decl_list: fn_decl_stmt  */
#line 175 "CMDgram.y"
      { (yyval.stmt) = (yyvsp[0].stmt); }
#line 1914 "CMDgram.cc"
    break;

  case 10: /* fn_decl_list: fn_decl_list fn_decl_stmt  */
#line 177 "CMDgram.y"
      { (yyval.stmt) = (yyvsp[-1].stmt); ((yyvsp[-1].stmt))->append((yyvsp[0].stmt));  }
#line 1920 "CMDgram.cc"
    break;

  case 11: /* statement_list: %empty  */
#line 182 "CMDgram.y"
      { (yyval.stmt) = nil; }
#line 1926 "CMDgram.cc"
    break;

  case 12: /* statement_list: statement_list stmt  */
#line 184 "CMDgram.y"
      { if(!(yyvsp[-1].stmt)) { (yyval.stmt) = (yyvsp[0].stmt); } else { ((yyvsp[-1].stmt))->append((yyvsp[0].stmt)); (yyval.stmt) = (yyvsp[-1].stmt); } }
#line 1932 "CMDgram.cc"
    break;

  case 18: /* stmt: rwBREAK ';'  */
#line 194 "CMDgram.y"
      { (yyval.stmt) = BreakStmtNode::alloc(); }
#line 1938 "CMDgram.cc"
    break;

  case 19: /* stmt: rwCONTINUE ';'  */
#line 196 "CMDgram.y"
      { (yyval.stmt) = ContinueStmtNode::alloc(); }
#line 1944 "CMDgram.cc"
    break;

  case 20: /* stmt: rwRETURN ';'  */
#line 198 "CMDgram.y"
      { (yyval.stmt) = ReturnStmtNode::alloc(NULL); }
#line 1950 "CMDgram.cc"
    break;

  case 21: /* stmt: rwRETURN expr ';'  */
#line 200 "CMDgram.y"
      { (yyval.stmt) = ReturnStmtNode::alloc((yyvsp[-1].expr)); }
#line 1956 "CMDgram.cc"
    break;

  case 22: /* stmt: expression_stmt ';'  */
#line 202 "CMDgram.y"
      { (yyval.stmt) = (yyvsp[-1].stmt); }
#line 1962 "CMDgram.cc"
    break;

  case 23: /* fn_decl_stmt: rwDEFINE IDENT '(' var_list_decl ')' '{' statement_list '}'  */
#line 207 "CMDgram.y"
      { (yyval.stmt) = FunctionDeclStmtNode::alloc((yyvsp[-6].s), NULL, (yyvsp[-4].var), (yyvsp[-1].stmt)); }
#line 1968 "CMDgram.cc"
    break;

  case 24: /* fn_decl_stmt: rwDEFINE IDENT opCOLONCOLON IDENT '(' var_list_decl ')' '{' statement_list '}'  */
#line 209 "CMDgram.y"
     { (yyval.stmt) = FunctionDeclStmtNode::alloc((yyvsp[-6].s), (yyvsp[-8].s), (yyvsp[-4].var), (yyvsp[-1].stmt)); }
#line 1974 "CMDgram.cc"
    break;

  case 25: /* var_list_decl: %empty  */
#line 214 "CMDgram.y"
     { (yyval.var) = NULL; }
#line 1980 "CMDgram.cc"
    break;

  case 26: /* var_list_decl: var_list  */
#line 216 "CMDgram.y"
     { (yyval.var) = (yyvsp[0].var); }
#line 1986 "CMDgram.cc"
    break;

  case 27: /* var_list: VAR  */
#line 221 "CMDgram.y"
      { (yyval.var) = VarNode::alloc((yyvsp[0].s), NULL); }
#line 1992 "CMDgram.cc"
    break;

  case 28: /* var_list: var_list ',' VAR  */
#line 223 "CMDgram.y"
      { (yyval.var) = (yyvsp[-2].var); ((StmtNode*)((yyvsp[-2].var)))->append((StmtNode*)VarNode::alloc((yyvsp[0].s), NULL)); }
#line 1998 "CMDgram.cc"
    break;

  case 29: /* datablock_decl: rwDATABLOCK IDENT '(' IDENT parent_block ')' '{' slot_assign_list '}' ';'  */
#line 228 "CMDgram.y"
      { (yyval.stmt) = ObjectDeclNode::alloc(ConstantNode::alloc((yyvsp[-8].s)), ConstantNode::alloc((yyvsp[-6].s)), NULL, (yyvsp[-5].s), (yyvsp[-2].slist), NULL, true); }
#line 2004 "CMDgram.cc"
    break;

  case 30: /* datablock_decl: rwDATABLOCK IDENT '(' IDENT parent_block ')' '{' '}' ';'  */
#line 230 "CMDgram.y"
      { (yyval.stmt) = ObjectDeclNode::alloc(ConstantNode::alloc((yyvsp[-7].s)), ConstantNode::alloc((yyvsp[-5].s)), NULL, (yyvsp[-4].s), NULL, NULL, true); }
#line 2010 "CMDgram.cc"
    break;

  case 31: /* object_decl: rwDECLARE class_name_expr '(' object_name parent_block object_args ')' '{' object_declare_block '}'  */
#line 235 "CMDgram.y"
      { (yyval.od) = ObjectDeclNode::alloc((yyvsp[-8].expr), (yyvsp[-6].expr), (yyvsp[-4].expr), (yyvsp[-5].s), (yyvsp[-1].odcl).slots, (yyvsp[-1].odcl).decls, false); }
#line 2016 "CMDgram.cc"
    break;

  case 32: /* object_decl: rwDECLARE class_name_expr '(' object_name parent_block object_args ')'  */
#line 237 "CMDgram.y"
      { (yyval.od) = ObjectDeclNode::alloc((yyvsp[-5].expr), (yyvsp[-3].expr), (yyvsp[-1].expr), (yyvsp[-2].s), NULL, NULL, false); }
#line 2022 "CMDgram.cc"
    break;

  case 33: /* parent_block: %empty  */
#line 242 "CMDgram.y"
      { (yyval.s) = NULL; }
#line 2028 "CMDgram.cc"
    break;

  case 34: /* parent_block: ':' IDENT  */
#line 244 "CMDgram.y"
      { (yyval.s) = (yyvsp[0].s); }
#line 2034 "CMDgram.cc"
    break;

  case 35: /* object_name: %empty  */
#line 249 "CMDgram.y"
      { (yyval.expr) = StrConstNode::alloc("", false); }
#line 2040 "CMDgram.cc"
    break;

  case 36: /* object_name: expr  */
#line 251 "CMDgram.y"
      { (yyval.expr) = (yyvsp[0].expr); }
#line 2046 "CMDgram.cc"
    break;

  case 37: /* object_args: %empty  */
#line 256 "CMDgram.y"
      { (yyval.expr) = NULL; }
#line 2052 "CMDgram.cc"
    break;

  case 38: /* object_args: ',' expr_list  */
#line 258 "CMDgram.y"
      { (yyval.expr) = (yyvsp[0].expr); }
#line 2058 "CMDgram.cc"
    break;

  case 39: /* object_declare_block: %empty  */
#line 263 "CMDgram.y"
      { (yyval.odcl).slots = NULL; (yyval.odcl).decls = NULL; }
#line 2064 "CMDgram.cc"
    break;

  case 40: /* object_declare_block: slot_assign_list  */
#line 265 "CMDgram.y"
      { (yyval.odcl).slots = (yyvsp[0].slist); (yyval.odcl).decls = NULL; }
#line 2070 "CMDgram.cc"
    break;

  case 41: /* object_declare_block: object_decl_list  */
#line 267 "CMDgram.y"
      { (yyval.odcl).slots = NULL; (yyval.odcl).decls = (yyvsp[0].od); }
#line 2076 "CMDgram.cc"
    break;

  case 42: /* object_declare_block: slot_assign_list object_decl_list  */
#line 269 "CMDgram.y"
      { (yyval.odcl).slots = (yyvsp[-1].slist); (yyval.odcl).decls = (yyvsp[0].od); }
#line 2082 "CMDgram.cc"
    break;

  case 43: /* object_decl_list: object_decl ';'  */
#line 274 "CMDgram.y"
      { (yyval.od) = (yyvsp[-1].od); }
#line 2088 "CMDgram.cc"
    break;

  case 44: /* object_decl_list: object_decl_list object_decl ';'  */
#line 276 "CMDgram.y"
      { (yyvsp[-2].od)->append((yyvsp[-1].od)); (yyval.od) = (yyvsp[-2].od); }
#line 2094 "CMDgram.cc"
    break;

  case 45: /* stmt_block: '{' statement_list '}'  */
#line 281 "CMDgram.y"
      { (yyval.stmt) = (yyvsp[-1].stmt); }
#line 2100 "CMDgram.cc"
    break;

  case 46: /* stmt_block: stmt  */
#line 283 "CMDgram.y"
      { (yyval.stmt) = (yyvsp[0].stmt); }
#line 2106 "CMDgram.cc"
    break;

  case 47: /* switch_stmt: rwSWITCH '(' expr ')' '{' case_block '}'  */
#line 288 "CMDgram.y"
      { (yyval.stmt) = (yyvsp[-1].ifnode); (yyvsp[-1].ifnode)->propagateSwitchExpr((yyvsp[-4].expr), false); }
#line 2112 "CMDgram.cc"
    break;

  case 48: /* switch_stmt: rwSWITCHSTR '(' expr ')' '{' case_block '}'  */
#line 290 "CMDgram.y"
      { (yyval.stmt) = (yyvsp[-1].ifnode); (yyvsp[-1].ifnode)->propagateSwitchExpr((yyvsp[-4].expr), true); }
#line 2118 "CMDgram.cc"
    break;

  case 49: /* case_block: rwCASE case_expr ':' statement_list  */
#line 295 "CMDgram.y"
      { (yyval.ifnode) = IfStmtNode::alloc((yyvsp[-3].i), (yyvsp[-2].expr), (yyvsp[0].stmt), NULL, false); }
#line 2124 "CMDgram.cc"
    break;

  case 50: /* case_block: rwCASE case_expr ':' statement_list rwDEFAULT ':' statement_list  */
#line 297 "CMDgram.y"
      { (yyval.ifnode) = IfStmtNode::alloc((yyvsp[-6].i), (yyvsp[-5].expr), (yyvsp[-3].stmt), (yyvsp[0].stmt), false); }
#line 2130 "CMDgram.cc"
    break;

  case 51: /* case_block: rwCASE case_expr ':' statement_list case_block  */
#line 299 "CMDgram.y"
      { (yyval.ifnode) = IfStmtNode::alloc((yyvsp[-4].i), (yyvsp[-3].expr), (yyvsp[-1].stmt), (yyvsp[0].ifnode), true); }
#line 2136 "CMDgram.cc"
    break;

  case 52: /* case_expr: expr  */
#line 304 "CMDgram.y"
      { (yyval.expr) = (yyvsp[0].expr);}
#line 2142 "CMDgram.cc"
    break;

  case 53: /* case_expr: case_expr rwCASEOR expr  */
#line 306 "CMDgram.y"
      { ((yyvsp[-2].expr))->append((yyvsp[0].expr)); (yyval.expr)=(yyvsp[-2].expr); }
#line 2148 "CMDgram.cc"
    break;

  case 54: /* if_stmt: rwIF '(' expr ')' stmt_block  */
#line 311 "CMDgram.y"
      { (yyval.stmt) = IfStmtNode::alloc((yyvsp[-4].i), (yyvsp[-2].expr), (yyvsp[0].stmt), NULL, false); }
#line 2154 "CMDgram.cc"
    break;

  case 55: /* if_stmt: rwIF '(' expr ')' stmt_block rwELSE stmt_block  */
#line 313 "CMDgram.y"
      { (yyval.stmt) = IfStmtNode::alloc((yyvsp[-6].i), (yyvsp[-4].expr), (yyvsp[-2].stmt), (yyvsp[0].stmt), false); }
#line 2160 "CMDgram.cc"
    break;

  case 56: /* while_stmt: rwWHILE '(' expr ')' stmt_block  */
#line 318 "CMDgram.y"
      { (yyval.stmt) = LoopStmtNode::alloc((yyvsp[-4].i), nil, (yyvsp[-2].expr), nil, (yyvsp[0].stmt), false); }
#line 2166 "CMDgram.cc"
    break;

  case 57: /* while_stmt: rwDO stmt_block rwWHILE '(' expr ')'  */
#line 320 "CMDgram.y"
      { (yyval.stmt) = LoopStmtNode::alloc((yyvsp[-3].i), nil, (yyvsp[-1].expr), nil, (yyvsp[-4].stmt), true); }
#line 2172 "CMDgram.cc"
    break;

  case 58: /* for_stmt: rwFOR '(' expr ';' expr ';' expr ')' stmt_block  */
#line 325 "CMDgram.y"
      { (yyval.stmt) = LoopStmtNode::alloc((yyvsp[-8].i), (yyvsp[-6].expr), (yyvsp[-4].expr), (yyvsp[-2].expr), (yyvsp[0].stmt), false); }
#line 2178 "CMDgram.cc"
    break;

  case 59: /* for_stmt: rwFOR '(' expr ';' expr ';' ')' stmt_block  */
#line 327 "CMDgram.y"
      { (yyval.stmt) = LoopStmtNode::alloc((yyvsp[-7].i), (yyvsp[-5].expr), (yyvsp[-3].expr), NULL, (yyvsp[0].stmt), false); }
#line 2184 "CMDgram.cc"
    break;

  case 60: /* for_stmt: rwFOR '(' expr ';' ';' expr ')' stmt_block  */
#line 329 "CMDgram.y"
      { (yyval.stmt) = LoopStmtNode::alloc((yyvsp[-7].i), (yyvsp[-5].expr), NULL, (yyvsp[-2].expr), (yyvsp[0].stmt), false); }
#line 2190 "CMDgram.cc"
    break;

  case 61: /* for_stmt: rwFOR '(' expr ';' ';' ')' stmt_block  */
#line 331 "CMDgram.y"
      { (yyval.stmt) = LoopStmtNode::alloc((yyvsp[-6].i), (yyvsp[-4].expr), NULL, NULL, (yyvsp[0].stmt), false); }
#line 2196 "CMDgram.cc"
    break;

  case 62: /* for_stmt: rwFOR '(' ';' expr ';' expr ')' stmt_block  */
#line 333 "CMDgram.y"
      { (yyval.stmt) = LoopStmtNode::alloc((yyvsp[-7].i), NULL, (yyvsp[-4].expr), (yyvsp[-2].expr), (yyvsp[0].stmt), false); }
#line 2202 "CMDgram.cc"
    break;

  case 63: /* for_stmt: rwFOR '(' ';' expr ';' ')' stmt_block  */
#line 335 "CMDgram.y"
      { (yyval.stmt) = LoopStmtNode::alloc((yyvsp[-6].i), NULL, (yyvsp[-3].expr), NULL, (yyvsp[0].stmt), false); }
#line 2208 "CMDgram.cc"
    break;

  case 64: /* for_stmt: rwFOR '(' ';' ';' expr ')' stmt_block  */
#line 337 "CMDgram.y"
      { (yyval.stmt) = LoopStmtNode::alloc((yyvsp[-6].i), NULL, NULL, (yyvsp[-2].expr), (yyvsp[0].stmt), false); }
#line 2214 "CMDgram.cc"
    break;

  case 65: /* for_stmt: rwFOR '(' ';' ';' ')' stmt_block  */
#line 339 "CMDgram.y"
      { (yyval.stmt) = LoopStmtNode::alloc((yyvsp[-5].i), NULL, NULL, NULL, (yyvsp[0].stmt), false); }
#line 2220 "CMDgram.cc"
    break;

  case 66: /* expression_stmt: stmt_expr  */
#line 344 "CMDgram.y"
      { (yyval.stmt) = (yyvsp[0].expr); }
#line 2226 "CMDgram.cc"
    break;

  case 67: /* expr: stmt_expr  */
#line 349 "CMDgram.y"
      { (yyval.expr) = (yyvsp[0].expr); }
#line 2232 "CMDgram.cc"
    break;

  case 68: /* expr: '(' expr ')'  */
#line 351 "CMDgram.y"
      { (yyval.expr) = (yyvsp[-1].expr); }
#line 2238 "CMDgram.cc"
    break;

  case 69: /* expr: rwCVLSTART expr_list_decl '}'  */
#line 353 "CMDgram.y"
      { (yyval.expr) = ValueListExprNode::alloc((yyvsp[-1].expr)); }
#line 2244 "CMDgram.cc"
    break;

  case 70: /* expr: expr '^' expr  */
#line 355 "CMDgram.y"
      { (yyval.expr) = IntBinaryExprNode::alloc((yyvsp[-1].i), (yyvsp[-2].expr), (yyvsp[0].expr)); }
#line 2250 "CMDgram.cc"
    break;

  case 71: /* expr: expr '%' expr  */
#line 357 "CMDgram.y"
      { (yyval.expr) = IntBinaryExprNode::alloc((yyvsp[-1].i), (yyvsp[-2].expr), (yyvsp[0].expr)); }
#line 2256 "CMDgram.cc"
    break;

  case 72: /* expr: expr '&' expr  */
#line 359 "CMDgram.y"
      { (yyval.expr) = IntBinaryExprNode::alloc((yyvsp[-1].i), (yyvsp[-2].expr), (yyvsp[0].expr)); }
#line 2262 "CMDgram.cc"
    break;

  case 73: /* expr: expr '|' expr  */
#line 361 "CMDgram.y"
      { (yyval.expr) = IntBinaryExprNode::alloc((yyvsp[-1].i), (yyvsp[-2].expr), (yyvsp[0].expr)); }
#line 2268 "CMDgram.cc"
    break;

  case 74: /* expr: expr '+' expr  */
#line 363 "CMDgram.y"
      { (yyval.expr) = FloatBinaryExprNode::alloc((yyvsp[-1].i), (yyvsp[-2].expr), (yyvsp[0].expr)); }
#line 2274 "CMDgram.cc"
    break;

  case 75: /* expr: expr '-' expr  */
#line 365 "CMDgram.y"
      { (yyval.expr) = FloatBinaryExprNode::alloc((yyvsp[-1].i), (yyvsp[-2].expr), (yyvsp[0].expr)); }
#line 2280 "CMDgram.cc"
    break;

  case 76: /* expr: expr '*' expr  */
#line 367 "CMDgram.y"
      { (yyval.expr) = FloatBinaryExprNode::alloc((yyvsp[-1].i), (yyvsp[-2].expr), (yyvsp[0].expr)); }
#line 2286 "CMDgram.cc"
    break;

  case 77: /* expr: expr '/' expr  */
#line 369 "CMDgram.y"
      { (yyval.expr) = FloatBinaryExprNode::alloc((yyvsp[-1].i), (yyvsp[-2].expr), (yyvsp[0].expr)); }
#line 2292 "CMDgram.cc"
    break;

  case 78: /* expr: '-' expr  */
#line 371 "CMDgram.y"
      { (yyval.expr) = FloatUnaryExprNode::alloc((yyvsp[-1].i), (yyvsp[0].expr)); }
#line 2298 "CMDgram.cc"
    break;

  case 79: /* expr: expr '?' expr ':' expr  */
#line 373 "CMDgram.y"
      { (yyval.expr) = ConditionalExprNode::alloc((yyvsp[-4].expr), (yyvsp[-2].expr), (yyvsp[0].expr)); }
#line 2304 "CMDgram.cc"
    break;

  case 80: /* expr: expr '<' expr  */
#line 375 "CMDgram.y"
      { (yyval.expr) = IntBinaryExprNode::alloc((yyvsp[-1].i), (yyvsp[-2].expr), (yyvsp[0].expr)); }
#line 2310 "CMDgram.cc"
    break;

  case 81: /* expr: expr '>' expr  */
#line 377 "CMDgram.y"
      { (yyval.expr) = IntBinaryExprNode::alloc((yyvsp[-1].i), (yyvsp[-2].expr), (yyvsp[0].expr)); }
#line 2316 "CMDgram.cc"
    break;

  case 82: /* expr: expr opGE expr  */
#line 379 "CMDgram.y"
      { (yyval.expr) = IntBinaryExprNode::alloc((yyvsp[-1].i), (yyvsp[-2].expr), (yyvsp[0].expr)); }
#line 2322 "CMDgram.cc"
    break;

  case 83: /* expr: expr opLE expr  */
#line 381 "CMDgram.y"
      { (yyval.expr) = IntBinaryExprNode::alloc((yyvsp[-1].i), (yyvsp[-2].expr), (yyvsp[0].expr)); }
#line 2328 "CMDgram.cc"
    break;

  case 84: /* expr: expr opEQ expr  */
#line 383 "CMDgram.y"
      { (yyval.expr) = IntBinaryExprNode::alloc((yyvsp[-1].i), (yyvsp[-2].expr), (yyvsp[0].expr)); }
#line 2334 "CMDgram.cc"
    break;

  case 85: /* expr: expr opNE expr  */
#line 385 "CMDgram.y"
      { (yyval.expr) = IntBinaryExprNode::alloc((yyvsp[-1].i), (yyvsp[-2].expr), (yyvsp[0].expr)); }
#line 2340 "CMDgram.cc"
    break;

  case 86: /* expr: expr opOR expr  */
#line 387 "CMDgram.y"
      { (yyval.expr) = IntBinaryExprNode::alloc((yyvsp[-1].i), (yyvsp[-2].expr), (yyvsp[0].expr)); }
#line 2346 "CMDgram.cc"
    break;

  case 87: /* expr: expr opSHL expr  */
#line 389 "CMDgram.y"
      { (yyval.expr) = IntBinaryExprNode::alloc((yyvsp[-1].i), (yyvsp[-2].expr), (yyvsp[0].expr)); }
#line 2352 "CMDgram.cc"
    break;

  case 88: /* expr: expr opSHR expr  */
#line 391 "CMDgram.y"
      { (yyval.expr) = IntBinaryExprNode::alloc((yyvsp[-1].i), (yyvsp[-2].expr), (yyvsp[0].expr)); }
#line 2358 "CMDgram.cc"
    break;

  case 89: /* expr: expr opAND expr  */
#line 393 "CMDgram.y"
      { (yyval.expr) = IntBinaryExprNode::alloc((yyvsp[-1].i), (yyvsp[-2].expr), (yyvsp[0].expr)); }
#line 2364 "CMDgram.cc"
    break;

  case 90: /* expr: expr opSTREQ expr  */
#line 395 "CMDgram.y"
      { (yyval.expr) = StreqExprNode::alloc((yyvsp[-2].expr), (yyvsp[0].expr), true); }
#line 2370 "CMDgram.cc"
    break;

  case 91: /* expr: expr opSTRNE expr  */
#line 397 "CMDgram.y"
      { (yyval.expr) = StreqExprNode::alloc((yyvsp[-2].expr), (yyvsp[0].expr), false); }
#line 2376 "CMDgram.cc"
    break;

  case 92: /* expr: expr opFORGIVE expr  */
#line 399 "CMDgram.y"
      { (yyval.expr) = StrForgiveExprNode::alloc((yyvsp[-2].expr), (yyvsp[0].expr)); }
#line 2382 "CMDgram.cc"
    break;

  case 93: /* expr: expr '@' expr  */
#line 401 "CMDgram.y"
      { (yyval.expr) = StrcatExprNode::alloc((yyvsp[-2].expr), (yyvsp[0].expr), (yyvsp[-1].i)); }
#line 2388 "CMDgram.cc"
    break;

  case 94: /* expr: expr opINSTANCE expr  */
#line 403 "CMDgram.y"
      { (yyval.expr) = InstanceOfExprNode::alloc((yyvsp[-2].expr), (yyvsp[0].expr)); }
#line 2394 "CMDgram.cc"
    break;

  case 95: /* expr: expr opIDXSTART expr ']'  */
#line 405 "CMDgram.y"
      { (yyvsp[-3].expr)->append((yyvsp[-1].expr)); (yyval.expr) = FuncCallExprNode::alloc(StringTable->insert("getWord"), NULL, (yyvsp[-3].expr), false); }
#line 2400 "CMDgram.cc"
    break;

  case 96: /* expr: expr opIDXSTART expr opRANGE expr ']'  */
#line 407 "CMDgram.y"
      { (yyvsp[-3].expr)->append((yyvsp[-1].expr)); (yyvsp[-5].expr)->append((yyvsp[-3].expr)); (yyval.expr) = FuncCallExprNode::alloc(StringTable->insert("getWords"), NULL, (yyvsp[-5].expr), false); }
#line 2406 "CMDgram.cc"
    break;

  case 97: /* expr: '!' expr  */
#line 409 "CMDgram.y"
      { (yyval.expr) = IntUnaryExprNode::alloc((yyvsp[-1].i), (yyvsp[0].expr)); }
#line 2412 "CMDgram.cc"
    break;

  case 98: /* expr: '~' expr  */
#line 411 "CMDgram.y"
      { (yyval.expr) = IntUnaryExprNode::alloc((yyvsp[-1].i), (yyvsp[0].expr)); }
#line 2418 "CMDgram.cc"
    break;

  case 99: /* expr: TAGATOM  */
#line 413 "CMDgram.y"
      { (yyval.expr) = StrConstNode::alloc((yyvsp[0].str), true); }
#line 2424 "CMDgram.cc"
    break;

  case 100: /* expr: FLTCONST  */
#line 415 "CMDgram.y"
      { (yyval.expr) = FloatNode::alloc((yyvsp[0].f)); }
#line 2430 "CMDgram.cc"
    break;

  case 101: /* expr: INTCONST  */
#line 417 "CMDgram.y"
      { (yyval.expr) = IntNode::alloc((yyvsp[0].i)); }
#line 2436 "CMDgram.cc"
    break;

  case 102: /* expr: rwBREAK  */
#line 419 "CMDgram.y"
      { (yyval.expr) = ConstantNode::alloc(StringTable->insert("break")); }
#line 2442 "CMDgram.cc"
    break;

  case 103: /* expr: slot_acc  */
#line 421 "CMDgram.y"
      { (yyval.expr) = SlotAccessNode::alloc((yyvsp[0].slot).object, (yyvsp[0].slot).array, (yyvsp[0].slot).slotName); }
#line 2448 "CMDgram.cc"
    break;

  case 104: /* expr: IDENT  */
#line 423 "CMDgram.y"
      { (yyval.expr) = ConstantNode::alloc((yyvsp[0].s)); }
#line 2454 "CMDgram.cc"
    break;

  case 105: /* expr: STRATOM  */
#line 425 "CMDgram.y"
      { (yyval.expr) = StrConstNode::alloc((yyvsp[0].str), false); }
#line 2460 "CMDgram.cc"
    break;

  case 106: /* expr: VAR  */
#line 427 "CMDgram.y"
      { (yyval.expr) = (ExprNode*)VarNode::alloc((yyvsp[0].s), NULL); }
#line 2466 "CMDgram.cc"
    break;

  case 107: /* expr: VAR '[' aidx_expr ']'  */
#line 429 "CMDgram.y"
      { (yyval.expr) = (ExprNode*)VarNode::alloc((yyvsp[-3].s), (yyvsp[-1].expr)); }
#line 2472 "CMDgram.cc"
    break;

  case 108: /* slot_acc: expr '.' IDENT  */
#line 434 "CMDgram.y"
      { (yyval.slot).object = (yyvsp[-2].expr); (yyval.slot).slotName = (yyvsp[0].s); (yyval.slot).array = NULL; }
#line 2478 "CMDgram.cc"
    break;

  case 109: /* slot_acc: expr '.' IDENT '[' aidx_expr ']'  */
#line 436 "CMDgram.y"
      { (yyval.slot).object = (yyvsp[-5].expr); (yyval.slot).slotName = (yyvsp[-3].s); (yyval.slot).array = (yyvsp[-1].expr); }
#line 2484 "CMDgram.cc"
    break;

  case 110: /* class_name_expr: IDENT  */
#line 441 "CMDgram.y"
      { (yyval.expr) = ConstantNode::alloc((yyvsp[0].s)); }
#line 2490 "CMDgram.cc"
    break;

  case 111: /* class_name_expr: '(' expr ')'  */
#line 443 "CMDgram.y"
      { (yyval.expr) = (yyvsp[-1].expr); }
#line 2496 "CMDgram.cc"
    break;

  case 112: /* assign_op_struct: opPLUSPLUS  */
#line 448 "CMDgram.y"
      { (yyval.asn).token = '+'; (yyval.asn).expr = FloatNode::alloc(1); }
#line 2502 "CMDgram.cc"
    break;

  case 113: /* assign_op_struct: opMINUSMINUS  */
#line 450 "CMDgram.y"
      { (yyval.asn).token = '-'; (yyval.asn).expr = FloatNode::alloc(1); }
#line 2508 "CMDgram.cc"
    break;

  case 114: /* assign_op_struct: opPLASN expr  */
#line 452 "CMDgram.y"
      { (yyval.asn).token = '+'; (yyval.asn).expr = (yyvsp[0].expr); }
#line 2514 "CMDgram.cc"
    break;

  case 115: /* assign_op_struct: opMIASN expr  */
#line 454 "CMDgram.y"
      { (yyval.asn).token = '-'; (yyval.asn).expr = (yyvsp[0].expr); }
#line 2520 "CMDgram.cc"
    break;

  case 116: /* assign_op_struct: opMLASN expr  */
#line 456 "CMDgram.y"
      { (yyval.asn).token = '*'; (yyval.asn).expr = (yyvsp[0].expr); }
#line 2526 "CMDgram.cc"
    break;

  case 117: /* assign_op_struct: opDVASN expr  */
#line 458 "CMDgram.y"
      { (yyval.asn).token = '/'; (yyval.asn).expr = (yyvsp[0].expr); }
#line 2532 "CMDgram.cc"
    break;

  case 118: /* assign_op_struct: opMODASN expr  */
#line 460 "CMDgram.y"
      { (yyval.asn).token = '%'; (yyval.asn).expr = (yyvsp[0].expr); }
#line 2538 "CMDgram.cc"
    break;

  case 119: /* assign_op_struct: opANDASN expr  */
#line 462 "CMDgram.y"
      { (yyval.asn).token = '&'; (yyval.asn).expr = (yyvsp[0].expr); }
#line 2544 "CMDgram.cc"
    break;

  case 120: /* assign_op_struct: opXORASN expr  */
#line 464 "CMDgram.y"
      { (yyval.asn).token = '^'; (yyval.asn).expr = (yyvsp[0].expr); }
#line 2550 "CMDgram.cc"
    break;

  case 121: /* assign_op_struct: opORASN expr  */
#line 466 "CMDgram.y"
      { (yyval.asn).token = '|'; (yyval.asn).expr = (yyvsp[0].expr); }
#line 2556 "CMDgram.cc"
    break;

  case 122: /* assign_op_struct: opSLASN expr  */
#line 468 "CMDgram.y"
      { (yyval.asn).token = opSHL; (yyval.asn).expr = (yyvsp[0].expr); }
#line 2562 "CMDgram.cc"
    break;

  case 123: /* assign_op_struct: opSRASN expr  */
#line 470 "CMDgram.y"
      { (yyval.asn).token = opSHR; (yyval.asn).expr = (yyvsp[0].expr); }
#line 2568 "CMDgram.cc"
    break;

  case 124: /* stmt_expr: funcall_expr  */
#line 475 "CMDgram.y"
      { (yyval.expr) = (yyvsp[0].expr); }
#line 2574 "CMDgram.cc"
    break;

  case 125: /* stmt_expr: object_decl  */
#line 477 "CMDgram.y"
      { (yyval.expr) = (yyvsp[0].od); }
#line 2580 "CMDgram.cc"
    break;

  case 126: /* stmt_expr: VAR '=' expr  */
#line 479 "CMDgram.y"
      { (yyval.expr) = AssignExprNode::alloc((yyvsp[-2].s), NULL, (yyvsp[0].expr)); }
#line 2586 "CMDgram.cc"
    break;

  case 127: /* stmt_expr: VAR '[' aidx_expr ']' '=' expr  */
#line 481 "CMDgram.y"
      { (yyval.expr) = AssignExprNode::alloc((yyvsp[-5].s), (yyvsp[-3].expr), (yyvsp[0].expr)); }
#line 2592 "CMDgram.cc"
    break;

  case 128: /* stmt_expr: VAR assign_op_struct  */
#line 483 "CMDgram.y"
      { (yyval.expr) = AssignOpExprNode::alloc((yyvsp[-1].s), NULL, (yyvsp[0].asn).expr, (yyvsp[0].asn).token); }
#line 2598 "CMDgram.cc"
    break;

  case 129: /* stmt_expr: VAR '[' aidx_expr ']' assign_op_struct  */
#line 485 "CMDgram.y"
      { (yyval.expr) = AssignOpExprNode::alloc((yyvsp[-4].s), (yyvsp[-2].expr), (yyvsp[0].asn).expr, (yyvsp[0].asn).token); }
#line 2604 "CMDgram.cc"
    break;

  case 130: /* stmt_expr: slot_acc assign_op_struct  */
#line 487 "CMDgram.y"
      { (yyval.expr) = SlotAssignOpNode::alloc((yyvsp[-1].slot).object, (yyvsp[-1].slot).slotName, (yyvsp[-1].slot).array, (yyvsp[0].asn).token, (yyvsp[0].asn).expr); }
#line 2610 "CMDgram.cc"
    break;

  case 131: /* stmt_expr: slot_acc '=' expr  */
#line 489 "CMDgram.y"
      { (yyval.expr) = SlotAssignNode::alloc((yyvsp[-2].slot).object, (yyvsp[-2].slot).array, (yyvsp[-2].slot).slotName, (yyvsp[0].expr)); }
#line 2616 "CMDgram.cc"
    break;

  case 132: /* funcall_expr: IDENT '(' expr_list_decl ')'  */
#line 494 "CMDgram.y"
     { (yyval.expr) = FuncCallExprNode::alloc((yyvsp[-3].s), NULL, (yyvsp[-1].expr), false); }
#line 2622 "CMDgram.cc"
    break;

  case 133: /* funcall_expr: IDENT opCOLONCOLON IDENT '(' expr_list_decl ')'  */
#line 496 "CMDgram.y"
     { (yyval.expr) = FuncCallExprNode::alloc((yyvsp[-3].s), (yyvsp[-5].s), (yyvsp[-1].expr), false); }
#line 2628 "CMDgram.cc"
    break;

  case 134: /* funcall_expr: expr '.' IDENT '(' expr_list_decl ')'  */
#line 498 "CMDgram.y"
      { (yyvsp[-5].expr)->append((yyvsp[-1].expr)); (yyval.expr) = FuncCallExprNode::alloc((yyvsp[-3].s), NULL, (yyvsp[-5].expr), true); }
#line 2634 "CMDgram.cc"
    break;

  case 135: /* expr_list_decl: %empty  */
#line 503 "CMDgram.y"
      { (yyval.expr) = NULL; }
#line 2640 "CMDgram.cc"
    break;

  case 136: /* expr_list_decl: expr_list  */
#line 505 "CMDgram.y"
      { (yyval.expr) = (yyvsp[0].expr); }
#line 2646 "CMDgram.cc"
    break;

  case 137: /* expr_list: expr  */
#line 510 "CMDgram.y"
      { (yyval.expr) = (yyvsp[0].expr); }
#line 2652 "CMDgram.cc"
    break;

  case 138: /* expr_list: expr_list ',' expr  */
#line 512 "CMDgram.y"
      { ((yyvsp[-2].expr))->append((yyvsp[0].expr)); (yyval.expr) = (yyvsp[-2].expr); }
#line 2658 "CMDgram.cc"
    break;

  case 139: /* slot_assign_list: slot_assign  */
#line 517 "CMDgram.y"
      { (yyval.slist) = (yyvsp[0].slist); }
#line 2664 "CMDgram.cc"
    break;

  case 140: /* slot_assign_list: slot_assign_list slot_assign  */
#line 519 "CMDgram.y"
      { (yyvsp[-1].slist)->append((yyvsp[0].slist)); (yyval.slist) = (yyvsp[-1].slist); }
#line 2670 "CMDgram.cc"
    break;

  case 141: /* slot_assign: IDENT '=' expr ';'  */
#line 524 "CMDgram.y"
      { (yyval.slist) = SlotAssignNode::alloc(NULL, NULL, (yyvsp[-3].s), (yyvsp[-1].expr)); }
#line 2676 "CMDgram.cc"
    break;

  case 142: /* slot_assign: rwDATABLOCK '=' expr ';'  */
#line 526 "CMDgram.y"
      { (yyval.slist) = SlotAssignNode::alloc(NULL, NULL, StringTable->insert("datablock"), (yyvsp[-1].expr)); }
#line 2682 "CMDgram.cc"
    break;

  case 143: /* slot_assign: IDENT '[' aidx_expr ']' '=' expr ';'  */
#line 528 "CMDgram.y"
      { (yyval.slist) = SlotAssignNode::alloc(NULL, (yyvsp[-4].expr), (yyvsp[-6].s), (yyvsp[-1].expr)); }
#line 2688 "CMDgram.cc"
    break;

  case 144: /* aidx_expr: expr  */
#line 533 "CMDgram.y"
      { (yyval.expr) = (yyvsp[0].expr); }
#line 2694 "CMDgram.cc"
    break;

  case 145: /* aidx_expr: aidx_expr ',' expr  */
#line 535 "CMDgram.y"
      { (yyval.expr) = CommaCatExprNode::alloc((yyvsp[-2].expr), (yyvsp[0].expr)); }
#line 2700 "CMDgram.cc"
    break;


#line 2704 "CMDgram.cc"

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

#line 537 "CMDgram.y"


