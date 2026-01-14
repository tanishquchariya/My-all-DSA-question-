#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    Node *next;

public:
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

 Node* constructLL(vector<int>& arr) {
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
    // int findlengthLL(Node* head){
    //     int count = 0;
    //     Node* temp = head;
    //     while(temp != nullptr){
    //         temp = temp->next;
    //         count++;
    //     }
    //     return count;
    // }
    int searchnodeLL(Node* head, int val){
        Node*temp = head;
        while(temp!= nullptr){
            if(temp->data == val){
                return 1;
                temp = temp->next;
            }
        }
        return 0;
    }
int main(){
    vector<int> arr={2,5,8,7};
    Node* head = constructLL(arr);
    // cout<<head->data; // returns the data stored at that memory point
    // Node* temp = head;
    // while(temp != nullptr){
    //     cout<<temp->data;
    //    temp = temp->next;
    // }
    // cout<<findlengthLL(head);
    cout<<searchnodeLL(head,2);
}