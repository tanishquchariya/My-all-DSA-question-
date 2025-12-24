#include <bits/stdc++.h>
using namespace std;

// Approach - 1: Brute Force using Two Loops

// This approach checks each index to see if it is a pivot index.
// The time complexity of this approach is O(n^2) and space complexity is O(1)
// int pivotIndexBruteForce(vector<int> &nums)
// {
//     int n = nums.size();
//     for (int i = 0; i < n; i++)
//     {
//         int leftSum = 0, rightSum = 0;
//         for (int j = 0; j < i; j++)
//         {
//             leftSum += nums[j];
//         }
//         for (int j = i + 1; j < n; j++)
//         {
//             rightSum += nums[j];
//         }
//         if (leftSum == rightSum)
//         {
//             return i;
//         }
//     }
//     return -1;
// }

// approacch  - 2 using optimal solution with one loop
// The time complexity of this approach is O(n) and space complexity is O(1)
int pivotIndex(vector<int> &nums)
{
    int n = nums.size();
    // int totalSum = accumulate(nums.begin(), nums.end(), 0);

    int totalSum = 0;
    for (int i = 0; i < n; i++)
    {
        totalSum += nums[i];
    }
    int cs = 0;
    for (int i = 0; i < n; i++)
    {
        int ls = cs;
        int rs = totalSum - ls - nums[i];
        if (ls == rs)
        {
            return i;
        }
        cs += nums[i];
    }
    return -1;
}

// or 
//  int pivotIndex(vector<int>& nums) {
//         int totalSum = accumulate(nums.begin(), nums.end(), 0);
//         int leftSum = 0;

//         for (int i = 0; i < nums.size(); ++i) {
//             if (leftSum == totalSum - leftSum - nums[i]) {
//                 return i;
//             }
//             leftSum += nums[i];
//         }
//         return -1;
//     }

// Example usage
int main()
{
    vector<int> nums = {1, 7, 3, 6, 5, 6};
    int pivot = pivotIndex(nums);
    if (pivot != -1)
    {
        cout << "Pivot index found at: " << pivot << endl;
    }
    else
    {
        cout << "No pivot index found." << endl;
    }
    return 0;
}