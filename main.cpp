#include "generator.h"
#include "quadtree.h"

int main()
{
  std::vector<double> vec;

  generator gen(0,10000);
	for(int i = 0; i < 20; i++)
	{
		vec.push_back(gen()/100.0);
		std::cout << vec[i] << std::endl;
	}

  quadtree<double> qt;

/*  qt.insert(std::pair<double,double>(-1.0,1.0),999.99);  
  qt.insert(std::pair<double,double>(-1.0,-1.0),999.98);  
  qt.insert(std::pair<double,double>(1.0,1.0),999.97);  
  qt.insert(std::pair<double,double>(1.0,-1.0),999.96);  
	qt.insert(std::pair<double,double>(-0.4,0.4),999.95);
	qt.insert(std::pair<double,double>(-0.5,-0.5),999.94);
	qt.insert(std::pair<double,double>(0.4,0.4),999.93);
	qt.insert(std::pair<double,double>(0.4,-0.4),999.92);
*/

/*

	qt.insert(std::pair<double,double>(2.0, 2.0),1.1);
	qt.insert(std::pair<double,double>(7.0,7.0),2.2);
	qt.insert(std::pair<double,double>(1.0,1.0),3.3);
	qt.insert(std::pair<double,double>(20.0,20.0),4.4);
	qt.insert(std::pair<double,double>(0.5, 0.5),5.5);
*/

//	for(int j = 0; j < 20; j++)
//	{
//		for(int k = 19; k >= 0; k--)
//		{
	int j = 0, k = 19; 
	while(j < 5) //&& k >= 0)
	{
		qt.insert(std::pair<double,double>(vec[j],vec[k]),((j+1.0) + ((j+1.0)/10)));
		j++;
		k--;
	}
//		}
//	}

  qt.inOrder();

  return 0;
}
