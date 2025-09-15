// 350. Intersection of Two Arrays II is similar to 349. Intersection of Two Arrays, but it allows for duplicates in the result. 

#include <bits/stdc++.h>
using namespace std;

// Approach - 1 two pointers and sorting(optimal solution)
// Time complexity: O(n log n + m log m), Space complexity: O(1)
vector<int> intersection(vector<int> &nums1, vector<int> &nums2) {
    sort(nums1.begin(), nums1.end());
    sort(nums2.begin(), nums2.end());

    vector<int> result;
    int i = 0, j = 0;
    int n = nums1.size(), m = nums2.size();

    while (i < n && j < m) {
        if (nums1[i] == nums2[j]) {
            result.push_back(nums1[i]);

            // if you want to skip duplicates in the result
            // while (i < n - 1 && nums1[i] == nums1[i + 1]) {
            //     i++; // Skip duplicates in nums1
            // }
            // while (j < m - 1 && nums2[j] == nums2[j + 1]) {
            //     j++; // Skip duplicates in nums2
            // }
            
            i++;
            j++;
        } else if (nums1[i] < nums2[j]) {
            i++;
        } else {
            j++;
        }
    }

    return result;
}

// example usage
int main()
{
    // Example usage
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