// Minimum Remove to Make Valid Parentheses


#include <bits/stdc++.h>
using namespace std;

// Approach: Two Pass String Construction
// Time Complexity: O(n)
// Space Complexity: O(n)

class Solution {
public:
    string minRemoveToMakeValid(string s) {
        if(s.size() == 0){
            return "";
        }
        int open = 0;
        int close = 0;
        string ans = "";
        for (int i = 0; i < s.size(); i++) {
            if (s[i] == '(') {
                open++;
            } else if (s[i] == ')') {
                if (open > 0) {
                    open--;
                } else {
                    continue;
                }
            }
            
            ans += s[i];
        }
        string Ans = "";
        for(int i = ans.size() - 1; i >= 0; i--){
            if(ans[i] == '(' && open > 0){
                open--;
            }else{
                Ans += ans[i];
            }
        }
        reverse(Ans.begin(), Ans.end());
        return Ans;
    }
};

// 