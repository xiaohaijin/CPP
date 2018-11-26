#ifndef PRINTCOLL_HPP
#define PRINTCOLL_HPP

#include <iostream>

template <typename T>
void printcoll(const T& coll) {
  typename T::const_iterator pos;
  typename T::const_iterator end(coll.end());

  for (pos = coll.begin(); pos != end; ++pos) {
    std::cout << *pos << "   ";
  }
  std::cout << '\n';
}

#endif  // PRINTCOLL_HPP
