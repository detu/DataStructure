#include <iostream>
#include <array>

std::array<int,n3> sortArray(const std::array<int,n1> a1,const std::array<int,n2> a2)
{
  size_t n3 = a1.size() + a2.size();
  std::array<int, n3> result;
  // sort a1
  // sort a2
  for(auto i: result){

  }

  return result;
}

int main() {

    const std::array<int,2> a1 = {3,4};
    const std::array<int,4> a2 = {1,2,5,6};

    auto sort2Arrays = sortArray(a1,a2);
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
