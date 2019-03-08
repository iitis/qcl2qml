

#include "qcl.tab.c"
#include "qcl.hh"
#include "qml.hh"
#include "qubit.hh"
#include <list>
#include <sstream>
#include <time.h>



extern list<XmlTag *> steps;
extern QubitManager qubitmanager;



namespace qcl{

  int nerrors = 0;

  void Symbol::checkAll(){
    Symbol * n = this;
    while(n){
      n->static_control();
      n=n->getNext();
    }
  }


  void Symbol::passAll(){
    Symbol *n = this;
    while(n){
      n->pass();
      n=n->getNext();
    }
  }




}



  /// Qcl constructor
Qcl::Qcl(const char *c=0){
  bFromFile=false;
  mainSymbol=0;
  if(c){
    ::srcname=c;
    bFromFile=true;
    ::qclin = fopen(c,"r");
    string ofname(c);
    ofname+=".qml";
    
  }
}

Qcl::~Qcl(){
  if(bFromFile)
    fclose(::qclin);
  delete mainSymbol;
}

Qml& Qcl::toQml(const char *jobid){
  //::yydebug = 1;
  //::yyparse((void**)(&mainSymbol));
  ::qclparse((void**)(&mainSymbol));
  if(mainSymbol){
    mainSymbol->checkAll();
    mainSymbol->passAll();
    
    qml.getsubtag("Job")->addParam("Id",jobid);

    createJob(qml);
    createSteps(qml);
    createCircuitLib(qml);
    createGateLib(qml);
  }else
    throw Exception("Missing main symbol.");
  return qml;
}


void Qcl::createJob(Qml &o){
  XmlTag *c = o.getsubtag("Circuit");
  c->addParam("Name","default");
  c->addParam("Size",1);
  c->addParam("Id","default.qml");
  c->addParam("Description","");
  XmlTag *j = o.getsubtag("Job");
  if(j){
    XmlTag *d = new XmlTag("Date"); j->addsubtag(d);
    d->addParam("Performed", "0");
    // win32 specific data
    stringstream s;
#ifdef WIN32
    LONG t;
    _time64(&t);
    t*=1000;
    s << t;
#else
    s << "1157483296394" ;
    
#endif //WIN32

    //#ifdef
//#else
      
    d->addParam("Requested", s.str().c_str());
    d= new XmlTag("Status"); j->addsubtag(d);
    s << "CREATED";
    d->addParam("Info",s.str().c_str());
    d->addParam("Current","CREATED");
    d->addParam("Error","NONE");

    d= new XmlTag("Method"); j->addsubtag(d);
    d->addParam("Threshold","0.0050");
    d->addParam("Performed","NONE");
    d->addParam("Requested","AUTO");

    d= new XmlTag("Computation"); j->addsubtag(d);
    d->addParam("RunTime","0");
    d->addParam("QueueTime","NONE");
    d->addParam("Cpus","0");
    d->addParam("Accuracy","1.0");
    d->addParam("MBytes","0");
    d->addParam("EstimatedTime","0");
  }
}

void Qcl::createSteps(Qml &o){
  XmlTag *stp = o.getsubtag("Circuit");
  int stepno=0;
  qml.getsubtag("Circuit")->getParam("Size")->setvalue( qubitmanager.getBitsUsed()<4 ? 4 : qubitmanager.getBitsUsed() );
  for(list<XmlTag*>::iterator i =steps.begin(); i!=steps.end(); i++){
    (*i)->addParam("Step",++stepno);
    stp->addsubtag( *i );
  }
  while(++stepno < 5 ) {
    XmlTag *s = new XmlTag("Operation");
    s->addParam("Step",stepno);
    stp->addsubtag(s);
  }
}

