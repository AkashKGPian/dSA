#include<bits/stdc++.h>
using namespace std;
// given a string in how many min cuts you can convert it fully to palindromic substrings
int n;
string st;
int dp1[1001][1001];
int dp2[1001];

int isPalindrome(int l, int r){
    //base case
    if(l>=r){
        return 1;
    }
    //cache check
    if(dp1[l][r]!=-1){
        return dp1[l][r];
    }
    //transitions
    int ans=0;
    if(st[l]==st[r]){
        ans = isPalindrome(l+1,r-1);
    }
    //save and return 
    return dp1[l][r]=ans;
}

int rec(int i){//returns the minimum no. of cuts to div the whole string into palindromic substrings
    //base case
    if(i==0)return -1;//to nullify the effect of extra +1 at the front take n=1 st='a'; ie cut at i=0
    //cache check
    if(dp2[i]!=-1){
        return dp2[i];
    }
    //transitions
    int ans = 1e9;
    for(int j=i;j>=0;j--){//1 indexing //cutting ka indexes j par just ek cut maro eg j = 0 par 
        if(isPalindrome(j,i)){
            ans=min(ans,rec(j-1)+1);
        }
    }
    //save and return 
    return dp2[i]=ans;
}

int main(){
    cin>>n>>st;
    st=" "+st;
    memset(dp1,-1,sizeof(dp1));
    memset(dp2,-1,sizeof(dp2));
    cout<<rec(n);
    return 0;
}