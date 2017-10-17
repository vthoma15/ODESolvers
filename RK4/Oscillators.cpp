//
//  Oscillators.cpp
//  RK4
//
//  Created by Vaughan Thomas on 10/9/17.
//  Copyright © 2017 Vaughan Thomas. All rights reserved.
//

#include "Oscillators.h"
UndampedOscillator::UndampedOscillator(double mass, double springConstant)
: ODE(2), m_k(springConstant), m_mass(mass)
{ }

void UndampedOscillator::dydt(double t, const dVector& y, dVector& dydt)
{
  dydt[0] = y[1];
  dydt[1] = -m_k * y[0] / m_mass;
  
  return;
}

DampedOscillator::DampedOscillator(double mass, double springConstant, double dampingCoefficient)
: ODE(2), m_k(springConstant), m_mass(mass), m_dampingCoefficient(dampingCoefficient)
{ }

void DampedOscillator::dydt(double t, const dVector& y, dVector& dydt)
{
  dydt[0] = y[1];
  dydt[1] = -(m_k * y[0] + m_dampingCoefficient * y[1])/ m_mass;
  
  return;
}
