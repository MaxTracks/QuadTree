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
  quadtree(unsigned int bukkitSize = 1):bucketSize(bukkitSize),root(nullptr){};
  ~quadtree();
  void destroy(node<T>* nd);
  void inOrder();
  void insert(std::pair<double,double> location,T item);
  bool deleteKey(std::pair<double,double> xy);
  std::vector<std::pair<std::pair<double,double>,T> > searchRange(std::pair<double,double> start,
      std::pair<double,double> end);
  template <class U>
  friend std::ostream& operator<<(std::ostream &out,quadtree<U> &hp);
  
 private:
  bool collision(node<T> *nd,std::pair<double,double> location);
  void split(node<T> *nd);
  void inOrder(node<T> *nd);
  void insert(node<T> *tmp, std::pair<double,double> location, T item);

  unsigned int bucketSize;
  node<T> *root;
};

#include "quadtree.cpp"

#endif
