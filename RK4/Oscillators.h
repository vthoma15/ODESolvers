//
//  Oscillators.hpp
//  RK4
//
//  Created by Vaughan Thomas on 10/9/17.
//  Copyright © 2017 Vaughan Thomas. All rights reserved.
//

#ifndef Oscillators_h
#define Oscillators_h

#include "ODESolvers.h"

class UndampedOscillator : public ODE
{
public:
  UndampedOscillator(double mass, double springConstant);
  void dydt(double t, const dVector& y, dVector& dydt);
private:
  double m_k;      // Restoring constant
  double m_mass;   // Mass
};

class DampedOscillator : public ODE
{
public:
  DampedOscillator(double mass, double springConstant, double dampingCoefficient);
  void dydt(double t, const dVector& y, dVector& dydt);
private:
  double m_k;                     // Restoring constant
  double m_mass;                  // Mass
  double m_dampingCoefficient;    // Damping coefficient
};
#endif /* Oscillators_h */
