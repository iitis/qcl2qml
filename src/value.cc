#include "value.hh"
#include <iostream>
using namespace std;

//string Value::os = "";

ostream & operator << (ostream & os, Value & v)
{
  string s = v;
  return os << s;
}


