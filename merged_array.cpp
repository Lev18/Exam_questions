
// [1, 2, 4]  [4, 7, 8, 9]

#include <vector>
#include <algorithm>
#include <iostream>

void arr_concat(std::vector<int> arr_1, std::vector<int> arr_2) {
  std::vector<int> arr {};
  for (const auto& i : arr_1) {
    arr.push_back(i);
  }
  
  for (const auto& i : arr_2) {
    arr.push_back(i);
  }
  std::sort(arr.begin(), arr.end());
  for(const auto& i : arr){
    std::cout << i;
  }
}

void arr_merge(int* arr_1, int* arr_2, int size_1, int size_2) {
  int* arr = new int[size_1 + size_2];
  if (size_1 <= size_2) {
    int i = 0;
    int j = 0;
    int k = 0;
    while( i < size_1 && j < size_2) {
     if(arr_1[i] <= arr_2[j]) {
      arr[k] = arr_1[i];
      ++i;
     } else {
        arr[k] = arr_2[j];
        ++j;
     }
     ++k;
    }
    
    while(i < size_1) {
      arr[k] = arr_1[i];
      ++i;
      ++k;
    }
    
    while(j < size_2) {
      arr[k] = arr_2[j];
      ++j;
      ++k;
    }
  }
}

int main() {
  int a[] = {1, 2, 4};
  int b[] = {2, 4, 8, 9};
  std::vector<int> arr_1 = {1, 2, 4};
  std::vector<int> arr_2 = {2, 4, 8, 9};
  int s1 = sizeof(a) / sizeof(int);
  int s2 = sizeof(b) / sizeof(int);
  //arr_merge(a, b, s1, s2);
  arr_concat(arr_1, arr_2);
  
  return 0;
}
