// Repeated Substring Pattern 

#include <iostream>
#include <string>
using namespace std;
// Approach - 1 : Using String Manipulation
// Time Complexity : O(N) where N is the length of the string
// Space Complexity : O(N) for the new string
// class Solution
// {
// public:
//     bool repeatedSubstringPattern(string s)
//     {
//         string str = s + s;
//         string sub = str.substr(1, str.size() - 2);
//         if (sub.find(s) != string::npos)
//         {
//             return true;
//         }
//         return false;
//     }
// };  

// Approach - 2 : Using Mathematical Insight
// Time Complexity : O(N) where N is the length of the string
// Space Complexity : O(1)
class Solution {
public:
    bool repeatedSubstringPattern(string s) {
        int n = s.size();

        for (int l = n / 2; l >= 1; l--) {
            string pattern = "";
            if (n % l == 0) {
                int time = n / l;
                while (time--) {
                    pattern += s.substr(0, l);
                }

                if (s == pattern) {
                    return true;
                }
            }
        }
        return false;
    }
};

// Example Usage

int main() {
    Solution sol;
    string s = "abcabcabcabc";
    cout << sol.repeatedSubstringPattern(s) << endl; // Output: true
    return 0;
}   