void Qcl::createGateLib(Qml &o){
  char * gates[]={"IDENT","PAULI_X","PAULI_Y","PAULI_Z","HADAMARD","RX","RY","_RX","_RY","T_GATE"};
  XmlTag *g;
  XmlTag *gl = o.getsubtag("GateLib");
  if(gl){
    for(int i=0;i<10;i++){
      g=new XmlTag("Gate");
      g->addParam("Type",gates[i]);
      gl->addsubtag(g);
    }
     g=new XmlTag("Gate");
     g->addParam("Type","S_GATE");
     gl->addsubtag(g);

     g=new XmlTag("Gate");
     g->addParam("Type","PHASE");
     g->addParam("Divisions",1);
     gl->addsubtag(g);
    
     g=new XmlTag("Gate");
     g->addParam("Matrix","1.0,i0.0,0.0,i0.0,0.0,i0.0,1.0,i0.0");
     g->addParam("Type","UNITARY_1");
     gl->addsubtag(g);
        
      g=new XmlTag("Gate");
     g->addParam("Type","CNOT");
     gl->addsubtag(g);


     g=new XmlTag("Gate");
     g->addParam("Type","SWAP");
     gl->addsubtag(g);

     g=new XmlTag("Gate");
     g->addParam("Type","CPHASE");
     g->addParam("Divisions",1);
     gl->addsubtag(g);

     g=new XmlTag("Gate");
     g->addParam("Matrix","1.0,i0.0,0.0,i0.0,0.0,i0.0,0.0,i0.0,0.0,i0.0,1.0,i0.0,0.0,i0.0,0.0,i0.0,0.0,i0.0,0.0,i0.0,1.0,i0.0,0.0,i0.0,0.0,i0.0,0.0,i0.0,0.0,i0.0,1.0,i0.0");
     g->addParam("Type","UNITARY_2");
     gl->addsubtag(g);
    
     g=new XmlTag("Gate");
     g->addParam("Type","TOFFOLI");
     gl->addsubtag(g);

     g=new XmlTag("Gate");
     g->addParam("Type","FREDKIN");
     gl->addsubtag(g);

     g=new XmlTag("Gate");
     g->addParam("Size",2);
     g->addParam("Type","ORACLE");
     g->addParam("BasisState","0x255");
     gl->addsubtag(g);
   
     g=new XmlTag("Gate");
     g->addParam("Size",2);
     g->addParam("Type","GROVER");
     g->addParam("Steps",1);
     g->addParam("BasisState","0x1");
     gl->addsubtag(g);
     
     g=new XmlTag("Gate");
     g->addParam("Size",2);
     g->addParam("Type","GROVER_STEP");
     g->addParam("BasisState","0x255");
     gl->addsubtag(g);
    
     g=new XmlTag("Gate");
     g->addParam("Modulus",1);
     g->addParam("Size",3);
     g->addParam("Type","MODULO");
     g->addParam("Base",1);
     g->addParam("Index",1);
     gl->addsubtag(g);
    
     g=new XmlTag("Gate");
     g->addParam("Size",2);
     g->addParam("Type","EXP");
     g->addParam("Duration","0.25");
     XmlTag *ht = new XmlTag("HTerm");
     ht->addParam("Matrix","0.0,0.0,1.0");
     ht->addParam("Index","0");
     g->addsubtag(ht);
     ht = new XmlTag("HTerm");
     ht->addParam("Matrix","0.0,0.0,1.0");
     ht->addParam("Index",1);
     g->addsubtag(ht);
     ht = new XmlTag("HTerm");
     ht->addParam("Matrix","0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,1.0");
     ht->addParam("Index","0,1");
     g->addsubtag(ht);
     gl->addsubtag(g);

     g=new XmlTag("Gate");
     g->addParam("Size",2);
     g->addParam("Type","REVERSE");
     gl->addsubtag(g);

     g=new XmlTag("Gate");
     g->addParam("Size",2);
     g->addParam("Type","QFT");
     gl->addsubtag(g);
    
     g=new XmlTag("Gate");
     g->addParam("Type","PREPARATION");
     g->addParam("Probability","1.0");
     gl->addsubtag(g);

     g=new XmlTag("Gate");
     g->addParam("Type","MEASUREMENT_Z");
     gl->addsubtag(g);
    
     g=new XmlTag("Gate");
     g->addParam("Size",2);
     g->addParam("Type","CIRCUIT");
     gl->addsubtag(g);
    
     g=new XmlTag("Gate");
     g->addParam("P1","0.5");
     g->addParam("Size",2);
     g->addParam("P0","0.5");
     g->addParam("Type","RANDOM");
     g->addParam("CaseSize",1);
     gl->addsubtag(g);
    
  }else{

    throw Exception("Unable to find GateLib tag"); 
  }
}


void Qcl::createCircuitLib(Qml &o){
}





/* EXTERN (global symbols)

operator Mix(qureg q);
extern operator H(qureg q);
qufunct set(int n,qureg q);
extern qufunct CNOT(qureg q,quconst c);
cond qufunct CNot(qureg q,quconst c);

operator Pauli(int i,qureg q);

cond operator CPhase(real phi,quconst q);
const E = 2.71828;
extern cond qufunct Fanout(quconst a,quvoid b);

const I = (0,1);
extern operator Matrix(complex matrix u,qureg q);
extern operator Matrix2x2(complex u00,complex u01,complex u10,complex u11,qureg 
extern operator Matrix4x4(complex u00,complex u01,complex u02,complex u03,comple
 u33,qureg q);
extern operator Matrix8x8(complex u00,complex u01,complex u02,complex u03,comple
 u17,complex u20,complex u21,complex u22,complex u23,complex u24,complex u25,com
lex u41,complex u42,complex u43,complex u44,complex u45,complex u46,complex u47,
omplex u63,complex u64,complex u65,complex u66,complex u67,complex u70,complex u

extern qufunct ModExp(int n,int x,quconst a,quvoid b);
extern qufunct NOT(qureg q);
cond qufunct Not(qureg q);

extern qufunct Perm(int vector p,qureg q);
extern qufunct Perm16(int p0,int p1,int p2,int p3,int p4,int p5,int p6,int p7,in
extern qufunct Perm2(int p0,int p1,qureg q);
extern qufunct Perm32(int p0,int p1,int p2,int p3,int p4,int p5,int p6,int p7,in
nt p25,int p26,int p27,int p28,int p29,int p30,int p31,qureg q);
extern qufunct Perm4(int p0,int p1,int p2,int p3,qureg q);
extern qufunct Perm64(int p0,int p1,int p2,int p3,int p4,int p5,int p6,int p7,in
nt p25,int p26,int p27,int p28,int p29,int p30,int p31,int p32,int p33,int p34,i
1,int p52,int p53,int p54,int p55,int p56,int p57,int p58,int p59,int p60,int p6
extern qufunct Perm8(int p0,int p1,int p2,int p3,int p4,int p5,int p6,int p7,qur
cond operator Phase(real phi);
extern operator Rot(real theta,qureg q);
extern operator RotX(real theta,qureg q);
extern operator RotY(real theta,qureg q);
extern operator RotZ(real theta,qureg q);
extern operator S(quconst q);
extern operator SqrtNot(qureg q);
extern cond qufunct Swap(qureg a,qureg b);
extern operator T(quconst q);
extern operator V(real phi,quconst q);
extern qufunct X(qureg q);
extern operator Y(qureg q);
extern operator Z(quconst q);
const pi = 3.14159;
procedure randomize(qureg q);




*/
