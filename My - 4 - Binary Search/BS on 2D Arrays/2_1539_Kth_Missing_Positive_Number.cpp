#include<bits/stdc++.h>
using namespace std;

// Approach - 1 using linear search
// Time Complexity - O(n) and Space Complexity - O(1)
// int findKthPositive(vector<int>& arr, int k) {
//     int n = arr.size();
//     // int missingCount = 0;
//     int num = 1;
//     int i = 0;

//     while (i < n && k > 0) {
//         if (arr[i] == num) {
//             i++;
//         } else {
//             k--;
//         }
//         num++;
//     }
//     while(k > 0) {
//         num++;
//         k--;
//     }
//     return num - 1;
// }

// Approach - 2 using binary search
// Time Complexity - O(log(n))

int findKthPositive(vector<int>& arr, int k) {
    int n = arr.size();
    int left = 0, right = n - 1;
    int missingCount = 0;

    while (left <= right) {
        int mid = left + (right - left) / 2;
        // Count how many numbers are missing up to arr[mid]
        missingCount = arr[mid] - (mid + 1);

        if (missingCount < k) {
            left = mid + 1; // We need to look for more missing numbers
        } else {
            right = mid - 1; // We have enough missing numbers
        }
    }

    // After the loop, 'left' is the position where we can find the kth missing number
    return left + k;
}

// Example usage
int main() {
    vector<int> arr = {2, 3, 4, 7, 11};
    int k = 5;
    cout << "The " << k << "th missing positive number is: " << findKthPositive(arr, k) << endl;
    return 0;
}