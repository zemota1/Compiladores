#include <string>
#include <sstream>
#include "targets/type_checker.h"
#include "targets/postfix_writer.h"
#include "targets/stack_visitor.h"  // all.h is automatically generated
#include "ast/all.h"

//---------------------------------------------------------------------------

void xpl::postfix_writer::do_sequence_node(cdk::sequence_node * const node, int lvl) {
  for (size_t i = 0; i < node->size(); i++) {
    node->node(i)->accept(this, lvl);
  }
}

//---------------------------------------------------------------------------

void xpl::postfix_writer::do_integer_node(cdk::integer_node * const node, int lvl) {
  if(global_flag){
      _pf.CONST(node->value());
  }
  else{
    _pf.INT(node->value()); // push an integer
    //_pf.DUP();
  }
}

void xpl::postfix_writer::do_string_node(cdk::string_node * const node, int lvl) {
  int lbl1;

  /* generate the string */
  _pf.RODATA(); // strings are DATA readonly
  _pf.ALIGN(); // make sure we are aligned
  _pf.LABEL(mklbl(lbl1 = ++_lbl)); // give the string a name
  _pf.STR(node->value()); // output string characters
  
  if(global_flag){
    _pf.DATA();
    _pf.ALIGN();
    _pf.ID(mklbl(lbl1));
}
  else{
  /* leave the address on the stack */
  _pf.TEXT(); // return to the TEXT segment
  _pf.ADDR(mklbl(lbl1)); // the string to be printed
  }
      
}

//---------------------------------------------------------------------------

void xpl::postfix_writer::do_neg_node(cdk::neg_node * const node, int lvl) {
  ASSERT_SAFE_EXPRESSIONS;
  node->argument()->accept(this, lvl); // determine the value
  _pf.NEG(); // 2-complement
}

//---------------------------------------------------------------------------

void xpl::postfix_writer::do_add_node(cdk::add_node * const node, int lvl) {
  ASSERT_SAFE_EXPRESSIONS;
  node->left()->accept(this, lvl);
  node->right()->accept(this, lvl);
  _pf.ADD();
}
void xpl::postfix_writer::do_sub_node(cdk::sub_node * const node, int lvl) {
  ASSERT_SAFE_EXPRESSIONS;
  node->left()->accept(this, lvl);
  node->right()->accept(this, lvl);
  _pf.SUB();
}
void xpl::postfix_writer::do_mul_node(cdk::mul_node * const node, int lvl) {
  ASSERT_SAFE_EXPRESSIONS;
  node->left()->accept(this, lvl);
  node->right()->accept(this, lvl);
  _pf.MUL();
}
void xpl::postfix_writer::do_div_node(cdk::div_node * const node, int lvl) {
  ASSERT_SAFE_EXPRESSIONS;
  node->left()->accept(this, lvl);
  node->right()->accept(this, lvl);
  _pf.DIV();
}
void xpl::postfix_writer::do_mod_node(cdk::mod_node * const node, int lvl) {
  ASSERT_SAFE_EXPRESSIONS;
  node->left()->accept(this, lvl);
  node->right()->accept(this, lvl);
  _pf.MOD();
}
void xpl::postfix_writer::do_lt_node(cdk::lt_node * const node, int lvl) {
  ASSERT_SAFE_EXPRESSIONS;
  node->left()->accept(this, lvl);
  node->right()->accept(this, lvl);
  _pf.LT();
}
void xpl::postfix_writer::do_le_node(cdk::le_node * const node, int lvl) {
  ASSERT_SAFE_EXPRESSIONS;
  node->left()->accept(this, lvl);
  node->right()->accept(this, lvl);
  _pf.LE();
}
void xpl::postfix_writer::do_ge_node(cdk::ge_node * const node, int lvl) {
  ASSERT_SAFE_EXPRESSIONS;
  node->left()->accept(this, lvl);
  node->right()->accept(this, lvl);
  _pf.GE();
}
void xpl::postfix_writer::do_gt_node(cdk::gt_node * const node, int lvl) {
  ASSERT_SAFE_EXPRESSIONS;
  node->left()->accept(this, lvl);
  node->right()->accept(this, lvl);
  _pf.GT();
}
void xpl::postfix_writer::do_ne_node(cdk::ne_node * const node, int lvl) {
  ASSERT_SAFE_EXPRESSIONS;
  node->left()->accept(this, lvl);
  node->right()->accept(this, lvl);
  _pf.NE();
}
void xpl::postfix_writer::do_eq_node(cdk::eq_node * const node, int lvl) {
  ASSERT_SAFE_EXPRESSIONS;
  node->left()->accept(this, lvl);
  node->right()->accept(this, lvl);
  _pf.EQ();
}

