#ifndef STACK1_H
#define STACK1_H

#include <vector>
#include <cassert>

template <typename T> class Stack {
public:
    void push(const T& elem);
    void pop();
    const T& top() const;
    bool empty() const;

private:
    std::vector<T> elems;
};

template <typename T> void Stack<T>::push(const T& elem)
{
    elems.push_back(elem);
}

template <typename T> void Stack<T>::pop()
{
    assert(!elems.empty());
    elems.pop_back();
}

template <typename T> const T& Stack<T>::top() const
{
    assert(!elems.empty());
    return elems.back();
}

template <typename T> bool Stack<T>::empty() const
{
    return elems.empty();
}

#endif // STACK1_H
