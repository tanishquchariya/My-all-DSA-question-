#include<bits/stdc++.h>
// #include <iostream>
using namespace std;

int main()
{
    int n;
    cout << "enter the index size of array" << endl;
    cin >> n;

    int arr[n];
    cout << "enter the unsorted array" << endl;

    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    for (int i = 1; i < n; i++)
    {
        int current = arr[i];
        int j = i - 1;
        while (arr[j] > current && j >= 0)
        {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = current;
    }
    cout << "sorted array" << endl;
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    return 0;
}


// vector<int> insertionSort(vector<int>& arr, int n) {
//     for (int i = 1; i < n; i++) {
//         int current = arr[i];
//         int j = i - 1;
//         while (j >= 0 && arr[j] > current) {
//             arr[j + 1] = arr[j];
//             j--;
//         }
//         arr[j + 1] = current;
//     }
// }
// int main(){

//     vector<int> arr = {12, 11, 13, 5, 6};
//     int n = arr.size();
//     insertionSort(arr, n);
//     cout << "Sorted array: \n";
//     for (int i = 0; i < n; i++)
//         cout << arr[i] << " ";
// }