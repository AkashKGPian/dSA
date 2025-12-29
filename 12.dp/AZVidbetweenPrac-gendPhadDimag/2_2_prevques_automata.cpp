#include <bits/stdc++.h>
using namespace std;

//count the no. of n length binary strings, not having any substring as "0100" in it;

int n;
int arr[100010];//array not need as such
string t="0100";//4 right and what is 010 = 2; next level = 3 ; **next coming if 0 then matched already assumed => next coming should be 1
int dp[100010][16];

int rec(int level, int match){
    //pruning
    if(match == 4){
        return 0;
    }
    //base case
    if(level==n){
        return 1;
    }
    //cache check
    if(dp[level][match]!=-1){
        return dp[level][match];
    }
    //transitions
    int ans=0;
    if(match==0){
        //1,0 coming up
        ans=rec(level+1,0)+rec(level+1,1);
    }else if(match==1){
        ans=rec(level+1,2)+rec(level+1,1);
    }else if(match==2){
        ans=rec(level+1,0)+rec(level+1,3);
    }else if(match==3){
        ans=rec(level+1,2)+rec(level+1,4);
    }
    //save and return 
    return dp[level][match]=ans;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    memset(dp,-1,sizeof(dp));
    cout<<rec(0,0);
    return 0;
}
