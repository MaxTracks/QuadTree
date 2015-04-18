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
  quadtree():currentSize(0){}
  ~quadtree();
  destroy(node *nd);
  void insert(std::pair<double,T> item);
  unsigned int size(){return currentSize;}
  template <class U>
  friend std::ostream& operator<<(std::ostream &out,quadtree<U> &hp);
  
 private:
  unsigned int currentSize;
  node* root;
};

#include "quadtree.cpp"

#endif
