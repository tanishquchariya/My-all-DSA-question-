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