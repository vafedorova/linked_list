#include <unordered_map>
#include "menu.h"
#include <exception>

using namespace std;

List<int> list;

// 1
void push_front() {
  cout << "Enter the value to insert: ";
  int x;
  cin >> x;
  list.push_front(x);
}

// 2
void push_back() {
  cout << "Enter the value to insert: ";
  int x;
  cin >> x;
  list.push_back(x);
}

// 3
void push_before() {
  cout << "Enter the value to insert: ";
  int x;
  cin >> x;
  cout << "Enter the value, before which you want to insert " << x << ": ";
  int before;
  cin >> before;
  const Node<int> *node = list.find(before);
  if (node == nullptr) {
    cout << "\nThere is no element with a value " << before << " in the list! Will use push_back() instead of push_before().\n";
    list.push_back(x);
  }
  else {
    list.push_before(x, node);
  }
}

// 4
void find_element() {
  cout << "Enter the value you want to find in the list: ";
  int x;
  cin >> x;
  const Node<int> *node = list.find(x);
  cout << "\nAddress of the list element with a value " << x << " is: " << node;   
  if (node == nullptr)
    cout << " (There is no element with a value " << x << " in the list!)";
  cout << "\n";
}

// 5
void remove_first_node() {
  list.pop_front();
}

// 6
void remove_last_node() {
  list.pop_back();
}

// 7
void remove_by_value() {
  cout << "Enter the value to remove: ";
  int x;
  cin >> x;
  list.pop_by_value(x);
}

// 8
void clear_list() {
  list.clear_list();
}

// 9
void concatenate_lists() {
  cout << "Enter the second list: \n";
  List<int> other;
  cout << "Enter next value, to stop enter -1: ";
  int x;
  cin >> x;
  while (x != -1) {
    other.push_front(x);
    cout << "Enter next value, to stop enter -1: ";
    cin >> x;
  }
  cout << "second: " << other << "\n";
  list += other;
}

// 10
void sort_list() {
  list.sort();
}
int show_menu() {
  cout << "\n";
  while (true) {
    cout << "My list: " << list;
    if (list.is_empty()) {
      cout << " (list is empty)";
    }
    cout << "\n\n";
    cout << "==========================================================\n";
    int i = 1;
    cout << i++ << ". Add an element in the front of the list.\n"
         << i++ << ". Add an element in the back of the list.\n"
         << i++ << ". Add an element before the given element.\n"
         << i++ << ". Find the address of the element with a given value.\n"
         << i++ << ". Remove the first element.\n"
         << i++ << ". Remove the last element.\n"
         << i++ << ". Remove the given element.\n"
         << i++ << ". Clear the list.\n"
         << i++ << ". Concatanate lists.\n"
         << i++ << ". Sort list.\n"
         << i++ << ". Exit the program.\n";
    cout << "Enter your choice: ";
    int choice;
    cin >> choice;
    if (choice >= i || choice < 1) {
      cerr << "Invalid choice. Try again." << endl;
      continue;
    }
    cout << "==========================================================\n";
    cout << "\n";
    return choice;
  }
}
