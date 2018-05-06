%{
// $Id: xpl_parser.y,v 1.16 2017/05/14 21:46:13 ist181726 Exp $
//-- don't change *any* of these: if you do, you'll break the compiler.
#include <cdk/compiler.h>
#include "ast/all.h"
#define LINE       compiler->scanner()->lineno()
#define yylex()    compiler->scanner()->scan()
#define yyerror(s) compiler->scanner()->error(s)
#define YYPARSE_PARAM_TYPE std::shared_ptr<cdk::compiler>
#define YYPARSE_PARAM      compiler
//-- don't change *any* of these --- END!
%}

%union {
  int                   i;	/* integer value */
  double                d;
  std::string          *s;	/* symbol name or string literal */
  cdk::basic_node      *node;	/* node pointer */
  cdk::sequence_node   *sequence;
  cdk::expression_node *expression; /* expression nodes */
  cdk::lvalue_node     *lvalue;
  basic_type           *t;
  xpl::block_node      *block;
};

%token <i> tINTEGER
%token <s> tIDENTIFIER tSTRING
%token <d> tREAL
%token tWHILE tIF tPRINTLN tPROCEDURE tPUBLIC tUSE tSWEEP tNEXT tNULL tSTOP tRETURN tUNARY tPRINT tREAD tTINT tTREAL tTSTRING tELSIF
 

%nonassoc tIFX
%nonassoc tELSE
%nonassoc tELSIF

%right '='
%left '|'
%left '&'
%nonassoc '~'
%left tEQ tNE
%left tGE tLE '>' '<'
%left '+' '-'
%left '*' '/' '%'
%nonassoc tUNARY '?'
%nonassoc '['

%type <s> strings
%type <node> program func decl var inst arg elsif sweep
%type <sequence> exprs args vars decls param insts
%type <expression> expr literal funcall 
%type <lvalue> lval
%type <t> type
%type <block> block

%{
//-- The rules below will be included in yyparse, the main parsing function.
%}
%%

program	: decls                         { compiler->ast($1); }
        |                               { compiler->ast(new cdk::nil_node(LINE)); }
        ;
        
        
decls : decls decl                      { $$ = new cdk::sequence_node(LINE, $2, $1); }
      | decl                            { $$ = new cdk::sequence_node(LINE, $1); }
      ;
     
     
decl : var ';'                          { $$ = $1; }
     | func                             { $$ = $1; }
     ;
     

var  : type tIDENTIFIER                 { $$ = new xpl::variable_node(LINE, false, false, $1, $2, NULL); }
     | tPUBLIC type tIDENTIFIER         { $$ = new xpl::variable_node(LINE, false, true, $2, $3, NULL); }
     | type tIDENTIFIER '=' expr        { $$ = new xpl::variable_node(LINE, false, false, $1, $2, $4); }
     | tPUBLIC type tIDENTIFIER '=' expr{ $$ = new xpl::variable_node(LINE, false, true, $2, $3, $5); }
     | tUSE type tIDENTIFIER            { $$ = new xpl::variable_node(LINE, true, false, $2, $3, NULL); }
     ;
     
     
