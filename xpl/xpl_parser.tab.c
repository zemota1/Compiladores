/* original parser id follows */
/* yysccsid[] = "@(#)yaccpar	1.9 (Berkeley) 02/21/93" */
/* (use YYMAJOR/YYMINOR for ifdefs dependent on parser version) */

#define YYBYACC 1
#define YYMAJOR 1
#define YYMINOR 9
#define YYPATCH 20150711

#define YYEMPTY        (-1)
#define yyclearin      (yychar = YYEMPTY)
#define yyerrok        (yyerrflag = 0)
#define YYRECOVERING() (yyerrflag != 0)
#define YYENOMEM       (-2)
#define YYEOF          0
#define YYPREFIX "yy"

#define YYPURE 0

#line 2 "xpl_parser.y"
/* $Id: xpl_parser.y,v 1.16 2017/05/14 21:46:13 ist181726 Exp $*/
/*-- don't change *any* of these: if you do, you'll break the compiler.*/
#include <cdk/compiler.h>
#include "ast/all.h"
#define LINE       compiler->scanner()->lineno()
#define yylex()    compiler->scanner()->scan()
#define yyerror(s) compiler->scanner()->error(s)
#define YYPARSE_PARAM_TYPE std::shared_ptr<cdk::compiler>
#define YYPARSE_PARAM      compiler
/*-- don't change *any* of these --- END!*/
#line 14 "xpl_parser.y"
#ifdef YYSTYPE
#undef  YYSTYPE_IS_DECLARED
#define YYSTYPE_IS_DECLARED 1
#endif
#ifndef YYSTYPE_IS_DECLARED
#define YYSTYPE_IS_DECLARED 1
typedef union {
  int                   i;	/* integer value */
  double                d;
  std::string          *s;	/* symbol name or string literal */
  cdk::basic_node      *node;	/* node pointer */
  cdk::sequence_node   *sequence;
  cdk::expression_node *expression; /* expression nodes */
  cdk::lvalue_node     *lvalue;
  basic_type           *t;
  xpl::block_node      *block;
} YYSTYPE;
#endif /* !YYSTYPE_IS_DECLARED */
#line 56 "xpl_parser.y"
/*-- The rules below will be included in yyparse, the main parsing function.*/
#line 53 "xpl_parser.tab.c"

/* compatibility with bison */
#ifdef YYPARSE_PARAM
/* compatibility with FreeBSD */
# ifdef YYPARSE_PARAM_TYPE
#  define YYPARSE_DECL() yyparse(YYPARSE_PARAM_TYPE YYPARSE_PARAM)
# else
#  define YYPARSE_DECL() yyparse(void *YYPARSE_PARAM)
# endif
#else
# define YYPARSE_DECL() yyparse(void)
#endif

/* Parameters sent to lex. */
#ifdef YYLEX_PARAM
# define YYLEX_DECL() yylex(void *YYLEX_PARAM)
# define YYLEX yylex(YYLEX_PARAM)
#else
# define YYLEX_DECL() yylex(void)
# define YYLEX yylex()
#endif

/* Parameters sent to yyerror. */
#ifndef YYERROR_DECL
#define YYERROR_DECL() yyerror(const char *s)
#endif
#ifndef YYERROR_CALL
#define YYERROR_CALL(msg) yyerror(msg)
#endif

extern int YYPARSE_DECL();

