// Detecting a cycle in a linked list using Floyd's Cycle Detection Algorithm (Tortoise and Hare)

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

// Approach - 1 : Using Hashmap
// Time Complexity : O(n)
// Space Complexity : O(n)

// bool detectCycle(Node* head) {
//     unordered_set<Node*> mp;
//     Node* temp = head;
//     while (temp != NULL) {
//         if (mp.find(temp) != mp.end()) {
//             return true; // Cycle detected
//         }
//         mp.insert(temp);
//         temp = temp->next;
//     }
//     return false; // No cycle
// }


// Approach - 2 : Floyd's Cycle Detection Algorithm
// Time Complexity : O(n)
// Space Complexity : O(1)
bool detectCycle(Node* head) {
    Node* slow = head;
    Node* fast = head;

    while (fast != NULL && fast->next != NULL) {
        slow = slow->next;           // Move slow pointer by 1
        fast = fast->next->next;     // Move fast pointer by 2

        if (slow == fast) {          // Cycle detected
            return true;
        }
    }
    return false; // No cycle
}


int main() {
    vector<int> arr = {3, 2, 0, -4};
    Node* head = constructLL_from_array(arr);

    // Creating a cycle for testing: connecting the last node to the second node
    head->next->next->next->next = head->next;

    if (detectCycle(head)) {
        cout << "Cycle detected in the linked list." << endl;
    } else {
        cout << "No cycle in the linked list." << endl;
    }

    return 0;
}