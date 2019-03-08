#ifndef QCL_HH
#define QCL_HH
#include "exception.hh"
#include "qml.hh"
#include "statement.hh"
#include "definition.hh"
#include "qusim.hh"
#include "qubit.hh"
#include <iostream>
#include <string>
using namespace std;

/// namespace of the QCL language objects
namespace qcl{
  /// QCL error counter
  extern int nerrors ;

  /// QCL object types
  typedef enum{UNKNOWNTYPE,ERROR,IDENTIFIER,DEFINITION,
		 PROCEDURE,OPERATOR,FUNCTION,QUFUNCTION,EXTERNOPERATOR,EXTERNQUFUNCTION,
		 VARIABLE,
		 CONST,
		 REGSIZE,
		 POWER,UNARYMINUS,MULTIPLICATION,DIVISION,MODULUS,ADDICTION,SUBSTRACTION,
		 CONCATENATION,
		 EQUAL,NEQUAL,LESS,LESSOREQ,GREATER,GREATEROREQ,NOT,AND,OR,XOR,
		 BOOLEAN,
		 INTEGER,REAL,COMPLEX,
		 STRING,
		 QUREG,QUVOID,QUCONST,QUSCRATCH,
		 ASSIGNMENT,SFANOUT,SSWAP,WHILE,FOR,IFELSE,RETURN,INPUT,PRINT,EXIT,
		 MEASURE,RESET,DUMP,LOAD,SAVE,SHELL
		 } ObjectType;

  /// QCL object class
  /// @brief class for base QCL object elements
  class Object{
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
    /// get object type
    const ObjectType &getType(){ return type; }
    /// class constructor
    /// @param ot - object type
    Object(ObjectType ot)
      :type(ot)
    {
      line = ::qcllineno;
      source=::srcname;
    }
    /// class destructor
    virtual ~Object(){}
    /// error reporting method
    /// @param msg - error message 
    void error(const char *msg)
    {
      cerr << source << ':' << line <<": error:" << msg << endl;
    }
  protected:
    /// type of the QCL object
    ObjectType type;
    /// line number in source
    int line;
    /// source file name
    string source;
  };
  
  /// QCL symbol class
  class Symbol :public Object{
  protected:
    /// pointer to next QCL Symbol element
    Symbol *next;
    ///
    Symbol(ObjectType ot):Object(ot),next(0)
    {}
  public:
    /// add next symbol 
    void addNext(Symbol *s){ next = s; }
    /// get next symbol
    Symbol * getNext(){ return next; }
    /// static control for all symbols in the list
    void checkAll();
    /// interpreter pass over all symbols in the list
    void passAll();
    /// static control method  
    virtual void static_control(){}// ultimatley =0
    /// interpreter pass over symbol
    virtual void pass(){} // ultimatley =0
    /// class destructor
    virtual ~Symbol(){
      delete next;
    }

  };

  /// QCL value abstract class
  class Value :public Object{
  protected:
    /// value class constructor
    /// protected constructor called by class derrivatives
    /// @param ot initial object type
    Value(ObjectType ot):Object(ot){}
  public:
    /// cast value to thestring
    virtual operator string(){ throw Exception("Invalid cast to string");  }
    /// cast value to the boolean
    virtual operator bool(){ throw Exception("Invalid cast to boolean"); }
    /// cast value to the integer
    virtual operator int(){ throw Exception("Invalid cast to int");}
    /// cast value to the double
    virtual operator double(){ throw Exception("Invalid cast to real");}
    /// cast value to the char *
    virtual operator char*(){ throw Exception("Invalid cast to string (char*)");}
    /// cast value to the complex 
    virtual complex<double>  getcomplex(){ throw Exception("Invalid cast to complex");}
    /// inverse the value
    virtual void minus(){ throw Exception("Invalid inversion"); }
    /// clone the value
    virtual Value * clone()=0;
    /// string representation of the value
    virtual string asString()=0;
  };

  /// push value to output stream
  /// @param os output stream
  /// @param the value
  ostream & operator<<(ostream &os, Value &v);


  /// Boolean value
  class Boolean:public Value
  {
  protected:
    /// boolean value
    bool value;
  public:
    /// class constructor
    /// @param b initial value
    Boolean(bool b=false):Value(BOOLEAN),value(b){}
    /// cast to bool
    virtual operator bool(){    return value;  }
    /// cast to int
    virtual operator int(){    return value ? 1:0;  }
    /// boolean value as string
    virtual string asString(){    return value ? string("true") : string("false");  }
    /// clone the value
    virtual Value * clone(){ return new Boolean(value); }
  };

  /// QCL integer class
  /// class for QCL integer type
  class Integer:public Value
  {
  protected:
    /// integer value
    int value;
  public:
    /// class constructor
    /// @param i initial value 
    Integer(int i=0):Value(INTEGER),value(i){}
    /// cast to int
    virtual operator int(){    return value;  }
    /// cast to double
    virtual operator double(){    return double(value);  }
    /// cast to complex
    virtual complex<double> getcomplex(){ return complex<double>(double(value),0); }
    /// string representation
    virtual string asString(){
      stringstream s;
      s << value;
      return s.str();
    }
    /// value inversion
    virtual void minus(){ value = -value; }
    /// clone the value
    virtual Value * clone(){ return new Integer(value); }
  };

