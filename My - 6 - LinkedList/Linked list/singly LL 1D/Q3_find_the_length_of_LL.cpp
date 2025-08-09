// count the linked list node (or)find the length of linked list
// How to traverse entire linked list and print

#include <bits/stdc++.h>
using namespace std;

class Node{
public:
    int data;
    Node *next;

// public:
//     Node(int data1, Node *next1)
//     {
//         data = data1;
//         next = next1;
//     }
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
int lengthofLL(Node *head)
{
    int count = 0;
    Node *temp = head;
    while (temp)
    {
        temp = temp->next;
        count++;
    }
    return count;
}
int main()
{
    vector<int> arr = {2, 5, 8, 7};
    Node *head = constructLL(arr);
    cout << lengthofLL(head);
}