#define tINTEGER 257
#define tIDENTIFIER 258
#define tSTRING 259
#define tREAL 260
#define tWHILE 261
#define tIF 262
#define tPRINTLN 263
#define tPROCEDURE 264
#define tPUBLIC 265
#define tUSE 266
#define tSWEEP 267
#define tNEXT 268
#define tNULL 269
#define tSTOP 270
#define tRETURN 271
#define tUNARY 272
#define tPRINT 273
#define tREAD 274
#define tTINT 275
#define tTREAL 276
#define tTSTRING 277
#define tELSIF 278
#define tIFX 279
#define tELSE 280
#define tEQ 281
#define tNE 282
#define tGE 283
#define tLE 284
#define YYERRCODE 256
typedef short YYINT;
static const YYINT yylhs[] = {                           -1,
    0,    0,   12,   12,    3,    3,    4,    4,    4,    4,
    4,    2,    2,    2,    2,    2,    2,    2,    2,    2,
    2,    2,    2,   11,   11,   20,   20,   20,   20,   14,
   14,    5,    5,    5,    5,    5,    5,    5,    5,    5,
    5,    5,    8,    8,    8,    8,    7,    7,    7,    9,
    9,   15,   15,   15,   15,   15,   15,   15,   15,   15,
   15,   15,   15,   15,   15,   15,   15,   15,   15,   15,
   15,   15,   15,   15,   15,   15,   13,   13,   10,   10,
    6,   18,   18,   19,   19,   19,   19,   16,   16,   16,
    1,    1,   17,   17,
};
static const YYINT yylen[] = {                            2,
    1,    0,    2,    1,    2,    1,    2,    3,    4,    5,
    3,    5,    6,    6,    5,    6,    6,    6,    8,    6,
    7,    9,    7,    3,    2,    4,    3,    3,    2,    2,
    1,    2,    2,    2,    5,    5,    6,    1,    1,    1,
    1,    1,   10,   12,   10,   12,    6,    5,    2,    3,
    1,    3,    3,    3,    3,    3,    3,    3,    3,    3,
    3,    3,    2,    2,    3,    3,    2,    2,    3,    3,
    3,    1,    1,    1,    1,    1,    1,    0,    3,    1,
    2,    1,    4,    3,    1,    1,    1,    1,    1,    1,
    2,    1,    4,    3,
};
static const YYINT yydefred[] = {                         0,
    0,    0,    0,   85,   86,   87,    0,    0,    6,    4,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    5,
    3,    0,    0,    0,    0,    0,    0,   84,    0,    0,
   80,    0,    0,    0,    0,    0,    0,    0,    0,   88,
    0,   92,   89,   72,   73,    0,    0,    0,    0,    0,
    0,    0,   75,   76,    0,    0,    0,    0,   81,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
   91,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,   67,    0,   79,    0,
   20,    0,    0,   17,   14,   94,    0,    0,   66,   65,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,   18,    0,    0,    0,
    0,    0,   40,   41,   42,    0,   29,    0,   31,   39,
    0,    0,    0,    0,   38,   23,    0,   21,   93,    0,
   83,    0,    0,    0,    0,    0,    0,    0,   25,   28,
    0,    0,   27,   30,   34,   33,   32,    0,    0,   50,
   19,    0,    0,    0,   11,    0,    0,   24,   26,   22,
    0,    0,    0,    0,    0,   35,    0,    0,    0,    0,
    0,   37,    0,    0,    0,   49,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,   43,    0,   45,
    0,   47,    0,    0,   44,   46,
};
static const YYINT yydgoto[] = {                          8,
   51,    9,   10,   11,  129,   31,  182,  130,   97,   32,
  131,   12,   33,  132,  133,   53,   54,   55,   34,  135,
};
static const YYINT yysindex[] = {                       -62,
 -253,  -27,  -13,    0,    0,    0,  -43,    0,    0,    0,
  -47,  -62, -238,  -17, -220, -203, -189, -177,   -8,    0,
    0,  -37,  -43,   46,  -22,   53,   59,    0, 1322,  -43,
    0,   57,   64, -143,  -43, 1322,  -43,  -43,  -43,    0,
   76,    0,    0,    0,    0, 1322, 1322, 1322, 1322, 1322,
 -141,  755,    0,    0,  -14,   80,  -43,    6,    0,   86,
  755,   89,   90,   91, 1304,  777,   44,   44,  413,  439,
    0, 1322, 1322, 1322, 1322, 1322, 1322, 1322, 1322, 1322,
 1322, 1322, 1322, 1322, 1322, 1322,    0,  -61,    0,  959,
    0,    6,  -55,    0,    0,    0,   95,  451,    0,    0,
  805,  777,  827,  827,   -1,   -1,   -1,   -1,    3,    3,
   44,   44,   44,  486,  755, -206,    0,  102,  104,  -43,
  -43,   16,    0,    0,    0,  845,    0,   87,    0,    0,
 1036, 1072,  350, -113,    0,    0, -206,    0,    0, 1322,
    0,    6, 1322, 1322, -111, -110,  109,  110,    0,    0,
   92, 1131,    0,    0,    0,    0,    0,  101,    6,    0,
    0,  527,  579,  108,    0, 1322, 1322,    0,    0,    0,
 1280, 1280,  755,   39,   56,    0, -201, 1322, 1322,  131,
 1280,    0,  600,  667, 1322,    0, 1322, 1322,  626,  184,
  401, 1280, 1280, 1322, 1280, 1322, -201,    0,  699,    0,
  734,    0, 1280, 1280,    0,    0,
};
static const YYINT yyrindex[] = {                       163,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,  172,    0,    0,    0,    0,    0,    0,    0,    0,
    0,  114,  133,    0,  116,    0,  117,    0,    0,  133,
    0,  136,    0,    0,  133,    0,  133,  133,  133,    0,
  -28,    0,    0,    0,    0,    0,    0,    0,    0,    0,
   29,  119,    0,    0,   66,    0,    0,    1,    0,    0,
  120,    0,    0,    0,    0, 1007,   96,  123,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    4,    0,    0,
    0,    7,   21,    0,    0,    0,    0,  139,    0,    0,
  491, 1145,  873, 1005,  897,  929,  969,  982,  861,  884,
  150,  278,  323,    0,  -33,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,  114,    0,    0,
    0,    0,    0,  116,    0,    0,    0,    0,    0,    0,
    0,    0,    0,  789,  789,    0, 1201,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0, 1231,    0,    0,    0,
    0,    0,    0,    0,    0,    0,
};
static const YYINT yygindex[] = {                         0,
    0,    0,  174,  -88, 1252,  127,    2,    0,   58,    0,
    0,    0,   45,   65, 1538,  -79,    0, -139, 1439,  -36,
};
#define YYTABLESIZE 1734
static const YYINT yytable[] = {                        116,
   15,  128,   30,   12,   14,  137,   16,   71,   82,   82,
   71,   20,   82,   82,   82,   82,   82,   37,   82,   22,
   13,   91,   23,   29,   71,   71,  174,  175,    7,   82,
   82,   82,   82,   82,   82,   84,  142,   24,   36,   84,
   82,   80,  151,   81,   82,   83,   86,    7,   87,   83,
   40,  117,   42,   43,   25,  136,  138,  159,  147,   71,
  148,   90,   82,    7,   82,   90,   90,   90,   26,   90,
   90,   90,   90,   90,   56,   90,  180,    7,  181,   60,
   27,   62,   63,   64,   28,   35,   90,   90,   90,   85,
   90,   15,   38,   85,   12,   82,  178,   16,   39,   86,
   57,   87,   74,   74,   58,  161,   74,   74,   74,   74,
   74,   13,   74,  179,   59,   65,   86,   71,   87,   90,
   88,   90,  170,   74,   74,   74,   92,   74,   90,   93,
   94,   95,   63,   63,   85,  139,   63,   63,   63,   63,
   63,  143,   63,  144,  158,  149,  164,  165,  166,  167,
  168,   90,   90,   63,   63,   63,   74,   63,   74,   64,
   64,   29,    2,   64,   64,   64,   64,   64,   36,   64,
  185,    1,    7,   78,    8,   11,   77,    9,   10,   51,
   64,   64,   64,   89,   64,   21,   54,   54,   63,   74,
   54,   54,   54,   54,   54,  152,   54,  160,  202,    0,
    0,    1,    2,    3,    0,    0,    0,   54,   54,   54,
    0,   54,    4,    5,    6,   64,    0,    0,    0,   63,
   84,   73,    0,    0,  193,   82,   80,    0,   81,   71,
   83,    4,    5,    6,   82,    0,   15,    0,    0,   71,
    0,  194,   54,   79,   82,   78,   64,    4,    5,    6,
   17,    0,   82,   82,   82,   82,    0,    0,    0,    0,
    0,    4,    5,    6,   15,   15,   15,   12,   12,   12,
   16,   16,   16,   54,   85,   15,   15,   15,   12,   12,
   12,   16,   16,   16,   13,   13,   13,    0,    0,    0,
    0,   90,    0,    0,    0,   13,   13,   13,    0,    0,
    0,   90,    0,    0,    0,    0,    0,   72,    0,   90,
   90,   90,   90,    0,   55,   55,    0,    0,   55,   55,
   55,   55,   55,    0,   55,    0,    0,    0,   74,    0,
    0,    0,    0,    0,    0,   55,   55,   55,   74,   55,
    0,    0,    0,    0,    0,    0,   74,   74,   74,   74,
    0,    0,    0,    0,    0,    0,    0,    0,   63,   56,
   56,    0,    0,   56,   56,   56,   56,   56,   63,   56,
   55,    0,    0,    0,    0,    0,   63,   63,   63,   63,
   56,   56,   56,    0,   56,   64,   84,   73,    0,    0,
    0,   82,   80,    0,   81,   64,   83,    0,    0,    0,
    0,   55,    0,   64,   64,   64,   64,    0,  157,   79,
    0,   78,   54,    0,    0,   56,    0,    0,    0,    0,
    0,    0,   54,    0,    0,    0,    0,    0,    0,    0,
   54,   54,   54,   54,    0,    0,    0,   84,   73,    0,
   85,  195,   82,   80,    0,   81,   56,   83,    0,   84,
   73,    0,    0,    0,   82,   80,    0,   81,  196,   83,
   79,    0,   78,    0,   74,   75,   76,   77,    0,    0,
    0,    0,   79,   72,   78,   84,   73,    0,    0,  100,
   82,   80,    0,   81,    0,   83,    0,   84,   73,    0,
    0,   85,   82,   80,  140,   81,    0,   83,   79,    0,
   78,    0,    0,   85,    0,   99,    0,    0,    0,    0,
   79,    0,   78,    0,    0,    0,    0,    0,    0,    0,
    0,    0,   84,   73,   72,    0,    0,   82,   80,   85,
   81,   70,   83,    0,   70,    0,   72,    0,    0,    0,
   55,   85,    0,    0,    0,   79,    0,   78,   70,   70,
   55,    0,    0,    0,    0,    0,    0,    0,   55,   55,
   55,   55,   72,   84,   73,    0,    0,  171,   82,   80,
    0,   81,    0,   83,   72,    0,   85,    0,  141,    0,
    0,    0,    0,   70,    0,   56,   79,    0,   78,    0,
    0,    0,    0,    0,    0,   56,    0,    0,    0,    0,
    0,    0,    0,   56,   56,   56,   56,    0,    0,   72,
    0,    0,  155,    0,   70,   84,   73,   85,    0,  172,
   82,   80,  156,   81,    0,   83,    0,    0,    0,    0,
   74,   75,   76,   77,    0,    0,   84,   73,   79,    0,
   78,   82,   80,    0,   81,    0,   83,    0,    0,    0,
   72,    0,    0,    0,    0,    0,    0,  187,    0,   79,
    0,   78,   84,   73,    0,    0,  192,   82,   80,   85,
   81,    0,   83,    0,    0,    0,    0,    0,    0,    0,
    0,   74,   75,   76,   77,   79,    0,   78,    0,    0,
   85,    0,    0,   74,   75,   76,   77,    0,    0,    0,
    0,    0,   72,   84,   73,    0,    0,    0,   82,   80,
    0,   81,    0,   83,    0,    0,   85,    0,    0,   74,
   75,   76,   77,   72,  188,    0,   79,    0,   78,    0,
    0,   74,   75,   76,   77,   84,   73,    0,    0,  203,
   82,   80,    0,   81,    0,   83,    0,    0,    0,   72,
    0,    0,    0,   70,    0,    0,    0,   85,   79,    0,
   78,    0,    0,   70,    0,    0,   74,   75,   76,   77,
   84,   73,    0,    0,  204,   82,   80,    0,   81,    0,
   83,    0,    0,    0,    0,    0,    0,    0,    0,   85,
   72,   84,   73,   79,    0,   78,   82,   80,    0,   81,
    0,   83,    0,    0,    0,    0,    0,   74,   75,   76,
   77,    0,    0,   84,   79,    0,   78,    0,   82,   80,
    0,   81,   72,   83,   85,   74,   74,    0,    0,    0,
   74,   74,    0,   74,    0,   74,   79,    0,   78,    0,
    0,   84,   73,    0,    0,   85,   82,   80,   74,   81,
   74,   83,    0,    0,    0,    0,    0,   72,    0,   74,
   75,   76,   77,   84,   79,    0,   78,   85,   82,   80,
    0,   81,    0,   83,    0,    0,    0,    0,   72,   74,
   74,   75,   76,   77,   50,    0,   79,   47,   78,   48,
    0,    0,    0,    0,    0,   85,    0,    0,   52,    0,
    0,   52,    0,   52,   52,   52,   74,   75,   76,   77,
   62,    0,   74,   62,    0,    0,   62,   85,   52,   52,
   52,   53,   52,    0,   53,    0,   53,   53,   53,    0,
   62,   62,    0,    0,   59,  126,    0,   59,    0,    0,
   59,   53,   53,   53,    0,   53,    0,   74,   75,   76,
   77,    0,    0,   52,   59,   59,   59,    0,   59,    0,
    0,    0,    0,    0,    0,   62,   60,    0,    0,   60,
   46,    0,   60,    0,    0,    0,   53,    0,    0,   74,
   75,   76,   77,    0,   52,    0,   60,   60,   60,   59,
   60,    0,    0,    0,    0,    0,   62,    0,   50,    0,
    0,   47,    0,   48,    0,    0,   58,   53,    0,   58,
    0,    0,   58,    0,   74,   75,   76,   77,    0,   57,
   59,   60,   57,    0,    0,   57,   58,   58,   58,    0,
   58,    0,    0,    0,    0,   74,   75,   76,   77,   57,
   57,   57,   61,   57,   68,   61,    0,   68,   61,  126,
   68,    0,   60,    0,    0,    0,    0,   74,   75,   76,
   77,   58,   61,   61,   68,   68,    0,    0,    0,   74,
   74,   74,   74,    0,   57,   50,    0,    0,   47,    0,
   48,   90,    0,  127,   46,   74,   75,   76,   77,    0,
    0,    0,   58,    0,    0,    0,    0,   61,    0,   68,
    0,   40,   41,   42,   43,   57,    0,    0,    0,   76,
   77,   50,    0,   44,   47,    0,   48,    0,   45,    4,
    5,    6,    0,   52,    0,    0,  126,    0,   61,    0,
   68,    0,    0,   52,    0,   62,    0,    0,    0,    0,
    0,   52,   52,   52,   52,   62,   53,    0,    0,    0,
    0,    0,    0,   62,   62,    0,   53,    0,   90,   59,
  150,   46,   49,    0,   53,   53,   53,   53,    0,   59,
   50,    0,    0,   47,    0,   48,    0,   59,   59,   59,
   59,    0,   69,    0,    0,   69,    0,    0,   69,    0,
    0,   60,    0,    0,   90,    0,  153,   46,    0,    0,
    0,   60,   69,   69,    0,    0,    0,    0,    0,   60,
   60,   60,   60,    0,    0,   40,   41,   42,   43,  118,
  119,   49,    0,  120,  121,  122,  123,   44,  124,  125,
    0,   58,   45,    4,    5,    6,    0,   69,    0,    0,
   36,   58,    0,   36,   57,   36,    0,    0,    0,   58,
   58,   58,   58,   90,   57,  169,   46,    0,    0,    0,
    0,    0,   57,   57,   57,   57,    0,   61,   69,   68,
   48,    0,    0,   48,    0,   48,    0,   61,    0,   68,
    0,    0,    0,    0,    0,   61,   61,    0,    0,    0,
    0,   36,   40,   41,   42,   43,  118,  119,    0,    0,
  120,  121,  122,  123,   44,  124,  125,    0,    0,   45,
    4,    5,    6,    0,    0,    0,    0,    0,    0,   50,
    0,   48,   47,   36,   48,   36,   36,    0,   40,   41,
   42,   43,  118,  119,    0,    0,    0,    0,  122,  123,
   44,  124,  125,   50,   96,   45,   47,    0,   48,    0,
    0,    0,    0,   48,    0,   48,   48,    0,    0,    0,
    0,   50,    0,    0,   47,    0,   48,    0,    0,    0,
   49,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,  154,    0,    0,    0,   40,   41,   42,
   43,  118,  119,    0,   49,    0,    0,  122,  123,   44,
  124,  125,   90,  154,   45,   46,    0,   69,    0,    0,
    0,    0,   49,    0,    0,    0,    0,   69,    0,    0,
    0,    0,  176,  177,    0,    0,    0,    0,    0,   46,
    0,    0,  186,    0,    0,    0,    0,    0,   13,    0,
   16,   18,    0,  197,  198,   19,  200,   46,    0,    0,
   13,    0,    0,    0,  205,  206,    0,   36,   36,   36,
   36,   36,   36,    0,    0,    0,    0,   36,   36,   36,
   36,   36,    0,    0,   36,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,   48,   48,   48,
   48,   48,   48,    0,    0,    0,    0,   48,   48,   48,
   48,   48,    0,    0,   48,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,  134,    0,
    0,    0,    0,    0,    0,    0,   40,   41,   42,   43,
  118,  119,    0,    0,    0,    0,  122,  123,   44,  124,
  125,    0,    0,   45,    0,    0,    0,    0,  145,  146,
   40,   41,   42,   43,   19,    0,   52,    0,    0,  134,
    0,    0,   44,   61,    0,    0,    0,   45,   40,   41,
   42,   43,    0,   66,   67,   68,   69,   70,    0,    0,
   44,    0,    0,    0,    0,   45,    0,    0,    0,    0,
    0,    0,   98,    0,    0,    0,    0,    0,    0,  101,
  102,  103,  104,  105,  106,  107,  108,  109,  110,  111,
  112,  113,  114,  115,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,   69,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,   98,    0,    0,
  162,  163,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,  173,  173,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,  183,  184,    0,    0,    0,
    0,    0,  189,    0,  190,  191,    0,    0,    0,    0,
    0,  199,    0,  201,
};
static const YYINT yycheck[] = {                         61,
    0,   90,   40,    0,  258,   61,    0,   41,   37,   38,
   44,   59,   41,   42,   43,   44,   45,   40,   47,  258,
    0,   58,   40,   61,   58,   59,  166,  167,   91,   58,
   59,   60,   61,   62,   63,   37,  116,  258,   61,   37,
   42,   43,  131,   45,   42,   47,   61,   91,   63,   47,
  257,   88,  259,  260,  258,   92,   93,  137,   43,   93,
   45,  123,   91,   91,   93,   37,   38,  123,  258,   41,
   42,   43,   44,   45,   30,   47,  278,   91,  280,   35,
  258,   37,   38,   39,   93,   40,   58,   59,   60,   91,
   62,   91,   40,   91,   91,  124,   58,   91,   40,   61,
   44,   63,   37,   38,   41,  142,   41,   42,   43,   44,
   45,   91,   47,   58,  258,   40,   61,  259,   63,   91,
   41,   93,  159,   58,   59,   60,   41,   62,  123,   41,
   41,   41,   37,   38,   91,   41,   41,   42,   43,   44,
   45,   40,   47,   40,  258,   59,  258,  258,   40,   40,
   59,  123,  124,   58,   59,   60,   91,   62,   93,   37,
   38,   61,    0,   41,   42,   43,   44,   45,   61,   47,
   40,    0,   59,   41,   59,   59,   41,   59,   59,   41,
   58,   59,   60,   57,   62,   12,   37,   38,   93,  124,
   41,   42,   43,   44,   45,  131,   47,  140,  197,   -1,
   -1,  264,  265,  266,   -1,   -1,   -1,   58,   59,   60,
   -1,   62,  275,  276,  277,   93,   -1,   -1,   -1,  124,
   37,   38,   -1,   -1,   41,   42,   43,   -1,   45,  263,
   47,  275,  276,  277,  263,   -1,  264,   -1,   -1,  273,
   -1,   58,   93,   60,  273,   62,  124,  275,  276,  277,
  264,   -1,  281,  282,  283,  284,   -1,   -1,   -1,   -1,
   -1,  275,  276,  277,  264,  265,  266,  264,  265,  266,
  264,  265,  266,  124,   91,  275,  276,  277,  275,  276,
  277,  275,  276,  277,  264,  265,  266,   -1,   -1,   -1,
   -1,  263,   -1,   -1,   -1,  275,  276,  277,   -1,   -1,
   -1,  273,   -1,   -1,   -1,   -1,   -1,  124,   -1,  281,
  282,  283,  284,   -1,   37,   38,   -1,   -1,   41,   42,
   43,   44,   45,   -1,   47,   -1,   -1,   -1,  263,   -1,
   -1,   -1,   -1,   -1,   -1,   58,   59,   60,  273,   62,
   -1,   -1,   -1,   -1,   -1,   -1,  281,  282,  283,  284,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,  263,   37,
   38,   -1,   -1,   41,   42,   43,   44,   45,  273,   47,
   93,   -1,   -1,   -1,   -1,   -1,  281,  282,  283,  284,
   58,   59,   60,   -1,   62,  263,   37,   38,   -1,   -1,
   -1,   42,   43,   -1,   45,  273,   47,   -1,   -1,   -1,
   -1,  124,   -1,  281,  282,  283,  284,   -1,   59,   60,
   -1,   62,  263,   -1,   -1,   93,   -1,   -1,   -1,   -1,
   -1,   -1,  273,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
  281,  282,  283,  284,   -1,   -1,   -1,   37,   38,   -1,
   91,   41,   42,   43,   -1,   45,  124,   47,   -1,   37,
   38,   -1,   -1,   -1,   42,   43,   -1,   45,   58,   47,
   60,   -1,   62,   -1,  281,  282,  283,  284,   -1,   -1,
   -1,   -1,   60,  124,   62,   37,   38,   -1,   -1,   41,
   42,   43,   -1,   45,   -1,   47,   -1,   37,   38,   -1,
   -1,   91,   42,   43,   44,   45,   -1,   47,   60,   -1,
   62,   -1,   -1,   91,   -1,   93,   -1,   -1,   -1,   -1,
   60,   -1,   62,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   37,   38,  124,   -1,   -1,   42,   43,   91,
   45,   41,   47,   -1,   44,   -1,  124,   -1,   -1,   -1,
  263,   91,   -1,   -1,   -1,   60,   -1,   62,   58,   59,
  273,   -1,   -1,   -1,   -1,   -1,   -1,   -1,  281,  282,
  283,  284,  124,   37,   38,   -1,   -1,   41,   42,   43,
   -1,   45,   -1,   47,  124,   -1,   91,   -1,   93,   -1,
   -1,   -1,   -1,   93,   -1,  263,   60,   -1,   62,   -1,
   -1,   -1,   -1,   -1,   -1,  273,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,  281,  282,  283,  284,   -1,   -1,  124,
   -1,   -1,  263,   -1,  124,   37,   38,   91,   -1,   41,
   42,   43,  273,   45,   -1,   47,   -1,   -1,   -1,   -1,
  281,  282,  283,  284,   -1,   -1,   37,   38,   60,   -1,
   62,   42,   43,   -1,   45,   -1,   47,   -1,   -1,   -1,
  124,   -1,   -1,   -1,   -1,   -1,   -1,   58,   -1,   60,
   -1,   62,   37,   38,   -1,   -1,   41,   42,   43,   91,
   45,   -1,   47,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,  281,  282,  283,  284,   60,   -1,   62,   -1,   -1,
   91,   -1,   -1,  281,  282,  283,  284,   -1,   -1,   -1,
   -1,   -1,  124,   37,   38,   -1,   -1,   -1,   42,   43,
   -1,   45,   -1,   47,   -1,   -1,   91,   -1,   -1,  281,
  282,  283,  284,  124,   58,   -1,   60,   -1,   62,   -1,
   -1,  281,  282,  283,  284,   37,   38,   -1,   -1,   41,
   42,   43,   -1,   45,   -1,   47,   -1,   -1,   -1,  124,
   -1,   -1,   -1,  263,   -1,   -1,   -1,   91,   60,   -1,
   62,   -1,   -1,  273,   -1,   -1,  281,  282,  283,  284,
   37,   38,   -1,   -1,   41,   42,   43,   -1,   45,   -1,
   47,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   91,
  124,   37,   38,   60,   -1,   62,   42,   43,   -1,   45,
   -1,   47,   -1,   -1,   -1,   -1,   -1,  281,  282,  283,
  284,   -1,   -1,   37,   60,   -1,   62,   -1,   42,   43,
   -1,   45,  124,   47,   91,   37,   38,   -1,   -1,   -1,
   42,   43,   -1,   45,   -1,   47,   60,   -1,   62,   -1,
   -1,   37,   38,   -1,   -1,   91,   42,   43,   60,   45,
   62,   47,   -1,   -1,   -1,   -1,   -1,  124,   -1,  281,
  282,  283,  284,   37,   60,   -1,   62,   91,   42,   43,
   -1,   45,   -1,   47,   -1,   -1,   -1,   -1,  124,   91,
  281,  282,  283,  284,   40,   -1,   60,   43,   62,   45,
   -1,   -1,   -1,   -1,   -1,   91,   -1,   -1,   38,   -1,
   -1,   41,   -1,   43,   44,   45,  281,  282,  283,  284,
   38,   -1,  124,   41,   -1,   -1,   44,   91,   58,   59,
   60,   38,   62,   -1,   41,   -1,   43,   44,   45,   -1,
   58,   59,   -1,   -1,   38,   91,   -1,   41,   -1,   -1,
   44,   58,   59,   60,   -1,   62,   -1,  281,  282,  283,
  284,   -1,   -1,   93,   58,   59,   60,   -1,   62,   -1,
   -1,   -1,   -1,   -1,   -1,   93,   38,   -1,   -1,   41,
  126,   -1,   44,   -1,   -1,   -1,   93,   -1,   -1,  281,
  282,  283,  284,   -1,  124,   -1,   58,   59,   60,   93,
   62,   -1,   -1,   -1,   -1,   -1,  124,   -1,   40,   -1,
   -1,   43,   -1,   45,   -1,   -1,   38,  124,   -1,   41,
   -1,   -1,   44,   -1,  281,  282,  283,  284,   -1,   38,
  124,   93,   41,   -1,   -1,   44,   58,   59,   60,   -1,
   62,   -1,   -1,   -1,   -1,  281,  282,  283,  284,   58,
   59,   60,   38,   62,   38,   41,   -1,   41,   44,   91,
   44,   -1,  124,   -1,   -1,   -1,   -1,  281,  282,  283,
  284,   93,   58,   59,   58,   59,   -1,   -1,   -1,  281,
  282,  283,  284,   -1,   93,   40,   -1,   -1,   43,   -1,
   45,  123,   -1,  125,  126,  281,  282,  283,  284,   -1,
   -1,   -1,  124,   -1,   -1,   -1,   -1,   93,   -1,   93,
   -1,  257,  258,  259,  260,  124,   -1,   -1,   -1,  283,
  284,   40,   -1,  269,   43,   -1,   45,   -1,  274,  275,
  276,  277,   -1,  263,   -1,   -1,   91,   -1,  124,   -1,
  124,   -1,   -1,  273,   -1,  263,   -1,   -1,   -1,   -1,
   -1,  281,  282,  283,  284,  273,  263,   -1,   -1,   -1,
   -1,   -1,   -1,  281,  282,   -1,  273,   -1,  123,  263,
  125,  126,   91,   -1,  281,  282,  283,  284,   -1,  273,
   40,   -1,   -1,   43,   -1,   45,   -1,  281,  282,  283,
  284,   -1,   38,   -1,   -1,   41,   -1,   -1,   44,   -1,
   -1,  263,   -1,   -1,  123,   -1,  125,  126,   -1,   -1,
   -1,  273,   58,   59,   -1,   -1,   -1,   -1,   -1,  281,
  282,  283,  284,   -1,   -1,  257,  258,  259,  260,  261,
  262,   91,   -1,  265,  266,  267,  268,  269,  270,  271,
   -1,  263,  274,  275,  276,  277,   -1,   93,   -1,   -1,
   40,  273,   -1,   43,  263,   45,   -1,   -1,   -1,  281,
  282,  283,  284,  123,  273,  125,  126,   -1,   -1,   -1,
   -1,   -1,  281,  282,  283,  284,   -1,  263,  124,  263,
   40,   -1,   -1,   43,   -1,   45,   -1,  273,   -1,  273,
   -1,   -1,   -1,   -1,   -1,  281,  282,   -1,   -1,   -1,
   -1,   91,  257,  258,  259,  260,  261,  262,   -1,   -1,
  265,  266,  267,  268,  269,  270,  271,   -1,   -1,  274,
  275,  276,  277,   -1,   -1,   -1,   -1,   -1,   -1,   40,
   -1,   91,   43,  123,   45,  125,  126,   -1,  257,  258,
  259,  260,  261,  262,   -1,   -1,   -1,   -1,  267,  268,
  269,  270,  271,   40,   41,  274,   43,   -1,   45,   -1,
   -1,   -1,   -1,  123,   -1,  125,  126,   -1,   -1,   -1,
   -1,   40,   -1,   -1,   43,   -1,   45,   -1,   -1,   -1,
   91,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,  132,   -1,   -1,   -1,  257,  258,  259,
  260,  261,  262,   -1,   91,   -1,   -1,  267,  268,  269,
  270,  271,  123,  152,  274,  126,   -1,  263,   -1,   -1,
   -1,   -1,   91,   -1,   -1,   -1,   -1,  273,   -1,   -1,
   -1,   -1,  171,  172,   -1,   -1,   -1,   -1,   -1,  126,
   -1,   -1,  181,   -1,   -1,   -1,   -1,   -1,    0,   -1,
    2,    3,   -1,  192,  193,    7,  195,  126,   -1,   -1,
   12,   -1,   -1,   -1,  203,  204,   -1,  257,  258,  259,
  260,  261,  262,   -1,   -1,   -1,   -1,  267,  268,  269,
  270,  271,   -1,   -1,  274,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,  257,  258,  259,
  260,  261,  262,   -1,   -1,   -1,   -1,  267,  268,  269,
  270,  271,   -1,   -1,  274,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   90,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,  257,  258,  259,  260,
  261,  262,   -1,   -1,   -1,   -1,  267,  268,  269,  270,
  271,   -1,   -1,  274,   -1,   -1,   -1,   -1,  120,  121,
  257,  258,  259,  260,  126,   -1,   29,   -1,   -1,  131,
   -1,   -1,  269,   36,   -1,   -1,   -1,  274,  257,  258,
  259,  260,   -1,   46,   47,   48,   49,   50,   -1,   -1,
  269,   -1,   -1,   -1,   -1,  274,   -1,   -1,   -1,   -1,
   -1,   -1,   65,   -1,   -1,   -1,   -1,   -1,   -1,   72,
   73,   74,   75,   76,   77,   78,   79,   80,   81,   82,
   83,   84,   85,   86,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,  126,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,  140,   -1,   -1,
  143,  144,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,  166,  167,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,  178,  179,   -1,   -1,   -1,
   -1,   -1,  185,   -1,  187,  188,   -1,   -1,   -1,   -1,
   -1,  194,   -1,  196,
};
#define YYFINAL 8
#ifndef YYDEBUG
#define YYDEBUG 1
#endif
#define YYMAXTOKEN 284
#define YYUNDFTOKEN 307
#define YYTRANSLATE(a) ((a) > YYMAXTOKEN ? YYUNDFTOKEN : (a))
#if YYDEBUG
static const char *const yyname[] = {

"end-of-file",0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,"'%'","'&'",0,"'('","')'","'*'","'+'","','","'-'",0,"'/'",0,0,0,0,0,0,0,0,
0,0,"':'","';'","'<'","'='","'>'","'?'",0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,"'['",0,"']'",0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,"'{'","'|'","'}'","'~'",0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,"tINTEGER","tIDENTIFIER",
"tSTRING","tREAL","tWHILE","tIF","tPRINTLN","tPROCEDURE","tPUBLIC","tUSE",
"tSWEEP","tNEXT","tNULL","tSTOP","tRETURN","tUNARY","tPRINT","tREAD","tTINT",
"tTREAL","tTSTRING","tELSIF","tIFX","tELSE","tEQ","tNE","tGE","tLE",0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,"illegal-symbol",
};
static const char *const yyrule[] = {
"$accept : program",
"program : decls",
"program :",
"decls : decls decl",
"decls : decl",
"decl : var ';'",
"decl : func",
"var : type tIDENTIFIER",
"var : tPUBLIC type tIDENTIFIER",
"var : type tIDENTIFIER '=' expr",
"var : tPUBLIC type tIDENTIFIER '=' expr",
"var : tUSE type tIDENTIFIER",
"func : type tIDENTIFIER '(' param ')'",
"func : tPUBLIC type tIDENTIFIER '(' param ')'",
"func : tUSE type tIDENTIFIER '(' param ')'",
"func : tPROCEDURE tIDENTIFIER '(' param ')'",
"func : tPUBLIC tPROCEDURE tIDENTIFIER '(' param ')'",
"func : tUSE tPROCEDURE tIDENTIFIER '(' param ')'",
"func : type tIDENTIFIER '(' param ')' block",
"func : type tIDENTIFIER '(' param ')' '=' literal block",
"func : tPROCEDURE tIDENTIFIER '(' param ')' block",
"func : tPUBLIC type tIDENTIFIER '(' param ')' block",
"func : tPUBLIC type tIDENTIFIER '(' param ')' '=' literal block",
"func : tPUBLIC tPROCEDURE tIDENTIFIER '(' param ')' block",
"vars : vars var ';'",
"vars : var ';'",
"block : '{' vars insts '}'",
"block : '{' insts '}'",
"block : '{' vars '}'",
"block : '{' '}'",
"insts : insts inst",
"insts : inst",
"inst : expr ';'",
"inst : expr tPRINT",
"inst : expr tPRINTLN",
"inst : tWHILE '(' expr ')' inst",
"inst : tIF '(' expr ')' inst",
"inst : tIF '(' expr ')' inst elsif",
"inst : block",
"inst : sweep",
"inst : tNEXT",
"inst : tSTOP",
"inst : tRETURN",
"sweep : tSWEEP '+' '(' lval ':' expr ':' expr ')' inst",
"sweep : tSWEEP '+' '(' lval ':' expr ':' expr ':' expr ')' inst",
"sweep : tSWEEP '-' '(' lval ':' expr ':' expr ')' inst",
"sweep : tSWEEP '-' '(' lval ':' expr ':' expr ':' expr ')' inst",
"elsif : tELSIF '(' expr ')' inst elsif",
"elsif : tELSIF '(' expr ')' inst",
"elsif : tELSE inst",
"exprs : expr ',' exprs",
"exprs : expr",
"expr : expr '+' expr",
"expr : expr '-' expr",
"expr : expr '*' expr",
"expr : expr '/' expr",
"expr : expr '%' expr",
"expr : expr '<' expr",
"expr : expr '>' expr",
"expr : expr tGE expr",
"expr : expr tLE expr",
"expr : expr tNE expr",
"expr : expr tEQ expr",
"expr : '+' expr",
"expr : '-' expr",
"expr : '(' expr ')'",
"expr : '[' expr ']'",
"expr : lval '?'",
"expr : '~' expr",
"expr : expr '&' expr",
"expr : expr '|' expr",
"expr : lval '=' expr",
"expr : tNULL",
"expr : tREAD",
"expr : lval",
"expr : literal",
"expr : funcall",
"param : args",
"param :",
"args : args ',' arg",
"args : arg",
"arg : type tIDENTIFIER",
"lval : tIDENTIFIER",
"lval : expr '[' expr ']'",
"type : '[' type ']'",
"type : tTINT",
"type : tTREAL",
"type : tTSTRING",
"literal : tINTEGER",
"literal : tREAL",
"literal : strings",
"strings : strings tSTRING",
"strings : tSTRING",
"funcall : tIDENTIFIER '(' exprs ')'",
"funcall : tIDENTIFIER '(' ')'",

};
#endif

