#include<bits/stdc++.h>
using namespace std;

// Approach - 1  :  brute force
// Time Complexity : O(n^2)
// Space Complexity : O(1)

vector<int> RotateArray(vector<int>& nums, int k) {
    int n = nums.size();
    k = k % n; // in case k is greater than n
    for(int i = 0; i < k; i++){
        int last = nums[n-1];
        for(int j = n-1; j > 0; j--){
            nums[j] = nums[j-1];
        }
        nums[0] = last;
    }
    return nums;
}


// Approach - 2 : Using Extra Array
// Time Complexity : O(n)
// Space Complexity : O(n)
vector<int> RotateArray2(vector<int>& nums, int k) {
    int n = nums.size();
    k = k % n; // in case k is greater than n
    vector<int> temp(n);
    for(int i = 0; i < n; i++){
        temp[(i + k) % n] = nums[i];
    }
    return temp;
}

// Approach - 3 : Using Reversal Algorithm (Optimal Solution)
// Time Complexity : O(n)   
// Space Complexity : O(1)
vector<int> RotateArray1(vector<int>& nums, int k) {
    int n = nums.size();
    k = k % n; // in case k is greater than n

    // Step 1: Reverse the entire array
    reverse(nums.begin(), nums.end());

    // Step 2: Reverse the first k elements
    reverse(nums.begin(), nums.begin() + k);

    // Step 3: Reverse the remaining n-k elements
    reverse(nums.begin() + k, nums.end());

    return nums;
}

int main(){
    vector<int> nums = {1,7,9,11};
    int k = 2;
    vector<int> rotated = RotateArray(nums, k);
    for(int i = 0; i < rotated.size(); i++){
        cout << rotated[i] << " ";
    }
    return 0;
}