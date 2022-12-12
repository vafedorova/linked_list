#include "node.h"
#include "menu.h"

int main() {
  while (true) {
    switch (show_menu()) {
    case 1:
      push_front();
      break;
    case 2:
      push_back();
      break;
    case 3:
      push_before();
      break;
    case 4:
      find_element();
      break;
    case 5:
      remove_first_node();
      break;
    case 6:
      remove_last_node();
      break;
    case 7:
      remove_by_value();
      break;
    case 8:
      clear_list();
      break;
    case 9:
      concatenate_lists();
      break;
    case 10:
      sort_list();
      break;
    default:
      return 0;
    }
  }
}