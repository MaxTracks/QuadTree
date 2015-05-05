#include "generator.h"
#include "quadtree.h"

int main()
{
  std::vector<double> vec;

  generator gen(-1000000,1000000);
  generator mult(1,5);

  quadtree<double> qt;

  qt.insert(std::pair<double,double>(-1.0,1.0),999.99);  
  qt.insert(std::pair<double,double>(-1.0,-1.0),999.98);  
  qt.insert(std::pair<double,double>(1.0,1.0),999.97);  
  qt.insert(std::pair<double,double>(1.0,-1.0),999.96);  

  qt.inOrder();

/*  for(int i=0;i<10000;i++)
  {
    vec.push_back(double(gen()) / (double(mult()) * 10.0));
  }
*/
  

  return 0;
}
