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

// Approach - 1: Insertion at the end of linked list
// time complexity: O(N), space complexity: O(1)
Node* insertAtEnd(Node* head, int data) {
    Node* newNode = new Node(data); // Create a new node with the given data
    if (head == NULL) {
        return newNode; // If the list is empty, return the new node as the head
    }
    Node* temp = head;
    while (temp->next != NULL) {
        temp = temp->next; // Traverse to the last node
    }
    temp->next = newNode; // Link the new node at the end
    return head; // Return the head of the modified list
}


int main (){
    vector<int> arr = {3, 5, 7, 10, 15};
    Node* head = constructLL_from_array(arr);
    int dataToInsert = 20;
    head = insertAtEnd(head, dataToInsert);
    
    // Print the updated linked list
    Node* temp = head;
    while (temp != NULL) {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
    return 0;
}