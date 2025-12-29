#include<bits/stdc++.h>
using namespace std;

int n,W;
int w[1001];
int v[1001];
int dp[1001][1001];

int rec(int level, int Wleft){//from [level to n-1] how many ways u have to make Wleft
    //pruning
    //base case
    if(level==n){//from n to n-1
        if(Wleft==0)return 1;
        else return 0;
    }
    //cache check
    if(dp[level][Wleft]!=-1){
        return dp[level][Wleft];
    }
    //transitions
    int ans = rec(level+1,Wleft);
    if(w[level]<=Wleft){
        ans = max(ans,v[level]+rec(level+1,Wleft-w[level]));
    }
    //save and return 
    dp[level][Wleft]=ans;
    return ans;
}

int main(){
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>w[i];
    }
    for(int i=0;i<n;i++){
        cin>>v[i];
    }
    cin>>W;
    cout<<rec(0,W);
    return 0;
}