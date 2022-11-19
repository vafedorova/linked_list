#include "list.h"
#include <iostream>

using namespace std;
int main() {
  List<int> a;
  for (int i = 0; i < 10; i++) {
    int x;
    cin >> x;
    if (i % 2 == 0) {
      a.push_front(x);
    }
    else {
      a.push_back(x);
    }
    cout << a << "\n";
  }
}