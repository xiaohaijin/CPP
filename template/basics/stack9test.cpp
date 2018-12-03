#include <iostream>
#include <vector>

#include "stack9.hpp"

int main(int argc, char **argv) {
  Stack<int> iStack;
  Stack<float> fStack;

  iStack.push(1);
  iStack.push(2);
  std::cout << "iStack.top(): " << iStack.top() << "\n";

  fStack.push(3.3);
  std::cout << "fStack.top(): " << fStack.top() << "\n";

  fStack = iStack;
  fStack.push(4.4);
  std::cout << "fStack.top(): " << fStack.top() << '\n';

  Stack<double, std::vector> vStack;
  vStack.push(5.5);
  vStack.push(6.1);
  std::cout << "vStack.top(): " << vStack.top() << '\n';

  return 0;
}
