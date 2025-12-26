#include<bits/stdc++.h>
using namespace std;

// Approach - 1  :  brute force
// Time Complexity : O(n^2)
// Space Complexity : O(1)
// eg. intervals = [[1,3],[2,6],[8,10],[15,18]]
// output = [[1,6],[8,10],[15,18]]

#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> mergeIntervalsBrute(vector<vector<int>>& intervals) {
    vector<vector<int>> result;
    int n = intervals.size();

    // Step 1: Sort intervals by start time
    sort(intervals.begin(), intervals.end());

    // Step 2: Outer loop
    for (int i = 0; i < n; i++) {

        int start = intervals[i][0];
        int end   = intervals[i][1];

        // Step 3: Inner loop
        for (int j = i + 1; j < n; j++) {

            // If next interval overlaps
            if (intervals[j][0] <= end) {
                end = max(end, intervals[j][1]);
            }
            else {
                break; // no more overlap
            }
        }

        result.push_back({start, end});

        // Step 4: Skip merged intervals
        while (i + 1 < n && intervals[i + 1][0] <= end) {
            i++;
        }
    }

    return result;
}


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
    vector<vector<int>> result;

    int n = intervals.size();

    // Line 1: sort intervals by starting time
    sort(intervals.begin(), intervals.end());

    // Line 2: loop through intervals
    for (int i = 0; i < n; i++) {

        // Line 3: take start and end of current interval
        int start = intervals[i][0];
        int end = intervals[i][1];

        // Line 4: merge overlapping intervals
        int j = i + 1;
        while (j < n && intervals[j][0] <= end) {
            end = max(end, intervals[j][1]);
            j++;
        }

        // Line 5: store merged interval
        result.push_back({start, end});

        // Line 6: move i to last merged interval
        i = j - 1;
    }

    return result;
}


int main(){
    vector<vector<int>> intervals = {{1,3},{8,10},{2,6},{15,18}};
    vector<vector<int>> merged = mergeIntervals(intervals);
    for(int i = 0; i < merged.size(); i++){
        cout << "[" << merged[i][0] << "," << merged[i][1] << "] ";
    }
    return 0;
}