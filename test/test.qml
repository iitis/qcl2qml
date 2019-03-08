<QML>
  <Job Id="">
    <Date Performed="0" Requested="1157483296394"/>
    <Status Info="1157483296394CREATED" Current="CREATED" Error="NONE"/>
    <Method Threshold="0.0050" Performed="NONE" Requested="AUTO"/>
    <Computation RunTime="0" QueueTime="NONE" Cpus="0" Accuracy="1.0" MBytes="0" EstimatedTime="0"/>
  </Job>
  <Circuit Name="default" Size="28" Id="default.qml" Description="">
    <Operation Step="0">
    </Operation>
    <Operation Step="1">
      <Application Name="G" Id="0" Bits="0">
        <Gate Type="PREPARATION" Probability="1"/>
      </Application>
      <Application Name="G" Id="1" Bits="1">
        <Gate Type="PREPARATION" Probability="1"/>
      </Application>
    </Operation>
    <Operation Step="2">
      <Application Name="G" Id="2" Bits="0">
        <Gate Type="HADAMARD"/>
      </Application>
      <Application Name="G" Id="3" Bits="1">
        <Gate Type="HADAMARD"/>
      </Application>
    </Operation>
    <Operation Step="3">
      <Application Name="G" Id="4" Bits="2,3">
        <Gate Type="SWAP"/>
      </Application>
    </Operation>
    <Operation Step="4">
      <Application Name="G" Id="5" Bits="0,4">
        <Gate Type="CNOT"/>
      </Application>
      <Application Name="G" Id="6" Bits="1,5">
        <Gate Type="CNOT"/>
      </Application>
    </Operation>
    <Operation Step="5">
      <Application Name="G" Id="7" Bits="4,0">
        <Gate Type="SWAP"/>
      </Application>
      <Application Name="G" Id="8" Bits="5,1">
        <Gate Type="SWAP"/>
      </Application>
    </Operation>
    <Operation Step="6">
      <Application Name="G" Id="9" Bits="4,0">
        <Gate Type="SWAP"/>
      </Application>
      <Application Name="G" Id="10" Bits="5,1">
        <Gate Type="SWAP"/>
      </Application>
    </Operation>
    <Operation Step="7">
      <Application Name="G" Id="11" Bits="4,0">
        <Gate Type="SWAP"/>
      </Application>
      <Application Name="G" Id="12" Bits="5,1">
        <Gate Type="SWAP"/>
      </Application>
    </Operation>
  </Circuit>
  <CircuitLib>
  </CircuitLib>
  <GateLib>
    <Gate Type="IDENT"/>
    <Gate Type="PAULI_X"/>
    <Gate Type="PAULI_Y"/>
    <Gate Type="PAULI_Z"/>
    <Gate Type="HADAMARD"/>
    <Gate Type="RX"/>
    <Gate Type="RY"/>
    <Gate Type="_RX"/>
    <Gate Type="_RY"/>
    <Gate Type="T_GATE"/>
    <Gate Type="S_GATE"/>
    <Gate Type="PHASE" Divisions="1"/>
    <Gate Matrix="1.0,i0.0,0.0,i0.0,0.0,i0.0,1.0,i0.0" Type="UNITARY_1"/>
    <Gate Type="CNOT"/>
    <Gate Type="SWAP"/>
    <Gate Type="CPHASE" Divisions="1"/>
    <Gate Matrix="1.0,i0.0,0.0,i0.0,0.0,i0.0,0.0,i0.0,0.0,i0.0,1.0,i0.0,0.0,i0.0,0.0,i0.0,0.0,i0.0,0.0,i0.0,1.0,i0.0,0.0,i0.0,0.0,i0.0,0.0,i0.0,0.0,i0.0,1.0,i0.0" Type="UNITARY_2"/>
    <Gate Type="TOFFOLI"/>
    <Gate Type="FREDKIN"/>
    <Gate Size="2" Type="ORACLE" BasisState="0x255"/>
    <Gate Size="2" Type="GROVER" Steps="1" BasisState="0x1"/>
    <Gate Size="2" Type="GROVER_STEP" BasisState="0x255"/>
    <Gate Modulus="1" Size="3" Type="MODULO" Base="1" Index="1"/>
    <Gate Size="2" Type="EXP" Duration="0.25">
      <HTerm Matrix="0.0,0.0,1.0" Index="0"/>
      <HTerm Matrix="0.0,0.0,1.0" Index="1"/>
      <HTerm Matrix="0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,1.0" Index="0,1"/>
    </Gate>
    <Gate Size="2" Type="REVERSE"/>
    <Gate Size="2" Type="QFT"/>
    <Gate Type="PREPARATION" Probability="1.0"/>
    <Gate Type="MEASUREMENT_Z"/>
    <Gate Size="2" Type="CIRCUIT"/>
    <Gate P1="0.5" Size="2" P0="0.5" Type="RANDOM" CaseSize="1"/>
  </GateLib>
</QML>
