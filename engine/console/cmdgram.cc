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
  YYSYMBOL_NLSATOM = 30,                   /* NLSATOM  */
  YYSYMBOL_31_ = 31,                       /* '+'  */
  YYSYMBOL_32_ = 32,                       /* '-'  */
  YYSYMBOL_33_ = 33,                       /* '*'  */
  YYSYMBOL_34_ = 34,                       /* '/'  */
  YYSYMBOL_35_ = 35,                       /* '<'  */
  YYSYMBOL_36_ = 36,                       /* '>'  */
  YYSYMBOL_37_ = 37,                       /* '='  */
  YYSYMBOL_38_ = 38,                       /* '.'  */
  YYSYMBOL_39_ = 39,                       /* '|'  */
  YYSYMBOL_40_ = 40,                       /* '&'  */
  YYSYMBOL_41_ = 41,                       /* '%'  */
  YYSYMBOL_42_ = 42,                       /* '('  */
  YYSYMBOL_43_ = 43,                       /* ')'  */
  YYSYMBOL_44_ = 44,                       /* ','  */
  YYSYMBOL_45_ = 45,                       /* ':'  */
  YYSYMBOL_46_ = 46,                       /* ';'  */
  YYSYMBOL_47_ = 47,                       /* '{'  */
  YYSYMBOL_48_ = 48,                       /* '}'  */
  YYSYMBOL_49_ = 49,                       /* '^'  */
  YYSYMBOL_50_ = 50,                       /* '~'  */
  YYSYMBOL_51_ = 51,                       /* '!'  */
  YYSYMBOL_52_ = 52,                       /* '@'  */
  YYSYMBOL_opMINUSMINUS = 53,              /* opMINUSMINUS  */
  YYSYMBOL_opPLUSPLUS = 54,                /* opPLUSPLUS  */
  YYSYMBOL_opSHL = 55,                     /* opSHL  */
  YYSYMBOL_opSHR = 56,                     /* opSHR  */
  YYSYMBOL_opPLASN = 57,                   /* opPLASN  */
  YYSYMBOL_opMIASN = 58,                   /* opMIASN  */
  YYSYMBOL_opMLASN = 59,                   /* opMLASN  */
  YYSYMBOL_opDVASN = 60,                   /* opDVASN  */
  YYSYMBOL_opMODASN = 61,                  /* opMODASN  */
  YYSYMBOL_opANDASN = 62,                  /* opANDASN  */
  YYSYMBOL_opXORASN = 63,                  /* opXORASN  */
  YYSYMBOL_opORASN = 64,                   /* opORASN  */
  YYSYMBOL_opSLASN = 65,                   /* opSLASN  */
  YYSYMBOL_opSRASN = 66,                   /* opSRASN  */
  YYSYMBOL_opEQ = 67,                      /* opEQ  */
  YYSYMBOL_opNE = 68,                      /* opNE  */
  YYSYMBOL_opGE = 69,                      /* opGE  */
  YYSYMBOL_opLE = 70,                      /* opLE  */
  YYSYMBOL_opAND = 71,                     /* opAND  */
  YYSYMBOL_opOR = 72,                      /* opOR  */
  YYSYMBOL_opSTREQ = 73,                   /* opSTREQ  */
  YYSYMBOL_opRANGE = 74,                   /* opRANGE  */
  YYSYMBOL_opCOLONCOLON = 75,              /* opCOLONCOLON  */
  YYSYMBOL_76_ = 76,                       /* '['  */
  YYSYMBOL_opMDASN = 77,                   /* opMDASN  */
  YYSYMBOL_opNDASN = 78,                   /* opNDASN  */
  YYSYMBOL_opNTASN = 79,                   /* opNTASN  */
  YYSYMBOL_80_ = 80,                       /* '?'  */
  YYSYMBOL_opCAT = 81,                     /* opCAT  */
  YYSYMBOL_opSTRNE = 82,                   /* opSTRNE  */
  YYSYMBOL_opFORGIVE = 83,                 /* opFORGIVE  */
  YYSYMBOL_opINSTANCE = 84,                /* opINSTANCE  */
  YYSYMBOL_UNARY = 85,                     /* UNARY  */
  YYSYMBOL_opIDXSTART = 86,                /* opIDXSTART  */
  YYSYMBOL_87_ = 87,                       /* ']'  */
  YYSYMBOL_YYACCEPT = 88,                  /* $accept  */
  YYSYMBOL_start = 89,                     /* start  */
  YYSYMBOL_decl_list = 90,                 /* decl_list  */
  YYSYMBOL_decl = 91,                      /* decl  */
  YYSYMBOL_package_decl = 92,              /* package_decl  */
  YYSYMBOL_fn_decl_list = 93,              /* fn_decl_list  */
  YYSYMBOL_statement_list = 94,            /* statement_list  */
  YYSYMBOL_stmt = 95,                      /* stmt  */
  YYSYMBOL_fn_decl_stmt = 96,              /* fn_decl_stmt  */
  YYSYMBOL_var_list_decl = 97,             /* var_list_decl  */
  YYSYMBOL_var_list = 98,                  /* var_list  */
  YYSYMBOL_datablock_decl = 99,            /* datablock_decl  */
  YYSYMBOL_object_decl = 100,              /* object_decl  */
  YYSYMBOL_parent_block = 101,             /* parent_block  */
  YYSYMBOL_object_name = 102,              /* object_name  */
  YYSYMBOL_object_args = 103,              /* object_args  */
  YYSYMBOL_object_declare_block = 104,     /* object_declare_block  */
  YYSYMBOL_object_decl_list = 105,         /* object_decl_list  */
  YYSYMBOL_stmt_block = 106,               /* stmt_block  */
  YYSYMBOL_switch_stmt = 107,              /* switch_stmt  */
  YYSYMBOL_case_block = 108,               /* case_block  */
  YYSYMBOL_case_expr = 109,                /* case_expr  */
  YYSYMBOL_if_stmt = 110,                  /* if_stmt  */
  YYSYMBOL_while_stmt = 111,               /* while_stmt  */
  YYSYMBOL_for_stmt = 112,                 /* for_stmt  */
  YYSYMBOL_expression_stmt = 113,          /* expression_stmt  */
  YYSYMBOL_expr = 114,                     /* expr  */
  YYSYMBOL_slot_acc = 115,                 /* slot_acc  */
  YYSYMBOL_class_name_expr = 116,          /* class_name_expr  */
  YYSYMBOL_assign_op_struct = 117,         /* assign_op_struct  */
  YYSYMBOL_stmt_expr = 118,                /* stmt_expr  */
  YYSYMBOL_funcall_expr = 119,             /* funcall_expr  */
  YYSYMBOL_expr_list_decl = 120,           /* expr_list_decl  */
  YYSYMBOL_expr_list = 121,                /* expr_list  */
  YYSYMBOL_slot_assign_list = 122,         /* slot_assign_list  */
  YYSYMBOL_slot_assign = 123,              /* slot_assign  */
  YYSYMBOL_aidx_expr = 124                 /* aidx_expr  */
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
#define YYLAST   2522

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  88
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  37
/* YYNRULES -- Number of rules.  */
#define YYNRULES  147
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  324

/* YYMAXUTOK -- Last valid token kind.  */
#define YYMAXUTOK   317


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
       2,     2,     2,    51,     2,     2,     2,    41,    40,     2,
      42,    43,    33,    31,    44,    32,    38,    34,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,    45,    46,
      35,    37,    36,    80,    52,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,    76,     2,    87,    49,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    47,    39,    48,    50,     2,     2,     2,
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
      25,    26,    27,    28,    29,    30,    53,    54,    55,    56,
      57,    58,    59,    60,    61,    62,    63,    64,    65,    66,
      67,    68,    69,    70,    71,    72,    73,    74,    75,    77,
      78,    79,    81,    82,    83,    84,    85,    86
};

