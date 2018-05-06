// $Id: null_node.h,v 1.2 2017/03/23 15:17:46 ist181726 Exp $ -*- c++ -*-
#ifndef __CDK_NULLNODE_H__
#define __CDK_NULLNODE_H__

#include <cdk/ast/expression_node.h>

namespace xpl {

  /**
   * Class for describing if-then nodes.
   */
  class null_node: public cdk::expression_node { /*literal????*/

  public:
    inline null_node(int lineno) :
        cdk::expression_node(lineno) {
    }

  public:

    void accept(basic_ast_visitor *sp, int level) {
      sp->do_null_node(this, level);
    }

  };

} // xpl

#endif
