#include<bits/stdc++.h>
using namespace std;
#define int long long
const int INF = 2e9;

int n,k;
int h[100100];
int vis[100100];
int dp[100100];

int rec(int level){
    //pruning
    //base case
    if(level==0){
        return 0;
    }
    //cache check
    if(vis[level]!=0){
        return dp[level];
    }
    //compute
    int ans=INF;
    for(int j=1;j<=k;j++){
        if(level-j>=0){
            ans = min(ans,abs(h[level]-h[level-j])+rec(level-j));
        }        
    }
    //save and return 
    vis[level]=1;
    return dp[level]=ans;
}

signed main(){
    cin>>n>>k;
    for(int i=0;i<n;i++){
        cin>>h[i];
        vis[i]=0;
    }
    cout<<rec(n-1);
    return 0;
}