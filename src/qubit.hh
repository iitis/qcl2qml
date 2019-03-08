#ifndef QUBIT_HH
#define QUBIT_HH

#include "qml.hh"

#include <utility>
#include <string>
#include <vector>
#include <iostream>
using namespace std;



// Quantum abstract computatioin 

/** 
 * Qubit class
 */
class Qubit{
protected:
  int id;
public:
  Qubit(){}
  Qubit(int i):id(i){}
  void setID(int i){ id =i; }
  int getID(){ return id;}
};


typedef vector<Qubit> QREGTYPE; 

/** 
 * QubitManager class
 */
class QubitManager{
  vector<QREGTYPE> qregs;
  vector<QREGTYPE> qscratch;
  int lastfree;
  int nqubits;

public:
  QubitManager();
  int qregister(int);
  //void qscratch(int);
  int getBitsUsed(){return lastfree;}
  void reset();
  void qoperator(int);
  void cnot(int,int,XmlTag*);
  void hadamard(int,XmlTag*);
  void pauli(int,int,XmlTag*);
  void swap(int,int,XmlTag*);
  void set( LONG,int, XmlTag*);
  string toString(int);
};




#endif
