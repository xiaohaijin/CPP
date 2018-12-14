/*!
编写函数，接受一对指向vector<int>的迭代器和一个int值。在两个迭代器指定
的范围内查找给定的值，返回一个布尔值来指出是否找到元素。
 */

#include <vector>
#include <iterator>

using std::vector;
using std::iterator;

using Iterator = vector<int>::iterator;
bool find(Iterator begin, Iterator end, int value){
  for(Iterator iter = begin; iter != end; ++iter){
    if(*iter == value){
      return true;
    }
  }

  return false;
}


#include<iostream>

using std::cout;

int main(){
  vector<int> vecInt{1, 2, 3, 4, 5, 6};
  cout << find(vecInt.begin(), vecInt.end(), 4) << '\n';
  cout << find(vecInt.begin(), vecInt.end(), 8) << '\n';
}
