#include <bits/stdc++.h>
using namespace std;

// // Approach - 1 brute force squaring each element and store in a new vector and sorting
// // time complexity - O(nlogn) and space complexity - O(n)
// vector<int> sortedSquares(vector<int> &nums)
// {
//     vector<int> result;
//     for (int num : nums)
//     {
//         result.push_back(num * num);
//     }
//     sort(result.begin(), result.end());
//     return result;
// }

// // Approach - 2 better approach using of approach 1 without using extra space
// // time complexity - O(nlogn) and space complexity - O(1) as we are sorting in place
// vector<int> sortedSquares(vector<int> &nums)
// {
//     int n = nums.size();
//     for (int i = 0; i < n; i++)
//     {
//         nums[i] = nums[i] * nums[i];
//     }
//     sort(nums.begin(), nums.end());
//     return nums;
// }


// Approach - 3 optimal solution using two pointers
// time complexity - O(n) and space complexity - O(1)
vector<int> sortedSquares(vector<int> &nums){
    int n = nums.size();
    vector<int> result(n);
    int i = 0;
    int j = n - 1;
    int index = n - 1;
    while (i <= j) {
        if (abs(nums[i]) > abs(nums[j])) {
            result[index] = nums[i] * nums[i];
            index--;
            i++;
        } else {
            result[index] = nums[j] * nums[j];
            index--;
            j--;
        }
    }
    return result;
}
// example usage
int main()
{
    vector<int> nums = {-4, -1, 0, 3, 10};
    vector<int> result = sortedSquares(nums);
    for (int num : result)
    {
        cout << num << " ";
    }
    return 0;
}