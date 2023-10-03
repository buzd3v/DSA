#include <algorithm>
#include <iostream>

#include "utilities.h"
#include <vector>

// the main idea is devide and conquere
//
// split the array into two half, if they are sorted , then merge them in the order
// the base case contain 2 number, after merge they become a sorted array

void merge(std::vector<int> &arr, int low, int mid, int high)
{
    int left = low;
    int right = mid + 1;
    std::vector<int> temp;
    while (left <= mid && right <= high)
    {
        if (arr[left] <= arr[right])
        {
            temp.push_back(arr[left]);
            left++;
        }
        else
        {
            temp.push_back(arr[right]);
            right++;
        }
    }
    while (left <= mid)
    {
        temp.push_back(arr[left]);
        left++;
    }
    while (right <= high)
    {
        temp.push_back(arr[right]);
        right++;
    }
    for (auto i = 0; i < temp.size(); i++)
    {
        arr[i + low] = temp[i];
    }
}

void mergeSort(std::vector<int> &arr, int low, int high)
{
    if (low >= high)
    {
        return;
    }
    int mid = (low + high) / 2;
    mergeSort(arr, low, mid);
    mergeSort(arr, mid + 1, high);
    merge(arr, low, mid, high);
}

int main()
{
    std::vector<int> v = {7, 3, 6, 2, 6, 3, 5, 3, 2, 4};
    mergeSort(v, 0, 9);
    printArray(v);
}