#ifndef _LIST_H_
#define _LIST_H_
#include "node.h"

template <typename T> class List {
  Node<T> *head;
  int length; // for merge_sort
public:
  List() : head(nullptr), length(0) {}
  ~List() { clear_list(); }
  Node<T> *get_head() const { return head; }
  int get_length() const { return length; }
  void push_front(const T &x);
  void push_back(const T &x);
  bool is_empty() const;
  void pop_front();
  void clear_list() {
    while (!is_empty())
      pop_front();
    head = nullptr;
    length = 0;
  }
  void pop_back();
  void push_before(const T &x, const Node<T> *node);
  void pop_by_pointer(const Node<T> *node);
  const Node<T> *find(const T &value) const;
  void pop_by_value(const T &value);
  List<T> &operator+=(List<T> &other);
  void sort();

  template <typename Type> friend
  List<Type> &merge_sorted(List<Type> &first, List<Type> &second);

  template <typename Type> friend
  void split_list(List<Type> &list, List<Type> &second);

  template <typename Type> friend
  List<Type> operator+(List<Type> &first, List<Type> &second);
};

// merge two sorted lists
template <typename T>
List<T> &merge_sorted(List<T> &first, List<T> &second) {
  if (first.is_empty()) {
    first.head = second.head;
    first.length = second.length;
    second.head = nullptr;
    second.length = 0;
    return first;
  }
  if (second.is_empty()) {
    return first;
  }
  Node<T> *curr_1 = first.get_head();
  Node<T> *curr_2 = second.get_head();
  Node<T> *result_head = nullptr;
  if (curr_1->data < curr_2->data) {
    result_head = curr_1;
    curr_1 = curr_1->next;
  } else {
    result_head = curr_2;
    curr_2 = curr_2->next;
  }
  Node<T> *curr_res = result_head;
  while (curr_1 != nullptr && curr_2 != nullptr) {
    if (curr_1->data < curr_2->data) {
      curr_res->next = curr_1;
      curr_1 = curr_1->next;
    } else {
      curr_res->next = curr_2;
      curr_2 = curr_2->next;
    }
    curr_res = curr_res->next;
  }
  if (curr_1 == nullptr) {
    curr_res->next = curr_2;
  } else {
    curr_res->next = curr_1;
  }
  if (result_head == first.get_head()) {
    second.head = nullptr;
    second.length = 0;
    return first;
  }
  first.head = second.head;
  first.length = second.length;
  second.head = nullptr;
  second.length = 0;
  return first;
}

template <typename T>
void split_list(List<T> &list, List<T> &second) {
  second.clear_list();
  if (list.length <= 1) {
    return;
  }
  int n = list.length;
  Node<T> *curr = list.head;
  for (int i = 0; i < (n + 1) / 2 - 1; i++) {
    curr = curr->next;
  }
  list.length = (n + 1) / 2;
  second.head = curr->next;
  second.length = n - list.length;
  curr->next = nullptr;
}

template <typename T>
List<T> &sortt(List<T> &list) {
  if (list.is_empty() || list.get_length() == 1) {
    return list;
  }
  List<T> second;
  split_list(list, second);
  return merge_sorted(sortt(list), sortt(second));
}
// sort list
template <typename T>
void List<T>::sort() {
  List<T> result = sortt(*this);
  head = result.head;
  result.head = nullptr;
  result.length = 0;
}
  
// operator <<
template <typename T>
std::ostream &operator<<(std::ostream &out, const List<T> &l) {
  Node<T> *curr = l.get_head();
  while (curr != nullptr) {
    out << *curr << " -> ";
    curr = curr->next;
  }
  out << "x";
  return out;
}

// check if empty
template <typename T> bool List<T>::is_empty() const { return head == nullptr; }

// add an element in the front of the list
template <typename T> void List<T>::push_front(const T &x) {
  Node<T> *new_node = new Node<T>(x);
  new_node->next = head;
  head = new_node;
  length++;
}

// add an element in the back of the list
template <typename T> void List<T>::push_back(const T &x) {
  if (is_empty()) {
    head = new Node<T>(x);
    length++;
    return;
  }

  Node<T> *curr = head;
  while (curr->next != nullptr)
    curr = curr->next;
  curr->next = new Node<T>(x);
  length++;
}

// remove the first element
template <typename T> void List<T>::pop_front() {
  if (is_empty()) {
    return;
  }
  Node<T> *new_head = head->next;
  delete head;
  head = new_head;
  length--;
}

// remove the last element
template <typename T> void List<T>::pop_back() {
  if (is_empty()) {
    return;
  }
  if (head->next == nullptr) { // only one element => should delete head
    delete head;
    head = nullptr;
    length--;
    return;
  }
  Node<T> *curr = head;
  while (curr->next->next != nullptr)
    curr = curr->next;
  delete curr->next;
  curr->next = nullptr;
  length--;
}

// add an element before the given pointer
template <typename T>
void List<T>::push_before(const T &x, const Node<T> *node) {
  if (node == nullptr) {
    push_back(x);
    return;
  }
  if (node == head) {
    push_front(x);
    return;
  }
  Node<T> *curr = head;
  while (curr->next != node) {
    curr = curr->next;
    if (curr == nullptr)
      push_back(x); // if node wasn't found, push x to the end of the list
  }
  curr->next = new Node<T>(x);
  length++;
  curr->next->next = const_cast<Node<T> *>(node);
}

// delete an element by the given pointer
template <typename T>
void List<T>::pop_by_pointer(const Node<T> *node_to_delete) {
  if (node_to_delete == nullptr || head == nullptr) {
    return;
  }
  if (node_to_delete == head) {
    pop_front();
    return;
  }
  Node<T> *curr = head;
  while (curr->next != node_to_delete) {
    curr = curr->next;
    if (curr == nullptr)
      return;
  }
  curr->next = node_to_delete->next;
  delete node_to_delete;
  node_to_delete = nullptr;
  length--;
}

// find an element by value
template <typename T> const Node<T> *List<T>::find(const T &value) const {
  Node<T> *curr = head;
  while (curr != nullptr && curr->data != value) {
    curr = curr->next;
  }
  return curr;
}

// pop by value
template <typename T> void List<T>::pop_by_value(const T &value) {
  pop_by_pointer(find(value));
}

// concatanate lists
template <typename T> List<T> operator+(List<T> &first, List<T> &second) {
  first += second;
  List<T> result = first;
  first.length = 0;
  first.head = nullptr;
  return result;
}

// move other list nodes to this list
template <typename T> List<T> &List<T>::operator+=(List<T> &other) {
  if (other.is_empty()) 
    return *this;
  if (!is_empty()) {
    Node<T> *curr = head; // head != nullptr
    while (curr->next != nullptr) {     
      curr = curr->next;
    }
    curr->next = other.head;
  }
  else {
    head = other.head;
  }
  length += other.length;
  other.head = nullptr;
  other.length = 0;
  return *this;
}

#endif //_LIST_H_