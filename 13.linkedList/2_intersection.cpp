#include <bits/stdc++.h>
using namespace std;

struct Node{
    int data;
    Node* next;
};

Node* findIntersection(Node* headA, Node* headB) {
    if(headA==NULL || headB==NULL) return NULL;
    Node* a = headA;
    Node* b = headB;
    while(a!=b){
        a=(a==NULL)?headB : a->next;
        b=(b==NULL)?headA : b->next;
    }
    return a;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    // Creating the common intersection part: 8 -> 9 -> 10 -> NULL
    Node* common = new Node{8, new Node{9, new Node{10, NULL}}};

    // Creating List A: 1 -> 2 -> 3 -> 8 -> 9 -> 10 -> NULL
    Node* headA = new Node{1, new Node{2, new Node{3, common}}};

    // Creating List B: 4 -> 5 -> 8 -> 9 -> 10 -> NULL
    Node* headB = new Node{4, new Node{5, common}};

    Node* intersectionNode = findIntersection(headA, headB);
    
    if (intersectionNode != NULL) {
        cout << "The intersection point is node with data: " << intersectionNode->data << "\n";
    } else {
        cout << "There is no intersection point.\n";
    }
    
    return 0;
}
