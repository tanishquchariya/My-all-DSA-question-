#include<bits/stdc++.h>
using namespace std;

// Binary Search implementation in C++
// Approach - 1 using iterative method time complexity O(log n) and space complexity O(1)(optimal solution)
int binarySearch(vector<int>& nums, int target) {
    int left = 0;
    int right = nums.size() - 1;
    while (left <= right) {
        int mid = left + (right - left) / 2;
        if (nums[mid] == target) {
            return mid;
        } else if (target > nums[mid]) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }
    return -1;
}

// // Approach - 2 using recursive method time complexity O(log n) and space complexity O(log n)
// int binarySearchRecursive(vector<int>& nums, int target, int left, int right) {
//     if (left > right) {
//         return -1;
//     }
//     int mid = left + (right - left) / 2;
//     if (nums[mid] == target) {
//         return mid;
//     } else if (target > nums[mid]) {
//         return binarySearchRecursive(nums, target, mid + 1, right);
//     } else {
//         return binarySearchRecursive(nums, target, left, mid - 1);
//     }
// }

int main() {
    vector<int> nums = {-1, 0, 3, 5, 9, 12};
    int target = 9;
    int result = binarySearch(nums, target);
    if (result != -1) {
        cout << "Element found at index: " << result << endl;
    } else {
        cout << "Element not found" << endl;
    }
    return 0;
}