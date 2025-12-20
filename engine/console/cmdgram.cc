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
  YYSYMBOL_PTHATOM = 28,                   /* PTHATOM  */
  YYSYMBOL_FLTCONST = 29,                  /* FLTCONST  */
  YYSYMBOL_30_ = 30,                       /* '+'  */
  YYSYMBOL_31_ = 31,                       /* '-'  */
  YYSYMBOL_32_ = 32,                       /* '*'  */
  YYSYMBOL_33_ = 33,                       /* '/'  */
  YYSYMBOL_34_ = 34,                       /* '<'  */
  YYSYMBOL_35_ = 35,                       /* '>'  */
  YYSYMBOL_36_ = 36,                       /* '='  */
  YYSYMBOL_37_ = 37,                       /* '.'  */
  YYSYMBOL_38_ = 38,                       /* '|'  */
  YYSYMBOL_39_ = 39,                       /* '&'  */
  YYSYMBOL_40_ = 40,                       /* '%'  */
  YYSYMBOL_41_ = 41,                       /* '('  */
  YYSYMBOL_42_ = 42,                       /* ')'  */
  YYSYMBOL_43_ = 43,                       /* ','  */
  YYSYMBOL_44_ = 44,                       /* ':'  */
  YYSYMBOL_45_ = 45,                       /* ';'  */
  YYSYMBOL_46_ = 46,                       /* '{'  */
  YYSYMBOL_47_ = 47,                       /* '}'  */
  YYSYMBOL_48_ = 48,                       /* '^'  */
  YYSYMBOL_49_ = 49,                       /* '~'  */
  YYSYMBOL_50_ = 50,                       /* '!'  */
  YYSYMBOL_51_ = 51,                       /* '@'  */
  YYSYMBOL_opMINUSMINUS = 52,              /* opMINUSMINUS  */
  YYSYMBOL_opPLUSPLUS = 53,                /* opPLUSPLUS  */
  YYSYMBOL_opSHL = 54,                     /* opSHL  */
  YYSYMBOL_opSHR = 55,                     /* opSHR  */
  YYSYMBOL_opPLASN = 56,                   /* opPLASN  */
  YYSYMBOL_opMIASN = 57,                   /* opMIASN  */
  YYSYMBOL_opMLASN = 58,                   /* opMLASN  */
  YYSYMBOL_opDVASN = 59,                   /* opDVASN  */
  YYSYMBOL_opMODASN = 60,                  /* opMODASN  */
  YYSYMBOL_opANDASN = 61,                  /* opANDASN  */
  YYSYMBOL_opXORASN = 62,                  /* opXORASN  */
  YYSYMBOL_opORASN = 63,                   /* opORASN  */
  YYSYMBOL_opSLASN = 64,                   /* opSLASN  */
  YYSYMBOL_opSRASN = 65,                   /* opSRASN  */
  YYSYMBOL_opEQ = 66,                      /* opEQ  */
  YYSYMBOL_opNE = 67,                      /* opNE  */
  YYSYMBOL_opGE = 68,                      /* opGE  */
  YYSYMBOL_opLE = 69,                      /* opLE  */
  YYSYMBOL_opAND = 70,                     /* opAND  */
  YYSYMBOL_opOR = 71,                      /* opOR  */
  YYSYMBOL_opSTREQ = 72,                   /* opSTREQ  */
  YYSYMBOL_opRANGE = 73,                   /* opRANGE  */
  YYSYMBOL_opCOLONCOLON = 74,              /* opCOLONCOLON  */
  YYSYMBOL_75_ = 75,                       /* '['  */
  YYSYMBOL_opMDASN = 76,                   /* opMDASN  */
  YYSYMBOL_opNDASN = 77,                   /* opNDASN  */
  YYSYMBOL_opNTASN = 78,                   /* opNTASN  */
  YYSYMBOL_79_ = 79,                       /* '?'  */
  YYSYMBOL_opCAT = 80,                     /* opCAT  */
  YYSYMBOL_opSTRNE = 81,                   /* opSTRNE  */
  YYSYMBOL_opFORGIVE = 82,                 /* opFORGIVE  */
  YYSYMBOL_opINSTANCE = 83,                /* opINSTANCE  */
  YYSYMBOL_UNARY = 84,                     /* UNARY  */
  YYSYMBOL_opIDXSTART = 85,                /* opIDXSTART  */
  YYSYMBOL_86_ = 86,                       /* ']'  */
  YYSYMBOL_YYACCEPT = 87,                  /* $accept  */
  YYSYMBOL_start = 88,                     /* start  */
  YYSYMBOL_decl_list = 89,                 /* decl_list  */
  YYSYMBOL_decl = 90,                      /* decl  */
  YYSYMBOL_package_decl = 91,              /* package_decl  */
  YYSYMBOL_fn_decl_list = 92,              /* fn_decl_list  */
  YYSYMBOL_statement_list = 93,            /* statement_list  */
  YYSYMBOL_stmt = 94,                      /* stmt  */
  YYSYMBOL_fn_decl_stmt = 95,              /* fn_decl_stmt  */
  YYSYMBOL_var_list_decl = 96,             /* var_list_decl  */
  YYSYMBOL_var_list = 97,                  /* var_list  */
  YYSYMBOL_datablock_decl = 98,            /* datablock_decl  */
  YYSYMBOL_object_decl = 99,               /* object_decl  */
  YYSYMBOL_parent_block = 100,             /* parent_block  */
  YYSYMBOL_object_name = 101,              /* object_name  */
  YYSYMBOL_object_args = 102,              /* object_args  */
  YYSYMBOL_object_declare_block = 103,     /* object_declare_block  */
  YYSYMBOL_object_decl_list = 104,         /* object_decl_list  */
  YYSYMBOL_stmt_block = 105,               /* stmt_block  */
  YYSYMBOL_switch_stmt = 106,              /* switch_stmt  */
  YYSYMBOL_case_block = 107,               /* case_block  */
  YYSYMBOL_case_expr = 108,                /* case_expr  */
  YYSYMBOL_if_stmt = 109,                  /* if_stmt  */
  YYSYMBOL_while_stmt = 110,               /* while_stmt  */
  YYSYMBOL_for_stmt = 111,                 /* for_stmt  */
  YYSYMBOL_expression_stmt = 112,          /* expression_stmt  */
  YYSYMBOL_expr = 113,                     /* expr  */
  YYSYMBOL_slot_acc = 114,                 /* slot_acc  */
  YYSYMBOL_class_name_expr = 115,          /* class_name_expr  */
  YYSYMBOL_assign_op_struct = 116,         /* assign_op_struct  */
  YYSYMBOL_stmt_expr = 117,                /* stmt_expr  */
  YYSYMBOL_funcall_expr = 118,             /* funcall_expr  */
  YYSYMBOL_expr_list_decl = 119,           /* expr_list_decl  */
  YYSYMBOL_expr_list = 120,                /* expr_list  */
  YYSYMBOL_slot_assign_list = 121,         /* slot_assign_list  */
  YYSYMBOL_slot_assign = 122,              /* slot_assign  */
  YYSYMBOL_aidx_expr = 123                 /* aidx_expr  */
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
#define YYLAST   2516

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  87
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  37
/* YYNRULES -- Number of rules.  */
#define YYNRULES  146
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  323

/* YYMAXUTOK -- Last valid token kind.  */
#define YYMAXUTOK   316


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
       2,     2,     2,    50,     2,     2,     2,    40,    39,     2,
      41,    42,    32,    30,    43,    31,    37,    33,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,    44,    45,
      34,    36,    35,    79,    51,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,    75,     2,    86,    48,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    46,    38,    47,    49,     2,     2,     2,
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
      25,    26,    27,    28,    29,    52,    53,    54,    55,    56,
      57,    58,    59,    60,    61,    62,    63,    64,    65,    66,
      67,    68,    69,    70,    71,    72,    73,    74,    76,    77,
      78,    80,    81,    82,    83,    84,    85
};

