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
extern YYSTYPE yylval;
