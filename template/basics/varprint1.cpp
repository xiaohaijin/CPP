
#include <iostream>
#include <string>

void print() {}

template <typename T, typename... Types>
void print(T firstArg, Types... args) {
  std::cout << firstArg << "\n";
  print(args...);
}

int main() {
  std::string s("world");
  print(7.5, "hello", s);

  return 0;
}
