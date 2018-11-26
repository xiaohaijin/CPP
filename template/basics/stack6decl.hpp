#ifndef STACK6DECL_HPP
#define STACK6DECL_HPP

#include <deque>

template <typename T>
class Stack {
  template <typename>
  friend class Stack;

 public:
  void push(const T& elem);
  void pop();
  const T& top() const;
  bool empty() const {
    return elems.empty();
  }

  template <typename T2>
  Stack& operator=(const Stack<T2>&);

 private:
  std::deque<T> elems;
};

#endif  // STACK6DECL_HPP