//---------------------------------------------------------------------------

void xpl::postfix_writer::do_identifier_node(cdk::identifier_node * const node, int lvl) {
  ASSERT_SAFE_EXPRESSIONS;
  // simplified generation: all variables are global
  std::shared_ptr<xpl::symbol> symbol = _symtab.find(node->name());
  if(symbol->offset() != 0){ /*LOCAL*/
    _pf.LOCAL(symbol->offset());
  }
  else{ 
    _pf.ADDR(node->name());
  }
}

void xpl::postfix_writer::do_rvalue_node(cdk::rvalue_node * const node, int lvl) {
  ASSERT_SAFE_EXPRESSIONS;
  node->lvalue()->accept(this, lvl);
  _pf.LOAD(); // depends on type size
}

void xpl::postfix_writer::do_assignment_node(cdk::assignment_node * const node, int lvl) { //TODO: FAZER NOVO
  ASSERT_SAFE_EXPRESSIONS;
  node->rvalue()->accept(this, lvl); // determine the new value
  _pf.DUP();
  if (new_symbol() == nullptr) {
    node->lvalue()->accept(this, lvl); // where to store the value
  } else {
    _pf.DATA(); // variables are all global and live in DATA
    _pf.ALIGN(); // make sure we are aligned
    _pf.LABEL(new_symbol()->name()); // name variable location
    _pf.CONST(0); // initialize it to 0 (zero)
    _pf.TEXT(); // return to the TEXT segment
    node->lvalue()->accept(this, lvl);  //DAVID: bah!
  }
  _pf.STORE(); // store the value at address
}

//---------------------------------------------------------------------------

void xpl::postfix_writer::do_function_definition_node(xpl::function_definition_node * const node, int lvl) {
  // The ProgramNode (representing the whole program) is the
  // main function node.
  ASSERT_SAFE_EXPRESSIONS;

  xpl::stack_visitor sv(_compiler);
  node->accept(&sv, lvl);

  _symtab.push();

  // generate the main function (RTS mandates that its name be "_main")
  _pf.TEXT();
  _pf.ALIGN();

  std::string functionName = node->name();

  for(size_t i=0; i < use_vector.size(); i++){
    if(use_vector[i] == functionName) use_vector.erase(use_vector.begin() + i);
  }

  if(functionName == "_main") {
    std::string aux = std::to_string(_main);
    _pf.GLOBAL("_main" + aux, _pf.FUNC());
    _pf.LABEL("_main" + aux);
    ++_main;
  }
  

  else if(functionName == "xpl"){
    _pf.GLOBAL("_main", _pf.FUNC());
    _pf.LABEL("_main");
  }

  else{
    _pf.GLOBAL(functionName, _pf.FUNC());
    _pf.LABEL(functionName);
  }
  size_t inc = node->returnType()->size();

  _pf.ENTER(sv.size() + inc);  

  std::cout<< functionName << std::endl;

  global_flag = false;
  arg_offset = 8;
  local_offset = 0;
  int offset_return = node->returnType()->size();

  if(node->parameters() != NULL)
    node->parameters()->accept(this, lvl); //argumentos de uma funcao

  //Default Return
  if(node->defaultReturn() != NULL){
    node->defaultReturn()->accept(this, lvl);
    _pf.LOCAL(-(offset_return));
    _pf.STORE();
  }


  //body
  node->body()->accept(this, lvl);
  global_flag = true;
    
  // VOID NAO TEM VALOR
  if(node->returnType()->name() != basic_type::TYPE_VOID){
    _pf.LOCAL(-(offset_return));
    _pf.LOAD();
    _pf.POP();
  }

  _pf.LEAVE();
  _pf.RET();

  _symtab.pop();

  // these are just a few library function imports 
  if(functionName == "xpl"){
    _pf.EXTERN("readi");
    _pf.EXTERN("printi");
    _pf.EXTERN("prints");
    _pf.EXTERN("println");
  }
}

//---------------------------------------------------------------------------

