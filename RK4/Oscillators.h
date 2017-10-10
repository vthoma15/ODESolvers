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
  UndampedOscillator(float mass, float springConstant);
  void eval(float t, const valarray<float>& y, valarray<float>& dydt);
private:
  float m_k;      // Restoring constant
  float m_mass;   // Mass
};

class DampedOscillator : public FuncEval
{
public:
  DampedOscillator(float mass, float springConstant, float dampingCoefficient);
  void eval(float t, const valarray<float>& y, valarray<float>& dydt);
private:
  float m_k;                     // Restoring constant
  float m_mass;                  // Mass
  float m_dampingCoefficient;    // Damping coefficient
};
#endif /* Oscillators_h */
