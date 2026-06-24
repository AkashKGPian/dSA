#include <bits/stdc++.h>
using namespace std;

struct Node{
    int data;
    Node* next;
};

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    Node* head=NULL;
    Node* tail=NULL;
    for(int i=0;i<n;i++){
        Node* curr = new Node();
        curr->data = arr[i];
        if(i==0){
            head=curr;
            tail=curr;
        }else{
            tail->next=curr;
            tail=curr;
        }
    }
    return 0;
}
