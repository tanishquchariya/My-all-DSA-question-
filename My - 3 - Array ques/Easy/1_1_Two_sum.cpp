// Approach - 1 using brute force
#include <bits/stdc++.h>
using namespace std;

// pair<int, int> twoSum(vector<int>& nums, int target) {
//     for (int i = 0; i < nums.size(); i++) {
//         for (int j = i + 1; j < nums.size(); j++) {
//             if (nums[i] + nums[j] == target) {
//                 return {i, j};  // Return the indices of the pair
//             }
//         }
//     }
//     return {-1, -1};  // Return -1 if no pair is found
// }

// Approach - 2 using two-pointer technique with sorting

// pair<int,int> twoSum(vector<int>& nums, int target) {
//     vector<pair<int, int>> v; // {value, original_index}
//     for (int i = 0; i < nums.size(); i++) {
//         v.push_back({nums[i], i});
//     }

//     sort(v.begin(), v.end());

//     int l = 0, r = v.size() - 1;
//     while (l < r) {
//         int sum = v[l].first + v[r].first;
//         if (sum == target) {
//             return {v[l].second, v[r].second};
//         } else if (sum < target) {
//             l++;
//         } else {
//             r--;
//         }
//     }
//     return {};
// }

// Approach - 3 using hash map
pair<int, int> twoSum(vector<int> &nums, int target)
{
    // Create a hash map to store the elements and their indices
    // key, Value---->Val, idx
    unordered_map<int, int> mymap;

    // Find the pair element by element

    for (int i = 0; i < nums.size(); ++i)
    {

        if (mymap.count(target - nums[i])) // num [i] -> is x

            return {i, mymap[target - nums[i]]};

        // Insert current element

        mymap[nums[i]] = i;
    }
    return {}; // No pair exists
}
int main()
{
    vector<int> nums = {2, 7, 11, 15};
    int target = 9;
    pair<int, int> result = twoSum(nums, target);
    if (result != make_pair(-1, -1))
    {
        cout << "Index of the first element in the pair: " << result.first << endl;
        cout << "Index of the second element in the pair: " << result.second << endl;
    }
    else
    {
        cout << "No pair found that sums to the target." << endl;
    }
    return 0;
}