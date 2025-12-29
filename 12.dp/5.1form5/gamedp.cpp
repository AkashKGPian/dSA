#include<bits/stdc++.h>
using namespace std;

int dp[1001];

int rec(int x){
    //base case
    if(x==0)return 0;
    //cache check
    if(dp[x]!=-1){
        return dp[x];
    }
    //transitions
    int ans=0;//is a losing position
    for(int i=0;(1<<i)<=x;i++){
        if(rec(x-(1<<i))==0){//if at this stage if he can push opponent in losing postion he wins
            ans=1;
            break;
        }
    }
    //save and return 
    return dp[x]=ans;
}

int main(){
    int tt;
    cin>>tt;
    memset(dp,-1,sizeof(dp));
    while(tt--){
        int x;
        cin>>x;
        // cout<<rec(x)<<"\n";
        //o(1)
        if(x%3==0){
            cout<<0<<"\n";
        }else{
            cout<<1<<"\n";
        }
    }
    return 0;
}