// $Id: function_call_node.h,v 1.5 2017/05/11 15:35:58 ist181726 Exp $ -*- c++ -*-
#ifndef __CDK_FUNCTIONCALLNODE_H__
#define __CDK_FUNCTIONCALLNODE_H__

#include <cdk/ast/sequence_node.h>
#include <cdk/ast/expression_node.h>


namespace xpl {

  /**
   * Class for describing if-then nodes.
   */
  class function_call_node: public cdk::expression_node {
    std::string _name;
    cdk::sequence_node *_args;

  public:
    inline function_call_node(int lineno, std::string *name, cdk::sequence_node *args) :
        cdk::expression_node(lineno), _name(*name), _args(args) {
    }

  public:

    inline std::string name(){
      return _name;
    }
    inline cdk::sequence_node *args(){
      return _args;
    }

    void accept(basic_ast_visitor *sp, int level) {
      sp->do_function_call_node(this, level);
    }

  };

} // xpl

#endif
