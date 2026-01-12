// Merge Two Sorted Lists

#include <bits/stdc++.h>
using namespace std;


class Node {
public:
    int data;
    Node* next;

    Node(int x) {
        data = x;
        next = NULL;
    }
};
Node* constructLL_from_array(vector<int>& arr) {
    Node* head = new Node(arr[0]);
    Node* mover = head;

    for (int i = 1; i < arr.size(); i++) {
        Node* temp = new Node(arr[i]);
        mover->next = temp;
        mover = temp;
    }
    return head;
}
// Appraoch - 1 : store values in array and then sort array and then create linked list from array
// Time Complexity : O(nlogn)
// Space Complexity : O(n)

// Node* mergeTwoLists_Array(Node* l1, Node* l2) {
//     vector<int> values;
//     Node* temp1 = l1;
//     Node* temp2 = l2;

//     while (temp1 != NULL) {
//         values.push_back(temp1->data);
//         temp1 = temp1->next;
//     }
//     while (temp2 != NULL) {
//         values.push_back(temp2->data);
//         temp2 = temp2->next;
//     }
//     sort(values.begin(), values.end());

//     Node* newHead = new Node(values[0]);
//     Node* mover = newHead;

//     for (int i = 1; i < values.size(); i++) {
//         Node* temp = new Node(values[i]);
//         mover->next = temp;
//         mover = temp;
//     }
//     return newHead;
// }

// approach - 2 : optimal approach
// Time Complexity : O(n+m)
// Space Complexity : O(1)
Node* mergeTwoLists(Node* l1, Node* l2) {
    if(l1 == NULL && l2 == NULL) return NULL;

    Node* dummy = new Node(-1);
    Node* temp = dummy;
    Node* temp1 = l1;
    Node* temp2 = l2;
    while(temp1 != NULL && temp2 != NULL) {
        if(temp1->data < temp2->data) {
            temp->next = temp1;
            temp = temp1;
            temp1 = temp1->next;
        } else {
            temp->next = temp2;
            temp = temp2;
            temp2 = temp2->next;
        }
    }
    if(temp1 != NULL) temp->next = temp1;
    if(temp2 != NULL) temp->next = temp2;
    return dummy->next;
}
int main() {
    vector<int> arr1 = {1, 2, 4};
    vector<int> arr2 = {1, 3, 4};

    Node* l1 = constructLL_from_array(arr1);
    Node* l2 = constructLL_from_array(arr2);

    Node* mergedHead = mergeTwoLists(l1, l2);

    Node* temp = mergedHead;
    while (temp != NULL) {
        cout << temp->data << " ";
        temp = temp->next;
    }
    return 0;
}