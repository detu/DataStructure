#include <iostream>
#include <array>

// node:using std::array is not flexible because we can't vary size of the array. better to use vector.

void mergeTwoSortedArray(const std::array<int,2> array1,const std::array<int,4> array2, std::array<int,6>& result)
{
   int indexArray1{0}, indexArray2{0}, indexResult{0};

   for (auto& i: result)
   {
       if (indexArray1 < 2 && indexArray2 < 4) {
           if (array1.at(indexArray1) < array2.at(indexArray2)) {
               i = array1.at(indexArray1);
               indexArray1++;
           } else if (array2.at(indexArray2) < array1.at(indexArray1)) {
               i = array2.at(indexArray2);
               indexArray2++;
           }
           indexResult++;
       }
       else if(indexArray1 == 2 && indexResult < 6){
           i = array2.at(indexArray2);
           indexArray2++;
           indexResult++;
       }
   }
}

int main() {

    const std::array<int,2> a1{3,4};
    const std::array<int,4> a2{1,2,5,6};
    std::array<int,6> result{0,0,0,0,0,0};

    mergeTwoSortedArray(a1,a2, result);
    for (const auto& r: result)
        std::cout << r << ' ';
    return 0;
}
