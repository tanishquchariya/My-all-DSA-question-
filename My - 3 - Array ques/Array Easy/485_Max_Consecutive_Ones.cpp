#include<bits/stdc++.h>
using namespace std;

// Approch - 1 optimal solution
// time complexity - O(n) and space complexity - O(1)
int maxConsecutiveOnes(vector<int>& nums) {
    int Count = 0, ans = 0;
    int n = nums.size();
    if (n == 0) return 0; // Handle empty array case
    for (int i = 0; i < n; i++) {
        if (nums[i] == 1) {
            Count++;
            ans = max(ans, Count);
        } else {
            Count = 0;
        }
    }
    return ans;
}

// Example usage
int main() { 
    vector<int> nums = {1, 0, 1, 1, 1, 0, 1, 1};
    int result = maxConsecutiveOnes(nums);
    cout << "Maximum consecutive ones: " << result << endl;
    return 0;
}