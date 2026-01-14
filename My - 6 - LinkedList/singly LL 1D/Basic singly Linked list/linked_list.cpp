// https://takeuforward.org/linked-list/linked-list-introduction

// Creating a Linked List
#include <iostream>
#include <bits/stdc++.h>
using namespace std;

// Define the structure of a Node
struct Node{
    public: // access modifier
    int data; // the data value
    Node* next; // the pointer to the next value
    public:
    // constructor
    Node (int data1, Node* next1){
        data=data1;  // Initialize data with the provided value
        next=next1;  // Initialize next with the provided
    }
    Node (int data1){
        data=data1;  // Initialize data with the provided value
        next=nullptr;  // Initialize next as null since it's the end of the list

    }
};
int main(){
    vector<int> arr={2,5,8,7};
    Node* y= new Node(arr[0]);
    cout<<y<<'\n'; // returns the memory value
    cout<<y->data<<'\n'; // returns the data stored at that memory point
}

// How to convert array in linked list

/*#include <bits/stdc++.h>
using namespace std;
class Node {
  public:
    int data;
    Node* next;

    // Default constructor
    Node() {
        data = 0;
        next = NULL;
    }

    // Parameterised Constructor
    Node(int data) {
        this->data = data;
        this->next = NULL;
    }
};*/

// How to convert array in linked list
#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    Node *next;

public:
    Node(int data1, Node *next1)
    {
        data = data1;
        next = next1;
    }
    Node(int data1)
    {
        data = data1;
        next = nullptr;
    }
};

 Node* constructLL(vector<int>& arr) {
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
int main(){
    vector<int> arr={2,5,8,7};
    Node* head = constructLL(arr);
    cout<<head->data; // returns the data stored at that memory point
}



// examples
#include <iostream>
#include<bits/stdc++.h>
using namespace std;

// Define the structure of a Node
struct Node {
    int data;      // The data value
    Node* next;    // Pointer to the next node

    // Constructor
    Node(int value) {
        data = value;
        next = nullptr;
    }
};

// Function to check if the key is present in the linked list
bool searchKey(Node* head, int key) {
    Node* current = head; // Start from the head of the linked list
    while (current != nullptr) {
        if (current->data == key) {
            return true; // Key found
        }
        current = current->next; // Move to the next node
    }
    return false; // Key not found
}

// Function to create a linked list from an array
Node* createLinkedList(int arr[], int n) {
    if (n == 0) return nullptr; // If the array is empty, return null

    Node* head = new Node(arr[0]); // Create the head node
    Node* current = head;

    for (int i = 1; i < n; i++) {
        current->next = new Node(arr[i]); // Create the next node
        current = current->next;         // Move to the new node
    }

    return head; // Return the head of the linked list
}

// Function to print the linked list (for debugging or visualization)
void printLinkedList(Node* head) {
    Node* current = head;
    while (current != nullptr) {
        cout << current->data << " ";
        current = current->next;
    }
    cout << endl;
}

// Main function
int main() {
    int n = 4;                 // Number of nodes in the linked list
    int arr[] = {1, 2, 3, 4};  // Array to create the linked list
    int key = 3;               // Key to search for

    // Create the linked list
    Node* head = createLinkedList(arr, n);

    // Print the linked list (optional)
    cout << "Linked List: ";
    printLinkedList(head);

    // Search for the key
    if (searchKey(head, key)) {
        cout << "Output: True" << endl;
    } else {
        cout << "Output: False" << endl;
    }

    // Free allocated memory (cleanup)
    Node* current = head;
    while (current != nullptr) {
        Node* nextNode = current->next;
        delete current;
        current = nextNode;
    }

    return 0;
}
