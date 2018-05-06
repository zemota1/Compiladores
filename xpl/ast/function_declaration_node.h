// $Id: function_declaration_node.h,v 1.4 2017/05/11 15:35:58 ist181726 Exp $ -*- c++ -*-
#ifndef __CDK_FUNCTIONDECLARATIONNODE_H__
#define __CDK_FUNCTIONDECLARATIONNODE_H__

#include <cdk/ast/sequence_node.h>
#include <cdk/ast/basic_node.h>


namespace xpl {

  /**
   * Class for describing if-then nodes.
   */
  class function_declaration_node: public cdk::basic_node {
    bool _use;
    bool _publicc;
    basic_type *_returnType;
    std::string _name;
    cdk::sequence_node *_parameters;

  public:
    function_declaration_node(int lineno, bool use, bool publicc, basic_type *returnType, std::string *name, cdk::sequence_node *parameters) :
        cdk::basic_node(lineno), _use(use), _publicc(publicc), _returnType(returnType), _name(*name), _parameters(parameters) {
    }

  public:
    inline bool use() {
      return _use;
    }
    inline bool publicc() {
      return _publicc;
    }
    inline basic_type *returnType() {
      return _returnType;
    }
    inline std::string name(){
      return _name;
    }
    inline cdk::sequence_node *parameters(){
      return _parameters;
    }

    void accept(basic_ast_visitor *sp, int level) {
      sp->do_function_declaration_node(this, level);
    }

  };

} // xpl

#endif