void xpl::postfix_writer::do_evaluation_node(xpl::evaluation_node * const node, int lvl) {
  ASSERT_SAFE_EXPRESSIONS;
  node->argument()->accept(this, lvl); // determine the value
  if (node->argument()->type()->name() == basic_type::TYPE_INT) {
    _pf.TRASH(4); // delete the evaluated value
  } else if (node->argument()->type()->name() == basic_type::TYPE_STRING) {
    _pf.TRASH(4); // delete the evaluated value's address

  } else if (node->argument()->type()->name() == basic_type::TYPE_POINTER){
    _pf.TRASH(4);
  } 
  else if (node->argument()->type()->name() == basic_type::TYPE_DOUBLE){
    _pf.TRASH(8);
  }
  else if (node->argument()->type()->name() == basic_type::TYPE_VOID){
    //nada!!!
  }else {
    std::cerr << "ERROR: CANNOT HAPPEN!" << std::endl;
    exit(1);
  }
}

void xpl::postfix_writer::do_print_node(xpl::print_node * const node, int lvl) {
  ASSERT_SAFE_EXPRESSIONS;
  node->argument()->accept(this, lvl); // determine the value to prinet
  if (node->argument()->type()->name() == basic_type::TYPE_INT) {
    _pf.CALL("printi");
    _pf.TRASH(4); // delete the printed value
  }
  else if (node->argument()->type()->name() == basic_type::TYPE_STRING) {
    _pf.CALL("prints");
    _pf.TRASH(4); // delete the printed value's address
  }
  else if (node->argument()->type()->name() == basic_type::TYPE_DOUBLE) {
    _pf.CALL("printd");
    _pf.TRASH(4); // delete the printed value's address
  } 
  else {
    std::cerr << "ERROR: CANNOT HAPPEN!" << std::endl;
    exit(1);
  }
  if(node->newline())
    _pf.CALL("println"); // print a newline
}

//---------------------------------------------------------------------------

void xpl::postfix_writer::do_read_node(xpl::read_node * const node, int lvl) {
  ASSERT_SAFE_EXPRESSIONS;
  _pf.CALL("readi");
  _pf.PUSH();
  /*
  node->argument()->accept(this, lvl);
  */_pf.STORE();
}

//---------------------------------------------------------------------------

void xpl::postfix_writer::do_while_node(xpl::while_node * const node, int lvl) {
  ASSERT_SAFE_EXPRESSIONS;
  int lbl1, lbl2;
  std::string ifLabel = mklbl(lbl1 = ++_lbl);
  std::string endLabel = mklbl(lbl2 = ++_lbl);
  next_vector.push_back(ifLabel);
  stop_vector.push_back(endLabel);
  _pf.LABEL(ifLabel);
  node->condition()->accept(this, lvl);
  _pf.JZ(endLabel);
  node->block()->accept(this, lvl + 2);
  _pf.JMP(ifLabel);
  _pf.LABEL(endLabel);

  next_vector.pop_back();
  stop_vector.pop_back();
}

//---------------------------------------------------------------------------

void xpl::postfix_writer::do_stop_node(xpl::stop_node * const node, int lvl) {
  if(stop_vector.size() == 0) throw std::string("Error, there aren't more lables in this context");

    std::string lblJmp = stop_vector.back();
    _pf.JMP(lblJmp);
}

void xpl::postfix_writer::do_not_node(cdk::not_node * const node, int lvl) {}

void xpl::postfix_writer::do_double_node(cdk::double_node * const node, int lvl) {
    int lbl1;

  /* generate the string */
  _pf.RODATA(); // strings are DATA readonly
  _pf.ALIGN(); // make sure we are aligned
  _pf.LABEL(mklbl(lbl1 = ++_lbl)); // give the string a name
  _pf.DOUBLE(node->value()); // output string characters

  /* leave the address on the stack */
  _pf.TEXT(); // return to the TEXT segment
  _pf.ADDR(mklbl(lbl1)); // the string to be printed
}


void xpl::postfix_writer::do_and_node(cdk::and_node * const node, int lvl) {
  ASSERT_SAFE_EXPRESSIONS;
  node->left()->accept(this, lvl);
  _pf.JZ("firstFalse");
  node->right()->accept(this, lvl);
  _pf.AND();
  _pf.LABEL("firstFalse");
}

void xpl::postfix_writer::do_or_node(cdk::or_node * const node, int lvl) {
  ASSERT_SAFE_EXPRESSIONS;
  node->left()->accept(this, lvl);
  _pf.JNZ("firstTrue");
  node->right()->accept(this, lvl);
  _pf.AND();
  _pf.LABEL("firstTrue");
}

//---------------------------------------------------------------------------

