// $Id: function_definition_node.h,v 1.7 2017/05/11 15:35:58 ist181726 Exp $ -*- c++ -*-
#ifndef __CDK_FUNCTIONDEFINITIONNODE_H__
#define __CDK_FUNCTIONDEFINITIONNNODE_H__

#include <cdk/ast/sequence_node.h>
#include <cdk/ast/expression_node.h>
#include <cdk/ast/lvalue_node.h>

namespace xpl {

  /**
   * Class for describing if-then nodes.
   */
  class function_definition_node: public cdk::basic_node {
    bool _publicc;
    basic_type *_returnType;
    std::string _name;
    cdk::sequence_node *_parameters;
    cdk::expression_node *_defaultReturn;
    block_node *_body;

  public:
    function_definition_node(int lineno, bool publicc, basic_type *returnType, std::string *name, cdk::sequence_node *parameters, cdk::expression_node *defaultReturn, block_node *body) :
        cdk::basic_node(lineno), _publicc(publicc), _returnType(returnType), _name(*name), _parameters(parameters), _defaultReturn(defaultReturn), _body(body) {
    }

  public:

    inline basic_type *returnType(){
      return _returnType;
    }
    
    inline bool publicc(){
        return _publicc;
    }
    
    inline std::string name(){
      return _name;
    }
    
    inline cdk::sequence_node *parameters(){
      return _parameters;
    }
    
    inline cdk::expression_node *defaultReturn(){
      return _defaultReturn;
    }

    inline block_node *body(){
      return _body;
    }

    void accept(basic_ast_visitor *sp, int level) {
      sp->do_function_definition_node(this, level);
    }

  };

} // xpl

#endif
