#include<bits/stdc++.h>
using namespace std;
//find the min no. of elem/size of the array arr to make the subset of with sum X
// 5 9
// 1 3 4 5 2


const int INF = 1e9;

int n,X;
int arr[1010];

int saved[1010][1010];

int rec(int i, int x){
    if(x<0)return INF;//pruning - optimizing even further
    //base case
    if(i==n){
        if(x==0)return 0;
        else return INF;
    }
    //cache check
    if(saved[i][x] != -1){
        return saved[i][x];
    }
    int onlyWay = min( rec(i+1,x) , 1+rec(i+1,x-arr[i]) );//not take + take
    saved[i][x] = onlyWay;
    return onlyWay;
}


int main(){
    memset(saved,-1,sizeof(saved));
    cin>>n>>X;
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    cout<<rec(0,X);
    return 0;
}