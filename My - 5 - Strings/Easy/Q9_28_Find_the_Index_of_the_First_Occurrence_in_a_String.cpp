// find the index of the first occurrence in a string

#include <bits/stdc++.h>
using namespace std;

// Approach - 1 : Using inbuilt function find
// Time Complexity : O(N) where N is the length of the string
// Space Complexity : O(1)
// class Solution
// {
// public:
//     int strStr(string haystack, string needle)
//     {
//         return haystack.find(needle);
//     }
// };

// Approach - 2 : Using brute force
// Time Complexity : O(N * M) where N is the length of the haystack and M is the length of the needle
// Space Complexity : O(1)
class Solution
{
public:
    int strStr(string haystack, string needle)
    {
        int m = haystack.size();
        int n = needle.size();
        for (int i = 0; i <= m - n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (haystack[i + j] != needle[j])
                    break;
                if (j == n - 1)
                {
                    return i;
                }
            }
        }
        return -1;
    }
};

// example usage
int main()
{
    Solution sol;
    string haystack = "sadbutsad";
    string needle = "sad";
    cout << "Index of first occurrence: " << sol.strStr(haystack, needle) << endl; // Output: 0
    return 0;
}
