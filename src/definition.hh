
#ifndef DEFINITION_HH
#define DEFINITION_HH

#include "symbol.hh"
#include "expression.hh"
#include "statement.hh"

/**
 * Def class
 */
class Def:public Symbol{
protected:
  Identifier *id;
  SymbolType stype;
  //  union{
  Expression *expr;
  Def * def;
  //};
public:
  Def(Identifier *i,SymbolType st,Expression *e=0)
    :Symbol(DEFINITION),id(i),stype(st),expr(e),def(0){}
  Def(Identifier *i,SymbolType st, Def * d)
    :Symbol(DEFINITION),id(i),stype(st),expr(0),def(d){}
  virtual void static_control();
  virtual void pass();
  Identifier * getId(){return id;}
  Expression * getExpr(){ return expr;}
  Def * getDef(){ return def; }
  virtual ~Def(){
    delete id;
    delete expr;
    delete def;
  }
};



/** 
 * ProcDef class
 */
class ProcDef:public Def{
protected:
  Symbol *body;
public:
  ProcDef(Identifier *i,Def *d,Symbol*b):Def(i,UNKNOWNTYPE,d),body(b){
    Symbol::type = PROCEDURE;
  }
  virtual void static_control();
  virtual void pass();
  ~ProcDef(){
    delete body;
  }
};

/** 
 * FunctDef class
 */
class FunctDef:public ProcDef{
public:
  FunctDef(Identifier *i, SymbolType ft, Def *d, Symbol *b):ProcDef(i,d,b){
    Symbol::type = FUNCTION;
    Def::stype = ft;
    
  }
  virtual void static_control();
  virtual void pass();
};

/** 
 * Defq class
 */
class Defq:public Def{
public:
  Defq(Identifier *i,SymbolType st,Expression *e)
    :Def(i,st,e){}
  Defq(Identifier *i,SymbolType st,Def *d)
    :Def(i,st,d){}
  virtual void static_control(){}
  virtual void pass();
  ~Defq(){}
};

/** 
 * OperDef class
 */
class OperDef:public Defq{
protected:
  Symbol *body;
public:
  OperDef(Identifier *i,Def *d, Symbol *b):Defq(i,OPERATOR,d),body(b){}
  virtual void static_control(){}
  virtual void pass();

};

/** 
 * QufuncDef class
 */
class QufuncDef:public Defq{
protected:
  Symbol *body;
public:
  QufuncDef(Identifier *i,Def *d, Symbol *b):Defq(i,QUFUNCTION,d),body(b){}
  virtual void static_control(){}
  virtual void pass(){}

};

/** 
 * ExOperDef class
 */
class ExOperDef:public Defq{
public:
  ExOperDef(Identifier *i, Def *d):Defq(i,EXTERNOPERATOR,d){}
  virtual void static_control(){}
  virtual void pass(){}

};

/** 
 * ExQufuncDef class
 */
class ExQufuncDef:public Defq{
public:
  ExQufuncDef(Identifier *i, Def *d):Defq(i,EXTERNQUFUNCTION,d){}
  virtual void static_control(){}
  virtual void pass(){}

};


#endif
