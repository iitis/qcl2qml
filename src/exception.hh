#ifndef EXCEPTION_HH
#define EXCEPTION_HH

#include <iostream>
using namespace std;

/**
 * Exception class
 */
class Exception
{
protected:
  string msg;
public:
  /// default exception constructor
  Exception(){ msg="Unknown exception."; }

  /// exception with string message
  Exception(string &s):msg(s){ }

  /// exception withc char* mesage
  Exception(const char* s):msg(s){}

  /// report an exception
  void report(){ 
	cerr << "Exception: " << msg.c_str() << endl; 
  }
};

/** 
 * ValueException class
 */
class ValueException: public Exception{
public:
  
};



#endif //EXCEPTION_HH

