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
    node<T>* tmp = root;

    //if leaf check bucketSize
    //  if less than bucketsize add
    //  else split and insert
    //else determine quedrent to access 
  }
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
