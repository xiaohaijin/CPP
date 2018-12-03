#ifndef STACK9_HPP
#define STACK9_HPP

#include <cassert>
#include <deque>
#include <memory>

template <typename T, template <typename Elem, typename = std::allocator<Elem>> class Cont = std::deque>
class Stack {
  template <typename, template <typename, typename> class>
  friend class Stack;

 public:
  void push(const T& elem);
  void pop();
  const T& top() const;
  bool empty() const {
    return elems.empty();
  }
  template <typename T2, template <typename Elem2, typename = std::allocator<Elem2>> class Cont2>
  Stack<T, Cont>& operator=(Stack<T2, Cont2> const&);

 private:
  Cont<T> elems;
};

template <typename T, template <typename, typename> class Cont>
void Stack<T, Cont>::push(const T& elem) {
  elems.push_back(elem);
}

template <typename T, template <typename, typename> class Cont>
void Stack<T, Cont>::pop() {
  assert(!elems.empty());
  elems.pop_back();
}

template <typename T, template <typename, typename> class Cont>
const T& Stack<T, Cont>::top() const {
  assert(!elems.empty());
  return elems.back();
}

template <typename T, template <typename, typename> class Cont>
template <typename T2, template <typename, typename> class Cont2>
Stack<T, Cont>& Stack<T, Cont>::operator=(Stack<T2, Cont2> const& op2) {
  elems.clear();
  elems.insert(elems.begin(), op2.elems.begin(), op2.elems.end());
  return *this;
}

#endif  // STACK9_HPP
