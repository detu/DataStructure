#include <iostream>
#include <vector>

template< typename T>
std::vector<T> mergeTwoSortedArray(const std::vector<T> array1,const std::vector<T> array2)
{
   int indexArray1{0}, indexArray2{0}, indexResult{0};
   int numRes = array1.size() + array2.size();
   std::vector<T> result(numRes,0);

   for (auto& i: result)
   {
       if (indexArray1 < array1.size() && indexArray2 < array2.size()) {
           if (array1.at(indexArray1) < array2.at(indexArray2)) {
               i = array1.at(indexArray1);
               indexArray1++;
           } else if (array2.at(indexArray2) < array1.at(indexArray1)) {
               i = array2.at(indexArray2);
               indexArray2++;
           }
           indexResult++;
       }
       else if(indexArray1 == array1.size() && indexResult < numRes){
           i = array2.at(indexArray2);
           indexArray2++;
           indexResult++;
       }
       else if(indexArray2 == array2.size() && indexResult < numRes){
           i = array1.at(indexArray1);
           indexArray1++;
           indexResult++;
       }

   }
   return result;
}

int main() {

    const std::vector<int> a2{1};
    const std::vector<int> a1{2,4,6,8};

    auto  result = mergeTwoSortedArray(a1,a2);
    for (const auto& r: result)
        std::cout << r << ' ';
    return 0;
}
