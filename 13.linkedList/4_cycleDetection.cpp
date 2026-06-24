#include <bits/stdc++.h>
using namespace std;

struct node{
    int data;
    node* next;
};

node* cycleDetection(node* head){
    if(head==NULL)return NULL;
    node* slow=head;
    node* fast=head;
    while(fast!=NULL && fast->next!=NULL){
        slow=slow->next;
        fast=fast->next->next;
        if(slow==fast)return slow; // Cycle detected, return the meeting point
    }
    return NULL; // No cycle detected
}

node* getCycleStart(node* head) {
    node* meet = cycleDetection(head);
    if(meet == NULL) return NULL; // No cycle
    
    // Reset one pointer to head, keep the other at the meeting point
    node* start = head;
    
    // Move both one step at a time until they meet
    while(start != meet) {
        start = start->next;
        meet = meet->next;
    }
    
    // The point where they meet is the start of the cycle
    return start;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    // 1. List WITHOUT cycle: 1 -> 2 -> 3 -> NULL
    node* headNoCycle = new node{1, new node{2, new node{3, NULL}}};
    
    // 2. List WITH cycle: 1 -> 2 -> 3 -> 4 -> (points back to 2)
    node* node4 = new node{4, NULL};
    node* node3 = new node{3, node4};
    node* node2 = new node{2, node3};
    node* headCycle = new node{1, node2};
    node4->next = node2; // Creating the cycle here
    
    // Testing first list
    if (cycleDetection(headNoCycle) != NULL) {
        cout << "Cycle detected in first list.\n";
    } else {
        cout << "No cycle detected in first list.\n";
    }
    
    // Testing second list
    node* meet = cycleDetection(headCycle);
    if (meet != NULL) {
        cout << "Cycle detected in second list! Meeting point data: " << meet->data << "\n";
        
        node* startNode = getCycleStart(headCycle);
        cout << "Cycle exactly starts at node with data: " << startNode->data << "\n";
    } else {
        cout << "No cycle detected in second list.\n";
    }

    return 0;
}
