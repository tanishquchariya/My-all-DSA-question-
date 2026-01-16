// 1021. Remove Outermost Parentheses
#include<bits/stdc++.h>
using namespace std;

// Approach - 1 : Using Stack
// Time Complexity : O(N)
// Space Complexity : O(N)
// class Solution {
// public:
//     string removeOuterParentheses(string s) {
//         stack<char> st;
//         string ans = "";
//         for(char c : s) {
//             if(c == '(') {
//                 if(!st.empty()) {
//                     ans += c;
//                 }
//                 st.push(c);
//             } else {
//                 st.pop();
//                 if(!st.empty()) {
//                     ans += c;
//                 }
//             }
//         }
//         return ans;
//     }
// };


// Approach - 2 : Using Count Variable
// Time Complexity : O(N)
// Space Complexity : O(1)
class Solution {
public:
    string removeOuterParentheses(string s) {
        int count = 0;
        string ans = "";
        for(char c : s) {
            if(c == '(') {
                if(count > 0) {
                    ans += c;
                }
                count++;
            } else {
                count--;
                if(count > 0) {
                    ans += c;
                }
            }
        }
        return ans;
    }
};


// Example Usage
int main() {
    Solution sol;
    string s = "(()())(())";
    cout << sol.removeOuterParentheses(s) << endl; // Output: "()()()"
    return 0;
}