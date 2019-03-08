#include "functional.hh"
#include "statement.hh"
#include "qml.hh"

#include <list>
#include <algorithm>
#include "qml.hh"
/**
* Values stack 
*/
Stack<Identifier> stack;

/**
* Subroutines stack (nested function definitions)
*/

SUBROUTINES_COLLECTION subroutines;
list<XmlTag*> steps;


/// Procedure constructor
Procedure::Procedure(Identifier *i,Def *ar, Symbol *bdy)
:Routine(i,ar,bdy),
Stmt(PROCEDURE){
}
void Procedure::static_control(){}
void Procedure::pass(){}



Operator::Operator(Identifier *i,Def*ar,Symbol *bdy)
  :Routine(i,ar,bdy),
Stmt(OPERATOR){
}

void Operator::static_control(){
}

void Operator::pass(){
}



void RoutineCall::static_control(){}

void RoutineCall::pass(){

  SUBROUTINES_COLLECTION::iterator r = find(subroutines.begin(),subroutines.end(),id->getName());
  args->passAll();
  if (build_in_check())
    return;

  if( r != subroutines.end() ){
    (**r).set_args(args);



    if((**r).getBody()) 
      (**r).getBody()->passAll();

    stack.pop_scope();
  }else{
    string s = "Function ";
    s+= id->getName();
    s+=" not defined";
    ERROR(s);
  }

}

bool RoutineCall::build_in_check( ){

#define COMPARETO(s) (this->id->getName().compare(s) == 0)


  XmlTag *t=0;
  if(COMPARETO("Mix") || COMPARETO("H")  ){
    t=new XmlTag("Operation");
    IdExpression *ide =  dynamic_cast<IdExpression*>(args);
    if(!ide)
      ERROR("Arguments must be a quantum register reference");

    Identifier *se = stack.find(ide->getName());
    Value &v =se->getValue();
    try{
      Qureg &q = dynamic_cast<Qureg&>(v);
      qubitmanager.hadamard(q.getID(),t);
    }catch(bad_cast){
      ERROR("Invalid argument")
    }
  }else{
    if( COMPARETO("CNOT") || COMPARETO("CNot") ){
      t=new XmlTag("Operation");
      IdExpression *ide1 =  dynamic_cast<IdExpression*>(args);
      IdExpression *ide2 =  dynamic_cast<IdExpression*>(args->getNext());
      if(!ide1 )
        ERROR("Argument 1 must be a quantum register reference");
      if(!ide2 )
        ERROR("Argument 2 must be a quantum register reference");

      Identifier *sa = stack.find(ide1->getName());
      Value &va =sa->getValue();
      Identifier *sb = stack.find(ide2->getName());
      Value &vb =sb->getValue();
      try{
        Qureg &qa = dynamic_cast<Qureg&>(va);
        Qureg &qb = dynamic_cast<Qureg&>(vb);
        qubitmanager.cnot(qa.getID(),qb.getID(),t);
      }catch(bad_cast){
        ERROR("Invalid argument")
      }
    }
    else
      if( COMPARETO("Swap") ){
        t=new XmlTag("Operation");
        IdExpression *ide1 =  dynamic_cast<IdExpression*>(args);
        IdExpression *ide2 =  dynamic_cast<IdExpression*>(args->getNext());
        if(!ide1 )
          ERROR("Argument 1 must be a quantum register reference");
        if(!ide2 )
          ERROR("Argument 2 must be a quantum register reference");

        Identifier *sa = stack.find(ide1->getName());
        Value &va =sa->getValue();
        Identifier *sb = stack.find(ide2->getName());
        Value &vb =sb->getValue();
        try{
          Qureg &qa = dynamic_cast<Qureg&>(va);
          Qureg &qb = dynamic_cast<Qureg&>(vb);
          qubitmanager.swap(qa.getID(),qb.getID(),t);
        }catch(bad_cast){
          ERROR("Invalid argument")
        }}
      else 
        if(COMPARETO("set")){
          t=new XmlTag("Operation");
          args->pass();
          int va =  (int)(args->getValue());
          IdExpression *ide2 =  dynamic_cast<IdExpression*>(args->getNext());
          if(!ide2 )
            ERROR("Argument 2 must be a quantum register reference");

          //Identifier *sa = stack.find(ide1->getName());
          //Value &va =sa->getValue();
          Identifier *sb = stack.find(ide2->getName());
	  
          Value &vb =sb->getValue();
          try{
            //Qureg &qa = dynamic_cast<Qureg&>(va);
            Qureg &qb = dynamic_cast<Qureg&>(vb);
            qubitmanager.set(va,qb.getID(),t);
          }catch(bad_cast){
            ERROR("Invalid argument")
          }
        }   
        else
          if(COMPARETO("Pauli")){
            t=new XmlTag("Operation");
            int va =  (int)(*args);
            IdExpression *ide2 =  dynamic_cast<IdExpression*>(args->getNext());
            if(!ide2 )
              ERROR("Argument 2 must be a quantum register reference");

            Identifier *sb = stack.find(ide2->getName());
            Value &vb =sb->getValue();
            try{
              //Qureg &qa = dynamic_cast<Qureg&>(va);
              Qureg &qb = dynamic_cast<Qureg&>(vb);
              if(va==1 || va==2 || va==3)
                ERROR("Invalid argument");
              qubitmanager.pauli(va,qb.getID(),t);
            }catch(bad_cast){
              ERROR("Invalid argument")
            }
          }else{
            return false;
          }  
  }
          steps.push_back(t);
          return true;
  
}

