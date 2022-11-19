#ifndef _LIST_H_
#define _LIST_H_
#include "node.h"

template <typename T>
class List {
  Node<T> *head;
public:
  List() { head = nullptr; }
  void push_front(const T &x);
  void push_back(const T &x);
  bool is_empty() const;
  template <typename Type>friend std::ostream& operator<<(std::ostream &out, const List<Type> &l);
};

// <<
template <typename T>
std::ostream& operator<<(std::ostream &out, const List<T> &l) {
  Node<T> *curr = l.head;
  while (curr != nullptr) {
    out << *curr << " -> ";
    curr = curr->next;
  }
  out << "x";
  return out;
}

// check if empty
template <typename T>
bool List<T>::is_empty() const {
  return head == nullptr;
}

// add an element in the front of the list
template <typename T>
void List<T>::push_front(const T &x) {
  Node<T> *new_node = new Node<T>(x);
  new_node->next = head;
  head = new_node;
}

// add an element in the back of the list
template <typename T>
void List<T>::push_back(const T &x) {
  if (is_empty()) {
    head = new Node<T>(x);
    return;
  }
  
  Node<T> *curr = head;
  while (curr->next != nullptr) 
    curr = curr->next;
  curr->next = new Node<T>(x);
}

#endif //_LIST_H_