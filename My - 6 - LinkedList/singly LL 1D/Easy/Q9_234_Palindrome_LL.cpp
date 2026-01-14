// Check if a linked list is a palindrome or not


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

// Approach -1 : Using array to store values
// Time Complexity : O(n)
// Space Complexity : O(n)

// bool isPalindrome(Node* head) {
//     vector<int> ans;
//     Node* temp = head;
//     while (temp != NULL) {
//         ans.push_back(temp->data);
//         temp = temp->next;
//     }
//     int left = 0;
//     int right = ans.size() - 1;
//     while (left < right) {
//         if (ans[left] != ans[right]) {
//             return false;
//         }
//         left++;
//         right--;
//     }
//     return true;
// }

// Approach -2 : Reversing the second half of the linked list using reverse function and comparing
// time Complexity : O(n)
// Space Complexity : O(1)
// Node* reverseList(Node* head) {
//     Node* prev = NULL;
//     Node* temp = head;
//     Node* front = NULL;

//     while (temp != NULL) {
//         front = temp->next;
//         temp->next = prev;
//         prev = temp;
//         temp = front;
//     }
//     return prev;
// }

// bool isPalindrome(Node* head) {
//     if (head == NULL || head->next == NULL) {
//         return true;
//     }

//     // Find the middle of the linked list
//     Node* slow = head;
//     Node* fast = head;
//     Node* prev = NULL;

//     while (fast != NULL && fast->next != NULL) {
//         prev = slow;
//         slow = slow->next;
//         fast = fast->next->next;
//     }

//     // Reverse the second half of the linked list
//     prev->next = NULL;
//     Node* secondHalf = reverseList(slow);

//     // Compare the first and second halves
//     while (secondHalf != NULL && head != NULL) {
//         if (head->data != secondHalf->data) {
//             return false;
//         }
//         head = head->next;
//         secondHalf = secondHalf->next;
//     }
//     return true;
// }

// Approach - 4 : Using recursion to check palindrome
// time Complexity : O(n)
// Space Complexity : O(n) due to recursive stack

// class Solution {
// public:
//     Node* curr;
//     bool recur(Node* head) {
//         if (head == NULL) {
//             return true;
//         }
//         bool ans = recur(head->next);
//         if (head->data != curr->data) {
//             return false;
//         }
//         curr = curr->next;
//         return ans;
//     }
//     bool isPalindrome(Node* head) {
//         curr = head;
//         return recur(head);
//     }
// };




// Approach - 4 Modified approach - 2 using without reverse function (optimal approach)
// time Complexity : O(n)
// Space Complexity : O(1)

bool isPalindrome(Node* head) {
    if (head == NULL || head->next == NULL) {
        return true;
    }
    // Find the middle of the linked list
    Node* slow = head;
    Node* fast = head;
    Node* prev = NULL;

    while (fast != NULL && fast->next != NULL) {
        fast = fast->next->next;
        Node* nextNode = slow->next;
        slow->next = prev;
        prev = slow;
        slow = nextNode;
    }
    // If the linked list has odd number of nodes, move slow one step forward
    if (fast != NULL) {
        slow = slow->next;
    }
    // Compare the first and second halves

    while (prev != NULL && slow != NULL) {
        if (prev->data != slow->data) {
            return false;
        }
        prev = prev->next;
        slow = slow->next;
    }
    return true;
}



int main() {
    vector<int> arr = {1, 2, 3, 2, 1};
    Node* head = constructLL_from_array(arr);
    if (isPalindrome(head)) {
        cout << "The linked list is a palindrome." << endl;
    } else {
        cout << "The linked list is not a palindrome." << endl;
    }
    return 0;
}