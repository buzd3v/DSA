#include <bits/stdc++.h>

#include <iostream>

#include "utilities.h"

using namespace std;

void selectionSort(vector<int> &arr)
{
    // Write your code here.
    for (auto i = 0; i < arr.size(); i++)
    {
        int min_element = 999999;
        int min_idx = i;
        for (auto j = i; j < arr.size(); j++)
        {
            if (arr[j] < min_element)
            {
                min_element = arr[j];
                min_idx = j;
            }
        }
        swap<int>(arr, i, min_idx);
    }
}

int main()
{
    vector<int> x = {3, 2, 1, 5, 2, 5, 8};
    selectionSort(x);
    printArray(x);
}