#if CMDDEBUG
/* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_int16 yyrline[] =
{
       0,   150,   150,   156,   157,   162,   164,   166,   171,   176,
     178,   184,   185,   190,   191,   192,   193,   194,   195,   197,
     199,   201,   203,   208,   210,   216,   217,   222,   224,   229,
     231,   236,   238,   244,   245,   251,   252,   258,   259,   265,
     266,   268,   270,   275,   277,   282,   284,   289,   291,   296,
     298,   300,   305,   307,   312,   314,   319,   321,   326,   328,
     330,   332,   334,   336,   338,   340,   345,   350,   352,   354,
     356,   358,   360,   362,   364,   366,   368,   370,   372,   374,
     376,   378,   380,   382,   384,   386,   388,   390,   392,   394,
     396,   398,   400,   402,   404,   406,   408,   410,   412,   414,
     416,   418,   420,   422,   424,   426,   428,   430,   432,   434,
     439,   441,   446,   448,   453,   455,   457,   459,   461,   463,
     465,   467,   469,   471,   473,   475,   480,   482,   484,   486,
     488,   490,   492,   494,   499,   501,   503,   509,   510,   515,
     517,   522,   524,   529,   531,   533,   538,   540
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
  "TAGATOM", "PTHATOM", "FLTCONST", "NLSATOM", "'+'", "'-'", "'*'", "'/'",
  "'<'", "'>'", "'='", "'.'", "'|'", "'&'", "'%'", "'('", "')'", "','",
  "':'", "';'", "'{'", "'}'", "'^'", "'~'", "'!'", "'@'", "opMINUSMINUS",
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

#define YYPACT_NINF (-253)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-67)

#define yytable_value_is_error(Yyn) \
  0

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int16 yypact[] =
{
    -253,    20,  1947,  -253,    -4,    -6,  2413,   -16,   -15,    13,
    2226,    15,  2024,    29,     8,    30,    36,    27,  -253,  2412,
     -25,  -253,  -253,  -253,  -253,  -253,  2413,  2413,  2413,  2413,
    -253,  -253,  -253,  -253,  -253,  -253,  -253,  -253,  -253,  -253,
      33,  1527,  2442,    34,  -253,   -24,  -253,  2413,    49,  -253,
    1527,  -253,    42,    50,  -253,  -253,  2413,  -253,   349,  2413,
    -253,  -253,    84,  2237,    55,  2413,  2413,    53,  2413,  -253,
    -253,  2413,  2413,  2413,  2413,  2413,  2413,  2413,  2413,  2413,
    2413,  2413,  -253,  2413,    77,   -30,   440,   -30,   -30,  -253,
    2413,  2413,  2413,  2413,  2413,  2413,    79,  2413,  2413,  2413,
    2413,  2413,  2413,  2413,  2413,  2413,  2413,  2413,  2413,  2413,
    2413,  2413,  2413,  2413,  2413,  2413,  2413,  -253,    81,    87,
     519,  2413,  -253,  2413,   575,  -253,   631,  2053,    76,  2269,
     687,    92,   743,   799,   117,  1527,  1527,  1527,  1527,  1527,
    1527,  1527,  1527,  1527,  1527,  1527,   855,    45,    78,    91,
    -253,    48,    48,   -30,   -30,   199,   199,   -27,  1751,  1863,
     -30,  1807,   429,     7,     7,    -9,    -9,   199,   199,  1695,
    1639,   429,   911,   429,   429,   429,    75,  1527,  -253,    86,
      93,    94,  -253,    90,  1527,  1527,  2024,  2024,  -253,  -253,
    2413,  2280,   967,  2312,    90,   105,   106,    10,  -253,  2413,
    2456,  -253,  2413,  2413,  2413,  2413,  2413,  -253,   107,   114,
      81,   115,    95,   134,  -253,  1023,  2024,  1079,  2323,  2355,
    1135,   113,   132,   132,   118,  -253,  -253,  2413,  -253,   120,
     122,    80,  1583,   137,  -253,  -253,   123,  -253,  2413,   131,
    2024,  -253,  -253,  2024,  2024,  1191,  2024,  1247,  2384,   133,
    2413,   135,   139,  -253,  1527,  -253,  -253,  -253,  -253,  2101,
     141,    50,   143,  -253,  -253,  -253,  2024,  -253,  2024,  2024,
    1303,    51,    24,  1527,  -253,  -253,  -253,  -253,    12,  -253,
    -253,  -253,  2024,   142,   -23,   136,   103,  -253,  2413,  -253,
    2149,   145,   146,   177,    12,  -253,  2413,  2413,  2413,  -253,
     149,  -253,  1527,  1995,  -253,  -253,  -253,   150,   177,  1359,
    1415,   110,  -253,   153,  -253,  -253,  -253,  -253,   162,  -253,
    2413,  2197,  1471,  -253
};

/* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE does not specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       3,     0,     2,     1,     0,     0,   137,   102,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   101,   108,
     104,   105,    99,   107,   100,   106,     0,     0,     0,     0,
       4,     7,     5,     6,    16,   127,    17,    13,    14,    15,
       0,     0,   103,    67,   126,     0,   112,     0,     0,   102,
     139,    67,     0,   138,    18,    19,     0,    20,     0,     0,
      11,    46,     0,     0,     0,     0,     0,     0,     0,   115,
     114,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   130,   137,     0,    78,     0,    98,    97,    22,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   132,    25,     0,
       0,    35,    69,     0,     0,    21,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   128,   116,   117,   118,   119,
     120,   121,   122,   123,   124,   125,   146,     0,     0,     0,
      68,    74,    75,    76,    77,    80,    81,   110,    73,    72,
      71,    70,    93,    87,    88,    84,    85,    82,    83,    89,
      86,    90,     0,    91,    92,    94,     0,   133,    27,     0,
      26,     0,   113,    33,    36,   140,     0,     0,    45,    12,
       0,     0,     0,     0,    33,     0,     0,     0,     9,     0,
     109,   134,   137,   137,     0,     0,     0,    95,     0,     0,
      25,     0,    37,    54,    56,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    10,   147,     0,   131,     0,
       0,     0,    79,     0,    11,    28,     0,    34,     0,     0,
       0,    57,    65,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     8,   129,   135,   136,   111,    96,     0,
       0,    38,    32,    55,    64,    63,     0,    61,     0,     0,
       0,     0,     0,    52,    47,    48,    23,    11,    39,    62,
      60,    59,     0,     0,     0,     0,     0,   141,     0,    11,
       0,     0,     0,    41,    40,    58,     0,     0,     0,    30,
       0,   142,    53,    49,    24,    43,    31,     0,    42,     0,
       0,     0,    29,     0,    51,    44,   144,   143,     0,    11,
       0,    50,     0,   145
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -253,  -253,  -253,  -253,  -253,  -253,  -223,    -1,  -127,   -10,
    -253,  -253,  -210,     9,  -253,  -253,  -253,   -93,  -181,  -253,
    -211,  -253,  -253,  -253,  -253,  -253,   250,  -253,  -253,   -40,
      -2,  -253,   -80,   -36,   -67,  -252,  -195
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
       0,     1,     2,    30,    31,   197,   127,    61,    33,   179,
     180,    34,    35,   212,   183,   239,   292,   293,    62,    36,
     251,   272,    37,    38,    39,    40,    41,    42,    48,    82,
      51,    44,    52,    53,   286,   287,   147
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      43,    32,   117,   148,   226,   213,   214,   198,    96,   231,
      43,   259,   252,     4,   297,   203,     5,    83,   118,    46,
       3,    45,    90,    91,    92,    93,    94,    95,   283,    96,
      54,    55,    99,    64,   301,   242,    47,   284,    90,    91,
      92,    93,   301,   101,   288,    96,   102,   103,    99,   204,
      84,   119,    67,   298,   290,    56,   115,    59,   224,   263,
     106,   107,   264,   265,   110,   267,   303,   283,   291,   289,
     225,    63,    65,   112,   113,   114,   284,   115,    66,    89,
     -66,    92,    93,   307,   291,   279,    96,   280,   281,    99,
     122,   121,   314,   115,   123,   128,   321,   131,   307,   285,
     134,   295,   149,   311,   157,   178,    90,    91,    92,    93,
      94,    95,   181,    96,    97,    98,    99,   194,   190,   283,
       4,   201,   229,   230,   100,    43,   189,   101,   284,   208,
     102,   103,   200,   202,   115,   211,   210,   209,   235,   238,
     237,   240,   104,   105,   106,   107,   108,   109,   110,   206,
     250,   300,   222,   223,   234,   111,   249,   112,   113,   114,
     228,   115,   207,   255,   253,   256,   260,   257,    90,    91,
      92,    93,    94,    95,   262,    96,    97,    98,    99,   296,
     271,     5,   299,   274,    43,    43,   100,   275,   277,   101,
     278,   305,   102,   103,   306,   312,   315,   318,   319,   320,
     236,   308,   261,   221,   104,   105,   106,   107,   108,   109,
     110,   294,     0,     0,    43,     0,     0,   111,     0,   112,
     113,   114,     0,   115,   258,     0,     0,     0,     0,     0,
      90,    91,    92,    93,     0,     0,     0,    96,    43,     0,
      99,    43,    43,     0,    43,     0,     0,     0,     0,     0,
       0,   101,     0,     0,   102,   103,    50,    43,   189,     0,
      58,     0,     0,     0,    43,     0,    43,    43,     0,     0,
       0,     0,   110,     0,     0,     0,    85,    86,    87,    88,
      43,   112,   113,   114,     0,   115,     0,     0,    43,   189,
       0,     0,     0,     0,     0,     0,     0,   120,     0,     0,
       0,    43,   189,     0,     0,     0,   124,     0,     0,   126,
       0,     0,     0,   130,     0,   132,   133,     0,   135,    43,
     189,   136,   137,   138,   139,   140,   141,   142,   143,   144,
     145,   146,     0,    50,     0,     0,     0,     0,     0,     0,
     151,   152,   153,   154,   155,   156,     0,   158,   159,   160,
     161,   162,   163,   164,   165,   166,   167,   168,   169,   170,
     171,   172,   173,   174,   175,   176,   177,     0,     0,     0,
       0,   184,     0,   185,     0,     0,     0,     0,     0,   192,
      90,    91,    92,    93,    94,    95,     0,    96,    97,    98,
      99,     0,     0,     0,     0,   125,     0,     0,   100,     0,
       0,   101,     0,     0,   102,   103,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   104,   105,   106,   107,
     108,   109,   110,     0,     0,     0,     0,     0,     0,   111,
       0,   112,   113,   114,     0,   115,     0,     0,     0,     0,
     215,   217,     0,   220,     0,     0,     0,     0,     0,   146,
       0,     0,    50,    50,   146,   232,   233,     0,     0,     0,
      90,    91,    92,    93,     0,     0,     0,    96,   245,   247,
      99,    90,    91,    92,    93,    94,    95,   254,    96,    97,
      98,    99,     0,   150,   102,   103,     0,     0,    50,   100,
       0,     0,   101,     0,     0,   102,   103,     0,   270,     0,
     273,     0,     0,     0,     0,     0,     0,   104,   105,   106,
     107,   108,   109,   110,     0,   115,     0,     0,     0,     0,
     111,     0,   112,   113,   114,     0,   115,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   302,     0,
       0,     0,     0,     0,     0,     0,   309,   310,   146,     0,
      90,    91,    92,    93,    94,    95,     0,    96,    97,    98,
      99,     0,   182,     0,     0,     0,     0,     0,   100,     0,
     322,   101,     0,     0,   102,   103,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   104,   105,   106,   107,
     108,   109,   110,     0,     0,     0,     0,     0,     0,   111,
       0,   112,   113,   114,     0,   115,    90,    91,    92,    93,
      94,    95,     0,    96,    97,    98,    99,     0,   186,     0,
       0,     0,     0,     0,   100,     0,     0,   101,     0,     0,
     102,   103,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   104,   105,   106,   107,   108,   109,   110,     0,
       0,     0,     0,     0,     0,   111,     0,   112,   113,   114,
       0,   115,    90,    91,    92,    93,    94,    95,     0,    96,
      97,    98,    99,     0,   187,     0,     0,     0,     0,     0,
     100,     0,     0,   101,     0,     0,   102,   103,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   104,   105,
     106,   107,   108,   109,   110,     0,     0,     0,     0,     0,
       0,   111,     0,   112,   113,   114,     0,   115,    90,    91,
      92,    93,    94,    95,     0,    96,    97,    98,    99,     0,
       0,     0,     0,   193,     0,     0,   100,     0,     0,   101,
       0,     0,   102,   103,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   104,   105,   106,   107,   108,   109,
     110,     0,     0,     0,     0,     0,     0,   111,     0,   112,
     113,   114,     0,   115,    90,    91,    92,    93,    94,    95,
       0,    96,    97,    98,    99,     0,   195,     0,     0,     0,
       0,     0,   100,     0,     0,   101,     0,     0,   102,   103,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     104,   105,   106,   107,   108,   109,   110,     0,     0,     0,
       0,     0,     0,   111,     0,   112,   113,   114,     0,   115,
      90,    91,    92,    93,    94,    95,     0,    96,    97,    98,
      99,     0,   196,     0,     0,     0,     0,     0,   100,     0,
       0,   101,     0,     0,   102,   103,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   104,   105,   106,   107,
     108,   109,   110,     0,     0,     0,     0,     0,     0,   111,
       0,   112,   113,   114,     0,   115,    90,    91,    92,    93,
      94,    95,     0,    96,    97,    98,    99,     0,     0,   199,
       0,     0,     0,     0,   100,     0,     0,   101,     0,     0,
     102,   103,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   104,   105,   106,   107,   108,   109,   110,     0,
       0,     0,     0,     0,     0,   111,     0,   112,   113,   114,
       0,   115,    90,    91,    92,    93,    94,    95,     0,    96,
      97,    98,    99,     0,     0,     0,   205,     0,     0,     0,
     100,     0,     0,   101,     0,     0,   102,   103,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   104,   105,
     106,   107,   108,   109,   110,     0,     0,     0,     0,     0,
       0,   111,     0,   112,   113,   114,     0,   115,    90,    91,
      92,    93,    94,    95,     0,    96,    97,    98,    99,     0,
       0,     0,     0,   218,     0,     0,   100,     0,     0,   101,
       0,     0,   102,   103,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   104,   105,   106,   107,   108,   109,
     110,     0,     0,     0,     0,     0,     0,   111,     0,   112,
     113,   114,     0,   115,    90,    91,    92,    93,    94,    95,
       0,    96,    97,    98,    99,     0,   241,     0,     0,     0,
       0,     0,   100,     0,     0,   101,     0,     0,   102,   103,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     104,   105,   106,   107,   108,   109,   110,     0,     0,     0,
       0,     0,     0,   111,     0,   112,   113,   114,     0,   115,
      90,    91,    92,    93,    94,    95,     0,    96,    97,    98,
      99,     0,   243,     0,     0,     0,     0,     0,   100,     0,
       0,   101,     0,     0,   102,   103,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   104,   105,   106,   107,
     108,   109,   110,     0,     0,     0,     0,     0,     0,   111,
       0,   112,   113,   114,     0,   115,    90,    91,    92,    93,
      94,    95,     0,    96,    97,    98,    99,     0,     0,     0,
       0,   248,     0,     0,   100,     0,     0,   101,     0,     0,
     102,   103,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   104,   105,   106,   107,   108,   109,   110,     0,
       0,     0,     0,     0,     0,   111,     0,   112,   113,   114,
       0,   115,    90,    91,    92,    93,    94,    95,     0,    96,
      97,    98,    99,     0,   266,     0,     0,     0,     0,     0,
     100,     0,     0,   101,     0,     0,   102,   103,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   104,   105,
     106,   107,   108,   109,   110,     0,     0,     0,     0,     0,
       0,   111,     0,   112,   113,   114,     0,   115,    90,    91,
      92,    93,    94,    95,     0,    96,    97,    98,    99,     0,
     268,     0,     0,     0,     0,     0,   100,     0,     0,   101,
       0,     0,   102,   103,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   104,   105,   106,   107,   108,   109,
     110,     0,     0,     0,     0,     0,     0,   111,     0,   112,
     113,   114,     0,   115,    90,    91,    92,    93,    94,    95,
       0,    96,    97,    98,    99,     0,   282,     0,     0,     0,
       0,     0,   100,     0,     0,   101,     0,     0,   102,   103,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     104,   105,   106,   107,   108,   109,   110,     0,     0,     0,
       0,     0,     0,   111,     0,   112,   113,   114,     0,   115,
      90,    91,    92,    93,    94,    95,     0,    96,    97,    98,
      99,     0,     0,     0,     0,   316,     0,     0,   100,     0,
       0,   101,     0,     0,   102,   103,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   104,   105,   106,   107,
     108,   109,   110,     0,     0,     0,     0,     0,     0,   111,
       0,   112,   113,   114,     0,   115,    90,    91,    92,    93,
      94,    95,     0,    96,    97,    98,    99,     0,     0,     0,
       0,   317,     0,     0,   100,     0,     0,   101,     0,     0,
     102,   103,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   104,   105,   106,   107,   108,   109,   110,     0,
       0,     0,     0,     0,     0,   111,     0,   112,   113,   114,
       0,   115,    90,    91,    92,    93,    94,    95,     0,    96,
      97,    98,    99,     0,     0,     0,     0,   323,     0,     0,
     100,     0,     0,   101,     0,     0,   102,   103,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   104,   105,
     106,   107,   108,   109,   110,     0,     0,     0,     0,     0,
       0,   111,     0,   112,   113,   114,     0,   115,    90,    91,
      92,    93,    94,    95,     0,    96,    97,    98,    99,     0,
       0,     0,     0,     0,     0,     0,   100,     0,     0,   101,
       0,     0,   102,   103,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   104,   105,   106,   107,   108,   109,
     110,     0,     0,     0,     0,     0,     0,   111,     0,   112,
     113,   114,     0,   115,    90,    91,    92,    93,    94,    95,
       0,    96,    97,    98,    99,     0,     0,     0,     0,     0,
       0,     0,   100,     0,     0,   101,     0,     0,   102,   103,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     104,   105,   106,   107,   108,   109,   110,     0,     0,     0,
       0,     0,     0,     0,     0,   112,   113,   114,     0,   115,
      90,    91,    92,    93,    94,    95,     0,    96,    97,    98,
      99,     0,     0,     0,     0,     0,     0,     0,   100,     0,
       0,   101,     0,     0,   102,   103,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   104,   105,   106,   107,
     108,     0,   110,     0,     0,     0,     0,     0,     0,     0,
       0,   112,   113,   114,     0,   115,    90,    91,    92,    93,
      94,    95,     0,    96,    97,    98,    99,     0,     0,     0,
       0,     0,     0,     0,   100,     0,     0,   101,     0,     0,
     102,   103,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   104,   105,   106,   107,     0,     0,   110,     0,
       0,     0,     0,     0,     0,     0,     0,   112,   113,   114,
       0,   115,    90,    91,    92,    93,    94,    95,     0,    96,
       0,    98,    99,     0,     0,     0,     0,     0,     0,     0,
     100,     0,     0,   101,     0,     0,   102,   103,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   104,   105,
     106,   107,     0,     0,   110,     0,     0,     0,     0,     0,
       0,     0,     0,   112,   113,   114,     0,   115,    90,    91,
      92,    93,    94,    95,     0,    96,     0,    98,    99,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   101,
       0,     0,   102,   103,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   104,   105,   106,   107,     0,     0,
     110,     0,     0,     0,     0,     0,     0,     0,     0,   112,
     113,   114,     0,   115,    90,    91,    92,    93,    94,    95,
       0,    96,     0,     0,    99,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   101,     0,     0,   102,   103,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     104,   105,   106,   107,     0,     0,   110,     0,     0,     0,
       0,     0,     0,     0,     0,   112,   113,   114,     0,   115,
       4,     5,     6,     7,     0,     8,     9,    10,    11,    12,
       0,     0,    13,    14,    15,     0,    16,     0,    17,     0,
      18,    19,    20,    21,    22,    23,    24,    25,     0,    26,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    27,
       0,     0,     0,     0,     0,     0,     0,    28,    29,     5,
       6,     7,     0,     8,     9,    10,    11,    12,   313,     0,
      13,    14,    15,   250,    16,     0,     0,     0,    18,    19,
      20,    21,    22,    23,    24,    25,     0,    26,     5,     6,
       7,     0,     8,     9,    10,    11,    12,    27,     0,    13,
      14,    15,     0,    16,     0,    28,    29,    18,    19,    20,
      21,    22,    23,    24,    25,     0,    26,     5,     6,     7,
       0,     8,     9,    10,    11,    12,    27,     0,    13,    14,
      15,    60,    16,     0,    28,    29,    18,    19,    20,    21,
      22,    23,    24,    25,     0,    26,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    27,     0,     0,     0,     0,
       0,   188,     0,    28,    29,     5,     6,     7,     0,     8,
       9,    10,    11,    12,     0,     0,    13,    14,    15,     0,
      16,     0,     0,     0,    18,    19,    20,    21,    22,    23,
      24,    25,     0,    26,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    27,     0,     0,     0,     0,     0,   276,
       0,    28,    29,     5,     6,     7,     0,     8,     9,    10,
      11,    12,     0,     0,    13,    14,    15,     0,    16,     0,
       0,     0,    18,    19,    20,    21,    22,    23,    24,    25,
       0,    26,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    27,     0,     0,     0,     0,     0,   304,     0,    28,
      29,     5,     6,     7,     0,     8,     9,    10,    11,    12,
       0,     0,    13,    14,    15,     0,    16,     0,     0,     0,
      18,    19,    20,    21,    22,    23,    24,    25,     0,    26,
       5,     6,    49,     0,     0,     0,     0,     0,     0,    27,
       0,     5,     6,    49,     0,     0,     0,    28,    29,    18,
      19,    20,    21,    22,    23,    24,    25,     0,    26,     0,
      18,    19,    20,    21,    22,    23,    24,    25,    27,    26,
       0,     0,    57,     5,     6,    49,    28,    29,     0,    27,
       0,     0,     0,   129,     5,     6,    49,    28,    29,     0,
       0,     0,    18,    19,    20,    21,    22,    23,    24,    25,
       0,    26,     0,    18,    19,    20,    21,    22,    23,    24,
      25,    27,    26,     0,     0,   191,     5,     6,    49,    28,
      29,     0,    27,   216,     0,     0,     0,     5,     6,    49,
      28,    29,     0,     0,     0,    18,    19,    20,    21,    22,
      23,    24,    25,     0,    26,     0,    18,    19,    20,    21,
      22,    23,    24,    25,    27,    26,     0,     0,   219,     5,
       6,    49,    28,    29,     0,    27,   244,     0,     0,     0,
       0,     0,     0,    28,    29,     0,     0,     0,    18,    19,
      20,    21,    22,    23,    24,    25,     0,    26,     5,     6,
      49,     0,     0,     0,     0,     0,     0,    27,   246,     0,
       0,     0,     0,     0,     0,    28,    29,    18,    19,    20,
      21,    22,    23,    24,    25,     0,    26,     5,     6,    49,
       0,     0,     0,     0,     0,     0,    27,   269,     0,     0,
       0,     0,     0,     0,    28,    29,    18,    19,    20,    21,
      22,    23,    24,    25,     0,    26,     0,     0,     0,    68,
       0,     0,     0,     0,     0,    27,     0,     0,     0,     0,
       0,     0,     0,    28,    29,    69,    70,     0,     0,    71,
      72,    73,    74,    75,    76,    77,    78,    79,    80,   116,
       0,     0,     0,     0,     0,     0,     0,     0,    81,     0,
       0,     0,     0,   227,     0,    69,    70,     0,     0,    71,
      72,    73,    74,    75,    76,    77,    78,    79,    80,    69,
      70,     0,     0,    71,    72,    73,    74,    75,    76,    77,
      78,    79,    80
};

static const yytype_int16 yycheck[] =
{
       2,     2,    42,    83,   199,   186,   187,   134,    38,   204,
      12,   234,   223,     3,    37,    42,     4,    42,    42,    25,
       0,    25,    31,    32,    33,    34,    35,    36,    16,    38,
      46,    46,    41,    25,   286,   216,    42,    25,    31,    32,
      33,    34,   294,    52,    20,    38,    55,    56,    41,    76,
      75,    75,    25,    76,   277,    42,    86,    42,    48,   240,
      69,    70,   243,   244,    73,   246,   289,    16,   278,    45,
     197,    42,    42,    82,    83,    84,    25,    86,    42,    46,
      46,    33,    34,   293,   294,   266,    38,   268,   269,    41,
      48,    42,   303,    86,    44,    11,   319,    42,   308,    48,
      47,   282,    25,   298,    25,    24,    31,    32,    33,    34,
      35,    36,    25,    38,    39,    40,    41,    25,    42,    16,
       3,    43,   202,   203,    49,   127,   127,    52,    25,    43,
      55,    56,    87,    42,    86,    45,    42,    44,    24,    44,
      25,     7,    67,    68,    69,    70,    71,    72,    73,    74,
      18,    48,    47,    47,    47,    80,    43,    82,    83,    84,
     200,    86,    87,    43,    46,    43,    43,    87,    31,    32,
      33,    34,    35,    36,    43,    38,    39,    40,    41,    37,
      47,     4,    46,    48,   186,   187,    49,    48,    47,    52,
      47,    46,    55,    56,    48,    46,    46,    87,    45,    37,
     210,   294,   238,   194,    67,    68,    69,    70,    71,    72,
      73,   278,    -1,    -1,   216,    -1,    -1,    80,    -1,    82,
      83,    84,    -1,    86,    87,    -1,    -1,    -1,    -1,    -1,
      31,    32,    33,    34,    -1,    -1,    -1,    38,   240,    -1,
      41,   243,   244,    -1,   246,    -1,    -1,    -1,    -1,    -1,
      -1,    52,    -1,    -1,    55,    56,     6,   259,   259,    -1,
      10,    -1,    -1,    -1,   266,    -1,   268,   269,    -1,    -1,
      -1,    -1,    73,    -1,    -1,    -1,    26,    27,    28,    29,
     282,    82,    83,    84,    -1,    86,    -1,    -1,   290,   290,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    47,    -1,    -1,
      -1,   303,   303,    -1,    -1,    -1,    56,    -1,    -1,    59,
      -1,    -1,    -1,    63,    -1,    65,    66,    -1,    68,   321,
     321,    71,    72,    73,    74,    75,    76,    77,    78,    79,
      80,    81,    -1,    83,    -1,    -1,    -1,    -1,    -1,    -1,
      90,    91,    92,    93,    94,    95,    -1,    97,    98,    99,
     100,   101,   102,   103,   104,   105,   106,   107,   108,   109,
     110,   111,   112,   113,   114,   115,   116,    -1,    -1,    -1,
      -1,   121,    -1,   123,    -1,    -1,    -1,    -1,    -1,   129,
      31,    32,    33,    34,    35,    36,    -1,    38,    39,    40,
      41,    -1,    -1,    -1,    -1,    46,    -1,    -1,    49,    -1,
      -1,    52,    -1,    -1,    55,    56,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    67,    68,    69,    70,
      71,    72,    73,    -1,    -1,    -1,    -1,    -1,    -1,    80,
      -1,    82,    83,    84,    -1,    86,    -1,    -1,    -1,    -1,
     190,   191,    -1,   193,    -1,    -1,    -1,    -1,    -1,   199,
      -1,    -1,   202,   203,   204,   205,   206,    -1,    -1,    -1,
      31,    32,    33,    34,    -1,    -1,    -1,    38,   218,   219,
      41,    31,    32,    33,    34,    35,    36,   227,    38,    39,
      40,    41,    -1,    43,    55,    56,    -1,    -1,   238,    49,
      -1,    -1,    52,    -1,    -1,    55,    56,    -1,   248,    -1,
     250,    -1,    -1,    -1,    -1,    -1,    -1,    67,    68,    69,
      70,    71,    72,    73,    -1,    86,    -1,    -1,    -1,    -1,
      80,    -1,    82,    83,    84,    -1,    86,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   288,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   296,   297,   298,    -1,
      31,    32,    33,    34,    35,    36,    -1,    38,    39,    40,
      41,    -1,    43,    -1,    -1,    -1,    -1,    -1,    49,    -1,
     320,    52,    -1,    -1,    55,    56,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    67,    68,    69,    70,
      71,    72,    73,    -1,    -1,    -1,    -1,    -1,    -1,    80,
      -1,    82,    83,    84,    -1,    86,    31,    32,    33,    34,
      35,    36,    -1,    38,    39,    40,    41,    -1,    43,    -1,
      -1,    -1,    -1,    -1,    49,    -1,    -1,    52,    -1,    -1,
      55,    56,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    67,    68,    69,    70,    71,    72,    73,    -1,
      -1,    -1,    -1,    -1,    -1,    80,    -1,    82,    83,    84,
      -1,    86,    31,    32,    33,    34,    35,    36,    -1,    38,
      39,    40,    41,    -1,    43,    -1,    -1,    -1,    -1,    -1,
      49,    -1,    -1,    52,    -1,    -1,    55,    56,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    67,    68,
      69,    70,    71,    72,    73,    -1,    -1,    -1,    -1,    -1,
      -1,    80,    -1,    82,    83,    84,    -1,    86,    31,    32,
      33,    34,    35,    36,    -1,    38,    39,    40,    41,    -1,
      -1,    -1,    -1,    46,    -1,    -1,    49,    -1,    -1,    52,
      -1,    -1,    55,    56,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    67,    68,    69,    70,    71,    72,
      73,    -1,    -1,    -1,    -1,    -1,    -1,    80,    -1,    82,
      83,    84,    -1,    86,    31,    32,    33,    34,    35,    36,
      -1,    38,    39,    40,    41,    -1,    43,    -1,    -1,    -1,
      -1,    -1,    49,    -1,    -1,    52,    -1,    -1,    55,    56,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      67,    68,    69,    70,    71,    72,    73,    -1,    -1,    -1,
      -1,    -1,    -1,    80,    -1,    82,    83,    84,    -1,    86,
      31,    32,    33,    34,    35,    36,    -1,    38,    39,    40,
      41,    -1,    43,    -1,    -1,    -1,    -1,    -1,    49,    -1,
      -1,    52,    -1,    -1,    55,    56,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    67,    68,    69,    70,
      71,    72,    73,    -1,    -1,    -1,    -1,    -1,    -1,    80,
      -1,    82,    83,    84,    -1,    86,    31,    32,    33,    34,
      35,    36,    -1,    38,    39,    40,    41,    -1,    -1,    44,
      -1,    -1,    -1,    -1,    49,    -1,    -1,    52,    -1,    -1,
      55,    56,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    67,    68,    69,    70,    71,    72,    73,    -1,
      -1,    -1,    -1,    -1,    -1,    80,    -1,    82,    83,    84,
      -1,    86,    31,    32,    33,    34,    35,    36,    -1,    38,
      39,    40,    41,    -1,    -1,    -1,    45,    -1,    -1,    -1,
      49,    -1,    -1,    52,    -1,    -1,    55,    56,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    67,    68,
      69,    70,    71,    72,    73,    -1,    -1,    -1,    -1,    -1,
      -1,    80,    -1,    82,    83,    84,    -1,    86,    31,    32,
      33,    34,    35,    36,    -1,    38,    39,    40,    41,    -1,
      -1,    -1,    -1,    46,    -1,    -1,    49,    -1,    -1,    52,
      -1,    -1,    55,    56,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    67,    68,    69,    70,    71,    72,
      73,    -1,    -1,    -1,    -1,    -1,    -1,    80,    -1,    82,
      83,    84,    -1,    86,    31,    32,    33,    34,    35,    36,
      -1,    38,    39,    40,    41,    -1,    43,    -1,    -1,    -1,
      -1,    -1,    49,    -1,    -1,    52,    -1,    -1,    55,    56,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      67,    68,    69,    70,    71,    72,    73,    -1,    -1,    -1,
      -1,    -1,    -1,    80,    -1,    82,    83,    84,    -1,    86,
      31,    32,    33,    34,    35,    36,    -1,    38,    39,    40,
      41,    -1,    43,    -1,    -1,    -1,    -1,    -1,    49,    -1,
      -1,    52,    -1,    -1,    55,    56,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    67,    68,    69,    70,
      71,    72,    73,    -1,    -1,    -1,    -1,    -1,    -1,    80,
      -1,    82,    83,    84,    -1,    86,    31,    32,    33,    34,
      35,    36,    -1,    38,    39,    40,    41,    -1,    -1,    -1,
      -1,    46,    -1,    -1,    49,    -1,    -1,    52,    -1,    -1,
      55,    56,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    67,    68,    69,    70,    71,    72,    73,    -1,
      -1,    -1,    -1,    -1,    -1,    80,    -1,    82,    83,    84,
      -1,    86,    31,    32,    33,    34,    35,    36,    -1,    38,
      39,    40,    41,    -1,    43,    -1,    -1,    -1,    -1,    -1,
      49,    -1,    -1,    52,    -1,    -1,    55,    56,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    67,    68,
      69,    70,    71,    72,    73,    -1,    -1,    -1,    -1,    -1,
      -1,    80,    -1,    82,    83,    84,    -1,    86,    31,    32,
      33,    34,    35,    36,    -1,    38,    39,    40,    41,    -1,
      43,    -1,    -1,    -1,    -1,    -1,    49,    -1,    -1,    52,
      -1,    -1,    55,    56,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    67,    68,    69,    70,    71,    72,
      73,    -1,    -1,    -1,    -1,    -1,    -1,    80,    -1,    82,
      83,    84,    -1,    86,    31,    32,    33,    34,    35,    36,
      -1,    38,    39,    40,    41,    -1,    43,    -1,    -1,    -1,
      -1,    -1,    49,    -1,    -1,    52,    -1,    -1,    55,    56,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      67,    68,    69,    70,    71,    72,    73,    -1,    -1,    -1,
      -1,    -1,    -1,    80,    -1,    82,    83,    84,    -1,    86,
      31,    32,    33,    34,    35,    36,    -1,    38,    39,    40,
      41,    -1,    -1,    -1,    -1,    46,    -1,    -1,    49,    -1,
      -1,    52,    -1,    -1,    55,    56,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    67,    68,    69,    70,
      71,    72,    73,    -1,    -1,    -1,    -1,    -1,    -1,    80,
      -1,    82,    83,    84,    -1,    86,    31,    32,    33,    34,
      35,    36,    -1,    38,    39,    40,    41,    -1,    -1,    -1,
      -1,    46,    -1,    -1,    49,    -1,    -1,    52,    -1,    -1,
      55,    56,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    67,    68,    69,    70,    71,    72,    73,    -1,
      -1,    -1,    -1,    -1,    -1,    80,    -1,    82,    83,    84,
      -1,    86,    31,    32,    33,    34,    35,    36,    -1,    38,
      39,    40,    41,    -1,    -1,    -1,    -1,    46,    -1,    -1,
      49,    -1,    -1,    52,    -1,    -1,    55,    56,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    67,    68,
      69,    70,    71,    72,    73,    -1,    -1,    -1,    -1,    -1,
      -1,    80,    -1,    82,    83,    84,    -1,    86,    31,    32,
      33,    34,    35,    36,    -1,    38,    39,    40,    41,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    49,    -1,    -1,    52,
      -1,    -1,    55,    56,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    67,    68,    69,    70,    71,    72,
      73,    -1,    -1,    -1,    -1,    -1,    -1,    80,    -1,    82,
      83,    84,    -1,    86,    31,    32,    33,    34,    35,    36,
      -1,    38,    39,    40,    41,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    49,    -1,    -1,    52,    -1,    -1,    55,    56,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      67,    68,    69,    70,    71,    72,    73,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    82,    83,    84,    -1,    86,
      31,    32,    33,    34,    35,    36,    -1,    38,    39,    40,
      41,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    49,    -1,
      -1,    52,    -1,    -1,    55,    56,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    67,    68,    69,    70,
      71,    -1,    73,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    82,    83,    84,    -1,    86,    31,    32,    33,    34,
      35,    36,    -1,    38,    39,    40,    41,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    49,    -1,    -1,    52,    -1,    -1,
      55,    56,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    67,    68,    69,    70,    -1,    -1,    73,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    82,    83,    84,
      -1,    86,    31,    32,    33,    34,    35,    36,    -1,    38,
      -1,    40,    41,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      49,    -1,    -1,    52,    -1,    -1,    55,    56,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    67,    68,
      69,    70,    -1,    -1,    73,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    82,    83,    84,    -1,    86,    31,    32,
      33,    34,    35,    36,    -1,    38,    -1,    40,    41,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    52,
      -1,    -1,    55,    56,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    67,    68,    69,    70,    -1,    -1,
      73,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    82,
      83,    84,    -1,    86,    31,    32,    33,    34,    35,    36,
      -1,    38,    -1,    -1,    41,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    52,    -1,    -1,    55,    56,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      67,    68,    69,    70,    -1,    -1,    73,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    82,    83,    84,    -1,    86,
       3,     4,     5,     6,    -1,     8,     9,    10,    11,    12,
      -1,    -1,    15,    16,    17,    -1,    19,    -1,    21,    -1,
      23,    24,    25,    26,    27,    28,    29,    30,    -1,    32,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    42,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    50,    51,     4,
       5,     6,    -1,     8,     9,    10,    11,    12,    13,    -1,
      15,    16,    17,    18,    19,    -1,    -1,    -1,    23,    24,
      25,    26,    27,    28,    29,    30,    -1,    32,     4,     5,
       6,    -1,     8,     9,    10,    11,    12,    42,    -1,    15,
      16,    17,    -1,    19,    -1,    50,    51,    23,    24,    25,
      26,    27,    28,    29,    30,    -1,    32,     4,     5,     6,
      -1,     8,     9,    10,    11,    12,    42,    -1,    15,    16,
      17,    47,    19,    -1,    50,    51,    23,    24,    25,    26,
      27,    28,    29,    30,    -1,    32,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    42,    -1,    -1,    -1,    -1,
      -1,    48,    -1,    50,    51,     4,     5,     6,    -1,     8,
       9,    10,    11,    12,    -1,    -1,    15,    16,    17,    -1,
      19,    -1,    -1,    -1,    23,    24,    25,    26,    27,    28,
      29,    30,    -1,    32,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    42,    -1,    -1,    -1,    -1,    -1,    48,
      -1,    50,    51,     4,     5,     6,    -1,     8,     9,    10,
      11,    12,    -1,    -1,    15,    16,    17,    -1,    19,    -1,
      -1,    -1,    23,    24,    25,    26,    27,    28,    29,    30,
      -1,    32,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    42,    -1,    -1,    -1,    -1,    -1,    48,    -1,    50,
      51,     4,     5,     6,    -1,     8,     9,    10,    11,    12,
      -1,    -1,    15,    16,    17,    -1,    19,    -1,    -1,    -1,
      23,    24,    25,    26,    27,    28,    29,    30,    -1,    32,
       4,     5,     6,    -1,    -1,    -1,    -1,    -1,    -1,    42,
      -1,     4,     5,     6,    -1,    -1,    -1,    50,    51,    23,
      24,    25,    26,    27,    28,    29,    30,    -1,    32,    -1,
      23,    24,    25,    26,    27,    28,    29,    30,    42,    32,
      -1,    -1,    46,     4,     5,     6,    50,    51,    -1,    42,
      -1,    -1,    -1,    46,     4,     5,     6,    50,    51,    -1,
      -1,    -1,    23,    24,    25,    26,    27,    28,    29,    30,
      -1,    32,    -1,    23,    24,    25,    26,    27,    28,    29,
      30,    42,    32,    -1,    -1,    46,     4,     5,     6,    50,
      51,    -1,    42,    43,    -1,    -1,    -1,     4,     5,     6,
      50,    51,    -1,    -1,    -1,    23,    24,    25,    26,    27,
      28,    29,    30,    -1,    32,    -1,    23,    24,    25,    26,
      27,    28,    29,    30,    42,    32,    -1,    -1,    46,     4,
       5,     6,    50,    51,    -1,    42,    43,    -1,    -1,    -1,
      -1,    -1,    -1,    50,    51,    -1,    -1,    -1,    23,    24,
      25,    26,    27,    28,    29,    30,    -1,    32,     4,     5,
       6,    -1,    -1,    -1,    -1,    -1,    -1,    42,    43,    -1,
      -1,    -1,    -1,    -1,    -1,    50,    51,    23,    24,    25,
      26,    27,    28,    29,    30,    -1,    32,     4,     5,     6,
      -1,    -1,    -1,    -1,    -1,    -1,    42,    43,    -1,    -1,
      -1,    -1,    -1,    -1,    50,    51,    23,    24,    25,    26,
      27,    28,    29,    30,    -1,    32,    -1,    -1,    -1,    37,
      -1,    -1,    -1,    -1,    -1,    42,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    50,    51,    53,    54,    -1,    -1,    57,
      58,    59,    60,    61,    62,    63,    64,    65,    66,    37,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    76,    -1,
      -1,    -1,    -1,    37,    -1,    53,    54,    -1,    -1,    57,
      58,    59,    60,    61,    62,    63,    64,    65,    66,    53,
      54,    -1,    -1,    57,    58,    59,    60,    61,    62,    63,
      64,    65,    66
};

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,    89,    90,     0,     3,     4,     5,     6,     8,     9,
      10,    11,    12,    15,    16,    17,    19,    21,    23,    24,
      25,    26,    27,    28,    29,    30,    32,    42,    50,    51,
      91,    92,    95,    96,    99,   100,   107,   110,   111,   112,
     113,   114,   115,   118,   119,    25,    25,    42,   116,     6,
     114,   118,   120,   121,    46,    46,    42,    46,   114,    42,
      47,    95,   106,    42,    25,    42,    42,    25,    37,    53,
      54,    57,    58,    59,    60,    61,    62,    63,    64,    65,
      66,    76,   117,    42,    75,   114,   114,   114,   114,    46,
      31,    32,    33,    34,    35,    36,    38,    39,    40,    41,
      49,    52,    55,    56,    67,    68,    69,    70,    71,    72,
      73,    80,    82,    83,    84,    86,    37,   117,    42,    75,
     114,    42,    48,    44,   114,    46,   114,    94,    11,    46,
     114,    42,   114,   114,    47,   114,   114,   114,   114,   114,
     114,   114,   114,   114,   114,   114,   114,   124,   120,    25,
      43,   114,   114,   114,   114,   114,   114,    25,   114,   114,
     114,   114,   114,   114,   114,   114,   114,   114,   114,   114,
     114,   114,   114,   114,   114,   114,   114,   114,    24,    97,
      98,    25,    43,   102,   114,   114,    43,    43,    48,    95,
      42,    46,   114,    46,    25,    43,    43,    93,    96,    44,
      87,    43,    42,    42,    76,    45,    74,    87,    43,    44,
      42,    45,   101,   106,   106,   114,    43,   114,    46,    46,
     114,   101,    47,    47,    48,    96,   124,    37,   117,   120,
     120,   124,   114,   114,    47,    24,    97,    25,    44,   103,
       7,    43,   106,    43,    43,   114,    43,   114,    46,    43,
      18,   108,   108,    46,   114,    43,    43,    87,    87,    94,
      43,   121,    43,   106,   106,   106,    43,   106,    43,    43,
     114,    47,   109,   114,    48,    48,    48,    47,    47,   106,
     106,   106,    43,    16,    25,    48,   122,   123,    20,    45,
      94,   100,   104,   105,   122,   106,    37,    37,    76,    46,
      48,   123,   114,    94,    48,    46,    48,   100,   105,   114,
     114,   124,    46,    13,   108,    46,    46,    46,    87,    45,
      37,    94,   114,    46
};

/* YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr1[] =
{
       0,    88,    89,    90,    90,    91,    91,    91,    92,    93,
      93,    94,    94,    95,    95,    95,    95,    95,    95,    95,
      95,    95,    95,    96,    96,    97,    97,    98,    98,    99,
      99,   100,   100,   101,   101,   102,   102,   103,   103,   104,
     104,   104,   104,   105,   105,   106,   106,   107,   107,   108,
     108,   108,   109,   109,   110,   110,   111,   111,   112,   112,
     112,   112,   112,   112,   112,   112,   113,   114,   114,   114,
     114,   114,   114,   114,   114,   114,   114,   114,   114,   114,
     114,   114,   114,   114,   114,   114,   114,   114,   114,   114,
     114,   114,   114,   114,   114,   114,   114,   114,   114,   114,
     114,   114,   114,   114,   114,   114,   114,   114,   114,   114,
     115,   115,   116,   116,   117,   117,   117,   117,   117,   117,
     117,   117,   117,   117,   117,   117,   118,   118,   118,   118,
     118,   118,   118,   118,   119,   119,   119,   120,   120,   121,
     121,   122,   122,   123,   123,   123,   124,   124
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
       1,     1,     1,     1,     1,     1,     1,     1,     1,     4,
       3,     6,     1,     3,     1,     1,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     1,     1,     3,     6,
       2,     5,     2,     3,     4,     6,     6,     0,     1,     1,
       3,     1,     2,     4,     4,     7,     1,     3
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
#line 151 "CMDgram.y"
      { }
#line 1893 "CMDgram.cc"
    break;

  case 3: /* decl_list: %empty  */
