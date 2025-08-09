#include <bits/stdc++.h>
using namespace std;

// Function to search the insert position or implement upper bound
// Approach - 1 Implementing Upper Bound using brute force method
// Time complexity: O(n), Space complexity: O(1)

// int upperBoundBruteForce(vector<int> &arr, int target)
// {
//     int n = arr.size();
//     for (int i = 0; i < n; i++)
//     {
//         if (arr[i] > target)
//         {
//             return i;
//         }
//     }
//     return n; // If no element is greater than target, return n
// } 

// Approach - 2 Implementing Upper Bound using Binary Search
// Time complexity: O(log n), Space complexity: O(1)
int upperBound(vector<int> &arr, int target)
{
    int low = 0;
    int n = arr.size();
    int high = n - 1;
    int ans = n;
    while (low <= high)
    {
        int mid = (low + high) / 2;
        if (arr[mid] > target)
        {
            ans = mid;
            high = mid - 1;
        }
        else
        {
            low = mid + 1;
        }
    }
    return ans;
}

// example usage
int main()
{
    vector<int> arr = {2, 3, 5, 6, 8, 9};
    int target = 4;
    int result = upperBound(arr, target);
    cout << "Upper bound for target " << target << " is at index: " << result << endl;
    return 0;
}