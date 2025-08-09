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

// // delete head
// Node *deleteHead2dLL(Node *head)
// {
//     if (head == NULL && head->next == NULL)
//     {
//         return NULL;
//     }

//     Node *prev = head;
//     head = head->next;
//     head->back = NULL;
//     prev->next = NULL;
//     delete prev;
//     return head;
// }
// // delete head of 2D LL
// Node *deleteTail2dLL(Node *head)
// {
//     if (head == NULL && head->next == NULL)
//     {
//         return NULL;
//     }
//     Node *tail = head;
//     while (tail->next != NULL)
//     {
//         tail = tail->next;
//     }

//     Node *prev = tail->back;
//     prev->next = NULL;
//     tail->back = NULL;

//     delete tail;
//     return head;
// }

void insertatGivenNode(Node *nodeG, int val)
{

    Node *prev = nodeG->back;
    Node *newNode = new Node(val, nodeG, prev);
    prev->next = newNode;
    nodeG->back = newNode;
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
    insertatGivenNode(head->next->next, 200);
    print(head); // Print the DLL
    return 0;
}
