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
        std::cout << "Prefix sum untill " << i << ": " << sum << std::endl;
        std::cout << "remain sum : " << sum - k << std::endl;
        if (sum == k)
        {
            maxlength = std::max(i + 1, maxlength);
        }
        if (prefix_sum.find(sum - k) != prefix_sum.end())
        {
            int length = i - prefix_sum[sum - k];
            std::cout << "Length: " << length << std::endl;
            if (length > maxlength)
            {
                maxlength = length;
            }
        }
        if (prefix_sum.find(sum) == prefix_sum.end())
        {
            prefix_sum[sum] = i;
        }
        i++;
    }
    return maxlength;
}
int main()
{
    vector<int> v = {2, 3, 5};
    int k = 5;
    int res = longestSubarrayWithSumK(v, k);
    std::cout << "Max Length = " << res << std::endl;

    std::unordered_map<int, int> umap;
    umap[0] = 1;
    umap[0] = 2;
    for (auto m : umap)
    {
        std::cout << "first: " << m.first << ", second:  " << m.second << std::endl;
    }
}