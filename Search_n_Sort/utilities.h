#pragma once
#include <iostream>
#include <vector>

template <typename T> static void swap(std::vector<T> &v, int i, int j) {
  T temp = v[i];
  v[i] = v[j];
  v[j] = temp;
}

template <typename T> static void printArray(std::vector<T> &v) {
  for (auto x : v) {
    std::cout << x << " ";
  }
  std::cout << "\n";
}