#if CMDDEBUG
/* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_int16 yyrline[] =
{
       0,   149,   149,   155,   156,   161,   163,   165,   170,   175,
     177,   183,   184,   189,   190,   191,   192,   193,   194,   196,
     198,   200,   202,   207,   209,   215,   216,   221,   223,   228,
     230,   235,   237,   243,   244,   250,   251,   257,   258,   264,
     265,   267,   269,   274,   276,   281,   283,   288,   290,   295,
     297,   299,   304,   306,   311,   313,   318,   320,   325,   327,
     329,   331,   333,   335,   337,   339,   344,   349,   351,   353,
     355,   357,   359,   361,   363,   365,   367,   369,   371,   373,
     375,   377,   379,   381,   383,   385,   387,   389,   391,   393,
     395,   397,   399,   401,   403,   405,   407,   409,   411,   413,
     415,   417,   419,   421,   423,   425,   427,   429,   431,   436,
     438,   443,   445,   450,   452,   454,   456,   458,   460,   462,
     464,   466,   468,   470,   472,   477,   479,   481,   483,   485,
     487,   489,   491,   496,   498,   500,   506,   507,   512,   514,
     519,   521,   526,   528,   530,   535,   537
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
  "TAGATOM", "PTHATOM", "FLTCONST", "'+'", "'-'", "'*'", "'/'", "'<'",
  "'>'", "'='", "'.'", "'|'", "'&'", "'%'", "'('", "')'", "','", "':'",
  "';'", "'{'", "'}'", "'^'", "'~'", "'!'", "'@'", "opMINUSMINUS",
  "opPLUSPLUS", "opSHL", "opSHR", "opPLASN", "opMIASN", "opMLASN",
  "opDVASN", "opMODASN", "opANDASN", "opXORASN", "opORASN", "opSLASN",
  "opSRASN", "opEQ", "opNE", "opGE", "opLE", "opAND", "opOR", "opSTREQ",
  "opRANGE", "opCOLONCOLON", "'['", "opMDASN", "opNDASN", "opNTASN", "'?'",
  "opCAT", "opSTRNE", "opFORGIVE", "opINSTANCE", "UNARY", "opIDXSTART",
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

#define YYPACT_NINF (-223)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-67)

#define yytable_value_is_error(Yyn) \
  0

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int16 yypact[] =
{
    -223,    19,  1954,  -223,     6,    17,  2408,   -12,   -11,    -5,
    2226,    14,  2029,    27,    44,    31,    37,    55,  -223,  2407,
     -24,  -223,  -223,  -223,  -223,  2408,  2408,  2408,  2408,  -223,
    -223,  -223,  -223,  -223,  -223,  -223,  -223,  -223,  -223,    36,
    1535,  2437,    38,  -223,   -23,  -223,  2408,    41,  -223,  1535,
    -223,    39,    52,  -223,  -223,  2408,  -223,   357,  2408,  -223,
    -223,    73,  2237,    58,  2408,  2408,    54,  2408,  -223,  -223,
    2408,  2408,  2408,  2408,  2408,  2408,  2408,  2408,  2408,  2408,
    2408,  -223,  2408,    77,   -29,   448,   -29,   -29,  -223,  2408,
    2408,  2408,  2408,  2408,  2408,    79,  2408,  2408,  2408,  2408,
    2408,  2408,  2408,  2408,  2408,  2408,  2408,  2408,  2408,  2408,
    2408,  2408,  2408,  2408,  2408,  2408,  -223,    81,    83,   527,
    2408,  -223,  2408,   583,  -223,   639,  2057,    68,  2268,   695,
      91,   751,   807,   123,  1535,  1535,  1535,  1535,  1535,  1535,
    1535,  1535,  1535,  1535,  1535,   863,    43,    85,    89,  -223,
      57,    57,   -29,   -29,   195,   195,   -26,  1759,  1871,   -29,
    1815,   437,     8,     8,    -8,    -8,   195,   195,  1703,  1647,
     437,   919,   437,   437,   437,    80,  1535,  -223,    90,    93,
      92,  -223,    94,  1535,  1535,  2029,  2029,  -223,  -223,  2408,
    2279,   975,  2310,    94,    95,    97,    10,  -223,  2408,  2451,
    -223,  2408,  2408,  2408,  2408,  2408,  -223,    98,   113,    81,
     114,   102,   133,  -223,  1031,  2029,  1087,  2321,  2352,  1143,
     112,   138,   138,   110,  -223,  -223,  2408,  -223,   115,   116,
      78,  1591,   137,  -223,  -223,   131,  -223,  2408,   136,  2029,
    -223,  -223,  2029,  2029,  1199,  2029,  1255,  2380,   134,  2408,
     132,   135,  -223,  1535,  -223,  -223,  -223,  -223,  2104,   140,
      52,   141,  -223,  -223,  -223,  2029,  -223,  2029,  2029,  1311,
       5,     0,  1535,  -223,  -223,  -223,  -223,    12,  -223,  -223,
    -223,  2029,   145,   -22,   144,    51,  -223,  2408,  -223,  2151,
     148,   143,   190,    12,  -223,  2408,  2408,  2408,  -223,   150,
    -223,  1535,  2001,  -223,  -223,  -223,   151,   190,  1367,  1423,
     111,  -223,   154,  -223,  -223,  -223,  -223,   163,  -223,  2408,
    2198,  1479,  -223
};

/* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE does not specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       3,     0,     2,     1,     0,     0,   136,   102,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   101,   107,
     104,   105,    99,   106,   100,     0,     0,     0,     0,     4,
       7,     5,     6,    16,   126,    17,    13,    14,    15,     0,
       0,   103,    67,   125,     0,   111,     0,     0,   102,   138,
      67,     0,   137,    18,    19,     0,    20,     0,     0,    11,
      46,     0,     0,     0,     0,     0,     0,     0,   114,   113,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   129,   136,     0,    78,     0,    98,    97,    22,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   131,    25,     0,     0,
      35,    69,     0,     0,    21,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   127,   115,   116,   117,   118,   119,
     120,   121,   122,   123,   124,   145,     0,     0,     0,    68,
      74,    75,    76,    77,    80,    81,   109,    73,    72,    71,
      70,    93,    87,    88,    84,    85,    82,    83,    89,    86,
      90,     0,    91,    92,    94,     0,   132,    27,     0,    26,
       0,   112,    33,    36,   139,     0,     0,    45,    12,     0,
       0,     0,     0,    33,     0,     0,     0,     9,     0,   108,
     133,   136,   136,     0,     0,     0,    95,     0,     0,    25,
       0,    37,    54,    56,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    10,   146,     0,   130,     0,     0,
       0,    79,     0,    11,    28,     0,    34,     0,     0,     0,
      57,    65,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     8,   128,   134,   135,   110,    96,     0,     0,
      38,    32,    55,    64,    63,     0,    61,     0,     0,     0,
       0,     0,    52,    47,    48,    23,    11,    39,    62,    60,
      59,     0,     0,     0,     0,     0,   140,     0,    11,     0,
       0,     0,    41,    40,    58,     0,     0,     0,    30,     0,
     141,    53,    49,    24,    43,    31,     0,    42,     0,     0,
       0,    29,     0,    51,    44,   143,   142,     0,    11,     0,
      50,     0,   144
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -223,  -223,  -223,  -223,  -223,  -223,  -222,    -1,  -126,    -9,
    -223,  -223,  -186,     9,  -223,  -223,  -223,   -92,  -180,  -223,
    -210,  -223,  -223,  -223,  -223,  -223,   258,  -223,  -223,   -39,
      -2,  -223,   -79,   -27,   -66,  -214,  -194
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
       0,     1,     2,    29,    30,   196,   126,    60,    32,   178,
     179,    33,    34,   211,   182,   238,   291,   292,    61,    35,
     250,   271,    36,    37,    38,    39,    40,    41,    47,    81,
      50,    43,    51,    52,   285,   286,   146
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      42,    31,   116,   147,   225,   212,   213,   197,    95,   230,
      42,   258,   251,     4,   296,   202,     5,    82,   117,     3,
     287,   282,    89,    90,    91,    92,    93,    94,   282,    95,
     283,    44,    98,    53,    54,   241,    55,   283,    89,    90,
      91,    92,    45,   100,   288,    95,   101,   102,    98,   203,
      83,   118,   284,   297,   289,    58,   114,   223,    46,   262,
     105,   106,   263,   264,   109,   266,   302,   282,    62,    63,
     224,   300,    64,   111,   112,   113,   283,   114,    65,   300,
      66,    88,   120,   -66,   127,   278,   121,   279,   280,    91,
      92,   290,   313,   114,    95,   122,   320,    98,   299,   130,
     133,   294,   148,   310,   156,   177,   306,   290,   180,   189,
      89,    90,    91,    92,    93,    94,   193,    95,    96,    97,
      98,   306,   228,   229,    42,   188,     4,   200,    99,   199,
     201,   100,   207,   209,   101,   102,   208,   234,   210,   236,
     239,   221,   114,   222,   233,   237,   103,   104,   105,   106,
     107,   108,   109,   205,   248,   252,   249,   254,   255,   110,
     227,   111,   112,   113,   256,   114,   206,    89,    90,    91,
      92,    93,    94,   259,    95,    96,    97,    98,   261,   273,
     270,   295,   274,    42,    42,    99,   276,   277,   100,   298,
     305,   101,   102,   304,     5,   311,   314,   317,   318,   319,
     235,   307,   220,   103,   104,   105,   106,   107,   108,   109,
     260,   293,     0,    42,     0,     0,   110,     0,   111,   112,
     113,     0,   114,   257,     0,    89,    90,    91,    92,     0,
       0,     0,    95,     0,     0,    98,     0,    42,     0,     0,
      42,    42,     0,    42,     0,     0,   100,     0,     0,   101,
     102,     0,     0,     0,     0,     0,    42,   188,     0,     0,
       0,     0,     0,    42,    49,    42,    42,   109,    57,     0,
       0,     0,     0,     0,     0,     0,   111,   112,   113,    42,
     114,     0,     0,    84,    85,    86,    87,    42,   188,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      42,   188,     0,     0,   119,     0,     0,     0,     0,     0,
       0,     0,     0,   123,     0,     0,   125,     0,    42,   188,
     129,     0,   131,   132,     0,   134,     0,     0,   135,   136,
     137,   138,   139,   140,   141,   142,   143,   144,   145,     0,
      49,     0,     0,     0,     0,     0,     0,   150,   151,   152,
     153,   154,   155,     0,   157,   158,   159,   160,   161,   162,
     163,   164,   165,   166,   167,   168,   169,   170,   171,   172,
     173,   174,   175,   176,     0,     0,     0,     0,   183,     0,
     184,     0,     0,     0,     0,     0,   191,    89,    90,    91,
      92,    93,    94,     0,    95,    96,    97,    98,     0,     0,
       0,     0,   124,     0,     0,    99,     0,     0,   100,     0,
       0,   101,   102,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   103,   104,   105,   106,   107,   108,   109,
       0,     0,     0,     0,     0,     0,   110,     0,   111,   112,
     113,     0,   114,     0,     0,     0,     0,   214,   216,     0,
     219,     0,     0,     0,     0,     0,   145,     0,     0,    49,
      49,   145,   231,   232,     0,     0,     0,    89,    90,    91,
      92,     0,     0,     0,    95,   244,   246,    98,    89,    90,
      91,    92,    93,    94,   253,    95,    96,    97,    98,     0,
     149,   101,   102,     0,     0,    49,    99,     0,     0,   100,
       0,     0,   101,   102,     0,   269,     0,   272,     0,     0,
       0,     0,     0,     0,   103,   104,   105,   106,   107,   108,
     109,     0,   114,     0,     0,     0,     0,   110,     0,   111,
     112,   113,     0,   114,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   301,     0,     0,     0,     0,
       0,     0,     0,   308,   309,   145,     0,    89,    90,    91,
      92,    93,    94,     0,    95,    96,    97,    98,     0,   181,
       0,     0,     0,     0,     0,    99,     0,   321,   100,     0,
       0,   101,   102,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   103,   104,   105,   106,   107,   108,   109,
       0,     0,     0,     0,     0,     0,   110,     0,   111,   112,
     113,     0,   114,    89,    90,    91,    92,    93,    94,     0,
      95,    96,    97,    98,     0,   185,     0,     0,     0,     0,
       0,    99,     0,     0,   100,     0,     0,   101,   102,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   103,
     104,   105,   106,   107,   108,   109,     0,     0,     0,     0,
       0,     0,   110,     0,   111,   112,   113,     0,   114,    89,
      90,    91,    92,    93,    94,     0,    95,    96,    97,    98,
       0,   186,     0,     0,     0,     0,     0,    99,     0,     0,
     100,     0,     0,   101,   102,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   103,   104,   105,   106,   107,
     108,   109,     0,     0,     0,     0,     0,     0,   110,     0,
     111,   112,   113,     0,   114,    89,    90,    91,    92,    93,
      94,     0,    95,    96,    97,    98,     0,     0,     0,     0,
     192,     0,     0,    99,     0,     0,   100,     0,     0,   101,
     102,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   103,   104,   105,   106,   107,   108,   109,     0,     0,
       0,     0,     0,     0,   110,     0,   111,   112,   113,     0,
     114,    89,    90,    91,    92,    93,    94,     0,    95,    96,
      97,    98,     0,   194,     0,     0,     0,     0,     0,    99,
       0,     0,   100,     0,     0,   101,   102,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   103,   104,   105,
     106,   107,   108,   109,     0,     0,     0,     0,     0,     0,
     110,     0,   111,   112,   113,     0,   114,    89,    90,    91,
      92,    93,    94,     0,    95,    96,    97,    98,     0,   195,
       0,     0,     0,     0,     0,    99,     0,     0,   100,     0,
       0,   101,   102,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   103,   104,   105,   106,   107,   108,   109,
       0,     0,     0,     0,     0,     0,   110,     0,   111,   112,
     113,     0,   114,    89,    90,    91,    92,    93,    94,     0,
      95,    96,    97,    98,     0,     0,   198,     0,     0,     0,
       0,    99,     0,     0,   100,     0,     0,   101,   102,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   103,
     104,   105,   106,   107,   108,   109,     0,     0,     0,     0,
       0,     0,   110,     0,   111,   112,   113,     0,   114,    89,
      90,    91,    92,    93,    94,     0,    95,    96,    97,    98,
       0,     0,     0,   204,     0,     0,     0,    99,     0,     0,
     100,     0,     0,   101,   102,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   103,   104,   105,   106,   107,
     108,   109,     0,     0,     0,     0,     0,     0,   110,     0,
     111,   112,   113,     0,   114,    89,    90,    91,    92,    93,
      94,     0,    95,    96,    97,    98,     0,     0,     0,     0,
     217,     0,     0,    99,     0,     0,   100,     0,     0,   101,
     102,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   103,   104,   105,   106,   107,   108,   109,     0,     0,
       0,     0,     0,     0,   110,     0,   111,   112,   113,     0,
     114,    89,    90,    91,    92,    93,    94,     0,    95,    96,
      97,    98,     0,   240,     0,     0,     0,     0,     0,    99,
       0,     0,   100,     0,     0,   101,   102,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   103,   104,   105,
     106,   107,   108,   109,     0,     0,     0,     0,     0,     0,
     110,     0,   111,   112,   113,     0,   114,    89,    90,    91,
      92,    93,    94,     0,    95,    96,    97,    98,     0,   242,
       0,     0,     0,     0,     0,    99,     0,     0,   100,     0,
       0,   101,   102,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   103,   104,   105,   106,   107,   108,   109,
       0,     0,     0,     0,     0,     0,   110,     0,   111,   112,
     113,     0,   114,    89,    90,    91,    92,    93,    94,     0,
      95,    96,    97,    98,     0,     0,     0,     0,   247,     0,
       0,    99,     0,     0,   100,     0,     0,   101,   102,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   103,
     104,   105,   106,   107,   108,   109,     0,     0,     0,     0,
       0,     0,   110,     0,   111,   112,   113,     0,   114,    89,
      90,    91,    92,    93,    94,     0,    95,    96,    97,    98,
       0,   265,     0,     0,     0,     0,     0,    99,     0,     0,
     100,     0,     0,   101,   102,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   103,   104,   105,   106,   107,
     108,   109,     0,     0,     0,     0,     0,     0,   110,     0,
     111,   112,   113,     0,   114,    89,    90,    91,    92,    93,
      94,     0,    95,    96,    97,    98,     0,   267,     0,     0,
       0,     0,     0,    99,     0,     0,   100,     0,     0,   101,
     102,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   103,   104,   105,   106,   107,   108,   109,     0,     0,
       0,     0,     0,     0,   110,     0,   111,   112,   113,     0,
     114,    89,    90,    91,    92,    93,    94,     0,    95,    96,
      97,    98,     0,   281,     0,     0,     0,     0,     0,    99,
       0,     0,   100,     0,     0,   101,   102,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   103,   104,   105,
     106,   107,   108,   109,     0,     0,     0,     0,     0,     0,
     110,     0,   111,   112,   113,     0,   114,    89,    90,    91,
      92,    93,    94,     0,    95,    96,    97,    98,     0,     0,
       0,     0,   315,     0,     0,    99,     0,     0,   100,     0,
       0,   101,   102,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   103,   104,   105,   106,   107,   108,   109,
       0,     0,     0,     0,     0,     0,   110,     0,   111,   112,
     113,     0,   114,    89,    90,    91,    92,    93,    94,     0,
      95,    96,    97,    98,     0,     0,     0,     0,   316,     0,
       0,    99,     0,     0,   100,     0,     0,   101,   102,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   103,
     104,   105,   106,   107,   108,   109,     0,     0,     0,     0,
       0,     0,   110,     0,   111,   112,   113,     0,   114,    89,
      90,    91,    92,    93,    94,     0,    95,    96,    97,    98,
       0,     0,     0,     0,   322,     0,     0,    99,     0,     0,
     100,     0,     0,   101,   102,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   103,   104,   105,   106,   107,
     108,   109,     0,     0,     0,     0,     0,     0,   110,     0,
     111,   112,   113,     0,   114,    89,    90,    91,    92,    93,
      94,     0,    95,    96,    97,    98,     0,     0,     0,     0,
       0,     0,     0,    99,     0,     0,   100,     0,     0,   101,
     102,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   103,   104,   105,   106,   107,   108,   109,     0,     0,
       0,     0,     0,     0,   110,     0,   111,   112,   113,     0,
     114,    89,    90,    91,    92,    93,    94,     0,    95,    96,
      97,    98,     0,     0,     0,     0,     0,     0,     0,    99,
       0,     0,   100,     0,     0,   101,   102,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   103,   104,   105,
     106,   107,   108,   109,     0,     0,     0,     0,     0,     0,
       0,     0,   111,   112,   113,     0,   114,    89,    90,    91,
      92,    93,    94,     0,    95,    96,    97,    98,     0,     0,
       0,     0,     0,     0,     0,    99,     0,     0,   100,     0,
       0,   101,   102,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   103,   104,   105,   106,   107,     0,   109,
       0,     0,     0,     0,     0,     0,     0,     0,   111,   112,
     113,     0,   114,    89,    90,    91,    92,    93,    94,     0,
      95,    96,    97,    98,     0,     0,     0,     0,     0,     0,
       0,    99,     0,     0,   100,     0,     0,   101,   102,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   103,
     104,   105,   106,     0,     0,   109,     0,     0,     0,     0,
       0,     0,     0,     0,   111,   112,   113,     0,   114,    89,
      90,    91,    92,    93,    94,     0,    95,     0,    97,    98,
       0,     0,     0,     0,     0,     0,     0,    99,     0,     0,
     100,     0,     0,   101,   102,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   103,   104,   105,   106,     0,
       0,   109,     0,     0,     0,     0,     0,     0,     0,     0,
     111,   112,   113,     0,   114,    89,    90,    91,    92,    93,
      94,     0,    95,     0,    97,    98,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   100,     0,     0,   101,
     102,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   103,   104,   105,   106,     0,     0,   109,     0,     0,
       0,     0,     0,     0,     0,     0,   111,   112,   113,     0,
     114,    89,    90,    91,    92,    93,    94,     0,    95,     0,
       0,    98,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   100,     0,     0,   101,   102,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   103,   104,   105,
     106,     0,     0,   109,     0,     0,     0,     0,     0,     0,
       0,     0,   111,   112,   113,     0,   114,     4,     5,     6,
       7,     0,     8,     9,    10,    11,    12,     0,     0,    13,
      14,    15,     0,    16,     0,    17,     0,    18,    19,    20,
      21,    22,    23,    24,     0,    25,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    26,     0,     0,     0,     0,
       0,     0,     0,    27,    28,     5,     6,     7,     0,     8,
       9,    10,    11,    12,   312,     0,    13,    14,    15,   249,
      16,     0,     0,     0,    18,    19,    20,    21,    22,    23,
      24,     0,    25,     5,     6,     7,     0,     8,     9,    10,
      11,    12,    26,     0,    13,    14,    15,     0,    16,     0,
      27,    28,    18,    19,    20,    21,    22,    23,    24,     0,
      25,     5,     6,     7,     0,     8,     9,    10,    11,    12,
      26,     0,    13,    14,    15,    59,    16,     0,    27,    28,
      18,    19,    20,    21,    22,    23,    24,     0,    25,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    26,     0,
       0,     0,     0,     0,   187,     0,    27,    28,     5,     6,
       7,     0,     8,     9,    10,    11,    12,     0,     0,    13,
      14,    15,     0,    16,     0,     0,     0,    18,    19,    20,
      21,    22,    23,    24,     0,    25,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    26,     0,     0,     0,     0,
       0,   275,     0,    27,    28,     5,     6,     7,     0,     8,
       9,    10,    11,    12,     0,     0,    13,    14,    15,     0,
      16,     0,     0,     0,    18,    19,    20,    21,    22,    23,
      24,     0,    25,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    26,     0,     0,     0,     0,     0,   303,     0,
      27,    28,     5,     6,     7,     0,     8,     9,    10,    11,
      12,     0,     0,    13,    14,    15,     0,    16,     0,     0,
       0,    18,    19,    20,    21,    22,    23,    24,     0,    25,
       5,     6,    48,     0,     0,     0,     0,     0,     0,    26,
       0,     5,     6,    48,     0,     0,     0,    27,    28,    18,
      19,    20,    21,    22,    23,    24,     0,    25,     0,     0,
      18,    19,    20,    21,    22,    23,    24,    26,    25,     0,
       0,    56,     5,     6,    48,    27,    28,     0,    26,     0,
       0,     0,   128,     5,     6,    48,    27,    28,     0,     0,
       0,    18,    19,    20,    21,    22,    23,    24,     0,    25,
       0,     0,    18,    19,    20,    21,    22,    23,    24,    26,
      25,     0,     0,   190,     5,     6,    48,    27,    28,     0,
      26,   215,     0,     0,     0,     5,     6,    48,    27,    28,
       0,     0,     0,    18,    19,    20,    21,    22,    23,    24,
       0,    25,     0,     0,    18,    19,    20,    21,    22,    23,
      24,    26,    25,     0,     0,   218,     5,     6,    48,    27,
      28,     0,    26,   243,     0,     0,     0,     0,     0,     0,
      27,    28,     0,     0,     0,    18,    19,    20,    21,    22,
      23,    24,     0,    25,     5,     6,    48,     0,     0,     0,
       0,     0,     0,    26,   245,     0,     0,     0,     0,     0,
       0,    27,    28,    18,    19,    20,    21,    22,    23,    24,
       0,    25,     5,     6,    48,     0,     0,     0,     0,     0,
       0,    26,   268,     0,     0,     0,     0,     0,     0,    27,
      28,    18,    19,    20,    21,    22,    23,    24,     0,    25,
       0,     0,     0,    67,     0,     0,     0,     0,     0,    26,
       0,     0,     0,     0,     0,     0,     0,    27,    28,    68,
      69,     0,     0,    70,    71,    72,    73,    74,    75,    76,
      77,    78,    79,   115,     0,     0,     0,     0,     0,     0,
       0,     0,    80,     0,     0,     0,     0,   226,     0,    68,
      69,     0,     0,    70,    71,    72,    73,    74,    75,    76,
      77,    78,    79,    68,    69,     0,     0,    70,    71,    72,
      73,    74,    75,    76,    77,    78,    79
};

static const yytype_int16 yycheck[] =
{
       2,     2,    41,    82,   198,   185,   186,   133,    37,   203,
      12,   233,   222,     3,    36,    41,     4,    41,    41,     0,
      20,    16,    30,    31,    32,    33,    34,    35,    16,    37,
      25,    25,    40,    45,    45,   215,    41,    25,    30,    31,
      32,    33,    25,    51,    44,    37,    54,    55,    40,    75,
      74,    74,    47,    75,   276,    41,    85,    47,    41,   239,
      68,    69,   242,   243,    72,   245,   288,    16,    41,    25,
     196,   285,    41,    81,    82,    83,    25,    85,    41,   293,
      25,    45,    41,    45,    11,   265,    47,   267,   268,    32,
      33,   277,   302,    85,    37,    43,   318,    40,    47,    41,
      46,   281,    25,   297,    25,    24,   292,   293,    25,    41,
      30,    31,    32,    33,    34,    35,    25,    37,    38,    39,
      40,   307,   201,   202,   126,   126,     3,    42,    48,    86,
      41,    51,    42,    41,    54,    55,    43,    24,    44,    25,
       7,    46,    85,    46,    46,    43,    66,    67,    68,    69,
      70,    71,    72,    73,    42,    45,    18,    42,    42,    79,
     199,    81,    82,    83,    86,    85,    86,    30,    31,    32,
      33,    34,    35,    42,    37,    38,    39,    40,    42,    47,
      46,    36,    47,   185,   186,    48,    46,    46,    51,    45,
      47,    54,    55,    45,     4,    45,    45,    86,    44,    36,
     209,   293,   193,    66,    67,    68,    69,    70,    71,    72,
     237,   277,    -1,   215,    -1,    -1,    79,    -1,    81,    82,
      83,    -1,    85,    86,    -1,    30,    31,    32,    33,    -1,
      -1,    -1,    37,    -1,    -1,    40,    -1,   239,    -1,    -1,
     242,   243,    -1,   245,    -1,    -1,    51,    -1,    -1,    54,
      55,    -1,    -1,    -1,    -1,    -1,   258,   258,    -1,    -1,
      -1,    -1,    -1,   265,     6,   267,   268,    72,    10,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    81,    82,    83,   281,
      85,    -1,    -1,    25,    26,    27,    28,   289,   289,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     302,   302,    -1,    -1,    46,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    55,    -1,    -1,    58,    -1,   320,   320,
      62,    -1,    64,    65,    -1,    67,    -1,    -1,    70,    71,
      72,    73,    74,    75,    76,    77,    78,    79,    80,    -1,
      82,    -1,    -1,    -1,    -1,    -1,    -1,    89,    90,    91,
      92,    93,    94,    -1,    96,    97,    98,    99,   100,   101,
     102,   103,   104,   105,   106,   107,   108,   109,   110,   111,
     112,   113,   114,   115,    -1,    -1,    -1,    -1,   120,    -1,
     122,    -1,    -1,    -1,    -1,    -1,   128,    30,    31,    32,
      33,    34,    35,    -1,    37,    38,    39,    40,    -1,    -1,
      -1,    -1,    45,    -1,    -1,    48,    -1,    -1,    51,    -1,
      -1,    54,    55,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    66,    67,    68,    69,    70,    71,    72,
      -1,    -1,    -1,    -1,    -1,    -1,    79,    -1,    81,    82,
      83,    -1,    85,    -1,    -1,    -1,    -1,   189,   190,    -1,
     192,    -1,    -1,    -1,    -1,    -1,   198,    -1,    -1,   201,
     202,   203,   204,   205,    -1,    -1,    -1,    30,    31,    32,
      33,    -1,    -1,    -1,    37,   217,   218,    40,    30,    31,
      32,    33,    34,    35,   226,    37,    38,    39,    40,    -1,
      42,    54,    55,    -1,    -1,   237,    48,    -1,    -1,    51,
      -1,    -1,    54,    55,    -1,   247,    -1,   249,    -1,    -1,
      -1,    -1,    -1,    -1,    66,    67,    68,    69,    70,    71,
      72,    -1,    85,    -1,    -1,    -1,    -1,    79,    -1,    81,
      82,    83,    -1,    85,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   287,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   295,   296,   297,    -1,    30,    31,    32,
      33,    34,    35,    -1,    37,    38,    39,    40,    -1,    42,
      -1,    -1,    -1,    -1,    -1,    48,    -1,   319,    51,    -1,
      -1,    54,    55,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    66,    67,    68,    69,    70,    71,    72,
      -1,    -1,    -1,    -1,    -1,    -1,    79,    -1,    81,    82,
      83,    -1,    85,    30,    31,    32,    33,    34,    35,    -1,
      37,    38,    39,    40,    -1,    42,    -1,    -1,    -1,    -1,
      -1,    48,    -1,    -1,    51,    -1,    -1,    54,    55,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    66,
      67,    68,    69,    70,    71,    72,    -1,    -1,    -1,    -1,
      -1,    -1,    79,    -1,    81,    82,    83,    -1,    85,    30,
      31,    32,    33,    34,    35,    -1,    37,    38,    39,    40,
      -1,    42,    -1,    -1,    -1,    -1,    -1,    48,    -1,    -1,
      51,    -1,    -1,    54,    55,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    66,    67,    68,    69,    70,
      71,    72,    -1,    -1,    -1,    -1,    -1,    -1,    79,    -1,
      81,    82,    83,    -1,    85,    30,    31,    32,    33,    34,
      35,    -1,    37,    38,    39,    40,    -1,    -1,    -1,    -1,
      45,    -1,    -1,    48,    -1,    -1,    51,    -1,    -1,    54,
      55,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    66,    67,    68,    69,    70,    71,    72,    -1,    -1,
      -1,    -1,    -1,    -1,    79,    -1,    81,    82,    83,    -1,
      85,    30,    31,    32,    33,    34,    35,    -1,    37,    38,
      39,    40,    -1,    42,    -1,    -1,    -1,    -1,    -1,    48,
      -1,    -1,    51,    -1,    -1,    54,    55,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    66,    67,    68,
      69,    70,    71,    72,    -1,    -1,    -1,    -1,    -1,    -1,
      79,    -1,    81,    82,    83,    -1,    85,    30,    31,    32,
      33,    34,    35,    -1,    37,    38,    39,    40,    -1,    42,
      -1,    -1,    -1,    -1,    -1,    48,    -1,    -1,    51,    -1,
      -1,    54,    55,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    66,    67,    68,    69,    70,    71,    72,
      -1,    -1,    -1,    -1,    -1,    -1,    79,    -1,    81,    82,
      83,    -1,    85,    30,    31,    32,    33,    34,    35,    -1,
      37,    38,    39,    40,    -1,    -1,    43,    -1,    -1,    -1,
      -1,    48,    -1,    -1,    51,    -1,    -1,    54,    55,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    66,
      67,    68,    69,    70,    71,    72,    -1,    -1,    -1,    -1,
      -1,    -1,    79,    -1,    81,    82,    83,    -1,    85,    30,
      31,    32,    33,    34,    35,    -1,    37,    38,    39,    40,
      -1,    -1,    -1,    44,    -1,    -1,    -1,    48,    -1,    -1,
      51,    -1,    -1,    54,    55,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    66,    67,    68,    69,    70,
      71,    72,    -1,    -1,    -1,    -1,    -1,    -1,    79,    -1,
      81,    82,    83,    -1,    85,    30,    31,    32,    33,    34,
      35,    -1,    37,    38,    39,    40,    -1,    -1,    -1,    -1,
      45,    -1,    -1,    48,    -1,    -1,    51,    -1,    -1,    54,
      55,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    66,    67,    68,    69,    70,    71,    72,    -1,    -1,
      -1,    -1,    -1,    -1,    79,    -1,    81,    82,    83,    -1,
      85,    30,    31,    32,    33,    34,    35,    -1,    37,    38,
      39,    40,    -1,    42,    -1,    -1,    -1,    -1,    -1,    48,
      -1,    -1,    51,    -1,    -1,    54,    55,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    66,    67,    68,
      69,    70,    71,    72,    -1,    -1,    -1,    -1,    -1,    -1,
      79,    -1,    81,    82,    83,    -1,    85,    30,    31,    32,
      33,    34,    35,    -1,    37,    38,    39,    40,    -1,    42,
      -1,    -1,    -1,    -1,    -1,    48,    -1,    -1,    51,    -1,
      -1,    54,    55,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    66,    67,    68,    69,    70,    71,    72,
      -1,    -1,    -1,    -1,    -1,    -1,    79,    -1,    81,    82,
      83,    -1,    85,    30,    31,    32,    33,    34,    35,    -1,
      37,    38,    39,    40,    -1,    -1,    -1,    -1,    45,    -1,
      -1,    48,    -1,    -1,    51,    -1,    -1,    54,    55,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    66,
      67,    68,    69,    70,    71,    72,    -1,    -1,    -1,    -1,
      -1,    -1,    79,    -1,    81,    82,    83,    -1,    85,    30,
      31,    32,    33,    34,    35,    -1,    37,    38,    39,    40,
      -1,    42,    -1,    -1,    -1,    -1,    -1,    48,    -1,    -1,
      51,    -1,    -1,    54,    55,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    66,    67,    68,    69,    70,
      71,    72,    -1,    -1,    -1,    -1,    -1,    -1,    79,    -1,
      81,    82,    83,    -1,    85,    30,    31,    32,    33,    34,
      35,    -1,    37,    38,    39,    40,    -1,    42,    -1,    -1,
      -1,    -1,    -1,    48,    -1,    -1,    51,    -1,    -1,    54,
      55,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    66,    67,    68,    69,    70,    71,    72,    -1,    -1,
      -1,    -1,    -1,    -1,    79,    -1,    81,    82,    83,    -1,
      85,    30,    31,    32,    33,    34,    35,    -1,    37,    38,
      39,    40,    -1,    42,    -1,    -1,    -1,    -1,    -1,    48,
      -1,    -1,    51,    -1,    -1,    54,    55,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    66,    67,    68,
      69,    70,    71,    72,    -1,    -1,    -1,    -1,    -1,    -1,
      79,    -1,    81,    82,    83,    -1,    85,    30,    31,    32,
      33,    34,    35,    -1,    37,    38,    39,    40,    -1,    -1,
      -1,    -1,    45,    -1,    -1,    48,    -1,    -1,    51,    -1,
      -1,    54,    55,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    66,    67,    68,    69,    70,    71,    72,
      -1,    -1,    -1,    -1,    -1,    -1,    79,    -1,    81,    82,
      83,    -1,    85,    30,    31,    32,    33,    34,    35,    -1,
      37,    38,    39,    40,    -1,    -1,    -1,    -1,    45,    -1,
      -1,    48,    -1,    -1,    51,    -1,    -1,    54,    55,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    66,
      67,    68,    69,    70,    71,    72,    -1,    -1,    -1,    -1,
      -1,    -1,    79,    -1,    81,    82,    83,    -1,    85,    30,
      31,    32,    33,    34,    35,    -1,    37,    38,    39,    40,
      -1,    -1,    -1,    -1,    45,    -1,    -1,    48,    -1,    -1,
      51,    -1,    -1,    54,    55,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    66,    67,    68,    69,    70,
      71,    72,    -1,    -1,    -1,    -1,    -1,    -1,    79,    -1,
      81,    82,    83,    -1,    85,    30,    31,    32,    33,    34,
      35,    -1,    37,    38,    39,    40,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    48,    -1,    -1,    51,    -1,    -1,    54,
      55,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    66,    67,    68,    69,    70,    71,    72,    -1,    -1,
      -1,    -1,    -1,    -1,    79,    -1,    81,    82,    83,    -1,
      85,    30,    31,    32,    33,    34,    35,    -1,    37,    38,
      39,    40,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    48,
      -1,    -1,    51,    -1,    -1,    54,    55,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    66,    67,    68,
      69,    70,    71,    72,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    81,    82,    83,    -1,    85,    30,    31,    32,
      33,    34,    35,    -1,    37,    38,    39,    40,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    48,    -1,    -1,    51,    -1,
      -1,    54,    55,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    66,    67,    68,    69,    70,    -1,    72,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    81,    82,
      83,    -1,    85,    30,    31,    32,    33,    34,    35,    -1,
      37,    38,    39,    40,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    48,    -1,    -1,    51,    -1,    -1,    54,    55,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    66,
      67,    68,    69,    -1,    -1,    72,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    81,    82,    83,    -1,    85,    30,
      31,    32,    33,    34,    35,    -1,    37,    -1,    39,    40,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    48,    -1,    -1,
      51,    -1,    -1,    54,    55,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    66,    67,    68,    69,    -1,
      -1,    72,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      81,    82,    83,    -1,    85,    30,    31,    32,    33,    34,
      35,    -1,    37,    -1,    39,    40,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    51,    -1,    -1,    54,
      55,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    66,    67,    68,    69,    -1,    -1,    72,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    81,    82,    83,    -1,
      85,    30,    31,    32,    33,    34,    35,    -1,    37,    -1,
      -1,    40,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    51,    -1,    -1,    54,    55,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    66,    67,    68,
      69,    -1,    -1,    72,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    81,    82,    83,    -1,    85,     3,     4,     5,
       6,    -1,     8,     9,    10,    11,    12,    -1,    -1,    15,
      16,    17,    -1,    19,    -1,    21,    -1,    23,    24,    25,
      26,    27,    28,    29,    -1,    31,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    41,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    49,    50,     4,     5,     6,    -1,     8,
       9,    10,    11,    12,    13,    -1,    15,    16,    17,    18,
      19,    -1,    -1,    -1,    23,    24,    25,    26,    27,    28,
      29,    -1,    31,     4,     5,     6,    -1,     8,     9,    10,
      11,    12,    41,    -1,    15,    16,    17,    -1,    19,    -1,
      49,    50,    23,    24,    25,    26,    27,    28,    29,    -1,
      31,     4,     5,     6,    -1,     8,     9,    10,    11,    12,
      41,    -1,    15,    16,    17,    46,    19,    -1,    49,    50,
      23,    24,    25,    26,    27,    28,    29,    -1,    31,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    41,    -1,
      -1,    -1,    -1,    -1,    47,    -1,    49,    50,     4,     5,
       6,    -1,     8,     9,    10,    11,    12,    -1,    -1,    15,
      16,    17,    -1,    19,    -1,    -1,    -1,    23,    24,    25,
      26,    27,    28,    29,    -1,    31,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    41,    -1,    -1,    -1,    -1,
      -1,    47,    -1,    49,    50,     4,     5,     6,    -1,     8,
       9,    10,    11,    12,    -1,    -1,    15,    16,    17,    -1,
      19,    -1,    -1,    -1,    23,    24,    25,    26,    27,    28,
      29,    -1,    31,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    41,    -1,    -1,    -1,    -1,    -1,    47,    -1,
      49,    50,     4,     5,     6,    -1,     8,     9,    10,    11,
      12,    -1,    -1,    15,    16,    17,    -1,    19,    -1,    -1,
      -1,    23,    24,    25,    26,    27,    28,    29,    -1,    31,
       4,     5,     6,    -1,    -1,    -1,    -1,    -1,    -1,    41,
      -1,     4,     5,     6,    -1,    -1,    -1,    49,    50,    23,
      24,    25,    26,    27,    28,    29,    -1,    31,    -1,    -1,
      23,    24,    25,    26,    27,    28,    29,    41,    31,    -1,
      -1,    45,     4,     5,     6,    49,    50,    -1,    41,    -1,
      -1,    -1,    45,     4,     5,     6,    49,    50,    -1,    -1,
      -1,    23,    24,    25,    26,    27,    28,    29,    -1,    31,
      -1,    -1,    23,    24,    25,    26,    27,    28,    29,    41,
      31,    -1,    -1,    45,     4,     5,     6,    49,    50,    -1,
      41,    42,    -1,    -1,    -1,     4,     5,     6,    49,    50,
      -1,    -1,    -1,    23,    24,    25,    26,    27,    28,    29,
      -1,    31,    -1,    -1,    23,    24,    25,    26,    27,    28,
      29,    41,    31,    -1,    -1,    45,     4,     5,     6,    49,
      50,    -1,    41,    42,    -1,    -1,    -1,    -1,    -1,    -1,
      49,    50,    -1,    -1,    -1,    23,    24,    25,    26,    27,
      28,    29,    -1,    31,     4,     5,     6,    -1,    -1,    -1,
      -1,    -1,    -1,    41,    42,    -1,    -1,    -1,    -1,    -1,
      -1,    49,    50,    23,    24,    25,    26,    27,    28,    29,
      -1,    31,     4,     5,     6,    -1,    -1,    -1,    -1,    -1,
      -1,    41,    42,    -1,    -1,    -1,    -1,    -1,    -1,    49,
      50,    23,    24,    25,    26,    27,    28,    29,    -1,    31,
      -1,    -1,    -1,    36,    -1,    -1,    -1,    -1,    -1,    41,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    49,    50,    52,
      53,    -1,    -1,    56,    57,    58,    59,    60,    61,    62,
      63,    64,    65,    36,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    75,    -1,    -1,    -1,    -1,    36,    -1,    52,
      53,    -1,    -1,    56,    57,    58,    59,    60,    61,    62,
      63,    64,    65,    52,    53,    -1,    -1,    56,    57,    58,
      59,    60,    61,    62,    63,    64,    65
};

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,    88,    89,     0,     3,     4,     5,     6,     8,     9,
      10,    11,    12,    15,    16,    17,    19,    21,    23,    24,
      25,    26,    27,    28,    29,    31,    41,    49,    50,    90,
      91,    94,    95,    98,    99,   106,   109,   110,   111,   112,
     113,   114,   117,   118,    25,    25,    41,   115,     6,   113,
     117,   119,   120,    45,    45,    41,    45,   113,    41,    46,
      94,   105,    41,    25,    41,    41,    25,    36,    52,    53,
      56,    57,    58,    59,    60,    61,    62,    63,    64,    65,
      75,   116,    41,    74,   113,   113,   113,   113,    45,    30,
      31,    32,    33,    34,    35,    37,    38,    39,    40,    48,
      51,    54,    55,    66,    67,    68,    69,    70,    71,    72,
      79,    81,    82,    83,    85,    36,   116,    41,    74,   113,
      41,    47,    43,   113,    45,   113,    93,    11,    45,   113,
      41,   113,   113,    46,   113,   113,   113,   113,   113,   113,
     113,   113,   113,   113,   113,   113,   123,   119,    25,    42,
     113,   113,   113,   113,   113,   113,    25,   113,   113,   113,
     113,   113,   113,   113,   113,   113,   113,   113,   113,   113,
     113,   113,   113,   113,   113,   113,   113,    24,    96,    97,
      25,    42,   101,   113,   113,    42,    42,    47,    94,    41,
      45,   113,    45,    25,    42,    42,    92,    95,    43,    86,
      42,    41,    41,    75,    44,    73,    86,    42,    43,    41,
      44,   100,   105,   105,   113,    42,   113,    45,    45,   113,
     100,    46,    46,    47,    95,   123,    36,   116,   119,   119,
     123,   113,   113,    46,    24,    96,    25,    43,   102,     7,
      42,   105,    42,    42,   113,    42,   113,    45,    42,    18,
     107,   107,    45,   113,    42,    42,    86,    86,    93,    42,
     120,    42,   105,   105,   105,    42,   105,    42,    42,   113,
      46,   108,   113,    47,    47,    47,    46,    46,   105,   105,
     105,    42,    16,    25,    47,   121,   122,    20,    44,    93,
      99,   103,   104,   121,   105,    36,    36,    75,    45,    47,
     122,   113,    93,    47,    45,    47,    99,   104,   113,   113,
     123,    45,    13,   107,    45,    45,    45,    86,    44,    36,
      93,   113,    45
};

/* YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr1[] =
{
       0,    87,    88,    89,    89,    90,    90,    90,    91,    92,
      92,    93,    93,    94,    94,    94,    94,    94,    94,    94,
      94,    94,    94,    95,    95,    96,    96,    97,    97,    98,
      98,    99,    99,   100,   100,   101,   101,   102,   102,   103,
     103,   103,   103,   104,   104,   105,   105,   106,   106,   107,
     107,   107,   108,   108,   109,   109,   110,   110,   111,   111,
     111,   111,   111,   111,   111,   111,   112,   113,   113,   113,
     113,   113,   113,   113,   113,   113,   113,   113,   113,   113,
     113,   113,   113,   113,   113,   113,   113,   113,   113,   113,
     113,   113,   113,   113,   113,   113,   113,   113,   113,   113,
     113,   113,   113,   113,   113,   113,   113,   113,   113,   114,
     114,   115,   115,   116,   116,   116,   116,   116,   116,   116,
     116,   116,   116,   116,   116,   117,   117,   117,   117,   117,
     117,   117,   117,   118,   118,   118,   119,   119,   120,   120,
     121,   121,   122,   122,   122,   123,   123
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
       1,     1,     1,     1,     1,     1,     1,     1,     4,     3,
       6,     1,     3,     1,     1,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     1,     1,     3,     6,     2,
       5,     2,     3,     4,     6,     6,     0,     1,     1,     3,
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
#line 150 "CMDgram.y"
      { }
#line 1890 "CMDgram.cc"
    break;

  case 3: /* decl_list: %empty  */
