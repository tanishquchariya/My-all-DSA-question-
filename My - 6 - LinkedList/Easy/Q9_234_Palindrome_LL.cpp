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

// Approach: Using array to store values
// Time Complexity : O(n)
// Space Complexity : O(n)

bool isPalindrome(Node* head) {
    vector<int> ans;
    Node* temp = head;
    while (temp != NULL) {
        ans.push_back(temp->data);
        temp = temp->next;
    }
    int left = 0;
    int right = ans.size() - 1;
    while (left < right) {
        if (ans[left] != ans[right]) {
            return false;
        }
        left++;
        right--;
    }
    return true;
}

// Ap

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