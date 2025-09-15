#include <bits/stdc++.h>
using namespace std;

// finding intersection of two arrays with unique elements

// Approach - 1 using brute force method using two unordered sets
// Time complexity: O(n + m + k), Space complexity: O(n + k)
// vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
//     unordered_set<int> set1(nums1.begin(), nums1.end());
//     unordered_set<int> set2;

//     for (int i = 0; i < nums2.size(); i++) {
//         if (set1.find(nums2[i]) != set1.end()) {
//             set2.insert(nums2[i]);
//         }
//     }
//     // Convert set to vector for the result
//     // This will ensure that the result contains unique elements
//     vector<int> result(set2.begin(), set2.end());
//     return result;
// }

// // Approach - 2 reduce space complexity using one unordered set
// // Time complexity: O(n + m), Space complexity: O(n)

// vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
//     unordered_set<int> set1(nums1.begin(), nums1.end());
//     vector<int> result;

//     for (int i = 0; i < nums2.size(); i++) {
//         if (set1.find(nums2[i]) != set1.end()) {
//             result.push_back(nums2[i]);
//             set1.erase(nums2[i]);  // Remove to avoid duplicates
//         }
//     }
//     return result;
// }

// // Approach - 3 using sorting and binary search
// // Time complexity: O(n log n + m log n), Space complexity: O(n)

// bool binarySearch(vector<int> nums, int target)
// {
//     int low = 0, high = nums.size() - 1;
//     while (low <= high)
//     {
//         int mid = (low + high) / 2;
//         if (target == nums[mid])
//         {
//             return true;
//         }
//         else if (target > nums[mid])
//         {
//             low = mid + 1;
//         }
//         else
//         {
//             high = mid - 1;
//         }
//     }
//     return false;
// }

// vector<int> intersection(vector<int> &nums1, vector<int> &nums2)
// {
//     sort(nums1.begin(), nums1.end());
//     unordered_set<int> st;

//     for (int i = 0; i < nums2.size(); i++)
//     {
//         if (binarySearch(nums1, nums2[i]))
//         {
//             // (binary_search(nums1.begin(), nums1.end(), nums2[i]))
//             st.insert(nums2[i]);
//         }
//     }
//     // Remove duplicates
//     vector<int> result(st.begin(), st.end());
//     return result;
// }

// approach - 4 using two pointers and sorting (optimal solution)
// time complexity: O(n log n + m log m), Space complexity: O(1)
vector<int> intersection(vector<int> &nums1, vector<int> &nums2)
{
    sort(nums1.begin(), nums1.end());
    sort(nums2.begin(), nums2.end());

    vector<int> result;
    int i = 0, j = 0;
    int n = nums1.size(), m = nums2.size();

    while (i < n && j < m)
    {
        if (nums1[i] == nums2[j])
        {
            result.push_back(nums1[i]);
            while (i < n - 1 && nums1[i] == nums1[i + 1])
            {
                i++; // Skip duplicates in nums1
            }
            while (j < m - 1 && nums2[j] == nums2[j + 1])
            {
                j++; // Skip duplicates in nums2
            }
            i++;
            j++;
        }
        else if (nums1[i] < nums2[j])
        {
            i++;
        }
        else
        {
            j++;
        }
    }

    return result;
}

// usage example
int main()
{
    vector<int> nums1 = {1, 2, 2, 1};
    vector<int> nums2 = {2, 2};

    vector<int> result = intersection(nums1, nums2);

    cout << "Intersection of two arrays: ";
    for (int num : result)
    {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}