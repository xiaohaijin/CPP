#ifndef STACKAUTO_H
#define STACKAUTO_H

#include <array>
#include <cassert>

template <typename T, auto Maxsize>
class Stack {
 public:
  using size_type = decltype(Maxsize);

 private:
  std::array<T, Maxsize> elems;
  size_type numElems;

 public:
  Stack();
  void push(const T &elem);
  void pop();
  const T &top() const;
  bool empty() const;
  size_type size() const;
};

template <typename T, auto Maxsize>
Stack<T, Maxsize>::Stack()
    : numElems(0) {}

template <typename T, auto Maxsize>
void Stack<T, Maxsize>::push(const T &elem) {
  assert(numElems < Maxsize);
  elems[numElems] = elem;
  ++numElems;
}

template <typename T, auto Maxsize>
void Stack<T, Maxsize>::pop() {
  assert(!elems.empty());
  --numElems;
}

template <typename T, auto Maxsize>
const T &Stack<T, Maxsize>::top() const {
  assert(!elems.empty());
  return elems[numElems - 1];
}
#endif  // STACKAUTO_H
