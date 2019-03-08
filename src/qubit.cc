#include "qubit.hh"

#include <sstream>


QubitManager qubitmanager;

QubitManager::QubitManager(){
  lastfree = 0;
  nqubits = 0;
}



int QubitManager::qregister(int n){
  QREGTYPE q;
  nqubits+=n;
  for(int i =0 ;i< n; i++)
    q.push_back(Qubit(lastfree++));
  qregs.push_back(q);
  return qregs.size()-1;
}

string QubitManager::toString(int n){
  stringstream s;
  QREGTYPE &q = qregs[n];

  for(QREGTYPE::iterator i = q.begin();i !=q.end(); i++){
    s<< (*i).getID();
    if(i+1!=q.end())
      s << ',';
  }
  return s.str();
}

void QubitManager::cnot(int a,int b,XmlTag*uptag){
  QREGTYPE &qa = qregs[a];
  QREGTYPE &qb = qregs[b];

  if(qa.size() == qb.size()){

    QREGTYPE::iterator abit = qa.begin();
    QREGTYPE::iterator bbit = qb.begin();
    while( abit != qa.end() ){
      XmlTag *a = new XmlTag("Application");
      a->addParam("Name","G");
      a->addParam("Id",Circuit::getAppId());
      stringstream sbits;
      sbits << (*abit).getID() << "," << (*bbit).getID();
      a->addParam("Bits",sbits.str().c_str());
      XmlTag *g = new XmlTag("Gate");
      g->addParam("Type","CNOT");
      a->addsubtag(g);
      uptag->addsubtag(a);
      abit++;
      bbit++;
    }
  }

}


/// append hadamard operation on register to uptag
void QubitManager::hadamard(int reg ,XmlTag *uptag){
  QREGTYPE &q = qregs[reg];
  for (QREGTYPE::iterator qbit = q.begin();qbit!=q.end();qbit++){
    XmlTag *a = new XmlTag("Application");
    a->addParam("Name","G");
    a->addParam("Id",Circuit::getAppId());
    a->addParam("Bits",(*qbit).getID());
    XmlTag *g = new XmlTag("Gate");
    g->addParam("Type","HADAMARD");
    a->addsubtag(g);
    uptag->addsubtag(a);
  }
}
void QubitManager::pauli(int axis ,int reg, XmlTag * uptag){
  QREGTYPE &q = qregs[reg];
  for (QREGTYPE::iterator qbit = q.begin();qbit!=q.end();qbit++){
    XmlTag *a = new XmlTag("Application");
    a->addParam("Name","G");
    a->addParam("Id",Circuit::getAppId());
    a->addParam("Bits",(*qbit).getID());
    XmlTag *g = new XmlTag("Gate");
    switch(axis){
      case 1: g->addParam("Type","PAULI_X");
        break;
      case 2: g->addParam("Type","PAULI_X");
        break;
      case 3: g->addParam("Type","PAULI_X");
        break;
      
        
    }
    
    a->addsubtag(g);
    uptag->addsubtag(a);
  } 
}



void QubitManager::swap(int a,int b,XmlTag*uptag){
  QREGTYPE &qa = qregs[a];
  QREGTYPE &qb = qregs[b];

  if(qa.size() == qb.size()){

    QREGTYPE::iterator abit = qa.begin();
    QREGTYPE::iterator bbit = qb.begin();
    while( abit != qa.end() ){
      XmlTag *a = new XmlTag("Application");
      a->addParam("Name","G");
      a->addParam("Id",Circuit::getAppId());
      stringstream sbits;
      sbits << (*abit).getID() << "," << (*bbit).getID();
      a->addParam("Bits",sbits.str().c_str());
      XmlTag *g = new XmlTag("Gate");
      g->addParam("Type","SWAP");
      a->addsubtag(g);
      uptag->addsubtag(a);
      abit++;
      bbit++;
    }
  }

}

void QubitManager::set(LONG value,int reg,  XmlTag * uptag){
  QREGTYPE &q = qregs[reg];
  LONG i =1;
  for (QREGTYPE::iterator qbit = q.begin();qbit!=q.end();qbit++){
    XmlTag *a = new XmlTag("Application");
    a->addParam("Name","G");
    a->addParam("Id",Circuit::getAppId());
    a->addParam("Bits",(*qbit).getID());
    XmlTag *g = new XmlTag("Gate");
    g->addParam("Type","PREPARATION");
    if( value & i){
      g->addParam("Probability","1");
    }else{
      g->addParam("Probability","0");
    }
    i = i << 1;

    a->addsubtag(g);
    uptag->addsubtag(a);
  }  
}

void QubitManager::reset(){
}
