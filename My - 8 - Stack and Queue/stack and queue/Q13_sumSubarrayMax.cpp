#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<int> getNGL(vector<int>& arr, int n) {
        vector<int> ans(n);
        stack<int> st;
        for (int i = 0; i < n; i++) {
            while (!st.empty() && arr[st.top()] <= arr[i]) {
                // non-strictly greater
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

    vector<int> getNGR(vector<int>& arr, int n) {
        vector<int> ans(n);
        stack<int> st;
        for (int i = n - 1; i >= 0; i--) {
            while (!st.empty() && arr[st.top()] < arr[i]) {
                // strictly greater
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

    int sumSubarrayMaxs(vector<int>& arr) {
        int n = arr.size();
        vector<int> NGL = getNGL(arr, n); // Next Greater to Left
        vector<int> NGR = getNGR(arr, n); // Next Greater to Right
        long long sum = 0;
        int M = 1e9 + 7;

        for (int i = 0; i < n; i++) {
            long long ls = i - NGL[i]; // distance to nearest greater to left
            long long rs = NGR[i] - i; // distance to nearest greater to right

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
    cout << sol.sumSubarrayMaxs(arr) << endl; // Output: 17
    return 0;
}