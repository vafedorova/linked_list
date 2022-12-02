#include "list.h"
#include <iostream>

using namespace std;
int main() {
  List<int> list;
  for (int i = 0; i < 5; i++) {
    int x;
    cin >> x;
    if (i % 2 == 0) {
      list.push_front(x);
    }
    else {
      list.push_back(x);
    }
    cout << list << "\n";
  }
  Node<int> *very_important_node = list.get_head();
  for (int i = 0; i < 3; i++) {
    very_important_node = very_important_node->next;
  }
  cout << "adding element before " << *very_important_node << "...\n";
  list.push_before(123, very_important_node);
  cout << list << "\n";

  const Node<int> *node_to_be_deleted = list.find(123);
  cout << "found node: " << *node_to_be_deleted << "\n";
  cout << "deleting the element found: \n";
  list.pop_by_pointer(node_to_be_deleted);
  cout << list << "\n";
  cout << "deleting the head of the list by pointer: \n";
  list.pop_by_pointer(list.get_head());
  cout << list << "\n";
  for (int i = 0; i < 10; i++) {
    cout << "deleting 1 from the list: \n";
    list.pop_by_value(1);
    cout << list << "\n";
  }
  List<int> list2;
  for (int i = 0; i < 5; i++) {
    int x;
    cin >> x;
    list2.push_front(x);
  }
   cout << "list = " << list << "\n";
   cout << "list2 = " <<  list2 << "\n";
   cout << "list + list2 = " << list + list2 << "\n";
   cout << "list = " << list << "\n";
   cout << "list2 = " <<  list2 << "\n";

  cout << "list + list + list = " <<  list + list + list << "\n";
}