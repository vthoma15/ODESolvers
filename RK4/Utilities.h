#include <valarray>

using std::valarray;

valarray<double> operator+(const valarray<double>& vec1,const valarray<double>& vec2);
valarray<double> operator*(double factor, const valarray<double>& vec);
valarray<double> operator*(const valarray<double>& vec, double factor);
valarray<double> operator/(const valarray<double>& vec, double divisor);
