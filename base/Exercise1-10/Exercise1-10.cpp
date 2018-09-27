#include <iostream>

int main(){

  const int MAXVALUE(10);
  const int MINVALUE(0);
  for(int i(10); i >= MINVALUE; --i){
    std::cout << i << std::endl;
  }
  
  return 0;
}
