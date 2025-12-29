#include <bits/stdc++.h>
using namespace std;
const int INF = 1e9;

int n;
int arr[1010][1010];
int dp[1010][1010];
int vis[1010][1010];

int rec(int r, int c){
    //pruning
    if(r<0 || c<0)return -INF;
    //base case
    if (r == 0 && c == 0) return arr[0][0];
    //cache check
    if(vis[r][c]!=0){
        return dp[r][c];
    }
    //transitions
    int ans = arr[r][c] + max(rec(r-1,c),rec(r,c-1));
    //save and return 
    vis[r][c]=1;
    return dp[r][c] = ans; 
}


int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    cin>>n;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cin>>arr[i][j];
            vis[i][j]=0;
        }
    }
    memset(dp,-1,sizeof(dp));
    cout<<rec(n-1,n-1);
    return 0;
}
