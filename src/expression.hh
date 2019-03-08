#ifndef EXPRESSION_HH
#define EXPRESSION_HH
#include "symbol.hh"
#include "value.hh"
#include "functional.hh"
#include "qml.hh"

extern list<XmlTag*> steps;

/**
 * Experssion class
 */
class Expression : public Symbol
{
public:
  virtual operator bool(){
    if(this->isBoolean())
      return *value;
    throw Exception("Unable convert expression to boolean");
  }
  virtual operator int(){
    if(this->isInteger()) 
      return *value;
    throw Exception("Unable convert expression to int");
  }
  virtual operator double(){
    if(this->isReal()) 
      return *value;
    throw Exception("Unable convert expression to real");
  }
  virtual operator complex<double>(){
    if(this->isComplex())
      return value->getcomplex();
    throw Exception("Unable convert expression to complex");
  }

  virtual string asString(){
    this->pass();
    assert(value);
    return value->asString();
  }
  virtual Value & getValue(){
    assert(value);
    return *value;
  }
  Value *getRightValue(SymbolType , Value * );
  virtual ~Expression(){
    delete value;
  }
protected:
  Expression(SymbolType st):Symbol(st),value(0){}
  Value *value;
};



/** 
 *  Identifier class
 */
class Identifier
  :public StackElement, 
   public Expression
{
public:
  Identifier(const char *n):Expression(IDENTIFIER){
    StackElement::name = n;
  }
  virtual ~Identifier(){}
  virtual void static_control();
  virtual void pass();
  virtual void setValue(Value &v){ 
    delete value;
    value=&v; 
  }
  virtual void setValue(Value *v){
    delete value;
    value = v;
  }
  virtual string &getName(){return name;}
  virtual void setConst(){ constant = true;}
protected:
  Identifier(SymbolType st):Expression(st){
    constant = false;
  }
  bool constant;
};




/** 
 *  Constant class
 */
class Constant: public Expression{
public:
  Constant(Value *v):Expression(CONST){
    value = v;
  }
  virtual operator bool(){
	assert(value);
	return (bool)*value;
  }
  virtual operator int(){
	assert(value);
	return (int)*value;
  }
  virtual operator double(){
	assert(value);
	return (double)*value;
  }
  virtual operator complex<double>(){
	assert(value);
	return (complex<double>)*value;
  }
  
  virtual void static_control();
  virtual void pass();
};

/** 
 * IdExpression class (r-value)
 */
class IdExpression: public Expression{
protected:
  Identifier *id;
public:
  IdExpression(Identifier *i):Expression(VARIABLE),id(i){}
  
  virtual void static_control();
  virtual void pass();
  virtual bool isLogic(){ return value->isLogic();  }
  virtual const string & getName(){ return id->getName(); }
  ~IdExpression(){
    //    delete id;
  }
};


/// IdQExpression class
/// quantum identifier class
class IdQExpression:public IdExpression{
protected:
  Expression *lexpr;
  Expression *rexpr;
  RegRangeType rrtype;
public:
  IdQExpression(Identifier *i,Expression *e1,Expression *e2=0,RegRangeType r=NORANGE)
    :IdExpression(i),lexpr(e1),rexpr(e2),rrtype(r){}
  virtual void static_control();
  virtual void pass();
  ~IdQExpression(){
    delete lexpr;
    delete rexpr;
  }
};


class Def; //  Def forward-declaration 

/** 
 * Routine class
 */
class Routine: public StackElement{
protected:
  Def * args;
  Symbol *body;
  
  
public:
  Routine(Identifier *i,Def *a,Symbol *b):args(a),body(b){
    StackElement::name = i->getName();
  }
  Def * getArgs(){ return args; }
  Symbol * getBody(){ 
    //std::cout << body << std::endl;
    return body;
  }
  virtual SymbolType getRetType(){ 
    throw Exception("Routine does not return value.");
  }

  
  virtual void set_args(Expression*);
  virtual void check_args(Expression *);
  virtual ~Routine();
};

/*
  pointer to routine class
 */
template<typename T>
class ptr{
  T *p; 
public:
  ptr(T*_p):p(_p){}
  ptr(const ptr<T> & t):p(t.p){}
  ~ptr(){
    assert(p);
    delete p;
  }
  bool operator==(T* _p){ 
    return *p == *_p; 
  }
  bool operator==(const string & s){ 
    assert(p);
    return (*p) == s; 
  }
  T & operator*(){return *p;}
};

typedef list<ptr<Routine> > SUBROUTINES_COLLECTION;

/** 
 * Function class
 */
class Function:public Routine, public Expression{
protected:
  SymbolType rettype;
public:
  Function( SymbolType ft, Identifier *i,Def * ar, Symbol *bdy)
    :Routine(i,ar,bdy),Expression(FUNCTION){ 
      rettype = ft; 
    }
  virtual SymbolType getRetType(){ 
    return rettype;
  } 

  virtual void static_control();
  virtual void pass();
  virtual ~Function(){
    
  }
};


/** 
 * FunctCall class
 */
class FunctCall:public Expression{
protected:
  Identifier *id;
  Expression * args;
public:
  FunctCall(Identifier *i,Expression *a):Expression(FUNCTION),id(i),args(a){}
  virtual void static_control();
  virtual void pass();
  bool build_in_check();
  ~FunctCall(){
    delete args;
    delete id;
  }
};

/** 
 * RegSizeExpression class
 */
class RegSizeExpression:public Expression{
public:
  RegSizeExpression(Expression *e):Expression(REGSIZE){}
  virtual void static_control();
  virtual void pass();
};

/** 
 * PowExpression class
 */
