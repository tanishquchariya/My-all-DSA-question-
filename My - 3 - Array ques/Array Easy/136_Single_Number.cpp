#include <bits/stdc++.h>
using namespace std;
// Approach - 1 using unordered_map
int singleNumber(vector<int> &nums)
{
    unordered_map<int, int> Mp;
    for (int i = 0; i < nums.size(); i++)
    {
        Mp[nums[i]]++;
    }
    for (const auto & i : Mp)
    {
        if (i.second == 1)
        {
            return i.first;
        }
    }
    // or but not best way for map
    // for (int i = 0; i < Mp.size(); i++)
    // {
    //     if (Mp[i] == 1)
    //     {
    //         return i;
    //     }
    // }
    return -1; // Should never reach here if input is valid
}

// Approach - 2 using XOR(Bit Manipulation) or (Optimal Approach)
int singleNumber(vector<int> &nums)
{
    int result = 0;
    for (int i = 0; i < nums.size(); i++)
    {
        result ^= nums[i]; // XOR operation
    }
    return result; // The single number will remain after all pairs cancel out
}
// example usage
int main()
{
    vector<int> nums = {4, 1, 2, 1, 2};
    cout << "The single number is: " << singleNumber(nums) << endl;
    return 0;
}