#line 156 "CMDgram.y"
      { (yyval.stmt) = nil; }
#line 1899 "CMDgram.cc"
    break;

  case 4: /* decl_list: decl_list decl  */
#line 158 "CMDgram.y"
      { if(!statementList) { statementList = (yyvsp[0].stmt); } else { statementList->append((yyvsp[0].stmt)); } }
#line 1905 "CMDgram.cc"
    break;

  case 5: /* decl: stmt  */
#line 163 "CMDgram.y"
      { (yyval.stmt) = (yyvsp[0].stmt); }
#line 1911 "CMDgram.cc"
    break;

  case 6: /* decl: fn_decl_stmt  */
#line 165 "CMDgram.y"
      { (yyval.stmt) = (yyvsp[0].stmt); }
#line 1917 "CMDgram.cc"
    break;

  case 7: /* decl: package_decl  */
#line 167 "CMDgram.y"
     { (yyval.stmt) = (yyvsp[0].stmt); }
#line 1923 "CMDgram.cc"
    break;

  case 8: /* package_decl: rwPACKAGE IDENT '{' fn_decl_list '}' ';'  */
#line 172 "CMDgram.y"
      { (yyval.stmt) = (yyvsp[-2].stmt); for(StmtNode *walk = ((yyvsp[-2].stmt));walk;walk = walk->getNext() ) walk->setPackage((yyvsp[-4].s)); }
