#include <bits/stdc++.h>
using namespace std;

// // Approach - 1 using brute force with extra space
// // time complexity - O(n^2) and space complexity - O(n)
// int removeDuplicates(vector<int>& nums) {
//     int n = nums.size();
//     vector<int> ans;
//     for (int i = 0; i < n; i++) {
//         if (i == 0 || nums[i] != nums[i - 1]) {
//             ans.push_back(nums[i]);
//         }
//     }
//     nums = ans; // Update the original array
//     return ans.size();
// }


// Approach - 2 using two pointers(optimal solution)
 int removeDuplicates(vector<int>& nums) {
        int n = nums.size();
        int i = 0;
        for (int j = 1; j < n; j++) {
            if (nums[i] != nums[j]) {
                i++;
                nums[i] = nums[j];
            }
        }
        return i + 1;
    }
// example usage
int main()
{
    vector<int> nums = {1, 1, 2, 2, 3, 4, 4, 5};
    int newLength = removeDuplicates(nums);
    cout << "New length: " << newLength << endl;
    cout << "Modified array: ";
    for (int i = 0; i < newLength; i++)
    {
        cout << nums[i] << " ";
    }
    cout << endl;
    return 0;
}