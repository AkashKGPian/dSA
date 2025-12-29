#include<bits/stdc++.h>
using namespace std;

int n,m,x;
string s,t,p;
int dp[1001][1001][1001];

int rec(int i, int j, int k){
    //returning LCS from i and j of s and st ie s[i...N-1] and st[i...M-1]
    //pruning
    //base case
    if(i>=n || j>=m || k>=x){
        return 0;
    }
    //cache check
    if(dp[i][j][k]!=-1){
        return dp[i][j][k];
    }
    //compute
    int ans=0;
    ans=max(ans,rec(i,j,k+1));
    ans=max(ans,rec(i,j+1,k));
    ans=max(ans,rec(i+1,j,k));
    if(s[i]==t[j] && t[j]==p[k] ){
        ans=max(ans,1+rec(i+1,j+1,k+1));
    }
    //save and return 
    return dp[i][j][k]=ans;
}

int main(){
    cin>>s>>t>>p;
    n=s.size();
    m=t.size();
    x=p.size();
    memset(dp,-1,sizeof(dp));
    cout<<rec(0,0,0);
    return 0;
}