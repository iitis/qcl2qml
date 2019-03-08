#ifndef SYMBOL_HH
#define SYMBOL_HH

#include "defs.hh"

#include <cassert>
#include <string>

using namespace std;
extern int qcllineno;
extern string srcname;
/**
 * QclObject class
 */
class QclObject{
public:  
  /// check if procedure
  virtual bool isProcedure(){ return type == PROCEDURE; }  
  /// check if operator
  virtual bool isOperator(){ return type == OPERATOR;}
  /// check if function
  virtual bool isFunction(){ return type == FUNCTION; }
  /// check if quantum function
  virtual bool isQuFunction(){ return type == QUFUNCTION; }
  /// check if extern operator
  virtual bool isExternOperator(){ return type == EXTERNOPERATOR; }
  /// check if extern quantum function
  virtual bool isExternQuFunction(){ return type == EXTERNQUFUNCTION; }
  /// check if object can be called
  virtual bool isCallable(){ return (type>=PROCEDURE) && (type<=EXTERNQUFUNCTION); }
  /// check if variable
  virtual bool isVariable(){ return type == VARIABLE; }
  /// check if boolean
  virtual bool isBoolean(){ return type == BOOLEAN; }
  /// check if logic
  virtual bool isLogic(){ return type == BOOLEAN; }
  /// check if integer
  virtual bool isInteger(){ return type == INTEGER; }
  /// check if real
  virtual bool isReal(){ return type == REAL; }
  /// check if complex
  virtual bool isComplex(){ return type == COMPLEX; }
  /// check if number
  virtual bool isNumber(){ return (type >=INTEGER) && (type <=COMPLEX); }
  /// check if string
  virtual bool isString(){ return type == STRING; }
  /// check if quantum register
  virtual bool isQureg(){ return type == QUREG; }
  /// check if void quantum object
  virtual bool isQuvoid(){ return type ==  QUVOID; }
  /// check if constant quantum
  virtual bool isQuconst(){ return type == QUCONST; }
  /// check if quantum scratch
  virtual bool isQuscratch(){ return type == QUSCRATCH; }
  /// check if general quantum object
  virtual bool isQuantum(){ return (type >=QUREG) && (type <=QUSCRATCH); }
  /// get line number in source
  const int & lineno(){ return line; }
  /// get source file name
  const string & srcname(){ return src; }
  /// check if object is given type
  bool isType(SymbolType st){ return st==type;}
  /// get object type
  const SymbolType & getType(){ return type;}
  /// destructor
  virtual ~QclObject(){}
protected:
  /// constructor
  QclObject(SymbolType st):type(st){
    line = qcllineno;
    src=::srcname;
  }
  /// symbol type
  SymbolType type;
  /// source line number
  int line;
  /// source file name
  string src;
};

/// error report macro
#define ERROR(msg) cout<< this->srcname()<< ':' << this->lineno() << ": error:" << msg << endl;
/// warning report macro 
#define WARNING(msg) cout<< this->srcname()<< ':' << this->lineno() << ": warning:" << msg << endl;


/**
 * Symol class
 */
class Symbol:public QclObject{
protected:
  Symbol * next;
  Symbol(SymbolType st):QclObject(st),next(0){}
public:
  /// add next symbol in symbol list
  void addNext(Symbol * n);
  /// get next symbol
  Symbol * getNext(){ return next; }
  /// do static control for all symbols in list
  void checkAll();
  /// do pass for all symbols in list
  void passAll();
  /// static control pure virtual function
  virtual void static_control() = 0;
  /// pass pure virtual functioin
  virtual void pass() = 0;
  /// class destructor
  virtual ~Symbol(){
    delete next;
  }
};




/**
 * Error class
 */
class Error: public Symbol
{
protected:
  /// error counter (static)
  static int noerrors;
public:
  Error():Symbol(ERROR){
    QclObject::line = ::qcllineno;
    noerrors++;
  }
  virtual ~Error(){}

  Error(string &s):Symbol(ERROR){
    src = s;
    QclObject::line = ::qcllineno;
    noerrors++;
  }
  static int nErrors(){ return noerrors; }
  virtual  void static_control(){
  }
  virtual void pass(){
  }

};




#endif
