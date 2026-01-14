#include<bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    Node* next;

    Node(int x) {
        data = x;
        next = NULL;
    }
};
 Node* constructLL_from_array(vector<int>& arr) {
        // code here
        Node* head = new Node(arr[0]);
        Node* mover = head;
        
        for(int i = 1; i<arr.size(); i++){
            Node* temp = new Node(arr[i]);
            mover->next = temp;
            mover = temp;
        }
        return head;
    }
// Approach - 1: Using two-pointer technique to find middle of linked list (optimal approach)
// time complexity: O(N), space complexity: O(1)
Node* middle(Node* head) {
    Node* slow = head;
    Node* fast = head;
    while (fast != NULL && fast->next != NULL) {
        slow = slow->next;
        fast = fast->next->next;
    }
    return slow;
}

// Approach - 2: Using length of linked list to find middle node
// time complexity: O(N), space complexity: O(1)

//  int lengthLL(Node* head) {
//         int cout = 0;
//         Node* temp = head;
//         while (temp != NULL) {
//             cout++;
//             temp = temp->next;
//         }
//         return cout;
//     }
//     Node* middleNode(Node* head) {
//         int cout = lengthLL(head);
//         int ans = cout / 2;
//         int cout2 = 0;
//         Node* temp = head;
//         while (cout2 < ans) {
//             cout2++;
//             temp = temp->next;
//         }
//         return temp;
//     }

// Example usage
int main (){
    vector<int> arr = {1, 2, 3, 4, 5};
    Node* head = constructLL_from_array(arr);
    
    Node* midNode = middleNode(head);
    cout << "Middle node using length calculation: " << midNode->data << endl;

    return 0;
}