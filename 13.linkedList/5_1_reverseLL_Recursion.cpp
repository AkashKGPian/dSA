#include <bits/stdc++.h>
using namespace std;

struct node{
    int data;
    node* next;
};
node* head=NULL;

void reverseLL(node* p){
    if(p == NULL) return; // Safety check for empty list
    
    if(p->next==NULL){
        head=p;
        return;
    }
    reverseLL(p->next);
    p->next->next=p;
    p->next=NULL;
}

// Helper function to print the linked list
void printLL(node* p) {
    while(p != NULL) {
        cout << p->data << " -> ";
        p = p->next;
    }
    cout << "NULL\n";
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    // Creating list: 1 -> 2 -> 3 -> 4 -> 5 -> NULL
    head = new node{1, new node{2, new node{3, new node{4, new node{5, NULL}}}}};

    cout << "Original List: ";
    printLL(head);

    // Reversing the list
    reverseLL(head);

    cout << "Reversed List: ";
    printLL(head);

    return 0;
}
