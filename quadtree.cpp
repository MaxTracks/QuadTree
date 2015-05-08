#include "quadtree.h"

template<class T>
quadtree<T>::~quadtree()
{
	if(root != nullptr) destroy(root);
}

template <class T>
void quadtree<T>::insert(std::pair<double,double> location,T item)
{
  insert(root,location,item);
}

template <class T>
void quadtree<T>::insert(node<T> *tmp, std::pair<double,double> location,T item)
{
	if(root == nullptr)
	{
    node<T> *nn = new node<T>();
    std::pair<std::pair<double,double>,T> data;
    data.first = location;
    data.second = item;
    nn->objects.push_back(data);

    nn->x.first = std::numeric_limits<double>::lowest();
    nn->x.second = std::numeric_limits<double>::max();
    nn->y.first = std::numeric_limits<double>::lowest();
    nn->y.second = std::numeric_limits<double>::max();

    root = nn;
	}
	else
	{
    while(1)
    {
      if(tmp->first == nullptr)
      {
        if(bucketSize == tmp->objects.size())
        {
          if(collision(tmp,location))return;
          split(tmp);
        } else {
          std::pair<std::pair<double, double>, T> tmppair;
          tmppair.first.first = location.first;
          tmppair.first.second = location.second;
          tmppair.second = item;
          tmp->objects.push_back(tmppair);
          return;
        }
      } else {
        if(location.first <= ((tmp->x.first + tmp->x.second)/2.0))
        {
          if(location.second <= ((tmp->y.first + tmp->y.second)/2.0))
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
          if(location.second <= ((tmp->y.first + tmp->y.second)/2.0))
          {
            tmp = tmp->second;
          }
          else
          {
            tmp = tmp->fourth;
          }
        }
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
  nd->first->x.second = (nd->x.second + nd->x.first)/2.0;
  nd->first->y.first = nd->y.first;
  nd->first->y.second = (nd->y.second + nd->y.first)/2.0;

  nd->second->x.first = (nd->x.second + nd->x.first)/2.0;
  nd->second->x.second = nd->x.second;
  nd->second->y.first = nd->y.first;
  nd->second->y.second = (nd->y.second + nd->y.first)/2.0;

  nd->third->x.second = nd->x.first;
  nd->third->x.first = (nd->x.second + nd->x.first)/2.0;
  nd->third->y.first = (nd->y.second + nd->y.first)/2.0;
  nd->third->y.second = nd->y.second;

  nd->third->x.first = (nd->x.first + nd->x.second)/2.0;
  nd->third->x.second = nd->x.second;
  nd->fourth->y.first = (nd->y.second + nd->y.first)/2.0;
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

template <class T>
bool quadtree<T>::collision(node<T> *nd,std::pair<double,double> location)
{
  for(int i=0;i<nd->objects.size();i++)
  {
    if(nd->objects[i].first.first == location.first 
        && nd->objects[i].first.second == location.second) 
      return true;
  }
  return false;
}
