#include<bits/stdc++.h>
using namespace std;

int n;
int a[100010], b[100010], c[100010];
int dp[100010][4];

int rec(int level, int last_taken){
    //base case
    if(level==n){
        return 0;
    }
    //cache check
    if(dp[level][last_taken]!=-1) return dp[level][last_taken];
    //transitions
    int ans=0;
    if(last_taken!=0)
        ans=max(ans, a[level]+rec(level+1,0));
    if(last_taken!=1)
        ans=max(ans, b[level]+rec(level+1,1));
    if(last_taken!=2)
        ans=max(ans, c[level]+rec(level+1,2));
    //save and return 
    return dp[level][last_taken] = ans;
}

int main(){
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>a[i]>>b[i]>>c[i];
    }
    memset(dp,-1,sizeof(dp));
    cout << rec(0, 3) << endl;  // 3 = no last activity
    return 0;
}