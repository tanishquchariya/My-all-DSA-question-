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
    head = insertBeforeTail(head, 62);
    print(head); // Print the DLL
    return 0;
}