int      yydebug;
int      yynerrs;

int      yyerrflag;
int      yychar;
YYSTYPE  yyval;
YYSTYPE  yylval;

/* define the initial stack-sizes */
#ifdef YYSTACKSIZE
#undef YYMAXDEPTH
#define YYMAXDEPTH  YYSTACKSIZE
#else
#ifdef YYMAXDEPTH
#define YYSTACKSIZE YYMAXDEPTH
#else
#define YYSTACKSIZE 10000
#define YYMAXDEPTH  10000
#endif
#endif

#define YYINITSTACKSIZE 200

typedef struct {
    unsigned stacksize;
    YYINT    *s_base;
    YYINT    *s_mark;
    YYINT    *s_last;
    YYSTYPE  *l_base;
    YYSTYPE  *l_mark;
} YYSTACKDATA;
/* variables for the parser stack */
static YYSTACKDATA yystack;

#if YYDEBUG
#include <stdio.h>		/* needed for printf */
#endif

#include <stdlib.h>	/* needed for malloc, etc */
#include <string.h>	/* needed for memset */

/* allocate initial stack or double stack size, up to YYMAXDEPTH */
static int yygrowstack(YYSTACKDATA *data)
{
    int i;
    unsigned newsize;
    YYINT *newss;
    YYSTYPE *newvs;

    if ((newsize = data->stacksize) == 0)
        newsize = YYINITSTACKSIZE;
    else if (newsize >= YYMAXDEPTH)
        return YYENOMEM;
    else if ((newsize *= 2) > YYMAXDEPTH)
        newsize = YYMAXDEPTH;

    i = (int) (data->s_mark - data->s_base);
    newss = (YYINT *)realloc(data->s_base, newsize * sizeof(*newss));
    if (newss == 0)
        return YYENOMEM;

    data->s_base = newss;
    data->s_mark = newss + i;

    newvs = (YYSTYPE *)realloc(data->l_base, newsize * sizeof(*newvs));
    if (newvs == 0)
        return YYENOMEM;

    data->l_base = newvs;
    data->l_mark = newvs + i;

    data->stacksize = newsize;
    data->s_last = data->s_base + newsize - 1;
    return 0;
}

