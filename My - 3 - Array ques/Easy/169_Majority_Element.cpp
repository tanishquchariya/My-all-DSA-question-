#include <bits/stdc++.h>
using namespace std;

// Approach - 1 brute force using two pointers
// time complexity - O(n^2) ans space complexity - O(1)
// int majorityElement(vector<int>& nums) {

//     int n = nums.size();
//     for (int i = 0; i < n; i++) {
//         int count = 0;
//         for (int j = 0; j < n; j++) {
//             if (nums[i] == nums[j]) {
//                 count++;
//             }
//         }
//         if (count > n / 2) {
//             return nums[i];
//         }
//     }
//     return -1; // This line should never be reached as per problem constraints
// }

// approach -  2 using hashmap
// time complexity - O(n)
// space complexity - O(n)
// int majorityElement(vector<int>& nums) {
//     unordered_map<int, int> countMap;
//     int n = nums.size();

//     for (int i = 0; i < n; i++) {
//         countMap[nums[i]]++;
//         if (countMap[nums[i]] > n / 2) {
//             return nums[i];
//         }
//     }

//     return -1; // This line should never be reached as per problem constraints
// }

// Approach - 3 using Boyer-Moore Voting Algorithm (optimal solution with O(1) space and O(n) time complexity)
int majorityElement(vector<int> &nums)
{
    int count = 0;
    int element = 0;
    int n = nums.size();
    for (int i = 0; i < n; i++)
    {
        if (count == 0)
        {
            count = 1;
            element = nums[i];
        }
        else if (nums[i] == element)
        {
            count++;
        }
        else
        {
            count--;
        }
    }
    return element; // The element is guaranteed to be the majority element as per problem constraints
}

// // or this solution with verification step
// // This solution includes a verification step to ensure the candidate is indeed the majority element.
// int majorityElement(vector<int> &nums)
// {
//     int count = 0;
//     int element = 0;
//     int n = nums.size();
//     for (int i = 0; i < n; i++)
//     {
//         if (count == 0)
//         {
//             count = 1;
//             element = nums[i];
//         }
//         else if (nums[i] == element)
//         {
//             count++;
//         }
//         else
//         {
//             count--;
//         }
//     }

//     // Verify that the candidate is indeed the majority element
//     int count1 = 0;
//     for (int i = 0; i < nums.size(); i++)
//     {
//         if (nums[i] == element)
//         {
//             count1++;
//         }
//         if (count1 > nums.size() / 2)
//         {
//             return element;
//         }
//     }
//     return -1; // This line should never be reached as per problem constraints
// }

// example usage
int main()
{
    vector<int> nums = {2, 2, 1, 1, 2, 2, 1};
    cout << "Majority Element: " << majorityElement(nums) << endl; // Output: 2
    return 0;
}