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
	quadtree<double> del;
		
	int j = 0, k = 99; 
	while(j < 100)
	{
		qt.insert(std::pair<double,double>(vec[j],vec[k]),((j+1.0) + ((j+1.0)/10)+vec[j]));
		j++;
		k--;
	}

	std::cout << qt << std::endl; 

	del.insert(std::pair<double,double>(157.0, 139.0), 1.1);
	del.insert(std::pair<double,double>(-234.0, -111.0), 2.2);
	del.insert(std::pair<double,double>(-132.2, 193.0), 3.3);
	del.insert(std::pair<double,double>(-111.0, -56.0), 4.4);
	del.insert(std::pair<double,double>(152.0, 140.0), 5.5);
	del.insert(std::pair<double,double>(160.0, 160.0), 6.6);
	del.insert(std::pair<double,double>(157.0, 173.0), 7.7);
	del.insert(std::pair<double,double>(157.0, 174.0), 8.8);
	
	std::cout << del << std::endl;

	std::pair<double,double> xy = std::make_pair(-234.0, -111.0);

	std::cout << del.deleteKey(xy) << std::endl;

	std::cout << del << std::endl;

	std::vector<std::pair<std::pair<double,double>, double> > testVector;
	testVector = del.searchRange(std::pair<double,double>(200.0, 200.0),std::pair<double,double>(150.0, 150.0));

  return 0;
}
