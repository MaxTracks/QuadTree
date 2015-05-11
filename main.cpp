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
	quadtree<double> del(1,0,500,500,0);

	del.insert(std::pair<double,double>(10.0, 15.0), 6.6);
  std::cout << "del.insert(std::pair<double,double>(10.0, 15.0), 6.6);" << std::endl;
	del.insert(std::pair<double,double>(15.0, 10.0), 5.5);
  std::cout << "del.insert(std::pair<double,double>(15.0, 10.0), 5.5);" << std::endl;
	del.insert(std::pair<double,double>(10.0, 10.0), 4.4);
  std::cout << "del.insert(std::pair<double,double>(10.0, 10.0), 4.4);" << std::endl;
	del.insert(std::pair<double,double>(5.0, 5.0), 3.3);
  std::cout << "del.insert(std::pair<double,double>(5.0, 5.0), 3.3);" << std::endl;

  std::vector<std::pair<std::pair<double,double>,double> > result;
  result = del.searchRange(std::pair<double,double>(0,500),std::pair<double,double>(500,0));

  std::cout << result.size() << std::endl;

  for(auto i:result){
    std::cout << "X:" << i.first.first  << " Y:" << i.first.second << " DATA:" << i.second << std::endl;
  }

  return 0;
}
