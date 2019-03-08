
#include "qcl.hh"
#include <iostream>

using namespace std;

int main(int argc,char *argv[])
{ 
    
 Qcl qcl( argc>1 ? argv[1] : 0 );
 
  try{
    cout << qcl.toQml( argc==3 ? argv[2] : 0 );
  }catch(Exception &e){
     e.report();   
  }
  return 0;
}
