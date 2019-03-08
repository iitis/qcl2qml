#ifndef FUNCTIONAL_HH
#define FUNCTIONAL_HH

#include <list>
#include <string>
#include <cassert>
#include <iostream>
#include "exception.hh"
//#define DEBUGSTACK 

using namespace std;

/** 
* StackElement class
*/
class StackElement
{
protected:
  string name;
public:
  /// constructor
  StackElement(){}
  /// constructor
  StackElement(const string & s):name(s){}
  /// destructor
  virtual ~StackElement(){}
  /// get object name
  string & getName(){ return name; }
  /// compare object to string
  bool operator==(const string & s){
    return name.compare(s)==0;
  }
};

/**
* Stack template
*/
template<class T>
class Stack{

protected:
  typedef list<T *> Scope;	// stack elements
  list<Scope> stack;		// stack of scopes
public:
  /// stack iterator class
  class iterator{
    /// stack scope iterator
    typename list<Scope>::iterator iscope;
    /// stack item iterator
    typename Scope::iterator iitem;
    /// iterator stack reference
    list<Scope> & istack;
  public:
    /// class constructor
    iterator(typename list<Scope>::iterator s,typename Scope::iterator i,list<Scope> &is)
      :iscope(s),iitem(i),istack(is){}
      /// iterator increment operator
      typename Stack<T>::iterator & operator ++(){
        iitem++;
        if(iitem == iscope->end()){
          iscope++;
          if(iscope == iscope->end()){

          }
        }
        return *this;
      }
      bool operator ==(typename Stack<T>::iterator  it){
        if(it.iscope == this->iscope && it.iitem == this->iitem )
          return true;
        return false;
      }
      bool operator !=(typename Stack<T>::iterator  it){
        return ! this->operator==(it);
      }
  };// iterator class

private:
  /// print stack
  void printstack(){
    for(typename list<Scope>::iterator i = stack.begin(); i ==stack.end(); i++){
      for(typename Scope::iterator j = i->begin(); j != i->end(); j++){
        StackElement * var = dynamic_cast<StackElement *>(*j);
        assert(var);
        cout << var->getName() << " " ;
      }
      cout << endl;
    }
  }

public:

  /// Stack constructor
  Stack(){
    Scope  global;		// create global scope
    stack.push_front(global);
  }

  /// stack bottom
  typename Stack<T>::iterator bottom(){
    return Stack<T>::iterator(stack.begin(),stack.begin()->begin(),stack);
  }
  typename Stack<T>::iterator top(){
    return Stack<T>::iterator(stack.end(),(stack.end())->end(),stack);
  }



  void push(T *t){		// push stack element
    stack.front().push_front(t);
#ifdef DEBUGSTACK
    cout << "push:" << endl;
    printstack();
#endif
  }

  void push_scope(){		// push scope to stack
    Scope newscope;
    stack.push_front(newscope);
#ifdef DEBUGSTACK
    cout << "push_scope:";
    printstack();
#endif
  }

  void pop_scope(){		// pop the most inner scope
    if(stack.empty())
      throw Exception("Unable pop from empty stack");
    else{
      
      stack.pop_front();
    }

#ifdef DEBUGSTACK
    cout <<"pop_scope:";
    printstack();
#endif
  }

  /// find Variable on the stack
  T* find(const string &c){
#ifdef DEBUGSTACK
    cout << "Stack::find("<< c<<")" << endl;
#endif
    for(typename list<Scope>::iterator i = stack.begin(); i !=stack.end(); i++)
      for(typename Scope::iterator j = i->begin(); j != i->end(); j++){
        StackElement * var = dynamic_cast<StackElement *>(*j);
        assert(var);
        string s = var->getName();
        if(!((var->getName()).compare(c))){
          return  *j;
        }
      }
      return 0;
  }
  virtual ~Stack(){
  /*    
    for(list<Scope>::iterator i = stack.begin(); i!=stack.end(); i++){
      for(list<typename T*>::iterator j = (*i).begin(); j!=(*i).end(); j++)
        delete *j;
    }
    */
  }
};




#endif
