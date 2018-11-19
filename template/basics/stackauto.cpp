#include <iostream>
#include <string>

#include "stackauto.hpp"

int main() {
  Stack<int, 20> int20Stack;
  Stack<std::string, 40> string40Stack;

  int20Stack.push(7);
  std::cout << int20Stack.top() << "\n";
  auto size1 = int20Stack.size();

  string40Stack.push("hello");
  std::cout << string40Stack.top() << "\n";
  auto size2 = string40Stack.size();

  if (!std::is_same_v<decltype(size1), decltype(size2)>) {
    std::cout << "size types differ"
              << "\n";
  }

  return 0;
}
