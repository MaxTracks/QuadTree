#include "quadtree.h"

template<class T>
quadtree<T>::~quadtree()
{
	if(root != nullptr) destroy(root);
}

template <class T>
void quadtree<T>::insert(std::pair<double,double> location,T item)
{
	if(root == nullptr)
	{
    node<T> *nn = new node<T>();
    std::pair<std::pair<double,double>,T> data;
    data.first = location;
    data.second = item;
    nn->objects.push_back(data);

/*    nn->x.first = std::numeric_limits<double>::lowest();
    nn->x.second = std::numeric_limits<double>::max();
    nn->y.first = std::numeric_limits<double>::lowest();
    nn->y.second = std::numeric_limits<double>::max();
*/
		nn->x.first = 0.0;
    nn->x.second = 100.0;
    nn->y.first = 0.0;
    nn->y.second = 100.0;

    root = nn;
	}
	else
	{
		insert(root, location, item);
	}
}

template <class T>
void quadtree<T>::insert(node<T> *nd,std::pair<double,double> location,T item)
{
	if(nd->first == nullptr)
	{
		if(bucketSize == nd->objects.size())
		{
			split(nd);
			insert(nd, location, item);
		} else {
			std::pair<std::pair<double, double>, T> tmp;
			tmp.first.first = location.first;
      tmp.first.second = location.second;
      tmp.second = item;
			nd->objects.push_back(tmp);
		}
  } else {
		if(location.first <= ((nd->x.first + nd->x.second)/2.0))
		{
			if(location.second <= ((nd->y.first + nd->y.second)/2.0))
			{
				insert(nd->first, location, item);
			}
			else
			{
				insert(nd->third, location, item);
			}
		}
		else
		{
			if(location.second <= ((nd->y.first + nd->y.second)/2.0))
			{
				insert(nd->second, location, item);
			}
			else
			{
				insert(nd->fourth, location, item);
			}
		}
	}
}

template <class T>
void quadtree<T>::split(node<T> *nd)
{
  static unsigned int splitcount = 0;
  std::cout << "split count: " << splitcount++ << std::endl;
  nd->first = new node<T>();
  nd->second = new node<T>();
  nd->third = new node<T>();
  nd->fourth = new node<T>();

  nd->first->x.first = nd->x.first;
  nd->first->x.second = (nd->x.second + nd->x.first)/2.0;
  nd->first->y.first = nd->y.first;
  nd->first->y.second = (nd->y.second + nd->y.first)/2.0;

  nd->second->x.first = (nd->x.second + nd->x.first)/2.0;
  nd->second->x.second = nd->x.second;
  nd->second->y.first = nd->y.first;
  nd->second->y.second = (nd->y.second + nd->y.first)/2.0;

  nd->third->x.first = nd->x.first;
  nd->third->x.second = (nd->x.second + nd->x.first)/2.0;
  nd->third->y.first = (nd->x.second + nd->x.first)/2.0;
  nd->third->y.second = nd->y.second;

  nd->third->x.first = (nd->x.first + nd->x.second)/2.0;
  nd->third->x.second = nd->x.second;
  nd->fourth->y.first = (nd->x.second + nd->x.first)/2.0;
  nd->fourth->y.second = nd->y.second;

  for(auto i:nd->objects)
  {
    insert(nd,i.first,i.second);
  }

  nd->objects.clear();
}

template<class T>
void quadtree<T>::destroy(node<T> *nd)
{
	if(nd != nullptr)
	{
		destroy(nd->first);
		destroy(nd->second);
		destroy(nd->third);
		destroy(nd->fourth);
		delete nd;
	}
}

template <class T>
void quadtree<T>::inOrder()
{
  inOrder(root);
}

template <class T>
void quadtree<T>::inOrder(node<T> *nd)
{
  if(nd == nullptr) return;

  for(auto i:nd->objects)
  {
    std::cout << i.second << std::endl;
  }

  inOrder(nd->first);
  inOrder(nd->second);
  inOrder(nd->third);
  inOrder(nd->fourth);
}

template <class T>
bool quadtree<T>::deleteKey(std::pair<double,double> xy)
{
  if(root == nullptr) return false;
  node<T> *tmp = root;

  if(tmp->first != nullptr)
  {
    if(xy.first <= ((tmp->x.first + tmp->x.second)/2.0))
    {
      if(xy.second <= ((tmp->y.first + tmp->y.second)/2.0))
      {
        tmp = tmp->first;
      }
      else
      {
        tmp = tmp->third;
      }
    }
    else
    {
      if(xy.second <= ((tmp->y.first + tmp->y.second)/2.0))
      {
        tmp = tmp->second;
      }
      else
      {
        tmp = tmp->fourth;
      }
    }
  } else {
    for(int i=0;i<tmp->objects.size();i++)
    {
      if(tmp->objects[i].first == xy) 
      {
        tmp->objects.erase(tmp->objects.begin() + i);
        return true;
      }
    }
  }

  return false;
}

template <class T>
std::vector<std::pair<std::pair<double,double>,T> > quadtree<T>::searchRange(std::pair<double,double> start,std::pair<double,double> end)
{
  

}

template <class U>
std::ostream& operator<<(std::ostream &out,quadtree<U> &qt)
{
  qt.inOrder();
  return out;
}
