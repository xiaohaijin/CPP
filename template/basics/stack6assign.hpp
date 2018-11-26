#include "stack6decl.hpp"

template <typename T>
template <typename T2>
Stack<T>& Stack<T>::operator=(Stack<T2> const& op2) {
  elems.clear();
  elems.insert(elems.begin(), op2.elems.begin(), op2.elems.end());
  return *this;
}
