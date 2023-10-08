#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;

int longestSubarrayWithSumK(vector<int> a, long long k)
{
    // Write your code here
    std::unordered_map<int, int> prefix_sum;
    int sum = 0;
    int i = 0;
    int maxlength = 0;
    for (auto c : a)
    {
        sum += c;
        prefix_sum[sum] = i;
        i++;
        if (prefix_sum[sum - k] != 0)
        {
            int length = i - prefix_sum[sum - k] - 1;
            if (length > maxlength)
            {
                maxlength = length;
            }
        }
    }
    return maxlength;
}
int main()
{
    vector<int> v = {1, 1, 0, 1, 1};
    int k = 2;
    std::cout << "Max Length = " << longestSubarrayWithSumK(v, k) << std::endl;
}