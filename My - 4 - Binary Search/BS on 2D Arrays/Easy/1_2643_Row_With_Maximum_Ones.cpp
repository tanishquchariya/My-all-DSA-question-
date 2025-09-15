#include <bits/stdc++.h>
using namespace std;
// 2643. Row With Maximum Ones

// Approach - 1 : Brute Force
// 1. Traverse each row and count the number of 1's.
// 2. Keep track of the maximum count and the corresponding row index.
// 3. Return the row index with the maximum count of 1's.
// T.c = O(n * m) and s.c = O(1)

// vector<int> rowAndMaximumOnes(vector<vector<int>>& mat) {
//     int n = mat.size(); // for rows traversal
//     int m = mat[0].size(); // for columns traversal
//     int count_max = 0;
//     int index = 0;
//     for (int i = 0; i < n; i++) {
//         int count_one = 0;
//         for (int j = 0; j < m; j++) {
//             count_one += mat[i][j];
//         }
//         if (count_one > count_max) {
//             count_max = count_one;
//             index = i;
//         }
//     }
//     return {index, count_max};
// }

// // Approach - 2 : using Binary Search and lower_bound (if array is sorted)
// // T.c = O(n * log(m)) and s.c = O(1)

// vector<int> rowAndMaximumOnes(vector<vector<int>>& mat) {
//     int n = mat.size();
//     int m = mat[0].size();
//     int maxRow = 0;
//     int maxCount = 0;

//     for (int i = 0; i < n; i++) {
//         // find first 1 in sorted row
//         auto it = lower_bound(mat[i].begin(), mat[i].end(), 1);
//         // int count = (it == mat[i].end()) ? 0 : (m - (it - mat[i].begin()));
//          int count;
//             if (it == mat[i].end()) {
//                 count = 0; // no 1 found
//             } else {
//                 count = m - (it - mat[i].begin()); // total 1s
//             }

//         if (count > maxCount) {
//             maxCount = count;
//             maxRow = i;
//         }
//     }
//     return {maxRow, maxCount};
// }

// Approach - 2 : using Binary Search
// T.c = O(n * log(m)) and s.c = O(1)

vector<int> rowAndMaximumOnes(vector<vector<int>> &mat)
{
    int n = mat.size();
    int m = mat[0].size();
    int maxRow = 0;
    int maxCount = 0;

    for (int i = 0; i < n; i++)
    {
        // Count the number of 1's in the current row
        int count = 0;
        for (int val : mat[i])
        {
            if (val == 1)
                count++;
        }
        // int count = std::count(mat[i].begin(), mat[i].end(), 1);
        if (count > maxCount)
        {
            maxCount = count;
            maxRow = i;
        }
    }
    return {maxRow, maxCount};
}

int main()
{
    vector<vector<int>> mat = {{0, 1, 0}, {1, 1, 1}, {0, 0, 0}};
    vector<int> result = rowAndMaximumOnes(mat);
    cout << "Row with maximum ones: " << result[0] << ", Count of ones: " << result[1] << endl;
    return 0;
}