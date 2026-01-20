// Longest Substring Without Repeating Characters

#include <bits/stdc++.h>
using namespace std;

// Approach: Sliding Window with HashSet
// Time Complexity: O(n)
// Space Complexity: O(min(m, n)) where m is the size of the character set and n is the length of the string

// class Solution {
// public:
//     int lengthOfLongestSubstring(string s) {
//         int n = s.size();
//         if(n == 0){
//             return 0;
//         }
//         unordered_set<char> st;
//         int l = 0;
//         int maxans = INT_MIN;
//         for (int r = 0; r < n; r++) {
//             // if char present in map
//             if (st.find(s[r]) != st.end()) {
//                 while (l < r && st.find(s[r]) != st.end()) {
//                     st.erase(s[l]);
//                     l++;
//                 }
//             }
//             st.insert(s[r]);
//             maxans = max(maxans, r - l + 1);
//         }
//         return maxans;
//     }
// };

// Apprach 2: Sliding Window with Map
// Time Complexity: O(n)
// Space Complexity: O(min(m, n)) where m is the size of the character set and n is the length of the string
class Solution2 {
public:
    int lengthOfLongestSubstring(string s) {
        int n = s.size();
        if(n == 0){
            return 0;
        }
        unordered_map<char, int> mp;
        int l = 0;
        int maxans = INT_MIN;
        for (int r = 0; r < n; r++) {
            // if char present in map
            if (mp.find(s[r]) != mp.end()) {
                l = max(mp[s[r]] + 1, l);
            }
            mp[s[r]] = r;
            maxans = max(maxans, r - l + 1);
        }
        return maxans;
    }
};