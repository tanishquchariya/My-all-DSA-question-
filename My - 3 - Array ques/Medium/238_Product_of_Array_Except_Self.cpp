#include<bits/stdc++.h>
using namespace std;

// Approach - 1  :  brute force
// Time Complexity : O(n^2)
// Space Complexity : O(1)

vector<int> productExceptSelfBrute(vector<int>& nums) {
    int n = nums.size();
    vector<int> result(n, 1);
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            if(i != j){
                result[i] *= nums[j];
            }
        }
    }
    return result;
}

int main(){
    vector<int> nums = {1,2,3,4};
    vector<int> result = productExceptSelfBrute(nums);
    for(int i = 0; i < result.size(); i++){
        cout << result[i] << " ";
    }
}