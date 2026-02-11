// sort characters by frequency : it is a problem to sort the characters of a string in decreasing order based on their frequency.
// The frequency of a character is the number of times it appears in the string.

#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>
#include <algorithm>
using namespace std;

// Approach - 1 : Using without map
// Time Complexity : O(N log N) where N is the length of the string
// Space Complexity : O(N) for the sorted vector

// class Solution
// {
// public:
//     string frequencySort(string s)
//     {
//         vector<pair<char, int>> vec(123);
//         for (int i = 0; i < s.size(); i++)
//         {
//             int freq = vec[s[i]].second;
//             vec[s[i]] = {s[i], freq + 1};
//         }
//         sort(vec.begin(), vec.end(), [](const pair<char, int> &a, const pair<char, int> &b)
//              {
//                  return a.second > b.second; // Sort in decreasing order of frequency
//              });
//         string ans = "";
//         for (int i = 0; i <= 122; i++)
//         {

//             if (vec[i].second > 0)
//             {
//                 char ch = vec[i].first;
//                 int count = vec[i].second;
//                 string temp = string(count, ch); // Create a string with 'count' occurrences of 'ch'
//                 ans += temp;                     // Append the string to the result
//             }
//         }
//         return ans;
//     }
// };

// Approach - 2 : Using Hash Map and Sorting
// Time Complexity : O(N log N) where N is the length of the string
// Space Complexity : O(N) for the hash map and the sorted vector
// class Solution {
// public:
//     string frequencySort(string s) {
//         unordered_map<char, int> freq;
//         for (char c : s) {
//             freq[c]++;
//         }
//         vector<pair<char, int>> vec(freq.begin(), freq.end());
//         sort(vec.begin(), vec.end(), [](const pair<char, int>& a, const pair<char, int>& b) {
//             return a.second > b.second; // Sort in decreasing order of frequency
//         });
//         string ans = "";
//         for (const auto& p : vec) {
//             ans += string(p.second, p.first); // Append character p.second times
//         }
//         return ans;
//     }
// };
// or
class Solution {
public:
    string frequencySort(string s) {

        // Step 1: Count frequency of each character
        unordered_map<char, int> freq;
        for (int i = 0; i < s.size(); i++) {
            char ch = s[i];
            freq[ch]++;
        }

        // Step 2: Copy map into a vector of pairs
        vector<pair<char, int>> vec;
        for (auto it = freq.begin(); it != freq.end(); it++) {
            vec.push_back({it->first, it->second});
        }

        // Step 3: Sort vector by frequency in decreasing order

        // for (int i = 0; i < vec.size(); i++) {
        //     for (int j = i + 1; j < vec.size(); j++) {
        //         if (vec[j].second > vec[i].second) {
        //             swap(vec[i], vec[j]);
        //         }
        //     }
        // }
        // or
        sort(vec.begin(), vec.end(), [](const pair<char, int>& a, const pair<char, int>& b) {
            return a.second > b.second; // Sort in decreasing order of frequency
        });

        // Step 4: Build the result string
        string ans = "";
        for (int i = 0; i < vec.size(); i++) {
            char ch = vec[i].first;
            int count = vec[i].second;
            for (int j = 0; j < count; j++) {
                ans += ch;   // Append character one by one
            }
        }

        return ans;
    }
};



// example usage

int main()
{
    Solution sol;
    string s = "tree";
    cout << sol.frequencySort(s) << endl; // Output: "eert"
    return 0;
}