// Sort a linked list in O(n log n) time using merge sort algorithm

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

// Approach - 1 : using merg two sort list and find mid
// Time Complexity : O(nlogn)
// Space Complexity : O(logn)  // recursive stack space

class Solution {
public:
    Node* findmid(Node* head) {
        Node* slow = head;
        Node* fast = head->next;
        while (fast != NULL && fast->next != NULL) {
            slow = slow->next;
            fast = fast->next->next;
        }
        return slow;
    }
    Node* mergeTwoLists(Node* l1, Node* l2) {
        Node* temp1 = l1;
        Node* temp2 = l2;
        Node* dumyNode = new Node(-1);
        Node* temp = dumyNode;
        if (l1 == NULL && l2 == NULL) {
            return NULL;
        }
        while (temp1 != NULL && temp2 != NULL) {
            if (temp1->data < temp2->data) {
                temp->next = temp1;
                temp = temp1;
                temp1 = temp1->next;
            } else {
                temp->next = temp2;
                temp = temp2;
                temp2 = temp2->next;
            }
        }
        if (temp1 != NULL) {
            temp->next = temp1;
        } else {
            temp->next = temp2;
        }
        return dumyNode->next;
    }
    Node* sortList(Node* head) {
        if (head == NULL || head->next == NULL) {
            return head;
        }
        Node* mid = findmid(head);
        Node* right = mid->next;
        mid->next = NULL;
        Node* left = head;
        Node* next = NULL;

        left = sortList(left);
        right = sortList(right);

        return mergeTwoLists(left, right);
    }
};

int main() {
    vector<int> arr = {4, 2, 1, 3};
    Node* head = constructLL_from_array(arr);

    Solution sol;
    Node* sortedHead = sol.sortList(head);

    // Print sorted linked list
    Node* temp = sortedHead;
    while (temp != NULL) {
        cout << temp->data << " ";
        temp = temp->next;
    }
    return 0;
}