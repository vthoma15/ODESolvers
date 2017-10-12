#include "Utilities.h"

valarray<double> operator+(const valarray<double>& vec1,const valarray<double>& vec2)
{
  valarray<double> result(vec1.size() );
    
    for(unsigned i = 0; i < vec1.size(); ++i)
      result[i] = vec1[i] + vec2[i];

  return result;
}

valarray<double> operator*(double factor, const valarray<double>& vec)
{
  valarray<double> result(vec.size() );
    
    for(unsigned i = 0; i < vec.size(); ++i)
      result[i] = vec[i] * factor;

  return result;
}

valarray<double> operator*(const valarray<double>& vec, double factor)
{
  valarray<double> result(vec.size() );
    
    for(unsigned i = 0; i < vec.size(); ++i)
      result[i] = vec[i] * factor;

  return result;
}

valarray<double> operator/(const valarray<double>& vec, double divisor)
{
  valarray<double> result(vec.size() );
    
    for(unsigned i = 0; i < vec.size(); ++i)
      result[i] = vec[i] / divisor;

  return result;
}
