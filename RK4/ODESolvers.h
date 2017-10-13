//
//  Solver.h
//  RK4
//
//  Created by Vaughan Thomas on 10/7/17.
//  Copyright © 2017 Vaughan Thomas. All rights reserved.
//

#ifndef ODESolvers_h
#define ODESolvers_h

#include "Utilities.h"
enum solverType {Euler, RK4};

class FuncEval
{
  public:
    FuncEval(unsigned nVariables) : m_nVariables(nVariables) {}
    unsigned nVars() const { return m_nVariables; }
    virtual void eval(double t, const valarray<double>& y, valarray<double>& dydt) = 0;
  
  protected:
    unsigned m_nVariables;
};

class ODESolver
{
  public:
    ODESolver(FuncEval& fEval, double t0, double dt, const valarray<double>& Y0)
  : m_nVars(fEval.nVars()), m_time(t0), m_dt(dt), m_y(Y0), m_dydt(fEval) { }
    virtual void step() = 0;
  
  double getTime() { return m_time; }
  valarray<double> getSolution() {return m_y; }
  
  protected:
    unsigned m_nVars;
    double m_time, m_dt;
    FuncEval& m_dydt;
    valarray<double> m_y;
};

class EulerSolver : public ODESolver
{
public:
  // Constructor
  EulerSolver(FuncEval& fEval, double t0, double dt, const valarray<double>& Y0);
  
  // Inherited virtual functions from base class 'ODESolver'
  void step();
  
};

class RK4Solver : public ODESolver
{
public:
  // Constructor
  RK4Solver(FuncEval& fEval, double t0, double dt, const valarray<double>& Y0);
  
  // Inherited virtual functions from base class 'ODESolver'
 void step();
  
private:

};

#endif /* ODESolvers_h */
