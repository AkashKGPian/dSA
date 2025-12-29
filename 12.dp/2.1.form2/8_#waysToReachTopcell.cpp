#include<bits/stdc++.h>
using namespace std;

int n,m;
vector<string> arr;
int dp[1001][1001];

int rec(int r, int c){
    //pruning
    if(r<0 || c<0){
        return 0;
    }
    // obstacle check
    //if the (0,0) and (n-1,m-1) are '#' then :-
    if(arr[r][c] == '#') return 0;
    
    //bases case
    if(r==0 && c==0){
        return 1;
    }
    //cache check
    if(dp[r][c]!=-1){
        return dp[r][c];
    }
    //up and left
    // transitions
    int ans = 0;
    if (r > 0 && arr[r-1][c] != '#')
        ans += rec(r-1, c);
    if (c > 0 && arr[r][c-1] != '#')
        ans += rec(r, c-1);
    //save and return 
    return dp[r][c]=ans;
}

int main(){
    cin>>n>>m;
    arr.resize(n);
    memset(dp,-1,sizeof(dp));
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    cout<<rec(n-1,m-1);
    return 0;
}