#line 155 "CMDgram.y"
      { (yyval.stmt) = nil; }
#line 1896 "CMDgram.cc"
    break;

  case 4: /* decl_list: decl_list decl  */
#line 157 "CMDgram.y"
      { if(!statementList) { statementList = (yyvsp[0].stmt); } else { statementList->append((yyvsp[0].stmt)); } }
#line 1902 "CMDgram.cc"
    break;

  case 5: /* decl: stmt  */
#line 162 "CMDgram.y"
      { (yyval.stmt) = (yyvsp[0].stmt); }
#line 1908 "CMDgram.cc"
    break;

  case 6: /* decl: fn_decl_stmt  */
#line 164 "CMDgram.y"
      { (yyval.stmt) = (yyvsp[0].stmt); }
#line 1914 "CMDgram.cc"
    break;

  case 7: /* decl: package_decl  */
#line 166 "CMDgram.y"
     { (yyval.stmt) = (yyvsp[0].stmt); }
#line 1920 "CMDgram.cc"
    break;

  case 8: /* package_decl: rwPACKAGE IDENT '{' fn_decl_list '}' ';'  */
#line 171 "CMDgram.y"
      { (yyval.stmt) = (yyvsp[-2].stmt); for(StmtNode *walk = ((yyvsp[-2].stmt));walk;walk = walk->getNext() ) walk->setPackage((yyvsp[-4].s)); }
