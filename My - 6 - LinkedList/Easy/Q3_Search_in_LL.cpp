// Search in Linked List

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
 Node* constructLL_from_array(vector<int>& arr) {
        // code here
        Node* head = new Node(arr[0]);
        Node* mover = head;
        
        for(int i = 1; i<arr.size(); i++){
            Node* temp = new Node(arr[i]);
            mover->next = temp;
            mover = temp;
        }
        return head;
    }
// Approach - 1: Iterative method to search an element in linked list
// time complexity: O(N), space complexity: O(1)
bool searchInLL(Node* head, int key) {
    Node* current = head;
    while (current != NULL) {
        if (current->data == key) {
            return true; // Key found
        }
        current = current->next;
    }
    return false; // Key not found
}

int main (){
    vector<int> arr = {3, 5, 7, 10, 15};
    Node* head = constructLL_from_array(arr);
    int key = 10;
    bool found = searchInLL(head, key);
    if (found) {
        cout << "Key " << key << " found in the linked list." << endl;
    } else {
        cout << "Key " << key << " not found in the linked list." << endl;
    }
    
}