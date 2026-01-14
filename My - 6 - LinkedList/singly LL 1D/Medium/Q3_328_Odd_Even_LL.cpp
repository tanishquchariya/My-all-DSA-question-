// Reorder a linked list such that all odd-indexed nodes come before even-indexed nodes

#include <bits/stdc++.h>
using namespace std;

class Node {
public:
    int data;
    Node* next;
    Node(int val) {
        data = val;
        next = NULL;
    }
};
Node* constructLL(vector<int> arr) {
    Node* head = new Node(arr[0]);
    Node* temp = head;
    for (int i = 1; i < arr.size(); i++) {
        temp->next = new Node(arr[i]);
        temp = temp->next;
    }
    return head;
}


// Approach - 1: Using extra space to store odd and even nodes separately and then combine them.
// Time Complexity: O(N), Space Complexity: O(N)

// Node* oddEvenListExtraSpace(Node* head) {
//     if (!head) return head;

//     vector<Node*> oddNodes;
//     vector<Node*> evenNodes;
//     Node* temp = head;
//     int index = 1;

//     while (temp) {
//         if (index % 2 != 0) {
//             oddNodes.push_back(temp);
//         } else {
//             evenNodes.push_back(temp);
//         }
//         temp = temp->next;
//         index++;
//     }

//     for (int i = 0; i < oddNodes.size() - 1; i++) {
//         oddNodes[i]->next = oddNodes[i + 1];
//     }
//     if (!evenNodes.empty()) {
//         oddNodes.back()->next = evenNodes[0];
//         for (int i = 0; i < evenNodes.size() - 1; i++) {
//             evenNodes[i]->next = evenNodes[i + 1];
//         }
//         evenNodes.back()->next = NULL;
//     } else {
//         oddNodes.back()->next = NULL;
//     }

//     return oddNodes[0];
// }


// Approach - 2: Maintain two pointers, one for odd and one for even nodes. Rearrange the next pointers accordingly.
// Time Complexity: O(N), Space Complexity: O(1) (Optimal)
Node* oddEvenList(Node* head) {
    if (!head || !head->next) return head;

    Node* odd = head;
    Node* even = head->next;
    Node* evenstart = even;

    while (even && even->next) {
        odd->next = even->next;
        odd = odd->next;
        even->next = odd->next;
        even = even->next;
    }
    odd->next = evenstart;
    return head;
}

int main() {
    vector<int> arr = {1, 2, 3, 4, 5};
    Node* head = constructLL(arr);
    head = oddEvenList(head);

    Node* temp = head;
    while (temp) {
        cout << temp->data << " ";
        temp = temp->next;
    }
    return 0;
}