// Group Anagrams

#include <bits/stdc++.h>
using namespace std;

// Approach - 1: Sorting Each String
// Time Complexity: O(N * K log K) where N is the number of strings and K is the maximum length of a string
// Space Complexity: O(N * K) for the output list

// class Solution {
// public:
//     vector<vector<string>> groupAnagrams(vector<string>& strs) {
//         unordered_map<string, vector<string>> mp;
//         vector<vector<string>> result;

//         for (int i = 0; i < strs.size(); i++) {
//             string temp = strs[i];
//             sort(temp.begin(), temp.end());
//             mp[temp].push_back(strs[i]);
//         }
//         for (auto it : mp) {
//             result.push_back(it.second);
//         }
//         return result;
//     }
// };

// Approach - 2: Using Character Count as Key
// Time Complexity: O(N * K) where N is the number of strings and K is the maximum length of a string
// Space Complexity: O(N * K) for the output list and the hashmap

class Solution {
public:

string generate(string & word){
    int arr[26] = {0};
    for(char c : word){
        arr[c - 'a']++;
    }
    string new_word = "";
    for(int i = 0; i< 26; i++){
        int freq = arr[i];
        if(freq > 0){

            new_word += string(freq, 'a' + i);
        }
    }
    return new_word;
}

vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> mp;
        vector<vector<string>> result;
        int n = strs.size();

        for (int i = 0; i < n; i++) {
            string word = strs[i];
            string new_word = generate(word);
            mp[new_word].push_back(strs[i]);
        }
        for (auto it : mp) {
            result.push_back(it.second);
        }
        return result;
    }
};
// example usage
int main() {
    Solution sol;
    vector<string> strs = {"eat", "tea", "tan", "ate", "nat", "bat"};
    vector<vector<string>> groupedAnagrams = sol.groupAnagrams(strs);

    for (const auto& group : groupedAnagrams) {
        for (const auto& str : group) {
            cout << str << " ";
        }
        cout << endl;
    }

    return 0;
}