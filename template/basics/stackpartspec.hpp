#ifndef STACKPARTSPEC_HPP
#define STACKPARTSPEC_HPP

#include <stack1.hpp>

template <typename T> class Stack<T*> {
public:
    void push(T* elem);
    T* pop();
    T* top() const;
    bool empty() const;

private:
    std::vector<T*> elems;
};

#endif // STACKPARTSPEC_HPP

template <typename T> void Stack<T*>::push(T* elem)
{
    elems.push_back(elem);
}

template <typename T> T* Stack<T*>::pop()
{
    assert(!elems.empty());
    T* p = elems.back();
    elems.pop_back();
    return p;
}

template <typename T> T* Stack<T*>::top() const
{
    assert(!elems.empty());
    return elems.back();
}

template <typename T> bool Stack<T*>::empty() const
{
    return elems.empty();
}
