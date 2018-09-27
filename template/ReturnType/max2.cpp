#include <iostream>

int max(int a, int b){
  return b < a ? a : b;
}

template <typename T>
T max(T a, T b){
  return b < a ? a : b;
}


int main(){

  std::cout << ::max(7, 42) << std::endl;    /*!< call nontemplate */
  std::cout << ::max(7.0, 42.0) << std::endl; /*!< call template */
  std::cout << ::max('a', 'b') << std::endl; /*!< call template */
  std::cout << ::max<>(7, 42) << std::endl;  /*!< call template */
  std::cout << ::max<double>(7, 42) << std::endl; /*!< call template */
  std::cout << ::max('a', 42.7) << std::endl; /*!< call nontemplate */
  
  return 0;
}
