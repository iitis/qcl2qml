#ifndef QML_HH
#define QML_HH


#include <string>
#include <iostream>
#include <vector>
#include <sstream>
#include "qusim.hh"
//#ifdef WIN32
#define LONG long long

//#else
// define LONG for other platform
//#define  LONG long long int 
//#endif 

using namespace std;


/**
 * XmlParam class
 */
class XmlParam{
  friend ostream & operator<<(ostream &,const XmlParam&);
protected:
  string name, value;
public:
  /*XmlParam(string & n, string & v)
    :name(n),value(v) 
    {}*/
    XmlParam(string & n, string  v)
   :name(n),value(v) 
  {}
  


  XmlParam(string &n)
    :name(n) 
  {}

  XmlParam(const char *n,const char *v)
    :name(n)
  {
	  if(v) 
      value=v;
  }
		

  XmlParam(const char *s)
    :name(s)
  {}


  static string inttostring(LONG i){
    stringstream s;
    s << i;
    return s.str();
  }

  void setname(string &s){ name = s; }
  void setvalue(string &s){ value = s; }
  void setvalue(LONG n){ value = XmlParam::inttostring(n); }
  string & getvalue(){ return value; }
  string & getname(){ return name; }

};

ostream & operator<<(ostream & out, const XmlParam & p);


class Comment;
/**
 * XmlTag class
 */
class XmlTag
{
  friend ostream & operator<<(ostream &, const XmlTag &);
  //  friend ostream & operator<<(ostream &, Comment &);
protected:
  static int tabs;
  string tag_name;
  bool empty_endtagname;
  vector<XmlParam *> params;
  vector<XmlTag *> subtags;
  void _empty_endtagname_init(const char *c){
     if((string("Operation").compare(c))==0 || (string("CircuitLib").compare(c))==0 ){
      empty_endtagname = true;
    }
    else{
      empty_endtagname = false;
    }
  }
public:
  XmlTag(string &n) 
    :tag_name(n) 
  {
    _empty_endtagname_init(n.c_str());
  }
  void setEmptyEndTagname(bool b=true){
    empty_endtagname = b;
  }
  XmlTag(const char *str) 
    :tag_name(str) 
  {
   _empty_endtagname_init(str);
  }
  virtual ~XmlTag(){
    for( vector<XmlParam*>::iterator i = params.begin(); i!=params.end(); i++)
      delete *i;
    for( vector<XmlTag*>::iterator i = subtags.begin(); i!=subtags.end(); i++)
      delete *i;
  }
    	
  XmlParam * getParam(const char * pname){
    for(vector<XmlParam *>::iterator i = params.begin(); i!=params.end(); i++)
      if((**i).getname().compare(pname)==0)
	return &**i;
    return 0;
  }
  void addsubtag(XmlTag *st){ subtags.push_back(st); }

  void addParam(const char *pname, const char *pvalue){
    params.push_back(new XmlParam(pname,pvalue));
  }

  void addParam(string pname, string pvalue){
    params.push_back(new XmlParam(pname,pvalue));
  }
  void addParam(string pname, LONG i){
    params.push_back(new XmlParam(pname,XmlParam::inttostring(i)));
  }


  string & getname(){ return tag_name;}
  XmlTag * getsubtag(const char *tname){
    for(vector<XmlTag *>::iterator i = subtags.begin(); i!=subtags.end(); i++)
      if((**i).getname().compare(tname)==0)
	return &**i;
    return 0;
  }
	
};

ostream & operator<<(ostream & out, const XmlTag & tag);




typedef enum {IDENT, PAULI_X, PAULI_Y, PAULI_Z, HADAMARD, RX, RY, _RX, _RY, T_GATE, S_GATE, PHASE,
UNITARY_1, CNOT, SWAP, CPHASE, UNITARY_2, TOFFOLI, FREDKIN, ORACLE, GROVER_STEP,GROVER,
MODULO, EXP, REVERSE, MEASUREMENT_Z} GateType;


/**
 * HTerm class
 */
class HTerm :public XmlTag{
public:	HTerm():XmlTag("HTerm")	{}
};

/**
 * Gate class
 */
class Gate :public XmlTag{
public:	Gate():XmlTag("Gate"){}
};
/**
 * Application class
 */
class Application :public XmlTag{
public:Application():XmlTag("Application"){}
};
/**
 * Operation class
 */
class Operation :public XmlTag{
  static int n;
public:	
  Operation():XmlTag("Operation"){
    char buff[32];
    sprintf(buff,"%d",n++);
    addParam("Step",buff);
  }
};


/**
 * Circuit class
 */
class Circuit :public XmlTag{
  static int app_id;
public:	
  Circuit():XmlTag("Circuit"){}
  static int getAppId(){return app_id++;}
};

/**
 * GateLib class
 */
class GateLib :public XmlTag{
public: GateLib():XmlTag("GateLib"){}
};
/**
 * CircuitLib class
 */
class CircuitLib :public XmlTag{
public: CircuitLib():XmlTag("CircuitLib"){}
};
/**
 * Results class
 */
class Results :public XmlTag{
public: Results():XmlTag("Results"){}
};
/**
 * Job class
 */
class Job :public XmlTag{

public: Job():XmlTag("Job"){}
};
/**
 * Qml class
 */






class Qml :public XmlTag{
public: 
  Qml():XmlTag("QML"){
    subtags.push_back(new Job);
    subtags.push_back(new Circuit);
    subtags.push_back(new CircuitLib);
    subtags.push_back(new GateLib);
  //   subtags.push_back(new Results);
    Operation *o = new Operation();
    getsubtag("Circuit")->addsubtag(o);
  }

  Qml & operator<<(Qusim &qs){
    return *this;
  }

};


/**
 * Comment class
 */
class Comment:public XmlTag{
  friend ostream & operator<<(ostream &,const Comment&);
public: 
  Comment(string &m):XmlTag(m){}
  Comment(const char *m):XmlTag(m){}
};
ostream & operator<<(ostream & out, const Comment & tag);







#endif
