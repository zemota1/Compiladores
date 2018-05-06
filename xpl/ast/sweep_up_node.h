// $Id: sweep_up_node.h,v 1.5 2017/03/24 14:38:01 ist181726 Exp $ -*- c++ -*-
#ifndef __XPL_SWEEPUP_H__
#define __XPL_SWEEPUP_H__

#include <cdk/ast/expression_node.h>
#include <cdk/ast/lvalue_node.h>
#include <cdk/ast/integer_node.h>

namespace xpl {

  /**
   * Class for describing if-then nodes.
   */
  class sweep_up_node: public cdk::basic_node {
    cdk::expression_node *_value;
    cdk::expression_node *_finish;
    cdk::expression_node *_step;
    cdk::lvalue_node *_left;
    cdk::basic_node *_instruction;

  public:
    inline sweep_up_node(int lineno, cdk::expression_node *value, cdk::expression_node *finish, cdk::expression_node *step ,cdk::lvalue_node *left, cdk::basic_node *instruction) :
        cdk::basic_node(lineno), _value(value), _finish(finish), _step(step), _left(left), _instruction(instruction) {
    }

    inline sweep_up_node(int lineno, cdk::expression_node *value, cdk::expression_node *finish, cdk::lvalue_node *left, cdk::basic_node *instruction) :
        cdk::basic_node(lineno), _value(value), _finish(finish), _step(new cdk::integer_node(lineno, 1)), _left(left), _instruction(instruction) {
    }

  public:
    inline cdk::expression_node *value() {
      return _value;
    }
    inline cdk::expression_node *finish() {
      return _finish;
    }
    inline cdk::expression_node *step() {
      return _step;
    }
    inline cdk::lvalue_node *left() {
      return _left;
    }
    inline cdk::basic_node *instruction(){
      return _instruction;
    }
    
    void accept(basic_ast_visitor *sp, int level) {
      sp->do_sweep_up_node(this, level);
    }

  };

} // xpl

#endif
