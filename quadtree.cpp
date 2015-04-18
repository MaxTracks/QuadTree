#include "quadtree.h"

template<class T>
quadtree::~quadtree()
{
  destroy(root);
  delete root;
}

template <class T>
void quadtree<T>::insert(std::pair<double,T> item)
{
  node<T>* nn = new node(item);

  if(root == nullptr))
  {
    root = nn;
  } else {
    node<T>* tmp = root;

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
void quadtree::destroy(node<T>* nd)
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
std::ostream& operator<<(std::ostream &out,quadtree<U> &hp)
{

  return out;
}