#line 1926 "CMDgram.cc"
    break;

  case 9: /* fn_decl_list: fn_decl_stmt  */
#line 176 "CMDgram.y"
      { (yyval.stmt) = (yyvsp[0].stmt); }
#line 1932 "CMDgram.cc"
    break;

  case 10: /* fn_decl_list: fn_decl_list fn_decl_stmt  */
#line 178 "CMDgram.y"
      { (yyval.stmt) = (yyvsp[-1].stmt); ((yyvsp[-1].stmt))->append((yyvsp[0].stmt));  }
#line 1938 "CMDgram.cc"
    break;

  case 11: /* statement_list: %empty  */
#line 183 "CMDgram.y"
      { (yyval.stmt) = nil; }
#line 1944 "CMDgram.cc"
    break;

  case 12: /* statement_list: statement_list stmt  */
#line 185 "CMDgram.y"
      { if(!(yyvsp[-1].stmt)) { (yyval.stmt) = (yyvsp[0].stmt); } else { ((yyvsp[-1].stmt))->append((yyvsp[0].stmt)); (yyval.stmt) = (yyvsp[-1].stmt); } }
#line 1950 "CMDgram.cc"
    break;

  case 18: /* stmt: rwBREAK ';'  */
#line 195 "CMDgram.y"
      { (yyval.stmt) = BreakStmtNode::alloc(); }