#line 1929 "CMDgram.cc"
    break;

  case 9: /* fn_decl_list: fn_decl_stmt  */
#line 177 "CMDgram.y"
      { (yyval.stmt) = (yyvsp[0].stmt); }
#line 1935 "CMDgram.cc"
    break;

  case 10: /* fn_decl_list: fn_decl_list fn_decl_stmt  */
#line 179 "CMDgram.y"
      { (yyval.stmt) = (yyvsp[-1].stmt); ((yyvsp[-1].stmt))->append((yyvsp[0].stmt));  }
#line 1941 "CMDgram.cc"
    break;

  case 11: /* statement_list: %empty  */
#line 184 "CMDgram.y"
      { (yyval.stmt) = nil; }
#line 1947 "CMDgram.cc"
    break;

  case 12: /* statement_list: statement_list stmt  */
#line 186 "CMDgram.y"
      { if(!(yyvsp[-1].stmt)) { (yyval.stmt) = (yyvsp[0].stmt); } else { ((yyvsp[-1].stmt))->append((yyvsp[0].stmt)); (yyval.stmt) = (yyvsp[-1].stmt); } }
#line 1953 "CMDgram.cc"
    break;

  case 18: /* stmt: rwBREAK ';'  */
#line 196 "CMDgram.y"
      { (yyval.stmt) = BreakStmtNode::alloc(); }
