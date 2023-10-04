#include "utilities.h"
#include <iostream>
#include <vector>

int getPartitionPoint(std::vector<int> &v, int low, int high)
{
    int pivot = v[low];
    int i = low;
    int j = high;

    while (i < j)
    {

        while (v[i] <= pivot && i < high)
        {
            i++;
            std::cout << "i: " << i << std::endl;
        }
        // j is find the last one smaller than pivot
        while (v[j] >= pivot && j > low)
        {
            j--;
            std::cout << "j: " << j << std::endl;
        }
        if (i < j)
        {
            std::cout << "swap\n";
            swap(v, i, j);
            printArray(v);
        }
    }
    std::cout << "end partition" << std::endl;
    // because j is the last one that smaller than pivot, i is the first one bigger than pivot, swap j and low, not i
    // and low
    swap(v, low, j);
    return j;
}

void quickSort(std::vector<int> &v, int low, int high)
{
    if (low < high)
    {

        int pivotIndex = getPartitionPoint(v, low, high);
        quickSort(v, low, pivotIndex - 1);
        quickSort(v, pivotIndex + 1, high);
    }
}

int main()
{
    std::vector<int> v = {4, 1, 6, 3, 2, 5, 9};
    quickSort(v, 0, 6);
    printArray(v);
    return 0;
}