  /// QCL real value class
  class Real:public Value
  {
  protected:
    /// value
    double value;
  public:
    /// constructor
    /// @param v initial value
    Real(double v=0):Value(REAL),value(v){}
    /// cast to dobule
    virtual operator double(){    return value ;  }
    /// cast to int
    virtual operator int(){ return (int) value; }
    /// cast to complex
    virtual complex<double> getcomplex(){ return complex<double>(value,0);}
    /// double value string representation
    virtual string asString(){
      stringstream s;
      s << value;
      return s.str();
    }
    /// value inversion
    virtual void minus(){ value = -value; }
    /// clone the value
    virtual Value * clone(){ return new Real(value); }
  };


  /// Complex class
  class Complex:public Value
  {
  protected:
    /// value
    complex<double> value;
  public:
    /// constructor
    /// @param r real initial value
    /// @param i imag. initial value
    Complex(double r=0,double i=0):Value(COMPLEX),value(r,i){}
    /// class constructor
    /// @param v initial value
    Complex(const complex<double> & v ):Value(COMPLEX),value(v){}
    /// class constructor
    /// @param v1 real value
    /// @param v2 imag. value
    Complex(Value *v1,Value *v2):Value(COMPLEX){
      value=complex<double>(*v1,*v2);
    }
    /// get complex value
    virtual complex<double>  getcomplex(){ return value;}
    /// string representation
    virtual string asString(){
      stringstream s;
      s << value;
      return s.str();
    }
    /// get real part
    double Re(){ return value.real(); }
    /// get imag. part
    double Im(){ return value.imag(); }
    /// get value modulus
    double abs(){ return std::abs(value); }
    /// get conjugate value
    complex<double> conj(){ return std::conj(value); }
    /// inverse value
    virtual void minus(){ value = -value ; }
    /// clone the value
    virtual Value * clone(){ return new Complex(value); }
  };


  /// QCL String value
  class String:public Value
  {
  protected:
    /// value
    string value;
  public:
    /// constructor
    /// @param v initial value
    String(string & v):Value(STRING),value(v){}
    /// constructor
    /// @param v initial string
    String(const char *v= ""):Value(STRING),value(v){}
    /// class destructor
    virtual ~String(){}
    /// std::string cast
    virtual operator string(){    return value;  }
    /// string representation
    virtual string asString(){    return value;  }
    /// clone the class
    virtual Value * clone(){ return new String(value); }
  };
  
  /// QCL quantum register class
  class Qureg:public Value
  {
  protected:
    /// qureg size
    int size;
    /// qureg identifier
    int quregID;
  public:
    /// class constructor
    Qureg(int s):Value(QUREG),size(s){
      quregID = qubitmanager.qregister(s);
    }
    /// class constructor
    ///    Qureg():Value(QUREG){ }

    /// quantum register string picture
    virtual string asString(){
      string s ="<";
      s+=qubitmanager.toString(quregID);
      s+=">";
      return s;
    }
    /// get register id
    int getID(){return quregID; }
    /// clone the class
    virtual Value * clone(){ return new Qureg(size); }
  };

  class Quvoid :public Value{};
  class Quscratch :public Value{};

  /// QCL error value 
  class ErrorVal:public Value
  {
  public:
    ErrorVal():Value(ERROR){
      Object::error("value error");      
    }
    /*
    virtual operator bool(){ throw Exception("Invalid value");  }
    virtual operator int(){ throw Exception("Invalid value");  }
    virtual operator double(){ throw Exception("Invalid value");  }
    virtual operator complex<double>(){ throw Exception("Invalid value");  }
    virtual operator string(){ throw Exception("Invalid value");  }
    virtual string asString(){ throw Exception("Invalid value");  }
    virtual Value * clone(){ return new ErrorVal(); }
    */
  };


  /// QCL expression class
  class Expression :public Symbol{
  protected:
    Value *value;
  public:
    virtual operator bool(){
      if(this->isBoolean())
	assert(value);
	return *value;
      throw Exception("Unable convert expression to boolean");
    }
    virtual operator int(){
      assert(value);
      if(this->isInteger()) 
	return *value;
      throw Exception("Unable convert expression to int");
    }
    virtual operator double(){
      assert(value);
      if(this->isReal()) 
	return *value;
      throw Exception("Unable convert expression to real");
    }
    virtual operator complex<double>(){
      assert(value);
      if(this->isComplex())
	return value->getcomplex();
      throw Exception("Unable convert expression to complex");
    }
    
    virtual string asString(){
      this->pass();
      assert(value);
      return value->asString();
    }
  };

  class Procedure{
  public:
    Procedure(){}
  };
  class Operator{
  };
  class Qufunction{
  };
  class Function{
  };
  class Variable{
  };
};

/// QCL language class for conversion to qml
class Qcl{
private:
  vector<qcl::Procedure*> procedures;
  vector<qcl::Operator*> operators;
  vector<qcl::Qufunction*> qufunctions;
  vector<qcl::Function*> functions;
  vector<qcl::Variable*> stack;

  Qml qml;  
  Symbol * mainSymbol;
  bool bFromFile;
  void createJob(Qml &);
  void createSteps(Qml &);
  void createGateLib(Qml &);
  void createCircuitLib(Qml &);
public:
  /// Qcl constructor
  Qcl(const char *);
  /// destructor
  ~Qcl();
  /// convert qcl to qml
  Qml& toQml(const char *);


  /// translate qcl input to intermediate 
  /// quantum simulation class
  Qcl & operator>>(Qusim &qs){
    return *this;
  }
};





#endif
