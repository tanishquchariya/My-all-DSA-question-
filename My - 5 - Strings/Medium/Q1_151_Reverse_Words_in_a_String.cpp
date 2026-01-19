// reverse words in a string

#include <bits/stdc++.h>

using namespace std;


// Approach - 1 : Using using reverse function (optimized solution)
// Time Complexity : O(N) where N is the length of the string
// Space Complexity : O(1)

// class Solution {
// public:
//     string reverseWords(string s) {
//         reverse(s.begin(), s.end());
//         int start = 0;
//         for (int i = 0; i <= s.size(); i++) {
//             if (i == s.size() || s[i] == ' ') {
//                 reverse(s.begin() + start, s.begin() + i);
//                 start = i + 1;
//             }
//         }
//         return s;
//     }
// };

// Approach - 2 : Using two pointers
// Time Complexity : O(N) where N is the length of the string
// Space Complexity : O(1)
// class Solution {
// public:
//     string reverseWords(string s) {
//         int n = s.size();
//         reverse(s.begin(), s.end());
//         int i = 0;
//         int l = 0;
//         int r = 0;
//         while(i<n){
//             while(i<n && s[i] != ' '){
//                 s[r] = s[i];
//                 r++;
//                 i++;
//             }
//             if(l<r){
//                 reverse(s.begin() + l, s.begin() + r);
//                 s[r] = ' ';
//                 r++;
//                 l = r;
//             }
//             i++;
//         }
//         s = s.substr(0, r-1);
//         return s;
//     }
// };

// Apprach - 3 : Using stringstream
// Time Complexity : O(N) where N is the length of the string
// Space Complexity : O(N)

class Solution {
public:
    string reverseWords(string s) {
        stringstream s_s(s);
        string token = "";
        string result = "";

        while(s_s >> token){
            result = token + " " + result;
        }
        return result.substr(0,result.size() - 1);
    }
};

// Example usage
int main() {
    Solution sol;
    string s = "the sky is blue";
    cout << sol.reverseWords(s) << endl; // Output: "blue is sky the"
    return 0;
}
