#include <bits/stdc++.h>
using namespace std;

// Appoach - 1 using burte force copy element of nums2 to nums1 and sort the nums1
// void merge(vector<int> &nums1, int m, vector<int> &nums2, int n)
// Time Complexity : O((m+n)log(m+n))
// Space Complexity : O(1)
// {
//     for (int i = 0; i < n; i++)
//     {
//         nums1[m + i] = nums2[i];
//     }
//     sort(nums1.begin(), nums1.end());
//     return;
// }

// Approach - 2 using two-pointer technique
// void merge(vector<int> &nums1, int m, vector<int> &nums2, int n)
// {
//     vector<int> merged;
//     int i = 0, j = 0;
//     while (i < m && j < n)
//     {
//         if (nums1[i] < nums2[j])
//         {
//             merged.push_back(nums1[i]);
//             i++;
//         }
//         else
//         {
//             merged.push_back(nums2[j]);
//             j++;
//         }
//     }
//     // Append any remaining elements from either array
//     while (i < m)
//     {
//         merged.push_back(nums1[i]);
//         i++;
//     }
//     while (j < n)
//     {
//         merged.push_back(nums2[j]);
//         j++;
//     }
//     // Copy the merged elements back into nums1
//     nums1 = merged;
// }
// or 
// Approach - 3 using two-pointer technique in reverse order
void merge(vector<int> &nums1, int m, vector<int> &nums2, int n)
{
    int p1 = m - 1; // Pointer for nums1
    int p2 = n - 1; // Pointer for nums2
    int i = m + n - 1; // Pointer for the end of nums1

    // Merge in reverse order
    while (p1 >= 0 && p2 >= 0)
    {
        if (nums1[p1] > nums2[p2])
        {
            nums1[i] = nums1[p1];
            p1--;
        }
        else
        {
            nums1[i] = nums2[p2];
            p2--;
        }
        i--;
    }

    // If there are remaining elements in nums2, copy them
    while (p2 >= 0)
    {
        nums1[i] = nums2[p2];
        p2--;
        i--;
    }
}       

// example usage
int main()
{
    vector<int> nums1 = {1, 2, 3, 0, 0, 0};
    vector<int> nums2 = {2, 5, 6};
    int m = 3; // Number of elements in nums1
    int n = 3; // Number of elements in nums2

    merge(nums1, m, nums2, n);

    for (int num : nums1)
    {
        cout << num << " ";
    }
    return 0;
}