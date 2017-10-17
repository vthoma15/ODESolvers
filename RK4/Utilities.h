#include <valarray>

typedef std::valarray<double> dVector;

dVector operator+(const dVector& vec1,const dVector& vec2);
dVector operator*(double factor, const dVector& vec);
dVector operator*(const dVector& vec, double factor);
dVector operator/(const dVector& vec, double divisor);
