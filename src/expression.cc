#include "expression.hh"
#include "definition.hh"
#include "statement.hh"
#include "definition.hh"
#include <cassert>
#include <algorithm>
#include <math.h>

#include <iostream>

using namespace std;


// type conversion for arithmetic operators 
#define ARITHMETIC_OPERATOR(val,l,oper,r)\
  assert(l);\
  assert(r);\
  l->pass();\
  r->pass();\
  SymbolType lt = l->getValue().getType();\
  SymbolType rt = r->getValue().getType();\
  switch(lt){ \
  case INTEGER: \
  switch(rt){ \
    case INTEGER: val = new Integer( (int)l->getValue()  oper (int)r->getValue() ); break; \
    case REAL   : val = new Real((int)l->getValue() oper (double)r->getValue() );break;\
    case COMPLEX: val = new Complex(l->getValue().getcomplex() oper r->getValue().getcomplex());break;\
    default:  ERROR("invalid type"); \
  }\
  break;\
  case REAL: \
  switch(rt){ \
    case INTEGER: val = new Real((double)l->getValue() oper (int)r->getValue()); break; \
    case REAL   : val = new Real((double)l->getValue() oper (double)r->getValue()); break; \
    case COMPLEX: val = new Complex( l->getValue().getcomplex() oper r->getValue().getcomplex()  ); break;\
    default: ERROR("invalid type");\
  }\
  break;\
  case COMPLEX: \
  switch(rt){ \
    case INTEGER: val = new Complex(l->getValue().getcomplex() oper (double)r->getValue());break;\
    case REAL   : val = new Complex(l->getValue().getcomplex() oper (double)r->getValue());break;\
    case COMPLEX: val = new Complex(l->getValue().getcomplex() oper r->getValue().getcomplex());break;\
    default: ERROR("invalid type");\
  }\
  default: ERROR("invalid type");\
  }

#define RELATION_OPERATOR(val, l, oper, r)\
  assert(l && r);\
  l->pass();\
  r->pass();\
  SymbolType lt = l->getValue().getType();\
  SymbolType rt = r->getValue().getType();\
  switch(lt){\
  case INTEGER: \
  switch(rt){ \
    case INTEGER: val = new Boolean((int)l->getValue() oper (int)r->getValue() ); break; \
    case REAL   : val = new Boolean((int)l->getValue() oper (double)r->getValue() );break;\
    default:  ERROR("invalid type"); \
  }\
  break;\
  case REAL: \
  switch(rt){ \
    case INTEGER: val = new Boolean((double)l->getValue() oper (int)r->getValue()); break; \
    case REAL   : val = new Boolean((double)l->getValue() oper (double)r->getValue()); break; \
    default: ERROR("invalid type");\
  }\
  break;\
  default: ERROR("invalid type");\
  }



#define LOGIC_OPERATOR(val, l , oper, r)\
  assert(l && r);\
  l->pass();\
  r->pass();\
  SymbolType lt = l->getValue().getType();\
  SymbolType rt = r->getValue().getType();\
  switch(lt){ \
  case BOOLEAN:\
  switch(rt):\
    case BOOLEAN: val = new Boolean((bool)l->getValue() oper (bool)r->getValue()); break;\
    default: ERROR("invalid type");\
    break;\
  case INTEGER: \
  switch(rt){ \
    case INTEGER: val = new Integer( (int)l->getValue()  oper (int)r->getValue() ); break; \
    case REAL   : val = new Real((int)l->getValue() oper (double)r->getValue() );break;\
    case COMPLEX: val = new Complex(l->getValue().getcomplex() oper r->getValue().getcomplex());break;\
    default:  ERROR("invalid type"); \
  }\
  break;\
  case REAL: \
  switch(rt){ \
    case INTEGER: val = new Real((double)l->getValue() oper (int)r->getValue()); break; \
    case REAL   : val = new Real((double)l->getValue() oper (double)r->getValue()); break; \
    case COMPLEX: val = new Complex( l->getValue().getcomplex() oper r->getValue().getcomplex()  ); break;\
    default: ERROR("invalid type");\
  }\
  break;\
  case COMPLEX: \
  switch(rt){ \
    case INTEGER: val = new Complex(l->getValue().getcomplex() oper (double)r->getValue());break;\
    case REAL   : val = new Complex(l->getValue().getcomplex() oper (double)r->getValue());break;\
    case COMPLEX: val = new Complex(l->getValue().getcomplex() oper r->getValue().getcomplex());break;\
    default: ERROR("invalid type");\
  }\
  default: ERROR("invalid type");\
  }