#if YYPURE || defined(YY_NO_LEAKS)
static void yyfreestack(YYSTACKDATA *data)
{
    free(data->s_base);
    free(data->l_base);
    memset(data, 0, sizeof(*data));
}
#else
#define yyfreestack(data) /* nothing */
#endif

#define YYABORT  goto yyabort
#define YYREJECT goto yyabort
#define YYACCEPT goto yyaccept
#define YYERROR  goto yyerrlab

int
YYPARSE_DECL()
{
    int yym, yyn, yystate;
#if YYDEBUG
    const char *yys;

    if ((yys = getenv("YYDEBUG")) != 0)
    {
        yyn = *yys;
        if (yyn >= '0' && yyn <= '9')
            yydebug = yyn - '0';
    }
#endif

    yynerrs = 0;
    yyerrflag = 0;
    yychar = YYEMPTY;
    yystate = 0;

#if YYPURE
    memset(&yystack, 0, sizeof(yystack));
#endif

    if (yystack.s_base == NULL && yygrowstack(&yystack) == YYENOMEM) goto yyoverflow;
    yystack.s_mark = yystack.s_base;
    yystack.l_mark = yystack.l_base;
    yystate = 0;
    *yystack.s_mark = 0;

yyloop:
    if ((yyn = yydefred[yystate]) != 0) goto yyreduce;
    if (yychar < 0)
    {
        if ((yychar = YYLEX) < 0) yychar = YYEOF;
#if YYDEBUG
        if (yydebug)
        {
            yys = yyname[YYTRANSLATE(yychar)];
            printf("%sdebug: state %d, reading %d (%s)\n",
                    YYPREFIX, yystate, yychar, yys);
        }
#endif
    }
    if ((yyn = yysindex[yystate]) && (yyn += yychar) >= 0 &&
            yyn <= YYTABLESIZE && yycheck[yyn] == yychar)
    {
#if YYDEBUG
        if (yydebug)
            printf("%sdebug: state %d, shifting to state %d\n",
                    YYPREFIX, yystate, yytable[yyn]);
#endif
        if (yystack.s_mark >= yystack.s_last && yygrowstack(&yystack) == YYENOMEM)
        {
            goto yyoverflow;
        }
        yystate = yytable[yyn];
        *++yystack.s_mark = yytable[yyn];
        *++yystack.l_mark = yylval;
        yychar = YYEMPTY;
        if (yyerrflag > 0)  --yyerrflag;
        goto yyloop;
    }
    if ((yyn = yyrindex[yystate]) && (yyn += yychar) >= 0 &&
            yyn <= YYTABLESIZE && yycheck[yyn] == yychar)
    {
        yyn = yytable[yyn];
        goto yyreduce;
    }
    if (yyerrflag) goto yyinrecovery;

    YYERROR_CALL("syntax error");

    goto yyerrlab;

yyerrlab:
    ++yynerrs;

yyinrecovery:
    if (yyerrflag < 3)
    {
        yyerrflag = 3;
        for (;;)
        {
            if ((yyn = yysindex[*yystack.s_mark]) && (yyn += YYERRCODE) >= 0 &&
                    yyn <= YYTABLESIZE && yycheck[yyn] == YYERRCODE)
            {
#if YYDEBUG
                if (yydebug)
                    printf("%sdebug: state %d, error recovery shifting\
 to state %d\n", YYPREFIX, *yystack.s_mark, yytable[yyn]);
#endif
                if (yystack.s_mark >= yystack.s_last && yygrowstack(&yystack) == YYENOMEM)
                {
                    goto yyoverflow;
                }
                yystate = yytable[yyn];
                *++yystack.s_mark = yytable[yyn];
                *++yystack.l_mark = yylval;
                goto yyloop;
            }
            else
            {
#if YYDEBUG
                if (yydebug)
                    printf("%sdebug: error recovery discarding state %d\n",
                            YYPREFIX, *yystack.s_mark);
#endif
                if (yystack.s_mark <= yystack.s_base) goto yyabort;
                --yystack.s_mark;
                --yystack.l_mark;
            }
        }
    }
    else
    {
        if (yychar == YYEOF) goto yyabort;
#if YYDEBUG
        if (yydebug)
        {
            yys = yyname[YYTRANSLATE(yychar)];
            printf("%sdebug: state %d, error recovery discards token %d (%s)\n",
                    YYPREFIX, yystate, yychar, yys);
        }
#endif
        yychar = YYEMPTY;
        goto yyloop;
    }

yyreduce:
#if YYDEBUG
    if (yydebug)
        printf("%sdebug: state %d, reducing by rule %d (%s)\n",
                YYPREFIX, yystate, yyn, yyrule[yyn]);
#endif
    yym = yylen[yyn];
    if (yym)
        yyval = yystack.l_mark[1-yym];
    else
        memset(&yyval, 0, sizeof yyval);
    switch (yyn)
    {
case 1:
#line 60 "xpl_parser.y"
	{ compiler->ast(yystack.l_mark[0].sequence); }
break;
case 2:
#line 61 "xpl_parser.y"
	{ compiler->ast(new cdk::nil_node(LINE)); }
break;
case 3:
#line 65 "xpl_parser.y"
	{ yyval.sequence = new cdk::sequence_node(LINE, yystack.l_mark[0].node, yystack.l_mark[-1].sequence); }
break;
case 4:
#line 66 "xpl_parser.y"
	{ yyval.sequence = new cdk::sequence_node(LINE, yystack.l_mark[0].node); }
break;
case 5:
#line 70 "xpl_parser.y"
	{ yyval.node = yystack.l_mark[-1].node; }
break;
case 6:
#line 71 "xpl_parser.y"
	{ yyval.node = yystack.l_mark[0].node; }
break;
case 7:
#line 75 "xpl_parser.y"
	{ yyval.node = new xpl::variable_node(LINE, false, false, yystack.l_mark[-1].t, yystack.l_mark[0].s, NULL); }
break;
case 8:
#line 76 "xpl_parser.y"
	{ yyval.node = new xpl::variable_node(LINE, false, true, yystack.l_mark[-1].t, yystack.l_mark[0].s, NULL); }
break;
case 9:
#line 77 "xpl_parser.y"
	{ yyval.node = new xpl::variable_node(LINE, false, false, yystack.l_mark[-3].t, yystack.l_mark[-2].s, yystack.l_mark[0].expression); }
break;
case 10:
#line 78 "xpl_parser.y"
	{ yyval.node = new xpl::variable_node(LINE, false, true, yystack.l_mark[-3].t, yystack.l_mark[-2].s, yystack.l_mark[0].expression); }
break;
case 11:
#line 79 "xpl_parser.y"
	{ yyval.node = new xpl::variable_node(LINE, true, false, yystack.l_mark[-1].t, yystack.l_mark[0].s, NULL); }
break;
case 12:
#line 83 "xpl_parser.y"
	{ yyval.node = new xpl::function_declaration_node(LINE, false, false, yystack.l_mark[-4].t, yystack.l_mark[-3].s, yystack.l_mark[-1].sequence); }
break;
case 13:
#line 84 "xpl_parser.y"
	{ yyval.node = new xpl::function_declaration_node(LINE, false, true, yystack.l_mark[-4].t, yystack.l_mark[-3].s, yystack.l_mark[-1].sequence); }
break;
case 14:
#line 85 "xpl_parser.y"
	{ yyval.node = new xpl::function_declaration_node(LINE, true, false, yystack.l_mark[-4].t, yystack.l_mark[-3].s, yystack.l_mark[-1].sequence); }
break;
case 15:
#line 86 "xpl_parser.y"
	{ yyval.node = new xpl::function_declaration_node(LINE, false, false, new basic_type(0, basic_type::TYPE_VOID), yystack.l_mark[-3].s, yystack.l_mark[-1].sequence); }
break;
case 16:
#line 87 "xpl_parser.y"
	{ yyval.node = new xpl::function_declaration_node(LINE, false, true, new basic_type(0, basic_type::TYPE_VOID), yystack.l_mark[-3].s, yystack.l_mark[-1].sequence);}
break;
case 17:
#line 88 "xpl_parser.y"
	{ yyval.node = new xpl::function_declaration_node(LINE, true, false, new basic_type(0, basic_type::TYPE_VOID), yystack.l_mark[-3].s, yystack.l_mark[-1].sequence); }
break;
case 18:
#line 90 "xpl_parser.y"
	{             yyval.node = new xpl::function_definition_node(LINE, false, yystack.l_mark[-5].t, yystack.l_mark[-4].s, yystack.l_mark[-2].sequence, NULL, yystack.l_mark[0].block); }
break;
case 19:
#line 91 "xpl_parser.y"
	{ yyval.node = new xpl::function_definition_node(LINE, false, yystack.l_mark[-7].t, yystack.l_mark[-6].s, yystack.l_mark[-4].sequence, yystack.l_mark[-1].expression, yystack.l_mark[0].block); }
break;
case 20:
#line 92 "xpl_parser.y"
	{       yyval.node = new xpl::function_definition_node(LINE, false, new basic_type(0, basic_type::TYPE_VOID), yystack.l_mark[-4].s, yystack.l_mark[-2].sequence, NULL, yystack.l_mark[0].block);}
break;
case 21:
#line 94 "xpl_parser.y"
	{ yyval.node = new xpl::function_definition_node(LINE, true, yystack.l_mark[-5].t, yystack.l_mark[-4].s, yystack.l_mark[-2].sequence, NULL, yystack.l_mark[0].block); }
break;
case 22:
#line 95 "xpl_parser.y"
	{ yyval.node = new xpl::function_definition_node(LINE, true, yystack.l_mark[-7].t, yystack.l_mark[-6].s, yystack.l_mark[-4].sequence, yystack.l_mark[-1].expression, yystack.l_mark[0].block); }
break;
case 23:
#line 96 "xpl_parser.y"
	{ yyval.node = new xpl::function_definition_node(LINE, true, new basic_type(0, basic_type::TYPE_VOID), yystack.l_mark[-4].s, yystack.l_mark[-2].sequence, NULL, yystack.l_mark[0].block);}
break;
case 24:
#line 100 "xpl_parser.y"
	{ yyval.sequence = new cdk::sequence_node(LINE, yystack.l_mark[-1].node, yystack.l_mark[-2].sequence); }
break;
case 25:
#line 101 "xpl_parser.y"
	{ yyval.sequence = new cdk::sequence_node(LINE, yystack.l_mark[-1].node); }
break;
case 26:
#line 105 "xpl_parser.y"
	{ yyval.block = new xpl::block_node(LINE, yystack.l_mark[-2].sequence, yystack.l_mark[-1].sequence); }
break;
case 27:
#line 106 "xpl_parser.y"
	{ yyval.block = new xpl::block_node(LINE, NULL, yystack.l_mark[-1].sequence); }
break;
case 28:
#line 107 "xpl_parser.y"
	{ yyval.block = new xpl::block_node(LINE, yystack.l_mark[-1].sequence, NULL); }
break;
case 29:
#line 108 "xpl_parser.y"
	{ yyval.block = new xpl::block_node(LINE, NULL, NULL); }
break;
case 30:
#line 111 "xpl_parser.y"
	{ yyval.sequence = new cdk::sequence_node(LINE, yystack.l_mark[0].node, yystack.l_mark[-1].sequence); }
break;
case 31:
#line 112 "xpl_parser.y"
	{ yyval.sequence = new cdk::sequence_node(LINE, yystack.l_mark[0].node); }
break;
case 32:
#line 116 "xpl_parser.y"
	{ yyval.node = new xpl::evaluation_node(LINE, yystack.l_mark[-1].expression); }
break;
case 33:
#line 117 "xpl_parser.y"
	{ yyval.node = new xpl::print_node(LINE, yystack.l_mark[-1].expression, false); }
break;
case 34:
#line 118 "xpl_parser.y"
	{ yyval.node = new xpl::print_node(LINE, yystack.l_mark[-1].expression, true); }
break;
case 35:
#line 119 "xpl_parser.y"
	{ yyval.node = new xpl::while_node(LINE, yystack.l_mark[-2].expression, yystack.l_mark[0].node); }
break;
case 36:
#line 120 "xpl_parser.y"
	{ yyval.node = new xpl::if_node(LINE, yystack.l_mark[-2].expression, yystack.l_mark[0].node); }
break;
case 37:
#line 121 "xpl_parser.y"
	{ yyval.node = new xpl::if_else_node(LINE, yystack.l_mark[-3].expression, yystack.l_mark[-1].node, yystack.l_mark[0].node); }
break;
case 38:
#line 122 "xpl_parser.y"
	{ yyval.node = yystack.l_mark[0].block; }
break;
case 39:
#line 123 "xpl_parser.y"
	{ yyval.node = yystack.l_mark[0].node; }
break;
case 40:
#line 124 "xpl_parser.y"
	{ yyval.node = new xpl::next_node(LINE); }
break;
case 41:
#line 125 "xpl_parser.y"
	{ yyval.node = new xpl::stop_node(LINE); }
break;
case 42:
#line 126 "xpl_parser.y"
	{ yyval.node = new xpl::return_node(LINE); }
break;
case 43:
#line 130 "xpl_parser.y"
	{ yyval.node = new xpl::sweep_up_node(LINE, yystack.l_mark[-4].expression, yystack.l_mark[-2].expression, yystack.l_mark[-6].lvalue, yystack.l_mark[0].node); }
break;
case 44:
#line 131 "xpl_parser.y"
	{ yyval.node = new xpl::sweep_up_node(LINE, yystack.l_mark[-6].expression, yystack.l_mark[-4].expression, yystack.l_mark[-2].expression, yystack.l_mark[-8].lvalue, yystack.l_mark[0].node); }
break;
case 45:
#line 132 "xpl_parser.y"
	{ yyval.node = new xpl::sweep_down_node(LINE, yystack.l_mark[-4].expression, yystack.l_mark[-2].expression, yystack.l_mark[-6].lvalue, yystack.l_mark[0].node); }
break;
case 46:
#line 133 "xpl_parser.y"
	{ yyval.node = new xpl::sweep_down_node(LINE, yystack.l_mark[-6].expression, yystack.l_mark[-4].expression, yystack.l_mark[-2].expression, yystack.l_mark[-8].lvalue, yystack.l_mark[0].node); }
break;
case 47:
#line 137 "xpl_parser.y"
	{ yyval.node = new xpl::if_else_node(LINE, yystack.l_mark[-3].expression, yystack.l_mark[-1].node, yystack.l_mark[0].node); }
break;
case 48:
#line 138 "xpl_parser.y"
	{ yyval.node = new xpl::if_node(LINE, yystack.l_mark[-2].expression, yystack.l_mark[0].node); }
break;
case 49:
#line 139 "xpl_parser.y"
	{ yyval.node = yystack.l_mark[0].node; }
break;
case 50:
#line 143 "xpl_parser.y"
	{ yyval.sequence = new cdk::sequence_node(LINE, yystack.l_mark[-2].expression, yystack.l_mark[0].sequence); }
break;
case 51:
#line 144 "xpl_parser.y"
	{ yyval.sequence = new cdk::sequence_node(LINE, yystack.l_mark[0].expression); }
break;
case 52:
#line 147 "xpl_parser.y"
	{ yyval.expression = new cdk::add_node(LINE, yystack.l_mark[-2].expression, yystack.l_mark[0].expression); }
break;
case 53:
#line 148 "xpl_parser.y"
	{ yyval.expression = new cdk::sub_node(LINE, yystack.l_mark[-2].expression, yystack.l_mark[0].expression); }
break;
case 54:
#line 149 "xpl_parser.y"
	{ yyval.expression = new cdk::mul_node(LINE, yystack.l_mark[-2].expression, yystack.l_mark[0].expression); }
break;
case 55:
#line 150 "xpl_parser.y"
	{ yyval.expression = new cdk::div_node(LINE, yystack.l_mark[-2].expression, yystack.l_mark[0].expression); }
break;
case 56:
#line 151 "xpl_parser.y"
	{ yyval.expression = new cdk::mod_node(LINE, yystack.l_mark[-2].expression, yystack.l_mark[0].expression); }
break;
case 57:
#line 152 "xpl_parser.y"
	{ yyval.expression = new cdk::lt_node(LINE, yystack.l_mark[-2].expression, yystack.l_mark[0].expression); }
break;
case 58:
#line 153 "xpl_parser.y"
	{ yyval.expression = new cdk::gt_node(LINE, yystack.l_mark[-2].expression, yystack.l_mark[0].expression); }
break;
case 59:
#line 154 "xpl_parser.y"
	{ yyval.expression = new cdk::ge_node(LINE, yystack.l_mark[-2].expression, yystack.l_mark[0].expression); }
break;
case 60:
#line 155 "xpl_parser.y"
	{ yyval.expression = new cdk::le_node(LINE, yystack.l_mark[-2].expression, yystack.l_mark[0].expression); }
break;
case 61:
#line 156 "xpl_parser.y"
	{ yyval.expression = new cdk::ne_node(LINE, yystack.l_mark[-2].expression, yystack.l_mark[0].expression); }
break;
case 62:
#line 157 "xpl_parser.y"
	{ yyval.expression = new cdk::eq_node(LINE, yystack.l_mark[-2].expression, yystack.l_mark[0].expression); }
break;
case 63:
#line 158 "xpl_parser.y"
	{ yyval.expression = new xpl::positive_node(LINE, yystack.l_mark[0].expression); }
break;
case 64:
#line 159 "xpl_parser.y"
	{ yyval.expression = new cdk::neg_node(LINE, yystack.l_mark[0].expression); }
break;
case 65:
#line 160 "xpl_parser.y"
	{ yyval.expression = yystack.l_mark[-1].expression; }
break;
case 66:
#line 161 "xpl_parser.y"
	{ yyval.expression = new xpl::allocation_node(LINE, yystack.l_mark[-1].expression); }
break;
case 67:
#line 162 "xpl_parser.y"
	{ yyval.expression = new xpl::address_node(LINE, yystack.l_mark[-1].lvalue); }
break;
case 68:
#line 163 "xpl_parser.y"
	{ yyval.expression = new cdk::not_node(LINE, yystack.l_mark[0].expression); }
break;
case 69:
#line 164 "xpl_parser.y"
	{ yyval.expression = new cdk::and_node(LINE, yystack.l_mark[-2].expression, yystack.l_mark[0].expression); }
break;
case 70:
#line 165 "xpl_parser.y"
	{ yyval.expression = new cdk::or_node(LINE, yystack.l_mark[-2].expression, yystack.l_mark[0].expression); }
break;
case 71:
#line 166 "xpl_parser.y"
	{ yyval.expression = new cdk::assignment_node(LINE, yystack.l_mark[-2].lvalue, yystack.l_mark[0].expression); }
break;
case 72:
#line 167 "xpl_parser.y"
	{ yyval.expression = new xpl::null_node(LINE); }
break;
case 73:
#line 168 "xpl_parser.y"
	{ yyval.expression = new xpl::read_node(LINE); }
break;
case 74:
#line 169 "xpl_parser.y"
	{ yyval.expression = new cdk::rvalue_node(LINE, yystack.l_mark[0].lvalue); }
break;
case 75:
#line 170 "xpl_parser.y"
	{ yyval.expression = yystack.l_mark[0].expression; }
break;
case 76:
#line 171 "xpl_parser.y"
	{ yyval.expression = yystack.l_mark[0].expression; }
break;
case 77:
#line 174 "xpl_parser.y"
	{ yyval.sequence = yystack.l_mark[0].sequence;  }
break;
case 78:
#line 175 "xpl_parser.y"
	{ yyval.sequence = NULL; }
break;
case 79:
#line 179 "xpl_parser.y"
	{ yyval.sequence = new cdk::sequence_node(LINE, yystack.l_mark[0].node, yystack.l_mark[-2].sequence); }
break;
case 80:
#line 180 "xpl_parser.y"
	{ yyval.sequence = new cdk::sequence_node(LINE, yystack.l_mark[0].node); }
break;
case 81:
#line 184 "xpl_parser.y"
	{ yyval.node = new xpl::variable_node(LINE, false, false, yystack.l_mark[-1].t, yystack.l_mark[0].s, NULL, true); }
break;
case 82:
#line 188 "xpl_parser.y"
	{ yyval.lvalue = new cdk::identifier_node(LINE, yystack.l_mark[0].s); }
break;
case 83:
#line 189 "xpl_parser.y"
	{ yyval.lvalue = new xpl::index_node(LINE, yystack.l_mark[-3].expression, yystack.l_mark[-1].expression); }
break;
case 84:
#line 193 "xpl_parser.y"
	{ yyval.t = new basic_type(4, basic_type::TYPE_POINTER); yyval.t->_subtype = yystack.l_mark[-1].t; }
break;
case 85:
#line 194 "xpl_parser.y"
	{ yyval.t = new basic_type(4, basic_type::TYPE_INT); }
break;
case 86:
#line 195 "xpl_parser.y"
	{ yyval.t = new basic_type(8, basic_type::TYPE_DOUBLE); }
break;
case 87:
#line 196 "xpl_parser.y"
	{ yyval.t = new basic_type(4, basic_type::TYPE_STRING); }
break;
case 88:
#line 199 "xpl_parser.y"
	{ yyval.expression = new cdk::integer_node(LINE, yystack.l_mark[0].i);}
break;
case 89:
#line 200 "xpl_parser.y"
	{ yyval.expression = new cdk::double_node(LINE, yystack.l_mark[0].d); }
break;
case 90:
#line 201 "xpl_parser.y"
	{ yyval.expression = new cdk::string_node(LINE, yystack.l_mark[0].s); }
break;
case 91:
#line 206 "xpl_parser.y"
	{ yyval.s = new std::string(*yystack.l_mark[-1].s + *yystack.l_mark[0].s); }
break;
case 92:
#line 207 "xpl_parser.y"
	{ yyval.s = yystack.l_mark[0].s; }
break;
case 93:
#line 211 "xpl_parser.y"
	{ yyval.expression = new xpl::function_call_node(LINE, yystack.l_mark[-3].s, yystack.l_mark[-1].sequence); }
break;
case 94:
#line 212 "xpl_parser.y"
	{ yyval.expression = new xpl::function_call_node(LINE, yystack.l_mark[-2].s, NULL); }
break;
#line 1303 "xpl_parser.tab.c"
    }
    yystack.s_mark -= yym;
    yystate = *yystack.s_mark;
    yystack.l_mark -= yym;
    yym = yylhs[yyn];
    if (yystate == 0 && yym == 0)
    {
#if YYDEBUG
        if (yydebug)
            printf("%sdebug: after reduction, shifting from state 0 to\
 state %d\n", YYPREFIX, YYFINAL);
#endif
        yystate = YYFINAL;
        *++yystack.s_mark = YYFINAL;
        *++yystack.l_mark = yyval;
        if (yychar < 0)
        {
            if ((yychar = YYLEX) < 0) yychar = YYEOF;
#if YYDEBUG
            if (yydebug)
            {
                yys = yyname[YYTRANSLATE(yychar)];
                printf("%sdebug: state %d, reading %d (%s)\n",
                        YYPREFIX, YYFINAL, yychar, yys);
            }
#endif
        }
        if (yychar == YYEOF) goto yyaccept;
        goto yyloop;
    }
    if ((yyn = yygindex[yym]) && (yyn += yystate) >= 0 &&
            yyn <= YYTABLESIZE && yycheck[yyn] == yystate)
        yystate = yytable[yyn];
    else
        yystate = yydgoto[yym];
#if YYDEBUG
    if (yydebug)
        printf("%sdebug: after reduction, shifting from state %d \
to state %d\n", YYPREFIX, *yystack.s_mark, yystate);
#endif
    if (yystack.s_mark >= yystack.s_last && yygrowstack(&yystack) == YYENOMEM)
    {
        goto yyoverflow;
    }
    *++yystack.s_mark = (YYINT) yystate;
    *++yystack.l_mark = yyval;
    goto yyloop;

yyoverflow:
    YYERROR_CALL("yacc stack overflow");

yyabort:
    yyfreestack(&yystack);
    return (1);

yyaccept:
    yyfreestack(&yystack);
    return (0);
}
