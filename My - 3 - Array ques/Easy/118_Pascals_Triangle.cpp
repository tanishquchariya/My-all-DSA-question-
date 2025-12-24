#include <bits/stdc++.h>
using namespace std;

// // Approach - 1 using brute force using nested loops
// // time complexity - O(n^2) and space complexity - O(n)
// vector<vector<int>> generate(int numRows) {
//     vector<vector<int>> triangle;
//     for (int i = 0; i < numRows; i++) {
//         vector<int> rowans(i + 1, 1); // Initialize the row with 1s
//         // Fill the row with the appropriate values
//         for (int j = 1; j < i; j++) {
//             rowans[j] = triangle[i - 1][j - 1] + triangle[i - 1][j];
//         }
//         triangle.push_back(rowans);
//     }
//     return triangle;
// }


// // Approach - 2 using combinatorial formula
// // or using ans * (row - col) / col
// vector<vector<int>> generate(int numRows) {
//     vector<vector<int>> triangle;
//     for (int i = 0; i < numRows; i++) {
//         vector<int> row(i + 1, 1); // Initialize the row with 1s
//         for (int j = 1; j < i; j++) {
//             row[j] = row[j - 1] * (i - j) / j; // Using ans * (row - col) / col
//         }
//         triangle.push_back(row);
//     }
//     return triangle;
// }

// approach - 3 optimal soltution
vector<vector<int>> generate(int numRows) {
    vector<vector<int>> triangle;
    for (int row = 0; row < numRows; row++) {
        long long ans = 1;
        vector<int> ansRow;
        ansRow.push_back(1);
        for (int col = 1; col <= row; col++) {
            ans = ans * (row - col + 1) / col;
            ansRow.push_back(ans);
        }
        triangle.push_back(ansRow);
    }
    return triangle;
}

// Example usage
int main() {
    int numRows = 5;
    vector<vector<int>> pascalTriangle = generate(numRows);
    for (const auto& row : pascalTriangle) {
        for (int num : row) {
            cout << num << " ";
        }
        cout << endl;
    }
    return 0;
}