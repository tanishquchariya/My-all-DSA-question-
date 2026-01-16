// Isomorphic Strings :- it is a problem to check whether two strings are isomorphic or not.
// Two strings s and t are isomorphic if the characters in s can be replaced to get t.
// All occurrences of a character must be replaced with another character while preserving the order of characters.

#include <bits/stdc++.h>
using namespace std;

// Approach - 1 : Using two maps to store the mapping of characters from s to t and t to s
// Time Complexity : O(N) where N is the length of the strings
// Space Complexity : O(1) as the size of the maps will be at most 256 (number of ASCII characters)
class Solution
{
public:
    bool isIsomorphic(string s, string t)
    {
        if (s.size() != t.size())
            return false;
        unordered_map<char, char> mp1, mp2;
        for (int i = 0; i < s.size(); i++)
        {
            char c1 = s[i];
            char c2 = t[i];
            if (mp1.find(c1) != mp1.end() && mp1[c1] != c2 || mp2.find(c2) != mp2.end() && mp2[c2] != c1)
            {
                return false;
            }
            mp1[c1] = c2;
            mp2[c2] = c1;
        }
        return true;
    }
};


// Example Usage
int main() {
    Solution sol;
    string s = "egg";
    string t = "add";
    cout << sol.isIsomorphic(s, t) << endl; // Output: true
    return 0;
}