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

// Approach - 1: Using a function to construct linked list from array
// time complexity: O(N), space complexity: O(N) for linked list nodes
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


int main(){
    vector<int> arr={2,5,8,7};
    Node* head = constructLL_from_array(arr);
    // To print the linked list
    Node* temp = head;
    while(temp) {
        cout << temp->data << " ";
        temp = temp->next;
    }
    // cout << endl;
    // cout << head->data; // returns the data stored at that memory point
}