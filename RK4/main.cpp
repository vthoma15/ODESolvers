//
//  main.cpp
//  RK4
//
//  Created by Vaughan Thomas on 9/17/17.
//  Copyright © 2017 Vaughan Thomas. All rights reserved.
//

#include "ODESolvers.h"
#include "Oscillators.h"
#include "DataLogger.h"


int main(int argc, const char * argv[])
{
  double tend  = 7.3;
  double mass = 30;
  double constant = 30;
  double dt = .01;
  string filename("/Users/vaughan/Dropbox/SEG/Jakir/RK4/Results/UndampedOscillator.csv");
  valarray<double> Y(2);
  
  Y[0] = 1;
  Y[1] = 0;
  
  UndampedOscillator spring(constant,mass);
  EulerSolver integrator(spring,0,dt,Y);
  DataLogger datalog(spring);
  
  // Record initial conditions
  datalog.addData(integrator.getTime(), integrator.getSolution() );
  
  // Integration loop
  do
  {
    std::cout << "Time: " << integrator.getTime() << std::endl;

    integrator.step();
    datalog.addData(integrator.getTime(), integrator.getSolution() );
    
  } while(integrator.getTime() < tend);
  
  Y = integrator.getSolution();
  std::cout << "Tend: " << integrator.getTime() << std::endl;
  std::cout << "[" << Y[0] << ',' << Y[1] << "]\n";
  datalog.saveDataToFile(filename);
  std::cout << "Data saved to file: " << filename << std::endl;
  
  return 0;
}

