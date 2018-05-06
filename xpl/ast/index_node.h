// $Id: index_node.h,v 1.2 2017/03/23 15:17:46 ist181726 Exp $ -*- c++ -*-
#ifndef __CDK_INDEXNODE_H__
#define __CDK_INDEXNODE_H__

#include <cdk/ast/expression_node.h>
#include <cdk/ast/lvalue_node.h>


namespace xpl {

  /**
   * Class for describing if-then nodes.
   */
  class index_node: public cdk::lvalue_node {
    cdk::expression_node *_base;
    cdk::expression_node *_offset;

  public:
    inline index_node(int lineno, cdk::expression_node *base, cdk::expression_node *offset) :
        cdk::lvalue_node(lineno), _base(base), _offset(offset) {
    }

  public:
    inline cdk::expression_node *base() {
      return _base;
    }
    inline cdk::basic_node *offset() {
      return _offset;
    }

    void accept(basic_ast_visitor *sp, int level) {
      sp->do_index_node(this, level);
    }

  };

} // xpl

#endif
