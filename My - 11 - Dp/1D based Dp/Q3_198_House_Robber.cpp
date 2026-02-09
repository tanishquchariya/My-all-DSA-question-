// House Robber - see the pattern of the maximum amount of money that can be robbed from houses without robbing adjacent houses.

#include <iostream>
#include <vector>
#include <cstring>
using namespace std;

// // Approach 1: Using Recursion or Brute Force
// // Time Complexity: O(2^n) - Exponential time complexity
// // Space Complexity: O(n) - Due to the recursion stack

// class solution {
// public:
//     int solve(vector<int>& nums, int i, int n) {
//         if (i >= n) {
//             return 0;
//         }
//         int rob = nums[i] + solve(nums, i + 2, n);
//         int notRob = solve(nums, i + 1, n);
//         return max(rob, notRob);
//     }
//     int rob(vector<int>& nums) {

//         int n = nums.size();
//         return solve(nums, 0, n);
        
//     }
// };

// Approach 2: Using Dynamic Programming (Memoization) OR Top-Down Approach
// Time Complexity: O(n) - Each state is computed once
// Space Complexity: O(n) - Due to the recursion stack and memoization array

// class Solution {
// public: 
//     int dp[100000];
//      int solve(vector<int>& nums, int i, int n) {
//         if (i >= n) {
//             return 0;
//         }
//         if(dp[i] != -1){
//             return dp[i];
//         }
//         int rob = nums[i] + solve(nums, i + 2, n);
//         int notRob = solve(nums, i + 1, n);
//         return dp[i] = max(rob, notRob);
//     }

//     int rob(vector<int>& nums) {

//         int n = nums.size();
//         memset(dp, -1, sizeof(dp));
//         return solve(nums, 0, n);
        
//     }
// };

// or without memset() we can initialize the dp array with -1 in the constructor of the class
// class Solution {
// public:
//     int solve(vector<int>& nums, int i, vector<int>& dp) {
//         if (i >= nums.size()) {
//             return 0;
//         }

//         if (dp[i] != -1) {
//             return dp[i];
//         }

//         int rob = nums[i] + solve(nums, i + 2, dp);
//         int notRob = solve(nums, i + 1, dp);

//         return dp[i] = max(rob, notRob);
//     }

//     int rob(vector<int>& nums) {
//         int n = nums.size();
//         vector<int> dp(n, -1);   // replaces memset
//         return solve(nums, 0, dp);
//     }
// };

// Approach 3: Using Dynamic Programming (Tabulation) or Bottom-Up Approach
// Time Complexity: O(n) - Each state is computed once
// Space Complexity: O(n) - Due to the dp array
// class Solution {
// public:
//     int rob(vector<int>& nums) {
//         int n = nums.size();
//         if(n == 0){
//             return nums[0];
//         }
//         vector<int> t(n + 1, 0);
//         // no house : i = 0
//         t[0] = 0;
//         // 1 house : i = 1
//         t[1] = nums[0];
//         for (int i = 2; i <= n; i++) {
//             int steal = nums[i - 1] + t[i - 2];
//             int skip = t[i - 1];
//             t[i] = max(steal, skip);
//         }
//         return t[n];
//     }
// };

// Approach 4: Using Dynamic Programming (Space Optimization)
// Time Complexity: O(n) - Each state is computed once
// Space Complexity: O(1) - Only a constant amount of space is used
class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        if(n == 0){
            return nums[0];
        }
        int prev2 = 0; // t[i-2]
        int prev1 = 0; // t[i-1]
        for (int i = 0; i < n; i++) {
            int curr = max(prev1, prev2 + nums[i]); // t[i] = max(steal, skip);
            prev2 = prev1;
            prev1 = curr;
        }
        return prev1; // t[n]
    }
};

// Example usage
int main() {
    Solution sol;
    vector<int> nums = {1, 2, 3, 1};
    cout << sol.rob(nums) << endl; // Output: 4
    return 0;
}