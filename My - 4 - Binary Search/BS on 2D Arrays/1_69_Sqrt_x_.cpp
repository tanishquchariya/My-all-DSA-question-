#include <bits/stdc++.h>
using namespace std;

// // Approach - 1 using built in function
// // Time Complexity - O(log(n))
// int mySqrt(int x) {
//     return sqrt(x);
// }

// Approach - 2 using brute force using a linear search
// Time Complexity - O(n) ans Space Complexity - O(1)
// int mySqrt(int x) {
//     long long ans = 1;
//     if (x < 2) return x; // Handle cases for 0 and 1
//     for (long long i = 0; i <= x; i++) {
//         if (i * i <= x) {
//             ans = i;
//         }else {
//             break; // If i*i exceeds x, we can stop
//         }
//     }
//     return ans;
// }

// Approach - 3 using binary search
// Time Complexity - O(log(n))
int mySqrt(int x)
{
    // Handle cases for 0 and 1
    if (x < 2)
        return x;
    int left = 1, right = x, ans;
    while (left <= right)
    {
        int mid = left + (right - left) / 2;
        if (mid * mid == x)
            return mid;
        if (mid * mid < x)
        {
            left = mid + 1;
            ans = mid;
        }
        else
        {
            right = mid - 1;
        }
    }
    return ans;
}

// example usage
int main()
{
    int x;
    cout << "Enter a number: ";
    cin >> x;
    cout << "Square root of " << x << " is: " << mySqrt(x) << endl;
    return 0;
}