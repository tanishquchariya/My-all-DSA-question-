// Valid Palindrome II : Given a string s, return true if it is a palindrome, or false otherwise.

#include <iostream>
using namespace std;
// Approach - 1 : Using two pointers
// Time Complexity : O(N) where N is the length of the string
// Space Complexity : O(1)

class Solution {
public:
    bool checkPalidrome(string s){
        int i = 0;
        int j = s.size() - 1;
        while(i<=j){
            if(s[i] != s[j]){
                return false;
            }
            i++;
            j--;
        }
        return true;

    }
    bool validPalindrome(string s) {
        int l = 0;
        int r = s.size() - 1;
        if(checkPalidrome(s)){
            return true;
        }
        while(l<=r){
            if(s[l] == s[r]){
                l++;
                r--;
            }else{
                return checkPalidrome(s.substr(l,r-l)) || checkPalidrome(s.substr(l+1,r-l));
            }
        } 
        return false;
    }
};


// Example usage
int main() {
    Solution sol;
    string s = "abcdeca";
    cout << sol.validPalindrome(s) << endl; // Output: true
    return 0;
}