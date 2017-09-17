#include "RK4.h"


FuncEval::FuncEval(unsigned nVariables, const valarray<float>& values)
: m_coeff(values) {}


void FuncEval::eval(float t, const valarray<float>& y, valarray<float>& dydt)
{
  for(unsigned i = 0; i < m_nVariables; ++i)
    dydt[i] = m_coeff[i]*y[i];
  
  return;
}


RK4Solver::RK4Solver(FuncEval& fEval, float t0, float dt, const valarray<float>& Y0)
: m_funcEval(fEval), m_y0(Y0), m_y(Y0), m_time(t0), m_dt(dt), m_nVars(fEval.nVars())
{ }

void RK4Solver::step()
{
  double tplusHalf = m_time + m_dt/2;
  valarray<float> k1(m_nVars),k2(m_nVars),k3(m_nVars),k4(m_nVars);
  valarray<float> y2(m_nVars),y3(m_nVars),y4(m_nVars);
  
  m_funcEval.eval(m_time, m_y, k1);
  
  for(unsigned i = 0; i < m_nVars; ++i)
    y2[i] = m_y[i] + k1[i]*m_dt/2;
  
  
  m_funcEval.eval(tplusHalf, y2, k2);
  
  for(unsigned i = 0; i < m_nVars; ++i)
    y3[i] = m_y[i] + k2[i]*m_dt/2;
  
  m_funcEval.eval(tplusHalf, y3, k3);
  
  for(unsigned i = 0; i < m_nVars; ++i)
    y4[i] = m_y[i] + k3[i]*m_dt;
  
  m_funcEval.eval(m_time+m_dt, y4, k4);
  
  for(unsigned i = 0; i < m_nVars; ++i)
    m_y[i] = m_dt/6 *( k1[i] + 2*k2[i] + 2*k3[i] + k4[i]);
  
  
  return;
}


void RK4Solver::stepTo(double tend)
{
  
  
  
  return;
}
