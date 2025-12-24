#include<bits/stdc++.h>
using namespace std;

// approach - 1 using brute force 
// the time complexity of this approach is O(n^2) and space complexity is O(n)
// vector<int> runningSum(vector<int>& nums) {
//     vector<int> ans;
//     int sum = 0;
//     for(int i = 0; i < nums.size(); i++) {
//         sum += nums[i];
//         ans.push_back(sum);
//     }
//     return ans;
// }


// approach - 2 using prefix sum (optimal solution)
// vector<int> runningSum(vector<int>& nums) {
//     vector<int> ans(nums.size());
//     ans[0] = nums[0];
//     for(int i = 1; i < nums.size(); i++) {
//         ans[i] = ans[i - 1] + nums[i];
//     }
//     return ans;
// }
// approach - 3 using in-place modification
vector<int> runningSum(vector<int>& nums) {
    for(int i = 1; i < nums.size(); i++) {
        nums[i] += nums[i - 1];
    }
    return nums;
}

// example usage
int main() {    
    vector<int> nums = {1, 2, 3, 4};
    vector<int> result = runningSum(nums);
    for(int i = 0; i < result.size(); i++) {
        cout << result[i] << " ";
    }
    return 0;
}   