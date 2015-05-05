#ifndef QUADTREE_H_
#define QUADTREE_H_

#include <iostream>
#include <utility>
#include <algorithm>
#include <cmath>
#include <limits>
#include "node.h"

template <class T>
class quadtree
{
 public:
  quadtree(unsigned int bukkitSize = 1):bucketSize(bukkitSize){};
  ~quadtree();
  void destroy(node<T>* nd);
  void inOrder();
  void insert(std::pair<double,double> location,T item);
  template <class U>
  friend std::ostream& operator<<(std::ostream &out,quadtree<U> &hp);
  
 private:
  void split(node<T> *nd);
  void inOrder(node<T> *nd);
	void insert(node<T> *nd, std::pair<double,double> location,T item);

  unsigned int bucketSize;
  node<T> *root;
};

#include "quadtree.cpp"

#endif
