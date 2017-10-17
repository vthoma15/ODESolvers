//
//  main.cpp
//  RK4
//
//  Created by Vaughan Thomas on 9/17/17.
//  Copyright © 2017 Vaughan Thomas. All rights reserved.
//

#include <cmath>

#include "ODESolvers.h"
#include "Oscillators.h"
#include "DataLogger.h"


int main(int argc, const char * argv[])
{
  const double pi = acos(-1.0);
  double tend  = 2*pi;
  double mass = 30;
  double constant = 30;
  double dt = .01;
  string EulerFilename("/Users/vaughan/Dropbox/SEG/Jakir/RK4/Results/UndampedOscillator_Euler.csv");
  string RK4Filename("/Users/vaughan/Dropbox/SEG/Jakir/RK4/Results/UndampedOscillator_RK4.csv");
  dVector Y(2);
  
  Y[0] = 1;
  Y[1] = 0;
  
  UndampedOscillator spring(constant,mass);
  EulerSolver euler(spring,0,dt,Y);
  RK4Solver rk4(spring,0,dt,Y);

  
  // Integration loop
  euler.stepTo(tend);
  rk4.stepTo(tend);
  
  Y = euler.getSolution();
  std::cout << "Euler Solution:\n\tTend: " << euler.getTime() << std::endl;
  std::cout << "\t[" << Y[0] << ',' << Y[1] << "]\n";
  euler.saveDataToFile(EulerFilename);
  std::cout << "Data from Euler integration saved to file: " << EulerFilename << std::endl;
  
  Y = rk4.getSolution();
  std::cout << "Euler Solution:\n\tTend: " << rk4.getTime() << std::endl;
  std::cout << "\t[" << Y[0] << ',' << Y[1] << "]\n";
  rk4.saveDataToFile(RK4Filename);
  std::cout << "Data from Euler integration saved to file: " << RK4Filename << std::endl;
  
  return 0;
}

