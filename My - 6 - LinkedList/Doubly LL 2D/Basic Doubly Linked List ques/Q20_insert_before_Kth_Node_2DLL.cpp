// insert before tail in 2D LL
// insert at head of doubly linked list (or) insert before the head of 2 DLL

#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int data;
    Node *next;
    Node *back;

    Node(int data1, Node *next1, Node *back1)
    {
        data = data1;
        next = next1;
        back = back1;
    }
    Node(int data1)
    {
        data = data1;
        next = nullptr;
        back = nullptr;
    }
};

// Convert array to DLL
Node *converArrToDll(vector<int> &arr)
{
    if (arr.empty())
        return nullptr; // Handle empty array case

    Node *head = new Node(arr[0]);
    Node *prev = head;

    for (int i = 1; i < arr.size(); i++)
    {
        Node *temp = new Node(arr[i], nullptr, prev); // Create new node
        prev->next = temp;
        prev = temp;
    }

    return head;
}

Node* insertathead(Node* head, int val){
    Node* newNode  = new Node(val);
    newNode->next = head;
    head->back = newNode;
    return newNode;
}

Node *insertBeforeTail(Node *head, int val)
{

    if (head->next == NULL)
    {
        return insertathead(head,val);
    }

    Node *tail = head;
    while (tail->next != NULL)
    {
        tail = tail->next;
    }
    Node *prev = tail->back;
    Node *newNode = new Node(val, tail, prev);
    prev->next = newNode;
    tail->back = newNode;
    return head;
}

// insert before kth Node in 2D LL 
Node* insertKthNode(Node* head, int val, int k){
    if(k == 1){
        return insertathead(head,val);
    }

    Node* temp = head;
    int cont = 0;
    while(temp != NULL){
        cont++;
        if(cont == k){
            break;
        }
        temp = temp->next;
    }
    Node* prev = temp->back;
    Node* newNode = new Node(val,temp,prev);
    prev->next = newNode;
    temp->back = newNode;
    return head;
}

// or solution of geeksforgeeks in which insert after k + 1 th node

/* Structure of Node
class Node {
  public:
    int data;
    Node* next;
    Node* prev;

    Node(int x) {
        data = x;
        next = prev = nullptr;
    }
};
*/

// class Solution {
//   public:

//     // Insert at head
//     Node* inserthead(Node* head, int x){
//         Node* newNode = new Node(x);

//         if(head == NULL){
//             return newNode;
//         }

//         newNode->next = head;
//         head->prev = newNode;

//         return newNode;
//     }

//     // Insert at tail
//     Node* inserttail(Node* head, int x){
//         Node* newNode = new Node(x);

//         if(head == NULL){
//             return newNode;
//         }

//         Node* temp = head;
//         while(temp->next != NULL){
//             temp = temp->next;
//         }

//         temp->next = newNode;
//         newNode->prev = temp;
//         return head;
//     }

//     // Insert at position p (0-based indexing)
//     Node* insertAtPos(Node* head, int p, int x) {
//         if(head == NULL){
//             return new Node(x);
//         }


//         Node* temp = head;
//         int count = 0;

//         while(temp != NULL && count < p){
//             temp = temp->next;
//             count++;
//         }

//         // Insert at tail if position is beyond length
//       // if p is beyond list length → insert at tail
//         if(temp == NULL){
//             return inserttail(head, x);
//         }

//         Node* newNode = new Node(x);
//         Node* front = temp->next;

//         newNode->next = front;
//         newNode->prev = temp;
//         temp->next = newNode;

//         if(front != NULL){
//             front->prev = newNode;
//         }

//         return head;
//     }
// };



// Print function
void print(Node *head)
{
    while (head != NULL)
    {
        cout << head->data << " ";
        head = head->next;
    }
}

int main()
{
    vector<int> arr = {4, 6, 7, 8, 28}; // Correct initialization of the vector
    Node *head = converArrToDll(arr);   // Pass the array to the function
    head = insertKthNode(head, 62,3);
    print(head); // Print the DLL
    return 0;
}
