#ifndef QUSIM_HH
#define QUSIM_HH

#include <vector>

using namespace std;

namespace qusim{

  typedef enum{X,Y,Z,RX,RY,RZ,H,NOT,CNOT,SWAP} OperationType;
  class Argument{};
  class Integer:public Argument{ };
  class Real:public Argument{};
  class Qureg: public Argument{
    vector<int> qubits;
  };

  class Operation{
    OperationType otype;
    vector<Argument*> args;
  };

  class Simulation{
    vector<Operation> actions;
  };
}

/// Quantum simulation class
class Qusim{
  
};

#endif
