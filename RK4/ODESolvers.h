//
//  Solver.h
//  RK4
//
//  Created by Vaughan Thomas on 10/7/17.
//  Copyright © 2017 Vaughan Thomas. All rights reserved.
//

#ifndef ODESolvers_h
#define ODESolvers_h

#include<valarray>

using std::valarray;

class FuncEval
{
  public:
    FuncEval(unsigned nVariables) : m_nVariables(nVariables) {}
    unsigned nVars() const { return m_nVariables; }
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
  
  float getTime() { return m_time; }
  valarray<float> getSolution() {return m_y; }
  
  protected:
    unsigned m_nVars;
    float m_time;
    FuncEval& m_dydt;
    valarray<float> m_y;
};

class RK4Solver : public ODESolver
{
public:
  // Constructor
  RK4Solver(FuncEval& fEval, float t0, float dt, const valarray<float>& Y0);
  
  // Inherited virtual functions from base class 'ODESolver'
  void step();
  void stepTo(double tend);
  
private:
  float m_dt;     // Time step for fixed time step solver
};

#endif /* ODESolvers_h */
