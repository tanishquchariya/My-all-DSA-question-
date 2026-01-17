// Rotate String : Given two strings s and goal, return true if and only if s can become goal after some number of shifts on s.

#include <bits/stdc++.h>
using namespace std;

// Apprach - 1 : Using brute force to check all rotations
// Time Complexity : O(N^2) where N is the length of the string
// Space Complexity : O(1)

// class Solution
// {
//     bool rotateString(string s, string goal)
//     {
//         if (s.size() != goal.size())
//         {
//             return false;
//         }
//         for (int i = 0; i < goal.size(); i++)
//         {
//             bool rotationPossible = true;
//             for (int j = 0; j < s.size(); j++)
//             {
//                 if (goal[(i + j) % goal.size()] != s[j])
//                 {
//                     rotationPossible = false;
//                     break;
//                 }
//             }
//             if (rotationPossible)
//             {
//                 return true;
//             }
//         }
//         return false;
//     }
// };

// Approach - 2 : Using String Concatenation
// Time Complexity : O(N) where N is the length of the string
// Space Complexity : O(N) for the concatenated string
class Solution
{
public:
    bool rotateString(string s, string goal)
    {
        if (s.size() != goal.size())
        {
            return false;
        }
        string ans = s + s;

        if (ans.find(goal) == string::npos)
        {
            return false;
        }
        else
        {
            return true;
        }
    }
};

// Example Usage
int main()
{
    Solution sol;
    string s = "abcde";
    string goal = "deabc";
    cout << boolalpha << sol.rotateString(s, goal) << endl; // Output: true
    return 0;
}