class PowExpression:public Expression{
public:
  PowExpression(Expression *e1,Expression *e2):Expression(POWER){}
  virtual void static_control();
  virtual void pass();
};

/** 
 * NegExpression class
 */
class NegExpression:public Expression{
public:
  NegExpression(Expression *e):Expression(NOT){}
  virtual void static_control();
  virtual void pass();
};

/** 
 * MultExpression class
 */
class MultExpression:public Expression{
protected:
  Expression *l,*r;
public:
  MultExpression(Expression *e1,Expression *e2):Expression(MULTIPLICATION),l(e1),r(e2){}
  virtual void static_control();
  virtual void pass();

};

/** 
 * DivExpression class
 */
class DivExpression:public Expression{
protected:
  Expression *l,*r;
public:
  DivExpression(Expression *e1,Expression *e2):Expression(DIVISION),l(e1),r(e2){}
  virtual void static_control();
  virtual void pass();
  ~DivExpression(){
    delete l;
    delete r;
  }
};

/** 
 * ModExpression class
 */
class ModExpression:public Expression{
public:
  ModExpression(Expression *e1,Expression *e2):Expression(MODULUS){}
  virtual void static_control();
  virtual void pass();
};

/** 
 * AddExpression class
 */
class AddExpression:public Expression{
protected:
  Expression *l,*r;
public:
  AddExpression(Expression *e1,Expression *e2):Expression(ADDICTION),l(e1),r(e2){}
  virtual void static_control();
  virtual void pass();
  ~AddExpression(){
    delete l;
    delete r;
  }
};

/** 
 * SubExpression class
 */
class SubExpression:public Expression{
protected:
  Expression *l,*r;
public:
  SubExpression(Expression *e1,Expression *e2):Expression(SUBSTRACTION),l(e1),r(e2){}
  virtual void static_control();
  virtual void pass();
  ~SubExpression(){
    delete l;
    delete r;
  }
};

/** 
 * ConExpression class
 */
class ConExpression:public Expression{
public:
  ConExpression(Expression *e1,Expression *e2):Expression(CONCATENATION){}
  virtual void static_control();
  virtual void pass();

};

/** 
 * IsEqExpression class
 */
class IsEqExpression:public Expression{
protected:
  Expression *l,*r;
public:
  IsEqExpression(Expression *e1,Expression *e2):Expression(EQUAL),l(e1),r(e2){}
  virtual void static_control();
  virtual void pass();
  virtual ~IsEqExpression(){
    delete l;
    delete r;
  }
};

/** 
 * IsNEqExpression class
 */
class IsNEqExpression:public Expression{
protected:
  Expression *l,*r;
public:
  IsNEqExpression(Expression *e1,Expression *e2):Expression(NEQUAL),l(e1),r(e2){}
  virtual void static_control();
  virtual void pass();
  ~IsNEqExpression(){
    delete l;
    delete r;
  }
};

/** 
 * IsLessExpression class
 */
class IsLessExpression:public Expression{
protected:
  Expression *l,*r;
public:
  IsLessExpression(Expression *e1,Expression *e2):Expression(LESS),l(e1),r(e2){}
  virtual void static_control();
  virtual void pass();
  ~IsLessExpression(){
    delete l;
    delete r;
  }
};

/** 
 * IsLessOrEqExpression class
 */
class IsLessOrEqExpression:public Expression{
protected:
  Expression *l,*r;
public:
  IsLessOrEqExpression(Expression *e1,Expression *e2):Expression(LESSOREQ),l(e1),r(e2){}
  virtual void static_control();
  virtual void pass();
  ~IsLessOrEqExpression(){
    delete l;
    delete r;
  }
};

/** 
 * IsGrExpression class
 */
class IsGrExpression:public Expression{
protected:
  Expression *l,*r;
public:
  IsGrExpression(Expression *e1,Expression *e2):Expression(GREATER),l(e1),r(e2){}
  virtual void static_control();
  virtual void pass();
  ~IsGrExpression(){
    delete l;
    delete r;
  }
};

/** 
 * IsGrOrEqExpression class
 */
class IsGrOrEqExpression:public Expression{
protected:
  Expression *l,*r;
public:
  IsGrOrEqExpression(Expression *e1,Expression *e2):Expression(GREATEROREQ),l(e1),r(e2){}
  virtual void static_control();
  virtual void pass();
  ~IsGrOrEqExpression(){
    delete l;
    delete r;
  }
};

/** 
 * NotExpression class
 */
class NotExpression:public Expression{
  Expression *r;
public:
  NotExpression(Expression *e):Expression(NOT),r(e){}
  virtual void static_control();
  virtual void pass();
  ~NotExpression(){
    delete r;
  }
};

/**
 *  AndExpression class
 */
class AndExpression: public Expression{
  Expression *l , *r;
public:
  AndExpression(Expression *e1, Expression *e2):Expression(AND),l(e1),r(e2){ }
  virtual void pass();
  virtual void static_control();
  ~AndExpression(){
    delete l;
    delete r;
  }
};

/** 
 * OrExpression class
 */
class OrExpression:public Expression{
  Expression *l , *r;
public:
  OrExpression(Expression *e1,Expression *e2):Expression(OR),l(e1),r(e2){}
  virtual void static_control();
  virtual void pass();
  ~OrExpression(){
    delete l;
    delete r;
  }
};

/** 
 * XorExpression class
 */
class XorExpression:public Expression{
  Expression *l , *r;
public:
  XorExpression(Expression *e1,Expression *e2):Expression(XOR),l(e1),r(e2){}
  virtual void static_control();
  virtual void pass();
  ~XorExpression(){
    delete l;
    delete r;
  }
};

#endif
