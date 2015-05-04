#ifndef QUADTREE_H_
#define QUADTREE_H_

#include <iostream>
#include <utility>
#include <algorithm>
#include <cmath>
#include "node.h"

template <class T>
class quadtree
{
 public:
  quadtree(unsigned int bukkitSize = 1):bucketSize(bukkitSize){}
  ~quadtree();
  void destroy(node<T>* nd);
  void insert(std::pair<double,T> item);
  template <class U>
  friend std::ostream& operator<<(std::ostream &out,quadtree<U> &hp);
  
 private:
  unsigned int bucketSize;
  node<T> *root;
};

#include "quadtree.cpp"

#endif
