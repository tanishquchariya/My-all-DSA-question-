// Valid Anagram : Given two strings s and t, return true if t is an anagram of s, and false otherwise.

#include <bits/stdc++.h>
using namespace std;

// Approach - 1 : Using Sorting
// Time Complexity : O(N log N) where N is the length of the strings
// Space Complexity : O(1)

// class Solution
// {
// public:
//     bool isAnagram(string s, string t)
//     {
//         if (s.size() != t.size())
//         {
//             return false;
//         }
//         sort(s.begin(), s.end());
//         sort(t.begin(), t.end());
//         return s == t;
//     }
// };

// Approach - 2 : Using Hash Map
// Time Complexity : O(N) where N is the length of the strings
// Space Complexity : O(1)
// class Solution
// {
// public:
//     bool isAnagram(string s, string t)
//     {
//         if (s.size() != t.size())
//         {
//             return false;
//         }
//         unordered_map<char, int> freq;
//         for (int i = 0; i < s.size(); i++)
//         {
//             freq[s[i]]++;
//         }
//         for (int i = 0; i < t.size(); i++)
//         {
//             freq[t[i]]--;
//         }
//         for (auto it : freq)
//         {
//             if (it.second != 0)
//             {
//                 return false;
//             }
//         }
//         return true;
//     }
// };

// or map code can be written as :

// class Solution {
// public:
//     bool isAnagram(string s, string t) {
//         if (s.size() != t.size()) {
//             return false;
//         }

//         unordered_map<char, int> mp;

//         // Count characters of s
//         for (int i = 0; i < s.size(); i++) {
//             char ch = s[i];
//             mp[ch]++;
//         }

//         // Subtract characters of t
//         for (int i = 0; i < t.size(); i++) {
//             char ch = t[i];
//             mp[ch]--;
//         }

//         // Check all values in map
//         for (auto it = mp.begin(); it != mp.end(); it++) {
//             if (it->second != 0) {
//                 return false;
//             }
//         }

//         return true;
//     }
// };

// Approach - 3 : Using Frequency Count
// Time Complexity : O(N) where N is the length of the strings
// Space Complexity : O(1)
 
class Solution
{
public:
    bool isAnagram(string s, string t)
    {
        if (s.size() != t.size())
        {
            return false;
        }
        vector<int> freq(26, 0);
        for (int i = 0; i < s.size(); i++)
        {
            freq[s[i] - 'a']++;
        }
        for (int i = 0; i < t.size(); i++)
        {
            freq[t[i] - 'a']--;
        }
        for (int count : freq)
        {
            if (count != 0)
            {
                return false;
            }
        }
        return true;
    }
};

// Example Usage
int main()
{
    Solution sol;
    string s = "anagram";
    string t = "nagaram";
    cout << sol.isAnagram(s, t) << endl; // Output: true
    return 0;
}
