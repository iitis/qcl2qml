#ifndef DEFS_HH
#define DEFS_HH

#ifdef WIN32

#define CRTDBG_MAP_ALLOC
#include <stdlib.h>
#include <crtdbg.h>
#include <typeinfo>
#endif

// turn on assertion
#undef NDEBUG



// turn off assertion
//#define NDEBUG
#include <assert.h>
#include <iostream>


#include "exception.hh"
using namespace std;

/** SymbolType entumeration */
typedef enum{
  UNKNOWNTYPE,
    ERROR,
    IDENTIFIER,
    DEFINITION,
    PROCEDURE,OPERATOR,FUNCTION,QUFUNCTION,EXTERNOPERATOR,EXTERNQUFUNCTION,
    VARIABLE,
    CONST,
    REGSIZE,
    POWER,UNARYMINUS,MULTIPLICATION,DIVISION,MODULUS,ADDICTION,SUBSTRACTION,
    CONCATENATION,
    EQUAL,NEQUAL,LESS,LESSOREQ,GREATER,GREATEROREQ,NOT,AND,OR,XOR,
    BOOLEAN,
    INTEGER,REAL,COMPLEX,
    STRING,
    QUREG,QUVOID,QUCONST,QUSCRATCH,
    ASSIGNMENT,SFANOUT,SSWAP,WHILE,FOR,IFELSE,RETURN,INPUT,PRINT,EXIT,
    MEASURE,RESET,DUMP,LOAD,SAVE,SHELL
    }
SymbolType;

typedef SymbolType ExprType;

typedef enum {NORANGE,FROMTO,FROMN} RegRangeType;


#endif
