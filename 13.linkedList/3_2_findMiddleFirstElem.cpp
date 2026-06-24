#include <bits/stdc++.h>
using namespace std;

struct node {
    int data;
    node* next;
};

// Function to find the FIRST middle node
node* findFirstMiddle(node* head) {
    if(head == NULL) return NULL;
    
    node* slow = head;
    node* fast = head;
    
    // Notice the difference here: we check fast->next and fast->next->next
    while(fast->next != NULL && fast->next->next != NULL) {
        slow = slow->next;
        fast = fast->next->next;
    }
    
    return slow;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    // Creating an EVEN length list: 1 -> 2 -> 3 -> 4 -> NULL
    // First middle of this is 2
    node* headEven = new node{1, new node{2, new node{3, new node{4, NULL}}}};
    node* midEven = findFirstMiddle(headEven);
    if(midEven != NULL) {
        cout << "First middle of even list (1->2->3->4) is: " << midEven->data << "\n";
    }

    // Creating an ODD length list: 1 -> 2 -> 3 -> 4 -> 5 -> NULL
    // Middle of this is 3
    node* headOdd = new node{1, new node{2, new node{3, new node{4, new node{5, NULL}}}}};
    node* midOdd = findFirstMiddle(headOdd);
    if(midOdd != NULL) {
        cout << "Middle of odd list (1->2->3->4->5) is: " << midOdd->data << "\n";
    }


    // Why this works:
    //     It stops the fast pointer one step earlier. For an even list like 1->2->3->4:

    //     slow=1, fast=1
    //***  Loop checks fast->next (2) and fast->next->next (3). Both are not NULL.
    //     slow moves to 2, fast moves to 3.
    //     Loop checks fast->next (4) and fast->next->next (NULL). The second condition is false.
    //     Loop terminates. slow stops at Node 2 (the first middle node).
            
    return 0;
}