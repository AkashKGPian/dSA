#include <bits/stdc++.h>
using namespace std;

struct node{
    int data;
    node* next;
};

node* findMiddle(node* head){
    if(head==NULL)return NULL;
    node* slow=head;
    node* fast=head;
    while(fast!=NULL && fast->next!=NULL){
        slow=slow->next;
        fast=fast->next->next;
    }
    return slow;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    // Creating an EVEN length list: 1 -> 2 -> 3 -> 4 -> NULL
    node* headEven = new node{1, new node{2, new node{3, new node{4, NULL}}}};
    node* midEven = findMiddle(headEven);
    if(midEven != NULL) {
        cout << "Middle of even list (1->2->3->4) is: " << midEven->data << "\n";
    }

    // Creating an ODD length list: 1 -> 2 -> 3 -> 4 -> 5 -> NULL
    node* headOdd = new node{1, new node{2, new node{3, new node{4, new node{5, NULL}}}}};
    node* midOdd = findMiddle(headOdd);
    if(midOdd != NULL) {
        cout << "Middle of odd list (1->2->3->4->5) is: " << midOdd->data << "\n";
    }
    
    return 0;
}
