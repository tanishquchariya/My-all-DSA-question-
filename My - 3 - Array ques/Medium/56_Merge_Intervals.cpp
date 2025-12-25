#include<bits/stdc++.h>
using namespace std;

// Approach - 1  :  brute force
// Time Complexity : O(n^2)
// Space Complexity : O(1)
// eg. intervals = [[1,3],[2,6],[8,10],[15,18]]
// output = [[1,6],[8,10],[15,18]]

// vector<vector<int>> mergeIntervals(vector<vector<int>>& intervals) {
//     vector<vector<int>> result;
//     int n = intervals.size();
//     sort(intervals.begin(), intervals.end());
//     for(int i = 0; i < n; i++){
//         int start = intervals[i][0];
//         int end = intervals[i][1];
//         for(int j = i + 1; j < n; j++){
//             if(intervals[j][0] <= end){
//                 end = max(end, intervals[j][1]);
//                 i++;
//             }
//             else{
//                 break;
//             }
//         }
//         result.push_back({start, end});
//     }
//     return result;
// }

// Approach - 2 : Using Extra Array 
// Time Complexity : O(n log n)  (due to sorting)
// Space Complexity : O(n)
vector<vector<int>> mergeIntervals(vector<vector<int>>& intervals) {
    if(intervals.size() == 0) return {};
    sort(intervals.begin(), intervals.end());
    vector<vector<int>> result;
    result.push_back(intervals[0]);
    for(int i = 1; i < intervals.size(); i++){
        if(intervals[i][0] <= result.back()[1]){
            result.back()[1] = max(result.back()[1], intervals[i][1]);
        }
        else{
            result.push_back(intervals[i]);
        }
    }
    return result;
}

// Approach - 3 : Using Stack (Optimal Solution)
// Time Complexity : O(n log n)  (due to sorting)
// Space Complexity : O(n)
vector<vector<int>> mergeIntervals(vector<vector<int>>& intervals) {
    if(intervals.size() == 0) return {};
    sort(intervals.begin(), intervals.end());
    stack<vector<int>> st;
    st.push(intervals[0]);
    for(int i = 1; i < intervals.size(); i++){
        vector<int> top = st.top();
        if(intervals[i][0] <= top[1]){
            top[1] = max(top[1], intervals[i][1]);
            st.pop();
            st.push(top);
        }
        else{
            st.push(intervals[i]);
        }
    }
    vector<vector<int>> result;
    while(!st.empty()){
        result.push_back(st.top());
        st.pop();
    }
    reverse(result.begin(), result.end());
    return result;
}

// Approach - 4 : In-place Merging (Optimal Solution)
// Time Complexity : O(n log n)  (due to sorting)
// Space Complexity : O(1)
vector<vector<int>> mergeIntervals(vector<vector<int>>& intervals) {
    if(intervals.size() == 0) return {};
    sort(intervals.begin(), intervals.end());
    int index = 0; // index of last merged interval
    for(int i = 1; i < intervals.size(); i++){
        if(intervals[index][1] >= intervals[i][0]){
            intervals[index][1] = max(intervals[index][1], intervals[i][1]);
        }
        else{
            index++;
            intervals[index] = intervals[i];
        }
    }
    intervals.resize(index + 1);
    return intervals;
}


int main(){
    vector<vector<int>> intervals = {{1,3},{8,10},{2,6},{15,18}};
    vector<vector<int>> merged = mergeIntervals(intervals);
    for(int i = 0; i < merged.size(); i++){
        cout << "[" << merged[i][0] << "," << merged[i][1] << "] ";
    }
    return 0;
}