Value * Expression::getRightValue(SymbolType st,Value *v=0){
  if(v){
    switch(st){
    case BOOLEAN: return new Boolean(*v);
    case INTEGER: return new Integer(*v);
    case REAL   : return new Real(*v);
    case COMPLEX: return new Complex(*v);
    case STRING : return new String(*v);
    default: return new ErrorVal();
    };
  }
  else{
    switch(st){
    case BOOLEAN: return new Boolean();
    case INTEGER: return new Integer();
    case REAL   : return new Real();
    case COMPLEX: return new Complex();
    case STRING : return new String();
    default: return new ErrorVal();
    };
  }
}


void Routine::check_args(Expression *e){
}				      
/**
* Actual arguments initialization
*/
void Routine::set_args(Expression *actl_args){
  Expression * aargs = actl_args;
  while(aargs){
    aargs->pass();
    aargs = dynamic_cast<Expression*>(aargs->getNext());
  }
  stack.push_scope();
  Def *form_arg = args;
  aargs = actl_args;
  while(form_arg){
    form_arg->pass();       // broke here
    if(aargs){
      VarAssig va(form_arg->getId(),aargs);
      va.pass_no_expr_pass() ; ////?????
      aargs = dynamic_cast<Expression*>(aargs->getNext());
      form_arg = dynamic_cast<Def*>(form_arg->getNext());
    }
  }
}

Routine::~Routine(){
  delete args;
  // body deleted by ~ProcDef()
}


void Function::static_control(){}
void Function::pass(){}

void AndExpression::static_control(){}
void AndExpression::pass(){
  delete value;
  l->pass();
  r->pass();
  value = new Boolean(  (bool)(*l) && (bool)(*r));
}

void Constant::static_control(){}
void Constant::pass(){}

void Identifier::static_control(){}
void Identifier::pass(){

}


void IdExpression::static_control(){
}
void IdExpression::pass(){
  assert(id);
  Identifier *i= stack.find(id->getName());
  delete value;
  if(i){
    value = i->getValue().clone();
  }else{
    ERROR("ERROR");
  }

}

void IdQExpression::static_control(){}
void IdQExpression::pass(){}

void FunctCall::static_control(){}

