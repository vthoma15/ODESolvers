#include "ODESolvers.h"

EulerSolver::EulerSolver(FuncEval& fEval, double t0, double dt, const valarray<double>& Y0)
: ODESolver(fEval, t0, Y0), m_dt(dt)
{ }

void EulerSolver::step()
{
  valarray<double> ydot(m_nVars);
  
  m_dydt.eval(m_time, m_y, ydot);
  for(unsigned i = 0; i < m_nVars; ++i)
    m_y[i] += m_dt * ydot[i];
  
  m_time += m_dt;
  return;
}

void EulerSolver::stepTo(double tend)
{
  
  
  
  return;
}

RK4Solver::RK4Solver(FuncEval& fEval, double t0, double dt, const valarray<double>& Y0)
: ODESolver(fEval, t0, Y0), m_dt(dt)
{ }

void RK4Solver::step()
{
  double tplusHalf = m_time + m_dt/2;
  valarray<double> k1(m_nVars),k2(m_nVars),k3(m_nVars),k4(m_nVars);
  valarray<double> y2(m_nVars),y3(m_nVars),y4(m_nVars),ydot(m_nVars);
  
  m_dydt.eval(m_time, m_y, k1);
  
  for(unsigned i = 0; i < m_nVars; ++i)
    y2[i] = m_y[i] + k1[i]*m_dt/2;
  
  
  m_dydt.eval(tplusHalf, y2, k2);
  
  for(unsigned i = 0; i < m_nVars; ++i)
    y3[i] = m_y[i] + k2[i]*m_dt/2;
  
  m_dydt.eval(tplusHalf, y3, k3);
  
  for(unsigned i = 0; i < m_nVars; ++i)
    y4[i] = m_y[i] + k3[i]*m_dt;
  
  m_dydt.eval(m_time+m_dt, y4, k4);
  
  for(unsigned i = 0; i < m_nVars; ++i)
    ydot = ( k1[i] + 2*k2[i] + 2*k3[i] + k4[i]) / 6;
  
  for(unsigned i = 0; i < m_nVars; ++i)
    m_y[i] += m_dt * ydot[i];
  
  m_time += m_dt;
  
  return;
}

void RK4Solver::stepTo(double tend)
{
  
  
  
  return;
}
