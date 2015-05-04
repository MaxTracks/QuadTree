#include "quadtree.h"

template<class T>
quadtree<T>::~quadtree()
{
  destroy(root);
  delete root;
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
    nn->object.add_back(data);
    nn->x.first = std::numeric_limits<double>::min();
    nn->x.second = std::numeric_limits<double>::max();
    nn->y.first = std::numeric_limits<double>::min();
    nn->y.second = std::numeric_limits<double>::max();
    root = nn;
	} else {
		insert(root, location, item);
	}
}

template <class T>
void quadtree<T>::insert(node<T> *nd,std::pair<double,double> location,T item)
{
	if(nd->first == nullptr)
	{
		if(bucketSize == nd->object.size())
		{
			split();
			insert(nd, location, item);
		} else {
			nd->object.push_back(std::pair<std::pair<double,double>, T>(location,item));
		}
  } else {
		if(location.first <= ((x.first + x.second)/2))
		{
			if(location.second <= ((y.first + y.second)/2))
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
			if(location.second <= ((y.first + y.second)/2))
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
  nd->first = new node<T>();
  nd->second = new node<T>();
  nd->third = new node<T>();
  nd->fourth = new node<T>();

  nd->first->x.first = nd->x.first;
  nd->first->x.second = (nd->x.second + nd->x.first)/2;
  nd->first->y.first = nd->y.first;
  nd->first->y.second = (nd->y.second + nd->y.first)/2;

  nd->second->x.first = (nd->x.second + nd->x.first)/2;
  nd->secdon->x.second = nd->x.second;

  for(auto i:objects)
  {
    insert(nd,i.first,i.second);
  }

  nd->object.clear();
  
}

template<class T>
void quadtree<T>::destroy(node<T> *nd)
{
  if(nd->first != nullptr)
  {
    destroy(nd->first);
    delete nd->first;
  }

  if(nd->second != nullptr)
  {
    destroy(nd->second);
    delete nd->second;
  }

  if(nd->third != nullptr)
  {
    destroy(nd->third);
    delete nd->third;
  }

  if(nd->fourth != nullptr)
  {
    destroy(nd->fourth);
    delete nd->fourth;
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



template <class U>
std::ostream& operator<<(std::ostream &out,quadtree<U> &qt)
{

  return out;
}
