#include <bits/stdc++.h>
using namespace std;

// Approach - 1  :  brute force
// Time Complexity : O(n^2)
// Space Complexity : O(1)

// vector<int> majorityElement2(vector<int>& nums) {
//     vector<int> result;
//     int n = nums.size();
//     for(int i = 0; i < n; i++){
//         int count = 0;
//         for(int j = 0; j < n; j++){
//             if(nums[j] == nums[i]){
//                 count++;
//             }
//         }
//         if(count > n/3 && find(result.begin(), result.end(), nums[i]) == result.end()){
//             result.push_back(nums[i]);
//         }
//         // we use set instead of vector to avoid duplicate entries then we do not need to check for duplicates in the vector
//     }
//     return result;
// }

// Approach - 2 : Using HashMap
// Time Complexity : O(n)
// Space Complexity : O(n)

// vector<int> majorityElement2(vector<int>&nums){
//     vector<int>result;
//     unordered_map<int, int> mp;
//     int n = nums.size();
//     for(int i = 0; i<n; i++){
//         mp[nums[i]]++;
//     }
//     for(auto it : mp){
//         if(it.second > n/3){
//             result.push_back(it.first);
//         }
//     }
// //we can also write for(pair<int, int> it : mp) instead of for(auto it : mp)
//     return result;
// }

// Approach - 3 : Using Boyer-Moore Voting Algorithm Extension (Optimal Solution)
// Time Complexity : O(n)
// Space Complexity : O(1)

vector<int> majorityElement2(vector<int> &nums)
{
    int n = nums.size();
    int count1 = 0, count2 = 0;
    int el1 = INT_MIN, el2 = INT_MIN;

    for (int i = 0; i < n; i++)
    {
        if (count1 == 0 && nums[i] != el2)
        {
            el1 = nums[i];
            count1++;
        }
        else if (count2 == 0 && nums[i] != el1)
        {
            el2 = nums[i];
            count2++;
        }
        else if (nums[i] == el1)
        {
            count1++;
        }
        else if (nums[i] == el2)
        {
            count2++;
        }
        else
        {
            count1--;
            count2--;
        }
    }


    count1 = 0;
    count2 = 0;
    for (int i = 0; i < n; i++)
    {
        if (nums[i] == el1)
        {
            count1++;
        }
        else if (nums[i] == el2)
        {
            count2++;
        }
    }
    vector<int> result;
    if (count1 > floor(n / 3))
    {
        result.push_back(el1);
    }
    if (count2 > floor(n / 3))
    {
        result.push_back(el2);
    }

    return result;
}

int main()
{
    vector<int> nums = {1, 1, 1, 3, 3, 2, 2, 2};
    vector<int> result = majorityElement2(nums);
    for (int num : result)
    {
        cout << num << " ";
    }
    return 0;
}