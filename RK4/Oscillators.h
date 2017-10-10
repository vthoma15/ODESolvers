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

class UndampedOscillator : public FuncEval
{
public:
  UndampedOscillator(double mass, double springConstant);
  void eval(double t, const valarray<double>& y, valarray<double>& dydt);
private:
  double m_k;      // Restoring constant
  double m_mass;   // Mass
};

class DampedOscillator : public FuncEval
{
public:
  DampedOscillator(double mass, double springConstant, double dampingCoefficient);
  void eval(double t, const valarray<double>& y, valarray<double>& dydt);
private:
  double m_k;                     // Restoring constant
  double m_mass;                  // Mass
  double m_dampingCoefficient;    // Damping coefficient
};
#endif /* Oscillators_h */
