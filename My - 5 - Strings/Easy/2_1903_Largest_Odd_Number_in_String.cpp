#include<bits/stdc++.h>
using namespace std;

// Approach - 1 : Find the largest odd number by checking digits from the end
// Time Complexity : O(N)
// Space Complexity : O(1)
// class Solution {
// public:
//     string largestOddNumber(string num) {
//         for(int i = num.size() - 1; i >= 0; i--) {
//             if((num[i] - '0') % 2 != 0) {
//                 return num.substr(0, i + 1);
//             }
//         }
//         return "";
//     }
// };

// Approach - 2 : Find the largest odd number by checking digits from the start
// Time Complexity : O(N)
// Space Complexity : O(1)  
class Solution {
public:
    string largestOddNumber(string num) {
        int n = num.size();
        for(int i = 0; i < n; i++) {
            if((num[n - 1 - i] - '0') % 2 != 0) {
                return num.substr(0, n - i);
            }
        }
        return "";
    }
};


// Example usage
int main() {
    Solution sol;
    string num = "35427";
    cout << "Largest odd number in the string: " << sol.largestOddNumber(num) << endl; // Output: 35427
    return 0;
}