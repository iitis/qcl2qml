#ifndef STATEMENT_HH
#define STATEMENT_HH

#include "defs.hh"
#include "symbol.hh"
#include "expression.hh"
#include "functional.hh"

#include <cassert>


using namespace std;

extern Stack<Identifier> stack;
//extern Stack<Routine> subroutines;
extern list<ptr<Routine> > subroutines;

/** 
 * Stmt class -  statement abstract class.
 */
class Stmt:public Symbol{
protected:
  /// class constructor
  Stmt(SymbolType st):Symbol(st){}
};

/** 
 * Procedure class
 */
class Procedure :public Routine,
		 public Stmt
{
public:
  Procedure(Identifier *i,Def *ar,Symbol *bdy);
  virtual void static_control();
  virtual void pass();
};

/** 
 * Operator class
 */
class Operator: public Routine,
		public Stmt
{
public:
  Operator(Identifier *i, Def *ar,Symbol *bdy);
  virtual void static_control();
  virtual void pass();
};


/** 
 * Routine Call class
 */
class RoutineCall: public Stmt{
protected:
  Identifier *id;
  Expression *args;
  bool rev;
public:
  RoutineCall(Identifier *i, Expression *e,bool r = false):Stmt(UNKNOWNTYPE),id(i),args(e),rev(r){ }
  virtual void static_control();
  virtual void pass();
  bool build_in_check();
};

/** 
 * VarAssig class
 */
class VarAssig:public Stmt{
protected:
  Identifier *id;
  Expression *expr;
public:
  VarAssig(Identifier *i,Expression *e):Stmt(ASSIGNMENT),id(i),expr(e){}
  virtual void static_control();
  virtual void pass();
  static void assign(Identifier *, Expression *);
  void pass_no_expr_pass();
  virtual ~VarAssig(){
    delete id;
    delete expr;
  }
};

/** 
 * FanoutOperator class
 */
class FanoutOperator: public Stmt{
protected:
  Expression *lexpr,*rexpr;
public:
  FanoutOperator(Expression *l, Expression *r):Stmt(SFANOUT),lexpr(l),rexpr(r){}
  virtual void static_control();
  virtual void pass();
  virtual ~FanoutOperator(){
    delete lexpr;
    delete rexpr;
  }
};

/** 
 * SwapOperator class
 */
class SwapOperator:public Stmt{
protected:
  Expression *lexpr,*rexpr;
public:
  SwapOperator(Expression *l, Expression *r):Stmt(SSWAP),lexpr(l),rexpr(r){}
  virtual void static_control();
  virtual void pass();
  virtual ~SwapOperator(){
    delete lexpr;
    delete rexpr;
  }
};


/** 
 * ForStmt class
 */
class ForStmt:public Stmt{
protected:
  Identifier *id;
  Expression *efrom,*eto,*estep;
  Symbol *body;
public:
  ForStmt(Identifier *i, Expression *ef, Expression *et, Symbol *b, Expression *stp=0)
    :Stmt(FOR),id(i),efrom(ef),eto(et),estep(stp),body(b){}
  ~ForStmt(){
    delete body;
    delete estep;
    delete eto;
    delete efrom;
    delete id;
  }
  virtual void static_control();
  virtual void pass();

};

/** 
 * WhileStmt class
 */
class WhileStmt:public Stmt{
protected:
  Expression *expr;
  Symbol *body;
public:
  WhileStmt(Expression *e,Symbol * b=0):Stmt(WHILE),expr(e),body(b){}
  virtual void static_control();
  virtual void pass();
};

/** 
 * UntilStmt class
 */
class UntilStmt:public Stmt{
protected:
  Expression *expr;
  Symbol *body;
public:
  UntilStmt(Expression *e,Symbol * b=0):Stmt(WHILE),expr(e),body(b){}
  virtual void static_control();
  virtual void pass();
};

/** 
 * IfStmt class
 */
class IfStmt:public Stmt{
protected:
  Expression *expr;
  Symbol *tblock;
  Symbol *fblock;
public:
  IfStmt(Expression *e, Symbol *t, Symbol *f=0):Stmt(IFELSE),expr(e),tblock(t),fblock(f){}
  virtual void static_control();
  virtual void pass();

};

/** 
 * ReturnStmt class
 */
class ReturnStmt: public Stmt{
protected:
  Expression *expr;
public:
  ReturnStmt(Expression *e):Stmt(RETURN),expr(e){}
  virtual void static_control();
  virtual void pass();
};

/** 
 * Input class
 */
class Input:public Stmt{
protected:
  Identifier *id;
  Expression *expr;
public:
  Input(Identifier *i,Expression *e=0):Stmt(INPUT),id(i),expr(e){}
  virtual void static_control();
  virtual void pass();
};

/** 
 * PrintStmt class
 */
class PrintStmt:public Stmt{
protected:
  Expression * expr;
public:
  PrintStmt(Expression *e):Stmt(PRINT),expr(e){}
  virtual void static_control();
  virtual void pass();
};

/** 
 * Exit class
 */
class Exit:public Stmt{
protected:
  Expression * expr;
public:
  Exit(Expression *e=0):Stmt(EXIT),expr(e){}
  virtual void static_control();
  virtual void pass();
};

/** 
 * Measure class
 */
class Measure:public Stmt{
protected:
  Expression *expr;
  Identifier *id;
public:
  Measure(Expression *e,Identifier *i=0):Stmt(MEASURE),expr(e),id(i){}
  virtual void static_control();
  virtual void pass();
};

/** 
 * Reset class
 */
class Reset:public Stmt{
public:
  Reset():Stmt(RESET){}
  virtual void static_control();
  virtual void pass();
};

/** 
 * Dump class
 */
class Dump:public Stmt{
protected:
  Expression *expr;
public:
  Dump(Expression *e=0):Stmt(DUMP),expr(e){}
  virtual void static_control();
  virtual void pass();
};

/** 
 * Load class
 */
class Load:public Stmt{
protected:
  Expression *expr;
public:
  Load(Expression *e=0):Stmt(LOAD){}
  virtual void static_control();
  virtual void pass();
};

/** 
 * Save class
 */
class Save:public Stmt{
protected:
  Expression *expr;
public:
  Save(Expression *e=0):Stmt(SAVE),expr(e){}
  virtual void static_control();
  virtual void pass();
};

/** 
 * Shell class
 */
class Shell
  :public Stmt{
public:
  Shell():Stmt(SHELL){}
  virtual void static_control();
  virtual void pass();
};
/*
class Set:public Stmt{
public:
  Set():Stmt(SET){}
  virtual void static_control();
  virtual void pass();
};

*/
#endif










