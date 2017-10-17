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
#include "DataLogger.h"

class ODE
{
  public:
    ODE(unsigned nVariables) : m_nVariables(nVariables) {}
    unsigned nVars() const { return m_nVariables; }
    virtual void dydt(double t, const dVector& y, dVector& dydt) = 0;
  
  protected:
    unsigned m_nVariables;
};

class ODESolver
{
  public:
    ODESolver(ODE& fEval, double t0, double dt, const dVector& Y0)
  : m_nVars(fEval.nVars()), m_time(t0), m_dt(dt), m_y(Y0), m_ODE(fEval), m_logger(fEval.nVars())
  { m_logger.addData(m_time,m_y); }
  
  // Integration Functions
  virtual void step() = 0;
  void stepTo(double tend);
  
  // Accessors
  double getTime() { return m_time; }
  dVector getSolution() {return m_y; }
  
  void saveDataToFile(string filename) { m_logger.saveDataToFile(filename); }
  
  protected:
    unsigned m_nVars;
    double m_time, m_dt;
    dVector m_y;
    ODE& m_ODE;
    DataLogger m_logger;
};

class EulerSolver : public ODESolver
{
public:
  // Constructor
  EulerSolver(ODE& fEval, double t0, double dt, const dVector& Y0);
  
  // Inherited virtual functions from base class 'ODESolver'
  void step();
  
};

class RK4Solver : public ODESolver
{
public:
  // Constructor
  RK4Solver(ODE& fEval, double t0, double dt, const dVector& Y0);
  
  // Inherited virtual functions from base class 'ODESolver'
 void step();
  
private:

};

#endif /* ODESolvers_h */
