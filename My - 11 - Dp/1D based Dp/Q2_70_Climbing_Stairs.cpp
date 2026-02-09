// Climbing Stairs - see the pattern of the number of ways to climb stairs and find the number of ways to reach the nth stair.

#include <iostream>
#include <vector>
using namespace std;

// // Approach 1: Using Recursion or Brute Force
// // Time Complexity: O(2^n) - Exponential time complexity
// // Space Complexity: O(n) - Due to the recursion stack

// class solution {
// public:
//     int climbStairs(int n) {
//         if (n < 0) {
//             return 0;
//         }
//         if (n == 0) {   
//             return 1;
//         }
//         return climbStairs(n - 1) + climbStairs(n - 2);
//     }
// };

// // Approach 2: Using Dynamic Programming (Memoization) OR Top-Down Approach
// // Time Complexity: O(n) - Each state is computed once
// // Space Complexity: O(n) - Due to the recursion stack and memoization array
// class Solution {
// public:
//     int solve(int n, vector<long long>& dp){
//         if(n<0){
//             return 0;
//         }
//         if(n == 0){
//             return 1;
//         }
//         if(dp[n] != -1){
//             return dp[n];
//         }
//         return dp[n] = solve(n-1,dp) + solve(n-2,dp);
//     }
//     int climbStairs(int n) {
//         if(n<0){
//             return 0;
//         }
//         if(n == 0){
//             return 1;
//         }
//         vector<long long>dp(n+1, -1);
//         return solve(n,dp);
//     }
// };
// //Approach 3: Using Dynamic Programming (Tabulation) or Bottom-Up Approach
// // Time Complexity: O(n) - Each state is computed once
// // Space Complexity: O(n) - Due to the dp array

// class Solution {
// public:
//     int climbStairs(int n) {
//         if(n<0){
//             return 0;
//         }
//         if(n == 0){
//             return 1;
//         }
//         vector<long long>dp(n+1, -1);
//         dp[0] = 1;
//         dp[1] = 1;
//         for(int i=2; i<=n; i++){
//             dp[i] = dp[i-1] + dp[i-2];
//         }
//         return dp[n];
//     }
// };

// Approach 4: Using Dynamic Programming (Space Optimization)
// Time Complexity: O(n) - Each Fibonacci number is computed once
// Space Complexity: O(1) - Only a constant amount of space is used

class Solution {
public:
    int climbStairs(int n) {
       if(n <= 0){
        return 0;
       }    
       int a = 0;
       int b = 1;
       int c;
       for(int i = 1; i<=n; i++){
        c = a + b;
        a = b;
        b = c;
       }
       return c;
    }
};

// exmple usage

int main() {
    Solution sol;
    int n = 4;
    cout << sol.climbStairs(n) << endl; // Output: 5
    return 0;
}