#line 1959 "CMDgram.cc"
    break;

  case 19: /* stmt: rwCONTINUE ';'  */
#line 198 "CMDgram.y"
      { (yyval.stmt) = ContinueStmtNode::alloc(); }
#line 1965 "CMDgram.cc"
    break;

  case 20: /* stmt: rwRETURN ';'  */
#line 200 "CMDgram.y"
      { (yyval.stmt) = ReturnStmtNode::alloc(NULL); }
#line 1971 "CMDgram.cc"
    break;

  case 21: /* stmt: rwRETURN expr ';'  */
#line 202 "CMDgram.y"
      { (yyval.stmt) = ReturnStmtNode::alloc((yyvsp[-1].expr)); }
#line 1977 "CMDgram.cc"
    break;

  case 22: /* stmt: expression_stmt ';'  */
#line 204 "CMDgram.y"
      { (yyval.stmt) = (yyvsp[-1].stmt); }
#line 1983 "CMDgram.cc"
    break;

  case 23: /* fn_decl_stmt: rwDEFINE IDENT '(' var_list_decl ')' '{' statement_list '}'  */
#line 209 "CMDgram.y"
      { (yyval.stmt) = FunctionDeclStmtNode::alloc((yyvsp[-6].s), NULL, (yyvsp[-4].var), (yyvsp[-1].stmt)); }
#line 1989 "CMDgram.cc"
    break;

  case 24: /* fn_decl_stmt: rwDEFINE IDENT opCOLONCOLON IDENT '(' var_list_decl ')' '{' statement_list '}'  */
#line 211 "CMDgram.y"
     { (yyval.stmt) = FunctionDeclStmtNode::alloc((yyvsp[-6].s), (yyvsp[-8].s), (yyvsp[-4].var), (yyvsp[-1].stmt)); }
#line 1995 "CMDgram.cc"
    break;

  case 25: /* var_list_decl: %empty  */
#line 216 "CMDgram.y"
     { (yyval.var) = NULL; }
#line 2001 "CMDgram.cc"
    break;

  case 26: /* var_list_decl: var_list  */
#line 218 "CMDgram.y"
     { (yyval.var) = (yyvsp[0].var); }
#line 2007 "CMDgram.cc"
    break;

  case 27: /* var_list: VAR  */