void xpl::postfix_writer::do_next_node(xpl::next_node * const node, int lvl) {
    if(next_vector.size() == 0) throw std::string("Error, there aren't more lables in this context");

    std::string lblJmp = next_vector.back();
    _pf.JMP(lblJmp);
}

//---------------------------------------------------------------------------

void xpl::postfix_writer::do_return_node(xpl::return_node * const node, int lvl) {
}

//---------------------------------------------------------------------------

void xpl::postfix_writer::do_sweep_up_node(xpl::sweep_up_node * const node, int lvl) {
  ASSERT_SAFE_EXPRESSIONS;

  int lbl1;

  std::string sweepCond = mklbl(lbl1 = ++_lbl);
  std::string sweepFim = mklbl(lbl1 = ++_lbl);
  std::string sweepStep = mklbl(lbl1 = ++_lbl);

  next_vector.push_back(sweepStep);
  stop_vector.push_back(sweepFim);

  /*inicializar o lft=val */
  _pf.TEXT();
  _pf.ALIGN();
  node->value()->accept(this, lvl);
  _pf.DUP();
  node->left()->accept(this, lvl);
  _pf.STORE();
  _pf.TRASH(4);

  /*label sweepCond*/
  _pf.ALIGN();
  _pf.LABEL(sweepCond);
  node->left()->accept(this, lvl);
  _pf.LOAD();
  node->finish()->accept(this, lvl);
  _pf.LE();
  _pf.JZ(sweepFim);
  node->instruction()->accept(this, lvl);

  /*label sweepStep*/
  _pf.ALIGN();
  _pf.LABEL(sweepStep);
  node->left()->accept(this, lvl);
  _pf.LOAD();
  node->step()->accept(this,lvl);
  _pf.ADD();
  _pf.DUP();
  node->left()->accept(this, lvl);
  _pf.STORE();
  _pf.TRASH(4);
  _pf.JMP(sweepCond);

  /*label sweepFim */
  _pf.ALIGN();
  _pf.LABEL(sweepFim);

  next_vector.pop_back();
  stop_vector.pop_back();
}
//---------------------------------------------------------------------------

void xpl::postfix_writer::do_sweep_down_node(xpl::sweep_down_node * const node, int lvl) {
  ASSERT_SAFE_EXPRESSIONS;

  int lbl1;

  std::string sweepCond = mklbl(lbl1 = ++_lbl);
  std::string sweepFim = mklbl(lbl1 = ++_lbl);
  std::string sweepStep = mklbl(lbl1 = ++_lbl);

  next_vector.push_back(sweepStep);
  stop_vector.push_back(sweepFim);

  /*inicializar o lft=val */
  _pf.TEXT();
  _pf.ALIGN();
  node->value()->accept(this, lvl);
  _pf.DUP();
  node->left()->accept(this, lvl);
  _pf.STORE();
  _pf.TRASH(4);

  /*label sweepCond*/
  _pf.ALIGN();
  _pf.LABEL(sweepCond);
  node->left()->accept(this, lvl);
  _pf.LOAD();
  node->finish()->accept(this, lvl);
  _pf.GE();
  _pf.JZ(sweepFim);
  node->instruction()->accept(this, lvl);

  /*label sweepStep*/
  _pf.ALIGN();
  _pf.LABEL(sweepStep);
  node->left()->accept(this, lvl);
  _pf.LOAD();
  node->step()->accept(this,lvl);
  _pf.SUB();
  _pf.DUP();
  node->left()->accept(this, lvl);
  _pf.STORE();
  _pf.TRASH(4);
  _pf.JMP(sweepCond);

  /*label sweepFim */
  _pf.ALIGN();
  _pf.LABEL(sweepFim);

  next_vector.pop_back();
  stop_vector.pop_back();
}


//---------------------------------------------------------------------------

void xpl::postfix_writer::do_block_node(xpl::block_node * const node, int lvl) {
    _symtab.push();
    if(node->declaration() != NULL) {
        node->declaration()->accept(this, lvl+2);
    }
    if(node->instruction() != NULL) {
        node->instruction()->accept(this,lvl + 2);
    }
    _symtab.pop();
}

//---------------------------------------------------------------------------

void xpl::postfix_writer::do_index_node(xpl::index_node * const node, int lvl) {
}

//---------------------------------------------------------------------------

void xpl::postfix_writer::do_null_node(xpl::null_node * const node, int lvl) {
}

//---------------------------------------------------------------------------

void xpl::postfix_writer::do_address_node(xpl::address_node * const node, int lvl) {
}

