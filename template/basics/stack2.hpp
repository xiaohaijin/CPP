#ifndef STACK2_HPP
#define STACK2_HPP

#include <deque>
#include <string>
#include <cassert>

#include "stack1.hpp"

template <> class Stack<std::string> {

public:
    void push(std::string const&);
    void pop();
    const std::string& top() const;
    bool empty() const;

private:
    std::deque<std::string> elems;
};

#endif // STACK2_HPP

void Stack<std::string>::push(const std::string& elem)
{
    elems.push_back(elem);
}

void Stack<std::string>::pop()
{
    assert(!elems.empty());
    elems.pop_back();
}

const std::string& Stack<std::string>::top() const
{
    assert(!elems.empty());
    elems.back();
}

bool Stack<std::string>::empty() const
{
    return elems.empty();
}
