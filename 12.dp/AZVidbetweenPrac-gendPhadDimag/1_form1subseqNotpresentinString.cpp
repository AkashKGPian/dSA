#include<bits/stdc++.h>
using namespace std;
//tell wheather a 0100 binary substring present in the strings as a subsequence

//Return value 1 → subsequence "0100" is not present in arr.
// Return value 0 → subsequence "0100" is present in arr.

// match == 4 → means we’ve successfully matched "0100" as a subsequence → the function immediately returns 0 (bad, because the pattern exists).
// level == n (end of array) → if match != 4, then "0100" was never completed, so return 1 (good, pattern not present).

int n;
string t = "0100";
int arr[100010];
int dp[100010][5];

int rec(int level, int match){
    //pruning
    if(match==4){
        return 0;
    }
    //basecase
    if(level==n){//that means match = 4 wasnt hit till the end
        return 1;
    }
    //cache check
    if(dp[level][match]!=-1){
        return dp[level][match];
    }
    //transitions
    // option 1: skip current element
    int ans = rec(level + 1, match);
    
    // option 2: take current element if it matches next needed character
    if (arr[level] == (t[match] - '0')) {
        ans = ans || rec(level + 1, match + 1);
    }
    //save and return 
    return dp[level][match]=ans;
}

int main(){
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    memset(dp,-1,sizeof(dp));
    cout<<rec(0,0);
    return 0;
}