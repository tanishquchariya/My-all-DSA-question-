// inserting at kth position in LL
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

Node *insertatposition(Node *head, int el, int k)
{
    if (head == NULL)
    {
        if (k == 1)
        {
            return new Node(el);
        }
        else
        {
            return NULL;
        }
    }
    if (k == 1)
    {
        return new Node(el, head);
    }
    int count = 0;
    Node *temp = head;
    while (temp != NULL)
    {
        count++;
        if (count == (k - 1))
        {
            Node *x = new Node(el, temp->next);
            temp ->next = x;
            break;
        }
        temp = temp->next;
    }
    return head;
}
int main()
{
    vector<int> arr = {2, 5, 8, 7};
    Node *head = constructLL(arr);
    head = insertatposition(head,62,3);
    print(head);
}