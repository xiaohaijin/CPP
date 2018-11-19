#include <iostream>
#include <string>

//#include <QtCore>

#include "stack1.hpp"

int main(int argc, char** argv)
{
    /*   Q_UNUSED(argc);
    Q_UNUSED(argv)*/;

    Stack<int> intStack;
    Stack<std::string> stringStack;

    intStack.push(7);
    std::cout << intStack.top() << '\n';

    stringStack.push("hello");
    std::cout << stringStack.top() << '\n';
    stringStack.pop();

    return 0;
}
