#include "Utilities.h"

dVector operator+(const dVector& vec1,const dVector& vec2)
{
  dVector result(vec1.size() );
    
    for(unsigned i = 0; i < vec1.size(); ++i)
      result[i] = vec1[i] + vec2[i];

  return result;
}

dVector operator*(double factor, const dVector& vec)
{
  dVector result(vec.size() );
    
    for(unsigned i = 0; i < vec.size(); ++i)
      result[i] = vec[i] * factor;

  return result;
}

dVector operator*(const dVector& vec, double factor)
{
  dVector result(vec.size() );
    
    for(unsigned i = 0; i < vec.size(); ++i)
      result[i] = vec[i] * factor;

  return result;
}

dVector operator/(const dVector& vec, double divisor)
{
  dVector result(vec.size() );
    
    for(unsigned i = 0; i < vec.size(); ++i)
      result[i] = vec[i] / divisor;

  return result;
}