#line 1956 "CMDgram.cc"
    break;

  case 19: /* stmt: rwCONTINUE ';'  */
#line 197 "CMDgram.y"
      { (yyval.stmt) = ContinueStmtNode::alloc(); }
#line 1962 "CMDgram.cc"
    break;

  case 20: /* stmt: rwRETURN ';'  */
#line 199 "CMDgram.y"
      { (yyval.stmt) = ReturnStmtNode::alloc(NULL); }
#line 1968 "CMDgram.cc"
    break;

  case 21: /* stmt: rwRETURN expr ';'  */
#line 201 "CMDgram.y"
      { (yyval.stmt) = ReturnStmtNode::alloc((yyvsp[-1].expr)); }
#line 1974 "CMDgram.cc"
    break;

  case 22: /* stmt: expression_stmt ';'  */
#line 203 "CMDgram.y"
      { (yyval.stmt) = (yyvsp[-1].stmt); }
#line 1980 "CMDgram.cc"
    break;

  case 23: /* fn_decl_stmt: rwDEFINE IDENT '(' var_list_decl ')' '{' statement_list '}'  */
#line 208 "CMDgram.y"
      { (yyval.stmt) = FunctionDeclStmtNode::alloc((yyvsp[-6].s), NULL, (yyvsp[-4].var), (yyvsp[-1].stmt)); }
#line 1986 "CMDgram.cc"
    break;

  case 24: /* fn_decl_stmt: rwDEFINE IDENT opCOLONCOLON IDENT '(' var_list_decl ')' '{' statement_list '}'  */
#line 210 "CMDgram.y"
     { (yyval.stmt) = FunctionDeclStmtNode::alloc((yyvsp[-6].s), (yyvsp[-8].s), (yyvsp[-4].var), (yyvsp[-1].stmt)); }
#line 1992 "CMDgram.cc"
    break;

  case 25: /* var_list_decl: %empty  */
#line 215 "CMDgram.y"
     { (yyval.var) = NULL; }
