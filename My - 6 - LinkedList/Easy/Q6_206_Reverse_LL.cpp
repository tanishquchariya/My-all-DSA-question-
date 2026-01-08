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


Approach - 1: Using stack to reverse linked list
// time complexity: O(N), space complexity: O(N)
Node* reverseList(Node* head) {
    if (head == NULL || head->next == NULL) {
        return head; // If the list is empty or has only one node, return head
    }

    stack<int> st;
    Node* temp = head;

    // Push all nodes onto the stack
    while (temp != NULL) {
        st.push(temp->data);
        temp = temp->next;
    }

    // Pop nodes from the stack to reverse the linked list
    // Node* newHead = st.top();

    temp = head;
    while (temp)
    {
        temp->data = st.top();
        st.pop();
        temp = temp->next;
    }
    return head;
}

// Approach - 2: usting reursion to reverse linked list
// time complexity: O(N), space complexity: O(N) due to recursive stack
Node* reverseListRecursive(Node* head) {
    // Base case: if head is NULL or only one node, return head
    if (head == NULL || head->next == NULL) {
        return head;
    }

    // Recursively reverse the rest of the list
    Node* newHead = reverseListRecursive(head->next);

    // Make the next node point to the current head
    head->next->next = head;
    head->next = NULL; // Set the next of current head to NULL

    return newHead; // Return the new head of the reversed list
}


// Approach - 3: Iterative method to reverse linked list (optimal approach)
// time complexity: O(N), space complexity: O(1)

Node* reverseListIterative(Node* head) {
    Node* prev = NULL;
    Node* temp = head;
    Node* front = NULL;

    while (temp != NULL) {
        front = temp->next; // Store the next node
        temp->next = prev; // Reverse the current node's pointer
        prev = temp;       // Move prev to current node
        temp = front;       // Move to the next node
    }
    return prev; // New head of the reversed list
}

int main (){
    vector<int> arr = {1, 2, 3, 4, 5};
    Node* head = constructLL_from_array(arr);
    
    cout << "Original Linked List: ";
    Node* temp = head;
    while (temp != NULL) {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;

    head = reverseList(head);

    cout << "Reversed Linked List: ";
    temp = head;
    while (temp != NULL) {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;

    return 0;
}