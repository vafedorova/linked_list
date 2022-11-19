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
}