#line 223 "CMDgram.y"
      { (yyval.var) = VarNode::alloc((yyvsp[0].s), NULL); }
#line 2013 "CMDgram.cc"
    break;

  case 28: /* var_list: var_list ',' VAR  */
#line 225 "CMDgram.y"
      { (yyval.var) = (yyvsp[-2].var); ((StmtNode*)((yyvsp[-2].var)))->append((StmtNode*)VarNode::alloc((yyvsp[0].s), NULL)); }
#line 2019 "CMDgram.cc"
    break;

  case 29: /* datablock_decl: rwDATABLOCK IDENT '(' IDENT parent_block ')' '{' slot_assign_list '}' ';'  */
#line 230 "CMDgram.y"
      { (yyval.stmt) = ObjectDeclNode::alloc(ConstantNode::alloc((yyvsp[-8].s)), ConstantNode::alloc((yyvsp[-6].s)), NULL, (yyvsp[-5].s), (yyvsp[-2].slist), NULL, true); }
#line 2025 "CMDgram.cc"
    break;

  case 30: /* datablock_decl: rwDATABLOCK IDENT '(' IDENT parent_block ')' '{' '}' ';'  */
#line 232 "CMDgram.y"
      { (yyval.stmt) = ObjectDeclNode::alloc(ConstantNode::alloc((yyvsp[-7].s)), ConstantNode::alloc((yyvsp[-5].s)), NULL, (yyvsp[-4].s), NULL, NULL, true); }
#line 2031 "CMDgram.cc"
    break;

  case 31: /* object_decl: rwDECLARE class_name_expr '(' object_name parent_block object_args ')' '{' object_declare_block '}'  */
#line 237 "CMDgram.y"
      { (yyval.od) = ObjectDeclNode::alloc((yyvsp[-8].expr), (yyvsp[-6].expr), (yyvsp[-4].expr), (yyvsp[-5].s), (yyvsp[-1].odcl).slots, (yyvsp[-1].odcl).decls, false); }
#line 2037 "CMDgram.cc"
    break;

  case 32: /* object_decl: rwDECLARE class_name_expr '(' object_name parent_block object_args ')'  */
#line 239 "CMDgram.y"
      { (yyval.od) = ObjectDeclNode::alloc((yyvsp[-5].expr), (yyvsp[-3].expr), (yyvsp[-1].expr), (yyvsp[-2].s), NULL, NULL, false); }
#line 2043 "CMDgram.cc"
    break;

  case 33: /* parent_block: %empty  */
#line 244 "CMDgram.y"
      { (yyval.s) = NULL; }
#line 2049 "CMDgram.cc"
    break;

  case 34: /* parent_block: ':' IDENT  */
#line 246 "CMDgram.y"
      { (yyval.s) = (yyvsp[0].s); }
#line 2055 "CMDgram.cc"
    break;

  case 35: /* object_name: %empty  */
#line 251 "CMDgram.y"
      { (yyval.expr) = StrConstNode::alloc("", false); }
#line 2061 "CMDgram.cc"
    break;

  case 36: /* object_name: expr  */
#line 253 "CMDgram.y"
      { (yyval.expr) = (yyvsp[0].expr); }
#line 2067 "CMDgram.cc"
    break;

  case 37: /* object_args: %empty  */
#line 258 "CMDgram.y"
      { (yyval.expr) = NULL; }
#line 2073 "CMDgram.cc"
    break;

  case 38: /* object_args: ',' expr_list  */
#line 260 "CMDgram.y"
      { (yyval.expr) = (yyvsp[0].expr); }
#line 2079 "CMDgram.cc"
    break;

  case 39: /* object_declare_block: %empty  */
#line 265 "CMDgram.y"
      { (yyval.odcl).slots = NULL; (yyval.odcl).decls = NULL; }
#line 2085 "CMDgram.cc"
    break;

  case 40: /* object_declare_block: slot_assign_list  */
#line 267 "CMDgram.y"
      { (yyval.odcl).slots = (yyvsp[0].slist); (yyval.odcl).decls = NULL; }
#line 2091 "CMDgram.cc"
    break;

  case 41: /* object_declare_block: object_decl_list  */
#line 269 "CMDgram.y"
      { (yyval.odcl).slots = NULL; (yyval.odcl).decls = (yyvsp[0].od); }
#line 2097 "CMDgram.cc"
    break;

  case 42: /* object_declare_block: slot_assign_list object_decl_list  */
#line 271 "CMDgram.y"
      { (yyval.odcl).slots = (yyvsp[-1].slist); (yyval.odcl).decls = (yyvsp[0].od); }
#line 2103 "CMDgram.cc"
    break;

  case 43: /* object_decl_list: object_decl ';'  */
#line 276 "CMDgram.y"
      { (yyval.od) = (yyvsp[-1].od); }
#line 2109 "CMDgram.cc"
    break;

  case 44: /* object_decl_list: object_decl_list object_decl ';'  */
#line 278 "CMDgram.y"
      { (yyvsp[-2].od)->append((yyvsp[-1].od)); (yyval.od) = (yyvsp[-2].od); }
#line 2115 "CMDgram.cc"
    break;

  case 45: /* stmt_block: '{' statement_list '}'  */
#line 283 "CMDgram.y"
      { (yyval.stmt) = (yyvsp[-1].stmt); }
#line 2121 "CMDgram.cc"
    break;

  case 46: /* stmt_block: stmt  */
#line 285 "CMDgram.y"
      { (yyval.stmt) = (yyvsp[0].stmt); }
#line 2127 "CMDgram.cc"
    break;

  case 47: /* switch_stmt: rwSWITCH '(' expr ')' '{' case_block '}'  */
#line 290 "CMDgram.y"
      { (yyval.stmt) = (yyvsp[-1].ifnode); (yyvsp[-1].ifnode)->propagateSwitchExpr((yyvsp[-4].expr), false); }
#line 2133 "CMDgram.cc"
    break;

  case 48: /* switch_stmt: rwSWITCHSTR '(' expr ')' '{' case_block '}'  */
#line 292 "CMDgram.y"
      { (yyval.stmt) = (yyvsp[-1].ifnode); (yyvsp[-1].ifnode)->propagateSwitchExpr((yyvsp[-4].expr), true); }
#line 2139 "CMDgram.cc"
    break;

  case 49: /* case_block: rwCASE case_expr ':' statement_list  */
#line 297 "CMDgram.y"
      { (yyval.ifnode) = IfStmtNode::alloc((yyvsp[-3].i), (yyvsp[-2].expr), (yyvsp[0].stmt), NULL, false); }
#line 2145 "CMDgram.cc"
    break;

  case 50: /* case_block: rwCASE case_expr ':' statement_list rwDEFAULT ':' statement_list  */
#line 299 "CMDgram.y"
      { (yyval.ifnode) = IfStmtNode::alloc((yyvsp[-6].i), (yyvsp[-5].expr), (yyvsp[-3].stmt), (yyvsp[0].stmt), false); }
#line 2151 "CMDgram.cc"
    break;

  case 51: /* case_block: rwCASE case_expr ':' statement_list case_block  */
#line 301 "CMDgram.y"
      { (yyval.ifnode) = IfStmtNode::alloc((yyvsp[-4].i), (yyvsp[-3].expr), (yyvsp[-1].stmt), (yyvsp[0].ifnode), true); }
#line 2157 "CMDgram.cc"
    break;

  case 52: /* case_expr: expr  */
#line 306 "CMDgram.y"
      { (yyval.expr) = (yyvsp[0].expr);}
#line 2163 "CMDgram.cc"
    break;

  case 53: /* case_expr: case_expr rwCASEOR expr  */
#line 308 "CMDgram.y"
      { ((yyvsp[-2].expr))->append((yyvsp[0].expr)); (yyval.expr)=(yyvsp[-2].expr); }
#line 2169 "CMDgram.cc"
    break;

  case 54: /* if_stmt: rwIF '(' expr ')' stmt_block  */
#line 313 "CMDgram.y"
      { (yyval.stmt) = IfStmtNode::alloc((yyvsp[-4].i), (yyvsp[-2].expr), (yyvsp[0].stmt), NULL, false); }
#line 2175 "CMDgram.cc"
    break;

  case 55: /* if_stmt: rwIF '(' expr ')' stmt_block rwELSE stmt_block  */
#line 315 "CMDgram.y"
      { (yyval.stmt) = IfStmtNode::alloc((yyvsp[-6].i), (yyvsp[-4].expr), (yyvsp[-2].stmt), (yyvsp[0].stmt), false); }
#line 2181 "CMDgram.cc"
    break;

  case 56: /* while_stmt: rwWHILE '(' expr ')' stmt_block  */
#line 320 "CMDgram.y"
      { (yyval.stmt) = LoopStmtNode::alloc((yyvsp[-4].i), nil, (yyvsp[-2].expr), nil, (yyvsp[0].stmt), false); }
#line 2187 "CMDgram.cc"
    break;

  case 57: /* while_stmt: rwDO stmt_block rwWHILE '(' expr ')'  */
#line 322 "CMDgram.y"
      { (yyval.stmt) = LoopStmtNode::alloc((yyvsp[-3].i), nil, (yyvsp[-1].expr), nil, (yyvsp[-4].stmt), true); }
#line 2193 "CMDgram.cc"
    break;

  case 58: /* for_stmt: rwFOR '(' expr ';' expr ';' expr ')' stmt_block  */
#line 327 "CMDgram.y"
      { (yyval.stmt) = LoopStmtNode::alloc((yyvsp[-8].i), (yyvsp[-6].expr), (yyvsp[-4].expr), (yyvsp[-2].expr), (yyvsp[0].stmt), false); }
#line 2199 "CMDgram.cc"
    break;

  case 59: /* for_stmt: rwFOR '(' expr ';' expr ';' ')' stmt_block  */
#line 329 "CMDgram.y"
      { (yyval.stmt) = LoopStmtNode::alloc((yyvsp[-7].i), (yyvsp[-5].expr), (yyvsp[-3].expr), NULL, (yyvsp[0].stmt), false); }
#line 2205 "CMDgram.cc"
    break;

  case 60: /* for_stmt: rwFOR '(' expr ';' ';' expr ')' stmt_block  */
#line 331 "CMDgram.y"
      { (yyval.stmt) = LoopStmtNode::alloc((yyvsp[-7].i), (yyvsp[-5].expr), NULL, (yyvsp[-2].expr), (yyvsp[0].stmt), false); }
#line 2211 "CMDgram.cc"
    break;

  case 61: /* for_stmt: rwFOR '(' expr ';' ';' ')' stmt_block  */
#line 333 "CMDgram.y"
      { (yyval.stmt) = LoopStmtNode::alloc((yyvsp[-6].i), (yyvsp[-4].expr), NULL, NULL, (yyvsp[0].stmt), false); }
#line 2217 "CMDgram.cc"
    break;

  case 62: /* for_stmt: rwFOR '(' ';' expr ';' expr ')' stmt_block  */
#line 335 "CMDgram.y"
      { (yyval.stmt) = LoopStmtNode::alloc((yyvsp[-7].i), NULL, (yyvsp[-4].expr), (yyvsp[-2].expr), (yyvsp[0].stmt), false); }
#line 2223 "CMDgram.cc"
    break;

  case 63: /* for_stmt: rwFOR '(' ';' expr ';' ')' stmt_block  */
#line 337 "CMDgram.y"
      { (yyval.stmt) = LoopStmtNode::alloc((yyvsp[-6].i), NULL, (yyvsp[-3].expr), NULL, (yyvsp[0].stmt), false); }
#line 2229 "CMDgram.cc"
    break;

  case 64: /* for_stmt: rwFOR '(' ';' ';' expr ')' stmt_block  */
