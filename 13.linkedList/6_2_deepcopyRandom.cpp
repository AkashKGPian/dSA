#include <bits/stdc++.h>
using namespace std;

// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;

    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};

class Solution {
public:
    Node* copyRandomList(Node* head) {

        if(head == NULL) return NULL;

        Node* curr = head;

        // Phase 1: Insert copied nodes in between
        while(curr){
            Node* copy = new Node(curr->val);

            copy->next = curr->next;
            curr->next = copy;

            curr = copy->next;
        }

        // Phase 2: Fix random pointers
        curr = head;

        while(curr){
            if(curr->random){
                curr->next->random = curr->random->next;
            }

            curr = curr->next->next;
        }

        // Phase 3: Separate original and copied list
        curr = head;
        Node* copyHead = head->next;

        while(curr){

            Node* copy = curr->next;

            curr->next = copy->next;

            if(copy->next){
                copy->next = copy->next->next;
            }

            curr = curr->next;
        }

        return copyHead;
    }
};