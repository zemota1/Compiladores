%option c++ yyclass="xpl_scanner" outfile="xpl_scanner.cpp"
%option stack noyywrap yylineno 8bit
%{ 
/* $Id: xpl_scanner.l,v 1.11 2017/05/15 15:50:26 ist181726 Exp $ */
// make relevant includes before including the parser's tab file
#include <string>
#include <cdk/ast/sequence_node.h>
#include <cdk/ast/expression_node.h>
#include "xpl_scanner.h"
#include "xpl_parser.tab.h"

// don't change this
#define yyerror LexerError
%}
%x X_STRING X_COMMENT X_SPECIAL X_IGNSTR

WHITESPACES            [ \t\n]+
DOUBLE		       [0-9]+"."[0-9]*|"."[0-9]+
INT                    0|[1-9][0-9]*
DIGIT                  [0-9]+
HEXA                   0[xX][0-9a-fA-F]+

%%
    /*{set_debug(1);} */

"//".*                  ; /* ignore comments */

">="                   return tGE; 
"<="                   return tLE; 
"=="                   return tEQ; 
"!="                   return tNE; 

"while"                return tWHILE; 
"if"                   return tIF;
"elsif"                return tELSIF;
"else"                 return tELSE; 
"!!"                   return tPRINTLN;
"!"                    return tPRINT;
"@"                    return tREAD;
"next"                 return tNEXT;
"stop"                 return tSTOP;
"sweep"                return tSWEEP;
"return"               return tRETURN;

"public"               return tPUBLIC;
"use"                  return tUSE;

"int"                  return tTINT;
"real"                 return tTREAL;
"string"               return tTSTRING;
"procedure"            return tPROCEDURE;


[A-Za-z_][A-Za-z0-9_]*  yylval.s = new std::string(yytext); return tIDENTIFIER;

\"                     yy_push_state(X_STRING); yylval.s = new std::string("");
<X_STRING>\"           yy_pop_state(); return tSTRING;
<X_STRING>\\           yy_push_state(X_SPECIAL); 
<X_STRING>.            *yylval.s += yytext;


<X_IGNSTR>\\\"         ;
<X_IGNSTR>\"           yy_pop_state();
<X_IGNSTR>.            ;


<X_SPECIAL>n           yy_pop_state(); *yylval.s += "\n";
<X_SPECIAL>t           yy_pop_state(); *yylval.s += "\t";
<X_SPECIAL>r           yy_pop_state(); *yylval.s += "\r";
<X_SPECIAL>\"          yy_pop_state(); *yylval.s += "\"";
<X_SPECIAL>\\          yy_pop_state(); *yylval.s += "\\";
<X_SPECIAL>0          yy_pop_state();yy_pop_state(); yy_push_state(X_IGNSTR); return tSTRING;
<X_SPECIAL>[0-9A-Fa-f][0-9A-Fa-f]? yy_pop_state(); *yylval.s += std::string(1,strtol(yytext,nullptr,16)); 
<X_SPECIAL>.|\n        yyerror("Invalid special char");


"/*"                   yy_push_state(X_COMMENT);
<X_COMMENT>"/*"        yy_push_state(X_COMMENT);
<X_COMMENT>"*/"        yy_pop_state();
<X_COMMENT>.|\n        ;


{INT}                  yylval.i = strtol(yytext, nullptr, 10); if(errno == ERANGE) yyerror("Overflow occurred"); return tINTEGER;
{HEXA}                 yylval.i = strtol(yytext, nullptr, 16); if(errno == ERANGE) yyerror("Overflow occurred"); return tINTEGER;

 
{DOUBLE}                 yylval.d = strtod(yytext, nullptr); if(errno == ERANGE) yyerror("Overflow occurred"); return tREAL;
{DIGIT}[eE][+-]?{DIGIT}  yylval.d = strtod(yytext, nullptr); if(errno == ERANGE) yyerror("Overflow occurred"); return tREAL;
{DOUBLE}[eE][+-]?{DIGIT} yylval.d = strtod(yytext, nullptr); if(errno == ERANGE) yyerror("Overflow occurred"); return tREAL;


[-()<>\[\]=+*/%:,;&{}?*/|.]       return *yytext;

{WHITESPACES}          ; /* ignore whitespace */

.                      yyerror("Unknown character");

%%
// Very, very dirty hack: flex is a mess generating C++ scanners.
int xpl_scanner::yywrap() { return 1; }
