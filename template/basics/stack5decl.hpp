#ifndef STACK5DECL_HPP
#define STACK5DECL_HPP

#include <deque>

template <typename T>
class Stack {
  template <typename T2>
  Stack &operator=(const Stack<T2> &);

 public:
  void push(const T &elem);
  void pop();
  const T &top() const;
  bool empty() const;

 private:
  std::deque<T> elems;
};

#endif  // STACK5DECL_HPP