#line 1998 "CMDgram.cc"
    break;

  case 26: /* var_list_decl: var_list  */
#line 217 "CMDgram.y"
     { (yyval.var) = (yyvsp[0].var); }
#line 2004 "CMDgram.cc"
    break;

  case 27: /* var_list: VAR  */
#line 222 "CMDgram.y"
      { (yyval.var) = VarNode::alloc((yyvsp[0].s), NULL); }
#line 2010 "CMDgram.cc"
    break;

  case 28: /* var_list: var_list ',' VAR  */
#line 224 "CMDgram.y"
      { (yyval.var) = (yyvsp[-2].var); ((StmtNode*)((yyvsp[-2].var)))->append((StmtNode*)VarNode::alloc((yyvsp[0].s), NULL)); }
#line 2016 "CMDgram.cc"
    break;

  case 29: /* datablock_decl: rwDATABLOCK IDENT '(' IDENT parent_block ')' '{' slot_assign_list '}' ';'  */
#line 229 "CMDgram.y"
      { (yyval.stmt) = ObjectDeclNode::alloc(ConstantNode::alloc((yyvsp[-8].s)), ConstantNode::alloc((yyvsp[-6].s)), NULL, (yyvsp[-5].s), (yyvsp[-2].slist), NULL, true); }
#line 2022 "CMDgram.cc"
    break;

  case 30: /* datablock_decl: rwDATABLOCK IDENT '(' IDENT parent_block ')' '{' '}' ';'  */
#line 231 "CMDgram.y"
      { (yyval.stmt) = ObjectDeclNode::alloc(ConstantNode::alloc((yyvsp[-7].s)), ConstantNode::alloc((yyvsp[-5].s)), NULL, (yyvsp[-4].s), NULL, NULL, true); }
#line 2028 "CMDgram.cc"
    break;

  case 31: /* object_decl: rwDECLARE class_name_expr '(' object_name parent_block object_args ')' '{' object_declare_block '}'  */
#line 236 "CMDgram.y"
      { (yyval.od) = ObjectDeclNode::alloc((yyvsp[-8].expr), (yyvsp[-6].expr), (yyvsp[-4].expr), (yyvsp[-5].s), (yyvsp[-1].odcl).slots, (yyvsp[-1].odcl).decls, false); }
#line 2034 "CMDgram.cc"
    break;

  case 32: /* object_decl: rwDECLARE class_name_expr '(' object_name parent_block object_args ')'  */
#line 238 "CMDgram.y"
      { (yyval.od) = ObjectDeclNode::alloc((yyvsp[-5].expr), (yyvsp[-3].expr), (yyvsp[-1].expr), (yyvsp[-2].s), NULL, NULL, false); }
#line 2040 "CMDgram.cc"
    break;

  case 33: /* parent_block: %empty  */
#line 243 "CMDgram.y"
      { (yyval.s) = NULL; }
#line 2046 "CMDgram.cc"
    break;

  case 34: /* parent_block: ':' IDENT  */
#line 245 "CMDgram.y"
      { (yyval.s) = (yyvsp[0].s); }
#line 2052 "CMDgram.cc"
    break;

  case 35: /* object_name: %empty  */
#line 250 "CMDgram.y"
      { (yyval.expr) = StrConstNode::alloc("", false); }
#line 2058 "CMDgram.cc"
    break;

  case 36: /* object_name: expr  */
#line 252 "CMDgram.y"
      { (yyval.expr) = (yyvsp[0].expr); }
#line 2064 "CMDgram.cc"
    break;

  case 37: /* object_args: %empty  */
#line 257 "CMDgram.y"
      { (yyval.expr) = NULL; }
#line 2070 "CMDgram.cc"
    break;

  case 38: /* object_args: ',' expr_list  */
#line 259 "CMDgram.y"
      { (yyval.expr) = (yyvsp[0].expr); }
#line 2076 "CMDgram.cc"
    break;

  case 39: /* object_declare_block: %empty  */
#line 264 "CMDgram.y"
      { (yyval.odcl).slots = NULL; (yyval.odcl).decls = NULL; }
#line 2082 "CMDgram.cc"
    break;

  case 40: /* object_declare_block: slot_assign_list  */
#line 266 "CMDgram.y"
      { (yyval.odcl).slots = (yyvsp[0].slist); (yyval.odcl).decls = NULL; }
#line 2088 "CMDgram.cc"
    break;

  case 41: /* object_declare_block: object_decl_list  */
#line 268 "CMDgram.y"
      { (yyval.odcl).slots = NULL; (yyval.odcl).decls = (yyvsp[0].od); }
#line 2094 "CMDgram.cc"
    break;

  case 42: /* object_declare_block: slot_assign_list object_decl_list  */
#line 270 "CMDgram.y"
      { (yyval.odcl).slots = (yyvsp[-1].slist); (yyval.odcl).decls = (yyvsp[0].od); }
#line 2100 "CMDgram.cc"
    break;

  case 43: /* object_decl_list: object_decl ';'  */
#line 275 "CMDgram.y"
      { (yyval.od) = (yyvsp[-1].od); }
#line 2106 "CMDgram.cc"
    break;

  case 44: /* object_decl_list: object_decl_list object_decl ';'  */
#line 277 "CMDgram.y"
      { (yyvsp[-2].od)->append((yyvsp[-1].od)); (yyval.od) = (yyvsp[-2].od); }
#line 2112 "CMDgram.cc"
    break;

  case 45: /* stmt_block: '{' statement_list '}'  */
#line 282 "CMDgram.y"
      { (yyval.stmt) = (yyvsp[-1].stmt); }
#line 2118 "CMDgram.cc"
    break;

  case 46: /* stmt_block: stmt  */
#line 284 "CMDgram.y"
      { (yyval.stmt) = (yyvsp[0].stmt); }
#line 2124 "CMDgram.cc"
    break;

  case 47: /* switch_stmt: rwSWITCH '(' expr ')' '{' case_block '}'  */
#line 289 "CMDgram.y"
      { (yyval.stmt) = (yyvsp[-1].ifnode); (yyvsp[-1].ifnode)->propagateSwitchExpr((yyvsp[-4].expr), false); }
#line 2130 "CMDgram.cc"
    break;

  case 48: /* switch_stmt: rwSWITCHSTR '(' expr ')' '{' case_block '}'  */
#line 291 "CMDgram.y"
      { (yyval.stmt) = (yyvsp[-1].ifnode); (yyvsp[-1].ifnode)->propagateSwitchExpr((yyvsp[-4].expr), true); }
#line 2136 "CMDgram.cc"
    break;

  case 49: /* case_block: rwCASE case_expr ':' statement_list  */
#line 296 "CMDgram.y"
      { (yyval.ifnode) = IfStmtNode::alloc((yyvsp[-3].i), (yyvsp[-2].expr), (yyvsp[0].stmt), NULL, false); }
#line 2142 "CMDgram.cc"
    break;

  case 50: /* case_block: rwCASE case_expr ':' statement_list rwDEFAULT ':' statement_list  */
#line 298 "CMDgram.y"
      { (yyval.ifnode) = IfStmtNode::alloc((yyvsp[-6].i), (yyvsp[-5].expr), (yyvsp[-3].stmt), (yyvsp[0].stmt), false); }
#line 2148 "CMDgram.cc"
    break;

  case 51: /* case_block: rwCASE case_expr ':' statement_list case_block  */
#line 300 "CMDgram.y"
      { (yyval.ifnode) = IfStmtNode::alloc((yyvsp[-4].i), (yyvsp[-3].expr), (yyvsp[-1].stmt), (yyvsp[0].ifnode), true); }
#line 2154 "CMDgram.cc"
    break;

  case 52: /* case_expr: expr  */
#line 305 "CMDgram.y"
      { (yyval.expr) = (yyvsp[0].expr);}
#line 2160 "CMDgram.cc"
    break;

  case 53: /* case_expr: case_expr rwCASEOR expr  */
#line 307 "CMDgram.y"
      { ((yyvsp[-2].expr))->append((yyvsp[0].expr)); (yyval.expr)=(yyvsp[-2].expr); }
#line 2166 "CMDgram.cc"
    break;

  case 54: /* if_stmt: rwIF '(' expr ')' stmt_block  */
#line 312 "CMDgram.y"
      { (yyval.stmt) = IfStmtNode::alloc((yyvsp[-4].i), (yyvsp[-2].expr), (yyvsp[0].stmt), NULL, false); }
#line 2172 "CMDgram.cc"
    break;

  case 55: /* if_stmt: rwIF '(' expr ')' stmt_block rwELSE stmt_block  */
#line 314 "CMDgram.y"
      { (yyval.stmt) = IfStmtNode::alloc((yyvsp[-6].i), (yyvsp[-4].expr), (yyvsp[-2].stmt), (yyvsp[0].stmt), false); }
#line 2178 "CMDgram.cc"
    break;

  case 56: /* while_stmt: rwWHILE '(' expr ')' stmt_block  */
#line 319 "CMDgram.y"
      { (yyval.stmt) = LoopStmtNode::alloc((yyvsp[-4].i), nil, (yyvsp[-2].expr), nil, (yyvsp[0].stmt), false); }
#line 2184 "CMDgram.cc"
    break;

  case 57: /* while_stmt: rwDO stmt_block rwWHILE '(' expr ')'  */
#line 321 "CMDgram.y"
      { (yyval.stmt) = LoopStmtNode::alloc((yyvsp[-3].i), nil, (yyvsp[-1].expr), nil, (yyvsp[-4].stmt), true); }
#line 2190 "CMDgram.cc"
    break;

  case 58: /* for_stmt: rwFOR '(' expr ';' expr ';' expr ')' stmt_block  */
#line 326 "CMDgram.y"
      { (yyval.stmt) = LoopStmtNode::alloc((yyvsp[-8].i), (yyvsp[-6].expr), (yyvsp[-4].expr), (yyvsp[-2].expr), (yyvsp[0].stmt), false); }
#line 2196 "CMDgram.cc"
    break;

  case 59: /* for_stmt: rwFOR '(' expr ';' expr ';' ')' stmt_block  */
#line 328 "CMDgram.y"
      { (yyval.stmt) = LoopStmtNode::alloc((yyvsp[-7].i), (yyvsp[-5].expr), (yyvsp[-3].expr), NULL, (yyvsp[0].stmt), false); }
#line 2202 "CMDgram.cc"
    break;

  case 60: /* for_stmt: rwFOR '(' expr ';' ';' expr ')' stmt_block  */
#line 330 "CMDgram.y"
      { (yyval.stmt) = LoopStmtNode::alloc((yyvsp[-7].i), (yyvsp[-5].expr), NULL, (yyvsp[-2].expr), (yyvsp[0].stmt), false); }
#line 2208 "CMDgram.cc"
    break;

  case 61: /* for_stmt: rwFOR '(' expr ';' ';' ')' stmt_block  */
#line 332 "CMDgram.y"
      { (yyval.stmt) = LoopStmtNode::alloc((yyvsp[-6].i), (yyvsp[-4].expr), NULL, NULL, (yyvsp[0].stmt), false); }
#line 2214 "CMDgram.cc"
    break;

  case 62: /* for_stmt: rwFOR '(' ';' expr ';' expr ')' stmt_block  */
#line 334 "CMDgram.y"
      { (yyval.stmt) = LoopStmtNode::alloc((yyvsp[-7].i), NULL, (yyvsp[-4].expr), (yyvsp[-2].expr), (yyvsp[0].stmt), false); }
#line 2220 "CMDgram.cc"
    break;

  case 63: /* for_stmt: rwFOR '(' ';' expr ';' ')' stmt_block  */
#line 336 "CMDgram.y"
      { (yyval.stmt) = LoopStmtNode::alloc((yyvsp[-6].i), NULL, (yyvsp[-3].expr), NULL, (yyvsp[0].stmt), false); }
