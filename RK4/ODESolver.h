//
//  Solver.h
//  RK4
//
//  Created by Vaughan Thomas on 10/7/17.
//  Copyright © 2017 Vaughan Thomas. All rights reserved.
//

#ifndef Solver_h
#define Solver_h

#include<valarray>

using std::valarray;

class FuncEval
{
  public:
    FuncEval(unsigned nVariables) : m_nVariables(nVariables) {}
    unsigned nVars() { return m_nVariables; }
    virtual void eval(float t, const valarray<float>& y, valarray<float>& dydt) = 0;
  
  protected:
    unsigned m_nVariables;
};

class ODESolver
{
  public:
    ODESolver(FuncEval& fEval, float t0, const valarray<float>& Y0)
  : m_nVars(fEval.nVars()), m_time(t0), m_y(Y0), m_dydt(fEval) { }
    virtual void step() = 0;
    virtual void stepTo() = 0;
  
  protected:
    unsigned m_nVars;
    float m_time;
    FuncEval& m_dydt;
    valarray<float> m_y;
};


#endif /* Solver_h */
