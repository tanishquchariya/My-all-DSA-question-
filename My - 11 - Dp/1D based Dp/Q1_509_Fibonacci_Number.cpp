// Fibonacci Number  :- see the pattern of the Fibonacci series and find the nth number in the series.

#include <iostream>
#include <vector>
using namespace std;

// // Approach 1: Using Recursion or Brute Force
// // Time Complexity: O(2^n) - Exponential time complexity
// // Space Complexity: O(n) - Due to the recursion stack

// class solution {
// public:
//     int fib(int n) {
//         if (n <= 1) {
//             return n;
//         }
//         return fib(n - 1) + fib(n - 2);
//     }
// };

// // Approach 2: Using Dynamic Programming (Memoization) OR Top-Down Approach
// // Time Complexity: O(n) - Each Fibonacci number is computed once
// // Space Complexity: O(n) - Due to the recursion stack and memoization array
// class solution {
// public:
//     int solve(int n, vector<int>& dp) {
//         if (n <= 1) {
//             return n;
//         }
//         if (dp[n] != -1) {
//             return dp[n];
//         }
//         dp[n] = solve(n - 1, dp) + solve(n - 2, dp);
//         return dp[n];
//     }
//     int fib(int n) {
//         vector<int> dp(n + 1, -1);
//         return solve(n, dp);
//     }
// };

// // Approach 3: Using Dynamic Programming (Tabulation) or Bottom-Up Approach
// // Time Complexity: O(n) - Each Fibonacci number is computed once
// // Space Complexity: O(n) - Due to the dp array

// class solution {
// public:
//     int fib(int n) {
//         if (n <= 1) {
//             return n;
//         }
//         vector<int> dp(n + 1, -1);
//         dp[0] = 0;
//         dp[1] = 1;
//         for (int i = 2; i <= n; i++) {
//             dp[i] = dp[i - 1] + dp[i - 2];
//         }
//         return dp[n];
//     }
// };

// Approach 4: Using Dynamic Programming (Space Optimization)
// Time Complexity: O(n) - Each Fibonacci number is computed once
// Space Complexity: O(1) - Only a constant amount of space is used
class solution {
public:
    int fib(int n) {
        if (n <= 1) {
            return n;
        }
        int a = 0, b = 1, c;
        for (int i = 1; i < n; i++) {
            c = a + b;
            a = b;
            b = c;
        }
        return c;
    }
};

// example usage
int main() {
    solution sol;
    int n = 6;
    cout << "The " << n << "th Fibonacci number is: " << sol.fib(n) << endl;
    return 0;
}