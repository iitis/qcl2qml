#include "symbol.hh"
#include "expression.hh"


int Error::noerrors=0;

void Symbol::addNext(Symbol *ns){
  next = ns;

}

void Symbol::checkAll(){
  Symbol *n = this;
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


