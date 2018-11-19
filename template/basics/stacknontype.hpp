#ifndef STACKNONTYPE_HPP
#define STACKNONTYPE_HPP

#include <array>
#include <cassert>

template <typename T, std::size_t Maxsize>
class Stack {
 private:
  std::array<T, Maxsize> elems;
  std::size_t numElems;

 public:
  Stack();
  void push(const T &elem);
  void pop();
  const T &top() const;
  bool empty() const;
  std::size_t size() const;
};

#endif  // STACKNONTYPE_HPP

template <typename T, std::size_t Maxsize>
Stack<T, Maxsize>::Stack()
    : numElems(0) {
  /// nothing else to do
}

template <typename T, std::size_t Maxsize>
void Stack<T, Maxsize>::push(const T &elem) {
  assert(numElems < Maxsize);
  elems[numElems] = elem;
  ++numElems;
}

template <typename T, std::size_t Maxsize>
const T &Stack<T, Maxsize>::top() const {
  assert(!elems.empty());
  return elems[numElems - 1];
}

template <typename T, std::size_t Maxsize>
bool Stack<T, Maxsize>::empty() const {
  return numElems == 0;
}

template <typename T, std::size_t Maxsize>
std::size_t Stack<T, Maxsize>::size() const {
  return numElems;
}

template <typename T, std::size_t Maxsize>
void Stack<T, Maxsize>::pop() {
  assert(!elems.empty());
  --numElems;
}