#line 339 "CMDgram.y"
      { (yyval.stmt) = LoopStmtNode::alloc((yyvsp[-6].i), NULL, NULL, (yyvsp[-2].expr), (yyvsp[0].stmt), false); }
#line 2235 "CMDgram.cc"
    break;

  case 65: /* for_stmt: rwFOR '(' ';' ';' ')' stmt_block  */
#line 341 "CMDgram.y"
      { (yyval.stmt) = LoopStmtNode::alloc((yyvsp[-5].i), NULL, NULL, NULL, (yyvsp[0].stmt), false); }
#line 2241 "CMDgram.cc"
    break;

  case 66: /* expression_stmt: stmt_expr  */
#line 346 "CMDgram.y"
      { (yyval.stmt) = (yyvsp[0].expr); }
#line 2247 "CMDgram.cc"
    break;

  case 67: /* expr: stmt_expr  */
#line 351 "CMDgram.y"
      { (yyval.expr) = (yyvsp[0].expr); }
#line 2253 "CMDgram.cc"
    break;

  case 68: /* expr: '(' expr ')'  */
#line 353 "CMDgram.y"
      { (yyval.expr) = (yyvsp[-1].expr); }
#line 2259 "CMDgram.cc"
    break;

  case 69: /* expr: rwCVLSTART expr_list_decl '}'  */
#line 355 "CMDgram.y"
      { (yyval.expr) = ValueListExprNode::alloc((yyvsp[-1].expr)); }
#line 2265 "CMDgram.cc"
    break;

  case 70: /* expr: expr '^' expr  */
#line 357 "CMDgram.y"
      { (yyval.expr) = IntBinaryExprNode::alloc((yyvsp[-1].i), (yyvsp[-2].expr), (yyvsp[0].expr)); }
#line 2271 "CMDgram.cc"
    break;

  case 71: /* expr: expr '%' expr  */
#line 359 "CMDgram.y"
      { (yyval.expr) = IntBinaryExprNode::alloc((yyvsp[-1].i), (yyvsp[-2].expr), (yyvsp[0].expr)); }
#line 2277 "CMDgram.cc"
    break;

  case 72: /* expr: expr '&' expr  */
#line 361 "CMDgram.y"
      { (yyval.expr) = IntBinaryExprNode::alloc((yyvsp[-1].i), (yyvsp[-2].expr), (yyvsp[0].expr)); }
#line 2283 "CMDgram.cc"
    break;

  case 73: /* expr: expr '|' expr  */
#line 363 "CMDgram.y"
      { (yyval.expr) = IntBinaryExprNode::alloc((yyvsp[-1].i), (yyvsp[-2].expr), (yyvsp[0].expr)); }
#line 2289 "CMDgram.cc"
    break;

  case 74: /* expr: expr '+' expr  */
#line 365 "CMDgram.y"
      { (yyval.expr) = FloatBinaryExprNode::alloc((yyvsp[-1].i), (yyvsp[-2].expr), (yyvsp[0].expr)); }
#line 2295 "CMDgram.cc"
    break;

  case 75: /* expr: expr '-' expr  */
#line 367 "CMDgram.y"
      { (yyval.expr) = FloatBinaryExprNode::alloc((yyvsp[-1].i), (yyvsp[-2].expr), (yyvsp[0].expr)); }
#line 2301 "CMDgram.cc"
    break;

  case 76: /* expr: expr '*' expr  */
#line 369 "CMDgram.y"
      { (yyval.expr) = FloatBinaryExprNode::alloc((yyvsp[-1].i), (yyvsp[-2].expr), (yyvsp[0].expr)); }
#line 2307 "CMDgram.cc"
    break;

  case 77: /* expr: expr '/' expr  */
#line 371 "CMDgram.y"
      { (yyval.expr) = FloatBinaryExprNode::alloc((yyvsp[-1].i), (yyvsp[-2].expr), (yyvsp[0].expr)); }
#line 2313 "CMDgram.cc"
    break;

  case 78: /* expr: '-' expr  */
#line 373 "CMDgram.y"
      { (yyval.expr) = FloatUnaryExprNode::alloc((yyvsp[-1].i), (yyvsp[0].expr)); }
#line 2319 "CMDgram.cc"
    break;

  case 79: /* expr: expr '?' expr ':' expr  */
#line 375 "CMDgram.y"
      { (yyval.expr) = ConditionalExprNode::alloc((yyvsp[-4].expr), (yyvsp[-2].expr), (yyvsp[0].expr)); }
#line 2325 "CMDgram.cc"
    break;

  case 80: /* expr: expr '<' expr  */
#line 377 "CMDgram.y"
      { (yyval.expr) = IntBinaryExprNode::alloc((yyvsp[-1].i), (yyvsp[-2].expr), (yyvsp[0].expr)); }
#line 2331 "CMDgram.cc"
    break;

  case 81: /* expr: expr '>' expr  */
#line 379 "CMDgram.y"
      { (yyval.expr) = IntBinaryExprNode::alloc((yyvsp[-1].i), (yyvsp[-2].expr), (yyvsp[0].expr)); }
#line 2337 "CMDgram.cc"
    break;

  case 82: /* expr: expr opGE expr  */
#line 381 "CMDgram.y"
      { (yyval.expr) = IntBinaryExprNode::alloc((yyvsp[-1].i), (yyvsp[-2].expr), (yyvsp[0].expr)); }
#line 2343 "CMDgram.cc"
    break;

  case 83: /* expr: expr opLE expr  */
#line 383 "CMDgram.y"
      { (yyval.expr) = IntBinaryExprNode::alloc((yyvsp[-1].i), (yyvsp[-2].expr), (yyvsp[0].expr)); }
#line 2349 "CMDgram.cc"
    break;

  case 84: /* expr: expr opEQ expr  */
#line 385 "CMDgram.y"
      { (yyval.expr) = IntBinaryExprNode::alloc((yyvsp[-1].i), (yyvsp[-2].expr), (yyvsp[0].expr)); }
#line 2355 "CMDgram.cc"
    break;

  case 85: /* expr: expr opNE expr  */
#line 387 "CMDgram.y"
      { (yyval.expr) = IntBinaryExprNode::alloc((yyvsp[-1].i), (yyvsp[-2].expr), (yyvsp[0].expr)); }
#line 2361 "CMDgram.cc"
    break;

  case 86: /* expr: expr opOR expr  */
#line 389 "CMDgram.y"
      { (yyval.expr) = IntBinaryExprNode::alloc((yyvsp[-1].i), (yyvsp[-2].expr), (yyvsp[0].expr)); }
#line 2367 "CMDgram.cc"
    break;

  case 87: /* expr: expr opSHL expr  */
#line 391 "CMDgram.y"
      { (yyval.expr) = IntBinaryExprNode::alloc((yyvsp[-1].i), (yyvsp[-2].expr), (yyvsp[0].expr)); }
#line 2373 "CMDgram.cc"
    break;

  case 88: /* expr: expr opSHR expr  */
#line 393 "CMDgram.y"
      { (yyval.expr) = IntBinaryExprNode::alloc((yyvsp[-1].i), (yyvsp[-2].expr), (yyvsp[0].expr)); }
#line 2379 "CMDgram.cc"
    break;

  case 89: /* expr: expr opAND expr  */
#line 395 "CMDgram.y"
      { (yyval.expr) = IntBinaryExprNode::alloc((yyvsp[-1].i), (yyvsp[-2].expr), (yyvsp[0].expr)); }
#line 2385 "CMDgram.cc"
    break;

  case 90: /* expr: expr opSTREQ expr  */
#line 397 "CMDgram.y"
      { (yyval.expr) = StreqExprNode::alloc((yyvsp[-2].expr), (yyvsp[0].expr), true); }
#line 2391 "CMDgram.cc"
    break;

  case 91: /* expr: expr opSTRNE expr  */
#line 399 "CMDgram.y"
      { (yyval.expr) = StreqExprNode::alloc((yyvsp[-2].expr), (yyvsp[0].expr), false); }
#line 2397 "CMDgram.cc"
    break;

  case 92: /* expr: expr opFORGIVE expr  */
#line 401 "CMDgram.y"
      { (yyval.expr) = StrForgiveExprNode::alloc((yyvsp[-2].expr), (yyvsp[0].expr)); }
#line 2403 "CMDgram.cc"
    break;

  case 93: /* expr: expr '@' expr  */
#line 403 "CMDgram.y"
      { (yyval.expr) = StrcatExprNode::alloc((yyvsp[-2].expr), (yyvsp[0].expr), (yyvsp[-1].i)); }
#line 2409 "CMDgram.cc"
    break;

  case 94: /* expr: expr opINSTANCE expr  */
#line 405 "CMDgram.y"
      { (yyval.expr) = InstanceOfExprNode::alloc((yyvsp[-2].expr), (yyvsp[0].expr)); }
#line 2415 "CMDgram.cc"
    break;

  case 95: /* expr: expr opIDXSTART expr ']'  */
#line 407 "CMDgram.y"
      { (yyvsp[-3].expr)->append((yyvsp[-1].expr)); (yyval.expr) = FuncCallExprNode::alloc(StringTable->insert("getWord"), NULL, (yyvsp[-3].expr), false); }
#line 2421 "CMDgram.cc"
    break;

  case 96: /* expr: expr opIDXSTART expr opRANGE expr ']'  */
#line 409 "CMDgram.y"
      { (yyvsp[-3].expr)->append((yyvsp[-1].expr)); (yyvsp[-5].expr)->append((yyvsp[-3].expr)); (yyval.expr) = FuncCallExprNode::alloc(StringTable->insert("getWords"), NULL, (yyvsp[-5].expr), false); }
#line 2427 "CMDgram.cc"
    break;

  case 97: /* expr: '!' expr  */
#line 411 "CMDgram.y"
      { (yyval.expr) = IntUnaryExprNode::alloc((yyvsp[-1].i), (yyvsp[0].expr)); }
#line 2433 "CMDgram.cc"
    break;

  case 98: /* expr: '~' expr  */
#line 413 "CMDgram.y"
      { (yyval.expr) = IntUnaryExprNode::alloc((yyvsp[-1].i), (yyvsp[0].expr)); }
#line 2439 "CMDgram.cc"
    break;

  case 99: /* expr: TAGATOM  */
#line 415 "CMDgram.y"
      { (yyval.expr) = StrConstNode::alloc((yyvsp[0].str), true); }
#line 2445 "CMDgram.cc"
    break;

  case 100: /* expr: FLTCONST  */
#line 417 "CMDgram.y"
      { (yyval.expr) = FloatNode::alloc((yyvsp[0].f)); }
#line 2451 "CMDgram.cc"
    break;

  case 101: /* expr: INTCONST  */
#line 419 "CMDgram.y"
      { (yyval.expr) = IntNode::alloc((yyvsp[0].i)); }
#line 2457 "CMDgram.cc"
    break;

  case 102: /* expr: rwBREAK  */
#line 421 "CMDgram.y"
      { (yyval.expr) = ConstantNode::alloc(StringTable->insert("break")); }
#line 2463 "CMDgram.cc"
    break;

  case 103: /* expr: slot_acc  */
#line 423 "CMDgram.y"
      { (yyval.expr) = SlotAccessNode::alloc((yyvsp[0].slot).object, (yyvsp[0].slot).array, (yyvsp[0].slot).slotName); }
#line 2469 "CMDgram.cc"
    break;

  case 104: /* expr: IDENT  */
#line 425 "CMDgram.y"
      { (yyval.expr) = ConstantNode::alloc((yyvsp[0].s)); }
#line 2475 "CMDgram.cc"
    break;

  case 105: /* expr: STRATOM  */
#line 427 "CMDgram.y"
      { (yyval.expr) = StrConstNode::alloc((yyvsp[0].str), false); }
