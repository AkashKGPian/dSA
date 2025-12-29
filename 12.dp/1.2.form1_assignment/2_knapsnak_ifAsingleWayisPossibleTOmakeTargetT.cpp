#include <bits/stdc++.h>
using namespace std;
//find if a subset adds upto a target t
int n,t;
int x[101];
int dp[101][10010];

int rec(int level, int sum_taken){
    //pruning
    if(sum_taken>t)return 0;
    //base case
    if(level>n){
        if(sum_taken==t)return 1;
        else return 0;
    }
    //cache check
    if(dp[level][sum_taken]!=-1){
        return dp[level][sum_taken];
    }
    //transitions
    int ans = 0;//assumed not possible
    if(rec(level+1,sum_taken)==1){//checking next level
        ans=1;
    }else if(rec(level+1,sum_taken+x[level])==1){
        ans=1;
    }
    //save and compute
    return dp[level][sum_taken] = ans;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    memset(dp,-1,sizeof(dp));
    cin>>n>>t;
    for(int i=1;i<=n;i++){
        cin>>x[i];
    }
    if(rec(1,0)){
        cout<<"YES\n";
    }else{
        cout<<"NO\n";
    }
    return 0;
}
