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

using std::string;
using std::vector;
using std::ofstream;

typedef std::valarray<double> dVector;


class DataLogger
{
public:
  DataLogger(unsigned dimension);
  
  void addData(double t, const dVector& y);
  void saveDataToFile(string filename) const;
  
private:
  unsigned m_nVars;
  vector<double> m_time;
  vector<dVector> m_data;
  
};

#endif /* DataLogger_h */
