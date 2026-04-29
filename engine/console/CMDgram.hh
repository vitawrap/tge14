/* A Bison parser, made by GNU Bison 3.8.2.  */

/* Bison interface for Yacc-like parsers in C

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

/* DO NOT RELY ON FEATURES THAT ARE NOT DOCUMENTED in the manual,
   especially those whose name start with YY_ or yy_.  They are
   private implementation details that can be changed or removed.  */

#ifndef YY_CMD_CMDGRAM_HH_INCLUDED
# define YY_CMD_CMDGRAM_HH_INCLUDED
/* Debug traces.  */
#ifndef CMDDEBUG
# if defined YYDEBUG
#if YYDEBUG
#   define CMDDEBUG 1
#  else
#   define CMDDEBUG 0
#  endif
# else /* ! defined YYDEBUG */
#  define CMDDEBUG 0
# endif /* ! defined YYDEBUG */
#endif  /* ! defined CMDDEBUG */
#if CMDDEBUG
extern int cmddebug;
#endif

/* Token kinds.  */
#ifndef CMDTOKENTYPE
# define CMDTOKENTYPE
  enum cmdtokentype
  {
    CMDEMPTY = -2,
    CMDEOF = 0,                    /* "end of file"  */
    CMDerror = 256,                /* error  */
    CMDUNDEF = 257,                /* "invalid token"  */
    rwDEFINE = 258,                /* rwDEFINE  */
    rwDECLARE = 259,               /* rwDECLARE  */
    rwCVLSTART = 260,              /* rwCVLSTART  */
    rwBREAK = 261,                 /* rwBREAK  */
    rwELSE = 262,                  /* rwELSE  */
    rwCONTINUE = 263,              /* rwCONTINUE  */
    rwIF = 264,                    /* rwIF  */
    rwRETURN = 265,                /* rwRETURN  */
    rwWHILE = 266,                 /* rwWHILE  */
    rwDO = 267,                    /* rwDO  */
    rwDEFAULT = 268,               /* rwDEFAULT  */
    rwNAMESPACE = 269,             /* rwNAMESPACE  */
    rwFOR = 270,                   /* rwFOR  */
    rwDATABLOCK = 271,             /* rwDATABLOCK  */
    rwSWITCH = 272,                /* rwSWITCH  */
    rwCASE = 273,                  /* rwCASE  */
    rwSWITCHSTR = 274,             /* rwSWITCHSTR  */
    rwCASEOR = 275,                /* rwCASEOR  */
    rwPACKAGE = 276,               /* rwPACKAGE  */
    ILLEGAL_TOKEN = 277,           /* ILLEGAL_TOKEN  */
    INTCONST = 278,                /* INTCONST  */
    VAR = 279,                     /* VAR  */
    IDENT = 280,                   /* IDENT  */
    STRATOM = 281,                 /* STRATOM  */
    TAGATOM = 282,                 /* TAGATOM  */
    PTHATOM = 283,                 /* PTHATOM  */
    FLTCONST = 284,                /* FLTCONST  */
    NLSATOM = 285,                 /* NLSATOM  */
    opMINUSMINUS = 286,            /* opMINUSMINUS  */
    opPLUSPLUS = 287,              /* opPLUSPLUS  */
    opSHL = 288,                   /* opSHL  */
    opSHR = 289,                   /* opSHR  */
    opPLASN = 290,                 /* opPLASN  */
    opMIASN = 291,                 /* opMIASN  */
    opMLASN = 292,                 /* opMLASN  */
    opDVASN = 293,                 /* opDVASN  */
    opMODASN = 294,                /* opMODASN  */
    opANDASN = 295,                /* opANDASN  */
    opXORASN = 296,                /* opXORASN  */
    opORASN = 297,                 /* opORASN  */
    opSLASN = 298,                 /* opSLASN  */
    opSRASN = 299,                 /* opSRASN  */
    opEQ = 300,                    /* opEQ  */
    opNE = 301,                    /* opNE  */
    opGE = 302,                    /* opGE  */
    opLE = 303,                    /* opLE  */
    opAND = 304,                   /* opAND  */
    opOR = 305,                    /* opOR  */
    opSTREQ = 306,                 /* opSTREQ  */
    opRANGE = 307,                 /* opRANGE  */
    opCOLONCOLON = 308,            /* opCOLONCOLON  */
    opMDASN = 309,                 /* opMDASN  */
    opNDASN = 310,                 /* opNDASN  */
    opNTASN = 311,                 /* opNTASN  */
    opCAT = 312,                   /* opCAT  */
    opSTRNE = 313,                 /* opSTRNE  */
    opFORGIVE = 314,               /* opFORGIVE  */
    opINSTANCE = 315,              /* opINSTANCE  */
    UNARY = 316,                   /* UNARY  */
    opIDXSTART = 317               /* opIDXSTART  */
  };
  typedef enum cmdtokentype cmdtoken_kind_t;
#endif

/* Value type.  */
#if ! defined CMDSTYPE && ! defined CMDSTYPE_IS_DECLARED
union CMDSTYPE
{
#line 76 "CMDgram.y"

   char              c;
   int               i;
   const char *      s;
   char *            str;
   double            f;
   StmtNode *        stmt;
   ExprNode *        expr;
   SlotAssignNode *  slist;
   VarNode *         var;
   SlotDecl          slot;
   ObjectBlockDecl   odcl;
   ObjectDeclNode *  od;
   AssignDecl        asn;
   IfStmtNode *      ifnode;

#line 151 "CMDgram.hh"

};
typedef union CMDSTYPE CMDSTYPE;
# define CMDSTYPE_IS_TRIVIAL 1
# define CMDSTYPE_IS_DECLARED 1
#endif


extern CMDSTYPE cmdlval;


int cmdparse (void);


#endif /* !YY_CMD_CMDGRAM_HH_INCLUDED  */
