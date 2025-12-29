#include<bits/stdc++.h>
using namespace std;

int t,n,m;
vector<string> arr;
int dp[1001][1001];

int rec(int r, int c){
    //pruning
    if(r<0 || c<0){
        return 0;
    }
    //basecase
    
    //cache check
    if(dp[r][c]!=-1){
        return dp[r][c];
    }

    // transitions
    int ans = 0;
    if(arr[r][c]=='1'){
        ans = 1 + min({rec(r-1,c),rec(r,c-1),rec(r-1,c-1)});
    }
    //save and return 
    return dp[r][c]=ans;
}

int main(){
    cin>>t;
    while(t--){
        cin>>n>>m;
        arr.resize(n);
        memset(dp,-1,sizeof(dp));
        for(int i=0;i<n;i++){
            cin>>arr[i];
        }
        int maxSide = 0;
        for(int i=n-1;i>=0;i--){
            for(int j=m-1;j>=0;j--){
                maxSide = max(maxSide, rec(i,j));
            }
        }
        int maxArea = maxSide * maxSide;
        cout << maxArea << "\n";
    }
    return 0;
}