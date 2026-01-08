// Find Length of Linked List

#include<bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    Node* next;

    Node(int x) {
        data = x;
        next = NULL;
    }
};


// // Approach - 1: Recursive method to find length of linked list
// // time complexity: O(N), space complexity: O(N) due to recursive stack
// int lengthRecursive(Node* head) {
//     if (head == NULL) {
//         return 0;
//     }
//     return 1 + lengthRecursive(head->next);
// }

// // Approach - 2: Using a helper function with reference parameter
// // time complexity: O(N), space complexity: O(1)
// void lengthHelper(Node* head, int& count) {
//     if (head == NULL) {
//         return;
//     }
//     count++;
//     lengthHelper(head->next, count);
// }
// int lengthUsingHelper(Node* head) {
//     int count = 0;
//     lengthHelper(head, count);
//     return count;(
// }

// Approach - 3 : Iterative method to find length of linked list  (optimal approach)
// time complexity: O(N), space complexity: O(1)
int length(Node* head) {
    int count = 0;
    while (head != NULL) {
        count++;
        head = head->next;
    }
    return count;
}
int main() {
    // Creating a simple linked list for demonstration: 1 -> 2 -> 3 -> NULL
    Node* head = new Node(1);
    head->next = new Node(2);
    head->next->next = new Node(3);

    cout << "Length of linked list: " << length(head) << endl; // Output: 3

    return 0;
}