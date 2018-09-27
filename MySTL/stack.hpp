#ifndef STACK_H
#define STACK_H

#include <cstddef>
#include <expection>
#include <memory>

namespace CPP{
  namespace MySTL{
    template<typename T>
    class Stack{
      using size_type = std::size_t;

      pub

    private:

      class StackEmptyException : public std::exception{
      public:
	virtual const char *what() const throw(){
	  return "stack is empty";
	}
      };

      class StackIndexOutOfBoundException : public std::exception{
      public:
	virtual const char *what() const throw(){
	  return "Index out of bound";
	}
      };
      
      size_type capacity;
      size_type size;
      T *ptr;
    };
  }
}

#endif /* STACK_H */
