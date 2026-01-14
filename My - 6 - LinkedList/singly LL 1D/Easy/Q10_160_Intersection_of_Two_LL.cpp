// Find the intersection of two linked lists

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

// Approach - 1 : using hash map
// Time Complexity : O(n)
// Space Complexity : O(n)

// Node* getIntersectionNode(Node* headA, Node* headB) {
//     unordered_map<Node*, int> mp;
//     Node* temp = headA;
//     while (temp != NULL) {
//         mp[temp] = true;
//         temp = temp->next;
//     }
//   Node* temp2= headB;
//     while (temp2 != NULL) {
//         if (mp.find(temp2) != mp.end()) {
//             return temp2;
//         }
//         temp2 = temp2->next;
//     }
//     return NULL;
// }

// Approach - 2 : using brute force
// Time Complexity : O(m*n)
// Space Complexity : O(1)
// Node* getIntersectionNode(Node* headA, Node* headB) {

//     while(headB != NULL) {
//         Node* temp = headA;
//         while(temp != NULL) {
//             if(temp == headB) {
//                 return headB;
//             }
//             temp = temp->next;
//         }
//         headB = headB->next;
//     }
//     return NULL;
// }

// Approach - 3 : using length of linked list


// Approach - 4 :- optimal approach without using extra space 
// Time Complexity : O(n)
// Space Complexity : O(1)

Node* getIntersectionNode(Node* headA, Node* headB) {
    if (headA == NULL || headB == NULL) {
        return NULL;
    }
    Node* temp1 = headA;
    Node* temp2 = headB;

    while (temp1 != temp2) {
        temp1 = temp1->next;
        temp2 = temp2->next;
        if(temp1 == temp2) {
            return temp1;
        }
        if (temp1 == NULL) {
            temp1 = headB;
        }
        if (temp2 == NULL) {
            temp2 = headA;
        }

    }
    return temp1; // or temp2, both are same at intersection point or NULL
}


int main() {
    vector<int> arr1 = {4, 1, 8, 4, 5};
    vector<int> arr2 = {5, 0, 1, 8, 4, 5};

    Node* headA = constructLL_from_array(arr1);
    Node* headB = constructLL_from_array(arr2);

    // Creating intersection for testing
    headB->next->next->next = headA->next->next; // Pointing node with value 1 in list B to node with value 8 in list A

    Node* intersectionNode = getIntersectionNode(headA, headB);
    if (intersectionNode != NULL) {
        cout << "Intersection at node with value: " << intersectionNode->data << endl;
    } else {
        cout << "No intersection." << endl;
    }

    return 0;
}   