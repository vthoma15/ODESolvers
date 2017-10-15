#include "ODESolvers.h"


void ODESolver::stepTo(double tend)
{
    while(m_time < tend)
  {
    step();
    m_logger.addData(m_time,m_y);
  }
  
  return;
}

EulerSolver::EulerSolver(ODE& fEval, double t0, double dt, const valarray<double>& Y0)
: ODESolver(fEval, t0, dt, Y0)
{ }

void EulerSolver::step()
{
  valarray<double> ydot(m_nVars);
  
  m_ODE.dydt(m_time, m_y, ydot);
  for(unsigned i = 0; i < m_nVars; ++i)
    m_y[i] += m_dt * ydot[i];
  
  m_time += m_dt;
  return;
}

RK4Solver::RK4Solver(ODE& fEval, double t0, double dt, const valarray<double>& Y0)
: ODESolver(fEval, t0, dt, Y0)
{ }

void RK4Solver::step()
{
  double tplusHalf = m_time + m_dt/2;
  valarray<double> k1(m_nVars),k2(m_nVars),k3(m_nVars),k4(m_nVars);
  valarray<double> y1(m_nVars),y2(m_nVars),y3(m_nVars),ydot(m_nVars);
  
  m_ODE.dydt(m_time, m_y, k1);
  y1 = m_y + 0.5*k1*m_dt;
  
  m_ODE.dydt(tplusHalf, y1, k2);
  y2 = m_y + 0.5*k2*m_dt;  

  m_ODE.dydt(m_time + m_dt, y2, k3);
  y3 = y2 + k3*m_dt;
  
  m_ODE.dydt(m_time+m_dt, y3, k4);
  
  for(unsigned i = 0; i < m_nVars; ++i)
    ydot = (k1 + 2*k2 + 2*k3 + k4) / 6;
  
  for(unsigned i = 0; i < m_nVars; ++i)
    m_y[i] += m_dt * ydot[i];
  
  m_time += m_dt;
  
  return;
}