//---------------------------------------------------------------------------

void xpl::postfix_writer::do_allocation_node(xpl::allocation_node * const node, int lvl) {
}

//---------------------------------------------------------------------------

void xpl::postfix_writer::do_function_declaration_node(xpl::function_declaration_node * const node, int lvl) {
  ASSERT_SAFE_EXPRESSIONS;
  //BUSCAR FUNCAO EXTERNA
  if(node->use()){
    std::string functionName = node->name();
    //_pf.EXTERN(functionName);
    use_vector.push_back(functionName);
  }
  /*
  if(node->parameters() != NULL) node->parameters()->accept(this, lvl);
  */
}

//---------------------------------------------------------------------------

void xpl::postfix_writer::do_function_call_node(xpl::function_call_node * const node, int lvl) {

  xpl::stack_visitor sv(_compiler);
  node->accept(&sv, lvl);

  if(!_symtab.find(node->name())) throw std::string("Function doesn't exists");
  
  if(node->args() != NULL)
    node->args()->accept(this, lvl);

  _pf.CALL(node->name());
  _pf.TRASH(sv.size());
  _pf.PUSH();



}

//---------------------------------------------------------------------------
/*
void xpl::postfix_writer::do_function_definition_node(xpl::function_definition_node * const node, int lvl) {
} */

//---------------------------------------------------------------------------

void xpl::postfix_writer::do_variable_node(xpl::variable_node * const node, int lvl) {
    
    ASSERT_SAFE_EXPRESSIONS;

    if(node->functionArg())//variavel argumento de uma funcao*/
    {    
        std::string id = node->name();
        if(!_symtab.find(id)){
          std::shared_ptr<xpl::symbol>symbol = std::make_shared<xpl::symbol>(node->type(), id, arg_offset);
          _symtab.insert(id, symbol);

          arg_offset += node->type()->size();
        }
      return;
    }
    if(global_flag){

      std::string id = node->name();
      std::shared_ptr<xpl::symbol>symbol = std::make_shared<xpl::symbol>(node->type(), id, 0);
      _symtab.insert(id, symbol);

      (node->initializer() == NULL ) ? _pf.BSS() : _pf.DATA();
      
      _pf.ALIGN();
      
      if(node->publicc() == true ) {
          _pf.GLOBAL(node->name(), _pf.OBJ());
      }
      else { } /*NAO PUBLICC*/
      
      _pf.LABEL(node->name());
      
      if(!node->initializer())
          (node->type()->name() == basic_type::TYPE_DOUBLE) ? _pf.BYTE(8) : _pf.BYTE(4);
      
      else
          node->initializer()->accept(this, lvl);
    }
    else{ /*NAO E GLOBAL*/
      

      local_offset -= node->type()->size();
      std::string id = node->name();
      std::shared_ptr<xpl::symbol>symbol = std::make_shared<xpl::symbol>(node->type(), id, local_offset);
      _symtab.insert(id, symbol);

       if(node->initializer() != NULL){
         node->initializer()->accept(this, lvl);
         _pf.LOCAL(local_offset);
         _pf.STORE();
       }
    }
} 
    







//---------------------------------------------------------------------------

void xpl::postfix_writer::do_positive_node(xpl::positive_node * const node, int lvl) {
  ASSERT_SAFE_EXPRESSIONS;
  node->argument()->accept(this, lvl); // determine the value
}


//---------------------------------------------------------------------------

void xpl::postfix_writer::do_if_node(xpl::if_node * const node, int lvl) {
  ASSERT_SAFE_EXPRESSIONS;
  int lbl1;
  node->condition()->accept(this, lvl);
  _pf.JZ(mklbl(lbl1 = ++_lbl));
  node->block()->accept(this, lvl + 2);
  _pf.LABEL(mklbl(lbl1));
}

//---------------------------------------------------------------------------

void xpl::postfix_writer::do_if_else_node(xpl::if_else_node * const node, int lvl) {
  ASSERT_SAFE_EXPRESSIONS;
  int lbl1, lbl2;
  node->condition()->accept(this, lvl);
  _pf.JZ(mklbl(lbl1 = ++_lbl));
  node->thenblock()->accept(this, lvl + 2);
  _pf.JMP(mklbl(lbl2 = ++_lbl));
  _pf.LABEL(mklbl(lbl1));
  node->elseblock()->accept(this, lvl + 2);
  _pf.LABEL(mklbl(lbl1 = lbl2));
}
