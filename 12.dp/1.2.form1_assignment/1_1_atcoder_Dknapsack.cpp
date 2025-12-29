#include<bits/stdc++.h>
using namespace std;
#define int long long
const int INF=1e9;

int n,W;
int w[101];
int v[101];

int dp[101][100100];

int rec(int level,int Wleft){
    //pruning
    // if(Wleft<0){
    //     return -INF;
    // }
    //basecase
    if(level==n){
        if(Wleft>=0)return 0;
        else return -INF;
    }
    //cache check
    if(dp[level][Wleft]!=-1){
        return dp[level][Wleft];
    }
    //transitions
    int ans=rec(level+1,Wleft);
    if(w[level]<=Wleft){
        ans=max(ans,v[level]+rec(level+1,Wleft-w[level]));
    }
    //save and return 
    return dp[level][Wleft]=ans;
}

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    cin>>n>>W;
    memset(dp,-1,sizeof(dp));
    for(int i=0;i<n;i++){
        cin>>w[i]>>v[i];
    }
    cout<<rec(0,W);
    return 0;
}