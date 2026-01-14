// Remove the nth node from the end of a linked list

#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int data;
    Node *next;
    Node(int val)
    {
        data = val;
        next = NULL;
    }
};
Node *constructLL(vector<int> arr)
{
    Node *head = new Node(arr[0]);
    Node *temp = head;
    for (int i = 1; i < arr.size(); i++)
    {
        temp->next = new Node(arr[i]);
        temp = temp->next;
    }
    return head;
}

// Appraoch - 1 : Using extra space to store odd and even nodes separately and then combine them.
// Time Complexity: O(N), Space Complexity: O(N)

// Node *removeNthFromEnd(Node *head, int n)
// {
//     if (!head)
//         return head;
//     vector<Node *> nodes;
//     Node *temp = head;
//     while (temp)
//     {
//         nodes.push_back(temp);
//         temp = temp->next;
//     }
//     if (n == nodes.size())
//     {
//         return head->next;
//     }
//     Node *prevNode = nodes[nodes.size() - n - 1];
//     Node *nextNode = nullptr;
//     if (n != nodes.size() - 1)
//     {
//         nextNode = nodes[nodes.size() - n - 1]->next;
//     }
//     prevNode->next = nextNode;

//     return head;
// }

// Approach - 2: using length of linked list and two pass solution
// Time Complexity: O(N), Space Complexity: O(1)
// Node *removeNthFromEndLength(Node *head, int n)
// {
//     if (!head)
//         return head;
//     int length = 0;
//     Node *temp = head;
//     while (temp)
//     {
//         length++;
//         temp = temp->next;
//     }
//     if (n == length)
//     {
//         return head->next;
//     }
//     temp = head;
//     for (int i = 1; i < length - n; i++)
//     {
//         temp = temp->next;
//     }
//     temp->next = temp->next->next;
//     return head;
// }

// // or
// int getLength(Node *head)
// {
//     int cout = 0;
//     Node *temp = head;
//     while (temp)
//     {
//         cout++;
//         temp = temp->next;
//     }
//     return cout;
// }
// Node *removeNthFromEnd(Node *head, int n)
// {
//     int len = getLength(head);
//     if (head == NULL || head->next == NULL)
//     {
//         return NULL;
//     }
//     if (len == n)
//     {
//         Node *temp = head->next;
//         delete head;
//         return temp;
//     }
//     if (len < n)
//     {
//         return NULL;
//     }
//     int tra = len - n;
//     Node *prev = NULL;
//     Node *temp = head;
//     while (tra != 0)
//     {
//         tra--;
//         prev = temp;
//         temp = temp->next;
//     }
//     prev->next = temp->next;
//     delete temp;
//     return head;
// }

// Appraoch - 3: using one pass solution with two pointers
// Time Complexity: O(N), Space Complexity: O(1) (Optimal)

Node* removeNthFromEnd(Node* head, int n) {
        Node* temp = head;
        for (int i = 0; i < n; i++) {
            temp = temp->next;
        }
        Node* prev = head;
        if (temp == NULL) {
            Node* ans = head->next;
            delete head;
            return ans;
        }
        while (temp != NULL && temp->next != NULL) {
            temp = temp->next;
            prev = prev->next;
        }
        Node* deleteNode = prev->next;
        prev->next = prev->next->next;
        prev = temp;
        delete deleteNode;
        return head;
    }
int main()
{
    vector<int> arr = {1, 2, 3, 4, 5};
    Node *head = constructLL(arr);
    head = removeNthFromEnd(head, 2);

    Node *temp = head;
    while (temp)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
    return 0;
}