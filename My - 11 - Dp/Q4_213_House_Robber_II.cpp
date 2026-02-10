// House Robber II - Dynamic Programming Solution 

#include <iostream>
#include <vector>
#include <cstring>
using namespace std;

// // Approach 1: Using Recursion or Brute Force
// // Time Complexity: O(2^n) - Exponential time complexity
// // Space Complexity: O(n) - Due to the recursion stack

// class Solution {
// public:
//     int solve(vector<int>& nums, int i, int n) {
//         if (i > n) {
//             return 0;
//         }
//         int steal = nums[i] + solve(nums, i + 2, n);
//         int skip = solve(nums, i + 1, n);
//         return max(steal, skip);
//     }
//     int rob(vector<int>& nums) {
//         int n = nums.size();
//         if (n == 1){
//             return nums[0]; // fix: handle single house
//         }
//         int take_0th_house = solve(nums, 0, n - 2);
//         int take_1th_house = solve(nums, 1, n-1);
//         return max(take_0th_house, take_1th_house);
//     }
// };

// Approach 2: Using Dynamic Programming (Memoization) OR Top-Down Approach
// Time Complexity: O(n) - Each state is computed once
// Space Complexity: O(n) - Due to the recursion stack and memoization array

// class Solution {
// public:
//     int t[101];
//     int solve(vector<int>& nums, int i, int n) {
//         if (i > n) {
//             return 0;
//         }
//         if(t[i] != -1){
//             return t[i];
//         }
//         int steal = nums[i] + solve(nums, i + 2, n);
//         int skip = solve(nums, i + 1, n);
//         return t[i] = max(steal, skip);
//     }
//     int rob(vector<int>& nums) {
//         int n = nums.size();
//         if (n == 1){
//             return nums[0]; // fix: handle single house
//         }
//         if(n == 2){
//             return max(nums[0],nums[1]);
//         }
//         // case - 1 Take first house 0th index house
//         memset(t,-1,sizeof(t));
//         int take_0th_house = solve(nums, 0, n - 2);
        
//         // case - 2 Take Sceond house 1th index house
//         memset(t,-1,sizeof(t));
//         int take_1th_house = solve(nums, 1, n-1);
//         return max(take_0th_house, take_1th_house);
//     }
// };

// Approach 3: Using Dynamic Programming (Tabulation) or Bottom-Up Approach
// Time Complexity: O(n) - Each state is computed once
// Space Complexity: O(n) - Due to the dp array
// class Solution {
// public:
//     int rob(vector<int>& nums) {
//         int n = nums.size();
//         if (n == 1) {
//             return nums[0];
//         }

//         vector<int> t(n + 1,0);

//         // case - 1: take 1th house and skip last house
//         t[0] = 0;
//         for (int i = 1; i <= n - 1; i++) {
//             int skip = t[i - 1];
//             int steal = nums[i - 1] + ((i - 2 >= 0 ? t[i - 2] : 0));
//             t[i] = max(skip, steal);
//         }
//         int result1 = t[n - 1];
//         t.clear();
//         // case - 2: skip 1th house and take last house
//         t[0] = 0;
//         t[1] = 0; // skip 1 house
//         for (int i = 2; i <= n; i++) {
//             int skip = t[i - 1];
//             int steal = nums[i - 1] + ((i - 2 >= 0 ? t[i - 2] : 0));
//             t[i] = max(skip, steal);
//         }
//         int result2 = t[n];
//         return max(result1, result2);
//     }
// };

// Approach 4: Using Dynamic Programming (Space Optimization)
// Time Complexity: O(n) - Each state is computed once
// Space Complexity: O(1) - Only a constant amount of space is used

class Solution {
public:
    int solve(vector<int>&nums, int l, int r){
        int prev = 0;
        int prevPrev = 0;
        for(int i = l; i<=r;i++){
            int skip = prev;
            int steal = nums[i] + prevPrev;
            int temp = max(skip,steal);
            prevPrev = prev;
            prev = temp;
        }
        return prev;
    }
    int rob(vector<int>& nums) {
        int n = nums.size();
        if(n == 1){
            return nums[0];
        }
        if(n == 2){
            return max(nums[0],nums[1]);
        }
        int take_first_house = solve(nums,0, n-2);
        int skip_first_house = solve(nums,1, n-1);
        return max(take_first_house,skip_first_house);
    }
};

// example usage
int main() {
    Solution sol;
    vector<int> nums = {2, 3, 2};
    cout << sol.rob(nums) << endl; // Output: 3
    return 0;
}