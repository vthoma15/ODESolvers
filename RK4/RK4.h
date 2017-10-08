#include<valarray>
#include<cmath>

#include "ODESolver.h"


 
using std::valarray;




class RK4Solver : public ODESolver
{
public:
  // Constructor
  RK4Solver(FuncEval& fEval, float t0, float dt, const valarray<float>& Y0);
  
  // Inherited virtual functions from base class 'ODESolver'
  void step();
  void stepTo(double tend);
  
private:
  float m_dt;     // Time step for fixed time step solver
};