func : type tIDENTIFIER '(' param ')'         { $$ = new xpl::function_declaration_node(LINE, false, false, $1, $2, $4); }
     | tPUBLIC type tIDENTIFIER '(' param ')' { $$ = new xpl::function_declaration_node(LINE, false, true, $2, $3, $5); }
     | tUSE type tIDENTIFIER '(' param ')'    { $$ = new xpl::function_declaration_node(LINE, true, false, $2, $3, $5); }
     | tPROCEDURE tIDENTIFIER '(' param ')'  { $$ = new xpl::function_declaration_node(LINE, false, false, new basic_type(0, basic_type::TYPE_VOID), $2, $4); }
     | tPUBLIC tPROCEDURE tIDENTIFIER '(' param ')' { $$ = new xpl::function_declaration_node(LINE, false, true, new basic_type(0, basic_type::TYPE_VOID), $3, $5);}
     | tUSE tPROCEDURE tIDENTIFIER '(' param ')' { $$ = new xpl::function_declaration_node(LINE, true, false, new basic_type(0, basic_type::TYPE_VOID), $3, $5); }
     
     | type tIDENTIFIER '(' param ')' block {             $$ = new xpl::function_definition_node(LINE, false, $1, $2, $4, NULL, $6); }
     | type tIDENTIFIER '(' param ')' '=' literal block { $$ = new xpl::function_definition_node(LINE, false, $1, $2, $4, $7, $8); }
     | tPROCEDURE tIDENTIFIER '(' param ')' block {       $$ = new xpl::function_definition_node(LINE, false, new basic_type(0, basic_type::TYPE_VOID), $2, $4, NULL, $6);}
     
     | tPUBLIC type tIDENTIFIER '(' param ')' block             { $$ = new xpl::function_definition_node(LINE, true, $2, $3, $5, NULL, $7); }
     | tPUBLIC type tIDENTIFIER '(' param ')' '=' literal block { $$ = new xpl::function_definition_node(LINE, true, $2, $3, $5, $8, $9); }
     | tPUBLIC tPROCEDURE tIDENTIFIER '(' param ')' block       { $$ = new xpl::function_definition_node(LINE, true, new basic_type(0, basic_type::TYPE_VOID), $3, $5, NULL, $7);}
     ;
     
     
vars : vars var ';'                     { $$ = new cdk::sequence_node(LINE, $2, $1); }
     | var ';'                          { $$ = new cdk::sequence_node(LINE, $1); }
     ;
     
     
block: "{" vars insts "}"               { $$ = new xpl::block_node(LINE, $2, $3); } 
     | "{" insts "}"                    { $$ = new xpl::block_node(LINE, NULL, $2); }
     | "{" vars "}"                     { $$ = new xpl::block_node(LINE, $2, NULL); }
     | "{" "}"                          { $$ = new xpl::block_node(LINE, NULL, NULL); }
     ;
 
insts : insts inst                      { $$ = new cdk::sequence_node(LINE, $2, $1); }
      | inst                            { $$ = new cdk::sequence_node(LINE, $1); }
      ;


inst : expr ';'                         { $$ = new xpl::evaluation_node(LINE, $1); }
     | expr tPRINT                      { $$ = new xpl::print_node(LINE, $1, false); }
     | expr tPRINTLN                    { $$ = new xpl::print_node(LINE, $1, true); }
     | tWHILE '(' expr ')' inst         { $$ = new xpl::while_node(LINE, $3, $5); }
     | tIF '(' expr ')' inst %prec tIFX { $$ = new xpl::if_node(LINE, $3, $5); }
     | tIF '(' expr ')' inst elsif      { $$ = new xpl::if_else_node(LINE, $3, $5, $6); }
     | block                            { $$ = $1; }
     | sweep                            { $$ = $1; }
     | tNEXT                            { $$ = new xpl::next_node(LINE); }
     | tSTOP                            { $$ = new xpl::stop_node(LINE); }
     | tRETURN                          { $$ = new xpl::return_node(LINE); }
     ;

     
sweep : tSWEEP '+' '(' lval ':' expr ':' expr ')' inst         { $$ = new xpl::sweep_up_node(LINE, $6, $8, $4, $10); }
      | tSWEEP '+' '(' lval ':' expr ':' expr ':' expr')' inst { $$ = new xpl::sweep_up_node(LINE, $6, $8, $10, $4, $12); }
      | tSWEEP '-' '(' lval ':' expr ':' expr ')' inst         { $$ = new xpl::sweep_down_node(LINE, $6, $8, $4, $10); }
      | tSWEEP '-' '(' lval ':' expr ':' expr ':' expr')' inst { $$ = new xpl::sweep_down_node(LINE, $6, $8, $10, $4, $12); }
      ;

      
elsif : tELSIF '(' expr ')' inst elsif      { $$ = new xpl::if_else_node(LINE, $3, $5, $6); } 
      | tELSIF '(' expr ')' inst %prec tIFX { $$ = new xpl::if_node(LINE, $3, $5); }
      | tELSE inst                          { $$ = $2; }
      ;
      
      
