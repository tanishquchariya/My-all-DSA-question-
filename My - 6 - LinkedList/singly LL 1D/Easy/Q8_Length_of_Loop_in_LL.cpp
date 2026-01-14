// Finding the length of a loop in a linked list using Floyd's Cycle Detection Algorithm

#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    Node* next;

    Node(int x) {
        data = x;
        next = NULL;
    }
};
Node* constructLL_from_array(vector<int>& arr) {
    Node* head = new Node(arr[0]);
    Node* mover = head;

    for (int i = 1; i < arr.size(); i++) {
        Node* temp = new Node(arr[i]);
        mover->next = temp;
        mover = temp;
    }
    return head;
}
// Approach - 1 : using maps
// Time Complexity : O(n)
// Space Complexity : O(n)
// int lengthOfLoop(Node* head) {
//     // Code here
//     unordered_map<Node*, int> mp;
//     Node* temp = head;
//     int count = 0;
//     while (temp != NULL) {
//         if (mp.find(temp) != mp.end()) {
//             int value = mp[temp];
//             return count - value;
//         }
//         mp[temp] = count;
//         count++;
//         temp = temp->next;
//     }
//     return 0;
// }

// Approach - 2 : Floyd's Cycle Detection Algorithm (Tortoise and Hare)
// Time Complexity : O(n)
// Space Complexity : O(1)

int findLength(Node* slow, Node* fast) {
    int loopLength = 1;
    fast = fast->next;
    while (slow != fast) {
        loopLength++;
        fast = fast->next;
    }
    return loopLength;
    
}
int lengthOfLoopFloyd(Node* head) {
    Node* slow = head;
    Node* fast = head;

    // Step 1: Detect cycle using Floyd's algorithm
    while (fast != NULL && fast->next != NULL) {
        slow = slow->next;           // Move slow pointer by 1
        fast = fast->next->next;     // Move fast pointer by 2

        if (slow == fast) {          // Cycle detected
            return findLength(slow, fast);
        }
    }
    return 0; // No cycle
}

int main() {
    vector<int> arr = {1, 2, 3, 4, 5};
    Node* head = constructLL_from_array(arr);

    // Creating a loop for testing
    head->next->next->next->next->next = head->next->next; // 5 -> 3

    int loopLength = lengthOfLoopFloyd(head);
    if (loopLength > 0) {
        cout << "Length of the loop is: " << loopLength << endl;
    } else {
        cout << "No loop detected." << endl;
    }

    return 0;
}   