#line 2226 "CMDgram.cc"
    break;

  case 64: /* for_stmt: rwFOR '(' ';' ';' expr ')' stmt_block  */
#line 338 "CMDgram.y"
      { (yyval.stmt) = LoopStmtNode::alloc((yyvsp[-6].i), NULL, NULL, (yyvsp[-2].expr), (yyvsp[0].stmt), false); }
#line 2232 "CMDgram.cc"
    break;

  case 65: /* for_stmt: rwFOR '(' ';' ';' ')' stmt_block  */
#line 340 "CMDgram.y"
      { (yyval.stmt) = LoopStmtNode::alloc((yyvsp[-5].i), NULL, NULL, NULL, (yyvsp[0].stmt), false); }
#line 2238 "CMDgram.cc"
    break;

  case 66: /* expression_stmt: stmt_expr  */
#line 345 "CMDgram.y"
      { (yyval.stmt) = (yyvsp[0].expr); }
#line 2244 "CMDgram.cc"
    break;

  case 67: /* expr: stmt_expr  */
#line 350 "CMDgram.y"
      { (yyval.expr) = (yyvsp[0].expr); }
#line 2250 "CMDgram.cc"
    break;

  case 68: /* expr: '(' expr ')'  */
#line 352 "CMDgram.y"
      { (yyval.expr) = (yyvsp[-1].expr); }
#line 2256 "CMDgram.cc"
    break;

  case 69: /* expr: rwCVLSTART expr_list_decl '}'  */
#line 354 "CMDgram.y"
      { (yyval.expr) = ValueListExprNode::alloc((yyvsp[-1].expr)); }
#line 2262 "CMDgram.cc"
    break;

  case 70: /* expr: expr '^' expr  */
#line 356 "CMDgram.y"
      { (yyval.expr) = IntBinaryExprNode::alloc((yyvsp[-1].i), (yyvsp[-2].expr), (yyvsp[0].expr)); }
#line 2268 "CMDgram.cc"
    break;

  case 71: /* expr: expr '%' expr  */
#line 358 "CMDgram.y"
      { (yyval.expr) = IntBinaryExprNode::alloc((yyvsp[-1].i), (yyvsp[-2].expr), (yyvsp[0].expr)); }
#line 2274 "CMDgram.cc"
    break;

  case 72: /* expr: expr '&' expr  */
#line 360 "CMDgram.y"
      { (yyval.expr) = IntBinaryExprNode::alloc((yyvsp[-1].i), (yyvsp[-2].expr), (yyvsp[0].expr)); }
#line 2280 "CMDgram.cc"
    break;

  case 73: /* expr: expr '|' expr  */
#line 362 "CMDgram.y"
      { (yyval.expr) = IntBinaryExprNode::alloc((yyvsp[-1].i), (yyvsp[-2].expr), (yyvsp[0].expr)); }
#line 2286 "CMDgram.cc"
    break;

  case 74: /* expr: expr '+' expr  */
#line 364 "CMDgram.y"
      { (yyval.expr) = FloatBinaryExprNode::alloc((yyvsp[-1].i), (yyvsp[-2].expr), (yyvsp[0].expr)); }
#line 2292 "CMDgram.cc"
    break;

  case 75: /* expr: expr '-' expr  */
#line 366 "CMDgram.y"
      { (yyval.expr) = FloatBinaryExprNode::alloc((yyvsp[-1].i), (yyvsp[-2].expr), (yyvsp[0].expr)); }
#line 2298 "CMDgram.cc"
    break;

  case 76: /* expr: expr '*' expr  */
#line 368 "CMDgram.y"
      { (yyval.expr) = FloatBinaryExprNode::alloc((yyvsp[-1].i), (yyvsp[-2].expr), (yyvsp[0].expr)); }
#line 2304 "CMDgram.cc"
    break;

  case 77: /* expr: expr '/' expr  */
#line 370 "CMDgram.y"
      { (yyval.expr) = FloatBinaryExprNode::alloc((yyvsp[-1].i), (yyvsp[-2].expr), (yyvsp[0].expr)); }
#line 2310 "CMDgram.cc"
    break;

  case 78: /* expr: '-' expr  */
#line 372 "CMDgram.y"
      { (yyval.expr) = FloatUnaryExprNode::alloc((yyvsp[-1].i), (yyvsp[0].expr)); }
#line 2316 "CMDgram.cc"
    break;

  case 79: /* expr: expr '?' expr ':' expr  */
#line 374 "CMDgram.y"
      { (yyval.expr) = ConditionalExprNode::alloc((yyvsp[-4].expr), (yyvsp[-2].expr), (yyvsp[0].expr)); }
#line 2322 "CMDgram.cc"
    break;

  case 80: /* expr: expr '<' expr  */
#line 376 "CMDgram.y"
      { (yyval.expr) = IntBinaryExprNode::alloc((yyvsp[-1].i), (yyvsp[-2].expr), (yyvsp[0].expr)); }
#line 2328 "CMDgram.cc"
    break;

  case 81: /* expr: expr '>' expr  */
#line 378 "CMDgram.y"
      { (yyval.expr) = IntBinaryExprNode::alloc((yyvsp[-1].i), (yyvsp[-2].expr), (yyvsp[0].expr)); }
#line 2334 "CMDgram.cc"
    break;

  case 82: /* expr: expr opGE expr  */
#line 380 "CMDgram.y"
      { (yyval.expr) = IntBinaryExprNode::alloc((yyvsp[-1].i), (yyvsp[-2].expr), (yyvsp[0].expr)); }
#line 2340 "CMDgram.cc"
    break;

  case 83: /* expr: expr opLE expr  */
#line 382 "CMDgram.y"
      { (yyval.expr) = IntBinaryExprNode::alloc((yyvsp[-1].i), (yyvsp[-2].expr), (yyvsp[0].expr)); }
#line 2346 "CMDgram.cc"
    break;

  case 84: /* expr: expr opEQ expr  */
#line 384 "CMDgram.y"
      { (yyval.expr) = IntBinaryExprNode::alloc((yyvsp[-1].i), (yyvsp[-2].expr), (yyvsp[0].expr)); }
#line 2352 "CMDgram.cc"
    break;

  case 85: /* expr: expr opNE expr  */
#line 386 "CMDgram.y"
      { (yyval.expr) = IntBinaryExprNode::alloc((yyvsp[-1].i), (yyvsp[-2].expr), (yyvsp[0].expr)); }
#line 2358 "CMDgram.cc"
    break;

  case 86: /* expr: expr opOR expr  */
#line 388 "CMDgram.y"
      { (yyval.expr) = IntBinaryExprNode::alloc((yyvsp[-1].i), (yyvsp[-2].expr), (yyvsp[0].expr)); }
#line 2364 "CMDgram.cc"
    break;

  case 87: /* expr: expr opSHL expr  */
#line 390 "CMDgram.y"
      { (yyval.expr) = IntBinaryExprNode::alloc((yyvsp[-1].i), (yyvsp[-2].expr), (yyvsp[0].expr)); }
#line 2370 "CMDgram.cc"
    break;

  case 88: /* expr: expr opSHR expr  */
#line 392 "CMDgram.y"
      { (yyval.expr) = IntBinaryExprNode::alloc((yyvsp[-1].i), (yyvsp[-2].expr), (yyvsp[0].expr)); }
#line 2376 "CMDgram.cc"
    break;

  case 89: /* expr: expr opAND expr  */
#line 394 "CMDgram.y"
      { (yyval.expr) = IntBinaryExprNode::alloc((yyvsp[-1].i), (yyvsp[-2].expr), (yyvsp[0].expr)); }
#line 2382 "CMDgram.cc"
    break;

  case 90: /* expr: expr opSTREQ expr  */
#line 396 "CMDgram.y"
      { (yyval.expr) = StreqExprNode::alloc((yyvsp[-2].expr), (yyvsp[0].expr), true); }
#line 2388 "CMDgram.cc"
    break;

  case 91: /* expr: expr opSTRNE expr  */
#line 398 "CMDgram.y"
      { (yyval.expr) = StreqExprNode::alloc((yyvsp[-2].expr), (yyvsp[0].expr), false); }
#line 2394 "CMDgram.cc"
    break;

  case 92: /* expr: expr opFORGIVE expr  */
#line 400 "CMDgram.y"
      { (yyval.expr) = StrForgiveExprNode::alloc((yyvsp[-2].expr), (yyvsp[0].expr)); }
#line 2400 "CMDgram.cc"
    break;

  case 93: /* expr: expr '@' expr  */
#line 402 "CMDgram.y"
      { (yyval.expr) = StrcatExprNode::alloc((yyvsp[-2].expr), (yyvsp[0].expr), (yyvsp[-1].i)); }
#line 2406 "CMDgram.cc"
    break;

  case 94: /* expr: expr opINSTANCE expr  */
#line 404 "CMDgram.y"
      { (yyval.expr) = InstanceOfExprNode::alloc((yyvsp[-2].expr), (yyvsp[0].expr)); }
#line 2412 "CMDgram.cc"
    break;

  case 95: /* expr: expr opIDXSTART expr ']'  */
#line 406 "CMDgram.y"
      { (yyvsp[-3].expr)->append((yyvsp[-1].expr)); (yyval.expr) = FuncCallExprNode::alloc(StringTable->insert("getWord"), NULL, (yyvsp[-3].expr), false); }
#line 2418 "CMDgram.cc"
    break;

  case 96: /* expr: expr opIDXSTART expr opRANGE expr ']'  */
#line 408 "CMDgram.y"
      { (yyvsp[-3].expr)->append((yyvsp[-1].expr)); (yyvsp[-5].expr)->append((yyvsp[-3].expr)); (yyval.expr) = FuncCallExprNode::alloc(StringTable->insert("getWords"), NULL, (yyvsp[-5].expr), false); }
#line 2424 "CMDgram.cc"
    break;

  case 97: /* expr: '!' expr  */
#line 410 "CMDgram.y"
      { (yyval.expr) = IntUnaryExprNode::alloc((yyvsp[-1].i), (yyvsp[0].expr)); }
#line 2430 "CMDgram.cc"
    break;

  case 98: /* expr: '~' expr  */
#line 412 "CMDgram.y"
      { (yyval.expr) = IntUnaryExprNode::alloc((yyvsp[-1].i), (yyvsp[0].expr)); }
#line 2436 "CMDgram.cc"
    break;

  case 99: /* expr: TAGATOM  */
#line 414 "CMDgram.y"
      { (yyval.expr) = StrConstNode::alloc((yyvsp[0].str), true); }
#line 2442 "CMDgram.cc"
    break;

  case 100: /* expr: FLTCONST  */
#line 416 "CMDgram.y"
      { (yyval.expr) = FloatNode::alloc((yyvsp[0].f)); }
#line 2448 "CMDgram.cc"
    break;

  case 101: /* expr: INTCONST  */
#line 418 "CMDgram.y"
      { (yyval.expr) = IntNode::alloc((yyvsp[0].i)); }
#line 2454 "CMDgram.cc"
    break;

  case 102: /* expr: rwBREAK  */
#line 420 "CMDgram.y"
      { (yyval.expr) = ConstantNode::alloc(StringTable->insert("break")); }
#line 2460 "CMDgram.cc"
    break;

  case 103: /* expr: slot_acc  */
#line 422 "CMDgram.y"
      { (yyval.expr) = SlotAccessNode::alloc((yyvsp[0].slot).object, (yyvsp[0].slot).array, (yyvsp[0].slot).slotName); }
#line 2466 "CMDgram.cc"
    break;

  case 104: /* expr: IDENT  */
#line 424 "CMDgram.y"
      { (yyval.expr) = ConstantNode::alloc((yyvsp[0].s)); }
