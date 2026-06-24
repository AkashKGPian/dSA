#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
    Node(int val) : data(val), next(nullptr) {}
};

// Function to print the linked list
void printLL(Node* head) {
    while(head != nullptr) {
        cout << head->data << " -> ";
        head = head->next;
    }
    cout << "NULL\n";
}

// Function to duplicate the linked list
Node* duplicateLinkedList(Node* head) {
    if (head == nullptr) return nullptr;

    // Step 1: Insert new nodes between the original nodes
    // e.g., 1 -> 2 -> 3  =>  1 -> 1* -> 2 -> 2* -> 3 -> 3*
    Node* curr = head;
    while (curr != nullptr) {
        Node* copy = new Node(curr->data);
        copy->next = curr->next;
        curr->next = copy;
        curr = copy->next; // Move to the next original node
    }

    // Step 2: Separate the original and the duplicated linked list
    Node* orig = head;
    Node* copyHead = head->next; // The new copy list head
    Node* copy = copyHead;

    while (orig != nullptr) {
        // Skip over the copy to connect to the next original node
        orig->next = orig->next->next;
        
        // Skip over the original to connect to the next copy node
        if (copy->next != nullptr) {
            copy->next = copy->next->next;
        }

        // Advance both pointers
        orig = orig->next;
        copy = copy->next;
    }

    // Return the head of the newly extracted duplicated list
    return copyHead;
}

int main() {
    // 1. Create a dummy linked list: 1 -> 2 -> 3 -> 4 -> NULL
    Node* head = new Node(1);
    head->next = new Node(2);
    head->next->next = new Node(3);
    head->next->next->next = new Node(4);

    cout << "Original List before duplication: \n";
    printLL(head);

    // 2. Perform the duplication and separation
    Node* duplicatedHead = duplicateLinkedList(head);

    cout << "\nOriginal List after separation (restored): \n";
    printLL(head);

    cout << "\nDuplicated List: \n";
    printLL(duplicatedHead);

    return 0;
}
