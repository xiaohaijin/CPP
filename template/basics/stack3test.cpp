#include <iostream>
#include <deque>

#include "stack3.hpp"

int main(int argc, char** argv)
{
    Stack<int> intStack;

    Stack<double, std::deque<double> > dblStack;

    intStack.push(7);
    std::cout << intStack.top() << '\n';
    intStack.pop();

    dblStack.push(42.122212);
    std::cout << dblStack.top() << "\n";
    dblStack.pop();

    return 0;
}
