#include <iostream>
#include <map>
#include <algorithm>

int main(){
  std::map<std::string, double> coll;

  auto pos = std::find_if(coll.begin(), coll.end(), [](const std::string &s){
      return s != "";
    });
  return 0;
}
