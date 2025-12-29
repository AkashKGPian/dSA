#include <bits/stdc++.h>
using namespace std;

//count the no. of n length binary strings, not having any substring as "0100" in it;

int n;
int arr[100010];
string t="0100";//4 right and what is 010 = 2; next level = 3 ; **next coming if 0 then matched already assumed => next coming should be 1
int dp[100010][16];

int rec(int level, int lastthree){
    //pruning
    // if(match==4){
    //     return 0;
    // }not req we will use new logic of bit to match/store the last three contiguous elem of t in the string 
    
    //base case
    if(level==n){
        return 1;
    }
    //cache check
    if(dp[level][lastthree]!=-1){
        return dp[level][lastthree];
    }
    //compute
    int ans=0;//assumed that the string matched 0100
    if(level>=3 && lastthree==2){
        //doesnt matches as after 010 next comes 1 = 0101 but we are maintaining only lastthree bits
        ans = rec(level+1,((lastthree<<1)|1)&7);//**next coming 1 cuz if 0 comes substring t matches which is ans=0 already assumed
    }else{
        //add zero //101
        ans = rec(level+1,((lastthree<<1)|0)&7);
        ans += rec(level+1,((lastthree<<1)|1)&7);
    }
    //save and return 
    return dp[level][lastthree]=ans;
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
