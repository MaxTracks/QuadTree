#ifndef NODE_H_
#define NODE_H_

template<class T>
class node
{
  node():first(nullptr),second(nullptr),third(nullptr),fourth(nullptr){}
  node(std::pair<double,T> item):first(nullptr),second(nullptr),
    third(nullptr),fourth(nullptr),data(item){}

  node* first;
  node* second;
  node* third;
  node* fourth;

  std::vector<std::pair<std::pair<double,double>,T> > objects;
};

#endif
