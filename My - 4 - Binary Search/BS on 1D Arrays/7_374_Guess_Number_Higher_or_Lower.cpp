#include <bits/stdc++.h>
using namespace std;

// approach - 1: Using linear search (not optimal, just for demonstration)
// Time Complexity - O(n)

// int pick = 6; // Assume this is the number we are trying to guess
// int guess(int num) {
//     if (num > pick) {
//         return -1; // Your guess is higher than the picked number
//     } else if (num < pick) {
//         return 1;  // Your guess is lower than the picked number
//     } else {
//         return 0;  // Your guess equals the picked number
//     }
// }
// int guessNumber(int n)
// {
//     for (int i = 1; i <= n; i++)
//     {
//         int val = guess(i);
//         if (val == 0)
//         {
//             return i;
//         }
//     }
//     return -1;
// }
// Approach - 2: Using binary search (optimal approach)
// Time Complexity - O(log n)
// Space Complexity - O(1)

int pick = 6; // Assume this is the number we are trying to guess
int guess(int num)
{
    if (num > pick)
    {
        return -1; // Your guess is higher than the picked number
    }
    else if (num < pick)
    {
        return 1; // Your guess is lower than the picked number
    }
    else
    {
        return 0; // Your guess equals the picked number
    }
}
int guessNumber(int n)
{
    int low = 1, high = n;
    while (low <= high)
    {
        int mid = (low + high) / 2;
        int val = guess(mid); // Assume guess is a predefined function that returns -1, 0, or 1
        if (val == 0)
        {
            return mid;
        }
        else if (val == -1)
        {
            high = mid - 1;
        }
        else
        {
            low = mid + 1;
        }
    }
    return -1;
}

// example usage
int main()
{
    int n = 10; // Example value for n
    int result = guessNumber(n);
    cout << "The guessed number is: " << result << endl;
    return 0;
}