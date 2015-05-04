#include "generator.h"
#include "quadtree.h"

int main()
{
  std::vector<double> vec;

  generator gen(-1000000,1000000);
  generator mult(1,5);

  quadtree<int> qt;

  for(int i=0;i<10000;i++)
  {
    vec.push_back(double(gen()) / (double(mult()) * 10.0));
  }

  

  return 0;
}
