#ifndef VALUE_HH
#define VALUE_HH


#include "symbol.hh"
#include "qubit.hh"
#include <string>
#include <complex>
#include <sstream>

using namespace std;

extern QubitManager qubitmanager;

/**
 * Value class
 */
class Value:public QclObject
{
protected:
  Value(SymbolType st):QclObject(st){}
public:
  virtual operator string(){ throw Exception("Invalid cast to string");  }
  virtual operator bool(){ throw Exception("Invalid cast to boolean"); }
  virtual operator int(){ throw Exception("Invalid cast to int");}
  virtual operator double(){ throw Exception("Invalid cast to real");}
  virtual operator char*(){ throw Exception("Invalid cast to string (char*)");}
  virtual complex<double>  getcomplex(){ throw Exception("Invalid cast to complex");}
  virtual void minus(){ throw Exception("Invalid inversion"); }

  virtual Value * clone()=0;

  virtual string asString()=0;
  
};

/**
 * operator<< (ostream&,Value&)
 */
ostream& operator<<(ostream &, Value &);



/** 
 * Boolean class
 */
class Boolean:public Value
{
protected:
  bool value;

public:
  Boolean(bool b=false):Value(BOOLEAN),value(b){}
  virtual operator bool(){    return value;  }
  virtual operator int(){    return value ? 1:0;  }
  virtual string asString(){    return value ? string("true") : string("false");  }
  virtual Value * clone(){ return new Boolean(value); }
};



/** 
 * Integer class
 */
class Integer:public Value
{
protected:
  int value;

public:
  Integer(int i=0):Value(INTEGER),value(i){}

  virtual operator int(){    return value;  }
  virtual operator double(){    return double(value);  }
  virtual complex<double> getcomplex(){ return complex<double>(double(value),0); }
  virtual string asString(){
    stringstream s;
    s << value;
    return s.str();
  }
  virtual void minus(){ value = -value; }
  virtual Value * clone(){ return new Integer(value); }

};

/** 
 * Real class
 */
class Real:public Value
{
protected:
  double value;
public:
  Real(double v=0):Value(REAL),value(v){}
  virtual operator double(){    return value ;  }
  virtual operator int(){ return (int) value; }
  virtual complex<double> getcomplex(){ return complex<double>(value,0);}
  virtual string asString(){
    stringstream s;
    s << value;
    return s.str();
  }
  virtual void minus(){ value = -value; }
  virtual Value * clone(){ return new Real(value); }
};

/** 
 * Complex class
 */
class Complex:public Value
{
protected:
   complex<double> value;
public:
  Complex(double r=0,double i=0):Value(COMPLEX),value(r,i){}
  Complex(const complex<double> & v ):Value(COMPLEX),value(v){}
  Complex(Value *v1,Value *v2):Value(COMPLEX){
    value=complex<double>(*v1,*v2);
  }
  virtual complex<double>  getcomplex(){ return value;}

  virtual string asString(){
    stringstream s;
    s << value;
    return s.str();
  }
  double Re(){ return value.real(); }
  double Im(){ return value.imag(); }
  double abs(){ return std::abs(value); }
  complex<double> conj(){ return std::conj(value); }
  virtual void minus(){ value = -value ; }
  virtual Value * clone(){ return new Complex(value); }
};


/** 
 * String class
 */
class String:public Value
{
protected:
  string value;
public:
  String(string & v):Value(STRING),value(v){}
  String(const char *v= ""):Value(STRING),value(v){}
  virtual ~String(){}
  virtual operator string(){    return value;  }
  virtual string asString(){    return value;  }
  virtual Value * clone(){ return new String(value); }
};

/** 
 * Qureg class
 */
class Qureg:public Value
{
protected:
  int size;
  int quregID;
public:
  Qureg(int s):Value(QUREG),size(s){
    quregID = qubitmanager.qregister(s);
  }
  Qureg():Value(QUREG){
  }
  virtual string asString(){
    string s ="<";
    s+=qubitmanager.toString(quregID);
    s+=">";
    return s;
  }
  int getID(){return quregID; }
  virtual Value * clone(){ return new Qureg(size); }
};


/** 
 * ErrorVal class
 */
class ErrorVal:public Value
{
public:
  ErrorVal():Value(ERROR){
    ERROR("value error.");
  }

  virtual operator bool(){ throw Exception("Invalid value");  }
  virtual operator int(){ throw Exception("Invalid value");  }
  virtual operator double(){ throw Exception("Invalid value");  }
  virtual operator complex<double>(){ throw Exception("Invalid value");  }
  virtual operator string(){ throw Exception("Invalid value");  }
  virtual string asString(){ throw Exception("Invalid value");  }
  virtual Value * clone(){ return new ErrorVal(); }
};







#endif

