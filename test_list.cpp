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
  for (int i = 0; i < 5; i++) {
    list.pop_back();
    cout << list << "\n";
  }
  list.pop_back();
}