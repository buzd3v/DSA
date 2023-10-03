#include "utilities.h"
#include <iostream>

void insertionSort(std::vector<int> &arr, int n) {
  for (int i = 0; i < n; i++) {
    for (int j = i; j > 0; j--) {
      if (arr[j] < arr[j - 1]) {
        swap(arr, j, j - 1);
      } else {
        { break; }
      }
    }
  }
}

int main() {
  std::vector<int> v = {9, 8, 7, 6, 5, 4, 3};
  insertionSort(v, 7);
  printArray(v);
}