exprs : expr ',' exprs           { $$ = new cdk::sequence_node(LINE, $1, $3); }
      | expr                     { $$ = new cdk::sequence_node(LINE, $1); }
      ;
     
expr : expr '+' expr	         { $$ = new cdk::add_node(LINE, $1, $3); }
     | expr '-' expr	         { $$ = new cdk::sub_node(LINE, $1, $3); }
     | expr '*' expr	         { $$ = new cdk::mul_node(LINE, $1, $3); }
     | expr '/' expr	         { $$ = new cdk::div_node(LINE, $1, $3); }
     | expr '%' expr	         { $$ = new cdk::mod_node(LINE, $1, $3); }
     | expr '<' expr	         { $$ = new cdk::lt_node(LINE, $1, $3); }
     | expr '>' expr	         { $$ = new cdk::gt_node(LINE, $1, $3); }
     | expr tGE expr	         { $$ = new cdk::ge_node(LINE, $1, $3); }
     | expr tLE expr             { $$ = new cdk::le_node(LINE, $1, $3); }
     | expr tNE expr	         { $$ = new cdk::ne_node(LINE, $1, $3); }
     | expr tEQ expr	         { $$ = new cdk::eq_node(LINE, $1, $3); }
     | '+' expr %prec tUNARY     { $$ = new xpl::positive_node(LINE, $2); }
     | '-' expr %prec tUNARY     { $$ = new cdk::neg_node(LINE, $2); }
     | '(' expr ')'              { $$ = $2; }
     | '[' expr ']'              { $$ = new xpl::allocation_node(LINE, $2); }
     | lval '?'                  { $$ = new xpl::address_node(LINE, $1); }
     | '~' expr                  { $$ = new cdk::not_node(LINE, $2); }
     | expr '&' expr             { $$ = new cdk::and_node(LINE, $1, $3); }
     | expr '|' expr             { $$ = new cdk::or_node(LINE, $1, $3); }
     | lval '=' expr             { $$ = new cdk::assignment_node(LINE, $1, $3); }
     | tNULL                     { $$ = new xpl::null_node(LINE); }
     | tREAD                     { $$ = new xpl::read_node(LINE); }
     | lval                      { $$ = new cdk::rvalue_node(LINE, $1); }
     | literal                   { $$ = $1; }
     | funcall                   { $$ = $1; }
     ;

param : args                     { $$ = $1;  }
      |                          { $$ = NULL; }
      ;
      
      
args : args ',' arg              { $$ = new cdk::sequence_node(LINE, $3, $1); }
     | arg                       { $$ = new cdk::sequence_node(LINE, $1); }
     ;
     
     
arg : type tIDENTIFIER           { $$ = new xpl::variable_node(LINE, false, false, $1, $2, NULL, true); } 
     ;
     
     
lval : tIDENTIFIER               { $$ = new cdk::identifier_node(LINE, $1); }
     | expr '[' expr ']'         { $$ = new xpl::index_node(LINE, $1, $3); }
     ;

     
type : '[' type ']'              { $$ = new basic_type(4, basic_type::TYPE_POINTER); $$->_subtype = $2; }
     | tTINT                  { $$ = new basic_type(4, basic_type::TYPE_INT); }
     | tTREAL                 { $$ = new basic_type(8, basic_type::TYPE_DOUBLE); }
     | tTSTRING               { $$ = new basic_type(4, basic_type::TYPE_STRING); }
     ;
     
literal : tINTEGER               { $$ = new cdk::integer_node(LINE, $1);}
        | tREAL                  { $$ = new cdk::double_node(LINE, $1); }
        | strings                { $$ = new cdk::string_node(LINE, $1); }
        ;


        
strings : strings tSTRING        { $$ = new std::string(*$1 + *$2); }
        | tSTRING                { $$ = $1; }
        ;
        
        
funcall : tIDENTIFIER '(' exprs ')' { $$ = new xpl::function_call_node(LINE, $1, $3); }
        | tIDENTIFIER '(' ')'       { $$ = new xpl::function_call_node(LINE, $1, NULL); } 
        ;
%%
