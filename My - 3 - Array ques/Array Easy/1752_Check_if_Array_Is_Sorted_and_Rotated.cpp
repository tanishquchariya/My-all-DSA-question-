#include <bits/stdc++.h>
using namespace std;

// apaproach - 1 optimal solution
// time complexity - O(n) and space complexity - O(1)
bool checkSortedAndRotated(vector<int> &arr)
{
    int n = arr.size();
    int count = 0;
    for (int i = 0; i < n; i++)
    {
        if (arr[i] > arr[(i + 1) % n])
        {
            count++;
        }
    }
    return count <= 1;
}

// or
// bool check(vector<int> &nums)
// {
//     int count = 0;
//     int n = nums.size();

//     for (int i = 1; i < n; i++)
//     {
//         if (nums[i - 1] > nums[i])
//         {
//             count++;
//         }
//     }
//     if (nums[n - 1] > nums[0])
//         count++;
//     return count <= 1;
// }

// example usage
int main()
{
    vector<int> arr = {3, 4, 5, 1, 2};
    if (checkSortedAndRotated(arr))
    {
        cout << "The array is sorted and rotated." << endl;
    }
    else
    {
        cout << "The array is not sorted and rotated." << endl;
    }
    return 0;
}