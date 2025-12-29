#include<bits/stdc++.h>
using namespace std;

int n,x,k;
int arr[1000100];
//find kth elem in arr from any x - using binary lifting 
int nextt[1000100][20]; //(instead of 20 we have to take log n) best practices but 20 is fine & not costly
//0-19

int main(){
    cin>>n>>x>>k;
    for(int i=1;i<=n;i++){//think this array as the linked list//or this is the parent array of the bfs tree
        cin>>arr[i];
        //since it is the par array index is the node and arr[index]=par of this node
        //above is the seq
        nextt[i][0]=arr[i];
    }
    for(int node=1;node<=n;node++){
        for(int i=1;i<20;i++){//i=0 base case above
            nextt[node][i]=nextt[nextt[node][i-1]][i-1];//as 2^i can be broken into two 2^i-1
        }
    }
    for(int i=19;i>=0;i--){
        if(k&(1<<i)){
            x=nextt[x][i];
        }
    }
    return 0;
}