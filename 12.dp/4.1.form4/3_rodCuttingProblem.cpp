#include<bits/stdc++.h>
using namespace std;
const int INF=1e9;
// MIXTURES - Mixtures spoj

int n;
int x[1001];
int dp[1001][1001];

int rec(int l, int r){
    //pruning
    //basecase
    if(l+1==r)return 0;
    //cachecheck
    if(dp[l][r]!=-1){
        return dp[l][r];
    }
    //compute
    int ans=1e9;
    for(int p=l+1; p<=r-1;p++){
        ans=min(ans, (x[r]-x[l])+rec(l,p)+rec(p,r));
    }
    //save and return 
    return dp[l][r]=ans;
}
int main(){
    cin>>n;
    memset(dp,-1,sizeof(dp));
    x[0]=0;
    for(int i=1;i<=n;i++){
        cin>>x[i];
    }
    cout<<rec(0,n)<<"\n";
    return 0;
}