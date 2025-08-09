#include<bits/stdc++.h>
using namespace std;

// // Approach - 1 :- using brute force 
// // Time Complexity - O(m * n)
// // Space Complexity - O(1)
// int countNegatives(vector<vector<int>>& grid) {
//     int ans = 0;
//     int m = grid.size(); // traverse rows
//     int n = grid[0].size(); // traverse columns
//     for (int i = 0; i < m; i++) {
//         for (int j = 0; j < n; j++) {
//             if (grid[i][j] < 0) {
//                 ans++;
//             }
//         }
//     }
//     return ans;
// }

// // Approach - 2 :- using binary search with lower bound
// // time Complexity - O(m * log(n))
// // Space Complexity - O(1)  
// int countNegatives(vector<vector<int>>& grid) {
//     int ans = 0;
//     int m = grid.size(); // number of rows
//     int n = grid[0].size(); // number of columns
    
//     for (int i = 0; i < m; i++) {
//         // Binary search to find the first negative number in the row
//         int left = 0, right = n - 1;
//         while (left <= right) {
//             int mid = left + (right - left) / 2;
//             if (grid[i][mid] < 0) {
//                 right = mid - 1; // move left
//             } else {
//                 left = mid + 1; // move right
//             }
//         }
//         // All elements from 'left' to the end of the row are negative
//         ans += n - left;
//     }
    
//     return ans;
// }

// approach - 3 :- using optimal approach
// Time Complexity - O(m + n)
// Space Complexity - O(1)
int countNegatives(vector<vector<int>>& grid) {
    int ans = 0;
    int m = grid.size(); // number of rows
    int n = grid[0].size(); // number of columns
    
    int row = m - 1; // start from the last row
    int col = 0; // start from the first column
    
    while (row >= 0 && col < n) {
        if (grid[row][col] < 0) {
            ans += (n - col); // all elements to the right are negative
            row--; // move up
        } else {
            col++; // move right
        }
    }
    
    return ans;
}

// example usage
int main() {
    vector<vector<int>> grid = {
        {4, 3, 2, -1},
        {3, 2, 1, -1},
        {1, 1, -1, -2},
        {-1, -1, -2, -3}
    };
    
    int result = countNegatives(grid);
    cout << "Count of negative numbers: " << result << endl; // Output: 8
    return 0;
}