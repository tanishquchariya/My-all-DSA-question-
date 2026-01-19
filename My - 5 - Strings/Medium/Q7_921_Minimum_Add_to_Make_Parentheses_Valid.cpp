// Minimum Add to Make Parentheses Valid

#include <bits/stdc++.h>
using namespace std;


// Approach 1: Using Stack
// Time Complexity: O(n)
// Space Complexity: O(n)
// class Solution {
// public:
//     int minAddToMakeValid(string s) {
//         stack<char> st;
//         for (char c : s) {
//             if (c == '(') {
//                 st.push(c);
//             } else {
//                 if (!st.empty() && st.top() == '(') {
//                     st.pop();
//                 } else {
//                     st.push(c);
//                 }
//             }
//         }
//         return st.size();
//     }
// };

// Approach 2: Using Counters
// Time Complexity: O(n)
// Space Complexity: O(1)

class Solution {
public:
    int minAddToMakeValid(string s) {
        int open = 0;
        int close = 0;
        for(int i = 0; i<s.size(); i++){
            if(s[i] == '('){
                open++;
            }else if(open > 0 && s[i] == ')'){
                open--;
            }else{
                close++;
            }
        }
        return open + close;
    }
};

// example usage

int main() {
    Solution sol;
    string s = "())()()";
    cout << sol.minAddToMakeValid(s) << endl; // Output: 1
    return 0;
}