#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<int> getNSL(vector<int>& arr, int n) {
        vector<int> ans(n);
        stack<int> st;
        for (int i = 0; i < n; i++) {
            while (!st.empty() && arr[st.top()] >= arr[i]) {
                //non-strictly less
                st.pop();
            }
            if (st.empty()) {
                ans[i] = -1;
            } else {
                ans[i] = st.top();
            }
            st.push(i);
        }
        return ans;
    }
    vector<int> getNSR(vector<int>& arr, int n) {
        vector<int> ans(n);
        stack<int> st;
        for (int i = n - 1; i >= 0; i--) {
            while (!st.empty() && arr[st.top()] > arr[i]) {
                //strictly less
                st.pop();
            }
            if (st.empty()) {
                ans[i] = n;
            } else {
                ans[i] = st.top();
            }
            st.push(i);
        }
        return ans;
    }
    int sumSubarrayMins(vector<int>& arr) {
        int n = arr.size();
        vector<int> NSL = getNSL(arr, n); //Next smaller to left
        vector<int> NSR = getNSR(arr, n); //Next smaller to right
        long long sum = 0;
        int M = 1e9 + 7;

        for (int i = 0; i < n; i++) {
            long long ls = i - NSL[i]; // distance to nearest smaller to left from i
            long long rs = NSR[i] - i; // distance to nearest smaller to right from i

            long long totalWays = ls * rs;

            long long totalSum = arr[i] * totalWays;

            sum = (sum + totalSum) % M;
        }
        return sum;
    }
};
int main() {
    Solution sol;
    vector<int> arr = {3, 1, 2, 4};
    cout << sol.sumSubarrayMins(arr) << endl; // Output: 17
    return 0;
}