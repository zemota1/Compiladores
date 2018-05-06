// $Id: allocation_node.h,v 1.2 2017/03/23 15:17:46 ist181726 Exp $ -*- c++ -*-
#ifndef __CDK_ALLOCATIONNODE_H__
#define __CDK_ALLOCATIONNODE_H__

#include <cdk/ast/unary_expression_node.h>
#include <cdk/ast/expression_node.h>

namespace xpl {

  /**
   * Class for describing if-then nodes.
   */
  class allocation_node: public cdk::unary_expression_node {

  public:
    inline allocation_node(int lineno, cdk::expression_node *arg1) :
        cdk::unary_expression_node(lineno, arg1) {
    }

  public:

    void accept(basic_ast_visitor *sp, int level) {
      sp->do_allocation_node(this, level);
    }

  };

} // xpl

#endif
