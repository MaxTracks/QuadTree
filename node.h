#ifndef NODE_H_
#define NODE_H_

template<class T>
struct node
{
  node* first;
  node* second;
  node* third;
  node* fourth;

  T* data;
  node():first(nullptr),second(nullptr),
    third(nullptr),fourth(nullptr),data(nullptr){}
};


#endif
