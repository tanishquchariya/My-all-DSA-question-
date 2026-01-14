// delete the begining or head of the linked list
// how to Search an element in the LL
#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int data;
    Node *next;

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

Node *constructLL(vector<int> &arr)
{

    Node *head = new Node(arr[0]);
    Node *mover = head;

    for (int i = 1; i < arr.size(); i++)
    {
        Node *temp = new Node(arr[i]);
        mover->next = temp;
        mover = temp;
    }
    return head;
}
void print(Node *head)
{
    while (head != NULL)
    {
        cout << head->data << " ";
        head = head->next;
    }
}
// Node *deletehead(Node *head)
// {
//     if (head == NULL)
//         return NULL;
//     Node *temp = head;
//     head = head->next;
//     delete temp;
//     return head;
// }
// Node *removeTail(Node *head)
// {
//     if (head == NULL || head->next == NULL)
//     {
//         return NULL;
//     }
//     Node *temp = head;
//     while (temp->next->next != NULL)
//     {
//         temp = temp->next;
//     }
//         delete temp->next;
//         temp->next = nullptr;
//         return head;
// }
Node *removeKth(Node *head, int k)
{
    if (head == NULL)
        return NULL;
    if (k == 1)
    {
        Node *temp = head;
        head = head->next;
        delete temp;
        return head;
    }
    // kth element
    int count = 0;
    Node *temp = head;
    Node *prev = NULL;
    while (temp != NULL)
    {
        count++;
        if (count == k)
        {
            prev->next = prev->next->next;
            delete temp;
            break;
        }
        prev = temp;
        temp = temp->next;
    }
    return head;
}
int main()
{
    vector<int> arr = {2, 5, 8, 7};
    Node *head = constructLL(arr);
    head = removeKth(head,3);
    print(head);
}