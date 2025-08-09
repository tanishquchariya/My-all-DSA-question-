#include<bits/stdc++.h>
using namespace std;

// approach - 1 using brute force method for implementing lower bound 
// and lower bound is also known as search insert position or ceil in sorted array problem
// reverse of lower bound is floor in sorted array problem
// Time complexity: O(n), Space complexity: O(1)
// int searchInsertBruteForce(vector<int>& nums, int target) {
//     for (int i = 0; i < nums.size(); i++) {
//         if (nums[i] >= target) {
//             return i;
//         }
//     }
//     return nums.size(); // If target is greater than all elements, return size
// }

// approach - 2 using binary search method
// Time complexity: O(log n), Space complexity: O(1)
// Function to search the insert position or implement lower bound
int searchInsert(vector<int>& nums, int target) {
    int n = nums.size();
    int low = 0, high = n - 1;
    int ans = n; // Default to n if target is greater than all elements
    if (n == 0) return 0; // If the array is empty, return 0
    while (low <= high) {
        int mid = low + (high - low) / 2;
        if (nums[mid] >= target) {
            ans  = mid;
            high = mid - 1;
        } else {
            low = mid + 1;
        }
    }
    return ans;
}

// example usage
int main() {
    
    vector<int> nums = {1, 3, 5, 6};

    int target = 4;
    int result = searchInsert(nums, target);
    cout << "Insert position for target " << target << " is: " << result << endl;
    return 0;
}