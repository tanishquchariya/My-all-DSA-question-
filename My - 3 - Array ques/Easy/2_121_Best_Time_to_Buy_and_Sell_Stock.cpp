#include <bits/stdc++.h>
using namespace std;

// Approach - 1 using brute force
// Time Complexity: O(n^2)
// Space Complexity: O(1)
// int maxProfit(vector<int> &prices)
// {
//     int maxProfit = 0;
//     for (int i = 0; i < prices.size(); i++)
//     {
//         for (int j = i + 1; j < prices.size(); j++)
//         {
//             if (prices[j] > prices[i])
//             {
//                 maxProfit = max(maxProfit, prices[j] - prices[i]);
//             }
//         }
//     }
//     return maxProfit;
// }

// Approach - 2 using auxiliary 
// Time Complexity: O(n)
// Space Complexity: O(n)
// int maxProfit(vector<int> &prices)
// {
//     int n = prices.size();
//     if (n == 0)
//         return 0;

//     vector<int> maxPrices(n);
//     maxPrices[n - 1] = prices[n - 1];   // Initialize the last element

//     for (int i = n - 2; i >= 0; i--)
//     {
//         maxPrices[i] = max(maxPrices[i + 1], prices[i]);
//     }

//     int maxProfit = 0;
//     for (int i = 0; i < n; i++)
//     {
//         maxProfit = max(maxProfit, maxPrices[i] - prices[i]);
//     }
//     return maxProfit;
// }



// approach - 3 using one pass o(n) time complexity and o(1) space complexity(optimal sol.)
// int maxProfit(vector<int> &prices)
// {
//     int minPrice = INT_MAX;
//     int maxProfit = 0;

//     for (int i = 0; i < prices.size(); i++)
//     {
//         if (prices[i] < minPrice)
//         {
//             minPrice = prices[i];
//         }
//         else if (prices[i] - minPrice > maxProfit)
//         {
//             maxProfit = prices[i] - minPrice;
//         }
//     }
//     return maxProfit;
// }

// or 
int maxProfit(vector<int> &prices)
{
    int minPrice = INT_MAX;
    int maxProfit = 0;

    for(int i = 0; i<prices.size(); i++ ){
        minPrice = min(minPrice,prices[i]);
        int profit = prices[i] - minPrice;
        maxProfit = max(maxProfit, profit);
    }
    return maxProfit;
}
int main()
{
    vector<int> prices = {7, 1, 5, 3, 9, 4};
    int result = maxProfit(prices);
    cout << "Maximum profit: " << result << endl;
    return 0;
}