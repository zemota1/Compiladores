#ifndef __XPL_SEMANTICS_POSTFIX_WRITER_H__
#define __XPL_SEMANTICS_POSTFIX_WRITER_H__

#include <string>
#include <iostream>
#include <cdk/symbol_table.h>
#include <cdk/emitters/basic_postfix_emitter.h>
#include "targets/basic_ast_visitor.h"
#include "targets/symbol.h"

namespace xpl {

  //!
  //! Traverse syntax tree and generate the corresponding assembly code.
  //!
  class postfix_writer: public basic_ast_visitor {
    cdk::symbol_table<xpl::symbol> &_symtab;
    cdk::basic_postfix_emitter &_pf;
    int _lbl;
    bool global_flag = true;
    size_t arg_offset = 0;
    size_t local_offset = 0;
    int _main = 0;
    std::vector<std::string> stop_vector;
    std::vector<std::string> next_vector;
    public : std::vector<std::string> use_vector;

  public:
    postfix_writer(std::shared_ptr<cdk::compiler> compiler, cdk::symbol_table<xpl::symbol> &symtab,
                   cdk::basic_postfix_emitter &pf) :
        basic_ast_visitor(compiler), _symtab(symtab), _pf(pf), _lbl(0) {
    }

  public:
    ~postfix_writer() {
      os().flush();
    }

  private:
    /** Method used to generate sequential labels. */
    inline std::string mklbl(int lbl) {
      std::ostringstream oss;
      if (lbl < 0)
        oss << ".L" << -lbl;
      else
        oss << "_L" << lbl;
      return oss.str();
    }

  public:
    void do_sequence_node(cdk::sequence_node * const node, int lvl);

  public:
    void do_integer_node(cdk::integer_node * const node, int lvl);
    void do_string_node(cdk::string_node * const node, int lvl);

  public:
    void do_neg_node(cdk::neg_node * const node, int lvl);

  public:
    void do_add_node(cdk::add_node * const node, int lvl);
    void do_sub_node(cdk::sub_node * const node, int lvl);
    void do_mul_node(cdk::mul_node * const node, int lvl);
    void do_div_node(cdk::div_node * const node, int lvl);
    void do_mod_node(cdk::mod_node * const node, int lvl);
    void do_lt_node(cdk::lt_node * const node, int lvl);
    void do_le_node(cdk::le_node * const node, int lvl);
    void do_ge_node(cdk::ge_node * const node, int lvl);
    void do_gt_node(cdk::gt_node * const node, int lvl);
    void do_ne_node(cdk::ne_node * const node, int lvl);
    void do_eq_node(cdk::eq_node * const node, int lvl);
    void do_not_node(cdk::not_node * const node, int lvl);
    void do_or_node(cdk::or_node * const node, int lvl);
    void do_double_node(cdk::double_node * const node, int lvl);
    void do_and_node(cdk::and_node * const node, int lvl);
    
  public:
    void do_identifier_node(cdk::identifier_node * const node, int lvl);
    void do_rvalue_node(cdk::rvalue_node * const node, int lvl);
    void do_assignment_node(cdk::assignment_node * const node, int lvl);

  public:
    /*void do_program_node(xpl::program_node * const node, int lvl);*/
    void do_evaluation_node(xpl::evaluation_node * const node, int lvl);
    void do_print_node(xpl::print_node * const node, int lvl);
    void do_read_node(xpl::read_node * const node, int lvl);

  public:
    void do_while_node(xpl::while_node * const node, int lvl);
    void do_if_node(xpl::if_node * const node, int lvl);
    void do_if_else_node(xpl::if_else_node * const node, int lvl);
    void do_stop_node(xpl::stop_node * const node, int lvl);
    void do_next_node(xpl::next_node * const node, int lvl);
    void do_return_node(xpl::return_node * const node, int lvl);
    void do_sweep_up_node(xpl::sweep_up_node * const node, int lvl);
    void do_sweep_down_node(xpl::sweep_down_node * const node, int lvl);
    void do_block_node(xpl::block_node * const node, int lvl);
    void do_index_node(xpl::index_node * const node, int lvl);
    void do_null_node(xpl::null_node * const node, int lvl);
    void do_address_node(xpl::address_node * const node, int lvl);
    void do_allocation_node(xpl::allocation_node * const node, int lvl);
    void do_function_declaration_node(xpl::function_declaration_node * const node, int lvl);
    void do_function_call_node(xpl::function_call_node * const node, int lvl);
    void do_function_definition_node(xpl::function_definition_node * const node, int lvl);
    void do_variable_node(xpl::variable_node * const node, int lvl);
    void do_positive_node(xpl::positive_node * const node, int lvl);
    
    
 };

} // xpl

#endif
