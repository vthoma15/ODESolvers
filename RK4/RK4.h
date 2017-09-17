#include<valarray>
#include<cmath>


using std::valarray;

class FuncEval
{
public:
  FuncEval(unsigned nVariables, const valarray<float>& values);
  unsigned nVars() { return m_nVariables; }
  void eval(float t, const valarray<float>& y, valarray<float>& dydt);
  
private:
  unsigned m_nVariables;
  valarray<float> m_coeff;
  
};


class RK4Solver
{
public:
  RK4Solver(FuncEval& fEval, float t0, float dt, const valarray<float>& Y0);
  
  void step();
  void stepTo(double tend);
  
  
private:
  FuncEval& m_funcEval;
  valarray<float> m_y0, m_y;
  float m_time, m_dt;
  unsigned m_nVars;
  
  
};

/*
 
class MyClass
{
  MyClass(int data) : m_data(data) {}
  
  int getData() {return m_data; } // This is a getter
  void setData(int newValue) {m_data = newValue;}
  
private:
  int m_data;
};

int main()
{
  MyClass object(67);
  
  if(object.data() == 67)
    {}
  
}

*/
