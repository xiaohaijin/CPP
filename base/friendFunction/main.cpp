#include <iostream>

#include "complex.h"

int main(int argc, char *argv[]) {
  complex c1(2, 1);
  complex c2;
  std::cout << c2.fuc(c1) << std::endl;
  return 0;
}
