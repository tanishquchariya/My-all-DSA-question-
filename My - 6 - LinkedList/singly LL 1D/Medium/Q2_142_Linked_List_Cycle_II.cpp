// Find the starting node of a cycle in a linked list

#include <bits/stdc++.h>
using namespace std;
class Node
{
public:
    int data;
    Node *next;

    Node(int x)
    {
        data = x;
        next = NULL;
    }
};
Node *constructLL_from_array(vector<int> &arr)
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

// Approach - 1 : using set
// Time Complexity : O(n)
// Space Complexity : O(n)
// Node* detectCycle(Node* head) {
//     unordered_set<Node*> s;
//     Node* temp = head;
//     while (temp != NULL) {
//         if (s.find(temp) != s.end()) {
//             return temp;
//         }
//         s.insert(temp);
//         temp = temp->next;
//     }
//     return NULL;
// }

// Approach - 2 : using Floyd's Cycle Detection Algorithm
// Time Complexity : O(n)
// Space Complexity : O(1)
Node *detectCycle(Node *head)
{
    if (head == NULL || head->next == NULL)
    {
        return NULL;
    }
    Node *slow = head;
    Node *fast = head;
    while (fast != NULL && fast->next != NULL)
    {
        slow = slow->next;
        fast = fast->next->next;
        if (slow == fast)
        {
            break;
        }
    }
    if (slow != fast)
    {
        return NULL;
    }
    Node *p = head;
    while (p != slow)
    {
        p = p->next;
        slow = slow->next;
    }
    return p;
}

int main()
{
    vector<int> arr = {3, 2, 0, -4};
    Node *head = constructLL_from_array(arr);
    head->next->next->next->next = head->next; // creating a cycle for testing

    Node *cycleStartNode = detectCycle(head);
    if (cycleStartNode != NULL)
    {
        cout << "Cycle starts at node with value: " << cycleStartNode->data << endl;
    }
    else
    {
        cout << "No cycle detected." << endl;
    }

    return 0;
}