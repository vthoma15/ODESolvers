//
//  DataLogger.cpp
//  RK4
//
//  Created by Vaughan Thomas on 10/8/17.
//  Copyright © 2017 Vaughan Thomas. All rights reserved.
//

#include "DataLogger.h"

DataLogger::DataLogger(unsigned dimension) : m_nVars(dimension )
{
  m_time = vector<double>();
  m_data = vector<valarray<double> >();
}

void DataLogger::addData(double t, const valarray<double>& y)
{
  m_time.push_back(t);
  m_data.push_back(y);
  
  return;
}

void DataLogger::saveDataToFile(string filename) const
{
  const char c = ',';
  ofstream outfile(filename.c_str() );
  
  for(unsigned i = 0; i < m_time.size(); ++i) {
    outfile << m_time[i];
    valarray<double> vec = m_data[i];
    for(unsigned j = 0; j < m_nVars; ++j) {
      outfile << c << vec[j];
    }
    outfile << std::endl;
    
  }
  outfile.close();
  
  return;
}
