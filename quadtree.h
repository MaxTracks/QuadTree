#ifndef QUADTREE_H_
#define QUADTREE_H_

#include <iostream>
#include <utility>
#include <algorithm>
#include <cmath>

template <class T>
class quadtree
{
 public:
  heap():currentSize(0){}
  void insert(T item);
  unsigned int size(){return currentSize;}
  template <class U>
  friend std::ostream& operator<<(std::ostream &out,heap<U> &hp);
  
 private:
  unsigned int currentSize;
  node* root;
};

#include "quadtree.cpp"

#endif