void VarAssig::static_control(){}

void VarAssig::pass(){
  assert(id && expr);
  expr->pass();
  Identifier * i = stack.find(id->getName());
  if(i){
    i->setValue(expr->getValue().clone());
  }else{
    string s=id->getName();
    s+=":undefined";
    ERROR(s.c_str());
  }	
}

void VarAssig::assign(Identifier *id, Expression *expr){
  assert(id && expr);
  expr->pass();
  Identifier * i = stack.find(id->getName());
  if(i){
    i->setValue(expr->getValue().clone());
  }else{
    string s=id->getName();
    s+=":undefined";
    //ERROR(s.c_str());
  }	
}

void VarAssig::pass_no_expr_pass(){
  assert(id && expr);
  Identifier * i = stack.find(id->getName());
  if(i){
    i->setValue(expr->getValue().clone());
  }else{
    string s=id->getName();
    s+=":undefined";
    ERROR(s.c_str());
  }
}


void FanoutOperator::static_control(){}
void FanoutOperator::pass(){}

void SwapOperator::static_control(){}
void SwapOperator::pass(){}

void ForStmt::static_control(){}
void ForStmt::pass(){
  assert(body);
  assert(efrom);
  assert(eto);

  stack.push_scope();

  //Def d(id,efrom->getValue().getType() ,efrom);
  //d.pass();
  //  IdExpression *ide = new IdExpression(id);
  VarAssig * init = new VarAssig(id,efrom);
  init->pass();

  if(!estep)
    estep = new Constant( new Integer(1));

  Expression * fcond;
  estep->pass();
  if( ((int)*estep) > 0){
    fcond = new IsGrExpression(new IdExpression(id),eto);
  }
  else if (((int)*estep) < 0)	{
    fcond = new IsLessExpression(new IdExpression(id),eto);
  }
  else {
    // error step = 0 
  }

  fcond->pass();

  AddExpression *add = new AddExpression(new IdExpression(id),estep);
  VarAssig *va = new VarAssig(id,add);

  while(! (bool)fcond->getValue()){  
    body->passAll();
    va->pass();
    fcond->pass();
  }
  //  body->passAll();

  //delete fcond;
  //delete init;
  //delete va;
  //delete add;

  stack.pop_scope();
}

void WhileStmt::static_control(){}
void WhileStmt::pass(){
  assert(expr && body);
  expr->pass();
  if(!expr->getValue().isLogic()){
    ERROR("invalid loop condition");
  }else{
    while(expr->getValue()){
      body->passAll();
      expr->pass();
      if(!expr->getValue().isLogic()){
        ERROR("invalid loop condition");
      }
    }
  }
}


void UntilStmt::static_control(){
}
void UntilStmt::pass(){
  assert(expr && body);

  body->passAll();

  expr->pass();

  while(expr->getValue()){
    body->passAll();
    expr->pass();
    if(!expr->getValue().isLogic()){
      ERROR("invalid loop condition");
    }

  }
}


void IfStmt::static_control(){
}

void IfStmt::pass(){
  expr->pass();
  if(!expr->getValue().isLogic()){
    ERROR("invalid if-condition");
  }
  else{
    if(expr->getValue()){
      if(tblock)
        tblock->passAll();
    }else{
      if(fblock)
        fblock->passAll();
    }
  }

}

void ReturnStmt::static_control(){}
void ReturnStmt::pass(){
  assert(expr);
  expr->pass();
  Identifier * pretval = new Identifier("return");
  pretval->setValue(expr->getValue().clone());
  stack.push(pretval);
}


void Input::static_control(){}
void Input::pass(){}

void PrintStmt::static_control(){}
void PrintStmt::pass(){
  Expression * ep = expr;
  string s;
  while(ep){
    s+= ep->asString() ;
    s+= ' ';
    ep = dynamic_cast<Expression*>(ep->getNext());
  }
  Comment comment(s);
  cout << comment;
}


void Exit::static_control(){}
void Exit::pass(){}

void Measure::static_control(){}
void Measure::pass(){}

void Reset::static_control(){}
void Reset::pass(){}

void Dump::static_control(){}
void Dump::pass(){}

void Load::static_control(){}
void Load::pass(){}

void Save::static_control(){}
void Save::pass(){}

void Shell::static_control(){}
void Shell::pass(){}
/*
void Set::static_control(){}
void Set::pass(){}
*/


