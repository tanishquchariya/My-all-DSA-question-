// String to Integer (atoi) :- in which we have to convert a string to an integer and return the integer value. 
// We have to take care of some edge cases like if the string is empty or if it contains non-numeric characters.


#include <iostream>
#include <string>
#include <sstream>
#include <climits>
#include <cmath>
using namespace std;


// // Approach 1: Using built-in function stoi
// // Time Complexity: O(n) - where n is the length of the string
// // Space Complexity: O(1) - No extra space is used

// class Solution {
// public:
//     int myAtoi(string s) {
//         try {
//             return stoi(s);
//         } catch (const std::exception& e) {
//             return 0; // Return 0 if conversion fails
//         }
//     }
// };

// // Approach 2: using stringstream
// // Time Complexity: O(n) - where n is the length of the string
// // Space Complexity: O(1) - No extra space is used

// class Solution {
// public:
//     int myAtoi(string s) {
//         stringstream ss(s);
//         long long result = 0;
//         ss >> result;
//         if (ss.fail()) {
//             return 0; // Return 0 if conversion fails
//         }
//         if (result > INT_MAX) return INT_MAX;
//         if (result < INT_MIN) return INT_MIN;
//         return result;
//     }
// };

// Approach 3: Manual parsing
// Time Complexity: O(n) - where n is the length of the string
// Space Complexity: O(1) - No extra space is used
class Solution {
public:
    int myAtoi(string s) {
        int i = 0, sign = 1;
        long long ans = 0;

        // Skip leading whitespaces
        while (i < s.size() && s[i] == ' ') {
            i++;
        }

        // Check for optional sign
        if (i < s.size() && (s[i] == '+' || s[i] == '-')) {
            if(s[i] == '-') {
                sign = -1;
            }   
            i++;
        }

        // Convert characters to integer
        while (i < s.size() && isdigit(s[i])) {
            ans = ans * 10 + (s[i] - '0');
            if (ans * sign > INT_MAX) return INT_MAX;
            if (ans * sign < INT_MIN) return INT_MIN;
            i++;
        }

        return ans * sign;
    }
};

// example usage
int main() {
    Solution sol;
    string s = "   -42";
    int result = sol.myAtoi(s);
    cout << "The integer value is: " << result << endl; // Output: -42
    return 0;
}   