#line 2472 "CMDgram.cc"
    break;

  case 105: /* expr: STRATOM  */
#line 426 "CMDgram.y"
      { (yyval.expr) = StrConstNode::alloc((yyvsp[0].str), false); }
#line 2478 "CMDgram.cc"
    break;

  case 106: /* expr: PTHATOM  */
#line 428 "CMDgram.y"
      { (yyval.expr) = FindObjectNode::alloc(StringTable->insert((yyvsp[0].str))); }
#line 2484 "CMDgram.cc"
    break;

  case 107: /* expr: VAR  */
#line 430 "CMDgram.y"
      { (yyval.expr) = (ExprNode*)VarNode::alloc((yyvsp[0].s), NULL); }
#line 2490 "CMDgram.cc"
    break;

  case 108: /* expr: VAR '[' aidx_expr ']'  */
#line 432 "CMDgram.y"
      { (yyval.expr) = (ExprNode*)VarNode::alloc((yyvsp[-3].s), (yyvsp[-1].expr)); }
#line 2496 "CMDgram.cc"
    break;

  case 109: /* slot_acc: expr '.' IDENT  */
#line 437 "CMDgram.y"
      { (yyval.slot).object = (yyvsp[-2].expr); (yyval.slot).slotName = (yyvsp[0].s); (yyval.slot).array = NULL; }
#line 2502 "CMDgram.cc"
    break;

  case 110: /* slot_acc: expr '.' IDENT '[' aidx_expr ']'  */
#line 439 "CMDgram.y"
      { (yyval.slot).object = (yyvsp[-5].expr); (yyval.slot).slotName = (yyvsp[-3].s); (yyval.slot).array = (yyvsp[-1].expr); }
#line 2508 "CMDgram.cc"
    break;

  case 111: /* class_name_expr: IDENT  */
#line 444 "CMDgram.y"
      { (yyval.expr) = ConstantNode::alloc((yyvsp[0].s)); }
#line 2514 "CMDgram.cc"
    break;

  case 112: /* class_name_expr: '(' expr ')'  */
#line 446 "CMDgram.y"
      { (yyval.expr) = (yyvsp[-1].expr); }
#line 2520 "CMDgram.cc"
    break;

  case 113: /* assign_op_struct: opPLUSPLUS  */
#line 451 "CMDgram.y"
      { (yyval.asn).token = '+'; (yyval.asn).expr = FloatNode::alloc(1); }
#line 2526 "CMDgram.cc"
    break;

  case 114: /* assign_op_struct: opMINUSMINUS  */
#line 453 "CMDgram.y"
      { (yyval.asn).token = '-'; (yyval.asn).expr = FloatNode::alloc(1); }
#line 2532 "CMDgram.cc"
    break;

  case 115: /* assign_op_struct: opPLASN expr  */
#line 455 "CMDgram.y"
      { (yyval.asn).token = '+'; (yyval.asn).expr = (yyvsp[0].expr); }
#line 2538 "CMDgram.cc"
    break;

  case 116: /* assign_op_struct: opMIASN expr  */
#line 457 "CMDgram.y"
      { (yyval.asn).token = '-'; (yyval.asn).expr = (yyvsp[0].expr); }
#line 2544 "CMDgram.cc"
    break;

  case 117: /* assign_op_struct: opMLASN expr  */
#line 459 "CMDgram.y"
      { (yyval.asn).token = '*'; (yyval.asn).expr = (yyvsp[0].expr); }
#line 2550 "CMDgram.cc"
    break;

  case 118: /* assign_op_struct: opDVASN expr  */
#line 461 "CMDgram.y"
      { (yyval.asn).token = '/'; (yyval.asn).expr = (yyvsp[0].expr); }
#line 2556 "CMDgram.cc"
    break;

  case 119: /* assign_op_struct: opMODASN expr  */
#line 463 "CMDgram.y"
      { (yyval.asn).token = '%'; (yyval.asn).expr = (yyvsp[0].expr); }
#line 2562 "CMDgram.cc"
    break;

  case 120: /* assign_op_struct: opANDASN expr  */
#line 465 "CMDgram.y"
      { (yyval.asn).token = '&'; (yyval.asn).expr = (yyvsp[0].expr); }
#line 2568 "CMDgram.cc"
    break;

  case 121: /* assign_op_struct: opXORASN expr  */
#line 467 "CMDgram.y"
      { (yyval.asn).token = '^'; (yyval.asn).expr = (yyvsp[0].expr); }
#line 2574 "CMDgram.cc"
    break;

  case 122: /* assign_op_struct: opORASN expr  */
#line 469 "CMDgram.y"
      { (yyval.asn).token = '|'; (yyval.asn).expr = (yyvsp[0].expr); }
#line 2580 "CMDgram.cc"
    break;

  case 123: /* assign_op_struct: opSLASN expr  */
#line 471 "CMDgram.y"
      { (yyval.asn).token = opSHL; (yyval.asn).expr = (yyvsp[0].expr); }
#line 2586 "CMDgram.cc"
    break;

  case 124: /* assign_op_struct: opSRASN expr  */
#line 473 "CMDgram.y"
      { (yyval.asn).token = opSHR; (yyval.asn).expr = (yyvsp[0].expr); }
#line 2592 "CMDgram.cc"
    break;

  case 125: /* stmt_expr: funcall_expr  */
#line 478 "CMDgram.y"
      { (yyval.expr) = (yyvsp[0].expr); }
#line 2598 "CMDgram.cc"
    break;

  case 126: /* stmt_expr: object_decl  */
#line 480 "CMDgram.y"
      { (yyval.expr) = (yyvsp[0].od); }
#line 2604 "CMDgram.cc"
    break;

  case 127: /* stmt_expr: VAR '=' expr  */
#line 482 "CMDgram.y"
      { (yyval.expr) = AssignExprNode::alloc((yyvsp[-2].s), NULL, (yyvsp[0].expr)); }
#line 2610 "CMDgram.cc"
    break;

  case 128: /* stmt_expr: VAR '[' aidx_expr ']' '=' expr  */
#line 484 "CMDgram.y"
      { (yyval.expr) = AssignExprNode::alloc((yyvsp[-5].s), (yyvsp[-3].expr), (yyvsp[0].expr)); }
#line 2616 "CMDgram.cc"
    break;

  case 129: /* stmt_expr: VAR assign_op_struct  */
#line 486 "CMDgram.y"
      { (yyval.expr) = AssignOpExprNode::alloc((yyvsp[-1].s), NULL, (yyvsp[0].asn).expr, (yyvsp[0].asn).token); }
#line 2622 "CMDgram.cc"
    break;

  case 130: /* stmt_expr: VAR '[' aidx_expr ']' assign_op_struct  */
#line 488 "CMDgram.y"
      { (yyval.expr) = AssignOpExprNode::alloc((yyvsp[-4].s), (yyvsp[-2].expr), (yyvsp[0].asn).expr, (yyvsp[0].asn).token); }
#line 2628 "CMDgram.cc"
    break;

  case 131: /* stmt_expr: slot_acc assign_op_struct  */
#line 490 "CMDgram.y"
      { (yyval.expr) = SlotAssignOpNode::alloc((yyvsp[-1].slot).object, (yyvsp[-1].slot).slotName, (yyvsp[-1].slot).array, (yyvsp[0].asn).token, (yyvsp[0].asn).expr); }
#line 2634 "CMDgram.cc"
    break;

  case 132: /* stmt_expr: slot_acc '=' expr  */
#line 492 "CMDgram.y"
      { (yyval.expr) = SlotAssignNode::alloc((yyvsp[-2].slot).object, (yyvsp[-2].slot).array, (yyvsp[-2].slot).slotName, (yyvsp[0].expr)); }
#line 2640 "CMDgram.cc"
    break;

  case 133: /* funcall_expr: IDENT '(' expr_list_decl ')'  */
#line 497 "CMDgram.y"
     { (yyval.expr) = FuncCallExprNode::alloc((yyvsp[-3].s), NULL, (yyvsp[-1].expr), false); }
#line 2646 "CMDgram.cc"
    break;

  case 134: /* funcall_expr: IDENT opCOLONCOLON IDENT '(' expr_list_decl ')'  */
#line 499 "CMDgram.y"
     { (yyval.expr) = FuncCallExprNode::alloc((yyvsp[-3].s), (yyvsp[-5].s), (yyvsp[-1].expr), false); }
#line 2652 "CMDgram.cc"
    break;

  case 135: /* funcall_expr: expr '.' IDENT '(' expr_list_decl ')'  */
#line 501 "CMDgram.y"
      { (yyvsp[-5].expr)->append((yyvsp[-1].expr)); (yyval.expr) = FuncCallExprNode::alloc((yyvsp[-3].s), NULL, (yyvsp[-5].expr), true); }
#line 2658 "CMDgram.cc"
    break;

  case 136: /* expr_list_decl: %empty  */
#line 506 "CMDgram.y"
      { (yyval.expr) = NULL; }
#line 2664 "CMDgram.cc"
    break;

  case 137: /* expr_list_decl: expr_list  */
#line 508 "CMDgram.y"
      { (yyval.expr) = (yyvsp[0].expr); }
#line 2670 "CMDgram.cc"
    break;

  case 138: /* expr_list: expr  */
#line 513 "CMDgram.y"
      { (yyval.expr) = (yyvsp[0].expr); }
#line 2676 "CMDgram.cc"
    break;

  case 139: /* expr_list: expr_list ',' expr  */
#line 515 "CMDgram.y"
      { ((yyvsp[-2].expr))->append((yyvsp[0].expr)); (yyval.expr) = (yyvsp[-2].expr); }
#line 2682 "CMDgram.cc"
    break;

  case 140: /* slot_assign_list: slot_assign  */
#line 520 "CMDgram.y"
      { (yyval.slist) = (yyvsp[0].slist); }
#line 2688 "CMDgram.cc"
    break;

  case 141: /* slot_assign_list: slot_assign_list slot_assign  */
#line 522 "CMDgram.y"
      { (yyvsp[-1].slist)->append((yyvsp[0].slist)); (yyval.slist) = (yyvsp[-1].slist); }
#line 2694 "CMDgram.cc"
    break;

  case 142: /* slot_assign: IDENT '=' expr ';'  */
#line 527 "CMDgram.y"
      { (yyval.slist) = SlotAssignNode::alloc(NULL, NULL, (yyvsp[-3].s), (yyvsp[-1].expr)); }
#line 2700 "CMDgram.cc"
    break;

  case 143: /* slot_assign: rwDATABLOCK '=' expr ';'  */
#line 529 "CMDgram.y"
      { (yyval.slist) = SlotAssignNode::alloc(NULL, NULL, StringTable->insert("datablock"), (yyvsp[-1].expr)); }
#line 2706 "CMDgram.cc"
    break;

  case 144: /* slot_assign: IDENT '[' aidx_expr ']' '=' expr ';'  */
#line 531 "CMDgram.y"
      { (yyval.slist) = SlotAssignNode::alloc(NULL, (yyvsp[-4].expr), (yyvsp[-6].s), (yyvsp[-1].expr)); }
#line 2712 "CMDgram.cc"
    break;

  case 145: /* aidx_expr: expr  */
#line 536 "CMDgram.y"
      { (yyval.expr) = (yyvsp[0].expr); }
#line 2718 "CMDgram.cc"
    break;

  case 146: /* aidx_expr: expr ',' aidx_expr  */
#line 538 "CMDgram.y"
      { (yyval.expr) = CommaCatExprNode::alloc((yyvsp[-2].expr), (yyvsp[0].expr)); }
#line 2724 "CMDgram.cc"
    break;


#line 2728 "CMDgram.cc"

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

#line 540 "CMDgram.y"


