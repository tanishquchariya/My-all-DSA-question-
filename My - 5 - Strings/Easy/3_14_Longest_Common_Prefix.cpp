#include <bits/stdc++.h>
using namespace std;

// Approach - 1 : using horizontal scanning
// Time Complexity : O(N * M) where N is the number of strings and M is the length of the smallest string
// Space Complexity : O(1)
// class Solution {
// public:
//     string longestCommonPrefix(vector<string>& strs) {
//         if(strs.empty()) return "";
//         string prefix = strs[0];
//         for(int i = 1; i < strs.size(); i++) {
//             while(strs[i].find(prefix) != 0) {
//                 prefix = prefix.substr(0, prefix.size() - 1);
//                 if(prefix.empty()) return "";
//             }
//         }
//         return prefix;
//     }
// };

// Approach - 2 : using vertical scanning
// Time Complexity : O(N * M) where N is the number of strings and M is the length of the smallest string
// Space Complexity : O(1)
// class Solution {
// public:
//     string longestCommonPrefix(vector<string>& strs) {
//         if(strs.empty()) return "";
//         for(int i = 0; i < strs[0].size(); i++) {
//             char c = strs[0][i];
//             for(int j = 1; j < strs.size(); j++) {

//                 if(i == strs[j].size() || strs[j][i] != c) {
//                     return strs[0].substr(0, i);
//                 }
//             }
//         }
//         return strs[0];
//     }
// };

// approach - 3 : using vertical scanning with a flag
// Time Complexity : O(N * M) where N is the number of strings and M is the length of the smallest string
// Space Complexity : O(1)

class Solution
{
public:
    string longestCommonPrefix(vector<string> &strs)
    {
        if (strs.empty())
            return "";
        string ans = "";
        for (int i = 0; i < strs[0].size(); i++)
        {
            char c = strs[0][i];
            bool match = true;
            for (int j = 1; j < strs.size(); j++)
            {
                // if not match
                if (i == strs[j].size() || strs[j][i] != c)
                {
                    match = false;
                    break;
                }
            }
            if (!match)
            {
                break;
            }
            else
            {
                ans.push_back(c);
            }
        }
        return ans;
    }
};

// Example usage
int main()
{
    Solution sol;
    vector<string> strs = {"flower", "flow", "flight"};
    cout << "Longest Common Prefix: " << sol.longestCommonPrefix(strs) << endl; // Output: "fl"
    return 0;
}