#line 2481 "CMDgram.cc"
    break;

  case 106: /* expr: NLSATOM  */
#line 429 "CMDgram.y"
      { (yyval.expr) = StrConstNode::alloc((yyvsp[0].str), false); }
#line 2487 "CMDgram.cc"
    break;

  case 107: /* expr: PTHATOM  */
#line 431 "CMDgram.y"
      { (yyval.expr) = FindObjectNode::alloc(StringTable->insert((yyvsp[0].str))); }
#line 2493 "CMDgram.cc"
    break;

  case 108: /* expr: VAR  */
#line 433 "CMDgram.y"
      { (yyval.expr) = (ExprNode*)VarNode::alloc((yyvsp[0].s), NULL); }
#line 2499 "CMDgram.cc"
    break;

  case 109: /* expr: VAR '[' aidx_expr ']'  */
#line 435 "CMDgram.y"
      { (yyval.expr) = (ExprNode*)VarNode::alloc((yyvsp[-3].s), (yyvsp[-1].expr)); }
#line 2505 "CMDgram.cc"
    break;

  case 110: /* slot_acc: expr '.' IDENT  */
#line 440 "CMDgram.y"
      { (yyval.slot).object = (yyvsp[-2].expr); (yyval.slot).slotName = (yyvsp[0].s); (yyval.slot).array = NULL; }
#line 2511 "CMDgram.cc"
    break;

  case 111: /* slot_acc: expr '.' IDENT '[' aidx_expr ']'  */
#line 442 "CMDgram.y"
      { (yyval.slot).object = (yyvsp[-5].expr); (yyval.slot).slotName = (yyvsp[-3].s); (yyval.slot).array = (yyvsp[-1].expr); }
#line 2517 "CMDgram.cc"
    break;

  case 112: /* class_name_expr: IDENT  */
#line 447 "CMDgram.y"
      { (yyval.expr) = ConstantNode::alloc((yyvsp[0].s)); }
#line 2523 "CMDgram.cc"
    break;

  case 113: /* class_name_expr: '(' expr ')'  */
#line 449 "CMDgram.y"
      { (yyval.expr) = (yyvsp[-1].expr); }
#line 2529 "CMDgram.cc"
    break;

  case 114: /* assign_op_struct: opPLUSPLUS  */
#line 454 "CMDgram.y"
      { (yyval.asn).token = '+'; (yyval.asn).expr = FloatNode::alloc(1); }
#line 2535 "CMDgram.cc"
    break;

  case 115: /* assign_op_struct: opMINUSMINUS  */
#line 456 "CMDgram.y"
      { (yyval.asn).token = '-'; (yyval.asn).expr = FloatNode::alloc(1); }
#line 2541 "CMDgram.cc"
    break;

  case 116: /* assign_op_struct: opPLASN expr  */
#line 458 "CMDgram.y"
      { (yyval.asn).token = '+'; (yyval.asn).expr = (yyvsp[0].expr); }
#line 2547 "CMDgram.cc"
    break;

  case 117: /* assign_op_struct: opMIASN expr  */
#line 460 "CMDgram.y"
      { (yyval.asn).token = '-'; (yyval.asn).expr = (yyvsp[0].expr); }
#line 2553 "CMDgram.cc"
    break;

  case 118: /* assign_op_struct: opMLASN expr  */
#line 462 "CMDgram.y"
      { (yyval.asn).token = '*'; (yyval.asn).expr = (yyvsp[0].expr); }
#line 2559 "CMDgram.cc"
    break;

  case 119: /* assign_op_struct: opDVASN expr  */
#line 464 "CMDgram.y"
      { (yyval.asn).token = '/'; (yyval.asn).expr = (yyvsp[0].expr); }
#line 2565 "CMDgram.cc"
    break;

  case 120: /* assign_op_struct: opMODASN expr  */
#line 466 "CMDgram.y"
      { (yyval.asn).token = '%'; (yyval.asn).expr = (yyvsp[0].expr); }
#line 2571 "CMDgram.cc"
    break;

  case 121: /* assign_op_struct: opANDASN expr  */
#line 468 "CMDgram.y"
      { (yyval.asn).token = '&'; (yyval.asn).expr = (yyvsp[0].expr); }
#line 2577 "CMDgram.cc"
    break;

  case 122: /* assign_op_struct: opXORASN expr  */
#line 470 "CMDgram.y"
      { (yyval.asn).token = '^'; (yyval.asn).expr = (yyvsp[0].expr); }
#line 2583 "CMDgram.cc"
    break;

  case 123: /* assign_op_struct: opORASN expr  */
#line 472 "CMDgram.y"
      { (yyval.asn).token = '|'; (yyval.asn).expr = (yyvsp[0].expr); }
#line 2589 "CMDgram.cc"
    break;

  case 124: /* assign_op_struct: opSLASN expr  */
#line 474 "CMDgram.y"
      { (yyval.asn).token = opSHL; (yyval.asn).expr = (yyvsp[0].expr); }
#line 2595 "CMDgram.cc"
    break;

  case 125: /* assign_op_struct: opSRASN expr  */
#line 476 "CMDgram.y"
      { (yyval.asn).token = opSHR; (yyval.asn).expr = (yyvsp[0].expr); }
#line 2601 "CMDgram.cc"
    break;

  case 126: /* stmt_expr: funcall_expr  */
#line 481 "CMDgram.y"
      { (yyval.expr) = (yyvsp[0].expr); }
#line 2607 "CMDgram.cc"
    break;

  case 127: /* stmt_expr: object_decl  */
#line 483 "CMDgram.y"
      { (yyval.expr) = (yyvsp[0].od); }
#line 2613 "CMDgram.cc"
    break;

  case 128: /* stmt_expr: VAR '=' expr  */
#line 485 "CMDgram.y"
      { (yyval.expr) = AssignExprNode::alloc((yyvsp[-2].s), NULL, (yyvsp[0].expr)); }
#line 2619 "CMDgram.cc"
    break;

  case 129: /* stmt_expr: VAR '[' aidx_expr ']' '=' expr  */
#line 487 "CMDgram.y"
      { (yyval.expr) = AssignExprNode::alloc((yyvsp[-5].s), (yyvsp[-3].expr), (yyvsp[0].expr)); }
#line 2625 "CMDgram.cc"
    break;

  case 130: /* stmt_expr: VAR assign_op_struct  */
#line 489 "CMDgram.y"
      { (yyval.expr) = AssignOpExprNode::alloc((yyvsp[-1].s), NULL, (yyvsp[0].asn).expr, (yyvsp[0].asn).token); }
#line 2631 "CMDgram.cc"
    break;

  case 131: /* stmt_expr: VAR '[' aidx_expr ']' assign_op_struct  */
#line 491 "CMDgram.y"
      { (yyval.expr) = AssignOpExprNode::alloc((yyvsp[-4].s), (yyvsp[-2].expr), (yyvsp[0].asn).expr, (yyvsp[0].asn).token); }
#line 2637 "CMDgram.cc"
    break;

  case 132: /* stmt_expr: slot_acc assign_op_struct  */
#line 493 "CMDgram.y"
      { (yyval.expr) = SlotAssignOpNode::alloc((yyvsp[-1].slot).object, (yyvsp[-1].slot).slotName, (yyvsp[-1].slot).array, (yyvsp[0].asn).token, (yyvsp[0].asn).expr); }
#line 2643 "CMDgram.cc"
    break;

  case 133: /* stmt_expr: slot_acc '=' expr  */
#line 495 "CMDgram.y"
      { (yyval.expr) = SlotAssignNode::alloc((yyvsp[-2].slot).object, (yyvsp[-2].slot).array, (yyvsp[-2].slot).slotName, (yyvsp[0].expr)); }
#line 2649 "CMDgram.cc"
    break;

  case 134: /* funcall_expr: IDENT '(' expr_list_decl ')'  */
#line 500 "CMDgram.y"
     { (yyval.expr) = FuncCallExprNode::alloc((yyvsp[-3].s), NULL, (yyvsp[-1].expr), false); }
#line 2655 "CMDgram.cc"
    break;

  case 135: /* funcall_expr: IDENT opCOLONCOLON IDENT '(' expr_list_decl ')'  */
#line 502 "CMDgram.y"
     { (yyval.expr) = FuncCallExprNode::alloc((yyvsp[-3].s), (yyvsp[-5].s), (yyvsp[-1].expr), false); }
#line 2661 "CMDgram.cc"
    break;

  case 136: /* funcall_expr: expr '.' IDENT '(' expr_list_decl ')'  */
#line 504 "CMDgram.y"
      { (yyvsp[-5].expr)->append((yyvsp[-1].expr)); (yyval.expr) = FuncCallExprNode::alloc((yyvsp[-3].s), NULL, (yyvsp[-5].expr), true); }
#line 2667 "CMDgram.cc"
    break;

  case 137: /* expr_list_decl: %empty  */
#line 509 "CMDgram.y"
      { (yyval.expr) = NULL; }
#line 2673 "CMDgram.cc"
    break;

  case 138: /* expr_list_decl: expr_list  */
#line 511 "CMDgram.y"
      { (yyval.expr) = (yyvsp[0].expr); }
#line 2679 "CMDgram.cc"
    break;

  case 139: /* expr_list: expr  */
#line 516 "CMDgram.y"
      { (yyval.expr) = (yyvsp[0].expr); }
#line 2685 "CMDgram.cc"
    break;

  case 140: /* expr_list: expr_list ',' expr  */
#line 518 "CMDgram.y"
      { ((yyvsp[-2].expr))->append((yyvsp[0].expr)); (yyval.expr) = (yyvsp[-2].expr); }
#line 2691 "CMDgram.cc"
    break;

  case 141: /* slot_assign_list: slot_assign  */
#line 523 "CMDgram.y"
      { (yyval.slist) = (yyvsp[0].slist); }
#line 2697 "CMDgram.cc"
    break;

  case 142: /* slot_assign_list: slot_assign_list slot_assign  */
#line 525 "CMDgram.y"
      { (yyvsp[-1].slist)->append((yyvsp[0].slist)); (yyval.slist) = (yyvsp[-1].slist); }
#line 2703 "CMDgram.cc"
    break;

  case 143: /* slot_assign: IDENT '=' expr ';'  */
#line 530 "CMDgram.y"
      { (yyval.slist) = SlotAssignNode::alloc(NULL, NULL, (yyvsp[-3].s), (yyvsp[-1].expr)); }
#line 2709 "CMDgram.cc"
    break;

  case 144: /* slot_assign: rwDATABLOCK '=' expr ';'  */
#line 532 "CMDgram.y"
      { (yyval.slist) = SlotAssignNode::alloc(NULL, NULL, StringTable->insert("datablock"), (yyvsp[-1].expr)); }
#line 2715 "CMDgram.cc"
    break;

  case 145: /* slot_assign: IDENT '[' aidx_expr ']' '=' expr ';'  */
#line 534 "CMDgram.y"
      { (yyval.slist) = SlotAssignNode::alloc(NULL, (yyvsp[-4].expr), (yyvsp[-6].s), (yyvsp[-1].expr)); }
#line 2721 "CMDgram.cc"
    break;

  case 146: /* aidx_expr: expr  */
#line 539 "CMDgram.y"
      { (yyval.expr) = (yyvsp[0].expr); }
#line 2727 "CMDgram.cc"
    break;

  case 147: /* aidx_expr: expr ',' aidx_expr  */
#line 541 "CMDgram.y"
      { (yyval.expr) = CommaCatExprNode::alloc((yyvsp[-2].expr), (yyvsp[0].expr)); }
#line 2733 "CMDgram.cc"
    break;


#line 2737 "CMDgram.cc"

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

#line 543 "CMDgram.y"


