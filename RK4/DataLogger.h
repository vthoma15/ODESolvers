//
//  DataLogger.hpp
//  RK4
//
//  Created by Vaughan Thomas on 10/8/17.
//  Copyright © 2017 Vaughan Thomas. All rights reserved.
//

#ifndef DataLogger_h
#define DataLogger_h

#include <iostream>
#include <fstream>
#include <vector>
#include <valarray>
#include <string>

#include "ODESolvers.h"

using std::string;
using std::vector;
using std::valarray;
using std::ofstream;

class DataLogger
{
public:
  DataLogger(const FuncEval& fEval);
  
  void addData(float t, const valarray<float>& y);
  void saveDataToFile(string filename) const;
  
private:
  unsigned m_nVars;
  vector<float> m_time;
  vector<valarray<float> > m_data;
  
};

#endif /* DataLogger_h */
