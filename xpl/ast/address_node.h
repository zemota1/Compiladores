// $Id: address_node.h,v 1.2 2017/03/23 15:17:46 ist181726 Exp $ -*- c++ -*-
#ifndef __CDK_ADDRESSNODE_H__
#define __CDK_ADDRESSNODE_H__

#include <cdk/ast/unary_expression_node.h>
#include <cdk/ast/lvalue_node.h>

namespace xpl {

  /**
   * Class for describing if-then nodes.
   */
  class address_node: public cdk::unary_expression_node {

  public:
    inline address_node(int lineno, cdk::lvalue_node *arg1) :
        cdk::unary_expression_node(lineno, arg1) {
    }

  public:

    void accept(basic_ast_visitor *sp, int level) {
      sp->do_address_node(this, level);
    }

  };

} // xpl

#endif
