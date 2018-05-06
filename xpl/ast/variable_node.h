// $Id: variable_node.h,v 1.6 2017/05/13 13:30:11 ist181726 Exp $ -*- c++ -*-
#ifndef __CDK_VARIABLENODE_H__
#define __CDK_VARIABLENODE_H__

#include <cdk/ast/expression_node.h>

namespace xpl {

  /**
   * Class for describing if-then nodes.
   */
  class variable_node: public cdk::basic_node {
    bool _use;
    bool _publicc;
    basic_type *_type;
    std::string _name;
    cdk::expression_node *_initializer;
    bool _functionArg;



  public:
    inline variable_node(int lineno, bool use, bool publicc, basic_type *type, std::string *name, cdk::expression_node *initializer, bool functionArg = false) :
        cdk::basic_node(lineno), _use(use), _publicc(publicc), _type(type), _name(*name), _initializer(initializer), _functionArg(functionArg){
    }

  public:

    bool use(){
      return _use;
    }

    bool publicc(){
      return _publicc;
    }

    basic_type *type(){
      return _type;
    }

    std::string name(){
      return _name;
    }

    cdk::expression_node *initializer(){
      return _initializer;
    }
    
    bool functionArg(){
        return _functionArg;
    }

    void accept(basic_ast_visitor *sp, int level) {
      sp->do_variable_node(this, level);
    }

  };

} // xpl

#endif
