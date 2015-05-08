#include "generator.h"
#include "quadtree.h"
#include <utility>

int main()
{
  std::vector<double> vec;

  generator gen(-1000000,1000000);
 
	for(int i = 0; i < 100; i++)
	{
		vec.push_back(gen()/100.0);
	}

  quadtree<double> qt;
	
	int j = 0, k = 99; 
	while(j < 100) //&& k >= 0)
	{
		qt.insert(std::pair<double,double>(vec[j],vec[k]),((j+1.0) + ((j+1.0)/10)+vec[j]));
		j++;
		k--;
	}

  qt.inOrder();

  return 0;
}
