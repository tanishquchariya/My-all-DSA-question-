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

void deleteNode (Node* temp){
    Node* prev = temp->back;
    Node* front = temp->next;

    if(front == NULL){
        prev->next = NULL;
        temp->back = NULL;
        delete temp;
        return;
    }
    prev->next = front;
    front->back = prev;
    temp->next = temp->back = NULL;
    delete temp;
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
    deleteNode(head->next->next);
    print(head); // Print the DLL
    return 0;
}
