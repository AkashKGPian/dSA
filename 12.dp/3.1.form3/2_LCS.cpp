#include<bits/stdc++.h>
using namespace std;

int n,m;
string s,st;
int dp[1001][1001];

int rec(int i, int j){
    //returning LCS from i and j of s and st ie s[i...N-1] and st[i...M-1]
    //pruning
    //base case
    if(i>=n || j>=m){
        return 0;
    }
    //cache check
    if(dp[i][j]!=-1){
        return dp[i][j];
    }
    //compute
    int ans=0;
    ans=max(ans,rec(i,j+1));
    ans=max(ans,rec(i+1,j));
    if(s[i]==st[j]){
        ans=max(ans,1+rec(i+1,j+1));
    }
    //save and return 
    return dp[i][j]=ans;
}

int main(){
    cin>>s>>st;
    n=s.size();
    m=st.size();
    memset(dp,-1,sizeof(dp));
    cout<<rec(0,0);
    return 0;
}