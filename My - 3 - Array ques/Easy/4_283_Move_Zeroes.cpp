#include<bits/stdc++.h>
using namespace std;

// approach - 1 using brute force using duplicate elements
    // void moveZeroes(vector<int>& nums) {
    //     vector<int> ans;
    //     for(int i = 0; i < nums.size(); i++) {
    //         if(nums[i] != 0) {
    //             ans.push_back(nums[i]);
    //         }
    //     }
    //     for(int i = 0; i < nums.size(); i++) {
    //         if(nums[i] == 0) {
    //             ans.push_back(0);
    //         }
    //     }
    //     nums = ans;
    // }
// approach - 2 using two-pointer technique
void moveZeroes(vector<int>& nums){
    int nonZeros = 0;
    for(int i = 0; i<nums.size(); i++){
        if(nums[i] != 0){
            swap(nums[i],nums[nonZeros]);
            nonZeros++;
        }
    }
}

// example usage
int main(){
    vector<int> nums = {0, 1, 0, 3, 12};
    moveZeroes(nums);
    for(int i = 0; i < nums.size(); i++) {
        cout << nums[i] << " ";
    }
    return 0;
}