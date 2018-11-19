#ifndef STACK3_HPP
#define STACK3_HPP

#include <vector>
#include <cassert>

template <typename T, typename Cont = std::vector<T> > class Stack {
public:
    void push(const T& elem);
    void pop();
    const T& top() const;
    bool empty() const;

private:
    Cont elems;
};

template <typename T, typename Cont> void Stack<T, Cont>::push(const T& elem)
{
    elems.push_back(elem);
}

template <typename T, typename Cont> void Stack<T, Cont>::pop()
{
    assert(!elems.empty());
    elems.pop_back();
}

template <typename T, typename Cont> const T& Stack<T, Cont>::top() const
{
    assert(!elems.empty());
    return elems.back();
}

template <typename T, typename Cont> bool Stack<T, Cont>::empty() const
{
    return elems.empty();
}

#endif // STACK3_HPP