bool FunctCall::build_in_check(){
#define COMPARETO(s) (this->id->getName().compare(s) == 0)
  try{

    if(COMPARETO("random")){
      value = new Real(  ((double)rand())/((double)RAND_MAX));
    }else{
      /// REAL FUNCTIONS
      //if(!args) return false;
      //else 
        args->passAll();
      if(COMPARETO("sin")){
        value = new Real ( ::sin( args->getValue()) );
      }else if(COMPARETO("cos")){
        value = new Real ( ::cos( args->getValue()) );
      }else if(COMPARETO("tan")){
        value = new Real ( ::tan( args->getValue()) );
      }else if(COMPARETO("cot")){
        value = new Real ( 1/::tan( args->getValue()) );
      }else if(COMPARETO("sinh")){
        value = new Real ( ::sinh( args->getValue()) );
      }else if(COMPARETO("cosh")){
        value = new Real ( ::cosh( args->getValue()) );
      }else if(COMPARETO("tanh")){
        value = new Real ( ::tanh( args->getValue()) );
      }else if(COMPARETO("coth")){
        value = new Real ( ::sinh( args->getValue())/::cosh( args->getValue()) );
      }else if(COMPARETO("exp")){
        value = new Real ( ::exp( args->getValue()) );
      }else if(COMPARETO("log")){
        Expression * n = dynamic_cast<Expression *>(args->getNext());
        if(n){
          n->pass();
          value = new Real ( ::log( args->getValue())/::log(n->getValue()));
        }else{
          value = new Real ( ::log( args->getValue()));
        }
      }else if(COMPARETO("sqrt")){
        value = new Real ( ::sqrt( args->getValue()));
      }
      /// COMPLEX functions
      else if(COMPARETO("Re")){
        Complex &v = dynamic_cast<Complex&>(args->getValue());
        value = new Real ( v.Re() );
      }else if(COMPARETO("Im")){
        Complex &v = dynamic_cast<Complex&>(args->getValue());
        value = new Real ( v.Im() );
      }else if(COMPARETO("abs")){
        Complex &v = dynamic_cast<Complex&>(args->getValue());
        value = new Real ( v.abs() );
      }else if(COMPARETO("conj")){
        Complex &v = dynamic_cast<Complex&>(args->getValue());
        value = new Complex ( v.conj() );
      }else if(COMPARETO("Re")){
        Complex &v = dynamic_cast<Complex&>(args->getValue());
        value = new Real ( v.Re() );
      }
      /// ROUNDING 
      else if(COMPARETO("ceil")){
        value = new Integer ( (int)::ceil(args->getValue()) );
      }else if(COMPARETO("floor")){
        value = new Integer ( (int)::floor(args->getValue()) );
      }else if(COMPARETO("max")){
        double max = args->getValue();
        Symbol *s=args->getNext();
        while(s){
          s->pass();
          Expression &e = dynamic_cast<Expression&>(*s);
          if(max < (double)e.getValue())
            max = e.getValue();
          s=args->getNext();          
        }
          value = new Real ( max );
      }else if(COMPARETO("min")){
        double max = args->getValue();
        Symbol *s=args->getNext();
        while(s){
          s->pass();
          Expression &e = dynamic_cast<Expression&>(*s);
          if(max < (double)e.getValue())
            max = e.getValue();
          s=args->getNext();          
        }
          value = new Real ( max );
      }else{
        return false;
      }
      }
      return true;
      }catch(bad_cast){
        ERROR("Invalid arguments");
      }
  return false;
}

    void FunctCall::pass(){
      args->passAll();
      if(build_in_check())
        return;
      SUBROUTINES_COLLECTION::iterator r = find(subroutines.begin(), subroutines.end(), id->getName());
      if( r != subroutines.end()){
        //std::cout << typeid(*f).name() << std::endl;
        (**r).set_args(args);
        if((**r).getBody()) 
          (**r).getBody()->passAll();
        Identifier * retval = stack.find(string("return"));
        if(retval){
          value = getRightValue( (**r).getRetType(),&(retval->getValue()));
        }
        stack.pop_scope();
      }else{
        string s = "Function ";
        s+= id->getName();
        s+=" not defined";
        ERROR(s);
      }

    }


    void RegSizeExpression::static_control(){}
    void RegSizeExpression::pass(){}

    void PowExpression::static_control(){}
    void PowExpression::pass(){}

    void NegExpression::static_control(){}
    void NegExpression::pass(){}

    void MultExpression::static_control(){}
    void MultExpression::pass(){
      delete value;
      ARITHMETIC_OPERATOR(value, l, * , r);
    }

    void DivExpression::static_control(){}
    void DivExpression::pass(){
      delete value;
      ARITHMETIC_OPERATOR(value, l, / , r);
    }

    void ModExpression::static_control(){}
    void ModExpression::pass(){}

    void AddExpression::static_control(){}
    void AddExpression::pass(){
      delete value;
      ARITHMETIC_OPERATOR(value, l, + , r);
    }

    void SubExpression::static_control(){}
    void SubExpression::pass(){
      delete value;
      ARITHMETIC_OPERATOR(value, l, - , r);
    }

    void ConExpression::static_control(){}
    void ConExpression::pass(){}

    void IsEqExpression::static_control(){}
    void IsEqExpression::pass(){
      delete value;
      RELATION_OPERATOR(value,l,==,r);
    }

    void IsNEqExpression::static_control(){}
    void IsNEqExpression::pass(){
      delete value;
      RELATION_OPERATOR(value,l,!=,r);
    }

    void IsLessExpression::static_control(){}
    void IsLessExpression::pass(){
      delete value;
      RELATION_OPERATOR(value,l,<,r);
    }

    void IsLessOrEqExpression::static_control(){}
    void IsLessOrEqExpression::pass(){
      delete value;
      RELATION_OPERATOR(value,l,<=,r);
    }

    void IsGrExpression::static_control(){}
    void IsGrExpression::pass(){
      delete value;
      RELATION_OPERATOR(value,l,>,r);
    }

    void IsGrOrEqExpression::static_control(){}
    void IsGrOrEqExpression::pass(){
      delete value;
      RELATION_OPERATOR(value,l,>=,r);
    }

    void NotExpression::static_control(){}
    void NotExpression::pass(){
      delete value;
      r->pass();
      value = new Boolean(! (bool)(*r));
    }

    void OrExpression::static_control(){}
    void OrExpression::pass(){
      delete value;
      l->pass();
      r->pass();
      value = new Boolean(  (bool)(*l) || (bool)(*r));
    }

    void XorExpression::static_control(){}
    void XorExpression::pass(){
      delete value;
      l->pass();
      r->pass();
      value = new Boolean(  ((bool)(*l) && ! (bool)(*r) )||( !(bool)(*l) && (bool)(*r))  );
    }


