// Delete a node in a singly linked list given only access to that node

#include <bits/stdc++.h>
using namespace std;

class Node {
public:
    int data;
    Node* next;
    Node(int val) {
        data = val;
        next = NULL;
    }
};

// construct linked list from vector
Node* constructLL(vector<int> arr) {
    Node* head = new Node(arr[0]);
    Node* temp = head;
    for (int i = 1; i < arr.size(); i++) {
        temp->next = new Node(arr[i]);
        temp = temp->next;
    }
    return head;
}

// Approach - 1: Copy the data from next node to current node and delete the next node.
// Time Complexity: O(1), Space Complexity: O(1)
void deleteNode(Node* node) {

    Node* prev = NULL;
    while(node != NULL && node->next != NULL){
        node->data = node->next->data;
        prev = node;
        node = node->next;
        }
    prev->next = NULL;
    delete node;
}


int main() {
    // Example usage:
    vector<int> arr = {4, 5, 1, 9};
    Node* head = constructLL(arr);
    
    // Let's say we want to delete the node with value 5
    Node* nodeToDelete = head->next; // Node with value 5
    deleteNode(nodeToDelete);
    
    // Print the modified linked list
    Node* temp = head;
    while (temp != NULL) {
        cout << temp->data << " ";
        temp = temp->next;
    }
    return 0;
}