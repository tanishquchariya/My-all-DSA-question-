#include <bits/stdc++.h>
using namespace std;

// // Approach - 1 using sorting (brute force)
// // time complexity - O(n log n) and space complexity - O(1)
// int missingNumber(vector<int>& nums) {
//     sort(nums.begin(), nums.end());
//     for (int i = 0; i < nums.size(); i++) {
//         if (nums[i] != i) {
//             return i;
//         }
//     }
//     return nums.size();
// }

// Approach - 2 using sum formula (optimal solution 1)
// time complexity - O(n) and space complexity - O(1)

// int missingNumber(vector<int> &nums)
// {
//     int n = nums.size();
//     int total = (n * (n + 1)) / 2;
//     // int ArrSum = accumulate(nums.begin(), nums.end(), 0);
//     // return total - ArrSum;
//     for(int i = 0; i < n; i++)
//     {
//         total -= nums[i];
//     }

//     return total;
// }

// Approach - 3 using XOR (optimal solution 2)
// time complexity - O(n) and space complexity - O(1)

// int missingNumber(vector<int> &nums)
// {
//     int n = nums.size();
//     int result = n;
//     for (int i = 0; i < n; i++)
//     {
//         result ^= i;
//         result ^= nums[i];
//     }
//     return result;
// // Alternative approach using XOR
// int xor1 = 0;
// int xor2 = 0;

// for (int i = 0; i < n; i++)
// {
//     xor1 ^= nums[i];
// }

// for (int i = 0; i <= n; i++)
// {
//     xor2 ^= i;
// }

// return xor1 ^ xor2;
// }

// approach - 4 using binary search (optimal solution 3)
// time complexity - O(n log n + log n ) and space complexity - O(1)
// Sorting: sort(nums.begin(), nums.end()) takes O(n log n) time.
// Binary Search: The while loop runs in O(log n) time.

int missingNumber(vector<int> &nums)
{
    int n = nums.size();
    sort(nums.begin(), nums.end());
    int left = 0, right = n - 1;
    int result = n; // Assume the missing number is n initially
    while (left <= right)
    {
        int mid = left + (right - left) / 2;
        if (nums[mid] > mid)
        {
            result = mid;    // Update result to the current mid
            right = mid - 1; // Search in the left half
        }
        else
        {
            left = mid + 1;
        }
    }
    return result;
}

int main()
{
    vector<int> arr = {3, 0, 1};
    cout << "Missing number is: " << missingNumber(arr) << endl;
    return 0;
}