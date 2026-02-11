// longest palindromic substring :- in which we have to find the longest palindromic substring in a given string
// we can solve this problem by using the brute force approach in which we will check for all

#include <bits/stdc++.h>
using namespace std;  

// Approach 1 :- Brute Force Approach
// we will check for all the possible substrings of the given string and check if they are         


// class Solution {
// public:
//     string longestPalindrome(string s) {
//         int n = s.size();
//         string ans = "";
//         for(int i=0; i<n; i++){
//             for(int j=i; j<n; j++){
//                 string temp = s.substr(i, j-i+1);
//                 string rev = temp;
//                 reverse(rev.begin(), rev.end());
//                 if(temp == rev){
//                     if(temp.size() > ans.size()){
//                         ans = temp;
//                     }
//                 }
//             }
//         }
//         return ans;
//     }
// };

// Approach 2 :- using two different cases for odd and even length palindromes
// Time Complexity :- O(n^2) and Space Complexity :- O(1)

class Solution {
public:
    string longestPalindrome(string s) {
        int n = s.size();
        int st = 0; // starting index
        int low;
        int high;
        int len = 1;

        for (int i = 1; i < n; i++) {
            // even case
            low = i;
            high = i - 1;
            while (low >= 0 && high < n && s[low] == s[high]) {
                if (high - low + 1 > len) {
                    st = low;
                    len = high - low + 1;
                }
                low--;
                high++;
            }

            // odd case
            low = i + 1;
            high = i - 1;
            while (low >= 0 && high < n && s[low] == s[high]) {
                if (high - low + 1 > len) {
                    st = low;
                    len = high - low + 1;
                }
                low--;
                high++;
            }
        }
        return s.substr(st, len);
    }
};

// example usecase
int main() {
    Solution sol;
    string s = "babad";
    cout << sol.longestPalindrome(s) << endl; // Output: "aba" or "bab"
    return 0;
}