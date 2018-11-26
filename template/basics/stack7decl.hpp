template <typename T, typename Cont = std::deque<T>>
class Stack{
private:
  Cont elems;

public:
  void push(const T& elem);
  void pop();
  const T& top() const;
  bool empty() const{
    return elems.empty();
  }

  template <typename T2, typename Cont2>
  Stack& operator=(Stack<T2, Cont2> const&);
  template <typename, typename> friend class Stack;
};
