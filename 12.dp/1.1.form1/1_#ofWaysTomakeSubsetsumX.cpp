#include<bits/stdc++.h>
using namespace std;
//find the no. of ways to make a subset of arr with sum X
// 4 5
// 1 2 3 4

// why not just saved[i][x] 
// Because saved[i][x] could legitimately be 0 (i.e., zero ways to form sum x using elements from index i onward), and we still want to cache and return that.

int n,X;
int arr[1010];

int saved[1010][1010];

int rec(int i, int x){
    if(x<0)return 0;//pruning - optimizing even further
    if(i==n){
        if(x==0)return 1;
        else return 0;
    }
    if(saved[i][x] != -1){// why not just saved[i][x] 
        return saved[i][x];
    }
    int noOfways = rec(i+1,x) + rec(i+1,x-arr[i]);//not take + take
    saved[i][x] = noOfways;
    return noOfways;
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