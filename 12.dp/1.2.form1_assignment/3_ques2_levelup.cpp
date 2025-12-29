#include <bits/stdc++.h>
using namespace std;
//print a subset that adds upto target t given  q queries ;
int n,t,q;
int x[101];
int dp[101][10010];

int rec(int level, int sum_left){
    //pruning
    if(sum_left<0)return 0;
    //base case
    if(level>n){
        if(sum_left==0)return 1;
        else return 0;
    }
    //cache check
    if(dp[level][sum_left]!=-1){
        return dp[level][sum_left];
    }
    //transitions
    int ans = 0;//assumed not possible
    if(rec(level+1,sum_left)==1){//checking next level
        ans=1;
    }else if(rec(level+1,sum_left-x[level])==1){
        ans=1;
    }
    //save and compute
    return dp[level][sum_left] = ans;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    memset(dp,-1,sizeof(dp));
    cin>>n>>q;
    for(int i=1;i<=n;i++){
        cin>>x[i];
    }
    while(q--){
        cin>>t;
        if(rec(1,t)){
            cout<<"YES\n";
        }else{
            cout<<"NO\n";
        }
    }
    return 0;
}
