#include "definition.hh"



void Def::static_control(){

}


void Def::pass(){

  if(expr){
    expr->pass();
    id->setValue(expr->getValue());
    if(stype == CONST){
      
    }
  }else{
    switch(stype){
    case BOOLEAN: id->setValue(new Boolean());
      break;
    case INTEGER: id->setValue(new Integer());
      break;
    case REAL: id->setValue(new Real());
      break;
    case COMPLEX: id->setValue(new Complex());
      break;
    case STRING: id->setValue(new String());
      break;
    default:
      ERROR("unknown variable.");
      break;
    }
  }
  stack.push(id);

}



void Defq::pass(){
  if(expr){
    expr->pass();

    switch(stype){
    case QUREG: id->setValue(new Qureg(expr->getValue()));      
      break;
    case QUVOID:
      break;
    case QUCONST:
      break;
    case QUSCRATCH:
      break;
    default:
      ERROR("unknown variable.");
      break;    
   }
  }
  else{
    ERROR("unknown quantum length");
  }
  stack.push(id);
}



void ProcDef::static_control(){}
void ProcDef::pass(){
  subroutines.push_back( * new ptr<Routine>( new Procedure(id,def,body)));
}

void FunctDef::static_control(){}

void FunctDef::pass(){
  subroutines.push_back( * new ptr<Routine> (new Function(stype,id,def,body)) );
}


void OperDef::pass(){
  subroutines.push_back( * new ptr<Routine> (new Operator(id,def,body)));
}

