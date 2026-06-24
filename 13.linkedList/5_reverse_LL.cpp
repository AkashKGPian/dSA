#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    Node* next;
    
    // Constructor 
    Node(int val) {
        data = val;
        next = NULL;
    }
};

// Function to reverse the linked list
Node* reverseLL(Node* head) {
    Node* prev = NULL;
    Node* curr = head;
    Node* nextTemp = NULL;

    while (curr != NULL) {
        nextTemp = curr->next;  // 1. Store the next node
        curr->next = prev;      // 2. Reverse the link
        prev = curr;            // 3. Move 'prev' one step forward
        curr = nextTemp;        // 4. Move 'curr' one step forward
    }
    
    // 'prev' will be pointing to the new head at the end
    return prev; 
}

// Helper function to print the linked list
void printLL(Node* head) {
    while(head != NULL) {
        cout << head->data << " -> ";
        head = head->next;
    }
    cout << "NULL\n";
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    // Creating list: 1 -> 2 -> 3 -> 4 -> 5 -> NULL
    Node* head = new Node(1);
    head->next = new Node(2);
    head->next->next = new Node(3);
    head->next->next->next = new Node(4);
    head->next->next->next->next = new Node(5);

    cout << "Original List: ";
    printLL(head);

    // Reversing the list
    head = reverseLL(head);

    cout << "Reversed List: ";
    printLL(head);

    return 0;
}