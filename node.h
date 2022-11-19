#ifndef _NODE_H_
#define _NODE_H_
#include <iostream>

template <typename T>
struct Node {
  T data;
  Node *next;

  Node(T x) : data(x), next(nullptr) {}
};

template <typename T>
std::ostream& operator<<(std::ostream &out, const Node<T> &a) {
  out << a.data;
  return out;
}
#endif //_NODE_H_