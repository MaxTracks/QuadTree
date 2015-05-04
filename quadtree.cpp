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
    root = nn;
  } else {
    node<T>* tmp = root;

    //if leaf add
    //
    //else determine quedrent to access 

    //figure out which quadrent to focus
    //while(1)
    //{
    //  if(tmp->first == nullptr 
    //   && tmp->second == nullptr 
    //   && tmp->third == nullptr 
    //   && tmp->fourth == nullptr) 
    //  {
    //   tmp = nn; 
    //   return; 
    //  }
    //  
    //  if()
    //  {
    //   tmp = tmp->first;
    //  } else if ()
    //  {
    //    tmp = tmp->second;
    //  } else if()
    //  {
    //    tmp = tmp->third;
    //  } else 
    //  {
    //   tmp = tmp->fourth;
    //  }
    //}
  }
}

template<class T>
void quadtree<T>::destroy(node<T>* nd)
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

template <class U>
std::ostream& operator<<(std::ostream &out,quadtree<U> &qt)
{

  return out;
}
