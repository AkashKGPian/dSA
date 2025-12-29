#include<bits/stdc++.h>
using namespace std;

int tc;
int n,m;
string s,t;
int dp[1001][1001];

int rec(int i, int j){
    //pruning
    //base case
    if(i==n || j==m){//any one of the string gets over
        return 0;
    }
    //cache check
    if(dp[i][j]!=-1){
        return dp[i][j];
    }
    //compute
    int ans=0;
    if(s[i]==t[j]){
        ans = 1 + rec(i+1,j+1);
    }// else{
    //     ans = 0;
    // }
    //save and return 
    return dp[i][j]=ans;
}

int main(){
    cin>>tc;
    while(tc--){
        cin>>s>>t;
        n=s.length();
        m=t.length();
        memset(dp,-1,sizeof(dp));
        int best=-1e9;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                best=max(best,rec(i,j));
            }
        }
        cout<<best<<"\n";
    }
    return 0;
}