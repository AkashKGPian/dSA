#include<bits/stdc++.h>
using namespace std;

int n;
int dp[100100];

int check(int ch, int level){
    if(ch+level<=n)return 1;
    else return 0;
}

int rec(int level){
    // cout<<"level: "<<level<<" \n";
    //pruning
    if(level>n)return 0;
    //base case
    if(level==n){
        return 1;
    }
    if(dp[level]!=-1){
        return dp[level];
    }
    int ans=0;
    for(int ch=1;ch<4;ch++){
        if(check(ch,level)){
            ans+=rec(level+ch);
        }
    }
    dp[level]=ans;
    return ans;
}

int main(){
    cin>>n;
    cout<<rec(0);
    return 0;
}