#include<bits/stdc++.h>
using namespace std;

string x,y;
int n,m;
// vector<vector<int>> dp;
int dp[5050][5050];

int rec(int l1, int l2){
    //returning LCS from i and j of s and st ie s[i...N-1] and st[i...M-1]
    //base case
    if(l1==n && l2==m)return 0;
    //cache check
    if(dp[l1][l2]!=-1)return dp[l1][l2];
    //compute
    int ans=1e9;
    if(l1<n){//-x[i...n-1]  //-
        ans = min(ans,rec(l1+1,l2)+1);
    }
    if(l2<m){//+y[j...m-1]  //+
        ans = min(ans,rec(l1,l2+1)+1);
    }
    if(l1<n && l2<m && x[l1]==y[l2]){//x[l] //0
        ans = min(ans,rec(l1+1,l2+1)+1);
    }
    //save and return 
    return dp[l1][l2]=ans;
}

int main(){
    cin>>x>>y;
    n=x.length();
    m=y.length();
    memset(dp,-1,sizeof(dp));
    // dp.resize(n+1);
    // for(int i=0;i<m;i++)dp[i].assign(m+1,-1);
    cout<<rec(0,0)<<"\n";
    return 0;
}