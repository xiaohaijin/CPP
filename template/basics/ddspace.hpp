#ifndef DDSPACE_HPP
#define DDSPACE_HPP

#include <iostream>

template <typename T>
class AddSpace {
 private:
  const T& ref;

 public:
  AddSpace(const T& r) : ref(r) {
  }

  friend std::ostream& operator<<(std::ostream& out, AddSpace<T> s) {
    return out << s.ref << " ";
  }
};

template <typename... Args>
void print(Args... args) {
  (std::cout << ... << AddSpace(args)) << "\n";
}

#endif  // DDSPACE_HPP
